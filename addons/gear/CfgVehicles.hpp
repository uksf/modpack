class CBA_Extended_EventHandlers;
class CfgVehicles {
	class UK3CB_BAF_B_Bergen_MTP_Medic_L_A;
	class UK3CB_BAF_B_Bergen_MTP_Radio_L_B;
	class Bag_Base;
	class UKSF_B_Medic: UK3CB_BAF_B_Bergen_MTP_Medic_L_A {
		scope = 2;
		scopeArsenal = 2;
		author = "UKSF";
		displayName = "Medic Pack";
		class TransportItems {
			class _xx_ACE_packingBandage {
				name = "ACE_packingBandage";
				count = 50;
			};
			class _xx_ACE_elasticBandage {
				name = "ACE_elasticBandage";
				count = 50;
			};
			class _xx_ACE_tourniquet {
				name = "ACE_tourniquet";
				count = 5;
			};
			class _xx_ACE_ACE_atropine {
				name = "ACE_atropine";
				count = 6;
			};
			class _xx_ACE_ACE_adenosinee {
				name = "ACE_adenosine";
				count = 6;
			};
			class _xx_ACE_morphine {
				name = "ACE_morphine";
				count = 25;
			};
			class _xx_ACE_epinephrine {
				name = "ACE_epinephrine";
				count = 25;
			};
			class _xx_ACE_bloodIV_500 {
				name = "ACE_bloodIV_500";
				count = 5;
			};
			class _xx_ACE_bloodIV {
				name = "ACE_bloodIV";
				count = 5;
			};
			class _xx_ACE_personalAidKit {
				name = "ACE_personalAidKit";
				count = 1;
			};
			class _xx_ACE_surgicalKit {
				name = "ACE_surgicalKit";
				count = 1;
			};
		};
	};
	class UKSF_B_ATC: UK3CB_BAF_B_Bergen_MTP_Radio_L_B {
		scope = 2;
		scopeArsenal = 2;
		author = "UKSF";
		displayName = "ATC Pack";
		maximumLoad = 400;
		class TransportItems {
			class _xx_ACE_packingBandage {
				name = "ACE_packingBandage";
				count = 10;
			};
			class _xx_ACE_elasticBandage {
				name = "ACE_elasticBandage";
				count = 10;
			};
			class _xx_ACE_epinephrine {
				name = "ACE_epinephrine";
				count = 5;
			};
			class _xx_ACE_bloodIV_500 {
				name = "ACE_bloodIV_500";
				count = 2;
			};
			class _xx_ACE_personalAidKit {
				name = "ACE_personalAidKit";
				count = 1;
			};
			class _xx_ACE_surgicalKit {
				name = "ACE_surgicalKit";
				count = 1;
			};
			class _xx_ACRE_PRC117F_ID_1 {
				name = "ACRE_PRC117F_ID_1";
				count = 1;
			};
			class _xx_ACRE_PRC117F_ID_2 {
				name = "ACRE_PRC117F_ID_2";
				count = 1;
			};
		};
	};
	class B_Parachute: Bag_Base {
		mapSize = 0.55;
		_generalMacro = "B_Parachute";
		scope = 2;
		displayName = "$STR_A3_Bag_ParachuteSteerable0";
		picture = "\A3\Characters_F\data\ui\icon_b_parachute_ca.paa";
		model = "\A3\Weapons_F\Ammoboxes\Bags\Backpack_Parachute";
		backpackSimulation = "ParachuteSteerable";
		ParachuteClass = "Steerable_Parachute_F";
		maximumLoad = 320;
	};

