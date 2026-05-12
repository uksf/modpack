class RscText;
class RscButton;
class RscControlsGroupNoScrollbars;
class RscPicture;
class RscListNBox;

class uksf_medical_uncon {
    idd = IDD_UNCON;
    movingEnable = 0;
    enableSimulation = 1;
    onLoad = QUOTE(call FUNC(openDialogOnLoad));

    class controls {
        class Background: RscText {
            idc = -1;
            x = QUOTE(X_PART(8));
            y = QUOTE(Y_PART(3));
            w = QUOTE(W_PART(24));
            h = QUOTE(H_PART(19));
            colorBackground[] = COLOR_BG_DIALOG;
            text = "";
        };

        class TabBar: RscControlsGroupNoScrollbars {
            idc = IDC_TAB_BAR;
            x = QUOTE(X_PART(8));
            y = QUOTE(Y_PART(3));
            w = QUOTE(W_PART(24));
            h = QUOTE(H_PART(1.5));

            class controls {
                class TabSpectator: RscButton {
                    idc = IDC_TAB_SPECTATOR_BTN;
                    x = 0;
                    y = 0;
                    w = QUOTE(W_PART(8));
                    h = QUOTE(H_PART(1.5));
                    text = "Spectator";
                    colorBackground[] = COLOR_BG_TAB;
                    action = QUOTE(['spectator'] call FUNC(switchTab));
                };
                class TabHealth: TabSpectator {
                    idc = IDC_TAB_HEALTH_BTN;
                    x = QUOTE(W_PART(8));
                    text = "Health";
                    action = QUOTE(['health'] call FUNC(switchTab));
                };
                class TabSettings: TabSpectator {
                    idc = IDC_TAB_SETTINGS_BTN;
                    x = QUOTE(W_PART(16));
                    text = "Settings";
                    action = QUOTE(['settings'] call FUNC(switchTab));
                };
            };
        };

        class ContainerSpectator: RscControlsGroupNoScrollbars {
            idc = IDC_CONTAINER_SPECTATOR;
            x = QUOTE(X_PART(8));
            y = QUOTE(Y_PART(4.5));
            w = QUOTE(W_PART(24));
            h = QUOTE(H_PART(17.5));
            show = 1;

            class controls {
                class SpecCamPicture: RscPicture {
                    idc = IDC_SPEC_CAM_PICTURE;
                    x = 0;
                    y = 0;
                    w = QUOTE(W_PART(24));
                    h = QUOTE(H_PART(15));
                    text = "#(argb,512,512,1)r2t(uksf_medical_rtt,1)";
                    colorText[] = COLOR_TEXT_NORMAL;
                };
                class SpecText: RscText {
                    idc = IDC_SPEC_TEXT;
                    x = 0;
                    y = QUOTE(H_PART(15));
                    w = QUOTE(W_PART(24));
                    h = QUOTE(H_PART(2.5));
                    text = "";
                    colorText[] = COLOR_TEXT_NORMAL;
                    style = 2; // ST_CENTER
                };
            };
        };

        class ContainerHealth: RscControlsGroupNoScrollbars {
            idc = IDC_CONTAINER_HEALTH;
            x = QUOTE(X_PART(8));
            y = QUOTE(Y_PART(4.5));
            w = QUOTE(W_PART(24));
            h = QUOTE(H_PART(17.5));
            show = 0;

            class controls {
                class HealthHR: RscText {
                    idc = IDC_HEALTH_HR;
                    x = 0;
                    y = QUOTE(H_PART(0));
                    w = QUOTE(W_PART(24));
                    h = QUOTE(H_PART(1.5));
                    text = "";
                    colorText[] = COLOR_TEXT_NORMAL;
                };
                class HealthBP: HealthHR {
                    idc = IDC_HEALTH_BP;
                    y = QUOTE(H_PART(1.5));
                };
                class HealthResp: HealthHR {
                    idc = IDC_HEALTH_RESP;
                    y = QUOTE(H_PART(3));
                };
                class HealthSpO2: HealthHR {
                    idc = IDC_HEALTH_SPO2;
                    y = QUOTE(H_PART(4.5));
                };
                class HealthPain: HealthHR {
                    idc = IDC_HEALTH_PAIN;
                    y = QUOTE(H_PART(6));
                };
                class HealthStateTimer: HealthHR {
                    idc = IDC_HEALTH_STATE_TIMER;
                    y = QUOTE(H_PART(8));
                    h = QUOTE(H_PART(2));
                    show = 0;
                };
                class HealthModeBtn: RscButton {
                    idc = IDC_HEALTH_MODE_BTN;
                    x = QUOTE(W_PART(18));
                    y = QUOTE(H_PART(15.5));
                    w = QUOTE(W_PART(6));
                    h = QUOTE(H_PART(1.5));
                    text = "Toggle Full/Minimal";
                    colorBackground[] = COLOR_BG_TAB;
                    action = QUOTE(call FUNC(vitalsToggleMode));
                };
            };
        };

        class ContainerSettings: RscControlsGroupNoScrollbars {
            idc = IDC_CONTAINER_SETTINGS;
            x = QUOTE(X_PART(8));
            y = QUOTE(Y_PART(4.5));
            w = QUOTE(W_PART(24));
            h = QUOTE(H_PART(17.5));
            show = 0;

            class controls {
                class SettingsList: RscListNBox {
                    idc = IDC_SETTINGS_LIST;
                    x = 0;
                    y = 0;
                    w = QUOTE(W_PART(24));
                    h = QUOTE(H_PART(17.5));
                    columns[] = {0, 0.7};
                };
            };
        };
    };
};
