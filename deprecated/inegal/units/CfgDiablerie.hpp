class Inegal_Diablerie_S: Inegal_Soldier_Base {
    _generalMacro = "Inegal_Mortel_R";
    scope = 2;
    displayName = "Specialist";
    editorSubcategory = QEGVAR(common,diablerie);
    editorPreview = QPATHTOEF(common,data\previews\Inegal_Diablerie_S.jpg);
    uniformClass = "SP_0000_Standard_FieldUniform_ATacsFG";
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
        "SP_Modular2_Tan",
        "NVGogglesB_blk_F",
        "G_Balaclava_TI_G_tna_F",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    respawnLinkedItems[] = {
        "H_HelmeInegal_Diablerie_HelmettSpecB",
        "SP_Modular2_Tan",
        "NVGogglesB_blk_F",
        "G_Balaclava_TI_G_tna_F",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
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
            armor = 4;
            material = -1;
            name = "neck";
            passThrough = 0.1;
            radius = 0.1;
            explosionShielding = 0.5;
            minimalHit = 0.01;
        };
        class HitHead: HitNeck {
            armor = 3;
            material = -1;
            name = "head";
            passThrough = 0.1;
            radius = 0.2;
            explosionShielding = 0.5;
            minimalHit = 0.01;
            depends = "HitFace max HitNeck";
        };
        class HitPelvis {
            armor = 8;
            material = -1;
            name = "pelvis";
            passThrough = 0.04;
            radius = 0.2;
            explosionShielding = 1;
            visual = "injury_body";
            minimalHit = 0.01;
        };
        class HitAbdomen: HitPelvis {
            armor = 8;
            material = -1;
            name = "spine1";
            passThrough = 0.04;
            radius = 0.15000001;
            explosionShielding = 1;
            visual = "injury_body";
            minimalHit = 0.01;
        };
        class HitDiaphragm: HitAbdomen {
            armor = 8;
            material = -1;
            name = "spine2";
            passThrough = 0.04;
            radius = 0.15;
            explosionShielding = 1.5;
            visual = "injury_body";
            minimalHit = 0.01;
        };
        class HitChest: HitDiaphragm {
            armor = 8;
            material = -1;
            name = "spine3";
            passThrough = 0.04;
            radius = 0.15000001;
            explosionShielding = 1.5;
            visual = "injury_body";
            minimalHit = 0.01;
        };
        class HitBody: HitChest {
            armor = 1000;
            material = -1;
            name = "body";
            passThrough = 0.04;
            radius = 0.16;
            explosionShielding = 1.5;
            visual = "injury_body";
            minimalHit = 0.01;
            depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
        };
        class HitArms {
            armor = 3;
            material = -1;
            name = "arms";
            passThrough = 0.4;
            radius = 0.1;
            explosionShielding = 0.3;
            visual = "injury_hands";
            minimalHit = 0.01;
        };
        class HitHands: HitArms {
            armor = 4;
            material = -1;
            name = "hands";
            passThrough = 0.4;
            radius = 0.1;
            explosionShielding = 0.3;
            visual = "injury_hands";
            minimalHit = 0.01;
            depends = "HitArms";
        };
        class HitLegs {
            armor = 3;
            material = -1;
            name = "legs";
            passThrough = 0.4;
            radius = 0.12;
            explosionShielding = 0.3;
            visual = "injury_legs";
            minimalHit = 0.01;
        };
    };
    armor = 10;
    armorStructural = 0.9;
    explosionShielding = 0.1;
    class EventHandlers {
        class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
    };
};
class Inegal_Diablerie_C: Inegal_Diablerie_S {
    _generalMacro = "Inegal_Diablerie_C";
    scope = 2;
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
        "SP_Modular2_Tan",
        "NVGogglesB_blk_F",
        "G_Balaclava_TI_G_tna_F",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    respawnLinkedItems[] = {
        "H_HelmeInegal_Diablerie_HelmettSpecB",
        "SP_Modular2_Tan",
        "NVGogglesB_blk_F",
        "G_Balaclava_TI_G_tna_F",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
};
class Inegal_Diablerie_G: Inegal_Diablerie_S {
    _generalMacro = "Inegal_Diablerie_G";
    scope = 2;
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
        "HandGrenade",
        "HandGrenade",
        "HandGrenade"
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
        "SP_Modular2_Tan",
        "NVGogglesB_blk_F",
        "G_Bandanna_beast",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    respawnLinkedItems[] = {
        "H_HelmeInegal_Diablerie_HelmettSpecB",
        "SP_Modular2_Tan",
        "NVGogglesB_blk_F",
        "G_Bandanna_beast",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
};
class Inegal_Diablerie_Su: Inegal_Diablerie_S {
    _generalMacro = "Inegal_Diablerie_Su";
    scope = 2;
    displayName = "Surgeon";
    icon = "iconManMedic";
    attendant = 1;
    editorPreview = QPATHTOEF(common,data\previews\Inegal_Diablerie_Su.jpg);
    picture = "pictureHeal";
    backpack = "Inegal_B_D_Surgeon";
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
        "SP_Modular2_Tan",
        "NVGogglesB_blk_F",
        "G_Balaclava_TI_G_tna_F",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    respawnLinkedItems[] = {
        "H_HelmeInegal_Diablerie_HelmettSpecB",
        "SP_Modular2_Tan",
        "NVGogglesB_blk_F",
        "G_Balaclava_TI_G_tna_F",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
};
class Inegal_Diablerie_B: Inegal_Diablerie_S {
    _generalMacro = "Inegal_Diablerie_B";
    scope = 2;
    displayName = "Brute";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_Diablerie_B.jpg);
    icon = "iconManMG";
    backpack = "Inegal_B_D_Brute";
    weapons[] = {
        "R3F_Minimi_762_Aimpoint",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "R3F_Minimi_762_Aimpoint",
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
        "SP_Modular2_Tan",
        "NVGogglesB_blk_F",
        "G_Balaclava_TI_G_tna_F",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    respawnLinkedItems[] = {
        "H_HelmeInegal_Diablerie_HelmettSpecB",
        "SP_Modular2_Tan",
        "NVGogglesB_blk_F",
        "G_Balaclava_TI_G_tna_F",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
};
class Inegal_Diablerie_Sh: Inegal_Diablerie_S {
    _generalMacro = "Inegal_Diablerie_Sh";
    scope = 2;
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
        "SP_Modular2_Tan",
        "NVGogglesB_blk_F",
        "G_Balaclava_TI_G_tna_F",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    respawnLinkedItems[] = {
        "H_HelmeInegal_Diablerie_HelmettSpecB",
        "SP_Modular2_Tan",
        "NVGogglesB_blk_F",
        "G_Balaclava_TI_G_tna_F",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
};
class Inegal_Diablerie_A: Inegal_Diablerie_S {
    _generalMacro = "Inegal_Diablerie_A";
    scope = 2;
    displayName = "Arsonist";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_Diablerie_A.jpg);
    icon = "iconManAT";
    threat[] = { 1,0.9,0.9 };
    backpack = "Inegal_B_D_Arsonist";
    weapons[] = {
        "arifle_SPAR_01_blk_F_erco_laser_bipod_suppressor",
        "R3F_AT4CS",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "arifle_SPAR_01_blk_F_erco_laser_bipod_suppressor",
        "R3F_AT4CS",
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
        "SP_Modular2_Tan",
        "NVGogglesB_blk_F",
        "G_Balaclava_TI_G_tna_F",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    respawnLinkedItems[] = {
        "H_HelmeInegal_Diablerie_HelmettSpecB",
        "SP_Modular2_Tan",
        "NVGogglesB_blk_F",
        "G_Balaclava_TI_G_tna_F",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
};
class Inegal_Diablerie_Se: Inegal_Diablerie_S {
    _generalMacro = "Inegal_Diablerie_Se";
    scope = 2;
    displayName = "Sentinel";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_Diablerie_Se.jpg);
    backpack = "Inegal_B_D_Sentinel";
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
        "SP_Modular2_Tan",
        "NVGogglesB_blk_F",
        "G_Balaclava_TI_G_tna_F",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    respawnLinkedItems[] = {
        "H_HelmeInegal_Diablerie_HelmettSpecB",
        "SP_Modular2_Tan",
        "NVGogglesB_blk_F",
        "G_Balaclava_TI_G_tna_F",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
};
class Inegal_Diablerie_As: Inegal_Diablerie_S {
    _generalMacro = "Inegal_Diablerie_As";
    scope = 2;
    displayName = "Assassin";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_Diablerie_As.jpg);
    uniformClass = "U_O_FullGhillie_sard";
    backpack = "Inegal_B_D_Assassin";
    weapons[] = {
        "R3F_PGM_Hecate_II_POLY_J10",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "R3F_PGM_Hecate_II_POLY_J10",
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
        "H_HelmetSpecB",
        "SP_Modular2_Tan",
        "NVGogglesB_blk_F",
        "G_Bandanna_beast",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    respawnLinkedItems[] = {
        "H_HelmetSpecB",
        "SP_Modular2_Tan",
        "NVGogglesB_blk_F",
        "G_Bandanna_beast",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
};
