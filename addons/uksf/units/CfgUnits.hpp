class UKSF_Clan_R : UKSF_Clan_Base {
    _generalMacro = "UKSF_Clan_R";
    scope = 2;
    displayName = "Rifleman";
	editorPreview = QPATHTOEF(common,data\previews\UKSF_Clan_R.jpg);
};
class UKSF_Clan_AR : UKSF_Clan_Base {
    scope = 2;
    displayName = "Autorifleman";
	editorPreview = QPATHTOEF(common,data\previews\UKSF_Clan_AR.jpg);
    icon = "iconManMG";
    cost = 1;
    camouflage = 1.3;
    threat[] = {1, 0.1, 0.3};
};
class UKSF_Clan_MG : UKSF_Clan_Base {
    scope = 2;
    displayName = "Machinegunner";
	editorPreview = QPATHTOEF(common,data\previews\UKSF_Clan_MG.jpg);
    icon = "iconManMG";
    cost = 1;
    camouflage = 1.3;
    threat[] = {1, 0.1, 0.4};
};
class UKSF_Clan_AT : UKSF_Clan_Base {
    scope = 2;
    displayName = "Rifleman (AT)";
	editorPreview = QPATHTOEF(common,data\previews\UKSF_Clan_AT.jpg);
    icon = "iconManAT";
    accuracy = 2.0999999;
    camouflage = 1.4;
    cost = 1;
    threat[] = {1, 0.8, 0.3};
};
class UKSF_Clan_O : UKSF_Clan_Base {
    scope = 2;
    displayName = "Officer";
	editorPreview = QPATHTOEF(common,data\previews\UKSF_Clan_O.jpg);
    icon = "iconManOfficer";
    accuracy = 2.5;
    sensitivity = 3.3;
    cost = 1;
    threat[] = {1, 0.3, 0.1};
    linkedItems[] = {
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "UK3CB_BAF_H_Beret_PR"
    };
    respawnLinkedItems[] = {
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "UK3CB_BAF_H_Beret_PR"
    };
};
class UKSF_Clan_SL : UKSF_Clan_Base {
    scope = 2;
    displayName = "Section Commander";
	editorPreview = QPATHTOEF(common,data\previews\UKSF_Clan_SL.jpg);
    icon = "iconManLeader";
    accuracy = 2.5;
    sensitivity = 3.3;
    cost = 1;
    threat[] = {1, 0.3, 0.1};
};
class UKSF_Clan_TL : UKSF_Clan_Base {
    scope = 2;
    displayName = "Team Leader";
	editorPreview = QPATHTOEF(common,data\previews\UKSF_Clan_TL.jpg);
    icon = "iconManLeader";
    accuracy = 2.5;
    sensitivity = 3.3;
    cost = 1;
    threat[] = {1, 0.3, 0.1};
};
class UKSF_Clan_MED : UKSF_Clan_Base {
    scope = 2;
    displayName = "Combat Medic";
	editorPreview = QPATHTOEF(common,data\previews\UKSF_Clan_MED.jpg);
    icon = "iconManMedic";
    picture = "pictureHeal";
    backpack = "UKSF_B_Medic";
    uniformClass = "UK3CB_BAF_U_CombatUniform_MTP_CSMR";
    attendant = 1;
    camouflage = 1.5;
    sensitivity = 2.5;
    cost = 1;
};
class UKSF_Clan_EXP : UKSF_Clan_Base {
    scope = 2;
    displayName = "Explosive Specialist";
	editorPreview = QPATHTOEF(common,data\previews\UKSF_Clan_EXP.jpg);
    icon = "iconManExplosive";
    picture = "pictureExplosive";
    canDeactivateMines = 1;
    detectSkill = 80;
    sensitivity = 2.5;
    cost = 1;
    threat[] = {1, 0.5, 0.1};
};
class UKSF_Clan_Sniper : UKSF_Clan_Base {
    scope = 2;
    displayName = "Sniper";
	editorPreview = QPATHTOEF(common,data\previews\UKSF_Clan_Sniper.jpg);
    detectSkill = 30;
    camouflage = 0.6;
    sensitivity = 3.3;
    canHideBodies = 1;
    cost = 1;
    threat[] = {1, 0.3, 0.3};
};
class UKSF_Clan_RTO : UKSF_Clan_Base {
    scope = 2;
    cost = 1;
    displayName = "RTO";
	editorPreview = QPATHTOEF(common,data\previews\UKSF_Clan_RTO.jpg);
    uniformClass = "UK3CB_BAF_U_CombatUniform_MTP_Sig";
};
class UKSF_Clan_ATC : UKSF_Clan_Base {
    author = "UKSF";
    faction = "UKSF_Clan";
    genericNames = "EnglishMen";
    editorSubcategory = QEGVAR(common,jsfaw);
    displayName = "Air Traffic Controller";
    model = "\A3\Characters_F\BLUFOR\b_soldier_01.p3d";
    uniformClass = "UKSF_U_ATC";
	editorPreview = QPATHTOEF(common,data\previews\UKSF_Clan_ATC.jpg);
    backpack = "UKSF_B_ATC";
    attendant = 1;
    cost = 1;
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers {};
    };
};
	class B_Helipilot_F;
