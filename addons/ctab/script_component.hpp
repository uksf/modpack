#define COMPONENT ctab
#define COMPONENT_BEAUTIFIED cTab
#include "\u\uksf\addons\main\script_mod.hpp"

#include "\u\uksf\addons\main\script_macros.hpp"

#define ANDROID_DIALOG "cTab_Android_dlg"
#define MODE_PREFIX "UKSF_"
#define MODE_LAUNCHER "UKSF_APPS"
#define MODE_APP_PREFIX "UKSF_APP_"
#define DEFAULT_MODE "BFT"

#define IDC_APPS_GROUP 1790000
#define IDC_APPS_BUTTON 1790001
#define IDC_APPS_PANEL 1790002
#define IDC_MAP_SCREEN 1201
#define IDC_MAP_TOPO 1202

#define APP_CTRL(name) (uiNamespace getVariable [QGVAR(name), controlNull])

#define DOUBLE_CLICK_TIME 0.35
#define COLOUR_ROUTE [1, 0.6, 0, 1]
#define COLOUR_TEXT [1, 1, 1, 1]
#define ICON_DOT "\A3\ui_f\data\map\markers\military\dot_ca.paa"
#define ICON_MAN "\A3\ui_f\data\map\VehicleIcons\iconmanvirtual_ca.paa"
#define FILL_SOLID "#(rgb,1,1,1)color(1,1,1,1)"

#define SPEED_FOOT 1.4
#define SPEED_VEHICLE 11.1

#define COLOUR_JUMP [0, 0.8, 1, 1]
#define ICON_DZ "\A3\ui_f\data\map\markers\military\end_ca.paa"

#define ELEVATION_CELLS 50
#define ELEVATION_CELLS_PER_FRAME 100
#define ELEVATION_TARGET_HEIGHT 1.7
#define ELEVATION_FULL_COLOUR_HEIGHT 100

#define REPORT_FIELDS 6

#define JUMP_FALL_START_TIME 4
#define JUMP_FALL_START_HEIGHT 130
#define JUMP_FALL_SPEED 67
#define JUMP_FALL_WIND_SHARE 0.1
#define JUMP_CANOPY_SINK 3
#define JUMP_CANOPY_SPEED 4.4
#define JUMP_GLIDE_USED 0.8
#define JUMP_HALO_OPENING 500
#define JUMP_HAHO_OPENING 7500
#define JUMP_OXYGEN_ALTITUDE 3000

#define DRONE_LOITER_RADIUS 300
#define DRONE_ESCORT_INTERVAL 10

#define LAUNCHER_COLUMNS 3
#define LAUNCHER_ROWS 4
