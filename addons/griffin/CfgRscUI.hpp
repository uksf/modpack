class RscInGameUI {
    class RscUnitInfo;
    class Rsc_UKSF_Air_Special : RscUnitInfo {
        controls[] = {
            "CA_BackgroundFuel",
            "CA_VehicleToggles",
            "CA_HitZones",
            "CA_Radar",
            "CA_ValueFuel"
        };
    };
};
class RscText;
class RscTitles {
    titles[] = { GVAR(metrics) };
    class GVAR(metrics) {
        idd = 1890;
        movingEnabled = 1;
        duration = 9.9999998e+010;
        fadein = 0;
        fadeout = 0;
        name = QGVAR(metrics);
        onLoad = QUOTE(uiNameSpace setVariable [ARR_2(QQGVAR(metrics), _this select 0)];);
        onUnload = QUOTE(uinamespace setvariable [ARR_2(QQGVAR(metrics), nil)];);
        class controls {
            class RscText_1891 : RscText {
                idc = 1891;
                text = "0 kn";
                x = 0.0823437 * safezoneW + safezoneX;
                y = 0.038 * safezoneH + safezoneY;
                w = 0.04125 * safezoneW;
                h = 0.022 * safezoneH;
            };
            class RscText_1892 : RscText {
                idc = 1892;
                text = "0 ft";
                x = 0.0823437 * safezoneW + safezoneX;
                y = 0.06 * safezoneH + safezoneY;
                w = 0.04125 * safezoneW;
                h = 0.022 * safezoneH;
            };
        };
    };
};