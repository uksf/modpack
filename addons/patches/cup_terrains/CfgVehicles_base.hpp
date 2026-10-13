class Land_Mil_House_no_interior_CUP;
class House_EP1;
class Pastor;
class Land_Mil_Guardhouse_EP1 : House_EP1 {
    class AnimationSources {
        class door_1_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class Land_Mil_House_no_interior_dam_CUP : Land_Mil_House_no_interior_CUP {
    class AnimationSources {
        class hit1 {
            source = "Hit";
            hitpoint = "Hit1";
            raw = 1;
        };
        class hit2 {
            source = "Hit";
            hitpoint = "Hit2";
            raw = 1;
        };
        class hit3 {
            source = "Hit";
            hitpoint = "Hit3";
            raw = 1;
        };
        class hit4 {
            source = "Hit";
            hitpoint = "Hit4";
            raw = 1;
        };
        class hit5 {
            source = "Hit";
            hitpoint = "Hit5";
            raw = 1;
        };
        class hit6 {
            source = "Hit";
            hitpoint = "Hit6";
            raw = 1;
        };
    };
};
class All {
    class AnimationSources;
};
class Static : All {};
class Building : Static {};
class NonStrategic : Building {};
class HouseBase : NonStrategic {};
class House : HouseBase {};
class CUP_A2_Baseclass : Static {};
class CUP_A2_Civilian : CUP_A2_Baseclass {};
class CUP_A2_Industry : CUP_A2_Baseclass {};
class CUP_A1_BaseObject : Static {};
class Land_Ind_Mlyn_03 : House {
    class HitPoints {
        GLASS_HITPOINT(Glass_1,Glass_1_hide);
        GLASS_HITPOINT(Glass_2,Glass_2_hide);
        GLASS_HITPOINT(Glass_3,Glass_3_hide);
    };
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class glass_1_source {
            source = "Hit";
            hitpoint = "Glass_1_hitpoint";
            raw = 1;
        };
        class glass_2_source {
            source = "Hit";
            hitpoint = "Glass_2_hitpoint";
            raw = 1;
        };
        class glass_3_source {
            source = "Hit";
            hitpoint = "Glass_3_hitpoint";
            raw = 1;
        };
    };
};