	class I_soldier_F;
	class I_Soldier_02_F;
	class B_Helipilot_F;
	class UK3CB_BAF_Soldier_MTP_1para_LongSleeve_base: I_soldier_F {
		scope = 1;
		scopeCurator = 0;
		author = "UKSF";
		side = 1;
		faction = "UKSF_Clan";
		identityTypes[] = { "LanguageENGB_F", "Head_NATO", "G_NATO_default" };
		displayName = "Base Soldier MTP 1Para";
		genericNames = "EnglishMen";
		uniformClass = "UK3CB_BAF_U_CombatUniform_MTP_1Para";
		hiddenSelections[] = { "Camo", "insignia" };
		hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_1para.paa) };
	};
	class UK3CB_BAF_Soldier_MTP_1para_ShortSleeve_base: I_Soldier_02_F {
		scope = 1;
		scopeCurator = 0;
		author = "UKSF";
		side = 1;
		faction = "UKSF_Clan";
		identityTypes[] = { "LanguageENGB_F", "Head_NATO", "G_NATO_default" };
		displayName = "Base Soldier MTP 1Para Rolled";
		genericNames = "EnglishMen";
		uniformClass = "UK3CB_BAF_U_CombatUniform_MTP_1Para_ShortSleeve";
		hiddenSelections[] = { "Camo", "insignia" };
		hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_1para.paa) };
	};
	class UK3CB_BAF_Soldier_MTP_CSMR_LongSleeve_base: UK3CB_BAF_Soldier_MTP_1para_LongSleeve_base {
		displayName = "Base Soldier MTP CSMR";
		uniformClass = "UK3CB_BAF_U_CombatUniform_MTP_CSMR";
		hiddenSelections[] = { "Camo", "insignia" };
		hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_csmr.paa) };
	};
	class UK3CB_BAF_Soldier_MTP_CSMR_ShortSleeve_base: UK3CB_BAF_Soldier_MTP_1para_ShortSleeve_base {
		displayName = "Base Soldier MTP CSMR Rolled";
		uniformClass = "UK3CB_BAF_U_CombatUniform_MTP_CSMR_ShortSleeve";
		hiddenSelections[] = { "Camo", "insignia" };
		hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_csmr.paa) };
	};
	class UK3CB_BAF_Soldier_MTP_Path_LongSleeve_base: UK3CB_BAF_Soldier_MTP_1para_LongSleeve_base {
		displayName = "Base Soldier MTP Pathfinder";
		uniformClass = "UK3CB_BAF_U_CombatUniform_MTP_Path";
		hiddenSelections[] = { "Camo", "insignia" };
		hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_path.paa) };
	};
	class UK3CB_BAF_Soldier_MTP_Path_ShortSleeve_base: UK3CB_BAF_Soldier_MTP_1para_ShortSleeve_base {
		displayName = "Base Soldier MTP Pathfinder Rolled";
		uniformClass = "UK3CB_BAF_U_CombatUniform_MTP_Path_ShortSleeve";
		hiddenSelections[] = { "Camo", "insignia" };
		hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_path.paa) };
	};
	class UK3CB_BAF_Soldier_MTP_Sig_LongSleeve_base: UK3CB_BAF_Soldier_MTP_1para_LongSleeve_base {
		displayName = "Base Soldier MTP Signals";
		uniformClass = "UK3CB_BAF_U_CombatUniform_MTP_Path";
		hiddenSelections[] = { "Camo", "insignia" };
		hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_sig.paa) };
	};
	class UK3CB_BAF_Soldier_MTP_Sig_ShortSleeve_base: UK3CB_BAF_Soldier_MTP_1para_ShortSleeve_base {
		displayName = "Base Soldier MTP Signals Rolled";
		uniformClass = "UK3CB_BAF_U_CombatUniform_MTP_Path_ShortSleeve";
		hiddenSelections[] = { "Camo", "insignia" };
		hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_sig.paa) };
	};
	class UK3CB_BAF_HeliPilot_RAF_base: B_Helipilot_F {
		scope = 1;
		scopeCurator = 0;
		author = "UKSF";
		side = 1;
		faction = "UKSF_Clan";
		identityTypes[] = { "LanguageENGB_F", "Head_NATO", "G_NATO_default" };
		displayName = "Base Helicopter Pilot RAF";
		genericNames = "EnglishMen";
		uniformClass = "UK3CB_BAF_U_HeliPilotCoveralls_RAF";
		model = "\A3\Characters_F\Common\coveralls.p3d";
		modelSides[] = { 3,1 };
		hiddenSelections[] = { "Camo", "insignia" };
		hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\helipilot_coveralls_raf.paa) };
	};
	class UKSF_Soldier_ATC_base: B_Helipilot_F {
		scope = 1;
		scopeCurator = 0;
		author = "UKSF";
		side = 1;
		faction = "UKSF_Clan";
		identityTypes[] = { "LanguageENGB_F", "Head_NATO", "G_NATO_default" };
		displayName = "ATC Base";
		genericNames = "EnglishMen";
		nakedUniform = "U_BasicBody";
		uniformClass = "UKSF_ATC";
		model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
		hiddenSelections[] = { "Camo" };
		hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\ATC.paa) };
	};

	class UK3CB_BAF_HeliPilot_base;
	class UK3CB_BAF_HeliPilot_RAF: UK3CB_BAF_HeliPilot_base {
		scope = 0;
		scopeCUrator = 0;
	};
	class UK3CB_BAF_HeliPilot_RN: UK3CB_BAF_HeliPilot_base {
		scope = 0;
		scopeCUrator = 0;
	};
	class UK3CB_BAF_Pilot_Army: UK3CB_BAF_HeliPilot_RAF {
		scope = 0;
		scopeCUrator = 0;
	};
	class UK3CB_BAF_Pilot_RAF: UK3CB_BAF_HeliPilot_RAF {
		scope = 0;
		scopeCUrator = 0;
	};
	class UK3CB_BAF_Pilot_RN: UK3CB_BAF_HeliPilot_RN {
		scope = 0;
		scopeCUrator = 0;
	};

	class CargoNet_01_ammo_base_F;
	class Land_CargoBox_V1_F;
	class UKSF_S_Empty: CargoNet_01_ammo_base_F {
		author = "UKSF";
		faction = "UKSF_Clan";
		scope = 2;
		scopeCurator = 2;
		displayName = "Resupply Crate (Empty)";
		editorPreview = QPATHTOEF(common,data\previews\UKSF_Crate.jpg);
		maximumLoad = 100000;
		hiddenSelectionsTextures[] = { "\A3\Weapons_F\Ammoboxes\Data\AmmoBox_CO.paa","\A3\Weapons_F\Ammoboxes\Data\AmmoBox_signs_CA.paa" };
		class TransportMagazines {};
		class TransportWeapons {};
		class TransportItems {};
		class TransportBackpacks {};
	};
	class UKSF_S_Ammo: UKSF_S_Empty {
		author = "UKSF";
		scope = 2;
		scopeCurator = 2;
		displayName = "Resupply Crate (Ammo)";
		class TransportMagazines {
			class _xx_UK3CB_BAF_556_30Rnd {
				magazine = "UK3CB_BAF_556_30Rnd";
				count = 50;
			};
			class _xx_UK3CB_BAF_556_30Rnd_T {
				magazine = "UK3CB_BAF_556_30Rnd_T";
				count = 50;
			};
			class _xx_UK3CB_BAF_556_200Rnd {
				magazine = "UK3CB_BAF_556_200Rnd";
				count = 15;
			};
			class _xx_UK3CB_BAF_556_200Rnd_T {
				magazine = "UK3CB_BAF_556_200Rnd_T";
				count = 15;
			};
			class _xx_UK3CB_BAF_762_100Rnd {
				magazine = "UK3CB_BAF_762_100Rnd";
				count = 15;
			};
			class _xx_UK3CB_BAF_762_100Rnd_T {
				magazine = "UK3CB_BAF_762_100Rnd_T";
				count = 15;
			};
			class _xx_UK3CB_BAF_762_L42A1_20Rnd {
				magazine = "UK3CB_BAF_762_L42A1_20Rnd";
				count = 20;
			};
			class _xx_UK3CB_BAF_762_L42A1_20Rnd_T {
				magazine = "UK3CB_BAF_762_L42A1_20Rnd_T";
				count = 10;
			};
			class _xx_UK3CB_BAF_338_5Rnd {
				magazine = "UK3CB_BAF_338_5Rnd";
				count = 10;
			};
			class _xx_1Rnd_HE_Grenade_shell {
				magazine = "1Rnd_HE_Grenade_shell";
				count = 40;
			};
			class _xx_HandGrenade {
				magazine = "HandGrenade";
				count = 20;
			};
			class _xx_SmokeShell {
				magazine = "SmokeShell";
				count = 20;
			};
			class _xx_SmokeShellRed {
				magazine = "SmokeShellRed";
				count = 20;
			};
			class _xx_SmokeShellGreen {
				magazine = "SmokeShellGreen";
				count = 20;
			};
		};
		class TransportWeapons {
			class _xx_UK3CB_BAF_NLAW_Launcher {
				weapon = "UK3CB_BAF_NLAW_Launcher";
				count = 5;
			};
			class _xx_UK3CB_BAF_AT4_CS_AT_Launcher {
				weapon = "UK3CB_BAF_AT4_CS_AT_Launcher";
				count = 5;
			};
			class _xx_UK3CB_BAF_Javelin_Slung_Tube {
				weapon = "UK3CB_BAF_Javelin_Slung_Tube";
				count = 5;
			};
		};
	};
	class UKSF_S_Medic: UKSF_S_Empty {
		author = "UKSF";
		scope = 2;
		scopeCurator = 2;
		displayName = "Resupply Crate (Medical)";
		class TransportItems {
			class _xx_ACE_packingBandage {
				name = "ACE_packingBandage";
				count = 50;
			};
			class _xx_ACE_elasticBandage {
				name = "ACE_elasticBandage";
				count = 50;
			};
			class _xx_ACE_quikclot {
				name = "ACE_quikclot";
				count = 50;
			};
			class _xx_ACE_epinephrine {
				name = "ACE_epinephrine";
				count = 30;
			};
			class _xx_ACE_morphine {
				name = "ACE_morphine";
				count = 30;
			};
			class _xx_ACE_bloodIV_500 {
				name = "ACE_bloodIV_500";
				count = 20;
			};
			class _xx_ACE_tourniquet {
				name = "ACE_tourniquet";
				count = 10;
			};
			class _xx_ACE_ACE_atropine {
				name = "ACE_atropine";
				count = 20;
			};
			class _xx_ACE_ACE_adenosinee {
				name = "ACE_adenosine";
				count = 20;
			};
			class _xx_ACE_bloodIV {
				name = "ACE_bloodIV";
				count = 20;
			};
			class _xx_ACE_personalAidKit {
				name = "ACE_personalAidKit";
				count = 1;
			};
			class _xx_ACE_surgicalKit {
				name = "ACE_surgicalKit";
				count = 1;
			};
		};
	};
	class UKSF_S_AmmoMedic: UKSF_S_Empty {
		author = "UKSF";
		scope = 2;
		scopeCurator = 2;
		displayName = "Resupply Crate (Ammo & Medical)";
		class TransportMagazines {
			class _xx_UK3CB_BAF_556_30Rnd {
				magazine = "UK3CB_BAF_556_30Rnd";
				count = 30;
			};
			class _xx_UK3CB_BAF_556_30Rnd_T {
				magazine = "UK3CB_BAF_556_30Rnd_T";
				count = 10;
			};
			class _xx_UK3CB_BAF_556_200Rnd {
				magazine = "UK3CB_BAF_556_200Rnd";
				count = 10;
			};
			class _xx_UK3CB_BAF_556_200Rnd_T {
				magazine = "UK3CB_BAF_556_200Rnd_T";
				count = 10;
			};
			class _xx_UK3CB_BAF_762_100Rnd {
				magazine = "UK3CB_BAF_762_100Rnd";
				count = 10;
			};
			class _xx_UK3CB_BAF_762_100Rnd_T {
				magazine = "UK3CB_BAF_762_100Rnd_T";
				count = 10;
			};
			class _xx_UK3CB_BAF_762_L42A1_20Rnd {
				magazine = "UK3CB_BAF_762_L42A1_20Rnd";
				count = 10;
			};
			class _xx_UK3CB_BAF_762_L42A1_20Rnd_T {
				magazine = "UK3CB_BAF_762_L42A1_20Rnd_T";
				count = 10;
			};
			class _xx_UK3CB_BAF_338_5Rnd {
				magazine = "UK3CB_BAF_338_5Rnd";
				count = 10;
			};
			class _xx_1Rnd_HE_Grenade_shell {
				magazine = "1Rnd_HE_Grenade_shell";
				count = 30;
			};
			class _xx_HandGrenade {
				magazine = "HandGrenade";
				count = 20;
			};
			class _xx_SmokeShell {
				magazine = "SmokeShell";
				count = 10;
			};
			class _xx_SmokeShellRed {
				magazine = "SmokeShellRed";
				count = 10;
			};
			class _xx_SmokeShellGreen {
				magazine = "SmokeShellGreen";
				count = 10;
			};
		};
		class TransportWeapons {
			class _xx_UK3CB_BAF_NLAW_Launcher {
				weapon = "UK3CB_BAF_NLAW_Launcher";
				count = 3;
			};
			class _xx_UK3CB_BAF_Javelin_Slung_Tube {
				weapon = "UK3CB_BAF_Javelin_Slung_Tube";
				count = 3;
			};
		};
		class TransportItems {
			class _xx_ACE_packingBandage {
				name = "ACE_packingBandage";
				count = 30;
			};
			class _xx_ACE_elasticBandage {
				name = "ACE_elasticBandage";
				count = 30;
			};
			class _xx_ACE_quikclot {
				name = "ACE_quikclot";
				count = 30;
			};
			class _xx_ACE_epinephrine {
				name = "ACE_epinephrine";
				count = 10;
			};
			class _xx_ACE_morphine {
				name = "ACE_morphine";
				count = 15;
			};
			class _xx_ACE_bloodIV_500 {
				name = "ACE_bloodIV_500";
				count = 10;
			};
			class _xx_ACE_ACE_atropine {
				name = "ACE_atropine";
				count = 10;
			};
			class _xx_ACE_ACE_adenosinee {
				name = "ACE_adenosine";
				count = 10;
			};
		};
	};
	class UKSF_S_Radios: UKSF_S_Empty {
		author = "UKSF";
		scope = 2;
		scopeCurator = 2;
		displayName = "ACRE Radios";
		class eventhandlers {
			init = "this addItemCargoGlobal [""ACRE_PRC117F"", 10]";
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
		};
		class TransportMagazines {};
		class TransportWeapons {};
		class TransportItems {
			class _xx_ACRE_PRC177F {
				name = "ACRE_PRC117F";
				count = 10;
			};
			class _xx_ACRE_PRC152 {
				name = "ACRE_PRC152";
				count = 25;
			};
			class _xx_ACRE_PRC343 {
				name = "ACRE_PRC343";
				count = 25;
			};
		};
		class TransportBackpacks {
			class _xx_UKSF_RadioPack {
				backpack = "B_Parachute";
				count = 5;
			};
		};
	};
	class UK3CB_BAF_Vehicles_Servicing_Aircraft_Point: Land_CargoBox_V1_F {
		scope = 2;
		scopeCurator = 2;
		faction = "UKSF_Clan";
		displayName = "Aircraft Servicing Point";
		editorPreview = QPATHTOEF(common,data\previews\UK3CB_BAF_Vehicles_Servicing_Aircraft_Point.jpg);
	};

	class TargetP_Inf_F;
	class UKSF_Target_Nopopup: TargetP_Inf_F {
		scope = 2;
		scopeCurator = 2;
		displayName = "Figure 11 Target - No Popup";
		class EventHandlers {
			hitPart = "";
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
		};
	};

	class B_AssaultPack_rgr;
	class GENFOR_B_R: B_AssaultPack_rgr {
		scope = 1;
		author = "UKSF";
		displayName = "Standard Pack";
		class TransportMagazines {
			class _xx_rhs_30Rnd_545x39_AK {
				magazine = "rhs_30Rnd_545x39_AK";
				count = 10;
			};
			class _xx_rhs_mag_rgd5 {
				magazine = "rhs_mag_rgd5";
				count = 5;
			};
			class _xx_rhs_mag_rdg2_white {
				magazine = "rhs_mag_rdg2_white";
				count = 5;
			};
		};
	};
	class GENFOR_B_RNOMAG: GENFOR_B_R {
		displayName = "Light Pack";
		class TransportMagazines {
			class _xx_rhs_mag_rgd5 {
				magazine = "rhs_mag_rgd5";
				count = 5;
			};
			class _xx_rhs_mag_rdg2_white {
				magazine = "rhs_mag_rdg2_white";
				count = 5;
			};
		};
	};
	class GENFOR_B_Mark: GENFOR_B_R {
		displayName = "Marksman Pack";
		class TransportMagazines {
			class _xx_rhs_30Rnd_762x39mm_tracer {
				magazine = "rhs_30Rnd_762x39mm_tracer";
				count = 6;
			};
			class _xx_rhs_mag_rgd5 {
				magazine = "rhs_mag_rgd5";
				count = 5;
			};
			class _xx_rhs_mag_rdg2_white {
				magazine = "rhs_mag_rdg2_white";
				count = 5;
			};
		};
	};
	class GENFOR_B_Med: UKSF_B_Medic {
		scope = 1;
		displayName = "Genfor Medic Pack";
		class TransportMagazines {};
	};
	class GENFOR_B_MG: GENFOR_B_R {
		displayName = "MG Pack";
		class TransportMagazines {
			class _xx_rhs_100Rnd_762x54mmR_green {
				magazine = "rhs_100Rnd_762x54mmR_green";
				count = 5;
			};
			class _xx_rhs_mag_rgd5 {
				magazine = "rhs_mag_rgd5";
				count = 5;
			};
			class _xx_rhs_mag_rdg2_white {
				magazine = "rhs_mag_rdg2_white";
				count = 5;
			};
		};
	};
	class SP_Carryall_Hunter2;
	class GENFOR_B_AA: SP_Carryall_Hunter2 {
		scope = 1;
		author = "UKSF";
		displayName = "AA Pack";
		class TransportMagazines {
			class _xx_rhs_mag_9k38_rocket {
				magazine = "rhs_mag_9k38_rocket";
				count = 4;
			};
			class _xx_rhs_30Rnd_545x39_AK {
				magazine = "rhs_30Rnd_545x39_AK";
				count = 10;
			};
			class _xx_rhs_mag_rgd5 {
				magazine = "rhs_mag_rgd5";
				count = 5;
			};
			class _xx_rhs_mag_rdg2_white {
				magazine = "rhs_mag_rdg2_white";
				count = 5;
			};
		};
	};
	class GENFOR_B_AT7: GENFOR_B_AA {
		displayName = "RPG Pack";
		class TransportMagazines {
			class _xx_rhs_rpg7_PG7VL_mag {
				magazine = "rhs_rpg7_PG7VL_mag";
				count = 6;
			};
			class _xx_rhs_30Rnd_545x39_AK {
				magazine = "rhs_30Rnd_545x39_AK";
				count = 10;
			};
			class _xx_rhs_mag_rgd5 {
				magazine = "rhs_mag_rgd5";
				count = 5;
			};
			class _xx_rhs_mag_rdg2_white {
				magazine = "rhs_mag_rdg2_white";
				count = 5;
			};
		};
	};
	class GENFOR_B_AT: GENFOR_B_AA {
		displayName = "AT Pack";
		class TransportMagazines {
			class _xx_Titan_AT {
				magazine = "Titan_AT";
				count = 2;
			};
			class _xx_Titan_AP {
				magazine = "Titan_AP";
				count = 2;
			};
			class _xx_rhs_30Rnd_545x39_AK {
				magazine = "rhs_30Rnd_545x39_AK";
				count = 10;
			};
			class _xx_rhs_mag_rgd5 {
				magazine = "rhs_mag_rgd5";
				count = 5;
			};
			class _xx_rhs_mag_rdg2_white {
				magazine = "rhs_mag_rdg2_white";
				count = 5;
			};
		};
	};
	class GENFOR_B_Sl: GENFOR_B_R {
		displayName = "Section Leader Pack";
		class TransportMagazines {
			class _xx_rhs_30Rnd_545x39_AK {
				magazine = "rhs_30Rnd_545x39_AK";
				count = 10;
			};
			class _xx_rhs_mag_rgd5 {
				magazine = "rhs_mag_rgd5";
				count = 5;
			};
			class _xx_rhs_mag_rdg2_white {
				magazine = "rhs_mag_rdg2_white";
				count = 5;
			};
			class _xx_rhs_VOG25 {
				magazine = "rhs_VOG25";
				count = 10;
			};
		};
	};
	class UK3CB_BAF_B_Bergen_MTP_JTAC_L_A;
	class GENFOR_B_Radio: UK3CB_BAF_B_Bergen_MTP_JTAC_L_A {
		scope = 1;
		displayName = "Radio Pack";
		class eventhandlers {
			init = "this addItemCargoGlobal [""ACRE_PRC117F"", 2]";
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
		};
		class TransportMagazines {
			class _xx_rhs_30Rnd_545x39_AK {
				magazine = "rhs_30Rnd_545x39_AK";
				count = 10;
			};
			class _xx_rhs_mag_rgd5 {
				magazine = "rhs_mag_rgd5";
				count = 5;
			};
			class _xx_rhs_mag_rdg2_white {
				magazine = "rhs_mag_rdg2_white";
				count = 5;
			};
		};
	};

	class GENFOR_B_P_R: SP_Carryall_Hunter2 {
		scope = 1;
		author = "UKSF";
		displayName = "Para Standard Pack";
		class TransportMagazines {
			class _xx_rhs_30Rnd_545x39_AK {
				magazine = "rhs_30Rnd_545x39_AK";
				count = 10;
			};
			class _xx_rhs_mag_rgd5 {
				magazine = "rhs_mag_rgd5";
				count = 5;
			};
			class _xx_rhs_mag_rdg2_white {
				magazine = "rhs_mag_rdg2_white";
				count = 5;
			};
		};
	};
	class GENFOR_B_P_RNOMAG: SP_Carryall_Hunter2 {
		scope = 1;
		author = "UKSF";
		displayName = "Para Light Pack";
		class TransportMagazines {
			class _xx_rhs_mag_rgd5 {
				magazine = "rhs_mag_rgd5";
				count = 5;
			};
			class _xx_rhs_mag_rdg2_white {
				magazine = "rhs_mag_rdg2_white";
				count = 5;
			};
		};
	};
	class GENFOR_B_P_B: GENFOR_B_P_R {
		displayName = "Para Breacher Pack";
		class TransportMagazines {
			class _xx_UK3CB_BAF_12G_Pellets {
				magazine = "UK3CB_BAF_12G_Pellets";
				count = 5;
			};
			class _xx_UK3CB_BAF_12G_Slugs {
				magazine = "UK3CB_BAF_12G_Slugs";
				count = 5;
			};
			class _xx_rhs_mag_rgd5 {
				magazine = "rhs_mag_rgd5";
				count = 5;
			};
			class _xx_rhs_mag_rdg2_white {
				magazine = "rhs_mag_rdg2_white";
				count = 5;
			};
			class _xx_DemoCharge_Remote_Mag {
				magazine = "DemoCharge_Remote_Mag";
				count = 4;
			};
		};
	};
	class GENFOR_B_P_MG: SP_Carryall_Hunter2 {
		scope = 1;
		displayName = "Para MG Pack";
		class TransportMagazines {
			class _xx_200Rnd_65x39_cased_Box_Tracer {
				magazine = "200Rnd_65x39_cased_Box_Tracer";
				count = 5;
			};
			class _xx_rhs_mag_rgd5 {
				magazine = "rhs_mag_rgd5";
				count = 5;
			};
			class _xx_rhs_mag_rdg2_white {
				magazine = "rhs_mag_rdg2_white";
				count = 5;
			};
		};
	};
	class GENFOR_B_P_AT: GENFOR_B_P_MG {
		displayName = "Para AT Pack";
		class TransportMagazines {
			class _xx_rhs_30Rnd_545x39_AK {
				magazine = "rhs_30Rnd_545x39_AK";
				count = 10;
			};
			class _xx_rhs_rpg7_PG7VL_mag {
				magazine = "rhs_rpg7_PG7VL_mag";
				count = 6;
			};
			class _xx_rhs_mag_rgd5 {
				magazine = "rhs_mag_rgd5";
				count = 5;
			};
			class _xx_rhs_mag_rdg2_white {
				magazine = "rhs_mag_rdg2_white";
				count = 5;
			};
		};
	};
	class GENFOR_B_P_AA: GENFOR_B_P_MG {
		displayName = "Para AA Pack";
		class TransportMagazines {
			class _xx_rhs_30Rnd_545x39_AK {
				magazine = "rhs_30Rnd_545x39_AK";
				count = 10;
			};
			class _xx_rhs_mag_9k32_rocket {
				magazine = "rhs_mag_9k32_rocket";
				count = 4;
			};
			class _xx_rhs_mag_rgd5 {
				magazine = "rhs_mag_rgd5";
				count = 5;
			};
			class _xx_rhs_mag_rdg2_white {
				magazine = "rhs_mag_rdg2_white";
				count = 5;
			};
		};
	};

	class GENFOR_B_SF_R: GENFOR_B_R {
		displayName = "SF Standard Pack";
		class TransportMagazines {
			class _xx_30Rnd_556x45_Stanag {
				magazine = "30Rnd_556x45_Stanag";
				count = 10;
			};
			class _xx_rhs_mag_rgd5 {
				magazine = "rhs_mag_rgd5";
				count = 5;
			};
			class _xx_rhs_mag_rdg2_white {
				magazine = "rhs_mag_rdg2_white";
				count = 5;
			};
		};
	};
	class GENFOR_B_SF_RNOMAG: GENFOR_B_SF_R {
		displayName = "SF Light Pack";
		class TransportMagazines {
			class _xx_rhs_mag_rgd5 {
				magazine = "rhs_mag_rgd5";
				count = 5;
			};
			class _xx_rhs_mag_rdg2_white {
				magazine = "rhs_mag_rdg2_white";
				count = 5;
			};
		};
	};
	class GENFOR_B_SF_MG: GENFOR_B_SF_R {
		displayName = "SF MG Pack";
		class TransportMagazines {
			class _xx_200Rnd_65x39_cased_Box_Tracer {
				magazine = "200Rnd_65x39_cased_Box_Tracer";
				count = 4;
			};
			class _xx_rhs_mag_rgd5 {
				magazine = "rhs_mag_rgd5";
				count = 5;
			};
			class _xx_rhs_mag_rdg2_white {
				magazine = "rhs_mag_rdg2_white";
				count = 5;
			};
		};
	};
	class GENFOR_B_SF_AT: GENFOR_B_SF_R {
		displayName = "SF AT Pack";
		class TransportMagazines {
			class _xx_30Rnd_556x45_Stanag {
				magazine = "30Rnd_556x45_Stanag";
				count = 10;
			};
			class _xx_RPG32_F {
				magazine = "RPG32_F";
				count = 3;
			};
			class _xx_RPG32_HE_F {
				magazine = "RPG32_HE_F";
				count = 3;
			};
			class _xx_rhs_mag_rgd5 {
				magazine = "rhs_mag_rgd5";
				count = 5;
			};
			class _xx_rhs_mag_rdg2_white {
				magazine = "rhs_mag_rdg2_white";
				count = 5;
			};
		};
	};
	class SP_Carryall_ATacsFG;
	class GENFOR_B_SF_P: SP_Carryall_ATacsFG {
		scope = 1;
		author = "UKSF";
		displayName = "SF Patrol Pack";
		class TransportMagazines {
			class _xx_rhs_30Rnd_545x39_AK {
				magazine = "rhs_30Rnd_545x39_AK";
				count = 10;
			};
			class _xx_rhs_mag_rgd5 {
				magazine = "rhs_mag_rgd5";
				count = 5;
			};
			class _xx_rhs_mag_rdg2_white {
				magazine = "rhs_mag_rdg2_white";
				count = 5;
			};
		};
	};

	class B_FieldPack_oli;
	class Inegal_B_F: B_FieldPack_oli {
		scope = 1;
		author = "UKSF";
		displayName = "Fusilier Pack";
		class TransportWeapons {};
		class TransportMagazines {
			class _xx_R3F_30Rnd_556x45_FAMAS {
				magazine = "R3F_30Rnd_556x45_FAMAS";
				count = 10;
			};
			class _xx_ClaymoreDirectionalMine_Remote_Mag {
				magazine = "ClaymoreDirectionalMine_Remote_Mag";
				count = 2;
			};
			class _xx_APERSMine_Range_Mag {
				magazine = "APERSMine_Range_Mag";
				count = 2;
			};
		};
		class TransportItems {
			class _xx_ACE_M26_Clacker {
				name = "ACE_M26_Clacker";
				count = 1;
			};
			class _xx_ACE_Cellphone {
				name = "ACE_Cellphone";
				count = 1;
			};
			class _xx_ACE_CableTie {
				name = "ACE_CableTie";
				count = 4;
			};
			class _xx_ACE_DefusalKit {
				name = "ACE_DefusalKit";
				count = 1;
			};
		};
		class TransportBackpacks {};
	};
	class Inegal_B_C: Inegal_B_F {
		scope = 1;
		author = "UKSF";
		displayName = "Commander Pack";
		class TransportMagazines: TransportMagazines {
			class _xx_1Rnd_HE_Grenade_shell {
				magazine = "1Rnd_HE_Grenade_shell";
				count = 10;
			};
			class _xx_R3F_30Rnd_556x45_FAMAS {
				magazine = "R3F_30Rnd_556x45_FAMAS";
				count = 10;
			};
		};
	};
	class B_TacticalPack_oli;
	class Inegal_B_Med: B_TacticalPack_oli {
		scope = 1;
		author = "UKSF";
		displayName = "Medical Pack";
		class TransportWeapons {};
		class TransportMagazines {};
		class TransportItems {
			class _xx_ACE_packingBandage {
				name = "ACE_packingBandage";
				count = 50;
			};
			class _xx_ACE_elasticBandage {
				name = "ACE_elasticBandage";
				count = 50;
			};
			class _xx_ACE_tourniquet {
				name = "ACE_tourniquet";
				count = 5;
			};
			class _xx_ACE_ACE_atropine {
				name = "ACE_atropine";
				count = 6;
			};
			class _xx_ACE_ACE_adenosinee {
				name = "ACE_adenosine";
				count = 6;
			};
			class _xx_ACE_morphine {
				name = "ACE_morphine";
				count = 25;
			};
			class _xx_ACE_epinephrine {
				name = "ACE_epinephrine";
				count = 25;
			};
			class _xx_ACE_bloodIV_500 {
				name = "ACE_bloodIV_500";
				count = 5;
			};
			class _xx_ACE_bloodIV {
				name = "ACE_bloodIV";
				count = 5;
			};
			class _xx_ACE_personalAidKit {
				name = "ACE_personalAidKit";
				count = 1;
			};
			class _xx_ACE_surgicalKit {
				name = "ACE_surgicalKit";
				count = 1;
			};
		};
		class TransportBackpacks {};
	};
	class Inegal_B_MG: Inegal_B_F {
		scope = 1;
		author = "UKSF";
		displayName = "MG Pack";
		class TransportMagazines {
			class _xx_R3F_100Rnd_762x51_MINIMI {
				magazine = "R3F_100Rnd_762x51_MINIMI";
				count = 4;
			};
		};
		class TransportItems {};
	};
	class Inegal_B_Mark: Inegal_B_F {
		scope = 1;
		author = "UKSF";
		displayName = "Marksman Pack";
		class TransportMagazines {
			class _xx_R3F_10Rnd_762x51_FRF2 {
				magazine = "R3F_10Rnd_762x51_FRF2";
				count = 10;
			};
			class _xx_APERSTripMine_Wire_Mag {
				magazine = "APERSTripMine_Wire_Mag";
				count = 2;
			};
			class _xx_APERSMine_Range_Mag {
				magazine = "APERSMine_Range_Mag";
				count = 2;
			};
			class _xx_ClaymoreDirectionalMine_Remote_Mag {
				magazine = "ClaymoreDirectionalMine_Remote_Mag";
				count = 2;
			};
		};
		class TransportItems {
			class _xx_ACE_M26_Clacker {
				name = "ACE_M26_Clacker";
				count = 1;
			};
			class _xx_ACE_EntrenchingTool {
				name = "ACE_EntrenchingTool";
				count = 1;
			};
			class _xx_ACE_DefusalKit {
				name = "ACE_DefusalKit";
				count = 1;
			};
		};
	};
	class Inegal_B_AA: Inegal_B_Med {
		scope = 1;
		author = "UKSF";
		displayName = "AA Pack";
		class TransportMagazines {
			class _xx_R3F_STINGER_mag {
				magazine = "R3F_STINGER_mag";
				count = 2;
			};
		};
		class TransportItems {};
	};
	class Inegal_B_AT_Eryx: Inegal_B_AA {
		scope = 1;
		author = "UKSF";
		displayName = "AT Eryx Pack";
		class TransportMagazines {
			class _xx_R3F_ERYX_Mag {
				magazine = "R3F_ERYX_Mag";
				count = 2;
			};
		};
	};
	class Inegal_B_Sniper: Inegal_B_Mark {
		scope = 1;
		author = "UKSF";
		displayName = "Sniper Pack";
		class TransportMagazines {
			class _xx_R3F_7Rnd_127x99_PGM {
				magazine = "R3F_7Rnd_127x99_PGM";
				count = 10;
			};
			class _xx_ClaymoreDirectionalMine_Remote_Mag {
				magazine = "ClaymoreDirectionalMine_Remote_Mag";
				count = 2;
			};
		};
		class TransportItems {
			class _xx_ACE_M26_Clacker {
				name = "ACE_M26_Clacker";
				count = 1;
			};
			class _xx_ACE_EntrenchingTool {
				name = "ACE_EntrenchingTool";
				count = 1;
			};
			class _xx_ACE_DefusalKit {
				name = "ACE_DefusalKit";
				count = 1;
			};
		};
	};
	class UK3CB_BAF_B_Bergen_MTP_JTAC_H_A;
	class Inegal_B_FAC: UK3CB_BAF_B_Bergen_MTP_JTAC_H_A {
		scope = 1;
		author = "UKSF";
		displayName = "FAC Pack";
		class TransportWeapons {};
		class TransportMagazines {
			class _xx_R3F_30Rnd_556x45_FAMAS {
				magazine = "R3F_30Rnd_556x45_FAMAS";
				count = 10;
			};
			class _xx_ClaymoreDirectionalMine_Remote_Mag {
				magazine = "ClaymoreDirectionalMine_Remote_Mag";
				count = 2;
			};
			class _xx_APERSMine_Range_Mag {
				magazine = "APERSMine_Range_Mag";
				count = 2;
			};
		};
		class TransportItems {
			class _xx_ACE_M26_Clacker {
				name = "ACE_M26_Clacker";
				count = 1;
			};
			class _xx_ACE_Cellphone {
				name = "ACE_Cellphone";
				count = 1;
			};
			class _xx_ACE_CableTie {
				name = "ACE_CableTie";
				count = 4;
			};
			class _xx_ACE_DefusalKit {
				name = "ACE_DefusalKit";
				count = 1;
			};
		};
		class TransportBackpacks {};
	};
	class B_Carryall_cbr;
	class Inegal_B_FDF_B: B_Carryall_cbr {
		scope = 1;
		author = "UKSF";
		displayName = "FDF Brute Pack";
		class TransportWeapons {};
		class TransportMagazines {
			class _xx_R3F_100Rnd_762x51_MINIMI {
				magazine = "R3F_100Rnd_762x51_MINIMI";
				count = 6;
			};
		};
		class TransportItems {};
		class TransportBackpacks {};
	};
	class Inegal_B_FDF_A: Inegal_B_FDF_B {
		scope = 1;
		author = "UKSF";
		displayName = "FDF Arsonist Pack";
		class TransportMagazines {
			class _xx_R3F_AT4CS_Mag {
				magazine = "R3F_AT4CS_Mag";
				count = 4;
			};
		};
	};
	class Inegal_B_D_Specialist: SP_Carryall_ATacsFG {
		scope = 1;
		author = "UKSF";
		displayName = "Diablerie Specialist Pack";
		class TransportWeapons {};
		class TransportMagazines {
			class _xx_ACE_30Rnd_556x45_Stanag_Mk262_mag {
				magazine = "ACE_30Rnd_556x45_Stanag_Mk262_mag";
				count = 16;
			};
			class _xx_ClaymoreDirectionalMine_Remote_Mag {
				magazine = "ClaymoreDirectionalMine_Remote_Mag";
				count = 2;
			};
			class _xx_APERSMine_Range_Mag {
				magazine = "APERSMine_Range_Mag";
				count = 2;
			};
			class _xx_APERSTripMine_Wire_Mag {
				magazine = "APERSTripMine_Wire_Mag";
				count = 2;
			};
			class _xx_APERSBoundingMine_Range_Mag {
				magazine = "APERSBoundingMine_Range_Mag";
				count = 2;
			};
			class _xx_DemoCharge_Remote_Mag {
				magazine = "DemoCharge_Remote_Mag";
				count = 2;
			};
		};
		class TransportItems {
			class _xx_ACE_M26_Clacker {
				name = "ACE_M26_Clacker";
				count = 1;
			};
			class _xx_ACE_Cellphone {
				name = "ACE_Cellphone";
				count = 1;
			};
			class _xx_ACE_CableTie {
				name = "ACE_CableTie";
				count = 4;
			};
			class _xx_ACE_DefusalKit {
				name = "ACE_DefusalKit";
				count = 1;
			};
		};
		class TransportBackpacks {};
	};
	class Inegal_B_D_Commander: Inegal_B_D_Specialist {
		scope = 1;
		author = "UKSF";
		displayName = "Diablerie Commander Pack";
		class TransportMagazines {
			class _xx_ACE_30Rnd_556x45_Stanag_Mk262_mag {
				magazine = "ACE_30Rnd_556x45_Stanag_Mk262_mag";
				count = 10;
			};
			class _xx_1Rnd_HE_Grenade_shell {
				magazine = "1Rnd_HE_Grenade_shell";
				count = 10;
			};
			class _xx_ClaymoreDirectionalMine_Remote_Mag {
				magazine = "ClaymoreDirectionalMine_Remote_Mag";
				count = 2;
			};
			class _xx_APERSMine_Range_Mag {
				magazine = "APERSMine_Range_Mag";
				count = 2;
			};
			class _xx_APERSTripMine_Wire_Mag {
				magazine = "APERSTripMine_Wire_Mag";
				count = 2;
			};
			class _xx_APERSBoundingMine_Range_Mag {
				magazine = "APERSBoundingMine_Range_Mag";
				count = 2;
			};
			class _xx_DemoCharge_Remote_Mag {
				magazine = "DemoCharge_Remote_Mag";
				count = 2;
			};
		};
	};
	class Inegal_B_D_Surgeon: Inegal_B_D_Specialist {
		scope = 1;
		author = "UKSF";
		displayName = "Diablerie Surgeon Pack";
		class TransportMagazines {
			class _xx_ACE_30Rnd_556x45_Stanag_Mk262_mag {
				magazine = "ACE_30Rnd_556x45_Stanag_Mk262_mag";
				count = 16;
			};
		};
		class TransportItems {
			class _xx_ACE_packingBandage {
				name = "ACE_packingBandage";
				count = 30;
			};
			class _xx_ACE_elasticBandage {
				name = "ACE_elasticBandage";
				count = 30;
			};
			class _xx_ACE_tourniquet {
				name = "ACE_tourniquet";
				count = 5;
			};
			class _xx_ACE_ACE_atropine {
				name = "ACE_atropine";
				count = 5;
			};
			class _xx_ACE_ACE_adenosinee {
				name = "ACE_adenosine";
				count = 5;
			};
			class _xx_ACE_morphine {
				name = "ACE_morphine";
				count = 20;
			};
			class _xx_ACE_epinephrine {
				name = "ACE_epinephrine";
				count = 20;
			};
			class _xx_ACE_bloodIV_500 {
				name = "ACE_bloodIV_500";
				count = 5;
			};
			class _xx_ACE_bloodIV {
				name = "ACE_bloodIV";
				count = 5;
			};
			class _xx_ACE_personalAidKit {
				name = "ACE_personalAidKit";
				count = 1;
			};
			class _xx_ACE_surgicalKit {
				name = "ACE_surgicalKit";
				count = 1;
			};
		};
	};
	class Inegal_B_D_Brute: Inegal_B_D_Specialist {
		scope = 1;
		author = "UKSF";
		displayName = "Diablerie Brute Pack";
		class TransportMagazines {
			class _xx_R3F_100Rnd_762x51_MINIMI {
				magazine = "R3F_100Rnd_762x51_MINIMI";
				count = 6;
			};
		};
		class TransportItems {};
	};
	class Inegal_B_D_Sharpshooter: SP_Carryall_ATacsFG {
		scope = 1;
		author = "UKSF";
		displayName = "Diablerie Sharpshooter Pack";
		class TransportWeapons {};
		class TransportMagazines {
			class _xx_ACE_20Rnd_762x51_Mk316_Mod_0_Mag {
				magazine = "ACE_20Rnd_762x51_Mk316_Mod_0_Mag";
				count = 8;
			};
			class _xx_ClaymoreDirectionalMine_Remote_Mag {
				magazine = "ClaymoreDirectionalMine_Remote_Mag";
				count = 2;
			};
			class _xx_APERSMine_Range_Mag {
				magazine = "APERSMine_Range_Mag";
				count = 2;
			};
			class _xx_APERSTripMine_Wire_Mag {
				magazine = "APERSTripMine_Wire_Mag";
				count = 2;
			};
			class _xx_APERSBoundingMine_Range_Mag {
				magazine = "APERSBoundingMine_Range_Mag";
				count = 2;
			};
			class _xx_DemoCharge_Remote_Mag {
				magazine = "DemoCharge_Remote_Mag";
				count = 2;
			};
		};
		class TransportItems {
			class _xx_ACE_M26_Clacker {
				name = "ACE_M26_Clacker";
				count = 1;
			};
			class _xx_ACE_Cellphone {
				name = "ACE_Cellphone";
				count = 1;
			};
			class _xx_ACE_CableTie {
				name = "ACE_CableTie";
				count = 4;
			};
			class _xx_ACE_DefusalKit {
				name = "ACE_DefusalKit";
				count = 1;
			};
		};
		class TransportBackpacks {};
	};
	class Inegal_B_D_Arsonist: Inegal_B_D_Specialist {
		scope = 1;
		author = "UKSF";
		displayName = "Diablerie Arsonist Pack";
		class TransportMagazines {
			class _xx_ACE_30Rnd_556x45_Stanag_Mk262_mag {
				magazine = "ACE_30Rnd_556x45_Stanag_Mk262_mag";
				count = 10;
			};
			class _xx_R3F_AT4CS_Mag {
				magazine = "R3F_AT4CS_Mag";
				count = 4;
			};
		};
		class TransportItems {};
	};
	class Inegal_B_D_Sentinel: Inegal_B_D_Specialist {
		scope = 1;
		author = "UKSF";
		displayName = "Diablerie Sentinel Pack";
		class TransportMagazines {
			class _xx_ACE_30Rnd_556x45_Stanag_Mk262_mag {
				magazine = "ACE_30Rnd_556x45_Stanag_Mk262_mag";
				count = 16;
			};
			class _xx_ClaymoreDirectionalMine_Remote_Mag {
				magazine = "ClaymoreDirectionalMine_Remote_Mag";
				count = 2;
			};
			class _xx_APERSMine_Range_Mag {
				magazine = "APERSMine_Range_Mag";
				count = 2;
			};
			class _xx_APERSTripMine_Wire_Mag {
				magazine = "APERSTripMine_Wire_Mag";
				count = 2;
			};
			class _xx_APERSBoundingMine_Range_Mag {
				magazine = "APERSBoundingMine_Range_Mag";
				count = 2;
			};
			class _xx_DemoCharge_Remote_Mag {
				magazine = "DemoCharge_Remote_Mag";
				count = 2;
			};
		};
		class TransportItems {
			class _xx_ACE_M26_Clacker {
				name = "ACE_M26_Clacker";
				count = 1;
			};
			class _xx_ACE_Cellphone {
				name = "ACE_Cellphone";
				count = 1;
			};
			class _xx_ACE_CableTie {
				name = "ACE_CableTie";
				count = 4;
			};
			class _xx_ACE_DefusalKit {
				name = "ACE_DefusalKit";
				count = 1;
			};
		};
	};
	class Inegal_B_D_Assassin: Inegal_B_D_Specialist {
		scope = 1;
		author = "UKSF";
		displayName = "Diablerie Assassin Pack";
		class TransportMagazines {
			class _xx_R3F_7Rnd_127x99_PEI_PGM {
				magazine = "R3F_7Rnd_127x99_PEI_PGM";
				count = 12;
			};
			class _xx_ClaymoreDirectionalMine_Remote_Mag {
				magazine = "ClaymoreDirectionalMine_Remote_Mag";
				count = 2;
			};
			class _xx_APERSMine_Range_Mag {
				magazine = "APERSMine_Range_Mag";
				count = 2;
			};
			class _xx_APERSTripMine_Wire_Mag {
				magazine = "APERSTripMine_Wire_Mag";
				count = 2;
			};
			class _xx_APERSBoundingMine_Range_Mag {
				magazine = "APERSBoundingMine_Range_Mag";
				count = 2;
			};
			class _xx_DemoCharge_Remote_Mag {
				magazine = "DemoCharge_Remote_Mag";
				count = 2;
			};
		};
		class TransportItems {
			class _xx_ACE_M26_Clacker {
				name = "ACE_M26_Clacker";
				count = 1;
			};
			class _xx_ACE_Cellphone {
				name = "ACE_Cellphone";
				count = 1;
			};
			class _xx_ACE_CableTie {
				name = "ACE_CableTie";
				count = 4;
			};
			class _xx_ACE_DefusalKit {
				name = "ACE_DefusalKit";
				count = 1;
			};
		};
	};
	class Inegal_B_R_C: B_FieldPack_oli {
		scope = 1;
		author = "UKSF";
		displayName = "Recrues Conscript Pack";
		class TransportWeapons {};
		class TransportMagazines {
			class _xx_R3F_30Rnd_556x45_FAMAS {
				magazine = "R3F_30Rnd_556x45_FAMAS";
				count = 4;
			};
			class _xx_R3F_25Rnd_556x45_FAMAS {
				magazine = "R3F_25Rnd_556x45_FAMAS";
				count = 3;
			};
			class _xx_R3F_25Rnd_556x45_TRACER_FAMAS {
				magazine = "R3F_25Rnd_556x45_TRACER_FAMAS";
				count = 2;
			};
		};
		class TransportItems {};
		class TransportBackpacks {};
	};
	class Inegal_B_R_L: Inegal_B_R_C {
		scope = 1;
		author = "UKSF";
		displayName = "Recrues Leader Pack";
		class TransportMagazines {
			class _xx_R3F_30Rnd_556x45_FAMAS {
				magazine = "R3F_30Rnd_556x45_FAMAS";
				count = 8;
			};
			class _xx_1Rnd_HE_Grenade_shell {
				magazine = "1Rnd_HE_Grenade_shell";
				count = 5;
			};
		};
	};
	class Inegal_B_R_R: Inegal_B_R_C {
		scope = 1;
		author = "UKSF";
		displayName = "Recrues Recruit Pack";
		class TransportMagazines {
			class _xx_R3F_25Rnd_556x45_FAMAS {
				magazine = "R3F_25Rnd_556x45_FAMAS";
				count = 5;
			};
			class _xx_R3F_25Rnd_556x45_TRACER_FAMAS {
				magazine = "R3F_25Rnd_556x45_TRACER_FAMAS";
				count = 5;
			};
		};
	};

	class B_Carryall_khk;
	class Laraka_B_PKM: B_Carryall_khk {
		scope = 1;
		author = "UKSF";
		displayName = "PKM/PKP Pack";
		class TransportMagazines {
			class _xx_rhs_100Rnd_762x54mmR_green {
				magazine = "rhs_100Rnd_762x54mmR_green";
				count = 6;
			};
		};
	};
	class Laraka_B_RPG: Laraka_B_PKM {
		displayName = "RPG Pack";
		class TransportMagazines {
			class _xx_rhs_rpg7_PG7VL_mag {
				magazine = "rhs_rpg7_PG7VL_mag";
				count = 8;
			};
		};
	};
	class Laraka_B_AA: Laraka_B_PKM {
		displayName = "AA Pack";
		class TransportMagazines {
			class _xx_rhs_mag_9k32_rocket {
				magazine = "rhs_mag_9k32_rocket";
				count = 6;
			};
		};
	};
};