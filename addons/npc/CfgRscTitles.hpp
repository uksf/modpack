class RscTitles {
    class GVAR(consoleCards) {
        idd = -1;
        movingEnable = 0;
        enableSimulation = 1;
        fadeIn = 0;
        fadeOut = 0;
        duration = 1e+11;
        onLoad = QUOTE(uiNamespace setVariable [ARR_2(QQGVAR(consoleCards),_this select 0)]);
        class controls {
            class Cards : RscStructuredText {
                idc = IDC_CONSOLE_CARDS;
                x = "safeZoneX + 0.66 * safeZoneW";
                y = "safeZoneY + 0.05 * safeZoneH";
                w = "0.32 * safeZoneW";
                h = "0.25 * safeZoneH";
                colorBackground[] = {0, 0, 0, 0};
                text = "";
            };
        };
    };
};
