class CBA_Extended_EventHandlers;

class CfgVehicles {
    class Car_F;
    class UK3CB_BAF_Jackal_Base : Car_F {
        RACKS_GROUND;
    };
    class UK3CB_BAF_LandRover_Base : Car_F {
        RACKS_GROUND;
    };
    class Wheeled_APC_F;
    class CUP_Mastiff_Base : Wheeled_APC_F {
        INTERCOM_GROUND;
        RACKS_GROUND;
    };
    class CUP_Ridgback_Base : Wheeled_APC_F {
        INTERCOM_GROUND;
        RACKS_GROUND;
    };
    class CUP_Wolfhound_Base : Wheeled_APC_F {
        INTERCOM_GROUND;
        RACKS_GROUND;
    };
    class Truck_01_base_F;
    class UK3CB_BAF_MAN_HX60_Base : Truck_01_base_F {
        RACKS_AIR_GROUND;
    };

    class ThingX;
    class GVAR(rebroStationBox): ThingX {
        scope = 2;
        scopeCurator = 2;
        author = QUOTE(UKSF);
        displayName = "Re-broadcasting Station Box";
        model = "\idi\acre\addons\sys_radio\data\models\acre_radiobox.p3d";
        editorPreview = "\idi\acre\addons\sys_radio\data\ui\acreRadioBox.jpg";
        editorCategory = "EdCat_Supplies";
        editorSubcategory = QEGVAR(common,resupply);
        icon = "iconObject_1x1";
        vehicleClass = "Cargo";
        ace_cargo_canLoad = 1;
        ace_cargo_size = 2;
        ace_dragging_canCarry = 1;
        ace_dragging_canDrag = 1;
        ace_dragging_carryPosition[] = {0, 1.4, 0};
        ace_dragging_dragPosition[] = {0, 1.2, 0};
    };

    class vhf30108Item;
    class GVAR(rebroStationMast): vhf30108Item {
        scope = 1;
        displayName = "Re-broadcasting Station Mast";

        class AcreComponents {};
        class ACE_Actions {};
    };

    class Land_PortableServer_01_black_F;
    class GVAR(rebroStationEquipment): Land_PortableServer_01_black_F {
        scope = 1;
        displayName = "Re-broadcasting Station Equipment";

        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
        };
    };
};
