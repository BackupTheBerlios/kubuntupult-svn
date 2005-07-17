/***************************************************************************
 *   Copyright (C) 2005 by Joe Ferris                                      *
 *   jferris@optimistictech.com                                            *
 *                                                                         *
 *   This document is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This document is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this document; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "documentcatalog.h"

#include <kservicegroup.h>
#include <ksycocaentry.h>
#include <ksycocatype.h>
#include <kapplication.h>
#include <knuminput.h>
#include <kcombobox.h>

#include <qcheckbox.h>

#include <actioncatalog.h>

#include "settings.h"
#include "document.h"
#include "directory.h"
#include "status.h"
#include "match.h"
#include "actionopendocument.h"

K_EXPORT_COMPONENT_FACTORY( katapult_documentcatalog,
                            KGenericFactory<DocumentCatalog>( "katapult_documentcatalog" ) )

DocumentCatalog::DocumentCatalog(QObject *, const char *, const QStringList&)
 : KatapultCatalog()
{
	_minQueryLen = 1;
	currentPath = "";
	queryMatched = 0;
	charsMatched = 0;
	filesListed = FALSE;
	ActionCatalog::self()->addAction(new ActionOpenDocument());
}

DocumentCatalog::~DocumentCatalog()
{
}

void DocumentCatalog::initialize()
{
	dir = QDir::home();
	refreshFolders();
	refreshFiles();
}

void DocumentCatalog::refreshFolders()
{
	folders.clear();
	files.clear();
	filesListed = FALSE;
	QStringList folderNames = dir.entryList(QDir::Dirs);
	for(QStringList::Iterator it = folderNames.begin(); it != folderNames.end(); ++it) {
		QString dirname = *it;
 		if(!dirname.startsWith("."))
			folders.append(dirname);
	}
}

void DocumentCatalog::refreshFiles()
{
	const QFileInfoList *fileList = dir.entryInfoList();

	for(QPtrListStdIterator<QFileInfo> it = fileList->begin(); it != fileList->end(); ++it) {
		const QFileInfo *file = *it;
		if(!file->fileName().startsWith(".")) {
			if(file->isDir())
				files.append(new Directory(currentPath+file->fileName(), file->absFilePath()));
			else
				files.append(new Document(currentPath+file->fileName(), file->absFilePath()));
		}
	}
	filesListed = TRUE;
}

void DocumentCatalog::queryChanged()
{
	int newStatus = 0;
	charsMatched = 0;
	if(query() == "")
	{
		// reset query
		dir = QDir::home();
		currentPath = "";
		queryMatched = 0;
		refreshFolders();
	} else {
		if(query().length() >= minQueryLen())
		{
			QString path = query().lower().remove(0, queryMatched);
			
			int index;
			while((index = path.find('/')) != -1) {
				QString folderQuery = path.left(index);
				QString guess = QString::null;
				
				for(QStringList::Iterator it = folders.begin(); it != folders.end(); ++it) {
					QString folderName = *it;
					if(folderName.lower().startsWith(folderQuery) && (guess.isNull() || folderName.length() < guess.length()))
						guess = folderName;
				}
				
				if(guess == QString::null) {
					path = QString::null;
					break;
				}
				
				if(!dir.cd(guess)) {
					path = QString::null;
					break;
				}
				refreshFolders();
				
				queryMatched += folderQuery.length() + 1;
				currentPath += guess + "/";
				path = path.remove(0, index+1);
			}
			
			if(path.isNull()) {
				files.clear();
			} else {
				charsMatched = currentPath.length() + path.length();
				if(!filesListed) {
					refreshFiles();
				}
				if(!path.isEmpty()) {
					Document::Ptr document;
					for(Document::List::Iterator it = files.begin(); it != files.end(); ) {
						document = *it;
						++it;
						if(!document->name().lower().startsWith(path))
							files.remove(document);
					}
				}
			}
			
			newStatus |= S_Active;
			if(files.count() > 0)
			{
				newStatus |= S_HasResults;
				if(files.count() > 1 || path.isEmpty())
					newStatus |= S_Multiple;
			} else
				newStatus |= S_NoResults;
				
		}
	}
	setStatus(newStatus);
}

unsigned int DocumentCatalog::minQueryLen() const
{
	return _minQueryLen;
}

void DocumentCatalog::readSettings(KConfigBase *config)
{
	_minQueryLen = config->readUnsignedNumEntry("MinQueryLen", 1);
}

void DocumentCatalog::writeSettings(KConfigBase *config)
{
	config->writeEntry("MinQueryLen", _minQueryLen);
}

QWidget * DocumentCatalog::configure()
{
	DocumentCatalogSettings *settings = new DocumentCatalogSettings();
	
	settings->minQueryLen->setValue(_minQueryLen);
	connect(settings->minQueryLen, SIGNAL(valueChanged(int)), this, SLOT(minQueryLenChanged(int)));
	
	return settings;
}

void DocumentCatalog::minQueryLenChanged(int _minQueryLen)
{
	this->_minQueryLen = _minQueryLen;
}

void DocumentCatalog::addMatches(QValueList<Match> & matches, unsigned int max, const KatapultAction *action)
{
	Document::Ptr file;
	for(Document::List::Iterator it = files.begin(); it != files.end(); ++it) {
		file = *it;
		if(action == 0 || action->accepts(file))
			addMatch(matches, Match(file, 100*query().length()/file->text().length(), charsMatched), max);
	}
}
