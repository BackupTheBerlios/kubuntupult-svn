# set the include path for X, qt and KDE
INCLUDES = -I$(top_srcdir)/common $(all_includes)

# header files
noinst_HEADERS = programcatalog.h program.h actionrunprogram.h

# use automoc
METASOURCES = AUTO

# our plugin
kde_module_LTLIBRARIES =  katapult_programcatalog.la
katapult_programcatalog_la_SOURCES = settings.ui programcatalog.cpp program.cpp actionrunprogram.cpp
katapult_programcatalog_la_LDFLAGS = -module $(KDE_RPATH) $(KDE_PLUGIN) $(all_libraries)
katapult_programcatalog_la_LIBADD = $(LIB_KDEUI) $(LIB_KIO) $(top_builddir)/common/libkatapultcatalog.la
kde_services_DATA = katapult_programcatalog.desktop
