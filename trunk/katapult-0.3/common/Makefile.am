# set the include path for X, qt and KDE
INCLUDES = $(all_includes)

# these are the headers for your project
noinst_HEADERS = status.h katapultdisplay.h katapultcatalog.h katapultaction.h \
	katapultitem.h cachedcatalog.h actionregistry.h match.h

# let automoc handle all of the meta source files (moc)
METASOURCES = AUTO

lib_LTLIBRARIES = libkatapult.la libkatapultcatalog.la libkatapultdisplay.la

# common library
libkatapult_la_SOURCES = katapultitem.cpp katapultaction.cpp actionregistry.cpp
libkatapult_la_LDFLAGS = $(all_libraries) -version-info 0:0:0

# catalog library
libkatapultcatalog_la_SOURCES = katapultcatalog.cpp cachedcatalog.cpp match.cpp
libkatapultcatalog_la_LDFLAGS = $(all_libraries) -version-info 0:0:0
libkatapultcatalog_la_LIBADD = libkatapult.la

# display library
libkatapultdisplay_la_SOURCES = katapultdisplay.cpp
libkatapultdisplay_la_LDFLAGS = $(all_libraries) -version-info 0:0:0
libkatapultdisplay_la_LIBADD = libkatapult.la

# this is where the service type files will go
kde_servicetypes_DATA = katapultdisplay.desktop katapultcatalog.desktop
