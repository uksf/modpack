#include "script_component.hpp"

#include "XEH_PREP.hpp"

if (!isClass (configFile >> "CfgPatches" >> "uksf_3rdperson")) then {
    ERROR("You tried to bypass 3rd person settings. These are not optional.");
    private _a = {call _a};
    isNil _a;
};
