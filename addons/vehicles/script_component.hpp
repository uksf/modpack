#define COMPONENT vehicles
#define COMPONENT_BEAUTIFIED Vehicles
#include "\u\uksf\addons\main\script_mod.hpp"

//#define DEBUG_MODE_FULL
//#define DISABLE_COMPILE_CACHE
//#define CBA_DEBUG_SYNCHRONOUS

#include "\u\uksf\addons\main\script_macros.hpp"

#define NET_DEPLOY_TIME 15
#define JACKAL_FUEL_CAPACITY 5 //Reduced from 100 (5% of 100 gave ~27km range)

#define NET_ACTIONS \
    class ACE_Actions : ACE_Actions { \
        class ACE_MainActions : ACE_MainActions { \
            class ACE_deployNetWoodland { \
                displayName = "Deploy Net (Woodland)"; \
                condition = QUOTE(!(_target getVariable [ARR_2(QQGVAR(deployed),false)]) && (isNull (_target getVariable [ARR_2(QQGVAR(netObj),objNull)]))); \
                statement = QUOTE([ARR_3(_target,_player,'CamoNet_BLUFOR_big_F')] call FUNC(deployNet)); \
                showDisabled = 0; \
                priority = 1; \
            }; \
            class ACE_deployNetDesert { \
                displayName = "Deploy Net (Desert)"; \
                condition = QUOTE(!(_target getVariable [ARR_2(QQGVAR(deployed),false)]) && (isNull (_target getVariable [ARR_2(QQGVAR(netObj),objNull)]))); \
                statement = QUOTE([ARR_3(_target,_player,'Land_CamoNetB_NATO_EP1')] call FUNC(deployNet)); \
                showDisabled = 0; \
                priority = 1; \
            }; \
            class ACE_concealNet { \
                displayName = "Conceal Net"; \
                condition = QUOTE((_target getVariable [ARR_2(QQGVAR(deployed),false)]) && !(isNull (_target getVariable [ARR_2(QQGVAR(netObj),objNull)])) && ((_target distance (_target getVariable [ARR_2(QQGVAR(netObj),objNull)])) < 10)); \
                statement = QUOTE([ARR_2(_target,_player)] call FUNC(concealNet)); \
                showDisabled = 0; \
                priority = 1; \
            }; \
        }; \
    };

#define NET_MEDICAL_ACTIONS \
    class ACE_Actions : ACE_Actions { \
        class ACE_MainActions : ACE_MainActions { \
            class ACE_deployNetWoodland { \
                displayName = "Deploy Medical Net (Woodland)"; \
                condition = QUOTE(!(_target getVariable [ARR_2(QQGVAR(deployed),false)]) && (isNull (_target getVariable [ARR_2(QQGVAR(netObj),objNull)]))); \
                statement = ""; \
                class ACE_left { \
                    displayName = "Left"; \
                    condition = QUOTE(!(_target getVariable [ARR_2(QQGVAR(deployed),false)]) && (isNull (_target getVariable [ARR_2(QQGVAR(netObj),objNull)]))); \
                    statement = QUOTE([ARR_4(_target,_player,'CamoNet_BLUFOR_open_F',[ARR_3(-2.6,-3,-0.65)])] call FUNC(deployNetMedical)); \
                    showDisabled = 0; \
                    priority = 1; \
                }; \
                class ACE_right { \
                    displayName = "Right"; \
                    condition = QUOTE(!(_target getVariable [ARR_2(QQGVAR(deployed),false)]) && (isNull (_target getVariable [ARR_2(QQGVAR(netObj),objNull)]))); \
                    statement = QUOTE([ARR_4(_target,_player,'CamoNet_BLUFOR_open_F',[ARR_3(1.6,-3,-0.65)])] call FUNC(deployNetMedical)); \
                    showDisabled = 0; \
                    priority = 1; \
                }; \
            }; \
            class ACE_deployNetDesert { \
                displayName = "Deploy Medical Net (Desert)"; \
                condition = QUOTE(!(_target getVariable [ARR_2(QQGVAR(deployed),false)]) && (isNull (_target getVariable [ARR_2(QQGVAR(netObj),objNull)]))); \
                statement = ""; \
                class ACE_left { \
                    displayName = "Left"; \
                    condition = QUOTE(!(_target getVariable [ARR_2(QQGVAR(deployed),false)]) && (isNull (_target getVariable [ARR_2(QQGVAR(netObj),objNull)]))); \
                    statement = QUOTE([ARR_4(_target,_player,'Land_CamoNetVar_NATO_EP1',[ARR_3(-2.6,-3,-0.65)])] call FUNC(deployNetMedical)); \
                    showDisabled = 0; \
                    priority = 1; \
                }; \
                class ACE_right { \
                    displayName = "Right"; \
                    condition = QUOTE(!(_target getVariable [ARR_2(QQGVAR(deployed),false)]) && (isNull (_target getVariable [ARR_2(QQGVAR(netObj),objNull)]))); \
                    statement = QUOTE([ARR_4(_target,_player,'Land_CamoNetVar_NATO_EP1',[ARR_3(1.6,-3,-0.65)])] call FUNC(deployNetMedical)); \
                    showDisabled = 0; \
                    priority = 1; \
                }; \
            }; \
            class ACE_concealNet { \
                displayName = "Conceal Medical Net"; \
                condition = QUOTE((_target getVariable [ARR_2(QQGVAR(deployed),false)]) && !(isNull (_target getVariable [ARR_2(QQGVAR(netObj),objNull)])) && ((_target distance (_target getVariable [ARR_2(QQGVAR(netObj),objNull)])) < 10)); \
                statement = QUOTE([ARR_2(_target,_player)] call FUNC(concealNet)); \
                showDisabled = 0; \
                priority = 1; \
            }; \
        }; \
    };

