/*
    Author:
        Tim Beswick, John_Spartan, Saul, USAF Team

    Description:
        Empties loadout

    Parameters:
        0: Plane <OBJECT>

    Return value:
        Nothing
*/
#include "script_component.hpp"

params ["_plane"];

// WEAPON CLASSNAME DEFINITIONS
_SAFE_weapon = "Fuller_master_arms_safe";
_AIM9X_weapon = "USAF_AIM9X_Launcher";
_AGM65_weapon = "USAF_AGM65_Launcher";
_AGM84_weapon = "USAF_AGM84_Launcher";
_AGM86_weapon = "USAF_AGM86C_Launcher";
_AGM88_weapon = "USAF_AGM88_Launcher";
_AIM120_weapon = "USAF_AIM120_Launcher";
_AIM120I_weapon = "USAF_AIM120I_Launcher";
_AGM65E_weapon = "USAF_AGM65E_Launcher";
_AGM154_weapon = "USAF_AGM154A1_Launcher";
_FFARU_weapon = "USAF_FFARLauncher_unguided";
_FFARL_weapon = "USAF_FFARLauncher_Laser";
_MK82_weapon = "USAF_MK82_Launcher";
_MK84_weapon = "USAF_MK84_Launcher";
_GBU12_weapon = "USAF_GBU12_Launcher";
_GBU24_weapon = "USAF_GBU24_Launcher";
_GBU31_weapon = "USAF_GBU31_Launcher";
_GBU32_weapon = "USAF_GBU32_Launcher";
_GBU38_weapon = "USAF_GBU38_Launcher";
_GBU39_weapon = "USAF_GBU39_Launcher";
_GBU53_weapon = "USAF_F35A_GBU53_int_W";
_CBU78_weapon = "USAF_CBU78B_Launcher";
_CBU87_weapon = "USAF_CBU87B_Launcher";
_CBU89_weapon = "USAF_CBU89B_Launcher";
_MK20_weapon = "USAF_CBU100_Launcher";
_MK77_weapon = "USAF_MK77_Launcher";
_JAGM_weapon = "USAF_JAGM_Launcher";


// MAGAZINE CLASSNAME DEFINITIONS
_AIM9X_magazine = "USAF_1Rnd_AIM9X";
_AIM120_magazine = "USAF_1Rnd_AIM120";
_AIM120I_magazine = "USAF_1Rnd_AIM120I";
_DUAL_RAIL_magazine = "USAF_1Rnd_DUALRAIL";
_TRIPPLE_RAIL_magazine = "USAF_1Rnd_LAU88";
_SINGLE_BOMB_magazine = "USAF_1Rnd_LAU117";
_DOUBLE_MISSILE_magazine = "USAF_1Rnd_RACKS_X2";
_TRIPPLE_MISSILE_magazine = "USAF_1Rnd_RACKS_X3";
_GBU12_magazine = "USAF_1Rnd_GBU12";
_GBU24_magazine = "USAF_1Rnd_GBU24";
_GBU38_magazine = "USAF_1Rnd_GBU38";
_GBU39_magazine = "USAF_1Rnd_GBU39";
_GBU31_magazine = "USAF_1Rnd_GBU31";
_GBU32_magazine = "USAF_1Rnd_GBU32";
_GBU53_magazine = "USAF_F35A_8Rnd_GBU53_M";
_MK82_magazine = "USAF_1Rnd_MK82";
_MK84_magazine = "USAF_1Rnd_MK84";
_MK82_RACK_magazine = "USAF_1Rnd_MK82RACK";
_F35_Station1_magazine = "USAF_1Rnd_Station1";
_F35_Station2_magazine = "USAF_1Rnd_Station2";
_F35_StationL_magazine = "USAF_1Rnd_StationL";
_F35_StationR_magazine = "USAF_1Rnd_StationR";
_FFARU7_magazine = "USAF_7Rnd_HYDRA70_unguided";
_FFARU19_magazine = "USAF_19Rnd_HYDRA70_unguided";
_FFARL7_magazine = "USAF_7Rnd_HYDRA70_laser";
_FFARL19_magazine = "USAF_19Rnd_HYDRA70_laser";
_FFAR_POD_magazine = "USAF_1Rnd_FFARPOD7";
_FFAR_POD2_magazine = "USAF_1Rnd_FFARPOD19";
_AGM65_magazine = "USAF_1Rnd_AGM65";
_AGM65E_magazine = "USAF_1Rnd_AGM65E";
_AGM84_magazine = "USAF_1Rnd_AGM84";
_AGM86_magazine = "USAF_1Rnd_AGM86";
_AGM88_magazine = "USAF_1Rnd_AGM88";
_AGM154_magazine = "USAF_1Rnd_AGM154A1";
_FUEL_TANK_1 = "USAF_1Rnd_F16_FUEL";
_FUEL_TANK_2 = "USAF_1Rnd_F16_DROPTANK";
_FUEL_TANK_3 = "USAF_1Rnd_F35_TANK";
_ANALQ131 = "USAF_1Rnd_ANALQ131";
_ANAAQ28 = "USAF_1Rnd_ANAAQ28";
_FlirPod = "USAF_1Rnd_Altflir_pod";
_BRU61A = "USAF_1Rnd_BRU61A";
_EMPTY_magazine = "USAF_empty";
_EMPTY_Fake_magazine = "USAF_Fake_empty";
_CBU78_M = "USAF_1Rnd_CBU78B";
_CBU89_M = "USAF_1Rnd_CBU89B";
_CBU87_M = "USAF_1Rnd_CBU87B";
_MK20_M = "USAF_1Rnd_CBU100";
_MK77_M = "USAF_1Rnd_MK77";
_JAGM_M = "USAF_1Rnd_JAGM";

