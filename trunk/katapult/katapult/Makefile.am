# set the include path for X, qt and KDE
INCLUDES = -I$(top_srcdir)/common $(all_includes)

# these are the headers for your project
noinst_HEADERS = katapult.h katapultsettings.h katapultconfigdlg.h

# let automoc handle all of the meta source files (moc)
METASOURCES = AUTO

messages: rc.cpp
	$(XGETTEXT) *.cpp -o $(podir)/katapult.pot

KDE_ICON = katapult

bin_PROGRAMS = katapult

# the application source, library search path, and link libraries
katapult_SOURCES = confgeneral.ui confcatalogs.ui confdisplay.ui main.cpp katapult.cpp katapultsettings.cpp \
	katapultconfigdlg.cpp
katapult_LDFLAGS = $(KDE_RPATH) $(all_libraries)
katapult_LDADD = $(LIB_KDEUI) $(LIB_KIO) $(top_builddir)/common/libkatapultcatalog.la $(top_builddir)/common/libkatapultdisplay.la

# this is where the desktop file will go 
xdg_apps_DATA = katapult.desktop
