#-------------------------------------------------
#  SKIRT -- an advanced radiative transfer code
#  © Astronomical Observatory, Ghent University
#-------------------------------------------------

#---------------------------------------------------------------------
# This "subdirs" project builds all library and application projects
# needed for SKIRT, FitSKIRT and DoxStyle (documentation streamliner)
#---------------------------------------------------------------------

TEMPLATE = subdirs

# add subdirectories in alphabetical order
SUBDIRS += \
    Cfitsio \
    Discover \
    DoxStyle \
    FitSKIRTcore \
    FitSKIRTmain \
    Fundamentals \
    GAlib \
    MPIsupport \
    SKIRTcore \
    SKIRTmain \
    Voro

# define dependencies between subprojects
SKIRTcore.depends    = Cfitsio Voro Fundamentals MPIsupport
Discover.depends     = Cfitsio Voro Fundamentals MPIsupport SKIRTcore
SKIRTmain.depends    = Cfitsio Voro Fundamentals MPIsupport SKIRTcore Discover
FitSKIRTcore.depends = GAlib Cfitsio Voro Fundamentals MPIsupport SKIRTcore Discover
FitSKIRTmain.depends = GAlib Cfitsio Voro Fundamentals MPIsupport SKIRTcore Discover FitSKIRTcore
