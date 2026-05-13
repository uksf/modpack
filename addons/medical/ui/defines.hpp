#ifndef UKSF_MEDICAL_UI_DEFINES
#define UKSF_MEDICAL_UI_DEFINES

#define IDD_UNCON                 859102

// Tab buttons (top)
#define IDC_TAB_HEALTH            547
#define IDC_TAB_SPECTATOR         548
#define IDC_TAB_VIEWMODE          559

// Spectator tab controls
#define IDC_SPEC_TOO_FAR          550
#define IDC_SPEC_INFO             551
#define IDC_SPEC_PIP              552
#define IDC_SPEC_NO_SIGNAL        553
#define IDC_SPEC_NVG_0            556
#define IDC_SPEC_NVG_1            557
#define IDC_SPEC_NVG_2            558

// Health tab controls
#define IDC_HEALTH_HR             573
#define IDC_HEALTH_BP             574
#define IDC_HEALTH_RESP           575
#define IDC_HEALTH_SPO2           576
#define IDC_HEALTH_STATE_TIMER    577
#define IDC_HEALTH_TABFOCUS       578

// Control types
#define CT_STATIC                 0
#define CT_BUTTON                 1
#define ST_LEFT                   0
#define ST_CENTER                 2
#define ST_PICTURE                0x30

// Fonts
#define GUI_FONT_NORMAL           PuristaMedium

// Grid (Arma 3 stock centre grid)
#define GUI_GRID_CENTER_WAbs      ((safezoneW / safezoneH) min 1.2)
#define GUI_GRID_CENTER_HAbs      (GUI_GRID_CENTER_WAbs / 1.2)
#define GUI_GRID_CENTER_W         (GUI_GRID_CENTER_WAbs / 40)
#define GUI_GRID_CENTER_H         (GUI_GRID_CENTER_HAbs / 25)
#define GUI_GRID_CENTER_X         (safezoneX + (safezoneW - GUI_GRID_CENTER_WAbs)/2)
#define GUI_GRID_CENTER_Y         (safezoneY + (safezoneH - GUI_GRID_CENTER_HAbs)/2)

#endif
