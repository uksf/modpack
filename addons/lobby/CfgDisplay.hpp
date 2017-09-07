#define DELETE delete CA_PlayerName; \
                delete ProfilePicture; \
                delete ProfileBackground; \
                delete Separator1;

class RscControlsGroup;
class RscDisplayMainMap {
    class controls {
        class TopRight: RscControlsGroup {
            class controls {
                DELETE
            };
        };
    };
};
class RscDisplayDiary {
    class controls {
        class TopRight: RscControlsGroup {
            class controls {
                DELETE
            };
        };
    };
};
class RscDisplayGetReady: RscDisplayMainMap {
    class controls {
        class TopRight: RscControlsGroup {
            class controls {
                DELETE
            };
        };
    };
};
class RscDisplayServerGetReady: RscDisplayGetReady {
    class controls {
        class TopRight: RscControlsGroup {
            class controls {
                DELETE
            };
        };
    };
};
class RscDisplayClientGetReady: RscDisplayGetReady {
    class controls {
        class TopRight: RscControlsGroup {
            class controls {
                DELETE
            };
        };
    };
};
