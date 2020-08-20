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
        displayName = "R1 (AM) Crate";
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
        displayName = "R2 (AT) Crate";
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
        displayName = "R3 (AH) Crate";
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
        displayName = "R4 (AMo) Crate";
        editorPreview = QPATHTOEF(common,data\previews\UKSF_S_R4.jpg);
        hiddenSelectionsTextures[] = { QPATHTOF(data\R4_co.paa) };
        class TransportMagazines {
            MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_60mm_Mo_Shells,60);
            MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_60mm_Mo_AB_Shells,25);
            MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_60mm_Mo_Smoke_White,30);
            MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_60mm_Mo_Flare_White,30);
        };
        class TransportWeapons {
            MACRO_ADDWEAPON(UK3CB_BAF_M6,2);
        };
        class ACE_Cargo {
            class Cargo {
                class UK3CB_BAF_Box_M6_Ammo_Mixed {
                    type = "UK3CB_BAF_Box_M6_Ammo_Mixed";
                    amount = 1;
                };
            };
        };
    };
    class UKSF_S_R5: UKSF_S_Empty {
        displayName = "R5 (MED) Crate";
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
        displayName = "R6 (Mo) Crate";
        editorPreview = QPATHTOEF(common,data\previews\UKSF_S_R6.jpg);
        hiddenSelectionsTextures[] = { QPATHTOF(data\R6_co.paa) };
        class TransportMagazines {
            MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_81mm_Mo_Shells,60);
            // MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_81mm_Mo_AB_Shells,30);
            MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_81mm_Mo_Smoke_White,25);
            MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_81mm_Mo_Flare_White,20);
        };
        class TransportWeapons {
            MACRO_ADDWEAPON(UK3CB_BAF_L16,2);
            MACRO_ADDWEAPON(UK3CB_BAF_L16_Tripod,2);
        };
        class ACE_Cargo {
            class Cargo {
                class UK3CB_BAF_Box_L16_Ammo_Mixed {
                    type = "UK3CB_BAF_Box_L16_Ammo_Mixed";
                    amount = 1;
                };
            };
        };
    };
    class UKSF_S_R7: UKSF_S_Empty {
        displayName = "R7 (Sn) Crate";
        editorPreview = QPATHTOEF(common,data\previews\UKSF_S_R7.jpg);
        hiddenSelectionsTextures[] = { QPATHTOF(data\R7_co.paa) };
        class TransportMagazines {
            MACRO_ADDMAGAZINE(SSQN_5Rnd_127x99_HEIAP,30);
            MACRO_ADDMAGAZINE(SSQN_5Rnd_127x99_HEIAP_Tracer,30);
            MACRO_ADDMAGAZINE(UK3CB_BAF_127_10Rnd_AP,30);
            MACRO_ADDMAGAZINE(UK3CB_BAF_127_10Rnd_T,30);
            MACRO_ADDMAGAZINE(UK3CB_BAF_338_5Rnd,50);
            MACRO_ADDMAGAZINE(UK3CB_BAF_338_5Rnd_Tracer,50);
            MACRO_ADDMAGAZINE(DemoCharge_Remote_Mag,5);
        };
        class TransportWeapons {
            MACRO_ADDWEAPON(SSQN_AW50,5);
            MACRO_ADDWEAPON(UK3CB_BAF_L135A1,5);
            MACRO_ADDWEAPON(UK3CB_BAF_L115A3,5);
            MACRO_ADDWEAPON(UK3CB_BAF_L115A3_Ghillie,5);
        };
        class TransportItems {
            MACRO_ADDITEM(SSQN_FiftyCal_Suppressor,5);
            MACRO_ADDITEM(RKSL_optic_PMII_525,5);
            MACRO_ADDITEM(RKSL_optic_PMII_312,5);
            MACRO_ADDITEM(UK3CB_BAF_Silencer_L115A3,5);
            MACRO_ADDITEM(ACE_SpottingScope,1);
            MACRO_ADDITEM(ACE_Tripod,1);
            MACRO_ADDITEM(ACE_RangeCard,5);
            MACRO_ADDITEM(U_B_FullGhillie_lsh,5);
            MACRO_ADDITEM(U_B_FullGhillie_sard,5);
            MACRO_ADDITEM(U_B_FullGhillie_ard,5);
            MACRO_ADDITEM(U_B_T_FullGhillie_tna_F,5);
            MACRO_ADDITEM(ACE_Sandbag_empty,25);
        };
        class TransportBackpacks {
            MACRO_ADDBACKPACK(UK3CB_BAF_B_Bergen_MTP_Rifleman_XL_A,5);
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
            MACRO_ADDITEM(ACE_packingBandage,150);
            MACRO_ADDITEM(ACE_adenosine,30);
            MACRO_ADDITEM(ACE_morphine,30);
            MACRO_ADDITEM(ACE_epinephrine,30);
            MACRO_ADDITEM(ACE_bloodIV,30);
            MACRO_ADDITEM(ACE_bloodIV_500,30);
            MACRO_ADDITEM(ACE_bloodIV_250,30);
            MACRO_ADDITEM(ACE_splint,30);
            MACRO_ADDITEM(ACE_painkillers,30);
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
                type = "fxp_VEELight";
                intensity = 0.001;
                interval = 1;
                position = "destructionEffect1";
                lifeTime = 20;
                start = "damage-0.99";
                enabled = "distToWater";
            };
            class Sound {
                simulation = "sound";
                type = "Fire";
                position = "destructionEffect1";
                intensity = 1;
                interval = 1;
                lifeTime = 1;
            };
            class FireBig {
                simulation = "particles";
                type = "ObjectDestructionFire1";
                position = "destructionEffect2";
                intensity = 0.15;
                interval = 1;
                lifeTime = 0.1;
            };
            class SmokeDest : FireBig {
                type = "fxp_CarFuelDestructionSmoke";
                lifeTime = 20;
            };
            class ExpFuel : SmokeDest {
                type = "fxp_CarFuelExp";
                position = "destructionEffect1";
                lifeTime = 0.001;
            };
            class Spark : ExpFuel {
                type = "fxp_CarFuelSparks";
                lifeTime = 20;
            };
            class Fire1 : Spark {
                type = "fxp_objectdestructionfire1";
            };
            class Fire2 : Fire1 {
                type = "fxp_objectdestructionfire1a";
            };
            class Fire3 : Fire2 {
                type = "fxp_objectdestructionfire1b";
            };
            class Smok1 : Fire3 {
                type = "ObjectDestructionSmoke1_2Smallx";
            };
            class Smok2 : Smok1 {
                type = "fxp_CarFuelDestSmoke";
            };
            class Refrc : Smok2 {
                type = "ObjectDestructionRefract";
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
