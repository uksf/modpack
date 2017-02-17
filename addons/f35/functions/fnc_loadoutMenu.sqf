/*
    Author:
        Tim Beswick, John_Spartan, Saul, USAF Team

    Description:
        Service menu functions

    Parameters:
        None

    Return value:
        Nothing
*/
#include "script_component.hpp"

GVAR(Menu_fnc_Open) = {
    createDialog QGVAR(Rsc_Service_Main);
};

GVAR(Menu_fnc_Return) = {
    closeDialog 0;
    createDialog QGVAR(Rsc_Service_Main);
};

GVAR(Menu_fnc_Loadout_Cas) = {    
    _plane = vehicle player;
    [_plane,["USAF_1Rnd_StationR","USAF_1Rnd_StationL","USAF_1Rnd_Station2","USAF_1Rnd_Station2","USAF_1Rnd_Station1","USAF_1Rnd_Station1","USAF_1Rnd_AIM9X","USAF_1Rnd_AIM9X","USAF_1Rnd_AGM154A1","USAF_1Rnd_AGM154A1","USAF_Empty","USAF_Empty","USAF_Empty","USAF_Empty","1Rnd_GBU12_LGB","1Rnd_GBU12_LGB","USAF_1Rnd_AIM120I","USAF_1Rnd_AIM120I","USAF_F35A_8Rnd_GBU53_M","USAF_F35A_8Rnd_GBU53_M","USAF_F35A_8Rnd_GBU53_M","USAF_F35A_8Rnd_GBU53_M","USAF_F35A_8Rnd_GBU53_M","USAF_F35A_8Rnd_GBU53_M","USAF_F35A_8Rnd_GBU53_M","USAF_F35A_8Rnd_GBU53_M","USAF_empty","USAF_empty","USAF_empty","USAF_empty","USAF_empty","USAF_empty","USAF_empty","USAF_empty"]]  call FUNC(loadoutDynamic);
    closeDialog 0;
};

GVAR(Menu_fnc_Loadout_Sead) = {
    _plane = vehicle player;
    [_plane,["USAF_1Rnd_StationR","USAF_1Rnd_StationL","USAF_1Rnd_Station2","USAF_1Rnd_Station2","USAF_1Rnd_Station1","USAF_1Rnd_Station1","USAF_1Rnd_AIM9X","USAF_1Rnd_AIM9X","USAF_1Rnd_AGM88","USAF_1Rnd_AGM88","USAF_empty","USAF_empty","USAF_empty","USAF_empty","USAF_1Rnd_AGM154A1","USAF_1Rnd_AGM154A1","USAF_1Rnd_AIM120I","USAF_1Rnd_AIM120I","USAF_1Rnd_JAGM","USAF_1Rnd_JAGM","USAF_1Rnd_JAGM","USAF_1Rnd_JAGM","USAF_Empty","USAF_Empty","USAF_Empty","USAF_Empty","USAF_empty","USAF_empty","USAF_empty","USAF_empty","USAF_empty","USAF_empty","USAF_empty","USAF_empty"]] call FUNC(loadoutDynamic);
    closeDialog 0;
};

GVAR(Menu_fnc_Loadout_Cap) = {
    _plane = vehicle player;
    [_plane,["USAF_1Rnd_StationR","USAF_1Rnd_StationL","USAF_1Rnd_Station2","USAF_1Rnd_Station2","USAF_1Rnd_Station1","USAF_1Rnd_Station1","USAF_1Rnd_AIM9X","USAF_1Rnd_AIM9X","USAF_1Rnd_RACKS_X2","USAF_1Rnd_RACKS_X2","USAF_1Rnd_GBU32","USAF_1Rnd_GBU32","USAF_1Rnd_GBU32","USAF_1Rnd_GBU32","USAF_1Rnd_F35_TANK","USAF_1Rnd_F35_TANK","USAF_1Rnd_AIM120I","USAF_1Rnd_AIM120I","USAF_1Rnd_AIM120","USAF_1Rnd_AIM120","USAF_1Rnd_AIM120","USAF_1Rnd_AIM120","USAF_Empty","USAF_Empty","USAF_Empty","USAF_Empty","USAF_Empty","USAF_Empty","USAF_Empty","USAF_Empty","USAF_empty","USAF_empty","USAF_empty","USAF_empty"]] call FUNC(loadoutDynamic);
    closeDialog 0;
};

