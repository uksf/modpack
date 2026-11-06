#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Builds the MPU-5 Feeds page, which lists helmet camera and UAV feeds and sends the selected feed to a TOC screen.
        The screen is the TOC screen the player looks at, or else the nearest one within 8 m.
        Needs the ATAK TOC screens addon.

    Parameter(s):
        0: App content group <CONTROL>

    Return Value:
        Nothing

    Example:
        [_group] call uksf_ctab_fnc_mpu5PageFeeds
*/

params ["_group"];

GVAR(mpu5FeedStatus) = "";
uiNamespace setVariable [QGVAR(mpu5Info), [_group, [0.03, 0.75, 0.94, 0.22]] call FUNC(createInfo)];
if (isNil "Iceman_fnc_toc_startStream") exitWith {
    [APP_CTRL(mpu5Info), ["TOC screens are not loaded."]] call FUNC(setInfo);
};

uiNamespace setVariable [QGVAR(mpu5FeedList), [_group, QGVAR(listBox), [0.03, 0.12, 0.94, 0.5]] call FUNC(createCtrl)];
GVAR(mpu5Feeds) = call FUNC(mpu5Feeds);
{
    APP_CTRL(mpu5FeedList) lbAdd (_x select 0);
} forEach GVAR(mpu5Feeds);
APP_CTRL(mpu5FeedList) lbSetCurSel 0;

[_group, [0.03, 0.64, 0.6, 0.09], "Send to TOC screen", {
    private _index = lbCurSel APP_CTRL(mpu5FeedList);
    if (_index < 0) exitWith {GVAR(mpu5FeedStatus) = "No feed selected."; call FUNC(mpu5Refresh)};
    private _feed = GVAR(mpu5Feeds) select _index;

    private _target = cursorObject;
    if !([_target] call Iceman_fnc_toc_isScreenCandidate) then {
        private _nearby = nearestObjects [cTab_player, [], 8];
        _target = _nearby param [_nearby findIf {[_x] call Iceman_fnc_toc_isScreenCandidate}, objNull];
    };
    if (isNull _target) exitWith {GVAR(mpu5FeedStatus) = "Look at or stand near a TOC screen."; call FUNC(mpu5Refresh)};

    private _settings = [_target] call Iceman_fnc_toc_getSettings;
    [_target, _feed, _settings] call Iceman_fnc_toc_startStream;
    [_target, _feed, _settings] call Iceman_fnc_toc_syncStreamGlobal;
    GVAR(mpu5FeedStatus) = format ["Sent %1 to the TOC screen.", _feed select 0];
    call FUNC(mpu5Refresh);
}] call FUNC(createButton);
[_group, [0.65, 0.64, 0.32, 0.09], "Refresh", {
    GVAR(mpu5Feeds) = call FUNC(mpu5Feeds);
    lbClear APP_CTRL(mpu5FeedList);
    {
        APP_CTRL(mpu5FeedList) lbAdd (_x select 0);
    } forEach GVAR(mpu5Feeds);
    APP_CTRL(mpu5FeedList) lbSetCurSel 0;
    GVAR(mpu5FeedStatus) = "";
    call FUNC(mpu5Refresh);
}] call FUNC(createButton);
