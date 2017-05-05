class RscControlsGroup;
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
    };
};
