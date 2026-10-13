class Truck_F : Car_F {};
class Truck_01_base_F : Truck_F {};
class B_Truck_01_transport_F : Truck_01_base_F {};
class Van_02_base_F : Truck_F {};
class Van_02_service_base_F : Van_02_base_F {
    class AnimationSources : AnimationSources {
        class enable_cargo {
            source = "user";
            animPeriod = 0.0002;
        };
    };
};
class B_Truck_01_medical_F : B_Truck_01_transport_F {
    class AnimationSources : AnimationSources {
        class mirror_l_hide {
            source = "user";
            animPeriod = 0.01;
            initPhase = 0;
        };
    };
};
class B_Truck_01_mover_F : B_Truck_01_transport_F {
    class AnimationSources : AnimationSources {
        class mirror_l_hide {
            source = "user";
            animPeriod = 0.01;
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
