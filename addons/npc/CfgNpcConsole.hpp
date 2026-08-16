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
            w = "0.58 * safeZoneW";
            h = "0.035 * safeZoneH";
            sizeEx = "0.024 * safeZoneH";
            text = "NPC Console";
        };
        class Picker : RscCombo {
            idc = IDC_CONSOLE_PICKER;
            x = "safeZoneX + 0.64 * safeZoneW";
            y = "safeZoneY + 0.09 * safeZoneH";
            w = "0.3 * safeZoneW";
            h = "0.035 * safeZoneH";
        };
        class IdentityGroup : RscControlsGroup {
            idc = -1;
            x = "safeZoneX + 0.05 * safeZoneW";
            y = "safeZoneY + 0.14 * safeZoneH";
            w = "0.22 * safeZoneW";
            h = "0.68 * safeZoneH";
            class controls {
                class Details : RscStructuredText {
                    idc = IDC_CONSOLE_DETAILS;
                    x = 0;
                    y = 0;
                    w = "0.21 * safeZoneW";
                    h = "1.2 * safeZoneH";
                    colorBackground[] = {0, 0, 0, 0.25};
                    text = "";
                };
            };
        };
        class PipelineGroup : RscControlsGroup {
            idc = -1;
            x = "safeZoneX + 0.28 * safeZoneW";
            y = "safeZoneY + 0.14 * safeZoneH";
            w = "0.28 * safeZoneW";
            h = "0.68 * safeZoneH";
            class controls {
                class Pipeline : RscStructuredText {
                    idc = IDC_CONSOLE_PIPELINE;
                    x = 0;
                    y = 0;
                    w = "0.27 * safeZoneW";
                    h = "1.2 * safeZoneH";
                    colorBackground[] = {0, 0, 0, 0.25};
                    text = "";
                };
            };
        };
        class TranscriptGroup : RscControlsGroup {
            idc = -1;
            x = "safeZoneX + 0.57 * safeZoneW";
            y = "safeZoneY + 0.14 * safeZoneH";
            w = "0.37 * safeZoneW";
            h = "0.68 * safeZoneH";
            class controls {
                class Transcript : RscStructuredText {
                    idc = IDC_CONSOLE_TRANSCRIPT;
                    x = 0;
                    y = 0;
                    w = "0.36 * safeZoneW";
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
