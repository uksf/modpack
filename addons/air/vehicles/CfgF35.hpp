class CUP_F35B_base : Plane {
    envelope[] = { 0, 1.75, 5.9, 7, 9.8, 10.3, 10.5, 10.9, 9.2, 7.8, 5, 3.8, 0.5, 0 };
    aileronSensitivity = 1.2;
    armor = 90;
    damageResistance = 0.004;
    attenuationEffectType = "PlaneAttenuation";
    soundEngineOnInt[] = { "A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_01\B_PLANE_FIGHTER_01_engine_start_int", 1, 1 };
    soundEngineOnExt[] = { "A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_01\B_PLANE_FIGHTER_01_engine_start_ext", 5, 1, 500 };
    soundEngineOffInt[] = { "A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_01\B_PLANE_FIGHTER_01_engine_shut_int", 1, 1 };
    soundEngineOffExt[] = { "A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_01\B_PLANE_FIGHTER_01_engine_shut_ext", 4, 1, 400 };
    class sounds {
        soundSets[] = {
            "Plane_Fighter_01_EngineLowExt_SoundSet",
            "Plane_Fighter_01_EngineHighExt_SoundSet",
            "Plane_Fighter_01_ForsageExt_SoundSet",
            "Plane_Fighter_01_WindNoiseExt_SoundSet",
            "Plane_Fighter_01_EngineExt_Dist_Front_SoundSet",
            "Plane_Fighter_01_EngineExt_Middle_SoundSet",
            "Plane_Fighter_01_EngineExt_Dist_Rear_SoundSet",
            "Plane_Fighter_01_EngineLowInt_SoundSet",
            "Plane_Fighter_01_EngineHighInt_SoundSet",
            "Plane_Fighter_01_ForsageInt_SoundSet",
            "Plane_Fighter_01_WindNoiseInt_SoundSet",
            "Plane_Fighter_01_VelocityInt_SoundSet"
        };
    };
    class EjectionSystem {
        EjectionSeatEnabled = 1;
        EjectionDual = 0;
        EjectionSeatClass = "uksf_f35_plane_ejection_seat";
        CanopyClass = "Plane_Fighter_01_Canopy_F";
        EjectionSeatHideAnim = "ejection_seat_hide";
        EjectionSeatRailAnim = "ejection_seat_motion";
        CanopyHideAnim = "canopy_hide";
        EjectionSeatPos = "eject_pos";
        CanopyPos = "eject_pos";
        EjectionSoundExt = "Plane_Fighter_01_ejection_ext_sound";
        EjectionSoundInt = "Plane_Fighter_01_ejection_in_sound";
        EjectionParachute = "Steerable_Parachute_F";
        EjectionSeatForce = 50;
        CanopyForce = 30;
    };
};
class CUP_F35B_dynamic_base : CUP_F35B_base {};
class CUP_B_F35B_USMC : CUP_F35B_dynamic_base {};
class CUP_B_F35B_BAF : CUP_B_F35B_USMC {
    scope = 0;
    scopeCurator = 0;
};
class CUP_B_F35B_AA_USMC : CUP_F35B_base {};
class CUP_B_F35B_AA_BAF : CUP_B_F35B_AA_USMC {
    scope = 0;
    scopeCurator = 0;
};
class CUP_B_F35B_CAS_USMC : CUP_F35B_base {};
class CUP_B_F35B_CAS_BAF : CUP_B_F35B_CAS_USMC {
    scope = 0;
    scopeCurator = 0;
};
class CUP_B_F35B_LGB_USMC : CUP_F35B_base {};
class CUP_B_F35B_LGB_BAF : CUP_B_F35B_LGB_USMC {
    scope = 0;
    scopeCurator = 0;
};
class CUP_B_F35B_Stealth_USMC;
class CUP_B_F35B_Stealth_BAF: CUP_B_F35B_Stealth_USMC {
    scope = 0;
    scopeCurator = 0;
};
