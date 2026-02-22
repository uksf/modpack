#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Returns sector control visualisation data for Zeus.

    Parameter(s):
        None

    Return Value:
        Array of sector data
*/

private _sectors = GVAR(sectors) select {!isNull _x};

private _sectorData = _sectors apply {
    private _position = getPosATL _x;
    private _area = _x getVariable ["objectArea", [0, 0, 0, false]];
    private _owner = _x getVariable [QGVAR(currentOwner), 2];
    private _opforScore = _x getVariable [QGVAR(currentOpforScore), 0];
    private _bluforScore = _x getVariable [QGVAR(currentbluforScore), 0];
    private _timeToCapture = _x getVariable [QGVAR(timeToCapture), 60];
    private _contested = _x getVariable [QGVAR(sectorContested), false];
    private _locked = _x getVariable [QGVAR(sectorLocked), false];
    private _name = _x getVariable [QGVAR(displayName), "Sector"];

    [_position, _area, _owner, _opforScore, _bluforScore, _timeToCapture, _contested, _locked, _name]
};

[_sectorData]