GVAR(Menu_fnc_Loadout_Empty) = {
    _plane = vehicle player;
    [_plane] call FUNC(loadoutEmpty);
    closeDialog 0;
};

GVAR(Menu_fnc_Loadout_Repair) = {
    _plane = vehicle player;

    closeDialog 0;
    [{
        params ["_args", "_idPFH"];
        _args params ["_plane"];

        _damage = damage _plane;
        _plane setDamage (_damage - 0.015);
        if (_damage < 0.01) exitWith {
            titleText ["Refueling Complete...", "PLAIN DOWN", 1.5];
            [_idPFH] call CBA_fnc_removePerFrameHandler;
        };
        if (speed _plane > 1) exitWith {
            titleText ["Refueling Canceled...", "PLAIN DOWN", 1.5];
            [_idPFH] call CBA_fnc_removePerFrameHandler;
        };
        titleText ["Rearming...", "PLAIN DOWN",1.5];
    }, 3, [_plane]] call CBA_fnc_addPerFrameHandler;
};

GVAR(Menu_fnc_Loadout_Loadouts) = {
    _plane = vehicle player;

    closeDialog 0;
    createDialog QGVAR(Rsc_Service_Loadout);

    {lbAdd[3101,_x]} forEach ["EMPTY", "AIM-9X", "AIM-120D"];
    {lbAdd[3102,_x]} forEach ["EMPTY", "AIM-9X", "AIM-120D"];
    {lbAdd[3103,_x]} forEach ["EMPTY","MK-82 (X2)","GBU-32 (X2)","AGM-154","GBU-31","GBU-12","AGM-88","CBU-78 (X2)","CBU-87 (X2)","CBU-89 (X2)"];
    {lbAdd[3104,_x]} forEach ["EMPTY","MK-82 (X2)","GBU-32 (X2)","AGM-154","GBU-31","GBU-12","AGM-88","CBU-78 (X2)","CBU-87 (X2)","CBU-89 (X2)"];
    {lbAdd[3105,_x]} forEach ["EMPTY","Fuel Pod","AGM-154","GBU-12","GBU-31","CBU-78 (X2)","CBU-87 (X2)","CBU-89 (X2)"];
    {lbAdd[3106,_x]} forEach ["EMPTY","Fuel Pod","AGM-154","GBU-12","GBU-31","CBU-78 (X2)","CBU-87 (X2)","CBU-89 (X2)"];
    {lbAdd[3107,_x]} forEach ["EMPTY","AIM-120D"];
    {lbAdd[3108,_x]} forEach ["EMPTY","AIM-120D"];
    {lbAdd[3109,_x]} forEach ["EMPTY","GBU-31 (X2)","GBU-32 (X2)","GBU-38 (X2)","GBU-24 (x2)","GBU-53 (x8)","AGM-154 (x2)","AIM-120 (x4)","CBU-100 (x2)","JAGM (X4)"];

    ((uiNamespace getVariable QGVAR(Service_Menu)) displayCtrl 3101) lbSetCurSel 1;
    ((uiNamespace getVariable QGVAR(Service_Menu)) displayCtrl 3102) lbSetCurSel 1;
    ((uiNamespace getVariable QGVAR(Service_Menu)) displayCtrl 3103) lbSetCurSel 2;
    ((uiNamespace getVariable QGVAR(Service_Menu)) displayCtrl 3104) lbSetCurSel 2;
    ((uiNamespace getVariable QGVAR(Service_Menu)) displayCtrl 3105) lbSetCurSel 11;
    ((uiNamespace getVariable QGVAR(Service_Menu)) displayCtrl 3106) lbSetCurSel 11;
    ((uiNamespace getVariable QGVAR(Service_Menu)) displayCtrl 3107) lbSetCurSel 8;
    ((uiNamespace getVariable QGVAR(Service_Menu)) displayCtrl 3108) lbSetCurSel 8;
    ((uiNamespace getVariable QGVAR(Service_Menu)) displayCtrl 3109) lbSetCurSel 0;
    ((uiNamespace getVariable QGVAR(Service_Menu)) displayCtrl 3110) lbSetCurSel 2;
    ((uiNamespace getVariable QGVAR(Service_Menu)) displayCtrl 3111) lbSetCurSel 1;
};

