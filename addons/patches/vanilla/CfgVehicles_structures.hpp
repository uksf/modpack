class Land_powerline_02_pole_junction_nest_a_bird : Land_powerline_02_pole_junction_nest_a_f {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Bomb : Strategic {
    ace_refuel_fuelCargo = -1;
};
class Land_NetFence_02_m_gate_v1_closed_F : Wall_F {
    class AnimationSources {
        class door_1_locked_source {
            source = "user";
            animPeriod = 0.8;
            initPhase = 0;
        };
    };
};
class Land_NetFence_02_m_gate_v2_closed_F : Wall_F {
    class AnimationSources {
        class door_1_locked_source {
            source = "user";
            animPeriod = 0.8;
            initPhase = 0;
        };
        class door_2_locked_source {
            source = "user";
            animPeriod = 0.8;
            initPhase = 0;
        };
    };
};
class Land_PipeFence_01_m_gate_v1_closed_F : Wall_F {
    class AnimationSources {
        class door_1_locked_source {
            source = "user";
            animPeriod = 0.8;
            initPhase = 0;
        };
    };
};
class Land_PipeFence_01_m_gate_v2_closed_F : Wall_F {
    class AnimationSources {
        class door_1_locked_source {
            source = "user";
            animPeriod = 0.8;
            initPhase = 0;
        };
        class door_2_locked_source {
            source = "user";
            animPeriod = 0.8;
            initPhase = 0;
        };
    };
};
class Land_PipeFence_03_m_gate_l_F : Wall_F {
    class AnimationSources;
};
class Land_PipeFence_03_m_gate_r_F : Land_PipeFence_03_m_gate_l_F {
    class AnimationSources : AnimationSources {
        class door_1_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class Land_PipeFence_04_m_gate_l_F : Wall_F {
    class AnimationSources;
};
class Land_PipeFence_04_m_gate_r_F : Land_PipeFence_04_m_gate_l_F {
    class AnimationSources : AnimationSources {
        class door_1_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class Land_TinWall_01_m_gate_v1_closed_F : Wall_F {
    class AnimationSources {
        class door_1_locked_source {
            source = "user";
            animPeriod = 0.8;
            initPhase = 0;
        };
        class door_2_locked_source {
            source = "user";
            animPeriod = 0.8;
            initPhase = 0;
        };
    };
};
class Land_TinWall_01_m_gate_v2_closed_F : Wall_F {
    class AnimationSources {
        class door_1_locked_source {
            source = "user";
            animPeriod = 0.8;
            initPhase = 0;
        };
        class door_2_locked_source {
            source = "user";
            animPeriod = 0.8;
            initPhase = 0;
        };
    };
};
