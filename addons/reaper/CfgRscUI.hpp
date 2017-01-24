class RscControlsGroup;
class RscText;
class RangeText : RscText {};
class RscInGameUI {
    class RscUnitInfo;
    class Rsc_USAF_MQ9_Turret_UI : RscUnitInfo {
        idd = 300;
        controls[] = { "CA_Zeroing", "CA_IGUI_elements_group", "CA_VehicleToggles" };
        class VScrollbar;
        class HScrollbar;
        class CA_IGUI_elements_group : RscControlsGroup {
            idc = 170;
            class VScrollbar : VScrollbar {
                width = 0;
            };
            class HScrollbar : HScrollbar {
                height = 0;
            };
            x = "0 *         (0.01875 * SafezoneH) +         (SafezoneX + ((SafezoneW - SafezoneH) / 2))";
            y = "0 *         (0.025 * SafezoneH) +         (SafezoneY)";
            w = "53.5 *         (0.01875 * SafezoneH)";
            h = "40 *         (0.025 * SafezoneH)";
            class controls {
                class CA_Distance : RscText {
                    idc = 151;
                    style = 2;
                    sizeEx = "0.0295*SafezoneH";
                    shadow = 0;
                    font = "EtelkaMonospacePro";
                    x = "24.78 *         (0.01875 * SafezoneH)";
                    y = "30.88 *         (0.025 * SafezoneH)";
                    w = "4 *         (0.01875 * SafezoneH)";
                    h = "1.2 *         (0.025 * SafezoneH)";
                };
                class CA_Speed : RangeText {
                    idc = 188;
                    style = 2;
                    sizeEx = "0.0295*SafezoneH";
                    shadow = 0;
                    source = "speed";
                    sourceScale = 1.94384;
                    font = "EtelkaMonospacePro";
                    text = "120";
                    x = "14.78 *         (0.01875 * SafezoneH)";
                    y = "30.88 *         (0.025 * SafezoneH)";
                    w = "4 *         (0.01875 * SafezoneH)";
                    h = "1.2 *         (0.025 * SafezoneH)";
                };
                class CA_Alt : RangeText {
                    idc = 189;
                    style = 2;
                    source = "altitudeASL";
                    sourceScale = 3.2808399;
                    sizeEx = "0.0295*SafezoneH";
                    shadow = 0;
                    font = "EtelkaMonospacePro";
                    text = "3825";
                    x = "34.78 *         (0.01875 * SafezoneH)";
                    y = "30.88 *         (0.025 * SafezoneH)";
                    w = "4 *         (0.01875 * SafezoneH)";
                    h = "1.2 *         (0.025 * SafezoneH)";
                };
                class ValueTime : RangeText {
                    idc = 190;
                    text = "20:28:35";
                    font = "EtelkaMonospacePro";
                    style = 2;
                    sizeEx = "0.0295*SafezoneH";
                    shadow = 0;
                    x = "1.75 *         (0.01875 * SafezoneH)";
                    y = "10.5 *         (0.025 * SafezoneH)";
                    w = "6 *         (0.01875 * SafezoneH)";
                    h = "1 *         (0.025 * SafezoneH)";
                };
                class CA_VisionMode : RscText {
                    idc = 152;
                    style = 0;
                    sizeEx = "0.0295*SafezoneH";
                    shadow = 0;
                    font = "EtelkaMonospacePro";
                    text = "VIS";
                    align = "right";
                    x = "2.6 *         (0.01875 * SafezoneH)";
                    y = "12.0 *         (0.025 * SafezoneH)";
                    w = "4 *         (0.01875 * SafezoneH)";
                    h = "1.0 *         (0.025 * SafezoneH)";
                };
                class CA_FlirMode : RscText {
                    idc = 153;
                    style = 0;
                    sizeEx = "0.0295*SafezoneH";
                    shadow = 0;
                    font = "EtelkaMonospacePro";
                    text = "BHOT";
                    align = "right";
                    x = "6.18 *         (0.01875 * SafezoneH)";
                    y = "12.0 *         (0.025 * SafezoneH)";
                    w = "4.5 *         (0.01875 * SafezoneH)";
                    h = "1.0 *         (0.025 * SafezoneH)";
                };
                class TgT_Grid_text : RangeText {
                    idc = 1005;
                    text = "TGT:";
                    font = "EtelkaMonospacePro";
                    style = 2;
                    sizeEx = "0.0295*SafezoneH";
                    shadow = 0;
                    x = "1.20 *         (0.01875 * SafezoneH)";
                    y = "13.5 *         (0.025 * SafezoneH)";
                    w = "6 *         (0.01875 * SafezoneH)";
                    h = "1 *         (0.025 * SafezoneH)";
                };
                class TGT_ValueGrid : RangeText {
                    idc = 172;
                    font = "EtelkaMonospacePro";
                    colorText[] = { 0.70599997,0.074500002,0.0196,0.80000001 };
                    style = 2;
                    sizeEx = "0.0295*SafezoneH";
                    shadow = 0;
                    x = "5.20 *         (0.01875 * SafezoneH)";
                    y = "13.5 *         (0.025 * SafezoneH)";
                    w = "6 *         (0.01875 * SafezoneH)";
                    h = "1 *         (0.025 * SafezoneH)";
                };
                class OWN_Grid_text : RangeText {
                    idc = 1005;
                    text = "OWN:";
                    font = "EtelkaMonospacePro";
                    style = 2;
                    sizeEx = "0.0295*SafezoneH";
                    shadow = 0;
                    x = "1.20 *         (0.01875 * SafezoneH)";
                    y = "15 *         (0.025 * SafezoneH)";
                    w = "6 *         (0.01875 * SafezoneH)";
                    h = "1 *         (0.025 * SafezoneH)";
                };
                class OWN_ValueGrid : RangeText {
                    idc = 171;
                    font = "EtelkaMonospacePro";
                    colorText[] = { 0.15000001,1,0.15000001,0.80000001 };
                    style = 2;
                    sizeEx = "0.0295*SafezoneH";
                    shadow = 0;
                    x = "5.20 *         (0.01875 * SafezoneH)";
                    y = "15 *         (0.025 * SafezoneH)";
                    w = "6 *         (0.01875 * SafezoneH)";
                    h = "1 *         (0.025 * SafezoneH)";
                };
                class CA_Laser : RscText {
                    idc = 158;
                    style = "0x30 + 0x800";
                    sizeEx = "0.038*SafezoneH";
                    shadow = 0;
                    align = "right";
                    font = "EtelkaMonospacePro";
                    text = "\USAF_MQ9\UI\data\Apache_LaserOn.paa";
                    x = "20.45 *         (0.01875 * SafezoneH)";
                    y = "14.1 *         (0.025 * SafezoneH)";
                    w = "12.5 *         (0.01875 * SafezoneH)";
                    h = "12 *         (0.025 * SafezoneH)";
                };
                class CA_Heading : RscText {
                    idc = 156;
                    style = 0;
                    sizeEx = "0.038*SafezoneH";
                    shadow = 0;
                    font = "EtelkaMonospacePro";
                    text = "023";
                    align = "right";
                    x = "25 *         (0.01875 * SafezoneH)";
                    y = "5 *         (0.025 * SafezoneH)";
                    w = "4 *         (0.01875 * SafezoneH)";
                    h = "1.2 *         (0.025 * SafezoneH)";
                };
            };
        };
    };
};