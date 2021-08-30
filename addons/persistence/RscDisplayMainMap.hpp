class RscDisplayMainMap {
    class controls {
        class RespawnControlsGroup: RscControlsGroupNoScrollbars {
            onLoad = QUOTE((_this select 0) ctrlEnable false; _this execVM 'a3\ui_f\scripts\gui\RscRespawnControls.sqf'; _this call FUNC(ui_onLoadDisplayRespawn));
        };
    };
};
