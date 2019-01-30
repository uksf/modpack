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
        EjectionSeatClass = "USAF_F35A_ejection_seat";
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
class CUP_B_F35B_Stealth_USMC_OCimport_02;
class CFP_B_GBARMY_F35B_Lightning_II_Stealth_WDL_01: CUP_B_F35B_Stealth_USMC_OCimport_02 {
    scope = 0;
    scopeCurator = 0;
};
class uksf_f35_plane_raf;
class USAF_F35A : uksf_f35_plane_raf {};
// class B_Plane_Fighter_01_F : Plane_Fighter_01_Base_F {
//     class pilotCamera;
//     class MFD;
// };
// class USAF_F35A : B_Plane_Fighter_01_F {
//     faction = "CUP_B_GB";
//     scopeCurator = 2;
//     crew = "UKSF_B_Pilot_617";
//     typicalCargo[] = { "UKSF_B_Pilot_617" };
//     acceleration = 250;
//     ace_cookoff_cookoffSelections[] = { "palivo" };
//     class pilotCamera : pilotCamera {
//         class OpticsIn {
//             class Wide {
//                 opticsDisplayName = "WFOV";
//                 initAngleX = 0;
//                 minAngleX = 0;
//                 maxAngleX = 0;
//                 initAngleY = 0;
//                 minAngleY = 0;
//                 maxAngleY = 0;
//                 initFov = "(75 / 120)";
//                 minFov = "(75 / 120)";
//                 maxFov = "(75 / 120)";
//                 directionStabilized = 1;
//                 visionMode[] = { "Normal", "NVG", "Ti" };
//                 thermalMode[] = { 0, 1 };
//                 gunnerOpticsModel = "\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
//                 opticsPPEffects[] = { "OpticsCHAbera2", "OpticsBlur2" };
//             };
//             class Medium : Wide {
//                 opticsDisplayName = "MFOV";
//                 initFov = "(14.4 / 120)";
//                 minFov = "(14.4 / 120)";
//                 maxFov = "(14.4 / 120)";
//                 gunnerOpticsModel = "\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_medium_F.p3d";
//             };
//             class Narrow : Wide {
//                 opticsDisplayName = "NFOV";
//                 initFov = "(4.8 / 120)";
//                 minFov = "(4.8 / 120)";
//                 maxFov = "(4.8 / 120)";
//                 gunnerOpticsModel = "\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
//             };
//             class VNarrow : Wide {
//                 opticsDisplayName = "VNFOV";
//                 initFov = "(2 / 120)";
//                 minFov = "(2 / 120)";
//                 maxFov = "(2 / 120)";
//                 gunnerOpticsModel = "\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
//             };
//         };
//     };
//     unitInfoType = "RscUnitInfoAirPlaneNoSpeed";
//     unitInfoTypeLite = "RscUnitInfoAirPlaneNoSpeed";
//     #include "MFDJet.hpp"
//     INVENTORY_AIRCRAFT
// };
