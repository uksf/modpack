class RscControlsGroup;
class RscControlsGroupNoScrollbars;
class RscButtonMenu;
class RscDisplayArsenal {
    class Controls {
        class Template: RscControlsGroup {
            class controls {
                class ButtonOK: RscButtonMenu {
                    x = "15.1 * (((safezoneW / safezoneH) min 1.2) / 40)";
                    w = "4.9 * (((safezoneW / safezoneH) min 1.2) / 40)";
                };
                class ButtonCancel: RscButtonMenu {
                    w = "4.9 * (((safezoneW / safezoneH) min 1.2) / 40)";
                };
                class ButtonDelete: RscButtonMenu {
                    x = "10.067 * (((safezoneW / safezoneH) min 1.2) / 40)";
                    w = "4.9 * (((safezoneW / safezoneH) min 1.2) / 40)";
                };
                class ButtonDefaults: RscButtonMenu {
                    idc = 36022;
                    text = "DEFAULTS";
                    x = "5.033 * (((safezoneW / safezoneH) min 1.2) / 40)";
                    y = "21.2 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                    w = "4.9 * (((safezoneW / safezoneH) min 1.2) / 40)";
                    h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                };
            };
        };
        class ControlBar: RscControlsGroupNoScrollbars {
            class controls {
                class ButtonClose;
                class ButtonInterface;
                class ButtonSave: ButtonInterface {
                    x = "4 * ((safezoneW - 1 * (((safezoneW / safezoneH) min 1.2) / 40)) * 0.1)";
                };
                class ButtonLoad: ButtonInterface {
                    x = "6 * ((safezoneW - 1 * (((safezoneW / safezoneH) min 1.2) / 40)) * 0.1)";
                };
                class ButtonExport: ButtonInterface {
                    x = "7 * ((safezoneW - 1 * (((safezoneW / safezoneH) min 1.2) / 40)) * 0.1)";
                };
                class ButtonImport: ButtonInterface {
                    x = "8 * ((safezoneW - 1 * (((safezoneW / safezoneH) min 1.2) / 40)) * 0.1)";
                };
                class ButtonOK: ButtonClose {
                    x = "9 * ((safezoneW - 1 * (((safezoneW / safezoneH) min 1.2) / 40)) * 0.1)";
                    w = "((safezoneW - 1 * (((safezoneW / safezoneH) min 1.2) / 40)) * 0.1) - 0.1 * (((safezoneW / safezoneH) min 1.2) / 40)";
                };
                class ButtonGear: ButtonInterface {
                    idc = 44449;
                    text = "MAIN OP GEAR";
                    x = "5 * ((safezoneW - 1 * (((safezoneW / safezoneH) min 1.2) / 40)) * 0.1)";
                    tooltip = "Load Main Op Gear";
                    shortcuts[] = {};
                };
            };
        };
    };
};
