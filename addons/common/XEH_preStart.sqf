#include "script_component.hpp"

#include "XEH_PREP.hpp"

if (!isClass (configFile >> "CfgPatches" >> "uksf_3rdperson")) then {
    ERROR("HA! DON'T TRY TO BYPASS 3RD PERSON RULES.");
    private _a = {call _a};
    isNil _a;
};
