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
