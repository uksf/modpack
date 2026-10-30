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
#define RAIN_OVERCAST 0.7
#define COLOUR_FRIENDLY [0.4, 0.75, 1, 1]
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
#define COLOUR_VISIBLE [0, 1, 0, 0.35]

#define REPORT_FIELDS 6
#define MESSAGES_SHOWN 12

#define MARKER_REFRESH_DELAY 1
#define MARKER_ICONS [["Enemy infantry", 0], ["Enemy mechanised", 1], ["Enemy motorised", 2], ["Enemy armour", 3], ["Enemy helicopter", 4], ["Enemy plane", 5], ["Enemy unknown", 6], ["Enemy MG", 8], ["Enemy AT", 9], ["Enemy mortar", 12], ["Enemy AA", 13], ["Mine", 80], ["IED", 81], ["Waypoint", 20], ["Objective", 21], ["Medical", 22], ["Warning", 23], ["Friendly HQ", 30], ["Dot", 100], ["Circle", 101], ["Contact point", 102], ["Outpost", 104], ["Target reference point", 106], ["Checkpoint", 201], ["Rally point", 204], ["Casualty collection point", 207]]
#define MARKER_SIZES [["No size or label", 0], ["Team or A", 1], ["Squad or B", 2], ["Section or C", 3], ["Platoon or D", 4]]
#define MARKER_DIRECTIONS [["No direction", 0], ["N", 1], ["NE", 2], ["E", 3], ["SE", 4], ["S", 5], ["SW", 6], ["W", 7], ["NW", 8]]

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
#define DRONE_REROUTE_DELAY 2

#define MPU5_CLASS "ACRE_MPU5"
#define MPU5_TALKGROUPS 16
#define DRONE_ESCORT_MOVE 50

#define LAUNCHER_COLUMNS 3
#define LAUNCHER_ROWS 4
