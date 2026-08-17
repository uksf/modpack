class GVAR(consoleInspector) {
    idd = IDD_CONSOLE_INSPECTOR;
    movingEnable = 1;
    enableSimulation = 1;
    onLoad = QUOTE(uiNamespace setVariable [ARR_2(QQGVAR(consoleInspector),_this select 0)]);
    class controlsBackground {
        class Background : RscText {
            idc = -1;
            x = "safeZoneX + 0.04 * safeZoneW";
            y = "safeZoneY + 0.08 * safeZoneH";
            w = "0.92 * safeZoneW";
            h = "0.84 * safeZoneH";
            colorBackground[] = {0.03, 0.04, 0.05, 0.94};
        };
    };
    class controls {
        class Title : RscText {
            idc = IDC_CONSOLE_TITLE;
            x = "safeZoneX + 0.05 * safeZoneW";
            y = "safeZoneY + 0.09 * safeZoneH";
            w = "0.38 * safeZoneW";
            h = "0.035 * safeZoneH";
            sizeEx = "0.024 * safeZoneH";
            text = "";
        };
        class Profile : RscText {
            idc = IDC_CONSOLE_PROFILE;
            x = "safeZoneX + 0.44 * safeZoneW";
            y = "safeZoneY + 0.09 * safeZoneH";
            w = "0.19 * safeZoneW";
            h = "0.035 * safeZoneH";
            sizeEx = "0.018 * safeZoneH";
            text = "";
        };
        class Picker : RscCombo {
            idc = IDC_CONSOLE_PICKER;
            x = "safeZoneX + 0.64 * safeZoneW";
            y = "safeZoneY + 0.09 * safeZoneH";
            w = "0.3 * safeZoneW";
            h = "0.035 * safeZoneH";
        };
        class StateGroup : RscControlsGroup {
            idc = -1;
            x = "safeZoneX + 0.05 * safeZoneW";
            y = "safeZoneY + 0.14 * safeZoneH";
            w = "0.264 * safeZoneW";
            h = "0.68 * safeZoneH";
            class controls {
                class Details : RscStructuredText {
                    idc = IDC_CONSOLE_DETAILS;
                    x = 0;
                    y = 0;
                    w = "0.254 * safeZoneW";
                    h = "1.2 * safeZoneH";
                    colorBackground[] = {0, 0, 0, 0.25};
                    text = "";
                };
            };
        };
        class ExchangeGroup : RscControlsGroup {
            idc = -1;
            x = "safeZoneX + 0.324 * safeZoneW";
            y = "safeZoneY + 0.14 * safeZoneH";
            w = "0.282 * safeZoneW";
            h = "0.68 * safeZoneH";
            class controls {
                class Pipeline : RscStructuredText {
                    idc = IDC_CONSOLE_PIPELINE;
                    x = 0;
                    y = 0;
                    w = "0.272 * safeZoneW";
                    h = "1.2 * safeZoneH";
                    colorBackground[] = {0, 0, 0, 0.25};
                    text = "";
                };
            };
        };
        class TranscriptGroup : RscControlsGroup {
            idc = -1;
            x = "safeZoneX + 0.616 * safeZoneW";
            y = "safeZoneY + 0.14 * safeZoneH";
            w = "0.334 * safeZoneW";
            h = "0.68 * safeZoneH";
            class controls {
                class Transcript : RscStructuredText {
                    idc = IDC_CONSOLE_TRANSCRIPT;
                    x = 0;
                    y = 0;
                    w = "0.324 * safeZoneW";
                    h = "1.6 * safeZoneH";
                    colorBackground[] = {0, 0, 0, 0.25};
                    text = "";
                };
            };
        };
        class Reset : RscButton {
            idc = IDC_CONSOLE_RESET;
            x = "safeZoneX + 0.05 * safeZoneW";
            y = "safeZoneY + 0.84 * safeZoneH";
            w = "0.14 * safeZoneW";
            h = "0.045 * safeZoneH";
            text = "Reset guarded";
            action = "['reset'] call uksf_npc_fnc_consoleAction";
        };
        class Cancel : Reset {
            idc = IDC_CONSOLE_CANCEL;
            x = "safeZoneX + 0.2 * safeZoneW";
            text = "Cancel turn";
            action = "['cancel'] call uksf_npc_fnc_consoleAction";
        };
        class Mute : Reset {
            idc = IDC_CONSOLE_MUTE;
            x = "safeZoneX + 0.35 * safeZoneW";
            text = "Mute";
            action = "['mute'] call uksf_npc_fnc_consoleAction";
        };
        class Unmute : Reset {
            idc = IDC_CONSOLE_UNMUTE;
            x = "safeZoneX + 0.5 * safeZoneW";
            text = "Unmute";
            action = "['unmute'] call uksf_npc_fnc_consoleAction";
        };
        class Close : Reset {
            idc = -1;
            x = "safeZoneX + 0.8 * safeZoneW";
            text = "Close";
            action = "call uksf_npc_fnc_consoleCloseInspector";
        };
    };
};
