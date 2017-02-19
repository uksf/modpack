class RscInGameUI {
    class Rsc_UKSF_Air_Limited;
    class Rsc_UKSF_F35_Limited : Rsc_UKSF_Air_Limited {
        controls[] = {
            "WeaponInfoControlsGroupRight",
            "CA_TextFlaresMode",
            "CA_TextFlares",
            "CA_VehicleToggles",
            "CA_Radar",
            "CA_ValueFuel"
        };
    };
};
class IGUIBack;
class RscFrame;
class RscPicture;
class RscCombo;
class RscButtonMenu;
class RscMapControl;
class RscObject;
class RscText;
class RscHTML;
class RscTextCheckbox;
class RscEdit;
class GVAR(RscButton) : RscButtonMenu {
    animTextureNormal = "\USAF_F35A\DATA\UI\USAF_F35A_GUI_main_button_normal_ca.paa";
    animTextureDisabled = "\USAF_F35A\DATA\UI\USAF_F35A_GUI_main_button_disabled_ca.paa";
    animTextureOver = "\USAF_F35A\DATA\UI\USAF_F35A_GUI_main_button_over_ca.paa";
    animTextureFocused = "\USAF_F35A\DATA\UI\USAF_F35A_GUI_main_button_focus_ca.paa";
    animTexturePressed = "\USAF_F35A\DATA\UI\USAF_F35A_GUI_main_button_down_ca.paa";
    animTextureDefault = "\USAF_F35A\DATA\UI\USAF_F35A_GUI_main_button_default_ca.paa";
    colorBackground[] = { 0,0,0,0.80000001 };
    colorBackground2[] = { 1,1,1,0.5 };
    color[] = { 1,1,1,1 };
    color2[] = { 1,1,1,1 };
    colorText[] = { 1,1,1,1 };
    colorDisabled[] = { 1,1,1,0.25 };
};
class GVAR(Rsc_Service_Main) {
    idd = 3000;
    movingenable = "false";
    onLoad = QUOTE(uiNamespace setVariable [ARR_2(QQGVAR(Service_Menu),(_this select 0))]);
    class Controls {
        class GVAR(Rsc_Service_Main_Box) : RscPicture {
            idc = 1200;
            x = "safezoneX";
            y = "safezoneY";
            w = "0.1 + safezoneW";
            h = "0.1 + safezoneH";
            text = "\USAF_F35A\data\UI\USAF_F35A_GUI_background.paa";
        };
        class GVAR(Rsc_Service_Main_Loadouts) : RscPicture {
            idc = 1204;
            text = "\USAF_F35A\data\UI\USAF_F35A_GUI_main_menu.paa";
            x = "0 * safezoneW + safezoneX";
            y = "0.052 * safezoneH + safezoneY";
            w = "1 * safezoneW";
            h = "0.84 * safezoneH";
        };
        class GVAR(Rsc_Service_Main_Frame) : RscFrame {
            idc = 1205;
            x = "0.005 * safezoneW + safezoneX";
            y = "0.005 * safezoneH + safezoneY";
            w = "0.99 * safezoneW";
            h = "0.99 * safezoneH";
        };
        class GVAR(Rsc_Service_Main_Button_Loadouts) : GVAR(RscButton) {
            idc = 1610;
            x = "0.456693 * safezoneW + safezoneX";
            y = "0.23114 * safezoneH + safezoneY";
            w = "0.0826794 * safezoneW";
            h = "0.13723 * safezoneH";
            text = "";
            size = 0.023;
            tooltip = "Loadout selection menu";
            action = QUOTE([] call GVAR(Menu_fnc_Loadout_Loadouts));
        };
        class GVAR(Rsc_Service_Main_Button_Close) : GVAR(RscButton) {
            idc = 1614;
            x = "0.877963 * safezoneW + safezoneX";
            y = "0.110712 * safezoneH + safezoneY";
            w = "0.094491 * safezoneW";
            h = "0.0255 * safezoneH";
            text = "";
            size = 0.023;
            tooltip = "Close this menu";
            action = "closeDialog 0";
        };
    };
};
class GVAR(Rsc_Service_Loadout) {
    idd = 3010;
    movingenable = "false";
    onLoad = QUOTE(uiNamespace setVariable [ARR_2(QQGVAR(Service_Menu),(_this select 0))]);
    class Controls {
        class GVAR(Rsc_Service_Loadout_Box) : RscPicture {
            idc = 1200;
            x = "safezoneX";
            y = "safezoneY";
            w = "0.1 + safezoneW";
            h = "0.1 + safezoneH";
            text = "\USAF_F35A\data\UI\USAF_F35A_GUI_background.paa";
        };
        class GVAR(Rsc_Service_Loadout_Loadouts) : RscPicture {
            idc = 1205;
            text = "\USAF_F35A\data\UI\USAF_F35A_GUI_main_loadouts.paa";
            x = "0 * safezoneW + safezoneX";
            y = "0.052 * safezoneH + safezoneY";
            w = "1 * safezoneW";
            h = "0.84 * safezoneH";
        };
        class GVAR(Rsc_Service_Loadout_Frame) : RscFrame {
            idc = 1204;
            x = "0.005 * safezoneW + safezoneX";
            y = "0.005 * safezoneH + safezoneY";
            w = "0.99 * safezoneW";
            h = "0.99 * safezoneH";
        };
        class GVAR(Rsc_Service_Loadout_Button_Load) : GVAR(RscButton) {
            idc = 1600;
            x = "0.422572 * safezoneW + safezoneX";
            y = "0.634429 * safezoneH + safezoneY";
            w = "0.1490 * safezoneW";
            h = "0.0898 * safezoneH";
            text = "";
            size = 0.023;
            tooltip = "Apply custom loadout";
            action = QUOTE([] call GVAR(Menu_fnc_Loadout_Exec));
        };
        class GVAR(Rsc_Service_Loadout_Combo_S1) : RscCombo {
            idc = 3101;
            x = "0.159687 * safezoneW + safezoneX";
            y = "0.368 * safezoneH + safezoneY";
            w = "0.0879296 * safezoneW";
            h = "0.0280067 * safezoneH";
            tooltip = "Weapon station 1";
        };
        class GVAR(Rsc_Service_Loadout_Combo_S2) : RscCombo {
            idc = 3102;
            x = "0.742344 * safezoneW + safezoneX";
            y = "0.368 * safezoneH + safezoneY";
            w = "0.0879296 * safezoneW";
            h = "0.0280067 * safezoneH";
            tooltip = "Weapon station 2";
        };
        class GVAR(Rsc_Service_Loadout_Combo_S3) : RscCombo {
            idc = 3103;
            x = "0.216406 * safezoneW + safezoneX";
            y = "0.401 * safezoneH + safezoneY";
            w = "0.0879296 * safezoneW";
            h = "0.0280067 * safezoneH";
            tooltip = "Weapon station 3";
        };
        class GVAR(Rsc_Service_Loadout_Combo_S4) : RscCombo {
            idc = 3104;
            x = "0.690781 * safezoneW + safezoneX";
            y = "0.412 * safezoneH + safezoneY";
            w = "0.0879296 * safezoneW";
            h = "0.0280067 * safezoneH";
            tooltip = "Weapon station 4";
        };
        class GVAR(Rsc_Service_Loadout_Combo_S5) : RscCombo {
            idc = 3105;
            x = "0.262812 * safezoneW + safezoneX";
            y = "0.445 * safezoneH + safezoneY";
            w = "0.0879296 * safezoneW";
            h = "0.0280067 * safezoneH";
            tooltip = "Weapon station 5";
        };
        class GVAR(Rsc_Service_Loadout_Combo_S6) : RscCombo {
            idc = 3106;
            x = "0.649531 * safezoneW + safezoneX";
            y = "0.445 * safezoneH + safezoneY";
            w = "0.0879296 * safezoneW";
            h = "0.0280067 * safezoneH";
            tooltip = "Weapon station 6";
        };
        class GVAR(Rsc_Service_Loadout_Combo_S7) : RscCombo {
            idc = 3107;
            x = "0.391719 * safezoneW + safezoneX";
            y = "0.489 * safezoneH + safezoneY";
            w = "0.0825 * safezoneW";
            h = "0.033 * safezoneH";
            tooltip = "Weapon station 7";
        };
        class GVAR(Rsc_Service_Loadout_Combo_S8) : RscCombo {
            idc = 3108;
            x = "0.525781 * safezoneW + safezoneX";
            y = "0.489 * safezoneH + safezoneY";
            w = "0.0876563 * safezoneW";
            h = "0.033 * safezoneH";
            tooltip = "Weapon station 8";
        };
        class GVAR(Rsc_Service_Loadout_Combo_S9) : RscCombo {
            idc = 3109;
            x = "0.45875 * safezoneW + safezoneX";
            y = "0.555 * safezoneH + safezoneY";
            w = "0.0876563 * safezoneW";
            h = "0.033 * safezoneH";
            tooltip = "Weapon station 9";
        };
        class GVAR(Rsc_Service_Loadout_Button_Rearm) : GVAR(RscButton) {
            idc = 1601;
            x = "0.162724 * safezoneW + safezoneX";
            y = "0.740852 * safezoneH + safezoneY";
            w = "0.0813676 * safezoneW";
            h = "0.134434 * safezoneH";
            text = "";
            size = 0.023;
            tooltip = "Rearm aircraft";
            action = QUOTE([] call GVAR(Menu_fnc_Loadout_Cas));
        };
        class GVAR(Rsc_Service_Loadout_Button_Repair) : GVAR(RscButton) {
            idc = 1602;
            x = "0.261148 * safezoneW + safezoneX";
            y = "0.740854 * safezoneH + safezoneY";
            w = "0.0813676 * safezoneW";
            h = "0.134434 * safezoneH";
            text = "";
            size = 0.023;
            tooltip = "Repair aircraft";
            action = QUOTE([] call GVAR(Menu_fnc_Loadout_Repair));
        };
        class GVAR(Rsc_Service_Loadout_Button_L1) : GVAR(RscButton) {
            idc = 1604;
            x = "0.556433 * safezoneW + safezoneX";
            y = "0.740854 * safezoneH + safezoneY";
            w = "0.0813676 * safezoneW";
            h = "0.134434 * safezoneH";
            text = "SEAD";
            size = 0.075;
            tooltip = "Load SEAD Preset";
            action = QUOTE([] call GVAR(Menu_fnc_Loadout_Sead));
        };
        class GVAR(Rsc_Service_Loadout_Button_L2) : GVAR(RscButton) {
            idc = 1605;
            x = "0.653547 * safezoneW + safezoneX";
            y = "0.740854 * safezoneH + safezoneY";
            w = "0.0813676 * safezoneW";
            h = "0.134434 * safezoneH";
            text = "CAP";
            size = 0.075;
            tooltip = "Load CAP Preset";
            action = QUOTE([] call GVAR(Menu_fnc_Loadout_Cap));
        };
        class GVAR(Rsc_Service_Loadout_Button_L3) : GVAR(RscButton) {
            idc = 1606;
            x = "0.459317 * safezoneW + safezoneX";
            y = "0.740854 * safezoneH + safezoneY";
            w = "0.0813676 * safezoneW";
            h = "0.134434 * safezoneH";
            text = "CAS";
            size = 0.075;
            tooltip = "Load CAS Preset";
            action = QUOTE([] call GVAR(Menu_fnc_Loadout_Cas));
        };
        class GVAR(Rsc_Service_Loadout_Button_Empty) : GVAR(RscButton) {
            idc = 1607;
            x = "0.750664 * safezoneW + safezoneX";
            y = "0.740854 * safezoneH + safezoneY";
            w = "0.0813676 * safezoneW";
            h = "0.134434 * safezoneH";
            text = "Empty";
            size = 0.075;
            tooltip = "Empty loadout, no weapons";
            action = QUOTE([] call GVAR(Menu_fnc_Loadout_Empty));
        };
        class GVAR(Rsc_Service_Loadout_Button_Return) : GVAR(RscButton) {
            idc = 1608;
            x = "0.787409 * safezoneW + safezoneX";
            y = "0.110712 * safezoneH + safezoneY";
            w = "0.0918668 * safezoneW";
            h = "0.0280066 * safezoneH";
            text = "";
            size = 0.023;
            tooltip = "Return to main menu";
            action = QUOTE([] call GVAR(Menu_fnc_Return));
        };
        class GVAR(Rsc_Service_Loadout_Button_Close) : GVAR(RscButton) {
            idc = 1609;
            x = "0.877963 * safezoneW + safezoneX";
            y = "0.110712 * safezoneH + safezoneY";
            w = "0.094491 * safezoneW";
            h = "0.0255 * safezoneH";
            text = "";
            size = 0.023;
            tooltip = "Close this menu";
            action = "closeDialog 0";
        };
    };
};
