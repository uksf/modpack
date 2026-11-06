#define ANDROID_GRID_H (safezoneH * 1.4)
#define ANDROID_GRID_W (ANDROID_GRID_H * 3/4)
#define ANDROID_GRID_X (safezoneX + (safezoneW - ANDROID_GRID_W) / 2)
#define ANDROID_GRID_Y (safezoneY + (safezoneH - ANDROID_GRID_H) / 2)
#define ANDROID_PX 2048
#define ANDROID_X(PIXEL) QUOTE((PIXEL) / ANDROID_PX * ANDROID_GRID_W + ANDROID_GRID_X)
#define ANDROID_Y(PIXEL) QUOTE((PIXEL) / ANDROID_PX * ANDROID_GRID_H + ANDROID_GRID_Y)
#define ANDROID_W(PIXEL) QUOTE((PIXEL) / ANDROID_PX * ANDROID_GRID_W)
#define ANDROID_H(PIXEL) QUOTE((PIXEL) / ANDROID_PX * ANDROID_GRID_H)

#define ANDROID_CONTENT_X 452
#define ANDROID_CONTENT_Y 773
#define ANDROID_CONTENT_W 1134
#define ANDROID_CONTENT_H 564
#define ANDROID_PANEL_W 476

class cTab_RscControlsGroup;
class cTab_android_btnBack;

class cTab_Android_dlg {
    class controls {
        class GVAR(apps): cTab_RscControlsGroup {
            idc = IDC_APPS_GROUP;
            x = ANDROID_X(ANDROID_CONTENT_X);
            y = ANDROID_Y(ANDROID_CONTENT_Y);
            w = ANDROID_W(ANDROID_CONTENT_W);
            h = ANDROID_H(ANDROID_CONTENT_H);
            class controls {};
        };
        class GVAR(panel): GVAR(apps) {
            idc = IDC_APPS_PANEL;
            x = ANDROID_X(ANDROID_CONTENT_X + ANDROID_CONTENT_W - ANDROID_PANEL_W);
            w = ANDROID_W(ANDROID_PANEL_W);
        };
        class GVAR(btnApps): cTab_android_btnBack {
            idc = IDC_APPS_BUTTON;
            action = QUOTE(['UKSF_APPS'] call FUNC(setMode));
            tooltip = "Apps";
        };
    };
};
