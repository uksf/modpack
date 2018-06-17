#include "script_component.hpp"

if (isNil QGVAR(exShakePFH)) then {
    GVAR(exShakePFH) = [{
        call FUNC(shockwaveHandler);
    }, 0.05] call CBA_fnc_addPerframeHandler;
};

// private _classes = ("true" configClasses (configFile >> "CfgAmmo"));
// private _output = [];
// {
//     private _name = configName _x;
//     private _hit = getNumber (_x >> "hit");
//     private _explosive = getNumber (_x >> "explosive");
//     private _indirectHitRange = getNumber (_x >> "indirectHitRange");
//     if (_hit > 0 && _explosive > 0 && _indirectHitRange > 0 && {(_name find "explosion_reflection") == -1}) then {
//         private _indirectHit = getNumber (_x >> "indirectHit");
//         _output pushBack [configName _x, _explosive, _hit, [_indirectHit, _indirectHitRange]];
//     };
// } forEach _classes;
// copyToClipboard str _output;
