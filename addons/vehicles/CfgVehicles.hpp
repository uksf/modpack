class CfgVehicles {
    class LandVehicle;
    class Car: LandVehicle {
        class ACE_Actions;
        class Turrets;
    };
    class Car_F: Car {
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions;
        };
        class Turrets: Turrets {
            class MainTurret;
        };
        class HitPoints;
    };
    class Wheeled_APC_F: Car_F {
        class NewTurret;
    };

    #include "vehicles\CfgJackal.hpp"
    #include "vehicles\CfgCoyote.hpp"
    #include "vehicles\CfgLandRover.hpp"
    #include "vehicles\CfgMastiff.hpp"
    #include "vehicles\CfgRidgeback.hpp"
    #include "vehicles\CfgWolfhound.hpp"
    #include "vehicles\CfgHemtt.hpp"

    class Items_base_F;
    class Land_CanisterFuel_F: Items_base_F {
        scope = 2;
        scopeCurator = 2;
        faction = "CUP_B_GB";
        displayName = "Jerry Can";
        editorCategory = QEGVAR(common,UKSF);
        editorSubcategory = QEGVAR(common,support);
        editorPreview = QPATHTOEF(common,data\previews\Land_CanisterFuel_F.jpg);
        simulation = "thingX";
        class EventHandlers {
            class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
        };
        SLX_XEH_DISABLED = 0;
        ace_cargo_canLoad = 1;
        ace_cargo_size = 1;
        ace_dragging_canCarry = 1;
        ace_dragging_canDrag = 1;
        ace_dragging_carryPosition[] = {0, 1, 1};
        ace_dragging_carryDirection = 0;
        ace_dragging_dragPosition[] = {0, 1.2, 0};
        ace_dragging_dragDirection = 0;
        ace_refuel_fuelCapacity = 20;
        ace_refuel_fuelCargo = 20;
        ace_refuel_flowRate = 4;
        ace_refuel_hooks[] = {{0.125,0,0.19}};
        class ACE_Actions {
            class ACE_MainActions {
                displayName = "Interactions";
                position = "[0,0,0]";
                selection = "";
                distance = 4;
                condition = 1;
                class ace_refuel_Refuel {
                    displayName = "$STR_ace_refuel_Refuel";
                    distance = 10;
                    condition = 1;
                    statement = "";
                    showDisabled = 0;
                    priority = 2;
                    icon = "\z\ace\addons\refuel\ui\icon_refuel_interact.paa";
                    class ace_refuel_TakeNozzle {
                        displayName = "$STR_ace_refuel_TakeNozzle";
                        condition = "[_player,_target] call ace_refuel_fnc_canTakeNozzle";
                        statement = "[_player,_target,objNull] call ace_refuel_fnc_TakeNozzle";
                        exceptions[] = { "isNotInside" };
                        icon = "\z\ace\addons\refuel\ui\icon_refuel_interact.paa";
                    };
                    class ace_refuel_CheckFuelCounter {
                        displayName = "$STR_ace_refuel_CheckFuelCounter";
                        condition = 1;
                        statement = "[_player,_target] call ace_refuel_fnc_readFuelCounter";
                        exceptions[] = { "isNotInside" };
                        icon = "\z\ace\addons\refuel\ui\icon_refuel_interact.paa";
                    };
                    class ace_refuel_CheckFuel {
                        displayName = "$STR_ace_refuel_CheckFuel";
                        condition = "[_player,_target] call ace_refuel_fnc_canCheckFuel";
                        statement = "[_player,_target] call ace_refuel_fnc_checkFuel";
                        exceptions[] = { "isNotInside" };
                        icon = "\z\ace\addons\refuel\ui\icon_refuel_interact.paa";
                    };
                    class ace_refuel_Return {
                        displayName = "$STR_ace_refuel_Return";
                        condition = "[_player,_target] call ace_refuel_fnc_canReturnNozzle";
                        statement = "[_player,_target] call ace_refuel_fnc_returnNozzle";
                        exceptions[] = { "isNotInside" };
                        icon = "\z\ace\addons\refuel\ui\icon_refuel_interact.paa";
                    };
                };
            };
        };
    };
    class CargoNet_01_base_F;
    class CargoNet_01_barrels_F: CargoNet_01_base_F {
        scope = 2;
        scopeCurator = 2;
        faction = "CUP_B_GB";
        displayName = "Cargo Net (Fuel Barrels)";
        editorCategory = QEGVAR(common,UKSF);
        editorSubcategory = QEGVAR(common,support);
        editorPreview = QPATHTOEF(common,data\previews\CargoNet_01_barrels_F.jpg);
        ace_refuel_fuelCapacity = 800;
        ace_refuel_fuelCargo = 800;
        ace_refuel_flowRate = 2;
        ace_cargo_hasCargo = 0;
        ace_refuel_hooks[] = {{0.498,0.27,0.485}};
        class ACE_Actions {
            class ACE_MainActions {
                displayName = "Interactions";
                position = "[0,0,0]";
                selection = "";
                distance = 4;
                condition = 1;
                class ace_refuel_Refuel {
                    displayName = "$STR_ace_refuel_Refuel";
                    distance = 10;
                    condition = 1;
                    statement = "";
                    showDisabled = 0;
                    priority = 2;
                    icon = "\z\ace\addons\refuel\ui\icon_refuel_interact.paa";
                    class ace_refuel_TakeNozzle {
                        displayName = "$STR_ace_refuel_TakeNozzle";
                        condition = "[_player,_target] call ace_refuel_fnc_canTakeNozzle";
                        statement = "[_player,_target,objNull] call ace_refuel_fnc_TakeNozzle";
                        exceptions[] = { "isNotInside" };
                        icon = "\z\ace\addons\refuel\ui\icon_refuel_interact.paa";
                    };
                    class ace_refuel_CheckFuelCounter {
                        displayName = "$STR_ace_refuel_CheckFuelCounter";
                        condition = 1;
                        statement = "[_player,_target] call ace_refuel_fnc_readFuelCounter";
                        exceptions[] = { "isNotInside" };
                        icon = "\z\ace\addons\refuel\ui\icon_refuel_interact.paa";
                    };
                    class ace_refuel_CheckFuel {
                        displayName = "$STR_ace_refuel_CheckFuel";
                        condition = "[_player,_target] call ace_refuel_fnc_canCheckFuel";
                        statement = "[_player,_target] call ace_refuel_fnc_checkFuel";
                        exceptions[] = { "isNotInside" };
                        icon = "\z\ace\addons\refuel\ui\icon_refuel_interact.paa";
                    };
                    class ace_refuel_Return {
                        displayName = "$STR_ace_refuel_Return";
                        condition = "[_player,_target] call ace_refuel_fnc_canReturnNozzle";
                        statement = "[_player,_target] call ace_refuel_fnc_returnNozzle";
                        exceptions[] = { "isNotInside" };
                        icon = "\z\ace\addons\refuel\ui\icon_refuel_interact.paa";
                    };
                };
            };
        };
    };
};