class UKSF_Clan_HP : B_Helipilot_F {
    author = "UKSF";
    faction = "UKSF_Clan";
    genericNames = "EnglishMen";
    displayName = "Rotary Pilot";
    editorSubcategory = QEGVAR(common,jsfaw);
    model = "\A3\Characters_F\BLUFOR\b_soldier_01.p3d";
    uniformClass = "UK3CB_BAF_U_HeliPilotCoveralls_RAF";
	editorPreview = QPATHTOEF(common,data\previews\UKSF_Clan_HP.jpg);
    backpack = "B_Parachute";
    attendant = 1;
    weapons[] = {
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "Throw",
        "Put"
    };
    magazines[] = {
        "SmokeShell",
        "SmokeShellBlue",
        "SmokeShellBlue",
        "SmokeShellOrange",
        "SmokeShellOrange",
        "Chemlight_red"
    };
    respawnMagazines[] = {
        "SmokeShell",
        "SmokeShellBlue",
        "SmokeShellBlue",
        "SmokeShellOrange",
        "SmokeShellOrange",
        "Chemlight_red"
    };
    Items[] = {
        "ACE_EarPlugs",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_morphine",
        "ACE_morphine",
        "ACE_IR_Strobe_Item",
        "ACE_IR_Strobe_Item"
    };
    respawnItems[] = {
        "ACE_EarPlugs",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_morphine",
        "ACE_morphine",
        "ACE_IR_Strobe_Item",
        "ACE_IR_Strobe_Item"
    };
    linkedItems[] = {
        "V_mas_uk_TacVest_p",
        "UK3CB_BAF_H_PilotHelmetHeli_A",
        "ACE_NVG_Pilot",
        "ItemMap",
        "ItemCompass",
        "ItemGPS",
        "ItemWatch"
    };
    respawnLinkedItems[] = {
        "V_mas_uk_TacVest_p",
        "UK3CB_BAF_H_PilotHelmetHeli_A",
        "ACE_NVG_Pilot",
        "ItemMap",
        "ItemCompass",
        "ItemGPS",
        "ItemWatch"
    };
    cost = 1;
    threat[] = {1, 0.8, 0.8};
    class Wounds {
        tex[] = {};
        mat[] = {
            "A3\Characters_F\BLUFOR\Data\clothing1.rvmat",
            "A3\Characters_F\BLUFOR\Data\clothing1_injury.rvmat",
            "A3\Characters_F\BLUFOR\Data\clothing1_injury.rvmat",
            "A3\Characters_F\Common\Data\basicbody.rvmat",
            "A3\Characters_F\Common\Data\basicbody_injury.rvmat",
            "A3\Characters_F\Common\Data\basicbody_injury.rvmat",
            "A3\characters_f\common\data\coveralls.rvmat",
            "A3\Characters_F\Common\Data\coveralls_injury.rvmat",
            "A3\Characters_F\Common\Data\coveralls_injury.rvmat",
            "A3\Characters_F\Heads\Data\hl_white_bald_muscular.rvmat",
            "A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",
            "A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",
            "A3\Characters_F\Heads\Data\hl_black_bald_muscular.rvmat",
            "A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",
            "A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",
            "A3\Characters_F\Heads\Data\hl_white_hairy_muscular.rvmat",
            "A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",
            "A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",
            "A3\Characters_F\Heads\Data\hl_white_old.rvmat",
            "A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",
            "A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",
            "A3\Characters_F\Heads\Data\hl_asian_bald_muscular.rvmat",
            "A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat",
            "A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat"};
    };
};
class UKSF_Clan_FW : UKSF_Clan_HP {
    author = "UKSF";
    displayName = "Fixed Wing Pilot";
    editorSubcategory = QEGVAR(common,jsfaw);
	editorPreview = QPATHTOEF(common,data\previews\UKSF_Clan_FW.jpg);
    backpack = "B_Parachute";
    linkedItems[] = {
        "UKSF_FlightVest",
        "H_PilotHelmetFighter_B",
        "ItemMap",
        "ItemCompass",
        "ItemGPS",
        "ItemWatch"
    };
    respawnLinkedItems[] = {
        "UKSF_FlightVest",
        "H_PilotHelmetFighter_B",
        "ItemMap",
        "ItemCompass",
        "ItemGPS",
        "ItemWatch"
    };
    cost = 1;
};