#define SUPPORT_ACTIONS \
    class ACE_Actions: ACE_Actions { \
        class ACE_MainActions: ACE_MainActions { \
            class ace_refuel_Refuel { \
                displayName = "$STR_ace_refuel_Refuel"; \
                distance = 10; \
                condition = 1; \
                statement = ""; \
                showDisabled = 0; \
                priority = 2; \
                icon = "\z\ace\addons\refuel\ui\icon_refuel_interact.paa"; \
                class ace_refuel_TakeNozzle { \
                        displayName = "$STR_ace_refuel_TakeNozzle"; \
                        condition = "[_player,_target] call ace_refuel_fnc_canTakeNozzle"; \
                        statement = "[_player,_target,objNull] call ace_refuel_fnc_TakeNozzle"; \
                        exceptions[] = { "isNotInside" }; \
                        icon = "\z\ace\addons\refuel\ui\icon_refuel_interact.paa"; \
                }; \
                class ace_refuel_CheckFuelCounter { \
                        displayName = "$STR_ace_refuel_CheckFuelCounter"; \
                        condition = 1; \
                        statement = "[_player,_target] call ace_refuel_fnc_readFuelCounter"; \
                        exceptions[] = { "isNotInside" }; \
                        icon = "\z\ace\addons\refuel\ui\icon_refuel_interact.paa"; \
                }; \
                class ace_refuel_CheckFuel { \
                        displayName = "$STR_ace_refuel_CheckFuel"; \
                        condition = "[_player,_target] call ace_refuel_fnc_canCheckFuel"; \
                        statement = "[_player,_target] call ace_refuel_fnc_checkFuel"; \
                        exceptions[] = { "isNotInside" }; \
                        icon = "\z\ace\addons\refuel\ui\icon_refuel_interact.paa"; \
                }; \
                class ace_refuel_Return { \
                        displayName = "$STR_ace_refuel_Return"; \
                        condition = "[_player,_target] call ace_refuel_fnc_canReturnNozzle"; \
                        statement = "[_player,_target] call ace_refuel_fnc_returnNozzle"; \
                        exceptions[] = { "isNotInside" }; \
                        icon = "\z\ace\addons\refuel\ui\icon_refuel_interact.paa"; \
                }; \
            }; \
            class ace_rearm_TakeAmmo { \
                displayName = "$STR_ace_rearm_TakeAmmo"; \
                distance = 7; \
                condition = "_this call ace_rearm_fnc_canTakeAmmo"; \
                insertChildren = "_target call ace_rearm_fnc_addRearmActions"; \
                exceptions[] = { "isNotInside" }; \
                showDisabled = 0; \
                priority = 2; \
                icon = "\z\ace\addons\rearm\ui\icon_rearm_interact.paa"; \
            }; \
            class ace_rearm_StoreAmmo { \
                displayName = "$STR_ace_rearm_StoreAmmo"; \
                distance = 7; \
                condition = "_this call ace_rearm_fnc_canStoreAmmo"; \
                statement = "_this call ace_rearm_fnc_storeAmmo"; \
                exceptions[] = { "isNotInside" }; \
                icon = "\z\ace\addons\rearm\ui\icon_rearm_interact.paa"; \
            }; \
        }; \
    };

#define COYOTE_SUPPORT \
    transportFuel = 0; \
    transportRepair = 0; \
    transportAmmo = 0; \
    ace_refuel_hooks[] = {{0.87, -2.47, 1.65}}; \
    ace_refuel_fuelCargo = 3000; \
    ace_repair_canRepair = 1; \
    SUPPORT_ACTIONS

#define REARM_ACTIONS \
    class UserActions { \
        class ResupplyAmmo { \
            displayName = "<t color='#217cd1'>Reload</t>"; \
            displayNameDefault = "<img image='A3\ui_f\data\igui\cfg\actions\reammo_ca' size='2' shadow='true' />"; \
            position = "crew_center"; \
            radius = 4; \
            priority = 5.92; \
            showwindow = 0; \
            condition = QUOTE(this call FUNC(canResupply)); \
            statement = QUOTE(this call FUNC(resupply)); \
            onlyforplayer = 1; \
        }; \
    };
