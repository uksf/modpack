class RscControlsGroup;
class RscText;
class RangeText: RscText {};
class RscInGameUI {
    class RscOptics_UAV_gunner;
    class RscOptics_UAV_gunnerClean: RscOptics_UAV_gunner {
        idd = 300;
        controls[] = { "CA_IGUI_elements_group" };
        class VScrollbar;
        class HScrollbar;
        class CA_IGUI_elements_group: RscControlsGroup {
            idc = 170;
            class VScrollbar: VScrollbar {
                width = 0;
            };
            class HScrollbar: HScrollbar {
                height = 0;
            };
            x = "0 * (0.01875 * SafezoneH) + (SafezoneX + ((SafezoneW - SafezoneH) / 2))";
            y = "0 * (0.025 * SafezoneH) + (SafezoneY)";
            w = "53.5 * (0.01875 * SafezoneH)";
            h = "40 * (0.025 * SafezoneH)";
            class controls {
                class Crosshair: RscText {
                    idc = 1012;
                    style = "0x30 + 0x800";
                    sizeEx = "0.02 * SafezoneH";
                    shadow = 0;
                    font = "EtelkaMonospacePro";
                    align = "right";
                    text = QPATHTOF(data\crosshair.paa);
                    x = "20.45 * (0.01875 * SafezoneH)";
                    y = "14.1 * (0.025 * SafezoneH)";
                    w = "12 * (0.01875 * SafezoneH)";
                    h = "12 * (0.025 * SafezoneH)";
                };
                class RangeText: RscText {
                    style = 0;
                    sizeEx = "0.02 * SafezoneH";
                    shadow = 0;
                    font = "EtelkaMonospacePro";
                    idc = 1000;
                    text = "RANGE:";
                    x = "18.5 * (0.01875 * SafezoneH)";
                    y = "13.2 * (0.025 * SafezoneH)";
                    w = "3 * (0.01875 * SafezoneH)";
                    h = "1.2 * (0.025 * SafezoneH)";
                };
                class CA_Distance: RangeText {
                    idc = 198;
                    text = "2456";
                    x = "21.3 * (0.01875 * SafezoneH)";
                    y = "13.2 * (0.025 * SafezoneH)";
                    w = "4 * (0.01875 * SafezoneH)";
                    h = "1.2 * (0.025 * SafezoneH)";
                };
                class ModeText: RangeText {
                    idc = 1002;
                    text = "MODE:";
                    x = "18.5 * (0.01875 * SafezoneH)";
                    y = "26.8 * (0.025 * SafezoneH)";
                    w = "3 * (0.01875 * SafezoneH)";
                    h = "1.2 * (0.025 * SafezoneH)";
                };
                class CA_VisionMode: RangeText {
                    idc = 179;
                    style = 0;
                    text = "VIS";
                    x = "22.2 * (0.01875 * SafezoneH)";
                    y = "26.8 * (0.025 * SafezoneH)";
                    w = "4 * (0.01875 * SafezoneH)";
                    h = "1.2 * (0.025 * SafezoneH)";
                };
                class CA_FlirMode: RangeText {
                    idc = 153;
                    style = 0;
                    text = "BHOT";
                    x = "23.4 * (0.01875 * SafezoneH)";
                    y = "26.8 * (0.025 * SafezoneH)";
                    w = "4.5 * (0.01875 * SafezoneH)";
                    h = "1.2 * (0.025 * SafezoneH)";
                };
                class TextSpd: RangeText {
                    idc = 1009;
                    text = "IAS:";
                    x = "5.8 * (0.01875 * SafezoneH)";
                    y = "12.4 * (0.025 * SafezoneH)";
                    w = "5 * (0.01875 * SafezoneH)";
                    h = "1.2 * (0.025 * SafezoneH)";
                };
                class CA_Speed: RangeText {
                    idc = 188;
                    text = "120";
                    sourceScale = 1.94384;
                    x = "10.3 * (0.01875 * SafezoneH)";
                    y = "12.4 * (0.025 * SafezoneH)";
                    w = "5 * (0.01875 * SafezoneH)";
                    h = "1.2 * (0.025 * SafezoneH)";
                };
                class TextAlt: RangeText {
                    idc = 1007;
                    text = "ASL:";
                    x = "5.8 * (0.01875 * SafezoneH)";
                    y = "13.2 * (0.025 * SafezoneH)";
                    w = "5 * (0.01875 * SafezoneH)";
                    h = "1.2 * (0.025 * SafezoneH)";
                };
                class CA_Alt: RangeText {
                    idc = 189;
                    text = "3825";
                    source = "altitudeASL";
                    sourceScale = 3.28084;
                    x = "10.3 * (0.01875 * SafezoneH)";
                    y = "13.2 * (0.025 * SafezoneH)";
                    w = "5 * (0.01875 * SafezoneH)";
                    h = "1.2 * (0.025 * SafezoneH)";
                };
                class TgT_Grid_text: RangeText {
                    idc = 1005;
                    text = "GRID TGT:";
                    x = "5.8 * (0.01875 * SafezoneH)";
                    y = "31 * (0.025 * SafezoneH)";
                    w = "5 * (0.01875 * SafezoneH)";
                    h = "1.2 * (0.025 * SafezoneH)";
                };
                class TGT_ValueGrid: RangeText {
                    idc = 172;
                    colorText[] = { 0.70599997, 0.074500002, 0.0196, 0.80000001 };
                    x = "10.3 * (0.01875 * SafezoneH)";
                    y = "31 * (0.025 * SafezoneH)";
                    w = "6 * (0.01875 * SafezoneH)";
                    h = "1 * (0.025 * SafezoneH)";
                };
                class TextGrid: RangeText {
                    idc = 1005;
                    text = "GRID:";
                    x = "5.8 * (0.01875 * SafezoneH)";
                    y = "31.8 * (0.025 * SafezoneH)";
                    w = "5 * (0.01875 * SafezoneH)";
                    h = "1.2 * (0.025 * SafezoneH)";
                };
                class ValueGrid: RangeText {
                    idc = 171;
                    text = "382546";
                    x = "10.3 * (0.01875 * SafezoneH)";
                    y = "31.8 * (0.025 * SafezoneH)";
                    w = "6 * (0.01875 * SafezoneH)";
                    h = "1 * (0.025 * SafezoneH)";
                };
                class TextTime: RangeText {
                    idc = 1010;
                    text = "TIME [UTC]:";
                    x = "5.8 * (0.01875 * SafezoneH)";
                    y = "32.6 * (0.025 * SafezoneH)";
                    w = "5 * (0.01875 * SafezoneH)";
                    h = "1 * (0.025 * SafezoneH)";
                };
                class ValueTime: RangeText {
                    idc = 190;
                    text = "20:28:35";
                    x = "10 * (0.01875 * SafezoneH)";
                    y = "32.6 * (0.025 * SafezoneH)";
                    w = "6 * (0.01875 * SafezoneH)";
                    h = "1 * (0.025 * SafezoneH)";
                };
                class TextMag: RangeText {
                    idc = 1011;
                    text = "CAM MAG:";
                    x = "18.5 * (0.01875 * SafezoneH)";
                    y = "26 * (0.025 * SafezoneH)";
                    w = "5 * (0.01875 * SafezoneH)";
                    h = "1.2 * (0.025 * SafezoneH)";
                };
                class CA_OpticsZoom: RangeText {
                    idc = 180;
                    text = "28x";
                    x = "22.2 * (0.01875 * SafezoneH)";
                    y = "26 * (0.025 * SafezoneH)";
                    w = "6 * (0.01875 * SafezoneH)";
                    h = "1.2 * (0.025 * SafezoneH)";
                };
                class CA_Laser: RscText {
                    idc = 158;
                    style = 0;
                    colorText[] = { 0.929, 0.796, 0.055, 1 };
                    sizeEx = "0.038 * SafezoneH";
                    shadow = 0;
                    font = "EtelkaMonospacePro";
                    text = "Laser ON";
                    align = "right";
                    x = "23.5 * (0.01875 * SafezoneH)";
                    y = "10 * (0.025 * SafezoneH)";
                    w = "6 * (0.01875 * SafezoneH)";
                    h = "1.2 * (0.025 * SafezoneH)";
                };
                class CA_Heading: RscText {
                    idc = 156;
                    style = 0;
                    sizeEx = "0.038 * SafezoneH";
                    shadow = 0;
                    font = "EtelkaMonospacePro";
                    text = "023";
                    align = "right";
                    x = "25 * (0.01875 * SafezoneH)";
                    y = "5 * (0.025 * SafezoneH)";
                    w = "4 * (0.01875 * SafezoneH)";
                    h = "1.2 * (0.025 * SafezoneH)";
                };
            };
        };
    };
};
