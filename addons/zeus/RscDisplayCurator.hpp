class RscControlsGroup;
class RscControlsGroupNoScrollbars;
class RscText;
class RscEdit;
class RscXSliderH;

class RscDisplayCurator {
    scriptName = "RscDisplayCurator";
    scriptPath = QGVAR(Displays);
    class Controls {
        delete Watermark;
    };
};

class RscDisplayAttributes {
    class Controls {
        class Background;
        class Title;
        class Content : RscControlsGroup {
            class Controls;
        };
        class ButtonOK;
        class ButtonCancel;
    };
};
class RscDisplayAttributesMan : RscDisplayAttributes {
    class Controls : Controls {
        class ButtonCustomLeft;
        class ButtonCargo : ButtonCustomLeft {
            onMouseButtonClick = QUOTE(call FUNC(openArsenal));
        };
        delete ButtonFlag;
    };
};
class RscDisplayAttributesVehicle : RscDisplayAttributes {
    class Controls : Controls {
        delete ButtonFlag;
    };
};
class RscDisplayAttributesVehicleEmpty : RscDisplayAttributes {
    class Controls : Controls {
        delete ButtonFlag;
    };
};

class GVAR(RscAltitude) : RscDisplayAttributes {
    onLoad = QUOTE([ARR_3('onLoad',_this,QQGVAR(RscAltitude))] call ace_zeus_fnc_zeusAttributes);
    onUnload = QUOTE([ARR_3('onUnload',_this,QQGVAR(RscAltitude))] call ace_zeus_fnc_zeusAttributes);
    class Controls : Controls {
        class Background : Background {};
        class Title : Title {};
        class Content : Content {
            class Controls {
                class Altitude : RscControlsGroupNoScrollbars {
                    onSetFocus = QUOTE(_this call FUNC(ui_altitude));
                    idc = 83470;
                    x = 0;
                    y = 0;
                    w = W_PART(26);
                    h = H_PART(1.1);
                    class controls {
                        class AltitudeLabel : RscText {
                            idc = -1;
                            text = "Altitude";
                            x = 0;
                            y = H_PART(0.1);
                            w = W_PART(10);
                            h = H_PART(1);
                            colorBackground[] = { 0, 0, 0, 0.5 };
                        };
                        class AltitudeSlider : RscXSliderH {
                            idc = 83572;
                            x = W_PART(10.1);
                            y = H_PART(0.1);
                            w = W_PART(13);
                            h = H_PART(1);
                        };
                        class AltitudeEdit : RscEdit {
                            idc = 83573;
                            x = W_PART(23.2);
                            y = H_PART(0.1);
                            w = W_PART(2.8);
                            h = H_PART(1);
                            autocomplete = "";
                            maxChars = 5;
                            canModify = 0;
                        };
                    };
                };
            };
        };
        class ButtonOK : ButtonOK {};
        class ButtonCancel : ButtonCancel {};
    };
};

class CfgScriptPaths {
    GVAR(Displays) = "\u\uksf\addons\zeus\ui\";
};
