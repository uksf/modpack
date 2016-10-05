#include "\z\ace\addons\common\define.hpp"

#define GUI_GRID_W  (0.025)
#define GUI_GRID_H  (0.04)

class RscText;

class GVAR(menu) {
	idd = 85730;
	movingEnable = false;
	controlsBackground[] = {};
	objects[] = {};
	class controls {
		class background : ACE_gui_backgroundBase {
			idc = -1;
			x = 12 * GUI_GRID_W;
			y = 10.5 * GUI_GRID_H;
			w = 16 * GUI_GRID_W;
			h = 4.5 * GUI_GRID_H;
		};
		class btnClose : ACE_gui_buttonBase {
			idc = -1;
			text = QUOTE(Close);
			action = QUOTE(GVAR(screenState) = 1; closeDialog 0);
			x = 13 * GUI_GRID_W;
			y = 13 * GUI_GRID_H;
			w = 4 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
		};
		class btnLogout : btnClose {
			text = QUOTE(Logout);
			y = 11 * GUI_GRID_H;
			action = QUOTE([] call FUNC(login););
		};
	};
};

class GVAR(login) {
	idd = 85731;
	movingEnable = false;
	onLoad = QUOTE(call FUNC(initLogin));
	controlsBackground[] = {};
	objects[] = {};
	class controls {
		class background : ACE_gui_backgroundBase {
			idc = -1;
			x = 10 * GUI_GRID_W;
			y = 10.5 * GUI_GRID_H;
			w = 20 * GUI_GRID_W;
			h = 4.5 * GUI_GRID_H;
		};
		class txtName : RscText {
			idc = 1020;
			x = 13 * GUI_GRID_W;
			y = 12 * GUI_GRID_H;
			w = 12 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
		};
		class txtZeus : txtName {
			idc = -1;
			text = QUOTE(Zeus :);
			x = 10.5 * GUI_GRID_W;
			y = 12 * GUI_GRID_H;
			w = 4 * GUI_GRID_W;
		};
		class btnClose : ACE_gui_buttonBase {
			idc = -1;
			action = QUOTE(closeDialog 0);
			text = QUOTE(Close);
			x = 25.5 * GUI_GRID_W;
			y = 13 * GUI_GRID_H;
			w = 4 * GUI_GRID_W;
			h = 1.5 * GUI_GRID_H;
		};
		class btnLogin : btnClose {
			action = QUOTE([] call FUNC(login););
			text = QUOTE(Login);
			y = 11 * GUI_GRID_H;
		};
	};
};