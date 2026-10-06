class CUP_MH60S_Unarmed_FFV_USN : CUP_MH60S_Unarmed_FFV_Base {
    class AnimationSources : AnimationSources {
        class miniguns_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
    };
};
class CUP_MH60S_Unarmed_USN : CUP_UH60_Unarmed_Base {
    class AnimationSources : AnimationSources {
        class miniguns_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
        class seats_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
    };
};
class House : HouseBase {};
class Land_Ind_Mlyn_03 : House {
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
    };
};
class B_Truck_01_Repair_F : B_Truck_01_mover_F {
    class AnimationSources : AnimationSources {
        class mirror_l_hide {
            source = "user";
            animPeriod = 0.01;
            initPhase = 0;
        };
    };
};
class B_Truck_01_ammo_F : B_Truck_01_mover_F {
    class AnimationSources : AnimationSources {
        class mirror_l_hide {
            source = "user";
            animPeriod = 0.01;
            initPhase = 0;
        };
    };
};
class B_Truck_01_box_F : B_Truck_01_mover_F {
    class AnimationSources : AnimationSources {
        class mirror_l_hide {
            source = "user";
            animPeriod = 0.01;
            initPhase = 0;
        };
    };
};
class B_Truck_01_fuel_F : B_Truck_01_mover_F {
    class AnimationSources : AnimationSources {
        class mirror_l_hide {
            source = "user";
            animPeriod = 0.01;
            initPhase = 0;
        };
    };
};
