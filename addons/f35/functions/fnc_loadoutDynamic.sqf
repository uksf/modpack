/*
    Author:
        Tim Beswick, John_Spartan, Saul, USAF Team

    Description:
        Applies given loadout

    Parameters:
        0: Plane <OBJECT>
        1: Array of magazines to load <ARRAY>

    Return value:
        Nothing
*/
#include "script_component.hpp"

params ["_plane", "_magazines"];

[{
    ((_this select 0) getVariable ["Rearming_done_switch", 1]) isEqualTo 1
}, {
    params ["_plane", "_magazines"]; 

    _plane selectWeapon "Fuller_master_arms_safe";
    _plane setVariable ["Rearming_done_switch", 0, false];

    if (speed _plane > 1) exitWith {
        [parseText format ["<t align = 'center' color = '#FF0000'>Rearming Canceled</t>"], [0.25, 1, 0.5, 0.05], [1, 1], 1] spawn BIS_fnc_textTiles;
    };
    [parseText format ["<t align = 'center' color = '#00CC00'>Rearming...</t>"], [0.25, 1, 0.5, 0.05], [1, 1], 1] spawn BIS_fnc_textTiles;

    //ROMEVE ALL POSSIBLE DEFAULT WEAPONS
    _plane removeWeapon "USAF_AIM9X_Launcher";
    _plane removeWeapon "USAF_AIM120_Launcher";
    _plane removeWeapon "USAF_AIM120I_Launcher";
    _plane removeWeapon "USAF_AGM65_Launcher";
    _plane removeWeapon "USAF_AGM84_Launcher";
    _plane removeWeapon "USAF_AGM86C_Launcher";
    _plane removeWeapon "USAF_AGM88_Launcher";
    _plane removeWeapon "USAF_AGM65E_Launcher";
    _plane removeWeapon "USAF_FFARLauncher_unguided";
    _plane removeWeapon "USAF_FFARLauncher_Laser";
    _plane removeWeapon "USAF_MK82_Launcher";
    _plane removeWeapon "USAF_MK84_Launcher";
    _plane removeWeapon "USAF_GBU12_Launcher";
    _plane removeWeapon "USAF_GBU24_Launcher";
    _plane removeWeapon "USAF_GBU31_Launcher";
    _plane removeWeapon "USAF_GBU32_Launcher";
    _plane removeWeapon "USAF_GBU38_Launcher";
    _plane removeWeapon "USAF_GBU39_Launcher";
    _plane removeWeapon "USAF_F35A_GBU53_int_W";
    _plane removeWeapon "USAF_AGM154A1_Launcher";
    _plane removeWeapon "USAF_CBU78B_Launcher";
    _plane removeWeapon "USAF_CBU87B_Launcher";
    _plane removeWeapon "USAF_CBU89B_Launcher";
    _plane removeWeapon "USAF_CBU100_Launcher";
    _plane removeWeapon "USAF_MK77_Launcher";
    _plane removeWeapon "USAF_JAGM_Launcher";

    _plane removeMagazines "USAF_1Rnd_AIM9X";
    _plane removeMagazines "USAF_1Rnd_AIM120";
    _plane removeMagazines "USAF_1Rnd_AIM120I";
    _plane removeMagazines "USAF_1Rnd_LAU117";
    _plane removeMagazines "USAF_1Rnd_DUALRAIL";
    _plane removeMagazines "USAF_1Rnd_LAU88";
    _plane removeMagazines "USAF_1Rnd_RACKS_X2";
    _plane removeMagazines "USAF_1Rnd_RACKS_X3";
    _plane removeMagazines "USAF_1Rnd_MK82RACK";
    _plane removeMagazines "USAF_1Rnd_Station1";
    _plane removeMagazines "USAF_1Rnd_Station2";
    _plane removeMagazines "USAF_1Rnd_StationL";
    _plane removeMagazines "USAF_1Rnd_StationR";
    _plane removeMagazines "USAF_1Rnd_GBU12";
    _plane removeMagazines "USAF_1Rnd_GBU24";
    _plane removeMagazines "USAF_1Rnd_GBU31";
    _plane removeMagazines "USAF_1Rnd_GBU32";
    _plane removeMagazines "USAF_1Rnd_GBU38";
    _plane removeMagazines "USAF_1Rnd_GBU39";
    _plane removeMagazines "USAF_1Rnd_MK82";
    _plane removeMagazines "USAF_1Rnd_MK84";
    _plane removeMagazines "USAF_1Rnd_GBU31";
    _plane removeMagazines "USAF_F35A_8Rnd_GBU53_M";
    _plane removeMagazines "USAF_1Rnd_AGM65";
    _plane removeMagazines "USAF_1Rnd_AGM65E";
    _plane removeMagazines "USAF_1Rnd_AGM84";
    _plane removeMagazines "USAF_1Rnd_AGM86";
    _plane removeMagazines "USAF_1Rnd_AGM88";
    _plane removeMagazines "USAF_1Rnd_AGM154A1";
    _plane removeMagazines "USAF_7Rnd_HYDRA70_unguided";
    _plane removeMagazines "USAF_19Rnd_HYDRA70_unguided";
    _plane removeMagazines "USAF_7Rnd_HYDRA70_laser";
    _plane removeMagazines "USAF_19Rnd_HYDRA70_laser";
    _plane removeMagazines "USAF_1Rnd_FFARPOD7";
    _plane removeMagazines "USAF_1Rnd_FFARPOD19";
    _plane removeMagazines "USAF_1Rnd_F16_FUEL";
    _plane removeMagazines "USAF_1Rnd_F16_DROPTANK";
    _plane removeMagazines "USAF_1Rnd_F35_TANK";
    _plane removeMagazines "USAF_1Rnd_ANALQ131";
    _plane removeMagazines "USAF_1Rnd_ANAAQ28";
    _plane removeMagazines "USAF_1Rnd_Altflir_pod";
    _plane removeMagazines "USAF_1Rnd_BRU61A";
    _plane removeMagazines "USAF_empty";
    _plane removeMagazines "USAF_Fake_empty";
    _plane removeMagazines "USAF_1Rnd_CBU78B";
    _plane removeMagazines "USAF_1Rnd_CBU89B";
    _plane removeMagazines "USAF_1Rnd_CBU87B";
    _plane removeMagazines "USAF_1Rnd_CBU100";
    _plane removeMagazines "USAF_1Rnd_MK77";
    _plane removeMagazines "USAF_1Rnd_JAGM";

    _plane animate ["pylon_1_hide",0];
    _plane animate ["pylon_2_hide",0];
    _plane animate ["pylon_3_hide",0];
    _plane animate ["pylon_4_hide",0];
    _plane animate ["pylon_5_hide",0];
    _plane animate ["pylon_6_hide",0];

    [{
        params ["_args", "_idPFH"];
        _args params ["_plane", "_magazines", "_i", "_j"];

        if (_i >= 34) exitWith {
            [_idPFH] call cba_fnc_removePerFrameHandler;
            _loadout = magazines _plane;
            if (("USAF_1Rnd_AIM9X" in _loadout)) then {_plane addWeapon "USAF_AIM9X_Launcher";};
            if (("USAF_1Rnd_AIM120" in _loadout)) then {_plane addWeapon "USAF_AIM120_Launcher";};
            if (("USAF_1Rnd_AIM120I" in _loadout)) then {_plane addWeapon "USAF_AIM120I_Launcher";};
            if (("USAF_7Rnd_HYDRA70_unguided" in _loadout)) then {_plane addWeapon "USAF_FFARLauncher_unguided";};
            if (("USAF_19Rnd_HYDRA70_unguided" in _loadout)) then {_plane addWeapon "USAF_FFARLauncher_unguided";};
            if (("USAF_7Rnd_HYDRA70_laser" in _loadout)) then {_plane addWeapon "USAF_FFARLauncher_Laser";};
            if (("USAF_19Rnd_HYDRA70_laser" in _loadout)) then {_plane addWeapon "USAF_FFARLauncher_Laser";};
            if (("USAF_19Rnd_HYDRA70_unguided" in _loadout)) then {_plane addWeapon "USAF_FFARLauncher_Laser";};
            if (("USAF_19Rnd_HYDRA70_unguided" in _loadout)) then {_plane addWeapon "USAF_FFARLauncher_unguided";};
            if (("USAF_1Rnd_MK82" in _loadout)) then {_plane addWeapon "USAF_MK82_Launcher";};
            if (("USAF_1Rnd_MK84" in _loadout)) then {_plane addWeapon "USAF_MK84_Launcher";};
            if (("USAF_1Rnd_GBU12" in _loadout)) then {_plane addWeapon "USAF_GBU12_Launcher";};
            if (("USAF_1Rnd_GBU24" in _loadout)) then {_plane addWeapon "USAF_GBU24_Launcher";};
            if (("USAF_1Rnd_GBU31" in _loadout)) then {_plane addWeapon "USAF_GBU31_Launcher";};
            if (("USAF_1Rnd_GBU32" in _loadout)) then {_plane addWeapon "USAF_GBU32_Launcher";};
            if (("USAF_1Rnd_GBU38" in _loadout)) then {_plane addWeapon "USAF_GBU38_Launcher";};
            if (("USAF_1Rnd_GBU39" in _loadout)) then {_plane addWeapon "USAF_GBU39_Launcher";};
            if (("USAF_F35A_8Rnd_GBU53_M" in _loadout)) then {_plane addWeapon "USAF_F35A_GBU53_int_W";};
            if (("USAF_1Rnd_AGM65" in _loadout)) then {_plane addWeapon "USAF_AGM65_Launcher";};
            if (("USAF_1Rnd_AGM65E" in _loadout)) then {_plane addWeapon "USAF_AGM65E_Launcher";};
            if (("USAF_1Rnd_AGM84" in _loadout)) then {_plane addWeapon "USAF_AGM84_Launcher";};
            if (("USAF_1Rnd_AGM86" in _loadout)) then {_plane addWeapon "USAF_AGM86C_Launcher";};
            if (("USAF_1Rnd_AGM88" in _loadout)) then {_plane addWeapon "USAF_AGM88_Launcher";};
            if (("USAF_1Rnd_AGM154A1" in _loadout)) then {_plane addWeapon "USAF_AGM154A1_Launcher";};
            if (("USAF_1Rnd_CBU78B" in _loadout)) then {_plane addWeapon "USAF_CBU78B_Launcher";};
            if (("USAF_1Rnd_CBU89B" in _loadout)) then {_plane addWeapon "USAF_CBU89B_Launcher";};
            if (("USAF_1Rnd_CBU87B" in _loadout)) then {_plane addWeapon "USAF_CBU87B_Launcher";};
            if (("USAF_1Rnd_CBU100" in _loadout)) then {_plane addWeapon "USAF_CBU100_Launcher";};
            if (("USAF_1Rnd_MK77" in _loadout)) then {_plane addWeapon "USAF_MK77_Launcher";};
            if (("USAF_1Rnd_JAGM" in _loadout)) then {_plane addWeapon "USAF_JAGM_Launcher";};
            _plane setVehicleAmmo 1;
            _plane selectWeapon "Fuller_master_arms_safe";
            _plane setVariable ["Rearming_done_switch", 1];
            [parseText format ["<t align = 'center' color = '#00CC00'>Rearming Complete</t>"], [0.25, 1, 0.5, 0.05], [1, 1], 5] spawn BIS_fnc_textTiles;
        };
        if (speed _plane > 1) exitWith {
            [parseText format ["<t align = 'center' color = '#FF0000'>Rearming Canceled</t>"], [0.25, 1, 0.5, 0.05], [1, 1], 1] spawn BIS_fnc_textTiles;
            [_idPFH] call cba_fnc_removePerFrameHandler;
        };

        [parseText format ["<t align = 'center' color = '#00CC00'>Rearming...</t>"], [0.25, 1, 0.5, 0.05], [1, 1], 1] spawn BIS_fnc_textTiles;
        _plane removeMagazines "USAF_Fake_empty";
        _new_magazine = _magazines select _i;
        diag_log _new_magazine;
        _plane addMagazine _new_magazine;
        for "_y" from 1 to _j do {
            _plane addMagazine "USAF_Fake_empty";
        };
        _args set [2, _i + 1];
        _args set [3, _j - 1];
    }, 0.1, [_plane, _magazines, 0, 34]] call cba_fnc_addPerFrameHandler;    
}, [_plane, _magazines]] call cba_fnc_waitUntilAndExecute;
