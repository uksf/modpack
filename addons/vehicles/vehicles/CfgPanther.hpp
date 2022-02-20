class UK3CB_BAF_Panther_Base : MRAP_01_base_F {
    armor = 200;
    armorStructural = 20;
    hullDamageCauseExplosion = 0;
    class HitPoints : HitPoints {
        class HitBody {
            passThrough = 0;
            explosionShielding = 1;  // 1.5
        };
        class HitEngine {
            armor = 1;  // 0.5
            passThrough = 0;
        };
        class HitFuel {
            armor = 1;  // 0.5
        };
    };
};
class UK3CB_BAF_Panther_GPMG_Sand_A : UK3CB_BAF_Panther_Base {
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
    COVER_ACTIONS
};
class UK3CB_BAF_Panther_GPMG_Green_A : UK3CB_BAF_Panther_GPMG_Sand_A {
    COVER_ACTIONS
};
