#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Toggles dive computer on/off and starts/stops information update

    Parameter(s):
        0: State <BOOLEAN>

    Return Value:
        None
*/
params ["_state"];

if (!_state) exitWith {
    [GVAR(diveComputerUpdatePFHID)] call CBA_fnc_removePerFrameHandler;
    GVAR(diveComputerUpdatePFHID) = -1;
    titleText ["", "PLAIN"];
};

titleRsc [QGVAR(diveComputerDialog), "PLAIN"];
GVAR(diveComputerUpdatePFHID) = [{
    private _display = uiNamespace getVariable QGVAR(diveComputerDialog);

    (_display displayCtrl 1111) ctrlSetText format ["%1", round GVAR(currentPressure)];
    (_display displayCtrl 1112) ctrlSetText format ["%1", (round (GVAR(currentAmbientPressure) * 10)) / 10];
    (_display displayCtrl 1113) ctrlSetText format ["%1", round (round (GVAR(currentDepth) * 10)) / 10];
    (_display displayCtrl 1114) ctrlSetText format ["%1", (round (GVAR(ascendRate) * 10)) / 10];
    (_display displayCtrl 1115) ctrlSetText format ["%1", [GVAR(elapsedDiveTime), "MM:SS"] call BIS_fnc_secondstostring];
    (_display displayCtrl 1116) ctrlSetText format ["%1", [GVAR(remainingDiveTime), "MM:SS"] call BIS_fnc_secondstostring];
    (_display displayCtrl 1117) ctrlSetText format ["%1", (round (GVAR(decompressDepth) * 10)) / 10];
    (_display displayCtrl 1118) ctrlSetText format ["%1", (round (GVAR(decompressTime) * 10)) / 10];
    (_display displayCtrl 1119) ctrlSetText format ["%1", (round (GVAR(deepStopDepth) * 10)) / 10];
    (_display displayCtrl 1120) ctrlSetText format ["%1", (round (GVAR(deepStopTime) * 10)) / 10];
    (_display displayCtrl 1121) ctrlSetText format ["%1", (round (GVAR(maxDepth) * 10)) / 10];
    (_display displayCtrl 1122) ctrlSetText format ["%1", [dayTime, "HH:MM:SS"] call BIS_fnc_timetostring];
    (_display displayCtrl 1123) ctrlSetText format ["%1", round (getDir player)];
    (_display displayCtrl 1124) ctrlSetText format ["%1", (round (GVAR(partialPressureO2) * 10)) / 10];
    (_display displayCtrl 1125) ctrlSetText format ["%1", (round (GVAR(partialPressureN2) * 10)) / 10];
    (_display displayCtrl 1126) ctrlSetText format ["%1%2%3%4%5", GVAR(warningTextO2), GVAR(warningTextN2), GVAR(warningTextAscendRate), GVAR(warningTextLowPressure), GVAR(warningTextDecompression)];
}, 0.1, []] call CBA_fnc_addPerFrameHandler;