GVAR(Menu_fnc_Loadout_Exec) = {
    _plane = vehicle player;

    _station1Index = lbCurSel 3101;
    _station2Index = lbCurSel 3102;
    _station3Index = lbCurSel 3103;
    _station4Index = lbCurSel 3104;
    _station5Index = lbCurSel 3105;
    _station6Index = lbCurSel 3106;
    _station17Index = lbCurSel 3107;
    _station18Index = lbCurSel 3108;
    _station19Index = lbCurSel 3109;

    _station1 = switch (_station1Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_1Rnd_StationR" };
        case 2: { "USAF_1Rnd_StationR" };
    };

    _station2 = switch (_station2Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_1Rnd_StationL" };
        case 2: { "USAF_1Rnd_StationL" };
    };

    _station3 = switch (_station3Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_1Rnd_Station2" };
        case 2: { "USAF_1Rnd_Station2" };
        case 3: { "USAF_1Rnd_Station2" };
        case 4: { "USAF_1Rnd_Station2" };
        case 5: { "USAF_1Rnd_Station2" };
        case 6: { "USAF_1Rnd_Station2" };
        case 7: { "USAF_1Rnd_Station2" };
        case 8: { "USAF_1Rnd_Station2" };
        case 9: { "USAF_1Rnd_Station2" };
    };

    _station4 = switch (_station4Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_1Rnd_Station2" };
        case 2: { "USAF_1Rnd_Station2" };
        case 3: { "USAF_1Rnd_Station2" };
        case 4: { "USAF_1Rnd_Station2" };
        case 5: { "USAF_1Rnd_Station2" };
        case 6: { "USAF_1Rnd_Station2" };
        case 7: { "USAF_1Rnd_Station2" };
        case 8: { "USAF_1Rnd_Station2" };
        case 9: { "USAF_1Rnd_Station2" };
    };

    _station5 = switch (_station5Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_1Rnd_Station1" };
        case 2: { "USAF_1Rnd_Station1" };
        case 3: { "USAF_1Rnd_Station1" };
        case 4: { "USAF_1Rnd_Station1" };
        case 5: { "USAF_1Rnd_Station1" };
        case 6: { "USAF_1Rnd_Station1" };
        case 7: { "USAF_1Rnd_Station1" };
    };

    _station6 = switch (_station6Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_1Rnd_Station1" };
        case 2: { "USAF_1Rnd_Station1" };
        case 3: { "USAF_1Rnd_Station1" };
        case 4: { "USAF_1Rnd_Station1" };
        case 5: { "USAF_1Rnd_Station1" };
        case 6: { "USAF_1Rnd_Station1" };
        case 7: { "USAF_1Rnd_Station1" };
    };

    _station7 = switch (_station1Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_1Rnd_AIM9X" };
        case 2: { "USAF_1Rnd_AIM120" };
    };

    _station8 = switch (_station2Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_1Rnd_AIM9X" };
        case 2: { "USAF_1Rnd_AIM120" };
    };

    _station9 = switch (_station3Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_1Rnd_RACKS_X2" };
        case 2: { "USAF_1Rnd_RACKS_X2" };
        case 3: { "USAF_1Rnd_AGM154A1" };
        case 4: { "USAF_1Rnd_GBU31" };
        case 5: { "1Rnd_GBU12_LGB" };
        case 6: { "USAF_1Rnd_AGM88" };
        case 7: { "USAF_1Rnd_RACKS_X2" };
        case 8: { "USAF_1Rnd_RACKS_X2" };
        case 9: { "USAF_1Rnd_RACKS_X2" };
    };

    _station10 = switch (_station4Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_1Rnd_RACKS_X2" };
        case 2: { "USAF_1Rnd_RACKS_X2" };
        case 3: { "USAF_1Rnd_AGM154A1" };
        case 4: { "USAF_1Rnd_GBU31" };
        case 5: { "1Rnd_GBU12_LGB" };
        case 6: { "USAF_1Rnd_AGM88" };
        case 7: { "USAF_1Rnd_RACKS_X2" };
        case 8: { "USAF_1Rnd_RACKS_X2" };
        case 9: { "USAF_1Rnd_RACKS_X2" };
    };

    _station11 = switch (_station3Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_1Rnd_MK82" };
        case 2: { "USAF_1Rnd_GBU32" };
        case 3: { "USAF_Empty" };
        case 4: { "USAF_Empty" };
        case 5: { "USAF_Empty" };
        case 6: { "USAF_Empty" };
        case 7: { "USAF_1Rnd_CBU78B" };
        case 8: { "USAF_1Rnd_CBU87B" };
        case 9: { "USAF_1Rnd_CBU89B" };
    };

    _station12 = switch (_station3Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_1Rnd_MK82" };
        case 2: { "USAF_1Rnd_GBU32" };
        case 3: { "USAF_Empty" };
        case 4: { "USAF_Empty" };
        case 5: { "USAF_Empty" };
        case 6: { "USAF_Empty" };
        case 7: { "USAF_1Rnd_CBU78B" };
        case 8: { "USAF_1Rnd_CBU87B" };
        case 9: { "USAF_1Rnd_CBU89B" };
    };

    _station13 = switch (_station4Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_1Rnd_MK82" };
        case 2: { "USAF_1Rnd_GBU32" };
        case 3: { "USAF_Empty" };
        case 4: { "USAF_Empty" };
        case 5: { "USAF_Empty" };
        case 6: { "USAF_Empty" };
        case 7: { "USAF_1Rnd_CBU78B" };
        case 8: { "USAF_1Rnd_CBU87B" };
        case 9: { "USAF_1Rnd_CBU89B" };
    };

    _station14 = switch (_station4Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_1Rnd_MK82" };
        case 2: { "USAF_1Rnd_GBU32" };
        case 3: { "USAF_Empty" };
        case 4: { "USAF_Empty" };
        case 5: { "USAF_Empty" };
        case 6: { "USAF_Empty" };
        case 7: { "USAF_1Rnd_CBU78B" };
        case 8: { "USAF_1Rnd_CBU87B" };
        case 9: { "USAF_1Rnd_CBU89B" };
    };

    _station15 = switch (_station5Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_1Rnd_F35_TANK" };
        case 2: { "USAF_1Rnd_AGM154A1" };
        case 3: { "1Rnd_GBU12_LGB" };
        case 4: { "USAF_1Rnd_GBU31" };
        case 5: { "USAF_1Rnd_RACKS_X2" };
        case 6: { "USAF_1Rnd_RACKS_X2" };
        case 7: { "USAF_1Rnd_RACKS_X2" };
    };

    _station16 = switch (_station6Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_1Rnd_F35_TANK" };
        case 2: { "USAF_1Rnd_AGM154A1" };
        case 3: { "1Rnd_GBU12_LGB" };
        case 4: { "USAF_1Rnd_GBU31" };
        case 5: { "USAF_1Rnd_RACKS_X2" };
        case 6: { "USAF_1Rnd_RACKS_X2" };
        case 7: { "USAF_1Rnd_RACKS_X2" };
    };

    _station17 = switch (_station17Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_1Rnd_AIM120I" };
    };
    
    _station18 = switch (_station18Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_1Rnd_AIM120I" };
    };

    _station19 = switch (_station19Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_1Rnd_GBU31" };
        case 2: { "USAF_1Rnd_GBU32" };
        case 3: { "USAF_1Rnd_GBU38" };
        case 4: { "USAF_1Rnd_GBU24" };
        case 5: { "USAF_F35A_8Rnd_GBU53_M" };
        case 6: { "USAF_1Rnd_AGM154A1" };
        case 7: { "USAF_1Rnd_AIM120" };
        case 8: { "USAF_1Rnd_CBU100" };
        case 9: { "USAF_1Rnd_JAGM" };
    };

    _station20 = switch (_station19Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_1Rnd_GBU31" };
        case 2: { "USAF_1Rnd_GBU32" };
        case 3: { "USAF_1Rnd_GBU38" };
        case 4: { "USAF_1Rnd_GBU24" };
        case 5: { "USAF_F35A_8Rnd_GBU53_M" };
        case 6: { "USAF_1Rnd_AGM154A1" };
        case 7: { "USAF_1Rnd_AIM120" };
        case 8: { "USAF_1Rnd_CBU100" };
        case 9: { "USAF_1Rnd_JAGM" };
    };

    _station21 = switch (_station19Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_Empty" };
        case 2: { "USAF_Empty" };
        case 3: { "USAF_Empty" };
        case 4: { "USAF_Empty" };
        case 5: { "USAF_F35A_8Rnd_GBU53_M" };
        case 6: { "USAF_Empty" };
        case 7: { "USAF_1Rnd_AIM120" };
        case 8: { "USAF_Empty" };
        case 9: { "USAF_1Rnd_JAGM" };
    };

    _station22 = switch (_station19Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_Empty" };
        case 2: { "USAF_Empty" };
        case 3: { "USAF_Empty" };
        case 4: { "USAF_Empty" };
        case 5: { "USAF_F35A_8Rnd_GBU53_M" };
        case 6: { "USAF_Empty" };
        case 7: { "USAF_1Rnd_AIM120" };
        case 8: { "USAF_Empty" };
        case 9: { "USAF_1Rnd_JAGM" };
    };

    _station23 = switch (_station19Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_Empty" };
        case 2: { "USAF_Empty" };
        case 3: { "USAF_Empty" };
        case 4: { "USAF_Empty" };
        case 5: { "USAF_F35A_8Rnd_GBU53_M" };
        case 6: { "USAF_Empty" };
        case 7: { "USAF_Empty" };
        case 8: { "USAF_Empty" };
        case 9: { "USAF_Empty" };
    };

    _station24 = switch (_station19Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_Empty" };
        case 2: { "USAF_Empty" };
        case 3: { "USAF_Empty" };
        case 4: { "USAF_Empty" };
        case 5: { "USAF_F35A_8Rnd_GBU53_M" };
        case 6: { "USAF_Empty" };
        case 7: { "USAF_Empty" };
        case 8: { "USAF_Empty" };
        case 9: { "USAF_Empty" };
    };

    _station25 = switch (_station19Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_Empty" };
        case 2: { "USAF_Empty" };
        case 3: { "USAF_Empty" };
        case 4: { "USAF_Empty" };
        case 5: { "USAF_F35A_8Rnd_GBU53_M" };
        case 6: { "USAF_Empty" };
        case 7: { "USAF_Empty" };
        case 8: { "USAF_Empty" };
        case 9: { "USAF_Empty" };
    };

    _station26 = switch (_station19Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_Empty" };
        case 2: { "USAF_Empty" };
        case 3: { "USAF_Empty" };
        case 4: { "USAF_Empty" };
        case 5: { "USAF_F35A_8Rnd_GBU53_M" };
        case 6: { "USAF_Empty" };
        case 7: { "USAF_Empty" };
        case 8: { "USAF_Empty" };
        case 9: { "USAF_Empty" };
    };

    _station27 = switch (_station19Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_Empty" };
        case 2: { "USAF_Empty" };
        case 3: { "USAF_Empty" };
        case 4: { "USAF_Empty" };
        case 5: { "USAF_Empty" };
        case 6: { "USAF_Empty" };
        case 7: { "USAF_Empty" };
        case 8: { "USAF_Empty" };
        case 9: { "USAF_Empty" };
    };

    _station28 = switch (_station19Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_Empty" };
        case 2: { "USAF_Empty" };
        case 3: { "USAF_Empty" };
        case 4: { "USAF_Empty" };
        case 5: { "USAF_Empty" };
        case 6: { "USAF_Empty" };
        case 7: { "USAF_Empty" };
        case 8: { "USAF_Empty" };
        case 9: { "USAF_Empty" };
    };

    _station29 = switch (_station19Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_Empty" };
        case 2: { "USAF_Empty" };
        case 3: { "USAF_Empty" };
        case 4: { "USAF_Empty" };
        case 5: { "USAF_Empty" };
        case 6: { "USAF_Empty" };
        case 7: { "USAF_Empty" };
        case 8: { "USAF_Empty" };
        case 9: { "USAF_Empty" };
    };

    _station30 = switch (_station19Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_Empty" };
        case 2: { "USAF_Empty" };
        case 3: { "USAF_Empty" };
        case 4: { "USAF_Empty" };
        case 5: { "USAF_Empty" };
        case 6: { "USAF_Empty" };
        case 7: { "USAF_Empty" };
        case 8: { "USAF_Empty" };
        case 9: { "USAF_Empty" };
    };

    _station31 = switch (_station5Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_Empty" };
        case 2: { "USAF_Empty" };
        case 3: { "USAF_Empty" };
        case 4: { "USAF_Empty" };
        case 5: { "USAF_1Rnd_CBU78B" };
        case 6: { "USAF_1Rnd_CBU87B" };
        case 7: { "USAF_1Rnd_CBU89B" };
    };

    _station32 = switch (_station5Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_Empty" };
        case 2: { "USAF_Empty" };
        case 3: { "USAF_Empty" };
        case 4: { "USAF_Empty" };
        case 5: { "USAF_1Rnd_CBU78B" };
        case 6: { "USAF_1Rnd_CBU87B" };
        case 7: { "USAF_1Rnd_CBU89B" };
    };

    _station33 = switch (_station6Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_Empty" };
        case 2: { "USAF_Empty" };
        case 3: { "USAF_Empty" };
        case 4: { "USAF_Empty" };
        case 5: { "USAF_1Rnd_CBU78B" };
        case 6: { "USAF_1Rnd_CBU87B" };
        case 7: { "USAF_1Rnd_CBU89B" };
    };

    _station34 = switch (_station6Index) do {
        case 0: { "USAF_Empty" };
        case 1: { "USAF_Empty" };
        case 2: { "USAF_Empty" };
        case 3: { "USAF_Empty" };
        case 4: { "USAF_Empty" };
        case 5: { "USAF_1Rnd_CBU78B" };
        case 6: { "USAF_1Rnd_CBU87B" };
        case 7: { "USAF_1Rnd_CBU89B" };
    };
    
    [_plane,[_station1,_station2,_station3,_station4,_station5,_station6,_station7,_station8,_station9,_station10,_station11,_station12,_station13,_station14,_station15,_station16,_station17,_station18,_station19,_station20,_station21,_station22,_station23,_station24,_station25,_station26,_station27,_station28,_station29,_station30,_station31,_station32,_station33,_station34]] call FUNC(loadoutDynamic);
    closeDialog 0;
};

[] call GVAR(Menu_fnc_Open);
