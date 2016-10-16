class Mode_FullAuto;
class Mode_SemiAuto;
class CfgWeapons {	
	class LMG_Zafir_F;
	class UK3CB_BAF_L7A2: LMG_Zafir_F {
		drySound[] = { "JSRSAPEX_P_Weaponsounds\dry\Navid_dry.ogg", 1, 1, 30 };
		reloadMagazineSound[] = { "JSRSAPEX_P_Weaponsounds\Reload\Navid_reload.ogg", 1.5, 1, 35 };
		changeFiremodeSound[] = { "JSRSAPEX_P_Weaponsounds\Noises\Navid_FireMode.ogg", 1.25, 1, 25 };
		class Single: Mode_SemiAuto {
			sounds[] = { "StandardSound", "SilencedSound" };
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_NAVID_Shot_SoundSet", "JPEX_NAVID_Tail_SoundSet", "JPEX_FRAME_MG_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_CAL308" };
			};
			class SilencedSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_NAVID_Shot_Silenced_SoundSet", "JPEX_NAVID_Tail_Silenced_SoundSet", "JPEX_FRAME_NOISE_LAYER_CAL308" };
			};
		};
		class FullAuto: Mode_FullAuto {
			sounds[] = { "StandardSound", "SilencedSound" };
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_NAVID_Shot_SoundSet", "JPEX_NAVID_Tail_SoundSet", "JPEX_FRAME_MG_REFLECTORS" };
			};
			class SilencedSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_NAVID_Shot_Silenced_SoundSet", "JPEX_NAVID_Tail_Silenced_SoundSet", "JPEX_FRAME_NOISE_LAYER_CAL308" };
			};
		};
		class WeaponSlotsInfo;
	};
	class UK3CB_BAF_L7A2_FIST: UK3CB_BAF_L7A2 {
		drySound[] = { "JSRSAPEX_P_Weaponsounds\dry\Navid_dry.ogg", 1, 1, 30 };
		reloadMagazineSound[] = { "JSRSAPEX_P_Weaponsounds\Reload\Navid_reload.ogg", 1.5, 1, 35 };
		changeFiremodeSound[] = { "JSRSAPEX_P_Weaponsounds\Noises\Navid_FireMode.ogg", 1.25, 1, 25 };
		class Single: Mode_SemiAuto {
			sounds[] = { "StandardSound", "SilencedSound" };
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_NAVID_Shot_SoundSet", "JPEX_NAVID_Tail_SoundSet", "JPEX_FRAME_MG_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_CAL308" };
			};
			class SilencedSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_NAVID_Shot_Silenced_SoundSet", "JPEX_NAVID_Tail_Silenced_SoundSet", "JPEX_FRAME_NOISE_LAYER_CAL308" };
			};
		};
		class FullAuto: Mode_FullAuto {
			sounds[] = { "StandardSound", "SilencedSound" };
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_NAVID_Shot_SoundSet", "JPEX_NAVID_Tail_SoundSet", "JPEX_FRAME_MG_REFLECTORS" };
			};
			class SilencedSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_NAVID_Shot_Silenced_SoundSet", "JPEX_NAVID_Tail_Silenced_SoundSet", "JPEX_FRAME_NOISE_LAYER_CAL308" };
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo {
			mass = 240;
		};
	};
	class UK3CB_BAF_L110A2: LMG_Zafir_F {
		drySound[] = { "JSRSAPEX_P_Weaponsounds\dry\Zafir_dry.ogg", 1, 1, 30 };
		reloadMagazineSound[] = { "JSRSAPEX_P_Weaponsounds\Reload\Zafir_reload.ogg", 1.5, 1, 35 };
		changeFiremodeSound[] = { "JSRSAPEX_P_Weaponsounds\Noises\Zafir_FireMode.ogg", 1.25, 1, 25 };
		class Single: Mode_SemiAuto {
			sounds[] = {
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_ZAFIR_Shot_SoundSet", "JPEX_ZAFIR_Tail_SoundSet", "JPEX_FRAME_MG_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_762MM" };
			};
		};
		class FullAuto: Mode_FullAuto {
			sounds[] = {
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_ZAFIR_Shot_SoundSet", "JPEX_ZAFIR_Tail_SoundSet", "JPEX_FRAME_MG_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_762MM" };
			};
		};
	};

	class arifle_Mk20_plain_F;
	class UGL_F;
	class UK3CB_BAF_L85A2: arifle_Mk20_plain_F {
		class UK3CB_BAF_L123A2: UGL_F {
			magazines[] = { "1Rnd_HE_Grenade_shell","UGL_FlareWhite_F","UGL_FlareGreen_F","UGL_FlareRed_F","UGL_FlareYellow_F","UGL_FlareCIR_F","1Rnd_Smoke_Grenade_shell","1Rnd_SmokeRed_Grenade_shell","1Rnd_SmokeGreen_Grenade_shell","1Rnd_SmokeYellow_Grenade_shell","1Rnd_SmokePurple_Grenade_shell","1Rnd_SmokeBlue_Grenade_shell","1Rnd_SmokeOrange_Grenade_shell","UK3CB_BAF_1Rnd_HEDP_Grenade_shell","ACE_HuntIR_M203" };
		};
		class UK3CB_BAF_L123A3_V2: UGL_F {
			magazines[] = { "1Rnd_HE_Grenade_shell","UGL_FlareWhite_F","UGL_FlareGreen_F","UGL_FlareRed_F","UGL_FlareYellow_F","UGL_FlareCIR_F","1Rnd_Smoke_Grenade_shell","1Rnd_SmokeRed_Grenade_shell","1Rnd_SmokeGreen_Grenade_shell","1Rnd_SmokeYellow_Grenade_shell","1Rnd_SmokePurple_Grenade_shell","1Rnd_SmokeBlue_Grenade_shell","1Rnd_SmokeOrange_Grenade_shell","UK3CB_BAF_1Rnd_HEDP_Grenade_shell","ACE_HuntIR_M203" };
		};
		class EGLM: UGL_F {
			magazines[] = { "1Rnd_HE_Grenade_shell","UGL_FlareWhite_F","UGL_FlareGreen_F","UGL_FlareRed_F","UGL_FlareYellow_F","UGL_FlareCIR_F","1Rnd_Smoke_Grenade_shell","1Rnd_SmokeRed_Grenade_shell","1Rnd_SmokeGreen_Grenade_shell","1Rnd_SmokeYellow_Grenade_shell","1Rnd_SmokePurple_Grenade_shell","1Rnd_SmokeBlue_Grenade_shell","1Rnd_SmokeOrange_Grenade_shell","ACE_HuntIR_M203" };
		};
	};

	class Rifle_Long_Base_F;
	class UK3CB_BAF_L110_Base: Rifle_Long_Base_F {
		drySound[] = { "JSRSAPEX_P_Weaponsounds\dry\Zafir_dry.ogg", 1, 1, 30 };
		reloadMagazineSound[] = { "JSRSAPEX_P_Weaponsounds\Reload\Zafir_reload.ogg", 1.5, 1, 35 };
		changeFiremodeSound[] = { "JSRSAPEX_P_Weaponsounds\Noises\Zafir_FireMode.ogg", 1.25, 1, 25 };
		class Single: Mode_SemiAuto {
			sounds[] = {
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_ZAFIR_Shot_SoundSet", "JPEX_ZAFIR_Tail_SoundSet", "JPEX_FRAME_MG_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_762MM" };
			};
		};
		class FullAuto: Mode_FullAuto {
			sounds[] = {
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_ZAFIR_Shot_SoundSet", "JPEX_ZAFIR_Tail_SoundSet", "JPEX_FRAME_MG_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_762MM" };
			};
		};
	};
	class UK3CB_BAF_L110_556_Base: UK3CB_BAF_L110_Base {
		drySound[] = { "JSRSAPEX_P_Weaponsounds\dry\Zafir_dry.ogg", 1, 1, 30 };
		reloadMagazineSound[] = { "JSRSAPEX_P_Weaponsounds\Reload\Zafir_reload.ogg", 1.5, 1, 35 };
		changeFiremodeSound[] = { "JSRSAPEX_P_Weaponsounds\Noises\Zafir_FireMode.ogg", 1.25, 1, 25 };
		class Single: Mode_SemiAuto {
			sounds[] = {
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_ZAFIR_Shot_SoundSet", "JPEX_ZAFIR_Tail_SoundSet", "JPEX_FRAME_MG_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_762MM" };
			};
		};
		class FullAuto: Mode_FullAuto {
			sounds[] = {
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_ZAFIR_Shot_SoundSet", "JPEX_ZAFIR_Tail_SoundSet", "JPEX_FRAME_MG_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_762MM" };
			};
		};
	};
	class UK3CB_BAF_L110A1: UK3CB_BAF_L110_556_Base {
		drySound[] = { "JSRSAPEX_P_Weaponsounds\dry\Zafir_dry.ogg", 1, 1, 30 };
		reloadMagazineSound[] = { "JSRSAPEX_P_Weaponsounds\Reload\Zafir_reload.ogg", 1.5, 1, 35 };
		changeFiremodeSound[] = { "JSRSAPEX_P_Weaponsounds\Noises\Zafir_FireMode.ogg", 1.25, 1, 25 };
		class Single: Mode_SemiAuto {
			sounds[] = {
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_ZAFIR_Shot_SoundSet", "JPEX_ZAFIR_Tail_SoundSet", "JPEX_FRAME_MG_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_762MM" };
			};
		};
		class FullAuto: Mode_FullAuto {
			sounds[] = {
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_ZAFIR_Shot_SoundSet", "JPEX_ZAFIR_Tail_SoundSet", "JPEX_FRAME_MG_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_762MM" };
			};
		};
	};
	class UK3CB_BAF_L110A2RIS: UK3CB_BAF_L110_556_Base {
		drySound[] = { "JSRSAPEX_P_Weaponsounds\dry\Zafir_dry.ogg", 1, 1, 30 };
		reloadMagazineSound[] = { "JSRSAPEX_P_Weaponsounds\Reload\Zafir_reload.ogg", 1.5, 1, 35 };
		changeFiremodeSound[] = { "JSRSAPEX_P_Weaponsounds\Noises\Zafir_FireMode.ogg", 1.25, 1, 25 };
		class Single: Mode_SemiAuto {
			sounds[] = {
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_ZAFIR_Shot_SoundSet", "JPEX_ZAFIR_Tail_SoundSet", "JPEX_FRAME_MG_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_762MM" };
			};
		};
		class FullAuto: Mode_FullAuto {
			sounds[] = {
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_ZAFIR_Shot_SoundSet", "JPEX_ZAFIR_Tail_SoundSet", "JPEX_FRAME_MG_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_762MM" };
			};
		};
	};
	class UK3CB_BAF_L110A2_FIST: UK3CB_BAF_L110A2RIS {
		drySound[] = { "JSRSAPEX_P_Weaponsounds\dry\Zafir_dry.ogg", 1, 1, 30 };
		reloadMagazineSound[] = { "JSRSAPEX_P_Weaponsounds\Reload\Zafir_reload.ogg", 1.5, 1, 35 };
		changeFiremodeSound[] = { "JSRSAPEX_P_Weaponsounds\Noises\Zafir_FireMode.ogg", 1.25, 1, 25 };
		class Single: Mode_SemiAuto {
			sounds[] = {
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_ZAFIR_Shot_SoundSet", "JPEX_ZAFIR_Tail_SoundSet", "JPEX_FRAME_MG_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_762MM" };
			};
		};
		class FullAuto: Mode_FullAuto {
			sounds[] = {
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_ZAFIR_Shot_SoundSet", "JPEX_ZAFIR_Tail_SoundSet", "JPEX_FRAME_MG_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_762MM" };
			};
		};
	};
	class UK3CB_BAF_L110A3: UK3CB_BAF_L110_556_Base {
		drySound[] = { "JSRSAPEX_P_Weaponsounds\dry\Zafir_dry.ogg", 1, 1, 30 };
		reloadMagazineSound[] = { "JSRSAPEX_P_Weaponsounds\Reload\Zafir_reload.ogg", 1.5, 1, 35 };
		changeFiremodeSound[] = { "JSRSAPEX_P_Weaponsounds\Noises\Zafir_FireMode.ogg", 1.25, 1, 25 };
		class Single: Mode_SemiAuto {
			sounds[] = {
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_ZAFIR_Shot_SoundSet", "JPEX_ZAFIR_Tail_SoundSet", "JPEX_FRAME_MG_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_762MM" };
			};
		};
		class FullAuto: Mode_FullAuto {
			sounds[] = {
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_ZAFIR_Shot_SoundSet", "JPEX_ZAFIR_Tail_SoundSet", "JPEX_FRAME_MG_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_762MM" };
			};
		};
	};
	class UK3CB_BAF_L110_762_Base: UK3CB_BAF_L110_Base {
		drySound[] = { "JSRSAPEX_P_Weaponsounds\dry\Navid_dry.ogg", 1, 1, 30 };
		reloadMagazineSound[] = { "JSRSAPEX_P_Weaponsounds\Reload\Navid_reload.ogg", 1.5, 1, 35 };
		changeFiremodeSound[] = { "JSRSAPEX_P_Weaponsounds\Noises\Navid_FireMode.ogg", 1.25, 1, 25 };
		class Single: Mode_SemiAuto {
			sounds[] = { "StandardSound" };
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_NAVID_Shot_SoundSet", "JPEX_NAVID_Tail_SoundSet", "JPEX_FRAME_MG_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_CAL308" };
			};
		};
		class FullAuto: Mode_FullAuto {
			sounds[] = { "StandardSound" };
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_NAVID_Shot_SoundSet", "JPEX_NAVID_Tail_SoundSet", "JPEX_FRAME_MG_REFLECTORS" };
			};
		};
	};
	class UK3CB_BAF_L110_762: UK3CB_BAF_L110_762_Base {
		drySound[] = { "JSRSAPEX_P_Weaponsounds\dry\Navid_dry.ogg", 1, 1, 30 };
		reloadMagazineSound[] = { "JSRSAPEX_P_Weaponsounds\Reload\Navid_reload.ogg", 1.5, 1, 35 };
		changeFiremodeSound[] = { "JSRSAPEX_P_Weaponsounds\Noises\Navid_FireMode.ogg", 1.25, 1, 25 };
		class Single: Mode_SemiAuto {
			sounds[] = { "StandardSound" };
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_NAVID_Shot_SoundSet", "JPEX_NAVID_Tail_SoundSet", "JPEX_FRAME_MG_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_CAL308" };
			};
		};
		class FullAuto: Mode_FullAuto {
			sounds[] = { "StandardSound" };
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_NAVID_Shot_SoundSet", "JPEX_NAVID_Tail_SoundSet", "JPEX_FRAME_MG_REFLECTORS" };
			};
		};
	};

	class Rifle_Base_F;
	class rhs_weap_ak74m_Base_F: Rifle_Base_F {
		drySound[] = { "JSRSAPEX_P_Weaponsounds\dry\AK12_dry.ogg", 1, 1, 30 };
		reloadMagazineSound[] = { "JSRSAPEX_P_Weaponsounds\Reload\AK12_reload.ogg", 1.5, 1, 35 };
		changeFiremodeSound[] = { "JSRSAPEX_P_Weaponsounds\Noises\AK12_FireMode.ogg", 1.25, 1, 25 };
		class Single: Mode_SemiAuto {
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_AK12_Shot_SoundSet", "JPEX_AK12_Tail_SoundSet", "JPEX_FRAME_RIFLE_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_762MM" };
			};
			class SilencedSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_AK12_Shot_Silenced_SoundSet", "JPEX_AK12_Tail_Silenced_SoundSet", "JPEX_FRAME_NOISE_LAYER_762MM" };
			};
		};
		class FullAuto: Mode_FullAuto {
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_AK12_Shot_SoundSet", "JPEX_AK12_Tail_SoundSet", "JPEX_FRAME_RIFLE_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_762MM" };
			};
			class SilencedSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_AK12_Shot_Silenced_SoundSet", "JPEX_AK12_Tail_Silenced_SoundSet", "JPEX_FRAME_NOISE_LAYER_762MM" };
			};
		};
	};
	class rhs_weap_akm: rhs_weap_ak74m {
		drySound[] = { "JSRSAPEX_P_Weaponsounds\dry\AKM_dry.ogg", 1, 1, 30 };
		reloadMagazineSound[] = { "JSRSAPEX_P_Weaponsounds\Reload\AKM_reload.ogg", 1.5, 1, 35 };
		changeFiremodeSound[] = { "JSRSAPEX_P_Weaponsounds\Noises\AKM_FireMode.ogg", 1.25, 1, 25 };
		class Single: Mode_SemiAuto {
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_AKM_Shot_SoundSet", "JPEX_AKM_Tail_SoundSet", "JPEX_FRAME_RIFLE_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_762MM" };
			};
		};
		class FullAuto: Mode_FullAuto {
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_AKM_Shot_SoundSet", "JPEX_AKM_Tail_SoundSet", "JPEX_FRAME_RIFLE_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_762MM" };
			};
		};
	};
	class Rifle_Long_Base_F: Rifle_Base_F {};
	class rhs_pkp_base: Rifle_Long_Base_F {
		drySound[] = { "JSRSAPEX_P_Weaponsounds\dry\Spmg_dry.ogg", 1, 1, 30 };
		reloadMagazineSound[] = { "JSRSAPEX_P_Weaponsounds\Reload\Spmg_reload.ogg", 1.5, 1, 35 };
		changeFiremodeSound[] = { "JSRSAPEX_P_Weaponsounds\Noises\Spmg_FireMode.ogg", 1.25, 1, 25 };
		class FullAuto: Mode_FullAuto {
			sounds[] = { "StandardSound", "SilencedSound" };
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_SPMG_Shot_SoundSet", "JPEX_SPMG_Tail_SoundSet", "JPEX_FRAME_MG_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_CAL308" };
			};
			class SilencedSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_SPMG_Shot_Silenced_SoundSet", "JPEX_SPMG_Tail_Silenced_SoundSet", "JPEX_FRAME_NOISE_LAYER_CAL308" };
			};
		};
		class Single: Mode_SemiAuto {
			sounds[] = { "StandardSound", "SilencedSound" };
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_SPMG_Shot_SoundSet", "JPEX_SPMG_Tail_SoundSet", "JPEX_FRAME_MG_REFLECTORS" };
			};
			class SilencedSound: BaseSoundModeType {
				soundSetShot[] = { "JPEX_SPMG_Shot_Silenced_SoundSet", "JPEX_SPMG_Tail_Silenced_SoundSet", "JPEX_FRAME_NOISE_LAYER_CAL308" };
			};
		};
	};

	class R3F_Famas_F1 : Rifle_Base_F {
		class Single : Mode_SemiAuto {
			class BaseSoundModeType;
			class StandardSound : BaseSoundModeType {
				soundSetShot[] = { "UKSF_FAMAS_Shot_SoundSet", "JPEX_MX_Tail_SoundSet", "JPEX_FRAME_RIFLE_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_556MM" };
			};
			class SilencedSound : BaseSoundModeType {
				soundSetShot[] = { "UKSF_FAMAS_Shot_Silenced_SoundSet", "JPEX_MX_Tail_Silenced_SoundSet", "JPEX_FRAME_NOISE_LAYER_556MM" };
			};
		};
		class Burst : Mode_Burst {
			class BaseSoundModeType;
			class StandardSound : BaseSoundModeType {
				soundSetShot[] = { "UKSF_FAMAS_Shot_SoundSet", "JPEX_MX_Tail_SoundSet", "JPEX_FRAME_RIFLE_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_556MM" };
			};
			class SilencedSound : BaseSoundModeType {
				soundSetShot[] = { "UKSF_FAMAS_Shot_Silenced_SoundSet", "JPEX_MX_Tail_Silenced_SoundSet", "JPEX_FRAME_NOISE_LAYER_556MM" };
			};
		};
		class FullAuto : Mode_FullAuto {
			class BaseSoundModeType;
			class StandardSound : BaseSoundModeType {
				soundSetShot[] = { "UKSF_FAMAS_Shot_SoundSet", "JPEX_MX_Tail_SoundSet", "JPEX_FRAME_RIFLE_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_556MM" };
			};
			class SilencedSound : BaseSoundModeType {
				soundSetShot[] = { "UKSF_FAMAS_Shot_Silenced_SoundSet", "JPEX_MX_Tail_Silenced_SoundSet", "JPEX_FRAME_NOISE_LAYER_556MM" };
			};
		};
	};
	class R3F_Famas_G2 : R3F_Famas_F1 {
		class Single : Mode_SemiAuto {
			class BaseSoundModeType;
			class StandardSound : BaseSoundModeType {
				soundSetShot[] = { "UKSF_FAMAS_Shot_SoundSet", "JPEX_MX_Tail_SoundSet", "JPEX_FRAME_RIFLE_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_556MM" };
			};
			class SilencedSound : BaseSoundModeType {
				soundSetShot[] = { "UKSF_FAMAS_Shot_Silenced_SoundSet", "JPEX_MX_Tail_Silenced_SoundSet", "JPEX_FRAME_NOISE_LAYER_556MM" };
			};
		};
		class Burst : Mode_Burst {
			class BaseSoundModeType;
			class StandardSound : BaseSoundModeType {
				soundSetShot[] = { "UKSF_FAMAS_Shot_SoundSet", "JPEX_MX_Tail_SoundSet", "JPEX_FRAME_RIFLE_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_556MM" };
			};
			class SilencedSound : BaseSoundModeType {
				soundSetShot[] = { "UKSF_FAMAS_Shot_Silenced_SoundSet", "JPEX_MX_Tail_Silenced_SoundSet", "JPEX_FRAME_NOISE_LAYER_556MM" };
			};
		};
		class FullAuto : Mode_FullAuto {
			class BaseSoundModeType;
			class StandardSound : BaseSoundModeType {
				soundSetShot[] = { "UKSF_FAMAS_Shot_SoundSet", "JPEX_MX_Tail_SoundSet", "JPEX_FRAME_RIFLE_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_556MM" };
			};
			class SilencedSound : BaseSoundModeType {
				soundSetShot[] = { "UKSF_FAMAS_Shot_Silenced_SoundSet", "JPEX_MX_Tail_Silenced_SoundSet", "JPEX_FRAME_NOISE_LAYER_556MM" };
			};
		};
	};
	class R3F_FRF2 : Rifle_Base_F {
		class Single : Mode_SemiAuto {
			class BaseSoundModeType;
			class StandardSound : BaseSoundModeType {
				soundSetShot[] = { "UKSF_FRF2_Shot_SoundSet", "JPEX_MK14_Tail_SoundSet", "JPEX_FRAME_RIFLE_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_762MM" };
			};
			class SilencedSound : BaseSoundModeType {
				soundSetShot[] = { "UKSF_FRF2_Shot_Silenced_SoundSet", "JPEX_MK14_Tail_Silenced_SoundSet", "JPEX_FRAME_NOISE_LAYER_762MM" };
			};
		};
	};
	class R3F_PGM_Hecate_II : Rifle_Base_F {
		class Single : Mode_SemiAuto {
			class BaseSoundModeType;
			class StandardSound : BaseSoundModeType {
				soundSetShot[] = { "UKSF_PGM_Shot_SoundSet", "JPEX_GM6_Tail_SoundSet", "JPEX_FRAME_SNIPER_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_cal308" };
			};
		};
	};
	class R3F_Minimi : Rifle_Base_F {
		class manual : Mode_FullAuto {
			class BaseSoundModeType;
			class StandardSound : BaseSoundModeType {
				soundSetShot[] = { "UKSF_Minimi_Shot_SoundSet", "JPEX_ZAFIR_Tail_SoundSet", "JPEX_FRAME_MG_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_762MM" };
			};
		};
	};
	class R3F_Minimi_HG : R3F_Minimi {
		class manual : Mode_FullAuto {
			class BaseSoundModeType;
			class StandardSound : BaseSoundModeType {
				soundSetShot[] = { "UKSF_Minimi_Shot_SoundSet", "JPEX_ZAFIR_Tail_SoundSet", "JPEX_FRAME_MG_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_762MM" };
			};
		};
	};
	class R3F_Minimi_762 : R3F_Minimi {
		class manual : Mode_FullAuto {
			class BaseSoundModeType;
			class StandardSound : BaseSoundModeType {
				soundSetShot[] = { "UKSF_Minimi762_Shot_SoundSet", "JPEX_NAVID_Tail_SoundSet", "JPEX_FRAME_MG_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_CAL308" };
			};
		};
	};
	class R3F_Minimi_762_HG : R3F_Minimi_762 {
		class manual : Mode_FullAuto {
			class BaseSoundModeType;
			class StandardSound : BaseSoundModeType {
				soundSetShot[] = { "UKSF_Minimi762_Shot_SoundSet", "JPEX_NAVID_Tail_SoundSet", "JPEX_FRAME_MG_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_CAL308" };
			};
		};
	};
};