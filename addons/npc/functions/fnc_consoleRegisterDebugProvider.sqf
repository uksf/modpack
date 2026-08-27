#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Registers the NPC console with the existing Zeus Debug provider registry.
*/
private _key = QGVAR(consoleDebug);
private _fnc_draw3d = {
    params ["", "_cameraPosition", "_maximumDistance"];
    {
        private _npc = objectFromNetId _x;
        if (isNull _npc || {_cameraPosition distance _npc > _maximumDistance}) then {continue};
        private _name = _npc getVariable [QGVAR(personaName), name _npc];
        private _colour = [[0.4, 0.7, 1, 0.9], [0.5, 0.5, 0.5, 0.8]] select !(_npc getVariable [QGVAR(talkable), false]);
        drawIcon3D ["\a3\ui_f\data\map\markers\military\dot_ca.paa", _colour, (getPosVisual _npc) vectorAdd [0, 0, 2.1], 0.35, 0.35, 0, _name, 1, 0.025, "TahomaB", "center", true];
    } forEach (missionNamespace getVariable [QGVAR(registeredNetIds), []]);
};
private _fnc_drawHud = {
    params ["", "_control"];
    private _position = positionCameraToWorld [0, 0, 0];
    _control ctrlSetStructuredText parseText ([_position] call FUNC(consoleCardText));
};
[QEGVAR(zeus,registerDebugProvider), [_key, createHashMapFromArray [
    ["draw3d", _fnc_draw3d],
    ["drawHud", _fnc_drawHud],
    ["hudLines", 7],
    ["menuName", "NPC Console"],
    ["menuPriority", -65],
    ["menuCondition", {(missionNamespace getVariable [QGVAR(registeredNetIds), []]) isNotEqualTo [] && {ADMIN_OR_WHITELISTED}}]
]]] call CBA_fnc_localEvent;
