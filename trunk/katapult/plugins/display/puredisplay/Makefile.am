# set the include path for X, qt and KDE
INCLUDES = -I$(top_srcdir)/common $(all_includes)

# header files
noinst_HEADERS = puredisplay.h

# use automoc
METASOURCES = AUTO

# our plugin
kde_module_LTLIBRARIES =  katapult_puredisplay.la
katapult_puredisplay_la_SOURCES = settings.ui puredisplay.cpp
katapult_puredisplay_la_LDFLAGS = -module $(KDE_RPATH) $(KDE_PLUGIN) $(all_libraries)
katapult_puredisplay_la_LIBADD = $(LIB_KDEUI) $(top_builddir)/common/libkatapultdisplay.la
kde_services_DATA = katapult_puredisplay.desktop
