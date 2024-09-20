#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Devirtualise any groups in radius from position

    Parameter(s):
        0: Position <ARRAY>
        1: Radius <SCALAR>

    Return Value:
        None
*/

if (!isServer) exitWith {
    [QGVAR(devirtualiseNearby), _this] call CBA_fnc_serverEvent;
};

[{
    params ["_args", "_idPFH"];
    _args params ["_position", "_radius"];

    private _groupIndex = GVAR(groupPositionMap) findIf {
        private _groupPosition = _x#1;

        _groupPosition distance2D _position < _radius
    };

    if (_groupIndex == -1) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    private _id = GVAR(groupPositionMap)#_groupIndex#0;
    GVAR(groupPositionMap) deleteAt _groupIndex;

    private _groupData = GVAR(groupDataMap) deleteAt _id;
    [QGVAR(recreateGroup), [_groupData, true]] call EFUNC(common,headlessEvent);

    call FUNC(sendDataToClients);
}, 0.2, _this] call CBA_fnc_addPerFrameHandler;
