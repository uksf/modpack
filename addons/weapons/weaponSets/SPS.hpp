class SPS_AI_AXMC338_27_PB_F : SPS_AI_AXMC_base_F {
    magazines[] = {
        "SPS_AI_AXMC_338_Mag",
        "SPS_AI_AXMC_338_300gr_Berger_Mag",
        "SPS_AI_AXMC_338_300gr_Berger_Mag_Tracer",
        "SPS_AI_AXMC_338_300gr_Berger_Mag_IR",
        "SPS_AI_AXMC_338_300gr_Scenar_Mag",
        "SPS_AI_AXMC_338_300gr_Scenar_Tracer_Mag",
        "SPS_AI_AXMC_338_300gr_Scenar_IR_Mag",
        "SPS_AI_AXMC_338_300gr_HPBT_Mag",
        "SPS_AI_AXMC_338_250gr_Naturalis_Mag",
        "SPS_AI_AXMC_338_250gr_Naturalis_Tracer_Mag",
        "SPS_AI_AXMC_338_250gr_Naturalis_IR_Mag",
        "SPS_AI_AXMC_338_API526_Mag",
        "SPS_AI_AXMC_338_HAPI_Mag"
    };
    class Single : Mode_SemiAuto {
        sounds[] = { "StandardSound", "SilencedSound" };
        class BaseSoundModeType {};
        class StandardSound : BaseSoundModeType {
            soundSetShot[] = {
                "FRAME_CALIBER_12x7MM",
                "CUP_sniper1_crackling_SoundSet",
                "CUP_BoltActions_Shot_SoundSet",
                "CUP_sniper1_Tail_SoundSet"
            };
        };
        class SilencedSound : BaseSoundModeType {
            soundSetShot[] = {
                "FRAME_CALIBER_12x7MM_SILENCED",
                "CUP_M2010_ShotSD_SoundSet",
                "CUP_rifle1_SD_Tail_SoundSet"
            };
        };
    };
    ace_overheating_closedBolt = 1;
};
