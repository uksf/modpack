#include "script_component.hpp"

[] spawn {
    private _unitNameConfigs = configFile >> "CfgUnitNames";
    private _unitConfig = (getArray (_unitNameConfigs >> (roleDescription player)));
    private _class = _unitConfig select 2;
    private _groupName = _unitConfig select 0;
    private _group = GVAR(unitGroups) select {(groupId _x) isEqualTo _groupName};
    if (isNull _group) then {
        _group = createGroup west;
    };
    private _unit = _group createUnit [_class, [-1000, -1000, 0], [], 0, "CAN_COLLIDE"];
    private _oldUnit = player;
    selectPlayer _unit;
    deleteVehicle _oldUnit;
    forceRespawn player;
};
