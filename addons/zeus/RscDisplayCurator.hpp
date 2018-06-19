class RscDisplayCurator {
    scriptName = "RscDisplayCurator";
    scriptPath = QGVAR(Displays);
    class Controls {
        delete Watermark;
    };
};
class RscDisplayAttributes {
    class Controls;
};
class RscDisplayAttributesMan: RscDisplayAttributes {
    class Controls: Controls {
        class ButtonCustomLeft;
        class ButtonCargo: ButtonCustomLeft {
            onMouseButtonClick = QUOTE(call FUNC(openArsenal));
        };
        delete ButtonFlag;
    };
};
class RscDisplayAttributesVehicle: RscDisplayAttributes {
    class Controls: Controls {
        delete ButtonFlag;
    };
};
class RscDisplayAttributesVehicleEmpty: RscDisplayAttributes {
    class Controls: Controls {
        delete ButtonFlag;
    };
};
class CfgScriptPaths {
    GVAR(Displays) = "\u\uksf\addons\zeus\UI\";
};
