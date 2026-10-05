// MBG's sound sources have no parent, so they lack every base vehicle entry and have no simulation.
class Sound;
class MBG_SndSrc_DoorOpen : Sound {};
// Two FFAA buildings list a ladder whose start1/end1 points their models do not have.
class ffaa_casa_af_base;
class land_ffaa_casa_urbana_8 : ffaa_casa_af_base {
    ladders[] = {};
};
class land_ffaa_casa_hangar_2 : ffaa_casa_af_base {
    ladders[] = {};
};
// Expeden's ScopeShieldDeMount declares ViewOptics directly in StaticMGWeapon's Turrets, so every static MG
// that inherits that list (Fort_Nest_M240) gets an empty second turret.
class LandVehicle;
class StaticWeapon : LandVehicle {
    class Turrets;
};
class StaticMGWeapon : StaticWeapon {
    class Turrets : Turrets {
        delete ViewOptics;
    };
};
// aggregateReflectors is a list of groups; CUP gives the M151 headlights as one flat list.
class Car_F;
class CUP_M151_base : Car_F {
    aggregateReflectors[] = { { "LightCarHeadL01", "LightCarHeadR01" } };
};
