class CfgVehicles {
    class O_Soldier_VR_F;
    class UKSF_O_Rifleman: O_Soldier_VR_F {  
        scope = 2;
        scopeCurator = 2;
        author = "UKSF";
        faction = "UKSF_VR";
        displayName = "VR Rifleman";
        role = "Rifleman";
        editorPreview = QPATHTOEF(common,data\previews\UKSF_O_Rifleman.jpg);
        hiddenSelections[] = { "Camo_arm_left", "Camo_arm_right", "Camo_body", "Camo_head", "Camo_leg_left", "Camo_leg_right" };
        hiddenSelectionsTextures[] = { "#(argb,8,8,3)color(0.85,0.05,0.05,1,ca)", "#(argb,8,8,3)color(0.85,0.05,0.05,1,ca)", "#(argb,8,8,3)color(0.85,0.05,0.05,1,ca)", "#(argb,8,8,3)color(0.85,0.05,0.05,1,ca)", "#(argb,8,8,3)color(0.85,0.05,0.05,1,ca)", "#(argb,8,8,3)color(0.85,0.05,0.05,1,ca)" };
        hiddenSelectionsMaterials[] = { QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\alive.rvmat) };
        uniformClass = "UKSF_U_VR";
        modelSides[] = {3, 0};
        weapons[] = { "CUP_arifle_M4A1_Acog","Throw","Put" };
        respawnWeapons[] = { "CUP_arifle_M4A1_Acog","Throw","Put" };
        magazines[] = { "30Rnd_556x45_Stanag" };
        respawnMagazines[] = { "30Rnd_556x45_Stanag" };
        items[] = {};
        respawnItems[] = {};
        linkedItems[] = { "ItemMap","ItemCompass","ItemWatch" };
        respawnLinkedItems[] = { "ItemMap","ItemCompass","ItemWatch" };
        class HitPoints {
            class HitFace {
                armor = 2;
                material = -1;
                name = "face_hub";
                passThrough = 0.1;
                radius = 0.08;
                explosionShielding = 0.1;
                minimalHit = 0.01;
            };
            class HitNeck: HitFace {
                armor = 2;
                material = -1;
                name = "neck";
                passThrough = 0.1;
                radius = 0.1;
                explosionShielding = 0.5;
                minimalHit = 0.01;
            };
            class HitHead: HitNeck {
                armor = 5;
                material = -1;
                name = "head";
                passThrough = 0.1;
                radius = 0.2;
                explosionShielding = 0.5;
                visual = "camo_head";
                minimalHit = 0.01;
                depends = "HitFace max HitNeck";
            };
            class HitPelvis {
                armor = 15;
                material = -1;
                name = "pelvis";
                passThrough = 0.1;
                radius = 0.2;
                explosionShielding = 1;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitAbdomen: HitPelvis {
                armor = 15;
                material = -1;
                name = "spine1";
                passThrough = 0.1;
                radius = 0.15;
                explosionShielding = 1;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitDiaphragm: HitAbdomen {
                armor = 15;
                material = -1;
                name = "spine2";
                passThrough = 0.1;
                radius = 0.15;
                explosionShielding = 6;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitChest: HitDiaphragm {
                armor = 10;
                material = -1;
                name = "spine3";
                passThrough = 0.1;
                radius = 0.15;
                explosionShielding = 6;
                visual = "injury_body";
                minimalHit = 0.01;
            };
            class HitBody: HitChest {
                armor = 1000;
                material = -1;
                name = "body";
                passThrough = 0.1;
                radius = 0.16;
                explosionShielding = 6;
                visual = "camo_body";
                minimalHit = 0.01;
                depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
            };
            class hand_l {
                armor = 10;
                material = -1;
                name = "hand_l";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 1;
                visual = "Camo_arm_left";
                minimalHit = 0.01;
            };
            class hand_r {
                armor = 10;
                material = -1;
                name = "hand_r";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 1;
                visual = "Camo_arm_right";
                minimalHit = 0.01;
            };
            class HitArms {
                armor = 10;
                material = -1;
                name = "arms";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 1;
                visual = "injury_hands";
                minimalHit = 0.01;
            };
            class HitHands: HitArms {
                armor = 10;
                material = -1;
                name = "hands";
                passThrough = 1;
                radius = 0.1;
                explosionShielding = 1;
                visual = "injury_hands";
                minimalHit = 0.01;
                depends = "HitArms";
            };
            class leg_l {
                armor = 10;
                material = -1;
                name = "leg_l";
                passThrough = 1;
                radius = 0.12;
                explosionShielding = 1;
                visual = "Camo_leg_left";
                minimalHit = 0.01;
            };
            class leg_r {
                armor = 10;
                material = -1;
                name = "leg_r";
                passThrough = 1;
                radius = 0.12;
                explosionShielding = 1;
                visual = "Camo_leg_right";
                minimalHit = 0.01;
            };
            class HitLegs {
                armor = 10;
                material = -1;
                name = "legs";
                passThrough = 1;
                radius = 0.12;
                explosionShielding = 1;
                visual = "injury_legs";
                minimalHit = 0.01;
            };
        };
        armor = 5;
        armorStructural = 0.5;
        explosionShielding = 0.2;
    };
    class UKSF_O_MG: UKSF_O_Rifleman {
        displayName = "VR Machinegunner";
        editorPreview = QPATHTOEF(common,data\previews\UKSF_O_MG.jpg);
        weapons[] = { "CUP_lmg_M240_LDS","Throw","Put" };
        respawnWeapons[] = { "CUP_lmg_M240_LDS","Throw","Put" };
        magazines[] = { "CUP_100Rnd_TE4_LRT4_White_Tracer_762x51_Belt_M" };
        respawnMagazines[] = { "CUP_100Rnd_TE4_LRT4_White_Tracer_762x51_Belt_M" };
    };
    class UKSF_O_AT: UKSF_O_Rifleman {
        displayName = "VR AT Specialist";
        editorPreview = QPATHTOEF(common,data\previews\UKSF_O_AT.jpg);
        backpack = "B_AssaultPack_VR_AT";
        weapons[] = { "CUP_arifle_M4A1_Acog","CUP_launch_Mk153Mod0","Throw","Put" };
        respawnWeapons[] = { "CUP_arifle_M4A1_Acog","CUP_launch_Mk153Mod0","Throw","Put" };
        magazines[] = { "30Rnd_556x45_Stanag" };
        respawnMagazines[] = { "30Rnd_556x45_Stanag" };
    };
    class UKSF_O_AA: UKSF_O_Rifleman {
        displayName = "VR AA Specialist";
        editorPreview = QPATHTOEF(common,data\previews\UKSF_O_AA.jpg);
        backpack = "B_AssaultPack_VR_AA";
        weapons[] = { "CUP_arifle_M4A1_Acog","CUP_launch_FIM92Stinger_Rubber","Throw","Put" };
        respawnWeapons[] = { "CUP_arifle_M4A1_Acog","CUP_launch_FIM92Stinger_Rubber","Throw","Put" };
        magazines[] = { "30Rnd_556x45_Stanag" };
        respawnMagazines[] = { "30Rnd_556x45_Stanag" };
    };

