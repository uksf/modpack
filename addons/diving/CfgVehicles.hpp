class CfgVehicles {
    class B_Carryall_khk;
    class GVAR(bag) : B_Carryall_khk {
        author = "UKSF";
        scope = 2;
        model = "\A3\weapons_f\Ammoboxes\bags\Backpack_Tortila";
        displayName = "Diving Bag (Adv)";
        descriptionShort = "Black backpack for transporting the divers equipment.";
        picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Tortila_blk.paa";
        hiddenSelectionsTextures[] = { "\A3\weapons_f\ammoboxes\bags\data\backpack_tortila_blk_co.paa" };
        maximumLoad = 500;
        mass = 75;
    };
    DEPRECATE_CLASS(ade_item_bag,GVAR(bag));

    class LandVehicle;
    class StaticWeapon : LandVehicle {
        class ACE_Actions {
            class ACE_MainActions;
        };
        class ACE_SelfActions;
    };
    class Pod_Heli_Transport_04_crewed_base_F : StaticWeapon {};
    class Land_Pod_Heli_Transport_04_medevac_F : Pod_Heli_Transport_04_crewed_base_F {};
    class GVAR(decoPod) : Land_Pod_Heli_Transport_04_medevac_F {
        author = "UKSF";
        displayName = "Decompression Pod";
        editorCategory = "EdCat_Supplies";
        editorSubcategory = QEGVAR(common,support);
        simulation = "submarinex";
        pointPilot = "pilot";
        pointCommander = "velitel";
        leftEngineEffect = "";
        rightEngineEffect = "";
        memoryPointsLeftEngineEffect = "EngineEffectL";
        memoryPointsRightEngineEffect = "EngineEffectR";
        class ACE_Actions : ACE_Actions {
            class ACE_MainActions : ACE_MainActions {
                class GVAR(loadPatient) {
                    displayName = "Load Patient";
                    condition = QUOTE(!isNull ([_target] call FUNC(nearestPodPatient)));
                    statement = QUOTE([ARR_2(_target,_player)] call FUNC(loadPodPatient));
                    exceptions[] = { "isNotSwimming" };
                };
            };
        };
        class ACE_SelfActions : ACE_SelfActions {
            class GVAR(decompress) {
                displayName = "Decompress";
                condition = QUOTE(GVAR(updatePFHID) != -1);
                statement = QUOTE([_target] call FUNC(decompress));
                exceptions[] = { "isNotInside", "isNotSwimming" };
                icon = QPATHTOF(data\ui\iconDiveComputer.paa);
            };
        };
    };
};
