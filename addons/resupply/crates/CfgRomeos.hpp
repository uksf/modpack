class B_supplyCrate_F;
class GVAR(rx) : B_supplyCrate_F {
    author = "UKSF";
    faction = "CUP_B_GB";
    scope = 2;
    scopeCurator = 2;
    editorCategory = "EdCat_Supplies";
    editorSubcategory = QEGVAR(common,romeos);
    displayName = "RX (Empty)";
    description = "Crate - Empty";
    PREVIEW(rx);
    hiddenSelectionsTextures[] = { QPATHTOF(data\romeo\rx.paa) };
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
class GVAR(r1) : GVAR(rx) {
    displayName = "R1 (SA)";
    description = "Crate - Small Arms Ammo";
    PREVIEW(r1);
    hiddenSelectionsTextures[] = { QPATHTOF(data\romeo\r1.paa) };
    class TransportMagazines {
        MACRO_ADDMAGAZINE(UK3CB_BAF_556_30Rnd,80);
        MACRO_ADDMAGAZINE(UK3CB_BAF_556_30Rnd_T,40);
        MACRO_ADDMAGAZINE(UK3CB_BAF_556_200Rnd,20);
        MACRO_ADDMAGAZINE(UK3CB_BAF_762_100Rnd,10);
        MACRO_ADDMAGAZINE(UK3CB_BAF_762_L42A1_20Rnd,20);
        MACRO_ADDMAGAZINE(1Rnd_HE_Grenade_shell,30);
        MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_Smoke_Grenade_shell,20);
        MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_SmokeRed_Grenade_shell,10);
        MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_SmokeGreen_Grenade_shell,10);
        MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_SmokeBlue_Grenade_shell,10);
        MACRO_ADDMAGAZINE(HandGrenade,20);
        MACRO_ADDMAGAZINE(SmokeShell,20);
        MACRO_ADDMAGAZINE(SmokeShellRed,10);
        MACRO_ADDMAGAZINE(SmokeShellBlue,10);
        MACRO_ADDMAGAZINE(SmokeShellGreen,10);
        MACRO_ADDMAGAZINE(SmokeShellPurple,10);
        MACRO_ADDMAGAZINE(ACE_M84,20);
        MACRO_ADDMAGAZINE(UK3CB_BAF_9_17Rnd,10);
    };
    class ACE_Cargo {
        class Cargo {
            MACRO_ADDACECARGO(GVAR(g1),3);
            MACRO_ADDACECARGO(GVAR(g2),1);
        };
    };
};
class GVAR(r2) : GVAR(rx) {
    displayName = "R2 (AT)";
    description = "Crate - Anti-Tank, Demolitions";
    PREVIEW(r2);
    hiddenSelectionsTextures[] = { QPATHTOF(data\romeo\r2.paa) };
    class TransportMagazines {
        MACRO_ADDMAGAZINE(MRAWS_HEAT_F,20);
        MACRO_ADDMAGAZINE(MRAWS_HE_F,5);
        MACRO_ADDMAGAZINE(DemoCharge_Remote_Mag,10);
        MACRO_ADDMAGAZINE(SatchelCharge_Remote_Mag,5);
        MACRO_ADDMAGAZINE(BreachCharge_Remote_Mag,10);
    };
    class TransportWeapons {
        MACRO_ADDWEAPON(UK3CB_BAF_Javelin_Slung_Tube,10);
        MACRO_ADDWEAPON(UK3CB_BAF_AT4_CS_AT_Launcher,10);
        MACRO_ADDWEAPON(UK3CB_BAF_AT4_CS_AP_Launcher,10);
        MACRO_ADDWEAPON(launch_NLAW_F,10);
    };
    class TransportItems {
        MACRO_ADDITEM(UK3CB_BAF_Javelin_CLU,3);
        MACRO_ADDITEM(ACE_Clacker,3);
    };
    class ACE_Cargo {
        class Cargo {
            MACRO_ADDACECARGO(GVAR(g3),3);
            MACRO_ADDACECARGO(GVAR(g4),2);
        };
    };
};
class GVAR(r3) : GVAR(rx) {
    displayName = "R3 (VA)";
    description = "Crate - Vehicle Ammo";
    PREVIEW(r3);
    hiddenSelectionsTextures[] = { QPATHTOF(data\romeo\r3.paa) };
    class TransportMagazines {
        MACRO_ADDMAGAZINE(UK3CB_BAF_127_100Rnd,30);
        MACRO_ADDMAGAZINE(UK3CB_BAF_32Rnd_40mm_G_Box,20);
        MACRO_ADDMAGAZINE(UK3CB_BAF_762_200Rnd,20);
    };
    class ACE_Cargo {
        class Cargo {
            MACRO_ADDACECARGO(GVAR(g5),3);
            MACRO_ADDACECARGO(GVAR(g6),2);
            MACRO_ADDACECARGO(GVAR(g7),2);
        };
    };
};
class GVAR(r4) : GVAR(rx) {
    displayName = "R4 (ME)";
    description = "Crate - Medical";
    PREVIEW(r4);
    hiddenSelectionsTextures[] = { QPATHTOF(data\romeo\r4.paa) };
    disableInventory = 1;
    class ACE_Cargo {
        class Cargo {
            MACRO_ADDACECARGO(GVAR(g14),1);
        };
    };
};
class GVAR(r5) : GVAR(rx) {
    displayName = "R5 (LM)";
    description = "Crate - Light Mortar";
    PREVIEW(r5);
    hiddenSelectionsTextures[] = { QPATHTOF(data\romeo\r5.paa) };
    class TransportWeapons {
        MACRO_ADDWEAPON(UK3CB_BAF_M6,1);
    };
    class ACE_Cargo {
        class Cargo {
            MACRO_ADDACECARGO(GVAR(g8),4);
            MACRO_ADDACECARGO(GVAR(g9),2);
        };
    };
};
class GVAR(r6) : GVAR(rx) {
    displayName = "R6 (MM)";
    description = "Crate - Medium Mortar";
    PREVIEW(r6);
    hiddenSelectionsTextures[] = { QPATHTOF(data\romeo\r6.paa) };
    class TransportMagazines {
        MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_81mm_Mo_Flare_White,20);
    };
    class TransportWeapons {
        MACRO_ADDWEAPON(UK3CB_BAF_L16,1);
        MACRO_ADDWEAPON(UK3CB_BAF_L16_Tripod,1);
    };
    class ACE_Cargo {
        class Cargo {
            MACRO_ADDACECARGO(GVAR(g10),8);
            MACRO_ADDACECARGO(GVAR(g11),2);
        };
    };
};
class GVAR(r7) : GVAR(rx) {
    displayName = "R7 (Sniper)";
    description = "Crate - Sniper Ammo";
    PREVIEW(r7);
    hiddenSelectionsTextures[] = { QPATHTOF(data\romeo\r7.paa) };
    class TransportMagazines {
        MACRO_ADDMAGAZINE(SSQN_5Rnd_127x99_HEIAP,30);
        MACRO_ADDMAGAZINE(SSQN_5Rnd_127x99_HEIAP_Tracer,30);
        MACRO_ADDMAGAZINE(UK3CB_BAF_127_10Rnd_AP,30);
        MACRO_ADDMAGAZINE(UK3CB_BAF_127_10Rnd_T,30);
        MACRO_ADDMAGAZINE(UK3CB_BAF_338_5Rnd,30);
        MACRO_ADDMAGAZINE(UK3CB_BAF_338_5Rnd_Tracer,30);
    };
    class ACE_Cargo {
        class Cargo {
            MACRO_ADDACECARGO(GVAR(g12),2);
            MACRO_ADDACECARGO(GVAR(g13),1);
        };
    };
};
class GVAR(rt) : GVAR(rx) {
    displayName = "RT (Tyres)";
    description = "Crate - Tyres, Toolkits";
    PREVIEW(rt);
    hiddenSelectionsTextures[] = { QPATHTOF(data\romeo\rt.paa) };
    class TransportItems {
        MACRO_ADDITEM(ToolKit,2);
    };
    class ACE_Cargo {
        class Cargo {
            class ACE_Wheel {
                type = "ACE_Wheel";
                amount = 10;
            };
        };
    };
};
class GVAR(rb) : GVAR(rx) {
    displayName = "RB (ReBro)";
    description = "Crate - Re-broadcasting Station";
    PREVIEW(rx); // TODO
    hiddenSelectionsTextures[] = { QPATHTOF(data\romeo\rb.paa) };
    class ACE_Cargo {
        class Cargo {
            MACRO_ADDACECARGO(EGVAR(radios,rebroStationBox),1);
        };
    };
};

class CargoNet_01_barrels_F;
class GVAR(rf) : CargoNet_01_barrels_F {
    scope = 2;
    scopeCurator = 2;
    faction = "CUP_B_GB";
    displayName = "RF (Fuel)";
    description = "Fuel Barrels";
    editorCategory = "EdCat_Supplies";
    editorSubcategory = QEGVAR(common,romeos);
    PREVIEW(rf);
    disableInventory = 1;
    ace_refuel_fuelCapacity = 800;
    ace_refuel_fuelCargo = 800;
    ace_refuel_flowRate = 2;
    ace_cargo_hasCargo = 0;
    ace_refuel_hooks[] = { { 0.498, 0.27, 0.485 } };
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
