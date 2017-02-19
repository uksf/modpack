class CfgVehicles {
    class Land_PowerGenerator_F;
    class UKSF_ATC_Core: Land_PowerGenerator_F {
        scope = 2;
        scopeCurator = 2;
        author = "UKSF";
        faction = "CUP_B_GB";
        editorSubcategory = QEGVAR(common,objects);
        displayname = "ATC Core";
        model = "z\ace\addons\fastroping\data\helper.p3d";
        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
        };
        class ACE_Actions {
            class ACE_MainActions {
                displayName = "ATC Radar";
                position = "";
                condition = "true";
                statement = "";
                showDisabled = 1;
                priority = 1;
                distance = 5;
                class ACE_startRadar {
                    displayName = "Start ATC Radar";
                    condition = QUOTE(!(_player getVariable [ARR_2(QQGVAR(isOperator), false)]) && !(_target getVariable [ARR_2(QQGVAR(radarOn), false)]));
                    statement = QUOTE([ARR_2(_target, _player)] call FUNC(loop));
                    showDisabled = 1;
                    priority = 1;
                };
                class ACE_stopRadar {
                    displayName = "Stop ATC Radar";
                    condition = QUOTE((_player == (_target getVariable [ARR_2(QQGVAR(isOperator), objNull)])) && (_target getVariable [ARR_2(QQGVAR(radarOn), false)]));
                    statement = QUOTE([ARR_2(_target, _player)] call FUNC(stop));
                    showDisabled = 1;
                    priority = 1;
                };
                class ACE_equipPilot {
                    displayName = "Equip Pilot";
                    condition = QUOTE(!(_player getVariable [ARR_2(QQGVAR(loadoutPilot), false)]));
                    statement = QUOTE(call FUNC(equipPilot));
                    showDisabled = 1;
                    priority = 1;
                };
                class ACE_equipATC {
                    displayName = "Equip ATC";
                    condition = QUOTE(_player getVariable [ARR_2(QQGVAR(loadoutPilot), true)]);
                    statement = QUOTE(call FUNC(equipATC));
                    showDisabled = 1;
                    priority = 1;
                };
            };
        };
    };
    class UKSF_ATC_Station: Land_PowerGenerator_F {
        scope = 2;
        scopeCurator = 2;
        author = "UKSF";
        faction = "CUP_B_GB";
        editorSubcategory = QEGVAR(common,objects);
        displayname = "ATC Station";
        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
        };
    };
};