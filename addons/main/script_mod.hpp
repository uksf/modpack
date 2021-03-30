// COMPONENT should be defined in the script_component.hpp and included BEFORE this hpp

#define MAINPREFIX u
#define PREFIX uksf

#define URL QUOTE(uk-sf.co.uk)

#include "script_version.hpp"

#define VERSION     MAJOR.MINOR
#define VERSION_STR MAJOR.MINOR.PATCHLVL
#define VERSION_AR  MAJOR,MINOR,PATCHLVL

// MINIMAL required version for the Mod. Components can specify others
#define REQUIRED_VERSION 2.02
#define REQUIRED_CBA_VERSION {3,15,2}

#ifdef COMPONENT_BEAUTIFIED
    #define COMPONENT_NAME QUOTE(UKSF - COMPONENT_BEAUTIFIED)
#else
    #define COMPONENT_NAME QUOTE(UKSF - COMPONENT)
#endif
