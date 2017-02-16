class Mode_FullAuto;
class Mode_Burst;
class Mode_SemiAuto;
class CfgWeapons {
    class GM6_base_F;
    class srifle_GM6_F: GM6_base_F {
        class Single;
    };
    /*class UK3CB_BAF_L135A1: srifle_GM6_F {
        class Single: Single {
            class BaseSoundModeType {};
            class StandardSound: BaseSoundModeType {
                soundSetShot[] = { "DS_sniper1_crackling_SoundSet","DS_lrr_Shot_SoundSet","DS_sniper1_Tail_SoundSet" };
            };
        };
    };*/
    /*class LMG_Zafir_F;
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
    };*/
};
