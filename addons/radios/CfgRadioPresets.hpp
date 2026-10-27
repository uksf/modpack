class RscText;
class RscStructuredText;
class RscListBox;
class RscEdit;
class RscButtonMenu;

class GVAR(presets) {
    idd = IDD_RADIO_PRESETS;
    movingEnable = 0;
    enableSimulation = 1;
    class controlsBackground {
        class Background: RscText {
            idc = -1;
            x = "safeZoneX + 0.3 * safeZoneW";
            y = "safeZoneY + 0.25 * safeZoneH";
            w = "0.4 * safeZoneW";
            h = "0.5 * safeZoneH";
            colorBackground[] = {0, 0, 0, 0.85};
        };
        class Title: RscText {
            idc = -1;
            x = "safeZoneX + 0.3 * safeZoneW";
            y = "safeZoneY + 0.25 * safeZoneH";
            w = "0.4 * safeZoneW";
            h = "0.035 * safeZoneH";
            sizeEx = "0.026 * safeZoneH";
            text = "Radio Presets";
            colorBackground[] = {0.2, 0.25, 0.2, 1};
        };
    };
    class controls {
        class List: RscListBox {
            idc = IDC_RADIO_PRESETS_LIST;
            x = "safeZoneX + 0.31 * safeZoneW";
            y = "safeZoneY + 0.295 * safeZoneH";
            w = "0.15 * safeZoneW";
            h = "0.33 * safeZoneH";
            sizeEx = "0.022 * safeZoneH";
            onLBSelChanged = QUOTE([ARR_2(ctrlParent (_this select 0),'select')] call FUNC(presetsAction));
            onLBDblClick = QUOTE([ARR_2(ctrlParent (_this select 0),'load')] call FUNC(presetsAction));
        };
        class Details: RscStructuredText {
            idc = IDC_RADIO_PRESETS_DETAILS;
            x = "safeZoneX + 0.47 * safeZoneW";
            y = "safeZoneY + 0.295 * safeZoneH";
            w = "0.22 * safeZoneW";
            h = "0.33 * safeZoneH";
            size = "0.022 * safeZoneH";
            colorBackground[] = {0, 0, 0, 0.4};
        };
        class Name: RscEdit {
            idc = IDC_RADIO_PRESETS_NAME;
            x = "safeZoneX + 0.31 * safeZoneW";
            y = "safeZoneY + 0.635 * safeZoneH";
            w = "0.38 * safeZoneW";
            h = "0.035 * safeZoneH";
            sizeEx = "0.024 * safeZoneH";
            tooltip = "Preset name";
        };
        class Status: RscText {
            idc = IDC_RADIO_PRESETS_STATUS;
            x = "safeZoneX + 0.31 * safeZoneW";
            y = "safeZoneY + 0.675 * safeZoneH";
            w = "0.38 * safeZoneW";
            h = "0.025 * safeZoneH";
            sizeEx = "0.02 * safeZoneH";
            text = "";
        };
        class Save: RscButtonMenu {
            idc = -1;
            x = "safeZoneX + 0.31 * safeZoneW";
            y = "safeZoneY + 0.705 * safeZoneH";
            w = "0.09 * safeZoneW";
            h = "0.035 * safeZoneH";
            text = "Save";
            tooltip = "Save the current radio settings under this name";
            onButtonClick = QUOTE([ARR_2(ctrlParent (_this select 0),'save')] call FUNC(presetsAction));
        };
        class Load: Save {
            x = "safeZoneX + 0.405 * safeZoneW";
            text = "Load";
            tooltip = "Apply the selected preset to your radios";
            onButtonClick = QUOTE([ARR_2(ctrlParent (_this select 0),'load')] call FUNC(presetsAction));
        };
        class Delete: Save {
            x = "safeZoneX + 0.5 * safeZoneW";
            text = "Delete";
            tooltip = "Delete the selected preset";
            onButtonClick = QUOTE([ARR_2(ctrlParent (_this select 0),'delete')] call FUNC(presetsAction));
        };
        class Close: Save {
            x = "safeZoneX + 0.6 * safeZoneW";
            text = "Close";
            tooltip = "";
            onButtonClick = QUOTE((ctrlParent (_this select 0)) closeDisplay 2);
        };
    };
};