// SWITCH PILOTS WEAPON TO SAFE
_plane selectWeapon _SAFE_weapon;
_plane setVariable ["Rearming_done_switch", 0];

// ROMEVE ALL POSSIBLE DEFAULT WEAPONS
_plane removeWeapon _AIM9X_weapon;
_plane removeWeapon _AIM120_weapon;
_plane removeWeapon _AIM120I_weapon;
_plane removeWeapon _AGM65_weapon;
_plane removeWeapon _AGM84_weapon;
_plane removeWeapon _AGM86_weapon;
_plane removeWeapon _AGM88_weapon;
_plane removeWeapon _AGM65E_weapon;
_plane removeWeapon _FFARU_weapon;
_plane removeWeapon _FFARL_weapon;
_plane removeWeapon _MK82_weapon;
_plane removeWeapon _MK84_weapon;
_plane removeWeapon _GBU12_weapon;
_plane removeWeapon _GBU24_weapon;
_plane removeWeapon _GBU31_weapon;
_plane removeWeapon _GBU32_weapon;
_plane removeWeapon _GBU38_weapon;
_plane removeWeapon _GBU39_weapon;
_plane removeWeapon _GBU53_weapon;
_plane removeWeapon _AGM154_weapon;
_plane removeWeapon _CBU78_weapon;
_plane removeWeapon _CBU87_weapon;
_plane removeWeapon _CBU89_weapon;
_plane removeWeapon _MK20_weapon;
_plane removeWeapon _MK77_weapon;
_plane removeWeapon _JAGM_weapon;

// ROMEVE ALL POSSIBLE DEFAULT MAGAZINES
_plane removeMagazines _AIM9X_magazine;
_plane removeMagazines _AIM120_magazine;
_plane removeMagazines _AIM120I_magazine;
_plane removeMagazines _SINGLE_BOMB_magazine;
_plane removeMagazines _DUAL_RAIL_magazine;
_plane removeMagazines _TRIPPLE_RAIL_magazine;
_plane removeMagazines _DOUBLE_MISSILE_magazine;
_plane removeMagazines _TRIPPLE_MISSILE_magazine;
_plane removeMagazines _MK82_RACK_magazine;
_plane removeMagazines _F35_Station1_magazine;
_plane removeMagazines _F35_Station2_magazine;
_plane removeMagazines _F35_StationL_magazine;
_plane removeMagazines _F35_StationR_magazine;
_plane removeMagazines _GBU12_magazine;
_plane removeMagazines _GBU24_magazine;
_plane removeMagazines _GBU31_magazine;
_plane removeMagazines _GBU32_magazine;
_plane removeMagazines _GBU38_magazine;
_plane removeMagazines _GBU39_magazine;
_plane removeMagazines _MK82_magazine;
_plane removeMagazines _MK84_magazine;
_plane removeMagazines _GBU31_magazine;
_plane removeMagazines _GBU53_magazine;
_plane removeMagazines _AGM65_magazine;
_plane removeMagazines _AGM65E_magazine;
_plane removeMagazines _AGM84_magazine;
_plane removeMagazines _AGM86_magazine;
_plane removeMagazines _AGM88_magazine;
_plane removeMagazines _AGM154_magazine;
_plane removeMagazines _FFARU7_magazine;
_plane removeMagazines _FFARU19_magazine;
_plane removeMagazines _FFARL7_magazine;
_plane removeMagazines _FFARL19_magazine;
_plane removeMagazines _FFAR_POD_magazine;
_plane removeMagazines _FFAR_POD2_magazine;
_plane removeMagazines _FUEL_TANK_1;
_plane removeMagazines _FUEL_TANK_2;
_plane removeMagazines _FUEL_TANK_3;
_plane removeMagazines _ANALQ131;
_plane removeMagazines _ANAAQ28;
_plane removeMagazines _FlirPod;
_plane removeMagazines _BRU61A;
_plane removeMagazines _EMPTY_magazine;
_plane removeMagazines _EMPTY_Fake_magazine;
_plane removeMagazines _CBU78_M;
_plane removeMagazines _CBU89_M;
_plane removeMagazines _CBU87_M;
_plane removeMagazines _MK20_M;
_plane removeMagazines _MK77_M;
_plane removeMagazines _JAGM_M;

// ANIMATE ALL HIDDEN SELECTIONS TO SUPPORT NEW LOADOUT
_plane animate ["pylon_1_hide",1];
_plane animate ["pylon_2_hide",1];
_plane animate ["pylon_3_hide",1];
_plane animate ["pylon_4_hide",1];
_plane animate ["pylon_5_hide",1];
_plane animate ["pylon_6_hide",1];

// FINALIZING FUNCTION
_plane setVehicleAmmo 1;
_plane selectWeapon _SAFE_weapon;
_plane setVariable ["Rearming_done_switch", 1, false];