    class CUP_B_HMMWV_M2_USA;
    class UKSF_O_HMMWV_M2_VR_Rubber: CUP_B_HMMWV_M2_USA {
        author = "UKSF";
        side = 0;
        faction = "UKSF_VR";
        displayName = "VR HMMWV M2";
        editorPreview = QPATHTOEF(common,data\previews\UKSF_O_HMMWV_M2_VR_Rubber.jpg);
        crew = "UKSF_O_Rifleman";
        typicalCargo[] = { "UKSF_O_Rifleman", "UKSF_O_Rifleman", "UKSF_O_Rifleman", "UKSF_O_Rifleman" };
        hiddenSelectionsTextures[] = { "#(argb,8,8,3)color(0.85,0.05,0.05,1,ca)" };
        hiddenSelectionsMaterials[] = { QPATHTO_R(data\alive.rvmat) };
        class Damage {
            tex[] = {};
            mat[] = {
                QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\damage.rvmat), QPATHTO_R(data\dead.rvmat), 
                QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\damage.rvmat), QPATHTO_R(data\dead.rvmat), 
                QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\damage.rvmat), QPATHTO_R(data\dead.rvmat), 
                QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\damage.rvmat), QPATHTO_R(data\dead.rvmat), 
                QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\damage.rvmat), QPATHTO_R(data\dead.rvmat), 
                QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\damage.rvmat), QPATHTO_R(data\dead.rvmat), 
                QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\damage.rvmat), QPATHTO_R(data\dead.rvmat), 
                QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\damage.rvmat), QPATHTO_R(data\dead.rvmat), 
                QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\damage.rvmat), QPATHTO_R(data\dead.rvmat), 
                QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\damage.rvmat), QPATHTO_R(data\dead.rvmat), 
                QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\damage.rvmat), QPATHTO_R(data\dead.rvmat),
                QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\damage.rvmat), QPATHTO_R(data\dead.rvmat), 
                QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\damage.rvmat), QPATHTO_R(data\dead.rvmat), 
                QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\damage.rvmat), QPATHTO_R(data\dead.rvmat)
            };
        };
    };

    class CUP_B_M1A2_TUSK_MG_DES_US_Army;
    class UKSF_O_M1A2_TUSK_MG_VR_Rubber: CUP_B_M1A2_TUSK_MG_DES_US_Army {
        author = "UKSF";
        side = 0;
        faction = "UKSF_VR";
        displayName = "VR M1A2 Abrams TUSK";
        editorPreview = QPATHTOEF(common,data\previews\UKSF_O_M1A2_TUSK_MG_VR_Rubber.jpg);
        crew = "UKSF_O_Rifleman";
        typicalCargo[] = { "UKSF_O_Rifleman", "UKSF_O_Rifleman", "UKSF_O_Rifleman", "UKSF_O_Rifleman" };
        hiddenSelectionsTextures[] = { "#(argb,8,8,3)color(0.85,0.05,0.05,1,ca)", "#(argb,8,8,3)color(0.85,0.05,0.05,1,ca)", "#(argb,8,8,3)color(0.85,0.05,0.05,1,ca)", "#(argb,8,8,3)color(0.85,0.05,0.05,1,ca)" };
        hiddenSelectionsMaterials[] = { QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\alive.rvmat) };
        class Damage {
            tex[] = {};
            mat[] = { 
                QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\damage.rvmat), QPATHTO_R(data\dead.rvmat), 
                QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\damage.rvmat), QPATHTO_R(data\dead.rvmat), 
                QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\damage.rvmat), QPATHTO_R(data\dead.rvmat), 
                QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\damage.rvmat), QPATHTO_R(data\dead.rvmat), 
                QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\damage.rvmat), QPATHTO_R(data\dead.rvmat), 
                QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\damage.rvmat), QPATHTO_R(data\dead.rvmat)
            };
        };
    };

    class CUP_M2Bradley_Base;
    class CUP_B_M2Bradley_USA_D: CUP_M2Bradley_Base {
        class Turrets;
    };
    class CUP_B_M6LineBacker_USA_D: CUP_B_M2Bradley_USA_D {
        class Turrets: Turrets {
            class Mainturret;
        };
    };
    class UKSF_O_M6LineBacker_VR_Rubber: CUP_B_M6LineBacker_USA_D {
        author = "UKSF";
        side = 0;
        faction = "UKSF_VR";
        displayName = "VR M6 Linebacker";
        editorPreview = QPATHTOEF(common,data\previews\UKSF_O_M6LineBacker_VR_Rubber.jpg);
        crew = "UKSF_O_Rifleman";
        hiddenSelectionsTextures[] = { "#(argb,8,8,3)color(0.85,0.05,0.05,1,ca)", "#(argb,8,8,3)color(0.85,0.05,0.05,1,ca)", "#(argb,8,8,3)color(0.85,0.05,0.05,1,ca)" };
        hiddenSelectionsMaterials[] = { QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\alive.rvmat) };
        class Damage {
            tex[] = {};
            mat[] = { 
                QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\damage.rvmat), QPATHTO_R(data\dead.rvmat), 
                QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\damage.rvmat), QPATHTO_R(data\dead.rvmat), 
                QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\damage.rvmat), QPATHTO_R(data\dead.rvmat), 
                QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\damage.rvmat), QPATHTO_R(data\dead.rvmat), 
                QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\damage.rvmat), QPATHTO_R(data\dead.rvmat), 
                QPATHTO_R(data\alive.rvmat), QPATHTO_R(data\damage.rvmat), QPATHTO_R(data\dead.rvmat)
            };
        };
        class Turrets: Turrets {
            class Mainturret: MainTurret {
                weapons[] = { "CUP_Vacannon_M242_veh", "CUP_Vlmg_M240_veh", "CUP_Vmlauncher_Stinger_vehicle_veh_Rubber" };
                magazines[] = { "CUP_210Rnd_TE1_Red_Tracer_25mm_M242_HE", "CUP_210Rnd_TE1_Red_Tracer_25mm_M242_APFSDS", "CUP_1200Rnd_TE4_Red_Tracer_762x51_M240_M", "CUP_4Rnd_Stinger_M_Rubber" };
            };
        };
    };
};
