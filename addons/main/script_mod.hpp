// COMPONENT should be defined in the script_component.hpp and included BEFORE this hpp

#define MAINPREFIX u
#define PREFIX uksf

#include "\u\uksf\addons\main\script_version.hpp"
#define VERSION MAJOR.MINOR.PATCHLVL
#define VERSION_AR MAJOR,MINOR,PATCHLVL

// MINIMAL required version for the Mod. Components can specify others..
#define REQUIRED_VERSION 1.68
#define REQUIRED_CBA_VERSION {3,1,2}

#ifdef COMPONENT_BEAUTIFIED
    #define COMPONENT_NAME QUOTE(UKSF - COMPONENT_BEAUTIFIED)
#else
    #define COMPONENT_NAME QUOTE(UKSF - COMPONENT)
#endif
