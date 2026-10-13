class B_L_Soldier_Base_F : B_G_Soldier_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class B_Story_crew_F : B_crew_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class B_Story_engineer_Future_G : B_Soldier_03_f {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class B_Story_medic_F : B_CTRG_soldier_M_medic_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class B_Story_officer_F : B_officer_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class B_Story_recon_TL_F : B_recon_TL_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class B_Story_ScottAlsworth : B_officer_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class B_Story_Soldier_SL_01_F : B_Soldier_SL_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class B_Story_Soldier_SL_02_F : B_Soldier_SL_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class B_Story_Soldier_TL_01_F : B_Soldier_TL_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class B_W_Story_Protagonist_01_F : B_W_Soldier_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class C_Story_Oldman_01_F : C_man_hunter_1_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class I_P_Soldier_base_F : I_Soldier_base_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class I_Story_Soldier_01_F : I_soldier_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class I_Story_Soldier_GL_01_F : B_G_Soldier_GL_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class O_T_Scientist_F : O_T_Soldier_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class O_T_Scientist_Unarmed_F : O_T_Soldier_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class O_T_Soldier_CBRN_F : O_T_Soldier_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Snake_random_F : Animal_Base_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Protagonist_VR_01 : C_man_1 {
    class HitPoints {
        class HitHands;
        class HitLegs;
        class HitLeftArm : HitHands {
            material = -1;
            name = "hand_l";
            radius = 0.08;
            visual = "injury_hands";
            minimalHit = 0.01;
        };
        class HitRightArm : HitLeftArm {
            name = "hand_r";
        };
        class HitLeftLeg : HitLegs {
            material = -1;
            name = "leg_l";
            radius = 0.1;
            visual = "injury_legs";
            minimalHit = 0.01;
        };
        class HitRightLeg : HitLeftLeg {
            name = "leg_r";
        };
    };
};
class O_Soldier_diver_noFins_base : O_Soldier_base_F {
    class HitPoints {
        class HitHands;
        class HitLegs;
        class HitLeftArm : HitHands {
            material = -1;
            name = "hand_l";
            radius = 0.08;
            visual = "injury_hands";
            minimalHit = 0.01;
        };
        class HitRightArm : HitLeftArm {
            name = "hand_r";
        };
        class HitLeftLeg : HitLegs {
            material = -1;
            name = "leg_l";
            radius = 0.1;
            visual = "injury_legs";
            minimalHit = 0.01;
        };
        class HitRightLeg : HitLeftLeg {
            name = "leg_r";
        };
    };
};
class I_Uniform_01_coveralls_G_gloves : I_E_Man_Base_F {
    class HitPoints {
        class HitHands;
        class HitLegs;
        class HitLeftArm : HitHands {
            material = -1;
            name = "hand_l";
            radius = 0.08;
            visual = "injury_hands";
            minimalHit = 0.01;
        };
        class HitRightArm : HitLeftArm {
            name = "hand_r";
        };
        class HitLeftLeg : HitLegs {
            material = -1;
            name = "leg_l";
            radius = 0.1;
            visual = "injury_legs";
            minimalHit = 0.01;
        };
        class HitRightLeg : HitLeftLeg {
            name = "leg_r";
        };
    };
};
class I_E_Helipilot_noGloves : I_E_Helipilot_F {
    class HitPoints {
        class HitHands;
        class HitLegs;
        class HitLeftArm : HitHands {
            material = -1;
            name = "hand_l";
            radius = 0.08;
            visual = "injury_hands";
            minimalHit = 0.01;
        };
        class HitRightArm : HitLeftArm {
            name = "hand_r";
        };
        class HitLeftLeg : HitLegs {
            material = -1;
            name = "leg_l";
            radius = 0.1;
            visual = "injury_legs";
            minimalHit = 0.01;
        };
        class HitRightLeg : HitLeftLeg {
            name = "leg_r";
        };
    };
};
class C_man_w_worker_F_Contact : C_man_w_worker_F_dgtl {
    class HitPoints {
        class HitHands;
        class HitLegs;
        class HitLeftArm : HitHands {
            material = -1;
            name = "hand_l";
            radius = 0.08;
            visual = "injury_hands";
            minimalHit = 0.01;
        };
        class HitRightArm : HitLeftArm {
            name = "hand_r";
        };
        class HitLeftLeg : HitLegs {
            material = -1;
            name = "leg_l";
            radius = 0.1;
            visual = "injury_legs";
            minimalHit = 0.01;
        };
        class HitRightLeg : HitLeftLeg {
            name = "leg_r";
        };
    };
};
class B_Uniform_01_coveralls_G_gloves : I_E_Man_Base_F {
    class HitPoints {
        class HitHands;
        class HitLegs;
        class HitLeftArm : HitHands {
            material = -1;
            name = "hand_l";
            radius = 0.08;
            visual = "injury_hands";
            minimalHit = 0.01;
        };
        class HitRightArm : HitLeftArm {
            name = "hand_r";
        };
        class HitLeftLeg : HitLegs {
            material = -1;
            name = "leg_l";
            radius = 0.1;
            visual = "injury_legs";
            minimalHit = 0.01;
        };
        class HitRightLeg : HitLeftLeg {
            name = "leg_r";
        };
    };
};
class B_CombatUniform_sage_worn : B_Soldier_F {
    uniformClass = "U_B_CombatUniform_sage_worn";
};
class B_CombatUniform_wdl_worn : B_Soldier_F {
    uniformClass = "U_B_CombatUniform_wdl_worn";
};
class C_Uniform_ArtTShirt_01_isntArt : C_Uniform_ArtTShirt_01_base_F {
    uniformClass = "U_C_ArtTShirt_01_isntArt";
};
