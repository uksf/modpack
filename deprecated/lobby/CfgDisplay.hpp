#define DELETE_RANK delete CA_PlayerName; \
                    delete ProfilePicture; \
                    delete ProfileBackground; \
                    delete Separator1;

class RscControlsGroup;
class RscControlsGroupNoScrollbars;
class RscDisplayMainMap {
    class controls {
        class TopRight: RscControlsGroup {
            class controls {
                DELETE_RANK
            };
        };
        class RespawnControlsGroup: RscControlsGroupNoScrollbars {
            onLoad = QUOTE((_this select 0) ctrlEnable false; _this execVM 'a3\ui_f\scripts\gui\RscRespawnControls.sqf'; _this call (uiNamespace getVariable QQFUNC(initDisplayRespawn)));
        };
    };
};
class RscDisplayDiary {
    class controls {
        class TopRight: RscControlsGroup {
            class controls {
                DELETE_RANK
            };
        };
    };
};
class RscDisplayGetReady: RscDisplayMainMap {
    class controls {
        class TopRight: RscControlsGroup {
            class controls {
                DELETE_RANK
            };
        };
    };
};
class RscDisplayServerGetReady: RscDisplayGetReady {
    class controls {
        class TopRight: RscControlsGroup {
            class controls {
                DELETE_RANK
            };
        };
    };
};
class RscDisplayClientGetReady: RscDisplayGetReady {
    class controls {
        class TopRight: RscControlsGroup {
            class controls {
                DELETE_RANK
            };
        };
    };
};
