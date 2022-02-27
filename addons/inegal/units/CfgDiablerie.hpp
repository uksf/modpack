class Inegal_Diablerie_S : Inegal_Soldier_Base {
    scope = 2;
    displayName = "Specialist";
    editorSubcategory = QEGVAR(common,diablerie);
    editorPreview = QPATHTOEF(common,data\previews\Inegal_Diablerie_S.jpg);
    uniformClass = "U_B_CTRG_Soldier_F";
    backpack = "Inegal_B_D_Specialist";
    weapons[] = {
        "arifle_SPAR_01_blk_F_erco_laser_bipod_suppressor",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "arifle_SPAR_01_blk_F_erco_laser_bipod_suppressor",
        "Throw",
        "Put"
    };
    magazines[] = {
        "ACE_M84",
        "ACE_M84",
        "ACE_M84",
        "ACE_M84",
        "SmokeShell",
        "SmokeShell",
        "SmokeShellBlue",
        "SmokeShellBlue",
        "SmokeShellRed",
        "SmokeShellRed",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade"
    };
    respawnMagazines[] = {
        "ACE_M84",
        "ACE_M84",
        "ACE_M84",
        "ACE_M84",
        "SmokeShell",
        "SmokeShell",
        "SmokeShellBlue",
        "SmokeShellBlue",
        "SmokeShellRed",
        "SmokeShellRed",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade"
    };
    items[] = {
        "ACE_EarPlugs",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_morphine",
        "ACE_morphine",
        "ACE_morphine",
        "ACE_morphine",
        "ACE_tourniquet",
        "ACE_tourniquet"
    };
    respawnItems[] = {
        "ACE_EarPlugs",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_morphine",
        "ACE_morphine",
        "ACE_morphine",
        "ACE_morphine",
        "ACE_tourniquet",
        "ACE_tourniquet"
    };
    linkedItems[] = {
        "Inegal_Diablerie_Helmet",
        "Inegal_Diablerie_Vest",
        "NVGogglesB_grn_F",
        "G_Balaclava_TI_G_tna_F",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    respawnLinkedItems[] = {
        "H_HelmeInegal_Diablerie_HelmettSpecB",
        "Inegal_Diablerie_Vest",
        "NVGogglesB_grn_F",
        "G_Balaclava_TI_G_tna_F",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    class HitPoints {
        class HitFace {
            armor = 1;
            material = -1;
            name = "face_hub";
            passThrough = 0.8;
            radius = 0.08;
            explosionShielding = 0.1;
            minimalHit = 0.01;
        };
        class HitNeck : HitFace {
            armor = 6;
            material = -1;
            name = "neck";
            passThrough = 0.8;
            radius = 0.1;
            explosionShielding = 0.5;
            minimalHit = 0.01;
        };
        class HitHead : HitNeck {
            armor = 1;
            material = -1;
            name = "head";
            passThrough = 0.8;
            radius = 0.2;
            explosionShielding = 0.5;
            minimalHit = 0.01;
            depends = "HitFace max HitNeck";
        };
        class HitPelvis : HitHead {
            armor = 8;
            material = -1;
            name = "pelvis";
            passThrough = 0.33;
            radius = 0.24;
            explosionShielding = 1;
            visual = "injury_body";
            minimalHit = 0.01;
            depends = "0";
        };
        class HitAbdomen : HitPelvis {
            armor = 8;
            material = -1;
            name = "spine1";
            passThrough = 0.33;
            radius = 0.16;
            explosionShielding = 1;
            visual = "injury_body";
            minimalHit = 0.01;
        };
        class HitDiaphragm : HitAbdomen {
            armor = 8;
            material = -1;
            name = "spine2";
            passThrough = 0.33;
            radius = 0.18;
            explosionShielding = 1.5;
            visual = "injury_body";
            minimalHit = 0.01;
        };
        class HitChest : HitDiaphragm {
            armor = 8;
            material = -1;
            name = "spine3";
            passThrough = 0.33;
            radius = 0.18;
            explosionShielding = 1.5;
            visual = "injury_body";
            minimalHit = 0.01;
        };
        class HitBody : HitChest {
            armor = 1000;
            material = -1;
            name = "body";
            passThrough = 1;
            radius = 0;
            explosionShielding = 1.5;
            visual = "injury_body";
            minimalHit = 0.01;
            depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
        };
        class HitArms : HitBody {
            armor = 8;
            material = -1;
            name = "arms";
            passThrough = 0.7;
            radius = 0.1;
            explosionShielding = 0.1;
            visual = "injury_hands";
            minimalHit = 0.01;
            depends = "0";
        };
        class HitHands : HitArms {
            armor = 8;
            material = -1;
            name = "hands";
            passThrough = 0.7;
            radius = 0.1;
            explosionShielding = 0.1;
            visual = "injury_hands";
            minimalHit = 0.01;
            depends = "HitArms";
        };
        class HitLegs : HitHands {
            armor = 8;
            material = -1;
            name = "legs";
            passThrough = 0.7;
            radius = 0.14;
            explosionShielding = 0.1;
            visual = "injury_legs";
            minimalHit = 0.01;
            depends = "0";
        };
        class Incapacitated : HitLegs {
            armor = 1000;
            material = -1;
            name = "body";
            passThrough = 1;
            radius = 0;
            explosionShielding = 1;
            visual = "";
            minimalHit = 0;
            depends = "(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 1.45";
        };
        class HitLeftArm {
            armor = 3;
            material = -1;
            name = "hand_l";
            passThrough = 1;
            radius = 0.08;
            explosionShielding = 1;
            visual = "injury_hands";
            minimalHit = 0.01;
        };
        class HitRightArm : HitLeftArm {
            name = "hand_r";
        };
        class HitLeftLeg {
            armor = 3;
            material = -1;
            name = "leg_l";
            passThrough = 1;
            radius = 0.1;
            explosionShielding = 1;
            visual = "injury_legs";
            minimalHit = 0.01;
        };
        class HitRightLeg : HitLeftLeg {
            name = "leg_r";
        };
        class ACE_HDBracket {
            armor = 1;
            material = -1;
            name = "head";
            passThrough = 0;
            radius = 1;
            explosionShielding = 1;
            visual = "";
            minimalHit = 0;
            depends = "HitHead";
        };
    };
    armor = 2;
    armorStructural = 4;
    explosionShielding = 0.4;
};
class Inegal_Diablerie_C : Inegal_Diablerie_S {
    displayName = "Commander";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_Diablerie_C.jpg);
    icon = "iconManLeader";
    backpack = "Inegal_B_D_Commander";
    weapons[] = {
        "arifle_SPAR_01_GL_blk_F_erco_laser_suppressor",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "arifle_SPAR_01_GL_blk_F_erco_laser_suppressor",
        "Throw",
        "Put"
    };
};
class Inegal_Diablerie_G : Inegal_Diablerie_S {
    displayName = "General";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_Diablerie_G.jpg);
    icon = "iconManOfficer";
    backpack = "Inegal_B_D_Commander";
    weapons[] = {
        "arifle_SPAR_01_GL_blk_F_erco_laser_suppressor",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "arifle_SPAR_01_GL_blk_F_erco_laser_suppressor",
        "Throw",
        "Put"
    };
    items[] = {
        "ACE_EarPlugs",
        "ACE_Banana",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_morphine",
        "ACE_morphine",
        "ACE_morphine",
        "ACE_morphine",
        "ACE_tourniquet",
        "ACE_tourniquet"
    };
    respawnItems[] = {
        "ACE_EarPlugs",
        "ACE_Banana",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_morphine",
        "ACE_morphine",
        "ACE_morphine",
        "ACE_morphine",
        "ACE_tourniquet",
        "ACE_tourniquet"
    };
    linkedItems[] = {
        "Inegal_Diablerie_Helmet",
        "Inegal_Diablerie_Vest",
        "NVGogglesB_grn_F",
        "G_Bandanna_beast",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    respawnLinkedItems[] = {
        "H_HelmeInegal_Diablerie_HelmettSpecB",
        "Inegal_Diablerie_Vest",
        "NVGogglesB_grn_F",
        "G_Bandanna_beast",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
};
class Inegal_Diablerie_Su : Inegal_Diablerie_S {
    displayName = "Surgeon";
    icon = "iconManMedic";
    attendant = 1;
    editorPreview = QPATHTOEF(common,data\previews\Inegal_Diablerie_Su.jpg);
    picture = "pictureHeal";
    backpack = "Inegal_B_D_Surgeon";
};
class Inegal_Diablerie_B : Inegal_Diablerie_S {
    displayName = "Brute";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_Diablerie_B.jpg);
    icon = "iconManMG";
    backpack = "Inegal_B_D_Brute";
    weapons[] = {
        "CUP_lmg_Mk48_des_Aimpoint",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "CUP_lmg_Mk48_des_Aimpoint",
        "Throw",
        "Put"
    };
};
class Inegal_Diablerie_Sh : Inegal_Diablerie_S {
    displayName = "Sharpshooter";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_Diablerie_Sh.jpg);
    backpack = "Inegal_B_D_Sharpshooter";
    weapons[] = {
        "arifle_SPAR_03_blk_F_dms_bipod_suppressor_laser",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "arifle_SPAR_03_blk_F_dms_bipod_suppressor_laser",
        "Throw",
        "Put"
    };
};
class Inegal_Diablerie_A : Inegal_Diablerie_S {
    displayName = "Arsonist";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_Diablerie_A.jpg);
    icon = "iconManAT";
    threat[] = { 1, 0.9, 0.9 };
    backpack = "Inegal_B_D_Arsonist";
    weapons[] = {
        "arifle_SPAR_01_blk_F_erco_laser_bipod_suppressor",
        "CUP_launch_MAAWS_Scope",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "arifle_SPAR_01_blk_F_erco_laser_bipod_suppressor",
        "CUP_launch_MAAWS_Scope",
        "Throw",
        "Put"
    };
};
class Inegal_Diablerie_Se : Inegal_Diablerie_S {
    displayName = "Sentinel";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_Diablerie_Se.jpg);
    backpack = "Inegal_B_D_Sentinel";
};
class Inegal_Diablerie_As : Inegal_Diablerie_S {
    displayName = "Assassin";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_Diablerie_As.jpg);
    uniformClass = "U_I_FullGhillie_sard";
    backpack = "Inegal_B_D_Assassin";
    weapons[] = {
        "CUP_srifle_M107_Base_PMII",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "CUP_srifle_M107_Base_PMII",
        "Throw",
        "Put"
    };
    magazines[] = {
        "SmokeShellRed",
        "SmokeShellRed",
        "SmokeShell",
        "SmokeShell",
        "SmokeShellBlue",
        "SmokeShellBlue",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade"
    };
    respawnMagazines[] = {
        "SmokeShellRed",
        "SmokeShellRed",
        "SmokeShell",
        "SmokeShell",
        "SmokeShellBlue",
        "SmokeShellBlue",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade"
    };
    linkedItems[] = {
        "H_HelmetSpecB",
        "Inegal_Diablerie_Vest",
        "NVGogglesB_grn_F",
        "G_Bandanna_beast",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    respawnLinkedItems[] = {
        "H_HelmetSpecB",
        "Inegal_Diablerie_Vest",
        "NVGogglesB_grn_F",
        "G_Bandanna_beast",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
};
