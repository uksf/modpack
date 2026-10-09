class Sound;
class MBG_SndSrc_DoorOpen : Sound {};
class ffaa_casa_af_base;
class land_ffaa_casa_urbana_8 : ffaa_casa_af_base {
    ladders[] = {};
};
class land_ffaa_casa_hangar_2 : ffaa_casa_af_base {
    ladders[] = {};
};
class LandVehicle;
class StaticWeapon : LandVehicle {
    class Turrets;
};
class StaticMGWeapon : StaticWeapon {
    class Turrets : Turrets {
        delete ViewOptics;
    };
};
class Car;
class Car_F : Car {
    class AnimationSources;
};
class CUP_M151_base : Car_F {
    aggregateReflectors[] = { { "LightCarHeadL01", "LightCarHeadR01" } };
};
class B_Soldier_F;
class B_CombatUniform_sage_worn : B_Soldier_F {
    uniformClass = "U_B_CombatUniform_sage_worn";
};
class B_CombatUniform_wdl_worn : B_Soldier_F {
    uniformClass = "U_B_CombatUniform_wdl_worn";
};
class C_Uniform_ArtTShirt_01_base_F;
class C_Uniform_ArtTShirt_01_isntArt : C_Uniform_ArtTShirt_01_base_F {
    uniformClass = "U_C_ArtTShirt_01_isntArt";
};
class UK3CB_BAF_Soldier_Smock_Base;
class UK3CB_BAF_Soldier_Smock_CW_DPM_Base : UK3CB_BAF_Soldier_Smock_Base {
    uniformClass = "UK3CB_BAF_U_Smock_CW_DPM";
};
class Helicopter_Base_H : Helicopter_Base_F {
    class AnimationSources : AnimationSources {
        class HitEngine2 {
            hitpoint = "HitEngine2";
        };
    };
};
class CUP_Tigr_Base : Car_F {
    class AnimationSources : AnimationSources {
        class HitGlass10 {
            hitpoint = "HitGlass10";
        };
    };
};
class CUP_Tigr_SPM_Base : CUP_Tigr_Base {
    class AnimationSources : AnimationSources {
        class HitGlass10 {
            hitpoint = "HitGlass10";
        };
    };
};
class CUP_Tigr_STS_Base : CUP_Tigr_Base {
    class AnimationSources : AnimationSources {
        class HitGlass10 {
            hitpoint = "HitGlass10";
        };
    };
};
class CUP_Tigr_M_Base : CUP_Tigr_Base {
    class AnimationSources : AnimationSources {
        class HitGlass10 {
            hitpoint = "HitGlass10";
        };
    };
};
class CUP_CRYE_G3C_MC;
class CUP_CRYE_G3C_RGR;
class CUP_B_ILDU_Soldier_TeamleaderUS : CUP_CRYE_G3C_MC {
    identityTypes[] = { "LanguageENG_F", "Head_NATO", "CUP_G_ARMY" };
};
class CUP_B_ILDU_Soldier_RiflemanUSAT : CUP_CRYE_G3C_RGR {
    identityTypes[] = { "LanguageENG_F", "Head_NATO", "CUP_G_ARMY" };
};
class CUP_B_ILDU_Soldier_ARUS : CUP_CRYE_G3C_MC {
    identityTypes[] = { "LanguageENG_F", "Head_NATO", "CUP_G_ARMY" };
};
class CUP_B_ILDU_Soldier_ATSpecialistUSA : CUP_CRYE_G3C_MC {
    identityTypes[] = { "LanguageENG_F", "Head_NATO", "CUP_G_ARMY" };
};
class CUP_B_ILDU_Soldier_RiflemanUS : CUP_CRYE_G3C_MC {
    identityTypes[] = { "LanguageENG_F", "Head_NATO", "CUP_G_ARMY" };
};
class CUP_B_ILDU_Soldier_ReconTeamLeader : CUP_CRYE_G3C_MC {
    identityTypes[] = { "LanguageENG_F", "Head_NATO", "CUP_G_ARMY" };
};
class CUP_B_ILDU_Soldier_ReconGrenadier : CUP_CRYE_G3C_MC {
    identityTypes[] = { "LanguageENG_F", "Head_NATO", "CUP_G_ARMY" };
};
