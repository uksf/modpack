class asdg_OpticRail;
class asdg_OpticRail1913: asdg_OpticRail {
	linkProxy = "\A3\data_f\proxies\weapon_slots\TOP";
	displayName = "$STR_A3_CowsSlot0";
	class compatibleItems {
		optic_Nightstalker = 1;
		optic_tws = 1;
		optic_tws_mg = 1;
		optic_NVS = 1;
		optic_SOS = 1;
		optic_MRCO = 1;
		optic_Arco = 1;
		optic_aco = 1;
		optic_ACO_grn = 1;
		optic_aco_smg = 1;
		optic_ACO_grn_smg = 1;
		optic_hamr = 1;
		optic_Holosight = 1;
		optic_Holosight_smg = 1;
		optic_DMS = 1;
		optic_LRPS = 1;
		optic_AMS = 1;
		optic_AMS_khk = 1;
		optic_AMS_snd = 1;
		optic_KHS_blk = 1;
		optic_KHS_hex = 1;
		optic_KHS_old = 1;
		optic_KHS_tan = 1;
		UK3CB_BAF_TA31F = 1;
		UK3CB_BAF_TA31F_3D = 1;
		UK3CB_BAF_TA31F_Hornbill = 1;
		UK3CB_BAF_TA31F_Hornbill_3D = 1;
		UK3CB_BAF_TA648 = 1;
		UK3CB_BAF_TA648_308 = 1;
	};
};
class asdg_OpticRail1913_long: asdg_OpticRail1913 {};
class rhs_western_rifle_scopes_slot_long: asdg_OpticRail1913_long {};
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class SlotInfo;
class CowsSlot;
class MuzzleSlot;
class PointerSlot;
class UnderBarrelSlot;
class CfgWeapons {
	class ItemCore;
	class Uniform_Base;
	class UniformItem;
	class HeadgearItem;
	class VestItem;

