// COMPONENT should be defined in the script_component.hpp and included BEFORE this hpp

#define MAINPREFIX u
#define PREFIX uksf

// MINIMAL required version for the Mod. Components can specify others..
#define REQUIRED_VERSION 1.64
#define REQUIRED_CBA_VERSION {3,1,1}

#ifdef COMPONENT_BEAUTIFIED
    #define COMPONENT_NAME QUOTE(UKSF - COMPONENT_BEAUTIFIED)
#else
    #define COMPONENT_NAME QUOTE(UKSF - COMPONENT)
#endif
