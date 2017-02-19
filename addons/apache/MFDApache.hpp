class MFD {
    class AirplaneHUD {
        class Bones{};
        class Draw{};
        topLeft = "HUD_top_left";
        topRight = "HUD_top_right";
        bottomLeft = "HUD_bottom_left";
        borderLeft = 0;
        borderRight = 0;
        borderTop = 0;
        borderBottom = 0;
        color[] = {0.15,1,0.15,1};
        enableParallax = 0;
        helmetMountedDisplay = 1;
        helmetPosition[] = {0,0,0};
        helmetRight[] = {0,0,0};
        helmetDown[] = {0,0,0};
    };
    class Kimi_HUD_1 {
        topLeft = "HUD_top_left";
        topRight = "HUD_top_right";
        bottomLeft = "HUD_bottom_left";
        borderLeft = 0;
        borderRight = 0;
        borderTop = 0;
        borderBottom = 0;
        color[] = {0.15,1,0.15,1};
        enableParallax = 0;
        class Bones {
            class GunnerAim {
                type = "vector";
                source = "weapon";
                pos0[] = {0.5,"0.9 - 0.04 + 0.012" };
                pos10[] = { "0.5 + 0.0111","0.9 - 0.04 + 0.012 + 0.0133" };
            };
            class Target {
                source = "target";
                type = "vector";
                pos0[] = {0.5,0.5};
                pos10[] = {0.85,0.85};
            };
            class Velocity {
                type = "vector";
                source = "velocity";
                pos0[] = {0.5,0.5};
                pos10[] = {0.65,0.65};
            };
            class Velocity_slip {
                type = "vector";
                source = "velocity";
                pos0[] = {0.5,0.845};
                pos10[] = {0.53,0.845};
            };
            class VspeedBone {
                type = "linear";
                source = "vspeed";
                sourceScale = 1;
                min = -10;
                max = 10;
                minPos[] = {0.93,0.2};
                maxPos[] = {0.93,0.8};
            };
            class RadarAltitudeBone {
                type = "linear";
                source = "altitudeAGL";
                sourceScale = 3.2808399;
                min = 0;
                max = 60;
                minPos[] = {0.965,0.2};
                maxPos[] = {0.965,0.8};
            };
            class HorizonBankRot {
                type = "rotational";
                source = "horizonBank";
                center[] = {0.5,0.5};
                min = -3.1416;
                max = 3.1416;
                minAngle = -180;
                maxAngle = 180;
                aspectRatio = 1;
            };
            class ForwardVec {
                type = "vector";
                source = "forward";
                pos0[] = {0,0};
                pos10[] = {0.25,0.25};
            };
            class WeaponAim {
                type = "vector";
                source = "weapon";
                pos0[] = {0.5,0.5};
                pos10[] = {0.75,0.75};
            };
            class Level0 {
                type = "horizon";
                pos0[] = {0.5,0.5};
                pos10[] = {0.78,0.78};
                angle = 0;
            };
            class LevelP5: Level0 {
                angle = 5;
            };
            class LevelM5: Level0 {
                angle = -5;
            };
            class LevelP10: Level0 {
                angle = 10;
            };
            class LevelM10: Level0 {
                angle = -10;
            };
            class LevelP15: Level0 {
                angle = 15;
            };
            class LevelM15: Level0 {
                angle = -15;
            };
            class LevelP20: Level0 {
                angle = 20;
            };
            class LevelM20: Level0 {
                angle = -20;
            };
            class LevelP25: Level0 {
                angle = 25;
            };
            class LevelM25: Level0 {
                angle = -25;
            };
            class LevelP30: Level0 {
                angle = 30;
            };
            class LevelM30: Level0 {
                angle = -30;
            };
            class LevelP35: Level0 {
                angle = 35;
            };
            class LevelM35: Level0 {
                angle = -35;
            };
            class LevelP40: Level0 {
                angle = 40;
            };
            class LevelM40: Level0 {
                angle = -40;
            };
            class LevelP45: Level0 {
                angle = 45;
            };
            class LevelM45: Level0 {
                angle = -45;
            };
            class LevelP50: Level0 {
                angle = 50;
            };
            class LevelM50: Level0 {
                angle = -50;
            };
        };
        class Draw {
            color[] = {0.18,1,0.18};
            alpha = 1;
            condition = "on";
            class Horizont {
                clipTL[] = {0.15,0.15};
                clipBR[] = {0.85,0.85};
                class Dimmed {
                    class Level0 {
                        type = "line";
                        points[] = {{ "Level0",{ -0.42,0 },1 },{ "Level0",{ -0.38,0 },1 },{  },{ "Level0",{ -0.37,0 },1 },{ "Level0",{ -0.33,0 },1 },{  },{ "Level0",{ -0.32,0 },1 },{ "Level0",{ -0.28,0 },1 },{  },{ "Level0",{ -0.27,0 },1 },{ "Level0",{ -0.23,0 },1 },{  },{ "Level0",{ -0.22,0 },1 },{ "Level0",{ -0.18,0 },1 },{  },{ "Level0",{ -0.17,0 },1 },{ "Level0",{ -0.13,0 },1 },{  },{ "Level0",{ -0.12,0 },1 },{ "Level0",{ -0.08,0 },1 },{  },{ "Level0",{ 0.42,0 },1 },{ "Level0",{ 0.38,0 },1 },{  },{ "Level0",{ 0.37,0 },1 },{ "Level0",{ 0.33,0 },1 },{  },{ "Level0",{ 0.32,0 },1 },{ "Level0",{ 0.28,0 },1 },{  },{ "Level0",{ 0.27,0 },1 },{ "Level0",{ 0.23,0 },1 },{  },{ "Level0",{ 0.22,0 },1 },{ "Level0",{ 0.18,0 },1 },{  },{ "Level0",{ 0.17,0 },1 },{ "Level0",{ 0.13,0 },1 },{  },{ "Level0",{ 0.12,0 },1 },{ "Level0",{ 0.08,0 },1 }};
                    };
                    class LevelM10: Level0 {
                        type = "line";
                        width = 2;
                        points[] = {{ "LevelM10",{ -0.2,-0.03 },1 },{ "LevelM10",{ -0.2,0 },1 },{ "LevelM10",{ -0.15,0 },1 },{  },{ "LevelM10",{ -0.1,0 },1 },{ "LevelM10",{ -0.05,0 },1 },{  },{ "LevelM10",{ 0.05,0 },1 },{ "LevelM10",{ 0.1,0 },1 },{  },{ "LevelM10",{ 0.15,0 },1 },{ "LevelM10",{ 0.2,0 },1 },{ "LevelM10",{ 0.2,-0.03 },1 }};
                    };
                    class VALM_1_10 {
                        type = "text";
                        source = "static";
                        text = -10;
                        align = "left";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelM10",{ -0.22,-0.085 },1};
                        right[] = { "LevelM10",{ -0.17,-0.085 },1};
                        down[] = { "LevelM10",{ -0.22,-0.035 },1};
                    };
                    class VALM_2_10: VALM_1_10 {
                        align = "right";
                        pos[] = { "LevelM10",{ 0.22,-0.085 },1};
                        right[] = { "LevelM10",{ 0.27,-0.085 },1};
                        down[] = { "LevelM10",{ 0.22,-0.035 },1};
                    };
                    class LevelP10: Level0 {
                        type = "line";
                        width = 2;
                        points[] = {{ "LevelP10",{ -0.2,0.03 },1 },{ "LevelP10",{ -0.2,0 },1 },{ "LevelP10",{ -0.05,0 },1 },{  },{ "LevelP10",{ 0.05,0 },1 },{ "LevelP10",{ 0.2,0 },1 },{ "LevelP10",{ 0.2,0.03 },1 }};
                    };
                    class VALP_1_10 {
                        type = "text";
                        source = "static";
                        text = "10";
                        align = "left";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelP10",{ -0.22,0.035 },1};
                        right[] = { "LevelP10",{ -0.17,0.035 },1};
                        down[] = { "LevelP10",{ -0.22,0.085 },1};
                    };
                    class VALP_2_10: VALP_1_10 {
                        align = "right";
                        pos[] = { "LevelP10",{ 0.22,0.035 },1};
                        right[] = { "LevelP10",{ 0.27,0.035 },1};
                        down[] = { "LevelP10",{ 0.22,0.085 },1};
                    };
                    class LevelM20: Level0 {
                        type = "line";
                        width = 2;
                        points[] = {{ "LevelM20",{ -0.2,-0.03 },1 },{ "LevelM20",{ -0.2,0 },1 },{ "LevelM20",{ -0.15,0 },1 },{  },{ "LevelM20",{ -0.1,0 },1 },{ "LevelM20",{ -0.05,0 },1 },{  },{ "LevelM20",{ 0.05,0 },1 },{ "LevelM20",{ 0.1,0 },1 },{  },{ "LevelM20",{ 0.15,0 },1 },{ "LevelM20",{ 0.2,0 },1 },{ "LevelM20",{ 0.2,-0.03 },1 }};
                    };
                    class VALM_1_20 {
                        type = "text";
                        source = "static";
                        text = -20;
                        align = "left";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelM20",{ -0.22,-0.085 },1};
                        right[] = { "LevelM20",{ -0.17,-0.085 },1};
                        down[] = { "LevelM20",{ -0.22,-0.035 },1};
                    };
                    class VALM_2_20: VALM_1_20 {
                        align = "right";
                        pos[] = { "LevelM20",{ 0.22,-0.085 },1};
                        right[] = { "LevelM20",{ 0.27,-0.085 },1};
                        down[] = { "LevelM20",{ 0.22,-0.035 },1};
                    };
                    class LevelP20: Level0 {
                        type = "line";
                        width = 2;
                        points[] = {{ "LevelP20",{ -0.2,0.03 },1 },{ "LevelP20",{ -0.2,0 },1 },{ "LevelP20",{ -0.05,0 },1 },{  },{ "LevelP20",{ 0.05,0 },1 },{ "LevelP20",{ 0.2,0 },1 },{ "LevelP20",{ 0.2,0.03 },1 }};
                    };
                    class VALP_1_20 {
                        type = "text";
                        source = "static";
                        text = "20";
                        align = "left";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelP20",{ -0.22,0.035 },1};
                        right[] = { "LevelP20",{ -0.17,0.035 },1};
                        down[] = { "LevelP20",{ -0.22,0.085 },1};
                    };
                    class VALP_2_20: VALP_1_20 {
                        align = "right";
                        pos[] = { "LevelP20",{ 0.22,0.035 },1};
                        right[] = { "LevelP20",{ 0.27,0.035 },1};
                        down[] = { "LevelP20",{ 0.22,0.085 },1};
                    };
                    class LevelM30: Level0 {
                        type = "line";
                        width = 2;
                        points[] = {{ "LevelM30",{ -0.2,-0.03 },1 },{ "LevelM30",{ -0.2,0 },1 },{ "LevelM30",{ -0.15,0 },1 },{  },{ "LevelM30",{ -0.1,0 },1 },{ "LevelM30",{ -0.05,0 },1 },{  },{ "LevelM30",{ 0.05,0 },1 },{ "LevelM30",{ 0.1,0 },1 },{  },{ "LevelM30",{ 0.15,0 },1 },{ "LevelM30",{ 0.2,0 },1 },{ "LevelM30",{ 0.2,-0.03 },1 }};
                    };
                    class VALM_1_30 {
                        type = "text";
                        source = "static";
                        text = -30;
                        align = "left";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelM30",{ -0.22,-0.085 },1};
                        right[] = { "LevelM30",{ -0.17,-0.085 },1};
                        down[] = { "LevelM30",{ -0.22,-0.035 },1};
                    };
                    class VALM_2_30: VALM_1_30 {
                        align = "right";
                        pos[] = { "LevelM30",{ 0.22,-0.085 },1};
                        right[] = { "LevelM30",{ 0.27,-0.085 },1};
                        down[] = { "LevelM30",{ 0.22,-0.035 },1};
                    };
                    class LevelP30: Level0 {
                        type = "line";
                        width = 2;
                        points[] = {{ "LevelP30",{ -0.2,0.03 },1 },{ "LevelP30",{ -0.2,0 },1 },{ "LevelP30",{ -0.05,0 },1 },{  },{ "LevelP30",{ 0.05,0 },1 },{ "LevelP30",{ 0.2,0 },1 },{ "LevelP30",{ 0.2,0.03 },1 }};
                    };
                    class VALP_1_30 {
                        type = "text";
                        source = "static";
                        text = "30";
                        align = "left";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelP30",{ -0.22,0.035 },1};
                        right[] = { "LevelP30",{ -0.17,0.035 },1};
                        down[] = { "LevelP30",{ -0.22,0.085 },1};
                    };
                    class VALP_2_30: VALP_1_30 {
                        align = "right";
                        pos[] = { "LevelP30",{ 0.22,0.035 },1};
                        right[] = { "LevelP30",{ 0.27,0.035 },1};
                        down[] = { "LevelP30",{ 0.22,0.085 },1};
                    };
                    class LevelM40: Level0 {
                        type = "line";
                        width = 2;
                        points[] = {{ "LevelM40",{ -0.2,-0.03 },1 },{ "LevelM40",{ -0.2,0 },1 },{ "LevelM40",{ -0.15,0 },1 },{  },{ "LevelM40",{ -0.1,0 },1 },{ "LevelM40",{ -0.05,0 },1 },{  },{ "LevelM40",{ 0.05,0 },1 },{ "LevelM40",{ 0.1,0 },1 },{  },{ "LevelM40",{ 0.15,0 },1 },{ "LevelM40",{ 0.2,0 },1 },{ "LevelM40",{ 0.2,-0.03 },1 }};
                    };
                    class VALM_1_40 {
                        type = "text";
                        source = "static";
                        text = -40;
                        align = "left";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelM40",{ -0.22,-0.085 },1};
                        right[] = { "LevelM40",{ -0.17,-0.085 },1};
                        down[] = { "LevelM40",{ -0.22,-0.035 },1};
                    };
                    class VALM_2_40: VALM_1_40 {
                        align = "right";
                        pos[] = { "LevelM40",{ 0.22,-0.085 },1};
                        right[] = { "LevelM40",{ 0.27,-0.085 },1};
                        down[] = { "LevelM40",{ 0.22,-0.035 },1};
                    };
                    class LevelP40: Level0 {
                        type = "line";
                        width = 2;
                        points[] = {{ "LevelP40",{ -0.2,0.03 },1 },{ "LevelP40",{ -0.2,0 },1 },{ "LevelP40",{ -0.05,0 },1 },{  },{ "LevelP40",{ 0.05,0 },1 },{ "LevelP40",{ 0.2,0 },1 },{ "LevelP40",{ 0.2,0.03 },1 }};
                    };
                    class VALP_1_40 {
                        type = "text";
                        source = "static";
                        text = "40";
                        align = "left";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelP40",{ -0.22,0.035 },1};
                        right[] = { "LevelP40",{ -0.17,0.035 },1};
                        down[] = { "LevelP40",{ -0.22,0.085 },1};
                    };
                    class VALP_2_40: VALP_1_40 {
                        align = "right";
                        pos[] = { "LevelP40",{ 0.22,0.035 },1};
                        right[] = { "LevelP40",{ 0.27,0.035 },1};
                        down[] = { "LevelP40",{ 0.22,0.085 },1};
                    };
                    class LevelM50: Level0 {
                        type = "line";
                        width = 2;
                        points[] = {{ "LevelM50",{ -0.2,-0.03 },1 },{ "LevelM50",{ -0.2,0 },1 },{ "LevelM50",{ -0.15,0 },1 },{  },{ "LevelM50",{ -0.1,0 },1 },{ "LevelM50",{ -0.05,0 },1 },{  },{ "LevelM50",{ 0.05,0 },1 },{ "LevelM50",{ 0.1,0 },1 },{  },{ "LevelM50",{ 0.15,0 },1 },{ "LevelM50",{ 0.2,0 },1 },{ "LevelM50",{ 0.2,-0.03 },1 }};
                    };
                    class VALM_1_50 {
                        type = "text";
                        source = "static";
                        text = -50;
                        align = "left";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelM50",{ -0.22,-0.085 },1};
                        right[] = { "LevelM50",{ -0.17,-0.085 },1};
                        down[] = { "LevelM50",{ -0.22,-0.035 },1};
                    };
                    class VALM_2_50: VALM_1_50 {
                        align = "right";
                        pos[] = { "LevelM50",{ 0.22,-0.085 },1};
                        right[] = { "LevelM50",{ 0.27,-0.085 },1};
                        down[] = { "LevelM50",{ 0.22,-0.035 },1};
                    };
                    class LevelP50: Level0 {
                        type = "line";
                        width = 2;
                        points[] = {{ "LevelP50",{ -0.2,0.03 },1 },{ "LevelP50",{ -0.2,0 },1 },{ "LevelP50",{ -0.05,0 },1 },{  },{ "LevelP50",{ 0.05,0 },1 },{ "LevelP50",{ 0.2,0 },1 },{ "LevelP50",{ 0.2,0.03 },1 }};
                    };
                    class VALP_1_50 {
                        type = "text";
                        source = "static";
                        text = "50";
                        align = "left";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelP50",{ -0.22,0.035 },1};
                        right[] = { "LevelP50",{ -0.17,0.035 },1};
                        down[] = { "LevelP50",{ -0.22,0.085 },1};
                    };
                    class VALP_2_50: VALP_1_50 {
                        align = "right";
                        pos[] = { "LevelP50",{ 0.22,0.035 },1};
                        right[] = { "LevelP50",{ 0.27,0.035 },1};
                        down[] = { "LevelP50",{ 0.22,0.085 },1};
                    };
                };
            };
            class HorizonBankRot {
                type = "line";
                width = 2;
                points[] = {{ "HorizonBankRot",{0,0.25},1},{ "HorizonBankRot",{-0.01,0.23},1},{ "HorizonBankRot",{0.01,0.23},1},{ "HorizonBankRot",{0,0.25},1}};
            };
            class Static_HAD_BOX {
                clipTL[] = {0,1};
                clipBR[] = {1,0};
                type = "line";
                width = 4;
                points[] = {{{ "0.5-0.1","0.9-0.04" },1},{{ "0.5-0.1","0.9+0.04" },1},{{ "0.5+0.1","0.9+0.04" },1},{{ "0.5+0.1","0.9-0.04" },1},{{ "0.5-0.1","0.9-0.04" },1},{},{{ "0.5-0.1","0.9-0.04+0.012" },1},{{ "0.5-0.092","0.9-0.04+0.012" },1},{},{{ "0.5+0.1","0.9-0.04+0.012" },1},{{ "0.5+0.092","0.9-0.04+0.012" },1},{},{{0.5,"0.9-0.04" },1},{{0.5,"0.9-0.032" },1},{},{{0.5,"0.9+0.04" },1},{{0.5,"0.9+0.032" },1},{}};
            };
            class Gunner_HAD {
                type = "line";
                width = 4;
                points[] = {{ "GunnerAim",{-0.015,-0.008},1},{ "GunnerAim",{-0.015,0.008},1},{ "GunnerAim",{0.015,0.008},1},{ "GunnerAim",{0.015,-0.008},1},{ "GunnerAim",{-0.015,-0.008},1}};
            };
            class Slip_ball_group {
                class Slip_bars {
                    type = "line";
                    width = 4;
                    points[] = {{{ "0.5-0.018","0.9-0.04" },1},{{ "0.5-0.018","0.9-0.075" },1},{},{{ "0.5+0.018","0.9-0.04" },1},{{ "0.5+0.018","0.9-0.075" },1}};
                };
                class Slip_ball {
                    type = "line";
                    width = 4;
                    points[] = {{ "Velocity_slip",1,{ "0 * 0.75","-0.02 * 0.75" },1},{ "Velocity_slip",1,{ "0.0099999998 * 0.75","-0.01732 * 0.75" },1},{ "Velocity_slip",1,{ "0.01732 * 0.75","-0.0099999998 * 0.75" },1},{ "Velocity_slip",1,{ "0.02 * 0.75","0 * 0.75" },1},{ "Velocity_slip",1,{ "0.01732 * 0.75","0.0099999998 * 0.75" },1},{ "Velocity_slip",1,{ "0.0099999998 * 0.75","0.01732 * 0.75" },1},{ "Velocity_slip",1,{ "0 * 0.75","0.02 * 0.75" },1},{ "Velocity_slip",1,{ "-0.0099999998 * 0.75","0.01732 * 0.75" },1},{ "Velocity_slip",1,{ "-0.01732 * 0.75","0.0099999998 * 0.75" },1},{ "Velocity_slip",1,{ "-0.02 * 0.75","0 * 0.75" },1},{ "Velocity_slip",1,{ "-0.01732 * 0.75","-0.0099999998 * 0.75" },1},{ "Velocity_slip",1,{ "-0.0099999998 * 0.75","-0.01732 * 0.75" },1},{ "Velocity_slip",1,{ "0 * 0.75","-0.02 * 0.75" },1},{},{ "Velocity_slip",1,{ "0 * 0.6","-0.02 * 0.6" },1},{ "Velocity_slip",1,{ "0.0099999998 * 0.6","-0.01732 * 0.6" },1},{ "Velocity_slip",1,{ "0.01732 * 0.6","-0.0099999998 * 0.6" },1},{ "Velocity_slip",1,{ "0.02 * 0.6","0 * 0.6" },1},{ "Velocity_slip",1,{ "0.01732 * 0.6","0.0099999998 * 0.6" },1},{ "Velocity_slip",1,{ "0.0099999998 * 0.6","0.01732 * 0.6" },1},{ "Velocity_slip",1,{ "0 * 0.6","0.02 * 0.6" },1},{ "Velocity_slip",1,{ "-0.0099999998 * 0.6","0.01732 * 0.6" },1},{ "Velocity_slip",1,{ "-0.01732 * 0.6","0.0099999998 * 0.6" },1},{ "Velocity_slip",1,{ "-0.02 * 0.6","0 * 0.6" },1},{ "Velocity_slip",1,{ "-0.01732 * 0.6","-0.0099999998 * 0.6" },1},{ "Velocity_slip",1,{ "-0.0099999998 * 0.6","-0.01732 * 0.6" },1},{ "Velocity_slip",1,{ "0 * 0.6","-0.02 * 0.6" },1},{},{ "Velocity_slip",1,{ "0 * 0.5","-0.02 * 0.5" },1},{ "Velocity_slip",1,{ "0.0099999998 * 0.5","-0.01732 * 0.5" },1},{ "Velocity_slip",1,{ "0.01732 * 0.5","-0.0099999998 * 0.5" },1},{ "Velocity_slip",1,{ "0.02 * 0.5","0 * 0.5" },1},{ "Velocity_slip",1,{ "0.01732 * 0.5","0.0099999998 * 0.5" },1},{ "Velocity_slip",1,{ "0.0099999998 * 0.5","0.01732 * 0.5" },1},{ "Velocity_slip",1,{ "0 * 0.5","0.02 * 0.5" },1},{ "Velocity_slip",1,{ "-0.0099999998 * 0.5","0.01732 * 0.5" },1},{ "Velocity_slip",1,{ "-0.01732 * 0.5","0.0099999998 * 0.5" },1},{ "Velocity_slip",1,{ "-0.02 * 0.5","0 * 0.5" },1},{ "Velocity_slip",1,{ "-0.01732 * 0.5","-0.0099999998 * 0.5" },1},{ "Velocity_slip",1,{ "-0.0099999998 * 0.5","-0.01732 * 0.5" },1},{ "Velocity_slip",1,{ "0 * 0.5","-0.02 * 0.5" },1},{},{ "Velocity_slip",1,{ "0 * 0.4","-0.02 * 0.4" },1},{ "Velocity_slip",1,{ "0.0099999998 * 0.4","-0.01732 * 0.4" },1},{ "Velocity_slip",1,{ "0.01732 * 0.4","-0.0099999998 * 0.4" },1},{ "Velocity_slip",1,{ "0.02 * 0.4","0 * 0.4" },1},{ "Velocity_slip",1,{ "0.01732 * 0.4","0.0099999998 * 0.4" },1},{ "Velocity_slip",1,{ "0.0099999998 * 0.4","0.01732 * 0.4" },1},{ "Velocity_slip",1,{ "0 * 0.4","0.02 * 0.4" },1},{ "Velocity_slip",1,{ "-0.0099999998 * 0.4","0.01732 * 0.4" },1},{ "Velocity_slip",1,{ "-0.01732 * 0.4","0.0099999998 * 0.4" },1},{ "Velocity_slip",1,{ "-0.02 * 0.4","0 * 0.4" },1},{ "Velocity_slip",1,{ "-0.01732 * 0.4","-0.0099999998 * 0.4" },1},{ "Velocity_slip",1,{ "-0.0099999998 * 0.4","-0.01732 * 0.4" },1},{ "Velocity_slip",1,{ "0 * 0.4","-0.02 * 0.4" },1},{},{ "Velocity_slip",1,{ "0 * 0.30","-0.02 * 0.30" },1},{ "Velocity_slip",1,{ "0.0099999998 * 0.30","-0.01732 * 0.30" },1},{ "Velocity_slip",1,{ "0.01732 * 0.30","-0.0099999998 * 0.30" },1},{ "Velocity_slip",1,{ "0.02 * 0.30","0 * 0.30" },1},{ "Velocity_slip",1,{ "0.01732 * 0.30","0.0099999998 * 0.30" },1},{ "Velocity_slip",1,{ "0.0099999998 * 0.30","0.01732 * 0.30" },1},{ "Velocity_slip",1,{ "0 * 0.30","0.02 * 0.30" },1},{ "Velocity_slip",1,{ "-0.0099999998 * 0.30","0.01732 * 0.30" },1},{ "Velocity_slip",1,{ "-0.01732 * 0.30","0.0099999998 * 0.30" },1},{ "Velocity_slip",1,{ "-0.02 * 0.30","0 * 0.30" },1},{ "Velocity_slip",1,{ "-0.01732 * 0.30","-0.0099999998 * 0.30" },1},{ "Velocity_slip",1,{ "-0.0099999998 * 0.30","-0.01732 * 0.30" },1},{ "Velocity_slip",1,{ "0 * 0.30","-0.02 * 0.30" },1},{},{ "Velocity_slip",1,{ "0 * 0.20","-0.02 * 0.20" },1},{ "Velocity_slip",1,{ "0.0099999998 * 0.20","-0.01732 * 0.20" },1},{ "Velocity_slip",1,{ "0.01732 * 0.20","-0.0099999998 * 0.20" },1},{ "Velocity_slip",1,{ "0.02 * 0.20","0 * 0.20" },1},{ "Velocity_slip",1,{ "0.01732 * 0.20","0.0099999998 * 0.20" },1},{ "Velocity_slip",1,{ "0.0099999998 * 0.20","0.01732 * 0.20" },1},{ "Velocity_slip",1,{ "0 * 0.20","0.02 * 0.20" },1},{ "Velocity_slip",1,{ "-0.0099999998 * 0.20","0.01732 * 0.20" },1},{ "Velocity_slip",1,{ "-0.01732 * 0.20","0.0099999998 * 0.20" },1},{ "Velocity_slip",1,{ "-0.02 * 0.20","0 * 0.20" },1},{ "Velocity_slip",1,{ "-0.01732 * 0.20","-0.0099999998 * 0.20" },1},{ "Velocity_slip",1,{ "-0.0099999998 * 0.20","-0.01732 * 0.20" },1},{ "Velocity_slip",1,{ "0 * 0.20","-0.02 * 0.20" },1},{},{ "Velocity_slip",1,{ "0 * 0.1","-0.02 * 0.1" },1},{ "Velocity_slip",1,{ "0.0099999998 * 0.1","-0.01732 * 0.1" },1},{ "Velocity_slip",1,{ "0.01732 * 0.1","-0.0099999998 * 0.1" },1},{ "Velocity_slip",1,{ "0.02 * 0.1","0 * 0.1" },1},{ "Velocity_slip",1,{ "0.01732 * 0.1","0.0099999998 * 0.1" },1},{ "Velocity_slip",1,{ "0.0099999998 * 0.1","0.01732 * 0.1" },1},{ "Velocity_slip",1,{ "0 * 0.1","0.02 * 0.1" },1},{ "Velocity_slip",1,{ "-0.0099999998 * 0.1","0.01732 * 0.1" },1},{ "Velocity_slip",1,{ "-0.01732 * 0.1","0.0099999998 * 0.1" },1},{ "Velocity_slip",1,{ "-0.02 * 0.1","0 * 0.1" },1},{ "Velocity_slip",1,{ "-0.01732 * 0.1","-0.0099999998 * 0.1" },1},{ "Velocity_slip",1,{ "-0.0099999998 * 0.1","-0.01732 * 0.1" },1},{ "Velocity_slip",1,{ "0 * 0.1","-0.02 * 0.1" },1}};
                };
            };
            class Centerline {
                type = "line";
                width = 3;
                points[] = {{{0.5,0.48},1},{{0.5,0.45},1},{},{{0.5,0.52},1},{{0.5,0.55},1},{},{{0.48,0.5},1},{{0.45,0.5},1},{},{{0.52,0.5},1},{{0.55,0.5},1},{}};
            };
            class WeaponName {
                type = "text";
                source = "weapon";
                sourceScale = 1;
                align = "right";
                scale = 1;
                pos[] = {{0.61,0.86},1};
                right[] = {{0.65,0.86},1};
                down[] = {{0.61,0.9},1};
            };
            class Ammo_GUN {
                type = "group";
                condition = "mgun";
                class Ammo_count_GUN {
                    type = "text";
                    source = "ammo";
                    sourceScale = 1;
                    align = "right";
                    scale = 1;
                    pos[] = {{0.61,0.89},1};
                    right[] = {{0.65,0.89},1};
                    down[] = {{0.61,0.93},1};
                };
            };
            class Ammo_RKT {
                type = "group";
                condition = "rocket";
                class Ammo_count_RKT {
                    type = "text";
                    source = "ammo";
                    sourceScale = 1;
                    align = "right";
                    scale = 1;
                    pos[] = {{0.61,0.89},1};
                    right[] = {{0.65,0.89},1};
                    down[] = {{0.61,0.93},1};
                };
            };
            class Ammo_AGM {
                type = "group";
                condition = "AAmissile";
                class Ammo_count_AGM {
                    type = "text";
                    source = "ammo";
                    sourceScale = 1;
                    align = "right";
                    scale = 1;
                    pos[] = {{0.61,0.89},1};
                    right[] = {{0.65,0.89},1};
                    down[] = {{0.61,0.93},1};
                };
            };
            class Ammo_AAM {
                type = "group";
                condition = "ATmissile";
                class Ammo_count_AAM {
                    type = "text";
                    source = "ammo";
                    sourceScale = 1;
                    align = "right";
                    scale = 1;
                    pos[] = {{0.61,0.89},1};
                    right[] = {{0.65,0.89},1};
                    down[] = {{0.61,0.93},1};
                };
            };
            class Ammo_Bomb {
                type = "group";
                condition = "Bomb";
                class Ammo_count_Bomb {
                    type = "text";
                    source = "ammo";
                    sourceScale = 1;
                    align = "right";
                    scale = 1;
                    pos[] = {{0.61,0.89},1};
                    right[] = {{0.65,0.89},1};
                    down[] = {{0.61,0.93},1};
                };
            };
            class LightsGroup {
                type = "group";
                condition = "lights";
                class LightsText {
                    type = "text";
                    source = "static";
                    text = "LIGHTS";
                    align = "right";
                    scale = 1;
                    pos[] = {{0.03,"0.53 + 0.055" },1};
                    right[] = {{0.07,"0.53 + 0.055" },1};
                    down[] = {{0.03,"0.53 + 0.095" },1};
                };
            };
            class CollisionLightsGroup {
                type = "group";
                condition = "collisionlights";
                class CollisionLightsText {
                    type = "text";
                    source = "static";
                    text = "A-COL";
                    align = "right";
                    scale = 1;
                    pos[] = {{0.03,"0.53 + 0.105" },1};
                    right[] = {{0.07,"0.53 + 0.105" },1};
                    down[] = {{0.03,"0.53 + 0.145" },1};
                };
            };
            class ATMissileTOFGroup {
                condition = "ATmissile";
                type = "group";
                class TOFtext {
                    type = "text";
                    align = "right";
                    source = "static";
                    text = "TOF = ";
                    scale = 1;
                    pos[] = {{0.61,0.92},1};
                    right[] = {{0.65,0.92},1};
                    down[] = {{0.61,0.96},1};
                };
                class TOFnumber {
                    type = "text";
                    source = "targetDist";
                    sourcescale = 0.0025;
                    align = "right";
                    scale = 1;
                    pos[] = {{0.69,0.92},1};
                    right[] = {{0.73,0.92},1};
                    down[] = {{0.69,0.96},1};
                };
            };
            class LaserTOFGroup {
                condition = "Bomb";
                type = "group";
                class TOFtext {
                    type = "text";
                    align = "right";
                    source = "static";
                    text = "TOF = ";
                    scale = 1;
                    pos[] = {{0.61,0.92},1};
                    right[] = {{0.65,0.92},1};
                    down[] = {{0.61,0.96},1};
                };
                class TOFnumber {
                    type = "text";
                    source = "targetDist";
                    sourcescale = 0.0025;
                    align = "right";
                    scale = 1;
                    pos[] = {{0.69,0.92},1};
                    right[] = {{0.73,0.92},1};
                    down[] = {{0.69,0.96},1};
                };
            };
            class RocketTOFGroup {
                condition = "Rocket";
                type = "group";
                class TOFtext {
                    type = "text";
                    align = "right";
                    source = "static";
                    text = "TOF = ";
                    scale = 1;
                    pos[] = {{0.61,0.92},1};
                    right[] = {{0.65,0.92},1};
                    down[] = {{0.61,0.96},1};
                };
                class TOFnumber {
                    type = "text";
                    source = "targetDist";
                    sourcescale = 0.0025;
                    align = "right";
                    scale = 1;
                    pos[] = {{0.69,0.92},1};
                    right[] = {{0.73,0.92},1};
                    down[] = {{0.69,0.96},1};
                };
            };
            class RangeNumber {
                type = "text";
                source = "targetDist";
                sourceScale = 1;
                align = "left";
                scale = 1;
                pos[] = {{0.39,0.89},1};
                right[] = {{0.43,0.89},1};
                down[] = {{0.39,0.93},1};
            };
            class RangeText {
                type = "text";
                source = "static";
                text = "RNG";
                align = "left";
                scale = 1;
                pos[] = {{0.39,0.86},1};
                right[] = {{0.43,0.86},1};
                down[] = {{0.39,0.9},1};
            };
            class SpeedNumber {
                type = "text";
                align = "right";
                scale = 1;
                source = "speed";
                sourceScale = 1.94384;
                pos[] = {{0.03,0.475},1};
                right[] = {{0.08,0.475},1};
                down[] = {{0.03,0.525},1};
            };
            class TorqueNumber {
                condition = "simulRTD";
                class Torque_number {
                    type = "text";
                    align = "left";
                    scale = 1;
                    source = "rtdRotorTorque";
                    sourceScale = 290;
                    pos[] = {{0.065,0.175},1};
                    right[] = {{0.115,0.175},1};
                    down[] = {{0.065,0.225},1};
                };
                class Torquetext {
                    type = "text";
                    source = "static";
                    text = "%";
                    align = "right";
                    scale = 1;
                    pos[] = {{0.07,0.175},1};
                    right[] = {{0.12,0.175},1};
                    down[] = {{0.07,0.225},1};
                };
            };
            class AltNumber: SpeedNumber {
                align = "right";
                source = "altitudeAGL";
                sourceScale = 3.2808399;
                pos[] = {{0.83,0.475},1};
                right[] = {{0.88,0.475},1};
                down[] = {{0.83,0.525},1};
            };
            class ASLNumber {
                type = "text";
                source = "altitudeASL";
                sourceScale = 3.2808399;
                align = "right";
                scale = 1;
                pos[] = {{0.835,0.18},1};
                right[] = {{0.875,0.18},1};
                down[] = {{0.835,0.22},1};
            };
            class VspeedScalePosta {
                type = "line";
                width = 4;
                points[] = {{{0.98,0.2},1},{{1,0.2},1},{},{{0.93,0.2},1},{{0.95,0.2},1},{},{{0.98,0.35},1},{{1,0.35},1},{},{{0.93,0.35},1},{{0.95,0.35},1},{},{{0.94,0.38},1},{{0.95,0.38},1},{},{{0.94,0.41},1},{{0.95,0.41},1},{},{{0.94,0.44},1},{{0.95,0.44},1},{},{{0.94,0.47},1},{{0.95,0.47},1},{},{{0.98,0.5},1},{{1,0.5},1},{},{{0.93,0.5},1},{{0.95,0.5},1},{},{{0.94,0.53},1},{{0.95,0.53},1},{},{{0.94,0.56},1},{{0.95,0.56},1},{},{{0.94,0.59},1},{{0.95,0.59},1},{},{{0.94,0.62},1},{{0.95,0.62},1},{},{{0.98,0.65},1},{{1,0.65},1},{},{{0.93,0.65},1},{{0.95,0.65},1},{},{{0.99,0.68},1},{{0.98,0.68},1},{},{{0.99,0.71},1},{{0.98,0.71},1},{},{{0.99,0.74},1},{{0.98,0.74},1},{},{{0.99,0.77},1},{{0.98,0.77},1},{},{{0.98,0.8},1},{{1,0.8},1},{},{{0.93,0.8},1},{{0.95,0.8},1},{}};
            };
            class RadarAltitudeBand {
                clipTL[] = {0,0.2};
                clipBR[] = {1,0.8};
                hideValue = 201;
                class radarbanda {
                    type = "line";
                    width = 17;
                    points[] = {{ "RadarAltitudeBone",{0,0},1},{ "RadarAltitudeBone",{0,0.6},1}};
                };
            };
            class VspeedBand {
                type = "line";
                width = 3;
                points[] = {{ "VspeedBone",{-0.01,0},1},{ "VspeedBone",{-0.025,-0.015},1},{ "VspeedBone",{-0.025,0.015},1},{ "VspeedBone",{-0.01,0},1},{}};
            };
            class HeadingNumber: SpeedNumber {
                source = "heading";
                sourceScale = 1;
                align = "center";
                pos[] = {{0.5,0.045},1};
                right[] = {{0.56,0.045},1};
                down[] = {{0.5,"0.045 + 0.06" },1};
            };
            class Center_box {
                type = "line";
                width = 1.5;
                points[] = {{{0.45,"0.02 + 0.085 - 0.06" },1},{{ "0.45 + 0.10","0.02 + 0.085 - 0.06" },1},{{ "0.45 + 0.10","0.02 + 0.085" },1},{{0.45,"0.02 + 0.085" },1},{{0.45,"0.02 + 0.085 - 0.06" },1}};
            };
            class HeadingArrow {
                type = "line";
                width = 7;
                points[] = {{{ "0.5","0.128 + 0.03" },1},{{0.5,0.128},1}};
            };
            class HeadingScale_LEFT {
                clipTL[] = {0,0};
                clipBR[] = {0.45,1};
                class Heading_group {
                    type = "scale";
                    horizontal = 1;
                    source = "heading";
                    sourceScale = 1;
                    width = 5;
                    top = 0.12;
                    center = 0.5;
                    bottom = 0.88;
                    lineXleft = "0.03 + 0.085";
                    lineYright = "0.02 + 0.085";
                    lineXleftMajor = "0.04 + 0.085";
                    lineYrightMajor = "0.02 + 0.085";
                    majorLineEach = 3;
                    numberEach = 3;
                    step = 10;
                    stepSize = "0.05";
                    align = "center";
                    scale = 1;
                    pos[] = {0.12,"0.0 + 0.065" };
                    right[] = {0.16,"0.0 + 0.065" };
                    down[] = {0.12,"0.04 + 0.065" };
                };
            };
            class HeadingScale_RIGHT {
                clipTL[] = {0.55,0};
                clipBR[] = {1,1};
                class Heading_group {
                    type = "scale";
                    horizontal = 1;
                    source = "heading";
                    sourceScale = 1;
                    width = 5;
                    top = 0.12;
                    center = 0.5;
                    bottom = 0.88;
                    lineXleft = "0.03 + 0.085";
                    lineYright = "0.02 + 0.085";
                    lineXleftMajor = "0.04 + 0.085";
                    lineYrightMajor = "0.02 + 0.085";
                    majorLineEach = 3;
                    numberEach = 3;
                    step = 10;
                    stepSize = "0.05";
                    align = "center";
                    scale = 1;
                    pos[] = {0.12,"0.0 + 0.065" };
                    right[] = {0.16,"0.0 + 0.065" };
                    down[] = {0.12,"0.04 + 0.065" };
                };
            };
            class HeadingScale_BOTTOM {
                clipTL[] = {0.45,"0.02 + 0.085" };
                clipBR[] = { "0.45 + 0.10",1};
                class Heading_group {
                    type = "scale";
                    horizontal = 1;
                    source = "heading";
                    sourceScale = 1;
                    width = 5;
                    top = 0.12;
                    center = 0.5;
                    bottom = 0.88;
                    lineXleft = "0.03 + 0.085";
                    lineYright = "0.02 + 0.085";
                    lineXleftMajor = "0.04 + 0.085";
                    lineYrightMajor = "0.02 + 0.085";
                    majorLineEach = 3;
                    numberEach = 3;
                    step = 10;
                    stepSize = "0.05";
                    align = "center";
                    scale = 1;
                    pos[] = {0.12,"0.0 + 0.065" };
                    right[] = {0.16,"0.0 + 0.065" };
                    down[] = {0.12,"0.04 + 0.065" };
                };
            };
            class Fuel_Text {
                type = "text";
                source = "static";
                text = "Fuel";
                align = "right";
                scale = 1;
                pos[] = {{0.03,0.9},1};
                right[] = {{0.07,0.9},1};
                down[] = {{0.03,0.94},1};
            };
            class Fuel_Number {
                type = "text";
                source = "fuel";
                sourceScale = 100;
                align = "right";
                scale = 1;
                pos[] = {{0.1,0.9},1};
                right[] = {{0.14,0.9},1};
                down[] = {{0.1,0.94},1};
            };
        };
        helmetMountedDisplay = 1;
        helmetPosition[] = {-0.04,0.04,0.1};
        helmetRight[] = {0.08,0,0};
        helmetDown[] = {0,-0.08,0};
    };
    class Kimi_HUD_2 {
        topLeft = "HUD_top_left";
        topRight = "HUD_top_right";
        bottomLeft = "HUD_bottom_left";
        borderLeft = 0;
        borderRight = 0;
        borderTop = 0;
        borderBottom = 0;
        color[] = {0.15,1,0.15,1};
        enableParallax = 0;
        class Bones {
            class Velocity {
                type = "vector";
                source = "velocity";
                pos0[] = {0.5,0.5};
                pos10[] = {0.75,0.75};
            };
            class ForwardVec1 {
                type = "vector";
                source = "forward";
                pos0[] = {0,0};
                pos10[] = {0.25,0.25};
            };
            class ForwardVec {
                type = "vector";
                source = "forward";
                pos0[] = {0,0};
                pos10[] = {0.253,0.253};
            };
            class WeaponAim {
                type = "vector";
                source = "weapon";
                pos0[] = {0.5,0.5};
                pos10[] = {0.753,0.753};
            };
            class WeaponAim1 {
                type = "vector";
                source = "weapon";
                pos0[] = {0,0};
                pos10[] = {0.253,0.23};
            };
            class Target {
                type = "vector";
                source = "target";
                pos0[] = {0.5,0.5};
                pos10[] = {0.753,0.753};
            };
            class RadarContact {
                type = "fixed";
                pos[] = {0,0};
            };
            class WeaponFixed {
                type = "fixed";
                pos[] = {0.5,0.5};
                pos10[] = {0.753,0.753};
            };
        };
        class Draw {
            color[] = {0.18,1,0.18};
            alpha = 1;
            condition = "on";
            class PlaneMovementCrosshair {
                type = "line";
                width = 4;
                points[] = {{ "ForwardVec1",1,"Velocity",1,{0,-0.02},1},{ "ForwardVec1",1,"Velocity",1,{0.01,-0.01732},1},{ "ForwardVec1",1,"Velocity",1,{0.01732,-0.01},1},{ "ForwardVec1",1,"Velocity",1,{0.02,0},1},{ "ForwardVec1",1,"Velocity",1,{0.01732,0.01},1},{ "ForwardVec1",1,"Velocity",1,{0.01,0.01732},1},{ "ForwardVec1",1,"Velocity",1,{0,0.02},1},{ "ForwardVec1",1,"Velocity",1,{-0.01,0.01732},1},{ "ForwardVec1",1,"Velocity",1,{-0.01732,0.01},1},{ "ForwardVec1",1,"Velocity",1,{-0.02,0},1},{ "ForwardVec1",1,"Velocity",1,{-0.01732,-0.01},1},{ "ForwardVec1",1,"Velocity",1,{-0.01,-0.01732},1},{ "ForwardVec1",1,"Velocity",1,{0,-0.02},1},{},{ "ForwardVec1",1,"Velocity",1,{0.04,0},1},{ "ForwardVec1",1,"Velocity",1,{0.02,0},1},{},{ "ForwardVec1",1,"Velocity",1,{-0.04,0},1},{ "ForwardVec1",1,"Velocity",1,{-0.02,0},1},{},{ "ForwardVec1",1,"Velocity",1,{0,-0.04},1},{ "ForwardVec1",1,"Velocity",1,{0,-0.02},1}};
            };
            class Gunner_AIM {
                type = "group";
                class Circle {
                    type = "line";
                    width = 2;
                    points[] = {{ "ForwardVec",1,"WeaponAim",1,{0,-0.015},1},{ "ForwardVec",1,"WeaponAim",1,{0,-0.03},1},{},{ "ForwardVec",1,"WeaponAim",1,{0,-0.0325},1},{ "ForwardVec",1,"WeaponAim",1,{0,-0.0475},1},{},{ "ForwardVec",1,"WeaponAim",1,{0,0.015},1},{ "ForwardVec",1,"WeaponAim",1,{0,0.03},1},{},{ "ForwardVec",1,"WeaponAim",1,{0,0.0325},1},{ "ForwardVec",1,"WeaponAim",1,{0,0.0475},1},{},{ "ForwardVec",1,"WeaponAim",1,{-0.015,0},1},{ "ForwardVec",1,"WeaponAim",1,{-0.03,0},1},{},{ "ForwardVec",1,"WeaponAim",1,{-0.0325,0},1},{ "ForwardVec",1,"WeaponAim",1,{-0.0475,0},1},{},{ "ForwardVec",1,"WeaponAim",1,{0.015,0},1},{ "ForwardVec",1,"WeaponAim",1,{0.03,0},1},{},{ "ForwardVec",1,"WeaponAim",1,{0.0325,0},1},{ "ForwardVec",1,"WeaponAim",1,{0.0475,0},1}};
                };
            };
            class GunCross {
                condition = "mgun";
                class Circle {
                    type = "line";
                    width = 4;
                    points[] = {{ "ForwardVec",1,"WeaponAim",1,{0,-0.05},1},{ "ForwardVec",1,"WeaponAim",1,{0,-0.015},1},{},{ "ForwardVec",1,"WeaponAim",1,{0,0.015},1},{ "ForwardVec",1,"WeaponAim",1,{0,0.05},1},{},{ "ForwardVec",1,"WeaponAim",1,{-0.05,0},1},{ "ForwardVec",1,"WeaponAim",1,{-0.015,0},1},{},{ "ForwardVec",1,"WeaponAim",1,{0.015,0},1},{ "ForwardVec",1,"WeaponAim",1,{0.05,0},1},{}};
                };
            };
            class RocketCross {
                condition = "rocket";  
                width = 4;
                class Circle {
                    type = "line";
                    width = 4;
                    points[] = {{ "ForwardVec",1,"WeaponAim",1,{-0.05,-0.08},1},{ "ForwardVec",1,"WeaponAim",1,{0.05,-0.08},1},{},{ "ForwardVec",1,"WeaponAim",1,{0,-0.08},1},{ "ForwardVec",1,"WeaponAim",1,{0,0.08},1},{},{ "ForwardVec",1,"WeaponAim",1,{-0.05,0.08},1},{ "ForwardVec",1,"WeaponAim",1,{0.05,0.08},1},{}};
                };
            };
            class WeaponCrossPilot {
                class Circle {
                    type = "line";
                    width = 2;
                    // points[] = {{ "ForwardVec",1,"WeaponFixed",1,{0,-0.02},1},{ "ForwardVec",1,"WeaponFixed",1,{0,0.02},1},{},{ "ForwardVec",1,"WeaponFixed",1,{-0.02,0},1},{ "ForwardVec",1,"WeaponFixed",1,{0.02, 0},1},{}};
                    points[] = {{ "ForwardVec",1,"WeaponFixed",1,{ "-1.2000 * 0.02","-0.0000 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "-1.0000 * 0.02","-0.0000 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "-0.9877 * 0.02","-0.1736 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "-0.9397 * 0.02","-0.3420 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "-0.8660 * 0.02","-0.5000 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "-0.7660 * 0.02","-0.6428 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "-0.6428 * 0.02","-0.7660 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "-0.5000 * 0.02","-0.8660 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "-0.3420 * 0.02","-0.9397 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "-0.1736 * 0.02","-0.9877 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "-0.0000 * 0.02","-1.0000 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "0.1736 * 0.02","-0.9877 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "0.3420 * 0.02","-0.9397 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "0.5000 * 0.02","-0.8660 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "0.6428 * 0.02","-0.7660 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "0.7660 * 0.02","-0.6428 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "0.8660 * 0.02","-0.5000 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "0.9397 * 0.02","-0.3420 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "0.9877 * 0.02","-0.1736 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "1.0000 * 0.02","-0.0000 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "1.2000 * 0.02","-0.0000 * 0.02" },1},{},{ "ForwardVec",1,"WeaponFixed",1,{ "-1.2000 * 0.02","0.0000 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "-1.0000 * 0.02","0.0000 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "-0.9877 * 0.02","0.1736 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "-0.9397 * 0.02","0.3420 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "-0.8660 * 0.02","0.5000 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "-0.7660 * 0.02","0.6428 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "-0.6428 * 0.02","0.7660 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "-0.5000 * 0.02","0.8660 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "-0.3420 * 0.02","0.9397 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "-0.1736 * 0.02","0.9877 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "-0.0000 * 0.02","1.0000 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "0.1736 * 0.02","0.9877 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "0.3420 * 0.02","0.9397 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "0.5000 * 0.02","0.8660 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "0.6428 * 0.02","0.7660 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "0.7660 * 0.02","0.6428 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "0.8660 * 0.02","0.5000 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "0.9397 * 0.02","0.3420 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "0.9877 * 0.02","0.1736 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "1.0000 * 0.02","0.0000 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "1.2000 * 0.02","0.0000 * 0.02" },1},{},{ "ForwardVec",1,"WeaponFixed",1,{ "-0.0000 * 0.02","-1.0000 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "-0.0000 * 0.02","-1.2000 * 0.02" },1},{},{ "ForwardVec",1,"WeaponFixed",1,{ "-0.0000 * 0.02","1.0000 * 0.02" },1},{ "ForwardVec",1,"WeaponFixed",1,{ "-0.0000 * 0.02","1.2000 * 0.02" },1},{},{ "ForwardVec",1,"WeaponFixed",1,{0.005,0},1},{ "ForwardVec",1,"WeaponFixed",1,{-0.005,0},1},{},{ "ForwardVec",1,"WeaponFixed",1,{0,0.005},1},{ "ForwardVec",1,"WeaponFixed",1,{0,-0.005},1}};
                };
            };
            class AT_Aim {
                condition = "ATmissile";
                width = 2;
                class Circle {
                    type = "line";
                    width = 2;
                    points[] = {{ "ForwardVec",1,"WeaponAim",1,{-0.1,-0.1},1},{ "ForwardVec",1,"WeaponAim",1,{0.1,-0.1},1},{ "ForwardVec",1,"WeaponAim",1,{0.1,0.1},1},{ "ForwardVec",1,"WeaponAim",1,{-0.1,0.1},1},{ "ForwardVec",1,"WeaponAim",1,{-0.1,-0.1},1}};
                };
            };
            class AA_aim {
                condition = "AAmissile";
                class Circle {
                    type = "line";
                    width = 2;
                    points[] = {{ "ForwardVec",1,"WeaponAim",1,{ "0 / 4","-0.248559 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.0434 / 4","-0.244781 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.0855 / 4","-0.233571 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.125 / 4","-0.215252 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.1607 / 4","-0.190396 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.1915 / 4","-0.159774 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.2165 / 4","-0.12428 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.234925 / 4","-0.0850072 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.2462 / 4","-0.0431499 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.25 / 4","0 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.2462 / 4","0.0431499 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.234925 / 4","0.0850072 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.2165 / 4","0.12428 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.1915 / 4","0.159774 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.1607 / 4","0.190396 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.125 / 4","0.215252 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.0855 / 4","0.233571 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.0434 / 4","0.244781 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0 / 4","0.248559 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.0434 / 4","0.244781 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.0855 / 4","0.233571 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.125 / 4","0.215252 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.1607 / 4","0.190396 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.1915 / 4","0.159774 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.2165 / 4","0.12428 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.234925 / 4","0.0850072 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.2462 / 4","0.0431499 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.25 / 4","0 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.2462 / 4","-0.0431499 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.234925 / 4","-0.0850072 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.2165 / 4","-0.12428 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.1915 / 4","-0.159774 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.1607 / 4","-0.190396 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.125 / 4","-0.215252 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.0855 / 4","-0.233571 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.0434 / 4","-0.244781 / 4" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0 / 4","-0.248559 / 4" },1},{},{ "ForwardVec",1,"WeaponAim",1,{ "0 / 2","-0.248559 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.0434 / 2","-0.244781 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.0855 / 2","-0.233571 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.125 / 2","-0.215252 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.1607 / 2","-0.190396 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.1915 / 2","-0.159774 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.2165 / 2","-0.12428 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.234925 / 2","-0.0850072 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.2462 / 2","-0.0431499 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.25 / 2","0 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.2462 / 2","0.0431499 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.234925 / 2","0.0850072 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.2165 / 2","0.12428 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.1915 / 2","0.159774 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.1607 / 2","0.190396 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.125 / 2","0.215252 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.0855 / 2","0.233571 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0.0434 / 2","0.244781 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0 / 2","0.248559 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.0434 / 2","0.244781 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.0855 / 2","0.233571 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.125 / 2","0.215252 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.1607 / 2","0.190396 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.1915 / 2","0.159774 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.2165 / 2","0.12428 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.234925 / 2","0.0850072 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.2462 / 2","0.0431499 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.25 / 2","0 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.2462 / 2","-0.0431499 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.234925 / 2","-0.0850072 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.2165 / 2","-0.12428 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.1915 / 2","-0.159774 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.1607 / 2","-0.190396 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.125 / 2","-0.215252 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.0855 / 2","-0.233571 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "-0.0434 / 2","-0.244781 / 2" },1},{ "ForwardVec",1,"WeaponAim",1,{ "0 / 2","-0.248559 / 2" },1}};
                };
            };
            class TargetACQ {
                type = "line";
                width = 2;
                points[] = {{ "ForwardVec",1,"target",{0,-0.06},1},{ "ForwardVec",1,"target",{0,-0.055},1},{},{ "ForwardVec",1,"target",{0,-0.05},1},{ "ForwardVec",1,"target",{0,-0.045},1},{},{ "ForwardVec",1,"target",{0,-0.04},1},{ "ForwardVec",1,"target",{0,-0.035},1},{},{ "ForwardVec",1,"target",{0,-0.03},1},{ "ForwardVec",1,"target",{0,-0.025},1},{},{ "ForwardVec",1,"target",{0,-0.02},1},{ "ForwardVec",1,"target",{0,-0.015},1},{},{ "ForwardVec",1,"target",{0,-0.01},1},{ "ForwardVec",1,"target",{0,-0.005},1},{},{ "ForwardVec",1,"target",{0,0},1},{ "ForwardVec",1,"target",{0,0},1},{},{ "ForwardVec",1,"target",{0,0.06},1},{ "ForwardVec",1,"target",{0,0.055},1},{},{ "ForwardVec",1,"target",{0,0.05},1},{ "ForwardVec",1,"target",{0,0.045},1},{},{ "ForwardVec",1,"target",{0,0.04},1},{ "ForwardVec",1,"target",{0,0.035},1},{},{ "ForwardVec",1,"target",{0,0.03},1},{ "ForwardVec",1,"target",{0,0.025},1},{},{ "ForwardVec",1,"target",{0,0.02},1},{ "ForwardVec",1,"target",{0,0.015},1},{},{ "ForwardVec",1,"target",{0,0.01},1},{ "ForwardVec",1,"target",{0,0.005},1},{},{ "ForwardVec",1,"target",{-0.06,0},1},{ "ForwardVec",1,"target",{-0.055,0},1},{},{ "ForwardVec",1,"target",{-0.05,0},1},{ "ForwardVec",1,"target",{-0.045,0},1},{},{ "ForwardVec",1,"target",{-0.04,0},1},{ "ForwardVec",1,"target",{-0.035,0},1},{},{ "ForwardVec",1,"target",{-0.03,0},1},{ "ForwardVec",1,"target",{-0.025,0},1},{},{ "ForwardVec",1,"target",{-0.02,0},1},{ "ForwardVec",1,"target",{-0.015,0},1},{},{ "ForwardVec",1,"target",{-0.01,0},1},{ "ForwardVec",1,"target",{-0.005,0},1},{},{ "ForwardVec",1,"target",{0.06,0},1},{ "ForwardVec",1,"target",{0.055,0},1},{},{ "ForwardVec",1,"target",{0.05,0},1},{ "ForwardVec",1,"target",{0.045,0},1},{},{ "ForwardVec",1,"target",{0.04,0},1},{ "ForwardVec",1,"target",{0.035,0},1},{},{ "ForwardVec",1,"target",{0.03,0},1},{ "ForwardVec",1,"target",{0.025,0},1},{},{ "ForwardVec",1,"target",{0.02,0},1},{ "ForwardVec",1,"target",{0.015,0},1},{},{ "ForwardVec",1,"target",{0.01,0},1},{ "ForwardVec",1,"target",{0.005,0},1},{}};
            };
        };
        helmetMountedDisplay = 1;
        helmetPosition[] = {-0.035,0.035,0.1};
        helmetRight[] = {0.07,0,0};
        helmetDown[] = {0,-0.07,0};
    };
};
