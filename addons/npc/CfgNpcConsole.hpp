class GVAR(consoleInspector) {
    idd = IDD_CONSOLE_INSPECTOR;
    movingEnable = 1;
    enableSimulation = 1;
    onLoad = QUOTE(uiNamespace setVariable [ARR_2(QQGVAR(consoleInspector),_this select 0)]);
    class controlsBackground {
        class Background : RscText {
            idc = -1;
            x = "safeZoneX + 0.15 * safeZoneW";
            y = "safeZoneY + 0.1 * safeZoneH";
            w = "0.7 * safeZoneW";
            h = "0.8 * safeZoneH";
            colorBackground[] = {0.03, 0.04, 0.05, 0.94};
        };
    };
    class controls {
        class Title : RscText {
            idc = IDC_CONSOLE_TITLE;
            x = "safeZoneX + 0.17 * safeZoneW";
            y = "safeZoneY + 0.12 * safeZoneH";
            w = "0.66 * safeZoneW";
            h = "0.035 * safeZoneH";
            sizeEx = "0.024 * safeZoneH";
            text = "NPC Console";
        };
        class Picker : RscCombo {
            idc = IDC_CONSOLE_PICKER;
            x = "safeZoneX + 0.17 * safeZoneW";
            y = "safeZoneY + 0.165 * safeZoneH";
            w = "0.28 * safeZoneW";
            h = "0.035 * safeZoneH";
        };
        class DetailsGroup : RscControlsGroup {
            idc = -1;
            x = "safeZoneX + 0.17 * safeZoneW";
            y = "safeZoneY + 0.215 * safeZoneH";
            w = "0.66 * safeZoneW";
            h = "0.58 * safeZoneH";
            class controls {
                class Details : RscStructuredText {
                    idc = IDC_CONSOLE_DETAILS;
                    x = 0;
                    y = 0;
                    w = "0.64 * safeZoneW";
                    h = "1.1 * safeZoneH";
                    colorBackground[] = {0, 0, 0, 0.25};
                    text = "";
                };
            };
        };
        class Reset : RscButton {
            idc = IDC_CONSOLE_RESET;
            x = "safeZoneX + 0.17 * safeZoneW";
            y = "safeZoneY + 0.82 * safeZoneH";
            w = "0.12 * safeZoneW";
            h = "0.045 * safeZoneH";
            text = "Reset guarded";
            action = "['reset'] call uksf_npc_fnc_consoleAction";
        };
        class Cancel : Reset {
            idc = IDC_CONSOLE_CANCEL;
            x = "safeZoneX + 0.305 * safeZoneW";
            text = "Cancel turn";
            action = "['cancel'] call uksf_npc_fnc_consoleAction";
        };
        class Mute : Reset {
            idc = IDC_CONSOLE_MUTE;
            x = "safeZoneX + 0.44 * safeZoneW";
            text = "Mute";
            action = "['mute'] call uksf_npc_fnc_consoleAction";
        };
        class Unmute : Reset {
            idc = IDC_CONSOLE_UNMUTE;
            x = "safeZoneX + 0.575 * safeZoneW";
            text = "Unmute";
            action = "['unmute'] call uksf_npc_fnc_consoleAction";
        };
        class Close : Reset {
            idc = -1;
            x = "safeZoneX + 0.71 * safeZoneW";
            text = "Close";
            action = "call uksf_npc_fnc_consoleCloseInspector";
        };
    };
};