	class U_I_CombatUniform;
	class U_I_CombatUniform_shortsleeve;
	class U_B_HeliPilotCoveralls;
	class UK3CB_BAF_U_CombatUniform_MTP_RM: U_I_CombatUniform {
		scope = 1;
	};
	class UK3CB_BAF_U_CombatUniform_MTP_ShortSleeve_RM: U_I_CombatUniform_shortsleeve {
		scope = 0;
	};
	class UK3CB_BAF_U_CombatUniform_MTP_TShirt_RM: U_I_CombatUniform {
		scope = 0;
	};
	class UK3CB_BAF_U_CombatUniform_MTP: U_I_CombatUniform {
		scope = 0;
	};
	class UK3CB_BAF_U_CombatUniform_MTP_ShortSleeve: U_I_CombatUniform_shortsleeve {
		scope = 1;
	};
	class UK3CB_BAF_U_HeliPilotCoveralls_RN: U_B_HeliPilotCoveralls {
		scope = 0;
	};
	class UK3CB_BAF_U_CombatUniform_MTP_Ghillie_RM: Uniform_Base {
		scope = 0;
	};
	class UK3CB_BAF_U_CombatUniform_MTP_TShirt: UK3CB_BAF_U_CombatUniform_MTP_TShirt_RM {
		scope = 2;
		author = "UKSF";
		displayName = "Combat T-Shirt MTP";
		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "UK3CB_BAF_Soldier_MTP_Tshirt_base";
			containerClass = "Supply40";
			mass = 40;
		};
	};
	class UK3CB_BAF_U_CombatUniform_MTP_1Para: U_I_CombatUniform {
		scope = 2;
		author = "UKSF";
		DLC = "UK3CB_BAF_Equipment";
		displayName = "Combat Uniform MTP 1Para";
		descriptionShort = "BAF Combat Uniform MTP<br/>by www.3commandobrigade.com";
		picture = QPATHTOF(UI\icon_uniform_mtp_1para_ca.paa);
		hiddenSelections[] = { "Camo" };
		hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_1para.paa) };
		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "UK3CB_BAF_Soldier_MTP_1para_LongSleeve_base";
			containerClass = "Supply40";
			mass = 40;
		};
	};
	class UK3CB_BAF_U_CombatUniform_MTP_1Para_ShortSleeve: U_I_CombatUniform_shortsleeve {
		scope = 2;
		author = "UKSF";
		DLC = "UK3CB_BAF_Equipment";
		displayName = "Combat Uniform MTP 1Para Rolled";
		descriptionShort = "BAF Combat Uniform MTP<br>Sleeves Rolled-Up<br/>by www.3commandobrigade.com";
		picture = QPATHTOF(UI\icon_uniform_mtp_1para_rolledup_ca.paa);
		hiddenSelections[] = { "Camo" };
		hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_1para.paa) };
		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "UK3CB_BAF_Soldier_MTP_1para_ShortSleeve_base";
			containerClass = "Supply40";
			mass = 40;
		};
	};
	class UK3CB_BAF_U_CombatUniform_MTP_CSMR: U_I_CombatUniform {
		scope = 2;
		author = "UKSF";
		DLC = "UK3CB_BAF_Equipment";
		displayName = "Combat Uniform MTP CSMR";
		descriptionShort = "BAF Combat Uniform MTP<br/>by www.3commandobrigade.com";
		picture = QPATHTOF(UI\icon_uniform_mtp_csmr_ca.paa);
		hiddenSelections[] = { "Camo" };
		hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_csmr.paa) };
		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "UK3CB_BAF_Soldier_MTP_CSMR_LongSleeve_base";
			containerClass = "Supply40";
			mass = 40;
		};
	};
	class UK3CB_BAF_U_CombatUniform_MTP_CSMR_ShortSleeve: U_I_CombatUniform_shortsleeve {
		scope = 2;
		author = "UKSF";
		DLC = "UK3CB_BAF_Equipment";
		displayName = "Combat Uniform MTP CSMR Rolled";
		descriptionShort = "BAF Combat Uniform MTP<br>Sleeves Rolled-Up<br/>by www.3commandobrigade.com";
		picture = QPATHTOF(UI\icon_uniform_mtp_csmr_rolledup_ca.paa);
		hiddenSelections[] = { "Camo" };
		hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_csmr.paa) };
		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "UK3CB_BAF_Soldier_MTP_CSMR_ShortSleeve_base";
			containerClass = "Supply40";
			mass = 40;
		};
	};
	class UK3CB_BAF_U_CombatUniform_MTP_Path: U_I_CombatUniform {
		scope = 2;
		author = "UKSF";
		DLC = "UK3CB_BAF_Equipment";
		displayName = "Combat Uniform MTP Pathfinder";
		descriptionShort = "BAF Combat Uniform MTP<br/>by www.3commandobrigade.com";
		picture = QPATHTOF(UI\icon_uniform_mtp_path_ca.paa);
		hiddenSelections[] = { "Camo" };
		hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_path.paa) };
		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "UK3CB_BAF_Soldier_MTP_Path_LongSleeve_base";
			containerClass = "Supply40";
			mass = 40;
		};
	};
	class UK3CB_BAF_U_CombatUniform_MTP_Path_ShortSleeve: U_I_CombatUniform_shortsleeve {
		scope = 2;
		author = "UKSF";
		DLC = "UK3CB_BAF_Equipment";
		displayName = "Combat Uniform MTP Pathfinder Rolled";
		descriptionShort = "BAF Combat Uniform MTP<br>Sleeves Rolled-Up<br/>by www.3commandobrigade.com";
		picture = QPATHTOF(UI\icon_uniform_mtp_path_rolledup_ca.paa);
		hiddenSelections[] = { "Camo" };
		hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_path.paa) };
		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "UK3CB_BAF_Soldier_MTP_Path_ShortSleeve_base";
			containerClass = "Supply40";
			mass = 40;
		};
	};
	class UK3CB_BAF_U_CombatUniform_MTP_Sig: U_I_CombatUniform {
		scope = 2;
		author = "UKSF";
		DLC = "UK3CB_BAF_Equipment";
		displayName = "Combat Uniform MTP Signals";
		descriptionShort = "BAF Combat Uniform MTP<br/>by www.3commandobrigade.com";
		picture = QPATHTOF(UI\icon_uniform_mtp_sig_ca.paa);
		hiddenSelections[] = { "Camo" };
		hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_sig.paa) };
		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "UK3CB_BAF_Soldier_MTP_Sig_LongSleeve_base";
			containerClass = "Supply40";
			mass = 40;
		};
	};
	class UK3CB_BAF_U_CombatUniform_MTP_Sig_ShortSleeve: U_I_CombatUniform_shortsleeve {
		scope = 2;
		author = "UKSF";
		DLC = "UK3CB_BAF_Equipment";
		displayName = "Combat Uniform MTP Signals Rolled";
		descriptionShort = "BAF Combat Uniform MTP<br>Sleeves Rolled-Up<br/>by www.3commandobrigade.com";
		picture = QPATHTOF(UI\icon_uniform_mtp_sig_rolledup_ca.paa);
		hiddenSelections[] = { "Camo" };
		hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\mtp_uk_sig.paa) };
		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "UK3CB_BAF_Soldier_MTP_Sig_ShortSleeve_base";
			containerClass = "Supply40";
			mass = 40;
		};
	};
	class UK3CB_BAF_U_HeliPilotCoveralls_RAF: U_B_HeliPilotCoveralls {
		scope = 2;
		author = "UKSF";
		displayName = "Heli Pilot Flight Suit RAF [BAF]";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_civilian_F.p3d";
		hiddenSelections[] = { "Camo" };
		hiddenSelectionsTextures[] = { QPATHTOF(data\uniforms\helipilot_coveralls_raf.paa) };
		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "UK3CB_BAF_HeliPilot_RAF_base";
			containerClass = "Supply40";
			mass = 60;
		};
	};
	class UKSF_U_ATC: Uniform_Base {
		scope = 2;
		author = "UKSF";
		displayName = "ATC Blues";
		picture = QPATHTOF(UI\icon_uniform_atc_ca.paa);
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
		class ItemInfo: UniformItem {
			uniformModel = "-";
			uniformClass = "UKSF_Soldier_ATC_base";
			containerClass = "Supply100";
			mass = 20;
		};
	};

	class H_Beret_02;
	class UKSF_H_RAFBeret: H_Beret_02 {
		scope = 2;
		author = "UKSF";
		displayName = "RAF Beret";
		picture = QPATHTOF(UI\icon_beret_raf_ca.paa);
		model = "\A3\characters_f_epb\BLUFOR\headgear_beret02";
		hiddenSelections[] = { "Camo" };
		hiddenSelectionsTextures[] = { QPATHTOF(data\hats\RAF_Beret.paa) };
		hiddenSelectionsMaterials[] = { QPATHTOF(data\hats\Beret.rvmat) };
		class ItemInfo: HeadgearItem {
			mass = 5;
			uniformmodel = "\A3\characters_f_epb\BLUFOR\headgear_beret02";
			modelSides[] = { 6 };
			class HitpointsProtectionInfo {
				class Head {
					hitpointName = "HitHead";
					armor = 0;
					passThrough = 0.5;
				};
			};
			hiddenSelectionsTextures[] = { QPATHTOF(data\hats\RAF_Beret.paa) };
			hiddenSelections[] = { "Camo" };
		};
	};
	class UKSF_H_AACBeret: H_Beret_02 {
		scope = 2;
		author = "UKSF";
		displayName = "AAC Beret";
		picture = QPATHTOF(UI\icon_beret_aac_ca.paa);
		model = "\A3\characters_f_epb\BLUFOR\headgear_beret02";
		hiddenSelections[] = { "Camo" };
		hiddenSelectionsTextures[] = { QPATHTOF(data\hats\AAC_Beret.paa) };
		hiddenSelectionsMaterials[] = { QPATHTOF(data\hats\Beret.rvmat) };
		class ItemInfo: HeadgearItem {
			mass = 5;
			uniformmodel = "\A3\characters_f_epb\BLUFOR\headgear_beret02";
			modelSides[] = { 6 };
			class HitpointsProtectionInfo {
				class Head {
					hitpointName = "HitHead";
					armor = 0;
					passThrough = 0.5;
				};
			};
			hiddenSelectionsTextures[] = { QPATHTOF(data\hats\AAC_Beret.paa) };
			hiddenSelections[] = { "Camo" };
		};
	};

	class V_TacVest_oli;
	class UKSF_V_Pilot: V_TacVest_oli {
		scope = 2;
		author = "UKSF";
		displayName = "UK Pilot vest";
		picture = QPATHTOF(UI\icon_v_tacvest_khk_ca.paa);
		hiddenSelections[] = { "camo" };
		hiddenSelectionsTextures[] = { QPATHTOF(data\vests\tacticalvest_olive_co.paa) };
		class ItemInfo: VestItem {
			uniformModel = "A3\Characters_F\Common\equip_tacticalvest";
			containerClass = "Supply200";
			mass = 40;
			armor = 20;
			passThrough = 1;
			hiddenSelections[] = { "camo" };
		};
	};
	class Vest_Camo_Base: ItemCore {
		class ItemInfo;
	};
	class UKSF_V_Flight: Vest_Camo_Base {
		scope = 2;
		author = "UKSF";
		displayName = "Pilot Survival Vest";
		picture = QPATHTOF(UI\pilotvest_pic_ca.paa);
		model = QPATHTOF(data\vests\FIR_pilot_vest.p3d);
		class ItemInfo: ItemInfo {
			uniformModel = QPATHTOF(data\vests\FIR_pilot_vest.p3d);
			containerClass = "Supply200";
			mass = 40;
			armor = 40;
			passThrough = 0.4;
		};
	};

	class InventoryOpticsItem_Base_F;
	class UK3CB_BAF_SpecterLDS_Dot;
	class UK3CB_BAF_SpecterLDS: ItemCore {
		class ItemInfo: InventoryOpticsItem_Base_F {
			class OpticsModes {
				class UK3CB_BAF_LDS {
					visionMode[] = {};
				};
			};
		};
	};
	class UK3CB_BAF_SpecterLDS_3D: UK3CB_BAF_SpecterLDS {
		scope = 2;
		scopeCUrator = 2;
		class ItemInfo: InventoryOpticsItem_Base_F {
			allowedSlots[] = {801,701,901};
			mass = 4;
			mountAction = "MountOptic";
			muzzleEnd = "konec hlavne";
			muzzlePos = "usti hlavne";
			optics = 1;
			scope = 0;
			type = 201;
			unmountAction = "DismountOptic";
			modelOptics = "UK3CB_BAF_Weapons\addons\UK3CB_BAF_Weapons_Accessories\Elcan_Optic.p3d";
			class OpticsModes {
				class UK3CB_BAF_LDS {
					cameraDir = "";
					discreteDistance[] = {300};
					discreteDistanceInitIndex = 0;
					distanceZoomMax = 300;
					distanceZoomMin = 300;
					memoryPointCamera = "opticView";
					opticsFlare = 1;
					opticsID = 1;
					opticsPPEffects[] = {"OpticsCHAbera5","OpticsBlur5"};
					opticsZoomInit = 0.09;
					opticsZoomMax = 0.09;
					opticsZoomMin = 0.09;
					visionMode[] = {};
					useModelOptics = 0;
					opticsDisablePeripherialVision = 0;
				};
			};
		};
	};
	class UK3CB_BAF_SpecterLDS_Dot_3D: UK3CB_BAF_SpecterLDS_Dot {
		scope = 2;
		scopeCUrator = 2;
		model = "UK3CB_BAF_Weapons\addons\UK3CB_BAF_Weapons_Accessories\Elcan_Reflex.p3d";
		modelOptics = "";
		class ItemInfo: InventoryOpticsItem_Base_F {
			allowedSlots[] = {801,701,901};
			mass = 4;
			mountAction = "MountOptic";
			muzzleEnd = "konec hlavne";
			muzzlePos = "usti hlavne";
			optics = 1;
			scope = 0;
			type = 201;
			unmountAction = "DismountOptic";
			modelOptics = "UK3CB_BAF_Weapons\addons\UK3CB_BAF_Weapons_Accessories\Elcan_Optic.p3d";
			class OpticsModes {
				class UK3CB_BAF_LDS {
					cameraDir = "";
					discreteDistance[] = {300};
					discreteDistanceInitIndex = 0;
					distanceZoomMax = 300;
					distanceZoomMin = 300;
					memoryPointCamera = "opticView";
					opticsFlare = 1;
					opticsID = 1;
					opticsPPEffects[] = {"OpticsCHAbera5","OpticsBlur5"};
					opticsZoomInit = 0.09;
					opticsZoomMax = 0.09;
					opticsZoomMin = 0.09;
					visionMode[] = {};
					useModelOptics = 0;
					opticsDisablePeripherialVision = 0;
				};
				class UK3CB_BAF_LDS_Top {
					cameraDir = "";
					discreteDistance[] = {100};
					discreteDistanceInitIndex = 0;
					distanceZoomMax = 100;
					distanceZoomMin = 100;
					memoryPointCamera = "eye";
					opticsFlare = 1;
					opticsID = 2;
					opticsPPEffects[] = {"OpticsCHAbera5","OpticsBlur5"};
					opticsZoomInit = 0.75;
					opticsZoomMax = 1.1;
					opticsZoomMin = 0.375;
					visionMode[] = {};
					useModelOptics = 0;
					opticsDisablePeripherialVision = 0;
				};
			};
		};
	};
	class UK3CB_BAF_TA31F: ItemCore {
		class ItemInfo: InventoryOpticsItem_Base_F {
			class OpticsModes {
				class UK3CB_BAF_ACOG {
					visionMode[] = {};
				};
			};
		};
	};
	class UK3CB_BAF_TA648: ItemCore {
		class ItemInfo: InventoryOpticsItem_Base_F {
			class OpticsModes {
				class ACOG_scope {
					visionMode[] = {};
				};
			};
		};
	};
	class UK3CB_BAF_SUSAT: ItemCore {
		class ItemInfo: InventoryOpticsItem_Base_F {
			class OpticsModes {
				class UK3CB_BAF_SUSAT {
					visionMode[] = {};
				};
			};
		};
	};
	class optic_LRPS: ItemCore {
		class ItemInfo: InventoryOpticsItem_Base_F {
			class OpticsModes {
				class Snip {
					visionMode[] = {};
				};
			};
		};
	};

	class ACE_NVG_Wide;
	class ACE_NVG_Pilot: ACE_NVG_Wide {
		scope = 2;
		scopeArsenal = 2;
		author = "UKSF";
		displayName = "Pilot NVG";
		ACE_NightVision_grain = 0;
		ACE_NightVision_blur = 0;
		ACE_NightVision_radBlur = 0;
	};

	class UK3CB_BAF_L119_Base;
	class UK3CB_BAF_L119A1: UK3CB_BAF_L119_Base {
		scope = 0;
	};
	class UK3CB_BAF_L119A1_CQB: UK3CB_BAF_L119_Base {
		scope = 0;
	};
	class UK3CB_BAF_L119A1_FG: UK3CB_BAF_L119_Base {
		scope = 0;
	};
	class UK3CB_BAF_L119A1_UKUGL: UK3CB_BAF_L119_Base {
		scope = 0;
	};

	class LMG_Zafir_F;
	class UK3CB_BAF_L7A2: LMG_Zafir_F {
		magazines[] = {
			"UK3CB_BAF_762_200Rnd_T",
			"UK3CB_BAF_762_200Rnd",
			"UK3CB_BAF_762_200Rnd_Blank",
			"UK3CB_BAF_762_100Rnd_T",
			"UK3CB_BAF_762_100Rnd",
			"UK3CB_BAF_762_100Rnd_Blank",
			"UK3CB_BAF_762_100Rnd_EL",
			"UK3CB_BAF_762_100Rnd_T_EL",
			"UK3CB_BAF_762_200Rnd_EL",
			"UK3CB_BAF_762_200Rnd_T_EL"
		};
	};
	class LMG_RCWS;
	class UK3CB_BAF_L7A2_veh: LMG_RCWS {
		magazines[] = {
			"UK3CB_BAF_762_200Rnd_T",
			"UK3CB_BAF_762_200Rnd",
			"UK3CB_BAF_762_200Rnd_Blank",
			"UK3CB_BAF_762_100Rnd_T",
			"UK3CB_BAF_762_100Rnd",
			"UK3CB_BAF_762_100Rnd_Blank",
			"UK3CB_BAF_762_100Rnd_EL",
			"UK3CB_BAF_762_100Rnd_T_EL",
			"UK3CB_BAF_762_200Rnd_EL",
			"UK3CB_BAF_762_200Rnd_T_EL"
		};
	};

	class LRR_base_F;
	class srifle_LRR_F: LRR_base_F {
		class WeaponSlotsInfo;
	};
	class arifle_mas_lee: srifle_LRR_F {
		author = "UKSF";
		displayname = "Lee-Enfield No4";
		model = "\mas_us_rifle\mas_LeeEnfield";
		reloadAction = "GestureReloadLRR";
		handanim[] = { "OFP2_ManSkeleton","\mas_us_rifle\Anim\LeeEnfield.rtm" };
		magazines[] = { "5Rnd_mas_762x51_Stanag","5Rnd_mas_762x51_T_Stanag" };
		picture = "\mas_us_rifle\ui\gear_lee_x_ca.paa";
		descriptionshort = "Rifle<br />Caliber: 7.62x51 mm";
		maxZeroing = 1200;
		hasBipod = 0;
		class Library {
			libtextdesc = "The Lee Enfield bolt action, magazine fed, repeating rifle was the main firearm used by the military forces of the British Empire and Commonwealth during the first half of the 20th century. It was the British Armys standard rifle from its official adoption in 1895 until 1957. It remained in widespread British service until the early mid 1960s and the 7,62 mm L42 sniper variant remained in service until the 1990s. As a standard issue infantry rifle, it is still found in service in the armed forces of some Commonwealth nations. During the 1960s, the British Government and the Ministry of Defence converted a number of Lee Enfield No4 rifles to 7,62�51mm NATO as part of a programme to retain the Lee Enfield as a reserve weapon.";
		};
		modes[] = { "Single" };
		drySound[] = { "JSRSAPEX_P_Weaponsounds\dry\emr_dry", 0.56234097, 1, 50 };
		reloadMagazineSound[] = { "JSRSAPEX_P_Weaponsounds\Reload\emr_reload", 0.96234101, 1, 100 };
		changeFiremodeSound[] = { "JSRSAPEX_P_Weaponsounds\Noises\emr_FireMode", 0.56234097, 1, 50 };
		class Single: Mode_SemiAuto {
			dispersion = 0.00018;
			soundContinuous = 0;
			reloadTime = 1.2;
			recoil = "recoil_single_gm6";
			recoilProne = "recoil_single_prone_gm6";
			sounds[] = { "StandardSound","SilencedSound" };
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_EMR_Shot_SoundSet", "JPEX_EMR_Tail_SoundSet", "JPEX_FRAME_RIFLE_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_762MM" };
			};
			class SilencedSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_EMR_Shot_Silenced_SoundSet", "JPEX_EMR_Tail_Silenced_SoundSet", "JPEX_FRAME_NOISE_LAYER_762MM" };
			};
			minRange = 2;
			minRangeProbab = 0.1;
			midRange = 250;
			midRangeProbab = 0.69999999;
			maxRange = 350;
			maxRangeProbab = 0.050000001;
			aiRateOfFire = 3;
			aiRateOfFireDistance = 500;
		};
		class WeaponSlotsInfo: WeaponSlotsInfo {
			class MuzzleSlot: MuzzleSlot {
				linkProxy = "\A3\data_f\proxies\weapon_slots\MUZZLE";
				iconPicture = "\mas_us_rifle\ui\attachment_muzzle.paa";
				iconPosition[] = { 0,0.40000001 };
				iconPinpoint = "Center";
				compatibleItems[] = { "muzzle_snds_B" };
				iconScale = 0.2;
			};
			class CowsSlot: CowsSlot {
				linkProxy = "\A3\data_f\proxies\weapon_slots\TOP";
				iconPicture = "\mas_us_rifle\ui\attachment_top.paa";
				iconPosition[] = { 0.5,0.40000001 };
				iconPinpoint = "Bottom";
				compatibleitems[] = {
					"optic_Arco",
					"optic_aco",
					"optic_ACO_grn",
					"optic_hamr",
					"optic_Holosight",
					"optic_SOS",
					"optic_MRCO",
					"optic_Aco_smg",
					"optic_Holosight_smg",
					"optic_NVS",
					"optic_Nightstalker",
					"optic_tws",
					"optic_DMS",
					"optic_LRPS",
					"optic_AMS_khk",
					"optic_AMS_snd",
					"optic_AMS",
					"optic_KHS_blk",
					"optic_KHS_hex",
					"optic_KHS_old",
					"optic_KHS_tan",
					"UK3CB_BAF_SpecterLDS",
					"UK3CB_BAF_SpecterLDS_3D",
					"UK3CB_BAF_SpecterLDS_Dot",
					"UK3CB_BAF_SpecterLDS_Dot_3D",
					"UK3CB_BAF_Eotech",
					"UK3CB_BAF_SUSAT",
					"UK3CB_BAF_SUSAT_3D",
					"UK3CB_BAF_TA31F",
					"UK3CB_BAF_TA31F_3D",
					"UK3CB_BAF_TA31F_Hornbill",
					"UK3CB_BAF_TA31F_Hornbill_3D",
					"UK3CB_BAF_TA648",
					"UK3CB_BAF_TA648_308"
				};
				iconScale = 0.2;
			};
			class PointerSlot: PointerSlot {
				linkProxy = "\A3\data_f\proxies\weapon_slots\SIDE";
				iconPicture = "\mas_us_rifle\ui\attachment_side.paa";
				iconPinpoint = "Center";
				iconPosition[] = { 0.2,0.40000001 };
				compatibleitems[] = { "acc_flashlight","acc_pointer_IR" };
				iconScale = 0.2;
			};
			class UnderBarrelSlot: UnderBarrelSlot {
				linkProxy = "\A3\Data_f_Mark\proxies\weapon_slots\UNDERBARREL";
				iconPicture = "\mas_us_rifle\ui\attachment_bipod.paa";
				iconPinpoint = "Center";
				iconPosition[] = { 0.2,0.80000001 };
				compatibleitems[] = { "bipod_01_F_snd","bipod_01_F_blk","bipod_01_F_mtp","bipod_02_F_blk","bipod_02_F_tan","bipod_02_F_hex","bipod_03_F_blk","bipod_03_F_oli" };
				iconScale = 0.2;
			};
			mass = 80;
		};
	};
	class arifle_mas_fal: arifle_mas_lee {
		author = "UKSF";
		_generalMacro = "arifle_mas_fal";
		displayname = "FN FAL";
		model = "\mas_us_rifle\mas_fnfal";
		reloadAction = "GestureReloadSMG_02";
		handanim[] = { "OFP2_ManSkeleton","\mas_us_rifle\Anim\Handanim_fal.rtm" };
		magazines[] = { "20Rnd_762x51_Mag" };
		picture = "\mas_us_rifle\ui\gear_fal_x_ca.paa";
		descriptionshort = "Assault Rifle<br />Caliber: 7.62x51 mm";
		class Library {
			libtextdesc = "The Fusil Automatique Leger or FAL is a self loading, selective fire battle rifle produced by the Belgian armaments manufacturer Fabrique Nationale de Herstal. During the Cold War it was adopted by many North Atlantic Treaty Organization NATO countries, with the notable exception of the United States. It is one of the most widely used rifles in history, having been used by more than 90 countries. The FAL was predominantly chambered for the 7.62�51mm NATO round, and because of its prevalence and widespread use among the armed forces of many NATO countries during the Cold War it was nicknamed The right arm of the Free World. A British Commonwealth derivative of the FN FAL has been produced under licence as the L1A1 Self Loading Rifle.";
		};
		recoil = "recoil_dmr_05";
		modes[] = {
			"Single",
			"FullAuto"
		};
		class Single: Mode_SemiAuto {
			sounds[] = { "StandardSound","SilencedSound" };
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_EMR_Shot_SoundSet", "JPEX_EMR_Tail_SoundSet", "JPEX_FRAME_RIFLE_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_762MM" };
			};
			class SilencedSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_EMR_Shot_Silenced_SoundSet", "JPEX_EMR_Tail_Silenced_SoundSet", "JPEX_FRAME_NOISE_LAYER_762MM" };
			};
			reloadTime = 0.075000003;
			dispersion = 0.00116;
			recoil = "recoil_single_ebr";
			recoilProne = "recoil_single_prone_ebr";
			minRange = 2;
			minRangeProbab = 0.5;
			midRange = 200;
			midRangeProbab = 0.69999999;
			maxRange = 400;
			maxRangeProbab = 0.30000001;
		};
		class FullAuto: Mode_FullAuto {
			sounds[] = { "StandardSound","SilencedSound" };
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_EMR_Shot_SoundSet", "JPEX_EMR_Tail_SoundSet", "JPEX_FRAME_RIFLE_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_762MM" };
			};
			class SilencedSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_EMR_Shot_Silenced_SoundSet", "JPEX_EMR_Tail_Silenced_SoundSet", "JPEX_FRAME_NOISE_LAYER_762MM" };
			};
			reloadTime = 0.085000001;
			dispersion = 0.00116;
			recoil = "recoil_auto_ebr";
			recoilProne = "recoil_auto_prone_ebr";
			minRange = 0;
			minRangeProbab = 0.89999998;
			midRange = 15;
			midRangeProbab = 0.69999999;
			maxRange = 30;
			maxRangeProbab = 0.1;
			aiRateOfFire = 1e-006;
		};
		class WeaponSlotsInfo: WeaponSlotsInfo {
			class MuzzleSlot: MuzzleSlot {
				linkProxy = "\A3\data_f\proxies\weapon_slots\MUZZLE";
				iconPicture = "\mas_us_rifle\ui\attachment_muzzle.paa";
				iconPosition[] = { 0,0.40000001 };
				iconPinpoint = "Center";
				compatibleItems[] = { "muzzle_snds_H" };
				iconScale = 0.2;
			};
			class CowsSlot: CowsSlot {
				linkProxy = "\A3\data_f\proxies\weapon_slots\TOP";
				iconPicture = "\mas_us_rifle\ui\attachment_top2.paa";
				iconPosition[] = { 0.5,0.30000001 };
				iconPinpoint = "Bottom";
				compatibleitems[] = {
					"optic_Arco",
					"optic_aco",
					"optic_ACO_grn",
					"optic_hamr",
					"optic_Holosight",
					"optic_SOS",
					"optic_MRCO",
					"optic_Aco_smg",
					"optic_Holosight_smg",
					"optic_NVS",
					"optic_Nightstalker",
					"optic_tws",
					"optic_DMS",
					"optic_LRPS",
					"optic_AMS_khk",
					"optic_AMS_snd",
					"optic_AMS",
					"optic_KHS_blk",
					"optic_KHS_hex",
					"optic_KHS_old",
					"optic_KHS_tan",
					"UK3CB_BAF_SpecterLDS",
					"UK3CB_BAF_SpecterLDS_3D",
					"UK3CB_BAF_SpecterLDS_Dot",
					"UK3CB_BAF_SpecterLDS_Dot_3D",
					"UK3CB_BAF_Eotech",
					"UK3CB_BAF_SUSAT",
					"UK3CB_BAF_SUSAT_3D",
					"UK3CB_BAF_TA31F",
					"UK3CB_BAF_TA31F_3D",
					"UK3CB_BAF_TA31F_Hornbill",
					"UK3CB_BAF_TA31F_Hornbill_3D",
					"UK3CB_BAF_TA648",
					"UK3CB_BAF_TA648_308"
				};
				iconScale = 0.2;
			};
			class PointerSlot: PointerSlot {
				linkProxy = "\A3\data_f\proxies\weapon_slots\SIDE";
				iconPicture = "\mas_us_rifle\ui\attachment_side.paa";
				iconPinpoint = "Center";
				iconPosition[] = { 0.2,0.40000001 };
				compatibleitems[] = { "acc_flashlight","acc_pointer_IR" };
				iconScale = 0.2;
			};
			class UnderBarrelSlot: UnderBarrelSlot {
				linkProxy = "\A3\Data_f_Mark\proxies\weapon_slots\UNDERBARREL";
				iconPicture = "\mas_us_rifle\ui\attachment_bipod.paa";
				iconPinpoint = "Center";
				iconPosition[] = { 0.2,0.80000001 };
				compatibleitems[] = { "bipod_01_F_snd","bipod_01_F_blk","bipod_01_F_mtp","bipod_02_F_blk","bipod_02_F_tan","bipod_02_F_hex","bipod_03_F_blk","bipod_03_F_oli" };
				iconScale = 0.2;
			};
			mass = 80;
		};
	};	

	class rhs_weap_ak74m_camo_npz;
	class rhs_weap_ak74m_camo_npz_acog: rhs_weap_ak74m_camo_npz {
		class LinkedItems {
			class LinkedItemsOptic {
				slot = "CowsSlot";
				item = "UK3CB_BAF_TA31F_3D";
			};
		};
	};
	class rhs_weap_ak74m_gp25_npz;
	class rhs_weap_ak74m_gp25_npz_acog: rhs_weap_ak74m_gp25_npz {
		class LinkedItems {
			class LinkedItemsOptic {
				slot = "CowsSlot";
				item = "UK3CB_BAF_TA31F_3D";
			};
		};
	};
	class arifle_mas_m4;
	class arifle_mas_m4_acog: arifle_mas_m4 {
		class LinkedItems {
			class LinkedItemsOptic {
				slot = "CowsSlot";
				item = "UK3CB_BAF_TA31F_3D";
			};
			class LinkedItemsAcc {
				slot = "PointerSlot";
				item = "acc_flashlight";
			};
		};
	};
	class arifle_mas_m4c;
	class arifle_mas_m4c_holo: arifle_mas_m4c {
		class LinkedItems {
			class LinkedItemsOptic {
				slot = "CowsSlot";
				item = "optic_Holosight";
			};
			class LinkedItemsAcc {
				slot = "PointerSlot";
				item = "acc_flashlight";
			};
			class LinkedItemsMuzzle {
				slot = "MuzzleSlot";
				item = "muzzle_snds_M";
			};
		};
	};
	class rhs_weap_ak105_npz;
	class rhs_weap_ak105_npz_acog: rhs_weap_ak105_npz {
		class LinkedItems {
			class LinkedItemsOptic {
				slot = "CowsSlot";
				item = "UK3CB_BAF_TA31F_3D";
			};
		};
	};
	class arifle_mas_m4_gl;
	class arifle_mas_m4_gl_acog: arifle_mas_m4_gl {
		class LinkedItems {
			class LinkedItemsOptic {
				slot = "CowsSlot";
				item = "UK3CB_BAF_TA31F_3D";
			};
			class LinkedItemsAcc {
				slot = "PointerSlot";
				item = "acc_flashlight";
			};
		};
	};
	class rhs_weap_ak103_npz;
	class rhs_weap_ak103_npz_dmr: rhs_weap_ak103_npz {
		class LinkedItems {
			class LinkedItemsOptic {
				slot = "CowsSlot";
				item = "optic_DMS";
			};
		};
	};
	class srifle_DMR_06_camo_F;
	class srifle_DMR_06_camo_F_dms : srifle_DMR_06_camo_F {
		class LinkedItems {
			class LinkedItemsOptic {
				slot = "CowsSlot";
				item = "optic_DMS";
			};
		};
	};
	class launch_O_Titan_F;
	class rhs_weap_strela: launch_O_Titan_F {
		scope = 0;
	};
	class Launcher_Base_F;
	class rhs_weap_rpg7: Launcher_Base_F {
		minRange = 10;
		midRange = 400;
		maxRange = 900;
	};

	class R3F_Famas_G2_HG;
	class R3F_Famas_G2_HG_Aimpoint: R3F_Famas_G2_HG {
		class LinkedItems {
			class LinkedItemsOptic {
				slot = "CowsSlot";
				item = "R3F_AIMPOINT";
			};
		};
	};
	class R3F_Famas_G2_M203;
	class R3F_Famas_G2_M203_Aimpoint: R3F_Famas_G2_M203 {
		class LinkedItems {
			class LinkedItemsOptic {
				slot = "CowsSlot";
				item = "R3F_AIMPOINT";
			};
		};
	};
	class arifle_SPAR_01_GL_blk_F;
	class arifle_SPAR_01_GL_blk_F_erco: arifle_SPAR_01_GL_blk_F {
		class LinkedItems {
			class LinkedItemsOptic {
				slot = "CowsSlot";
				item = "optic_ERCO_blk_F";
			};
		};
	};
	class R3F_Famas_G2;
	class R3F_Famas_G2_Aimpoint: R3F_Famas_G2 {
		class LinkedItems {
			class LinkedItemsOptic {
				slot = "CowsSlot";
				item = "R3F_AIMPOINT";
			};
		};
	};
	class R3F_Minimi_762;
	class R3F_Minimi_762_Aimpoint: R3F_Minimi_762 {
		class LinkedItems {
			class LinkedItemsOptic {
				slot = "CowsSlot";
				item = "R3F_AIMPOINT";
			};
		};
	};
	class R3F_FRF2_DES;
	class R3F_FRF2_DES_Zeiss: R3F_FRF2_DES {
		class LinkedItems {
			class LinkedItemsOptic {
				slot = "CowsSlot";
				item = "R3F_ZEISS_DES";
			};
		};
	};
	class R3F_PGM_Hecate_II_DES;
	class R3F_PGM_Hecate_II_DES_Zeiss: R3F_PGM_Hecate_II_DES {
		class LinkedItems {
			class LinkedItemsOptic {
				slot = "CowsSlot";
				item = "R3F_ZEISS_DES";
			};
		};
	};
	class arifle_SPAR_01_blk_F;
	class arifle_SPAR_01_blk_F_eotech_lamp_bipod: arifle_SPAR_01_blk_F {
		class LinkedItems {
			class LinkedItemsOptic {
				slot = "CowsSlot";
				item = "UK3CB_BAF_Eotech";
			};
			class LinkedItemsAcc {
				slot = "PointerSlot";
				item = "acc_flashlight";
			};
			class LinkedItemsUnder {
				slot = "UnderBarrelSlot";
				item = "bipod_01_F_blk";
			};
		};
	};
	class arifle_SPAR_01_GL_blk_F_eotech: arifle_SPAR_01_GL_blk_F {
		class LinkedItems {
			class LinkedItemsOptic {
				slot = "CowsSlot";
				item = "UK3CB_BAF_Eotech";
			};
			class LinkedItemsAcc {
				slot = "PointerSlot";
				item = "acc_flashlight";
			};
		};
	};
	class arifle_SPAR_03_blk_F;
	class arifle_SPAR_03_blk_F_dms_bipod: arifle_SPAR_03_blk_F {
		class LinkedItems {
			class LinkedItemsOptic {
				slot = "CowsSlot";
				item = "optic_DMS";
			};
			class LinkedItemsUnder {
				slot = "UnderBarrelSlot";
				item = "bipod_01_F_blk";
			};
		};
	};
	class arifle_SPAR_01_blk_F_erco_laser_bipod_suppressor: arifle_SPAR_01_blk_F {
		class LinkedItems {
			class LinkedItemsOptic {
				slot = "CowsSlot";
				item = "optic_ERCO_blk_F";
			};
			class LinkedItemsAcc {
				slot = "PointerSlot";
				item = "acc_pointer_IR";
			};
			class LinkedItemsMuzzle {
				slot = "MuzzleSlot";
				item = "muzzle_snds_M";
			};
			class LinkedItemsUnder {
				slot = "UnderBarrelSlot";
				item = "bipod_01_F_blk";
			};
		};
	};
	class arifle_SPAR_01_GL_blk_F_erco_laser_suppressor: arifle_SPAR_01_GL_blk_F {
		class LinkedItems {
			class LinkedItemsOptic {
				slot = "CowsSlot";
				item = "optic_ERCO_blk_F";
			};
			class LinkedItemsAcc {
				slot = "PointerSlot";
				item = "acc_pointer_IR";
			};
			class LinkedItemsMuzzle {
				slot = "MuzzleSlot";
				item = "muzzle_snds_M";
			};
		};
	};
	class arifle_SPAR_03_blk_F_dms_bipod_suppressor_laser: arifle_SPAR_03_blk_F {
		class LinkedItems {
			class LinkedItemsOptic {
				slot = "CowsSlot";
				item = "optic_DMS";
			};
			class LinkedItemsAcc {
				slot = "PointerSlot";
				item = "acc_pointer_IR";
			};
			class LinkedItemsMuzzle {
				slot = "MuzzleSlot";
				item = "muzzle_snds_B";
			};
			class LinkedItemsUnder {
				slot = "UnderBarrelSlot";
				item = "bipod_01_F_blk";
			};
		};
	};
	class R3F_PGM_Hecate_II_POLY;
	class R3F_PGM_Hecate_II_POLY_J10: R3F_PGM_Hecate_II_POLY {
		class LinkedItems {
			class LinkedItemsOptic {
				slot = "CowsSlot";
				item = "R3F_J10_MILDOT_DES";
			};
		};
	};
	class R3F_Famas_F1_M203;
	class R3F_Famas_F1_M203_Eotech: R3F_Famas_F1_M203 {
		class LinkedItems {
			class LinkedItemsOptic {
				slot = "CowsSlot";
				item = "R3F_EOTECH";
			};
		};
	};
	class R3F_Famas_F1_HG;
	class R3F_Famas_F1_HG_Eotech: R3F_Famas_F1_HG {
		class LinkedItems {
			class LinkedItemsOptic {
				slot = "CowsSlot";
				item = "R3F_EOTECH";
			};
		};
	};

	class R3F_MP5A5;
	class R3F_MP5A5_Eotech: R3F_MP5A5 {
		class LinkedItems {
			class LinkedItemsOptic {
				slot = "CowsSlot";
				item = "R3F_EOTECH";
			};
		};
	};

	class Vest_NoCamo_Base;
	class V_PlateCarrier1_rgr: Vest_NoCamo_Base {
		class ItemInfo;
	};
	class SP_Modular2_Tan: V_PlateCarrier1_rgr {
		class ItemInfo: ItemInfo {
			containerClass = "Supply100";
			mass = 80;
			hiddenSelections[] = {
				"camo"
			};
			class HitpointsProtectionInfo {
				class Neck {
					hitpointName = "HitNeck";
					armor = 25;
					passThrough = 0.25;
				};
				class Arms {
					hitpointName = "HitArms";
					armor = 25;
					passThrough = 0.25;
				};
				class Chest {
					hitpointName = "HitChest";
					armor = 45;
					passThrough = 0.1;
				};
				class Diaphragm {
					hitpointName = "HitDiaphragm";
					armor = 45;
					passThrough = 0.1;
				};
				class Abdomen {
					hitpointName = "HitAbdomen";
					armor = 45;
					passThrough = 0.1;
				};
				class Body {
					hitpointName = "HitBody";
					passThrough = 0.1;
				};
			};
		};
	};

	class SP_ECHHelmet_ATacsFG1: ItemCore {
		scope = 0;
		class ItemInfo;
	};
	class Inegal_Diablerie_Helmet: SP_ECHHelmet_ATacsFG1 {
		scope = 2;
		class ItemInfo: ItemInfo {
			mass = 50;
			modelSides[] = {0,1,2,3};
			class HitpointsProtectionInfo {
				class Head {
					hitpointName = "HitHead";
					armor = 25;
					passThrough = 0.1;
				};
			};
		};
	};
};