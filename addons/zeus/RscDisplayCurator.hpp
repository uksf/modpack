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
    };
};
class CfgScriptPaths {
    GVAR(Displays) = "\u\uksf\addons\zeus\UI\";
};
