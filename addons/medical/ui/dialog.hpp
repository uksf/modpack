class uksf_medical_uncon {
    idd = IDD_UNCON;
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = QUOTE(call FUNC(openDialogOnLoad));

    class Controls {
        class Backdrop {
            type = CT_STATIC;
            idc = -1;
            style = ST_LEFT;
            x = QUOTE(safezoneX);
            y = QUOTE(safezoneY);
            w = QUOTE(safezoneW);
            h = QUOTE(safezoneH);
            text = "";
            sizeEx = 0;
            font = QUOTE(GUI_FONT_NORMAL);
            colorText[] = {0,0,0,0};
            colorBackground[] = {0,0,0,0.6};
        };

        class tabMedical {
            access = 0;
            idc = IDC_TAB_HEALTH;
            type = CT_BUTTON;
            style = ST_CENTER;
            default = 1;
            blinkingPeriod = 0;
            x = QUOTE(12 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X);
            y = QUOTE(1.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y);
            w = QUOTE(8 * GUI_GRID_CENTER_W);
            h = QUOTE(1.1 * GUI_GRID_CENTER_H);
            colorBackground[] = {0.1,0.1,0.1,0.8};
            colorBackgroundDisabled[] = {0,0,0,0.4};
            colorBackgroundActive[] = {0.2,0.2,0.2,0.9};
            colorFocused[] = {0.18,0.18,0.18,0.9};
            text = "Health";
            sizeEx = QUOTE(GUI_GRID_CENTER_H * 0.9);
            font = QUOTE(GUI_FONT_NORMAL);
            shadow = 1;
            colorText[] = {0.85,0.85,0.85,1};
            colorDisabled[] = {0.5,0.5,0.5,1};
            tooltip = "";
            tooltipColorShade[] = {0,0,0,1};
            tooltipColorText[] = {1,1,1,1};
            tooltipColorBox[] = {1,1,1,1};
            borderSize = 0;
            colorBorder[] = {0,0,0,0};
            colorShadow[] = {0,0,0,0};
            offsetX = 0;
            offsetY = 0;
            offsetPressedX = 0;
            offsetPressedY = 0;
            period = 0;
            periodFocus = 0;
            periodOver = 0;
            soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
            soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
            soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
            soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
            onButtonDown = QUOTE(call FUNC(openHealthTab));
        };
        class tabSpectate: tabMedical {
            idc = IDC_TAB_SPECTATOR;
            default = 0;
            x = QUOTE(20 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X);
            w = QUOTE(8 * GUI_GRID_CENTER_W);
            text = "Spectator";
            onButtonDown = QUOTE(call FUNC(openSpectatorTab));
        };
        class spc_SpectatingInfo_TooFar {
            show = 0;
            type = CT_STATIC;
            idc = IDC_SPEC_TOO_FAR;
            style = ST_CENTER;
            x = QUOTE(0 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X);
            y = QUOTE(22 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y);
            w = QUOTE(40 * GUI_GRID_CENTER_W);
            h = QUOTE(1.1 * GUI_GRID_CENTER_H);
            text = "";
            sizeEx = QUOTE(GUI_GRID_CENTER_H * 0.9);
            font = QUOTE(GUI_FONT_NORMAL);
            lineSpacing = 1;
            colorText[] = {0.95,0.95,0.95,1};
            colorBackground[] = {0,0,0,0.55};
        };
        class spc_SpectatingInfo: spc_SpectatingInfo_TooFar {
            idc = IDC_SPEC_INFO;
        };
        class PiPZone {
            show = 0;
            idc = IDC_SPEC_PIP;
            type = CT_STATIC;
            style = ST_PICTURE;
            colorText[] = {1,1,1,1};
            colorBackground[] = {0,0,0,1};
            font = QUOTE(GUI_FONT_NORMAL);
            sizeEx = 0.023;
            x = QUOTE(0 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X);
            y = QUOTE(0 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y);
            w = QUOTE(40 * GUI_GRID_CENTER_W);
            h = QUOTE(21.5 * GUI_GRID_CENTER_H);
            text = "#(argb,512,512,1)r2t(uksf_medical_rtt,1.333)";
            moving = 0;
        };
        class spc_NoSignal: spc_SpectatingInfo_TooFar {
            show = 0;
            idc = IDC_SPEC_NO_SIGNAL;
            y = QUOTE(11 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y);
            h = QUOTE(2 * GUI_GRID_CENTER_H);
            sizeEx = QUOTE(GUI_GRID_CENTER_H * 1.3);
            colorBackground[] = {0,0,0,0};
            colorText[] = {0.8,0.8,0.8,1};
            text = "No conscious allies nearby";
        };

        class spc_nvg_0 {
            show = 0;
            access = 0;
            idc = IDC_SPEC_NVG_0;
            type = CT_BUTTON;
            style = ST_CENTER;
            default = 0;
            blinkingPeriod = 0;
            x = QUOTE(12 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X);
            y = QUOTE(23.3 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y);
            w = QUOTE(5 * GUI_GRID_CENTER_W);
            h = QUOTE(1 * GUI_GRID_CENTER_H);
            colorBackground[] = {0.1,0.1,0.1,0.85};
            colorBackgroundDisabled[] = {0,0,0,0.4};
            colorBackgroundActive[] = {0.22,0.22,0.22,0.9};
            colorFocused[] = {0.15,0.15,0.15,0.9};
            text = "Normal";
            sizeEx = QUOTE(GUI_GRID_CENTER_H * 0.85);
            font = QUOTE(GUI_FONT_NORMAL);
            shadow = 1;
            colorText[] = {0.85,0.85,0.85,1};
            colorDisabled[] = {0.5,0.5,0.5,1};
            tooltip = "";
            borderSize = 0;
            colorBorder[] = {0,0,0,0};
            colorShadow[] = {0,0,0,0};
            offsetX = 0;
            offsetY = 0;
            offsetPressedX = 0;
            offsetPressedY = 0;
            period = 0;
            periodFocus = 0;
            periodOver = 0;
            soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
            soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
            soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
            soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
            onButtonDown = QUOTE('uksf_medical_rtt' setPiPEffect [0]);
        };
        class spc_nvg_1: spc_nvg_0 {
            idc = IDC_SPEC_NVG_1;
            x = QUOTE(17.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X);
            text = "Night Vision";
            onButtonDown = QUOTE('uksf_medical_rtt' setPiPEffect [1]);
        };
        class spc_nvg_2: spc_nvg_0 {
            idc = IDC_SPEC_NVG_2;
            x = QUOTE(23 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X);
            text = "Thermal";
            onButtonDown = QUOTE('uksf_medical_rtt' setPiPEffect [2]);
        };

        class spc_HeartRate {
            show = 0;
            type = 13;
            idc = IDC_HEALTH_HR;
            style = ST_LEFT;
            x = QUOTE(10 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X);
            y = QUOTE(4 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y);
            w = QUOTE(20 * GUI_GRID_CENTER_W);
            h = QUOTE(2.8 * GUI_GRID_CENTER_H);
            text = "";
            size = QUOTE(GUI_GRID_CENTER_H * 1.4);
            font = QUOTE(GUI_FONT_NORMAL);
            colorText[] = {1,1,1,1};
            colorBackground[] = {0.06,0.06,0.06,0.65};
            shadow = 1;
            class Attributes {
                font = QUOTE(GUI_FONT_NORMAL);
                color = "#ffffff";
                align = "left";
                shadow = 1;
            };
        };
        class spc_BloodPressure: spc_HeartRate {
            idc = IDC_HEALTH_BP;
            y = QUOTE(7 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y);
        };
        class spc_Respiration: spc_HeartRate {
            idc = IDC_HEALTH_RESP;
            y = QUOTE(10 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y);
        };
        class spc_SpO2: spc_HeartRate {
            idc = IDC_HEALTH_SPO2;
            y = QUOTE(13 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y);
        };
        class spc_cr_timer: spc_HeartRate {
            idc = IDC_HEALTH_STATE_TIMER;
            x = QUOTE(10 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X);
            y = QUOTE(19.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y);
            w = QUOTE(20 * GUI_GRID_CENTER_W);
            h = QUOTE(2.4 * GUI_GRID_CENTER_H);
            size = QUOTE(GUI_GRID_CENTER_H * 1.4);
            colorBackground[] = {0.06,0.06,0.06,0.75};
        };
        class spc_medtabfocus {
            type = CT_STATIC;
            idc = IDC_HEALTH_TABFOCUS;
            style = ST_LEFT;
            x = QUOTE(0 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X);
            y = QUOTE(50 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y);
            w = QUOTE(0 * GUI_GRID_CENTER_W);
            h = QUOTE(0 * GUI_GRID_CENTER_H);
            text = "";
            sizeEx = 0;
            font = QUOTE(GUI_FONT_NORMAL);
            lineSpacing = 0;
            colorText[] = {0,0,0,0};
            colorBackground[] = {0,0,0,0};
            shadow = 0;
            fixedWidth = 0;
        };
    };
};
