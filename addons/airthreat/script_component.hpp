#define COMPONENT airthreat
#define COMPONENT_BEAUTIFIED Air Threat
#include "\u\uksf\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS

#include "\u\uksf\addons\main\script_macros.hpp"

// Scramble delay constants (seconds, ±25% jitter applied at runtime)
// These are doctrine, not mission-maker-tunable.
#define INTERCEPT_SCRAMBLE_DELAY 90
#define CAS_SCRAMBLE_DELAY       120
#define STRIKE_SCRAMBLE_DELAY    180
#define INTERCEPT_STAGGER_DELAY  60
