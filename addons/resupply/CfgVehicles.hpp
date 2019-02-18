class CfgVehicles {
    class B_supplyCrate_F;
    class UKSF_S_Empty: B_supplyCrate_F {
        author = "UKSF";
        faction = "CUP_B_GB";
        scope = 2;
        scopeCurator = 2;
        editorCategory = "EdCat_Supplies";
        editorSubcategory = QEGVAR(common,resupply);
        displayName = "Empty Crate";
        editorPreview = QPATHTOEF(common,data\previews\UKSF_S_Empty.jpg);
        maximumLoad = 100000;
        transportMaxWeapons = 200;
        transportMaxMagazines = 1000;
        transportMaxBackpacks = 100;
        ace_cargo_hasCargo = 1;
        ace_cargo_space = 20;
        class TransportMagazines {};
        class TransportWeapons {};
        class TransportItems {};
        class TransportBackpacks {};
    };
    class UKSF_S_Arsenal: UKSF_S_Empty {
        displayName = "Arsenal Crate";
    };
    class UKSF_S_R1: UKSF_S_Empty {
        displayName = "R1 Crate";
        editorPreview = QPATHTOEF(common,data\previews\UKSF_S_R1.jpg);
        hiddenSelectionsTextures[] = { QPATHTOF(data\R1_co.paa) };
        class TransportMagazines {
            MACRO_ADDMAGAZINE(UK3CB_BAF_556_30Rnd,50);
            MACRO_ADDMAGAZINE(UK3CB_BAF_556_30Rnd_T,50);
            MACRO_ADDMAGAZINE(UK3CB_BAF_556_200Rnd,15);
            MACRO_ADDMAGAZINE(UK3CB_BAF_556_200Rnd_T,15);
            MACRO_ADDMAGAZINE(UK3CB_BAF_762_100Rnd,15);
            MACRO_ADDMAGAZINE(UK3CB_BAF_762_100Rnd_T,15);
            MACRO_ADDMAGAZINE(UK3CB_BAF_762_L42A1_20Rnd,20);
            MACRO_ADDMAGAZINE(UK3CB_BAF_338_5Rnd,10);
            MACRO_ADDMAGAZINE(UK3CB_BAF_9_17Rnd,10);
            MACRO_ADDMAGAZINE(1Rnd_HE_Grenade_shell,40);
            MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_Smoke_Grenade_shell,5);
            MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_SmokeRed_Grenade_shell,5);
            MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_SmokeGreen_Grenade_shell,5);
            MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_SmokeBlue_Grenade_shell,5);
            MACRO_ADDMAGAZINE(UK3CB_BAF_UGL_FlareWhite_F,10);
            MACRO_ADDMAGAZINE(CUP_1Rnd_StarFlare_White_M203,5);
            MACRO_ADDMAGAZINE(CUP_1Rnd_StarCluster_White_M203,5);
            MACRO_ADDMAGAZINE(HandGrenade,20);
            MACRO_ADDMAGAZINE(SmokeShell,10);
            MACRO_ADDMAGAZINE(SmokeShellRed,10);
            MACRO_ADDMAGAZINE(SmokeShellGreen,10);
            MACRO_ADDMAGAZINE(SmokeShellBlue,10);
        };
        class TransportWeapons {
            MACRO_ADDWEAPON(UK3CB_BAF_NLAW_Launcher,5);
            MACRO_ADDWEAPON(UK3CB_BAF_AT4_CS_AT_Launcher,5);
            MACRO_ADDWEAPON(UK3CB_BAF_AT4_CS_AP_Launcher,5);
            MACRO_ADDWEAPON(UK3CB_BAF_Javelin_Slung_Tube,5);
        };
        class TransportItems {
            MACRO_ADDITEM(UK3CB_BAF_Javelin_CLU,2);
        };
    };
    class UKSF_S_R2: UKSF_S_Empty {
        displayName = "R2 Crate";
        editorPreview = QPATHTOEF(common,data\previews\UKSF_S_R2.jpg);
        hiddenSelectionsTextures[] = { QPATHTOF(data\R2_co.paa) };
        class TransportMagazines {
            MACRO_ADDMAGAZINE(DemoCharge_Remote_Mag,10);
            MACRO_ADDMAGAZINE(SatchelCharge_Remote_Mag,5);
            MACRO_ADDMAGAZINE(BreachCharge_Remote_Mag,5);
        };
        class TransportWeapons {
            MACRO_ADDWEAPON(UK3CB_BAF_NLAW_Launcher,10);
            MACRO_ADDWEAPON(UK3CB_BAF_AT4_CS_AT_Launcher,10);
            MACRO_ADDWEAPON(UK3CB_BAF_AT4_CS_AP_Launcher,10);
            MACRO_ADDWEAPON(UK3CB_BAF_Javelin_Slung_Tube,10);
        };
        class TransportItems {
            MACRO_ADDITEM(UK3CB_BAF_Javelin_CLU,2);
            MACRO_ADDITEM(ACE_Clacker,5);
        };
    };
    class UKSF_S_R3: UKSF_S_Empty {
        displayName = "R3 Crate";
        editorPreview = QPATHTOEF(common,data\previews\UKSF_S_R3.jpg);
        hiddenSelectionsTextures[] = { QPATHTOF(data\R3_co.paa) };
        class TransportMagazines {
            MACRO_ADDMAGAZINE(UK3CB_BAF_127_100Rnd,10);
            MACRO_ADDMAGAZINE(UK3CB_BAF_32Rnd_40mm_G_Box,10);
            MACRO_ADDMAGAZINE(UK3CB_BAF_762_200Rnd_T,10);
            MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_60mm_Mo_Shells,20);
            MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_60mm_Mo_Smoke_White,10);
            MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_60mm_Mo_Flare_White,10);
            MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_60mm_Mo_AB_Shells,10);
        };
    };
    class UKSF_S_R4: UKSF_S_Empty {
        displayName = "R4 Crate";
        editorPreview = QPATHTOEF(common,data\previews\UKSF_S_R4.jpg);
        hiddenSelectionsTextures[] = { QPATHTOF(data\R4_co.paa) };
        class TransportMagazines {
            MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_60mm_Mo_Shells,60);
            MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_60mm_Mo_Smoke_White,20);
            MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_60mm_Mo_Flare_White,40);
            MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_60mm_Mo_AB_Shells,30);
        };
        class TransportWeapons {
            MACRO_ADDWEAPON(UK3CB_BAF_M6,2);
        };
    };
    class UKSF_S_R5: UKSF_S_Empty {
        displayName = "R5 Crate";
        disableInventory = 1;
        editorPreview = QPATHTOEF(common,data\previews\UKSF_S_R5.jpg);
        hiddenSelectionsTextures[] = { QPATHTOF(data\R5_co.paa) };
        class ACE_Cargo {
            class Cargo {
                class UKSF_S_MedicalBox {
                    type = "UKSF_S_MedicalBox";
                    amount = 1;
                };
            };
        };
    };
    class UKSF_S_R6: UKSF_S_Empty {
        displayName = "R6 Crate";
        editorPreview = QPATHTOEF(common,data\previews\UKSF_S_R6.jpg);
        hiddenSelectionsTextures[] = { QPATHTOF(data\R6_co.paa) };
        class TransportMagazines {
            MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_81mm_Mo_Shells,50);
            MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_81mm_Mo_Smoke_White,15);
            MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_81mm_Mo_Flare_White,15);
            MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_81mm_Mo_AB_Shells,30);
        };
        class TransportWeapons {
            MACRO_ADDWEAPON(UK3CB_BAF_L16,2);
            MACRO_ADDWEAPON(UK3CB_BAF_L16_Tripod,2);
        };
    };
    class UKSF_S_RT: UKSF_S_Empty {
        displayName = "RT Crate";
        editorPreview = QPATHTOEF(common,data\previews\UKSF_S_RT.jpg);
        hiddenSelectionsTextures[] = { QPATHTOF(data\RT_co.paa) };
        class TransportItems {
            MACRO_ADDITEM(ToolKit,1);
        };
        class ACE_Cargo {
            class Cargo {
                class ACE_Wheel {
                    type = "ACE_Wheel";
                    amount = 6;
                };
            };
        };
    };

    class ACE_medicalSupplyCrate;
    class UKSF_S_MedicalBox: ACE_medicalSupplyCrate {
        scope = 2;
        scopeCurator = 2;
        faction = "CUP_B_GB";
        displayName = "Medical Box";
        editorPreview = QPATHTOEF(common,data\previews\UKSF_S_MedicalBox.jpg);
        editorCategory = "EdCat_Supplies";
        editorSubcategory = QEGVAR(common,resupply);
        class TransportItems {
            MACRO_ADDITEM(ACE_elasticBandage,150);
            MACRO_ADDITEM(ACE_morphine,30);
            MACRO_ADDITEM(ACE_epinephrine,30);
            MACRO_ADDITEM(ACE_bloodIV,30);
            MACRO_ADDITEM(ACE_bloodIV_500,30);
        };
    };

    class CargoNet_01_base_F;
    class CargoNet_01_barrels_F: CargoNet_01_base_F {
        scope = 2;
        scopeCurator = 2;
        faction = "CUP_B_GB";
        displayName = "RF (Fuel Barrels)";
        editorCategory = "EdCat_Supplies";
        editorSubcategory = QEGVAR(common,resupply);
        editorPreview = QPATHTOEF(common,data\previews\CargoNet_01_barrels_F.jpg);
        ace_refuel_fuelCapacity = 800;
        ace_refuel_fuelCargo = 800;
        ace_refuel_flowRate = 2;
        ace_cargo_hasCargo = 0;
        ace_refuel_hooks[] = {{0.498,0.27,0.485}};
        armor = 50;
        fuelExplosionPower = 2;
        destrType = "DestructBuilding";
        explosionEffect = "FuelExplosion";
        class DestructionEffects {
            class Light1 {
                simulation = "light";
                type = "ObjectDestructionLightFuel";
                position = "destructionEffect1";
                intensity = 1;
                interval = 1;
                lifeTime = 0;
            };
            class Smoke1 {
                simulation = "particles";
                type = "FuelTruck_Explosion";
                position = "destructionEffect1";
                intensity = 1;
                interval = 1;
                lifeTime = 0.001;
            };
            class LightFlames1 {
                simulation = "particles";
                type = "FlameLightBC";
                position = "destructionEffect1";
                intensity = 1;
                interval = 1;
                lifeTime = 0.5;
                enabled = "distToWater";
            };
            class LightBig1 {
                simulation = "light";
                type = "ObjectDestructionLight";
                position = "destructionEffect1";
                intensity = 1;
                interval = 1;
                lifeTime = 2;
                enabled = "distToWater";
            };
            class Sound {
                simulation = "sound";
                position = "destructionEffect1";
                intensity = 1;
                interval = 1;
                lifeTime = 1;
                type = "Fire";
            };
            class FireBig1 {
                simulation = "particles";
                type = "ObjectDestructionFire1";
                position = "destructionEffect1";
                intensity = 0.15;
                interval = 1;
                lifeTime = 3;
            };
            class SmokeBig1 {
                simulation = "particles";
                type = "ObjectDestructionSmoke";
                position = "destructionEffect1";
                intensity = 0.15;
                interval = 1;
                lifeTime = 3.5;
            };
            class SparksBig1 {
                simulation = "particles";
                type = "ObjectDestructionSparks";
                position = "destructionEffect1";
                intensity = 1;
                interval = 1;
                lifeTime = 0;
            };
            class FireSparksBig1 {
                simulation = "particles";
                type = "FireSparks";
                position = "destructionEffect2";
                intensity = 1;
                interval = 1;
                lifeTime = 2.8;
            };
            class FireBig2 {
                simulation = "particles";
                type = "ObjectDestructionFire2";
                position = "destructionEffect2";
                intensity = 0.15;
                interval = 1;
                lifeTime = 3;
            };
            class SmokeBig1_2 {
                simulation = "particles";
                type = "ObjectDestructionSmoke1_2";
                position = "destructionEffect2";
                intensity = 0.15;
                interval = 1;
                lifeTime = 3.5;
            };
            class SmokeBig2 {
                simulation = "particles";
                type = "ObjectDestructionSmoke2";
                position = "destructionEffect2";
                intensity = 1;
                interval = 1;
                lifeTime = 3.2;
            };
        };
    };

    class UKSF_S_Ammo: UKSF_S_R1 {
        scope = 1;
        scopeCurator = 1;
    };
    class UKSF_S_AmmoMedic: UKSF_S_R1 {
        scope = 1;
        scopeCurator = 1;
    };
    class UKSF_S_Medic: UKSF_S_R5 {
        scope = 1;
        scopeCurator = 1;
    };

    class Items_base_F;
    class Land_CanisterFuel_F: Items_base_F {
        scope = 2;
        scopeCurator = 2;
        faction = "CUP_B_GB";
        displayName = "Jerry Can";
        editorCategory = "EdCat_Supplies";
        editorSubcategory = QEGVAR(common,resupply);
        editorPreview = QPATHTOEF(common,data\previews\Land_CanisterFuel_F.jpg);
        ace_dragging_canCarry = 1;
        ace_dragging_carryPosition[] = {0, 1, 1};
        ace_dragging_carryDirection = 0;
    };
    class Misc_thing;
    class Fuel_can: Misc_thing {
        editorPreview = QPATHTOEF(common,data\previews\Land_CanisterFuel_F.jpg);
        ace_dragging_canCarry = 1;
        ace_dragging_carryPosition[] = {0, 1, 1};
        ace_dragging_carryDirection = 0;
        class ace_refuel {
            init = QUOTE(call ace_refuel_fnc_makeJerryCan);
        };
    };

    class ACE_RepairItem_Base;
    class ACE_Track: ACE_RepairItem_Base {
        editorCategory = "EdCat_Supplies";
        editorSubcategory = QEGVAR(common,resupply);
    };
    class ACE_Wheel: ACE_RepairItem_Base {
        editorCategory = "EdCat_Supplies";
        editorSubcategory = QEGVAR(common,resupply);
    };
};
