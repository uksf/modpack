class MFD {
    class AirplaneHUD {
        class Bones {};
        class Draw {};
        topLeft = "HUD_top_left";
        topRight = "HUD_top_right";
        bottomLeft = "HUD_bottom_left";
        borderLeft = 0;
        borderRight = 0;
        borderTop = 0;
        borderBottom = 0;
        color[] = { 0.15, 1, 0.15, 1 };
        enableParallax = 0;
        helmetMountedDisplay = 1;
        helmetPosition[] = { 0, 0, 0 };
        helmetRight[] = { 0, 0, 0 };
        helmetDown[] = { 0, 0, 0 };
    };
    class Kimi_HUD_1 {
        topLeft = "HUD_top_left";
        topRight = "HUD_top_right";
        bottomLeft = "HUD_bottom_left";
        borderLeft = 0;
        borderRight = 0;
        borderTop = 0;
        borderBottom = 0;
        color[] = { 0.15, 1, 0.15, 1 };
        enableParallax = 0;
        class Bones {
            class PlaneOrientation {
                type = "fixed";
                pos[] = { 0.5, 0.5 };
            };
            class GunnerAim {
                type = "vector";
                source = "weapon";
                pos0[] = { 0.5, "0.9 - 0.04 + 0.02667" };
                pos10[] = { "0.5 + 0.0111", "0.9 - 0.04 + 0.02667 + 0.0133" };
            };
            class Target {
                source = "target";
                type = "vector";
                pos0[] = { 0.5, 0.5 };
                pos10[] = { 0.85, 0.85 };
            };
            class Velocity {
                type = "vector";
                source = "velocity";
                pos0[] = { 0.5, 0.5 };
                pos10[] = { 0.65, 0.65 };
            };
            class Velocity_slip {
                type = "vector";
                source = "velocity";
                pos0[] = { 0.5, 0.845 };
                pos10[] = { 0.53, 0.845 };
            };
            class VspeedBone {
                type = "linear";
                source = "vspeed";
                sourceScale = 1;
                min = -10;
                max = 10;
                minPos[] = { 0.93, 0.2 };
                maxPos[] = { 0.93, 0.8 };
            };
            class RadarAltitudeBone {
                type = "linear";
                source = "altitudeAGL";
                sourceScale = 3.28084;
                min = 0;
                max = 60;
                minPos[] = { 0.965, 0.2 };
                maxPos[] = { 0.965, 0.8 };
            };
            class HorizonBankRot {
                type = "rotational";
                source = "horizonBank";
                center[] = { 0.5, 0.5 };
                min = -3.1416;
                max = 3.1416;
                minAngle = -180;
                maxAngle = 180;
                aspectRatio = 1;
            };
            class ForwardVec {
                type = "vector";
                source = "forward";
                pos0[] = { 0, 0 };
                pos10[] = { 0.2193, 0.2193 };
            };
            class WeaponAim {
                type = "vector";
                source = "weapon";
                pos0[] = { 0.5, 0.5 };
                pos10[] = { 0.753, 0.753 };
            };
            class Level0 {
                type = "horizon";
                pos0[] = { 0.5, 0.5 };
                pos10[] = { 0.78, 0.78 };
                angle = 0;
            };
        };
        class Draw {
            color[] = { 0.18, 1, 0.18 };
            alpha = 1;
            condition = "on";
            class Horizont {
                clipTL[] = { 0.15, 0.15 };
                clipBR[] = { 0.85, 0.85 };
                class Dimmed {
                    class Level0 {
                        type = "line";
                        points[] = { { "Level0", { -0.42, 0 }, 1 }, { "Level0", { -0.38, 0 }, 1 }, {}, { "Level0", { -0.37, 0 }, 1 }, { "Level0", { -0.33, 0 }, 1 }, {}, { "Level0", { -0.32, 0 }, 1 }, { "Level0", { -0.28, 0 }, 1 }, {}, { "Level0", { -0.27, 0 }, 1 }, { "Level0", { -0.23, 0 }, 1 }, {}, { "Level0", { -0.22, 0 }, 1 }, { "Level0", { -0.18, 0 }, 1 }, {}, { "Level0", { -0.17, 0 }, 1 }, { "Level0", { -0.13, 0 }, 1 }, {}, { "Level0", { -0.12, 0 }, 1 }, { "Level0", { -0.08, 0 }, 1 }, {}, { "Level0", { 0.42, 0 }, 1 }, { "Level0", { 0.38, 0 }, 1 }, {}, { "Level0", { 0.37, 0 }, 1 }, { "Level0", { 0.33, 0 }, 1 }, {}, { "Level0", { 0.32, 0 }, 1 }, { "Level0", { 0.28, 0 }, 1 }, {}, { "Level0", { 0.27, 0 }, 1 }, { "Level0", { 0.23, 0 }, 1 }, {}, { "Level0", { 0.22, 0 }, 1 }, { "Level0", { 0.18, 0 }, 1 }, {}, { "Level0", { 0.17, 0 }, 1 }, { "Level0", { 0.13, 0 }, 1 }, {}, { "Level0", { 0.12, 0 }, 1 }, { "Level0", { 0.08, 0 }, 1 } };
                    };
                };
            };
            class HorizonBankRot {
                type = "line";
                width = 3;
                points[] = { { "HorizonBankRot", { 0, 0.25 }, 1 }, { "HorizonBankRot", { -0.01, 0.23 }, 1 }, { "HorizonBankRot", { 0.01, 0.23 }, 1 }, { "HorizonBankRot", { 0, 0.25 }, 1 } };
            };
            class Static_HAD_BOX {
                clipTL[] = { 0, 1 };
                clipBR[] = { 1, 0 };
                type = "line";
                width = 5;
                points[] = { { { "0.5-0.1", "0.9-0.04" }, 1 }, { { "0.5-0.1", "0.9+0.04" }, 1 }, { { "0.5+0.1", "0.9+0.04" }, 1 }, { { "0.5+0.1", "0.9-0.04" }, 1 }, { { "0.5-0.1", "0.9-0.04" }, 1 }, {}, { { "0.5-0.1", "0.9-0.04+0.02667" }, 1 }, { { "0.5-0.092", "0.9-0.04+0.02667" }, 1 }, {}, { { "0.5+0.1", "0.9-0.04+0.02667" }, 1 }, { { "0.5+0.092", "0.9-0.04+0.02667" }, 1 }, {}, { { 0.5, "0.9-0.04" }, 1 }, { { 0.5, "0.9-0.032" }, 1 }, {}, { { 0.5, "0.9+0.04" }, 1 }, { { 0.5, "0.9+0.032" }, 1 }, {} };
            };
            class Gunner_HAD {
                type = "line";
                width = 6;
                points[] = { { "GunnerAim", { -0.015, -0.008 }, 1 }, { "GunnerAim", { -0.015, 0.008 }, 1 }, { "GunnerAim", { 0.015, 0.008 }, 1 }, { "GunnerAim", { 0.015, -0.008 }, 1 }, { "GunnerAim", { -0.015, -0.008 }, 1 } };
            };
            class Centerline {
                type = "line";
                width = 7;
                points[] = { { { 0.5, 0.49 }, 1 }, { { 0.5, 0.47 }, 1 }, {}, { { 0.5, 0.51 }, 1 }, { { 0.5, 0.53 }, 1 }, {}, { { 0.49, 0.5 }, 1 }, { { 0.47, 0.5 }, 1 }, {}, { { 0.51, 0.5 }, 1 }, { { 0.53, 0.5 }, 1 }, {} };
            };
            class Slip_ball_group {
                class Slip_bars {
                    type = "line";
                    width = 4;
                    points[] = { { { "0.5-0.018", "0.9-0.04" }, 1 }, { { "0.5-0.018", "0.9-0.075" }, 1 }, {}, { { "0.5+0.018", "0.9-0.04" }, 1 }, { { "0.5+0.018", "0.9-0.075" }, 1 } };
                };
                class Slip_ball {
                    type = "line";
                    width = 6.0;
                    points[] = { { "Velocity_slip", 1, { "0 * 0.75", "-0.02 * 0.75" }, 1 }, { "Velocity_slip", 1, { "0.0099999998 * 0.75", "-0.01732 * 0.75" }, 1 }, { "Velocity_slip", 1, { "0.01732 * 0.75", "-0.0099999998 * 0.75" }, 1 }, { "Velocity_slip", 1, { "0.02 * 0.75", "0 * 0.75" }, 1 }, { "Velocity_slip", 1, { "0.01732 * 0.75", "0.0099999998 * 0.75" }, 1 }, { "Velocity_slip", 1, { "0.0099999998 * 0.75", "0.01732 * 0.75" }, 1 }, { "Velocity_slip", 1, { "0 * 0.75", "0.02 * 0.75" }, 1 }, { "Velocity_slip", 1, { "-0.0099999998 * 0.75", "0.01732 * 0.75" }, 1 }, { "Velocity_slip", 1, { "-0.01732 * 0.75", "0.0099999998 * 0.75" }, 1 }, { "Velocity_slip", 1, { "-0.02 * 0.75", "0 * 0.75" }, 1 }, { "Velocity_slip", 1, { "-0.01732 * 0.75", "-0.0099999998 * 0.75" }, 1 }, { "Velocity_slip", 1, { "-0.0099999998 * 0.75", "-0.01732 * 0.75" }, 1 }, { "Velocity_slip", 1, { "0 * 0.75", "-0.02 * 0.75" }, 1 }, {}, { "Velocity_slip", 1, { "0 * 0.6", "-0.02 * 0.6" }, 1 }, { "Velocity_slip", 1, { "0.0099999998 * 0.6", "-0.01732 * 0.6" }, 1 }, { "Velocity_slip", 1, { "0.01732 * 0.6", "-0.0099999998 * 0.6" }, 1 }, { "Velocity_slip", 1, { "0.02 * 0.6", "0 * 0.6" }, 1 }, { "Velocity_slip", 1, { "0.01732 * 0.6", "0.0099999998 * 0.6" }, 1 }, { "Velocity_slip", 1, { "0.0099999998 * 0.6", "0.01732 * 0.6" }, 1 }, { "Velocity_slip", 1, { "0 * 0.6", "0.02 * 0.6" }, 1 }, { "Velocity_slip", 1, { "-0.0099999998 * 0.6", "0.01732 * 0.6" }, 1 }, { "Velocity_slip", 1, { "-0.01732 * 0.6", "0.0099999998 * 0.6" }, 1 }, { "Velocity_slip", 1, { "-0.02 * 0.6", "0 * 0.6" }, 1 }, { "Velocity_slip", 1, { "-0.01732 * 0.6", "-0.0099999998 * 0.6" }, 1 }, { "Velocity_slip", 1, { "-0.0099999998 * 0.6", "-0.01732 * 0.6" }, 1 }, { "Velocity_slip", 1, { "0 * 0.6", "-0.02 * 0.6" }, 1 }, {}, { "Velocity_slip", 1, { "0 * 0.5", "-0.02 * 0.5" }, 1 }, { "Velocity_slip", 1, { "0.0099999998 * 0.5", "-0.01732 * 0.5" }, 1 }, { "Velocity_slip", 1, { "0.01732 * 0.5", "-0.0099999998 * 0.5" }, 1 }, { "Velocity_slip", 1, { "0.02 * 0.5", "0 * 0.5" }, 1 }, { "Velocity_slip", 1, { "0.01732 * 0.5", "0.0099999998 * 0.5" }, 1 }, { "Velocity_slip", 1, { "0.0099999998 * 0.5", "0.01732 * 0.5" }, 1 }, { "Velocity_slip", 1, { "0 * 0.5", "0.02 * 0.5" }, 1 }, { "Velocity_slip", 1, { "-0.0099999998 * 0.5", "0.01732 * 0.5" }, 1 }, { "Velocity_slip", 1, { "-0.01732 * 0.5", "0.0099999998 * 0.5" }, 1 }, { "Velocity_slip", 1, { "-0.02 * 0.5", "0 * 0.5" }, 1 }, { "Velocity_slip", 1, { "-0.01732 * 0.5", "-0.0099999998 * 0.5" }, 1 }, { "Velocity_slip", 1, { "-0.0099999998 * 0.5", "-0.01732 * 0.5" }, 1 }, { "Velocity_slip", 1, { "0 * 0.5", "-0.02 * 0.5" }, 1 }, {}, { "Velocity_slip", 1, { "0 * 0.4", "-0.02 * 0.4" }, 1 }, { "Velocity_slip", 1, { "0.0099999998 * 0.4", "-0.01732 * 0.4" }, 1 }, { "Velocity_slip", 1, { "0.01732 * 0.4", "-0.0099999998 * 0.4" }, 1 }, { "Velocity_slip", 1, { "0.02 * 0.4", "0 * 0.4" }, 1 }, { "Velocity_slip", 1, { "0.01732 * 0.4", "0.0099999998 * 0.4" }, 1 }, { "Velocity_slip", 1, { "0.0099999998 * 0.4", "0.01732 * 0.4" }, 1 }, { "Velocity_slip", 1, { "0 * 0.4", "0.02 * 0.4" }, 1 }, { "Velocity_slip", 1, { "-0.0099999998 * 0.4", "0.01732 * 0.4" }, 1 }, { "Velocity_slip", 1, { "-0.01732 * 0.4", "0.0099999998 * 0.4" }, 1 }, { "Velocity_slip", 1, { "-0.02 * 0.4", "0 * 0.4" }, 1 }, { "Velocity_slip", 1, { "-0.01732 * 0.4", "-0.0099999998 * 0.4" }, 1 }, { "Velocity_slip", 1, { "-0.0099999998 * 0.4", "-0.01732 * 0.4" }, 1 }, { "Velocity_slip", 1, { "0 * 0.4", "-0.02 * 0.4" }, 1 }, {}, { "Velocity_slip", 1, { "0 * 0.30", "-0.02 * 0.30" }, 1 }, { "Velocity_slip", 1, { "0.0099999998 * 0.30", "-0.01732 * 0.30" }, 1 }, { "Velocity_slip", 1, { "0.01732 * 0.30", "-0.0099999998 * 0.30" }, 1 }, { "Velocity_slip", 1, { "0.02 * 0.30", "0 * 0.30" }, 1 }, { "Velocity_slip", 1, { "0.01732 * 0.30", "0.0099999998 * 0.30" }, 1 }, { "Velocity_slip", 1, { "0.0099999998 * 0.30", "0.01732 * 0.30" }, 1 }, { "Velocity_slip", 1, { "0 * 0.30", "0.02 * 0.30" }, 1 }, { "Velocity_slip", 1, { "-0.0099999998 * 0.30", "0.01732 * 0.30" }, 1 }, { "Velocity_slip", 1, { "-0.01732 * 0.30", "0.0099999998 * 0.30" }, 1 }, { "Velocity_slip", 1, { "-0.02 * 0.30", "0 * 0.30" }, 1 }, { "Velocity_slip", 1, { "-0.01732 * 0.30", "-0.0099999998 * 0.30" }, 1 }, { "Velocity_slip", 1, { "-0.0099999998 * 0.30", "-0.01732 * 0.30" }, 1 }, { "Velocity_slip", 1, { "0 * 0.30", "-0.02 * 0.30" }, 1 }, {}, { "Velocity_slip", 1, { "0 * 0.20", "-0.02 * 0.20" }, 1 }, { "Velocity_slip", 1, { "0.0099999998 * 0.20", "-0.01732 * 0.20" }, 1 }, { "Velocity_slip", 1, { "0.01732 * 0.20", "-0.0099999998 * 0.20" }, 1 }, { "Velocity_slip", 1, { "0.02 * 0.20", "0 * 0.20" }, 1 }, { "Velocity_slip", 1, { "0.01732 * 0.20", "0.0099999998 * 0.20" }, 1 }, { "Velocity_slip", 1, { "0.0099999998 * 0.20", "0.01732 * 0.20" }, 1 }, { "Velocity_slip", 1, { "0 * 0.20", "0.02 * 0.20" }, 1 }, { "Velocity_slip", 1, { "-0.0099999998 * 0.20", "0.01732 * 0.20" }, 1 }, { "Velocity_slip", 1, { "-0.01732 * 0.20", "0.0099999998 * 0.20" }, 1 }, { "Velocity_slip", 1, { "-0.02 * 0.20", "0 * 0.20" }, 1 }, { "Velocity_slip", 1, { "-0.01732 * 0.20", "-0.0099999998 * 0.20" }, 1 }, { "Velocity_slip", 1, { "-0.0099999998 * 0.20", "-0.01732 * 0.20" }, 1 }, { "Velocity_slip", 1, { "0 * 0.20", "-0.02 * 0.20" }, 1 }, {}, { "Velocity_slip", 1, { "0 * 0.1", "-0.02 * 0.1" }, 1 }, { "Velocity_slip", 1, { "0.0099999998 * 0.1", "-0.01732 * 0.1" }, 1 }, { "Velocity_slip", 1, { "0.01732 * 0.1", "-0.0099999998 * 0.1" }, 1 }, { "Velocity_slip", 1, { "0.02 * 0.1", "0 * 0.1" }, 1 }, { "Velocity_slip", 1, { "0.01732 * 0.1", "0.0099999998 * 0.1" }, 1 }, { "Velocity_slip", 1, { "0.0099999998 * 0.1", "0.01732 * 0.1" }, 1 }, { "Velocity_slip", 1, { "0 * 0.1", "0.02 * 0.1" }, 1 }, { "Velocity_slip", 1, { "-0.0099999998 * 0.1", "0.01732 * 0.1" }, 1 }, { "Velocity_slip", 1, { "-0.01732 * 0.1", "0.0099999998 * 0.1" }, 1 }, { "Velocity_slip", 1, { "-0.02 * 0.1", "0 * 0.1" }, 1 }, { "Velocity_slip", 1, { "-0.01732 * 0.1", "-0.0099999998 * 0.1" }, 1 }, { "Velocity_slip", 1, { "-0.0099999998 * 0.1", "-0.01732 * 0.1" }, 1 }, { "Velocity_slip", 1, { "0 * 0.1", "-0.02 * 0.1" }, 1 } };
                };
            };
            class GunCross_CIRCLE {
                type = "group";
                class CCIP_circle {
                    type = "line";
                    width = 4.0;
                    points[] = { { "ForwardVec", 1, "PlaneOrientation", 1, { "-1.2000 * 0.04", "-0.0000 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "-1.0000 * 0.04", "-0.0000 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "-0.9877 * 0.04", "-0.1736 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "-0.9397 * 0.04", "-0.3420 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "-0.8660 * 0.04", "-0.5000 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "-0.7660 * 0.04", "-0.6428 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "-0.6428 * 0.04", "-0.7660 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "-0.5000 * 0.04", "-0.8660 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "-0.3420 * 0.04", "-0.9397 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "-0.1736 * 0.04", "-0.9877 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "-0.0000 * 0.04", "-1.0000 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "0.1736 * 0.04", "-0.9877 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "0.3420 * 0.04", "-0.9397 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "0.5000 * 0.04", "-0.8660 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "0.6428 * 0.04", "-0.7660 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "0.7660 * 0.04", "-0.6428 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "0.8660 * 0.04", "-0.5000 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "0.9397 * 0.04", "-0.3420 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "0.9877 * 0.04", "-0.1736 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "1.0000 * 0.04", "-0.0000 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "1.2000 * 0.04", "-0.0000 * 0.04" }, 1 }, {}, { "ForwardVec", 1, "PlaneOrientation", 1, { "-1.2000 * 0.04", "0.0000 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "-1.0000 * 0.04", "0.0000 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "-0.9877 * 0.04", "0.1736 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "-0.9397 * 0.04", "0.3420 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "-0.8660 * 0.04", "0.5000 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "-0.7660 * 0.04", "0.6428 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "-0.6428 * 0.04", "0.7660 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "-0.5000 * 0.04", "0.8660 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "-0.3420 * 0.04", "0.9397 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "-0.1736 * 0.04", "0.9877 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "-0.0000 * 0.04", "1.0000 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "0.1736 * 0.04", "0.9877 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "0.3420 * 0.04", "0.9397 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "0.5000 * 0.04", "0.8660 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "0.6428 * 0.04", "0.7660 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "0.7660 * 0.04", "0.6428 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "0.8660 * 0.04", "0.5000 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "0.9397 * 0.04", "0.3420 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "0.9877 * 0.04", "0.1736 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "1.0000 * 0.04", "0.0000 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "1.2000 * 0.04", "0.0000 * 0.04" }, 1 }, {}, { "ForwardVec", 1, "PlaneOrientation", 1, { "-0.0000 * 0.04", "-1.0000 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "-0.0000 * 0.04", "-1.2000 * 0.04" }, 1 }, {}, { "ForwardVec", 1, "PlaneOrientation", 1, { "-0.0000 * 0.04", "1.0000 * 0.04" }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { "-0.0000 * 0.04", "1.2000 * 0.04" }, 1 }, {}, { "ForwardVec", 1, "PlaneOrientation", 1, { 0.005, 0 }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { -0.005, 0 }, 1 }, {}, { "ForwardVec", 1, "PlaneOrientation", 1, { 0, 0.005 }, 1 }, { "ForwardVec", 1, "PlaneOrientation", 1, { 0, -0.005 }, 1 } };
                };
            };
            class WeaponName {
                type = "text";
                source = "weapon";
                sourceScale = 1;
                align = "right";
                scale = 1;
                pos[] = { { 0.61, 0.86 }, 1 };
                right[] = { { 0.65, 0.86 }, 1 };
                down[] = { { 0.61, 0.9 }, 1 };
            };
            class Ammo_ALL {
                type = "group";
                condition = "on";
                class Ammo_count_ALL {
                    type = "text";
                    source = "ammo";
                    sourceScale = 1;
                    align = "right";
                    scale = 1;
                    pos[] = { { 0.61, 0.89 }, 1 };
                    right[] = { { 0.65, 0.89 }, 1 };
                    down[] = { { 0.61, 0.93 }, 1 };
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
                    pos[] = { { 0.03, "0.53 + 0.055" }, 1 };
                    right[] = { { 0.07, "0.53 + 0.055" }, 1 };
                    down[] = { { 0.03, "0.53 + 0.095" }, 1 };
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
                    pos[] = { { 0.03, "0.53 + 0.105" }, 1 };
                    right[] = { { 0.07, "0.53 + 0.105" }, 1 };
                    down[] = { { 0.03, "0.53 + 0.145" }, 1 };
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
                    pos[] = { { 0.61, 0.92 }, 1 };
                    right[] = { { 0.65, 0.92 }, 1 };
                    down[] = { { 0.61, 0.96 }, 1 };
                };
                class TOFnumber {
                    type = "text";
                    source = "targetDist";
                    sourcescale = 0.0025;
                    align = "right";
                    scale = 1;
                    pos[] = { { 0.69, 0.92 }, 1 };
                    right[] = { { 0.73, 0.92 }, 1 };
                    down[] = { { 0.69, 0.96 }, 1 };
                };
            };
            class RangeNumber {
                type = "text";
                source = "targetDist";
                sourceScale = 1;
                align = "left";
                scale = 1;
                pos[] = { { 0.39, 0.89 }, 1 };
                right[] = { { 0.43, 0.89 }, 1 };
                down[] = { { 0.39, 0.93 }, 1 };
            };
            class RangeText {
                type = "text";
                source = "static";
                text = "RNG";
                align = "left";
                scale = 1;
                pos[] = { { 0.39, 0.86 }, 1 };
                right[] = { { 0.43, 0.86 }, 1 };
                down[] = { { 0.39, 0.9 }, 1 };
            };
            class SpeedNumber {
                type = "text";
                align = "right";
                scale = 1;
                source = "speed";
                sourceScale = 1.94384;
                pos[] = { { 0.03, 0.475 }, 1 };
                right[] = { { 0.08, 0.475 }, 1 };
                down[] = { { 0.03, 0.525 }, 1 };
            };
            class TorqueNumber {
                condition = "simulRTD";
                class Torque_number {
                    type = "text";
                    align = "left";
                    scale = 1;
                    source = "rtdRotorTorque";
                    sourceScale = 363;
                    pos[] = { { 0.065, 0.175 }, 1 };
                    right[] = { { 0.115, 0.175 }, 1 };
                    down[] = { { 0.065, 0.225 }, 1 };
                };
                class Torquetext {
                    type = "text";
                    source = "static";
                    text = "%";
                    align = "right";
                    scale = 1;
                    pos[] = { { 0.07, 0.175 }, 1 };
                    right[] = { { 0.12, 0.175 }, 1 };
                    down[] = { { 0.07, 0.225 }, 1 };
                };
            };
            class AltNumber : SpeedNumber {
                align = "right";
                source = "altitudeAGL";
                sourceScale = 3.28084;
                pos[] = { { 0.83, 0.475 }, 1 };
                right[] = { { 0.88, 0.475 }, 1 };
                down[] = { { 0.83, 0.525 }, 1 };
            };
            class ASLNumber {
                type = "text";
                source = "altitudeASL";
                sourceScale = 3.28084;
                align = "right";
                scale = 1;
                pos[] = { { 0.835, 0.18 }, 1 };
                right[] = { { 0.875, 0.18 }, 1 };
                down[] = { { 0.835, 0.22 }, 1 };
            };
            class VspeedScalePosta {
                type = "line";
                width = 5;
                points[] = { { { 0.98, 0.2 }, 1 }, { { 1.0, 0.2 }, 1 }, {}, { { 0.93, 0.2 }, 1 }, { { 0.95, 0.2 }, 1 }, {}, { { 0.98, 0.35 }, 1 }, { { 1.0, 0.35 }, 1 }, {}, { { 0.93, 0.35 }, 1 }, { { 0.95, 0.35 }, 1 }, {}, { { 0.94, 0.38 }, 1 }, { { 0.95, 0.38 }, 1 }, {}, { { 0.94, 0.41 }, 1 }, { { 0.95, 0.41 }, 1 }, {}, { { 0.94, 0.44 }, 1 }, { { 0.95, 0.44 }, 1 }, {}, { { 0.94, 0.47 }, 1 }, { { 0.95, 0.47 }, 1 }, {}, { { 0.98, 0.5 }, 1 }, { { 1.0, 0.5 }, 1 }, {}, { { 0.93, 0.5 }, 1 }, { { 0.95, 0.5 }, 1 }, {}, { { 0.94, 0.53 }, 1 }, { { 0.95, 0.53 }, 1 }, {}, { { 0.94, 0.56 }, 1 }, { { 0.95, 0.56 }, 1 }, {}, { { 0.94, 0.59 }, 1 }, { { 0.95, 0.59 }, 1 }, {}, { { 0.94, 0.62 }, 1 }, { { 0.95, 0.62 }, 1 }, {}, { { 0.98, 0.65 }, 1 }, { { 1.0, 0.65 }, 1 }, {}, { { 0.93, 0.65 }, 1 }, { { 0.95, 0.65 }, 1 }, {}, { { 0.99, 0.68 }, 1 }, { { 0.98, 0.68 }, 1 }, {}, { { 0.99, 0.71 }, 1 }, { { 0.98, 0.71 }, 1 }, {}, { { 0.99, 0.74 }, 1 }, { { 0.98, 0.74 }, 1 }, {}, { { 0.99, 0.77 }, 1 }, { { 0.98, 0.77 }, 1 }, {}, { { 0.98, 0.8 }, 1 }, { { 1.0, 0.8 }, 1 }, {}, { { 0.93, 0.8 }, 1 }, { { 0.95, 0.8 }, 1 }, {} };
            };
            class RadarAltitudeBand {
                clipTL[] = { 0, 0.2 };
                clipBR[] = { 1, 0.8 };
                class radarbanda {
                    type = "line";
                    width = 17;
                    points[] = { { "RadarAltitudeBone", { 0, 0 }, 1 }, { "RadarAltitudeBone", { 0, 0.6 }, 1 } };
                };
            };
            class VspeedBand {
                type = "line";
                width = 3;
                points[] = { { "VspeedBone", { -0.01, 0.0 }, 1 }, { "VspeedBone", { -0.025, -0.015 }, 1 }, { "VspeedBone", { -0.025, 0.015 }, 1 }, { "VspeedBone", { -0.01, 0.0 }, 1 }, {} };
            };
            class HeadingNumber : SpeedNumber {
                source = "heading";
                sourceScale = 1;
                align = "center";
                pos[] = { { 0.5, 0.01 }, 1 };
                right[] = { { 0.56, 0.01 }, 1 };
                down[] = { { 0.5, 0.06 }, 1 };
            };
            class Center_box {
                type = "line";
                width = 3.0;
                points[] = { { { 0.44, 0.005 }, 1 }, { { "0.44 + 0.12", 0.005 }, 1 }, { { "0.44 + 0.12", "0.005 + 0.06" }, 1 }, { { 0.44, "0.005 + 0.06" }, 1 }, { { 0.44, 0.005 }, 1 } };
            };
            class HeadingArrow {
                type = "line";
                width = 7;
                points[] = { { { "0.5", "0.128 + 0.03" }, 1 }, { { 0.5, 0.128 }, 1 } };
            };
            class HeadingScale {
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
                pos[] = { 0.119, "0.0 + 0.065" };
                right[] = { 0.159, "0.0 + 0.065" };
                down[] = { 0.119, "0.04 + 0.065" };
            };
            class Fuel_Text {
                type = "text";
                source = "static";
                text = "Fuel";
                align = "right";
                scale = 1;
                pos[] = { { 0.03, 0.9 }, 1 };
                right[] = { { 0.07, 0.9 }, 1 };
                down[] = { { 0.03, 0.94 }, 1 };
            };
            class Fuel_Number {
                type = "text";
                source = "fuel";
                sourceScale = 100;
                align = "right";
                scale = 1;
                pos[] = { { 0.1, 0.9 }, 1 };
                right[] = { { 0.14, 0.9 }, 1 };
                down[] = { { 0.1, 0.94 }, 1 };
            };
        };
        helmetMountedDisplay = 1;
        helmetPosition[] = { -0.04, 0.04, 0.1 };
        helmetRight[] = { 0.08, 0, 0 };
        helmetDown[] = { 0, -0.08, 0 };
    };
    class Kimi_HUD_2 {
        topLeft = "HUD_top_left";
        topRight = "HUD_top_right";
        bottomLeft = "HUD_bottom_left";
        borderLeft = 0;
        borderRight = 0;
        borderTop = 0;
        borderBottom = 0;
        color[] = { 0.15, 1, 0.15, 1 };
        enableParallax = 0;
        class Bones {
            class Velocity {
                type = "vector";
                source = "velocity";
                pos0[] = { 0.5, 0.5 };
                pos10[] = { 0.75, 0.75 };
            };
            class ForwardVec1 {
                type = "vector";
                source = "forward";
                pos0[] = { 0, 0 };
                pos10[] = { 0.25, 0.25 };
            };
            class ForwardVec {
                type = "vector";
                source = "forward";
                pos0[] = { 0, 0 };
                pos10[] = { 0.253, 0.253 };
            };
            class WeaponAim {
                type = "vector";
                source = "weapon";
                pos0[] = { 0.5, 0.5 };
                pos10[] = { 0.753, 0.753 };
            };
            class WeaponAim1 {
                type = "vector";
                source = "weapon";
                pos0[] = { 0, 0 };
                pos10[] = { 0.253, 0.23 };
            };
            class Target {
                type = "vector";
                source = "target";
                pos0[] = { 0.5, 0.5 };
                pos10[] = { 0.753, 0.753 };
            };
            class RadarContact {
                type = "fixed";
                pos[] = { 0, 0 };
            };
        };
        class Draw {
            color[] = { 0.18, 1, 0.18 };
            alpha = 1;
            condition = "on";
            class PlaneMovementCrosshair {
                type = "line";
                width = 7;
                points[] = { { "ForwardVec1", 1, "Velocity", 1, { 0, -0.02 }, 1 }, { "ForwardVec1", 1, "Velocity", 1, { 0.01, -0.01732 }, 1 }, { "ForwardVec1", 1, "Velocity", 1, { 0.01732, -0.01 }, 1 }, { "ForwardVec1", 1, "Velocity", 1, { 0.02, 0 }, 1 }, { "ForwardVec1", 1, "Velocity", 1, { 0.01732, 0.01 }, 1 }, { "ForwardVec1", 1, "Velocity", 1, { 0.01, 0.01732 }, 1 }, { "ForwardVec1", 1, "Velocity", 1, { 0, 0.02 }, 1 }, { "ForwardVec1", 1, "Velocity", 1, { -0.01, 0.01732 }, 1 }, { "ForwardVec1", 1, "Velocity", 1, { -0.01732, 0.01 }, 1 }, { "ForwardVec1", 1, "Velocity", 1, { -0.02, 0 }, 1 }, { "ForwardVec1", 1, "Velocity", 1, { -0.01732, -0.01 }, 1 }, { "ForwardVec1", 1, "Velocity", 1, { -0.01, -0.01732 }, 1 }, { "ForwardVec1", 1, "Velocity", 1, { 0, -0.02 }, 1 }, {}, { "ForwardVec1", 1, "Velocity", 1, { 0.04, 0 }, 1 }, { "ForwardVec1", 1, "Velocity", 1, { 0.02, 0 }, 1 }, {}, { "ForwardVec1", 1, "Velocity", 1, { -0.04, 0 }, 1 }, { "ForwardVec1", 1, "Velocity", 1, { -0.02, 0 }, 1 }, {}, { "ForwardVec1", 1, "Velocity", 1, { 0, -0.04 }, 1 }, { "ForwardVec1", 1, "Velocity", 1, { 0, -0.02 }, 1 } };
            };
            class Gunner_AIM {
                type = "line";
                width = 7.0;
                points[] = { { "ForwardVec", 1, "WeaponAim", 1, { 0, -0.02 }, 1 }, { "ForwardVec", 1, "WeaponAim", 1, { 0, -0.01 }, 1 }, {}, { "ForwardVec", 1, "WeaponAim", 1, { 0, -0.0225 }, 1 }, { "ForwardVec", 1, "WeaponAim", 1, { 0, -0.0325 }, 1 }, {}, { "ForwardVec", 1, "WeaponAim", 1, { 0, 0.01 }, 1 }, { "ForwardVec", 1, "WeaponAim", 1, { 0, 0.02 }, 1 }, {}, { "ForwardVec", 1, "WeaponAim", 1, { 0, 0.0225 }, 1 }, { "ForwardVec", 1, "WeaponAim", 1, { 0, 0.0325 }, 1 }, {}, { "ForwardVec", 1, "WeaponAim", 1, { -0.02, 0 }, 1 }, { "ForwardVec", 1, "WeaponAim", 1, { -0.01, 0 }, 1 }, {}, { "ForwardVec", 1, "WeaponAim", 1, { -0.0225, 0 }, 1 }, { "ForwardVec", 1, "WeaponAim", 1, { -0.0325, 0 }, 1 }, {}, { "ForwardVec", 1, "WeaponAim", 1, { 0.01, 0 }, 1 }, { "ForwardVec", 1, "WeaponAim", 1, { 0.02, 0 }, 1 }, {}, { "ForwardVec", 1, "WeaponAim", 1, { 0.0225, 0 }, 1 }, { "ForwardVec", 1, "WeaponAim", 1, { 0.0325, 0 }, 1 } };
            };
            class TargetACQ {
                type = "line";
                width = 2;
                points[] = { { "ForwardVec", 1, "target", { 0, -0.06 }, 1 }, { "ForwardVec", 1, "target", { 0, -0.055 }, 1 }, {}, { "ForwardVec", 1, "target", { 0, -0.05 }, 1 }, { "ForwardVec", 1, "target", { 0, -0.045 }, 1 }, {}, { "ForwardVec", 1, "target", { 0, -0.04 }, 1 }, { "ForwardVec", 1, "target", { 0, -0.035 }, 1 }, {}, { "ForwardVec", 1, "target", { 0, -0.03 }, 1 }, { "ForwardVec", 1, "target", { 0, -0.025 }, 1 }, {}, { "ForwardVec", 1, "target", { 0, -0.02 }, 1 }, { "ForwardVec", 1, "target", { 0, -0.015 }, 1 }, {}, { "ForwardVec", 1, "target", { 0, -0.01 }, 1 }, { "ForwardVec", 1, "target", { 0, -0.005 }, 1 }, {}, { "ForwardVec", 1, "target", { 0, 0 }, 1 }, { "ForwardVec", 1, "target", { 0, 0 }, 1 }, {}, { "ForwardVec", 1, "target", { 0, 0.06 }, 1 }, { "ForwardVec", 1, "target", { 0, 0.055 }, 1 }, {}, { "ForwardVec", 1, "target", { 0, 0.05 }, 1 }, { "ForwardVec", 1, "target", { 0, 0.045 }, 1 }, {}, { "ForwardVec", 1, "target", { 0, 0.04 }, 1 }, { "ForwardVec", 1, "target", { 0, 0.035 }, 1 }, {}, { "ForwardVec", 1, "target", { 0, 0.03 }, 1 }, { "ForwardVec", 1, "target", { 0, 0.025 }, 1 }, {}, { "ForwardVec", 1, "target", { 0, 0.02 }, 1 }, { "ForwardVec", 1, "target", { 0, 0.015 }, 1 }, {}, { "ForwardVec", 1, "target", { 0, 0.01 }, 1 }, { "ForwardVec", 1, "target", { 0, 0.005 }, 1 }, {}, { "ForwardVec", 1, "target", { -0.06, 0 }, 1 }, { "ForwardVec", 1, "target", { -0.055, 0 }, 1 }, {}, { "ForwardVec", 1, "target", { -0.05, 0 }, 1 }, { "ForwardVec", 1, "target", { -0.045, 0 }, 1 }, {}, { "ForwardVec", 1, "target", { -0.04, 0 }, 1 }, { "ForwardVec", 1, "target", { -0.035, 0 }, 1 }, {}, { "ForwardVec", 1, "target", { -0.03, 0 }, 1 }, { "ForwardVec", 1, "target", { -0.025, 0 }, 1 }, {}, { "ForwardVec", 1, "target", { -0.02, 0 }, 1 }, { "ForwardVec", 1, "target", { -0.015, 0 }, 1 }, {}, { "ForwardVec", 1, "target", { -0.01, 0 }, 1 }, { "ForwardVec", 1, "target", { -0.005, 0 }, 1 }, {}, { "ForwardVec", 1, "target", { 0.06, 0 }, 1 }, { "ForwardVec", 1, "target", { 0.055, 0 }, 1 }, {}, { "ForwardVec", 1, "target", { 0.05, 0 }, 1 }, { "ForwardVec", 1, "target", { 0.045, 0 }, 1 }, {}, { "ForwardVec", 1, "target", { 0.04, 0 }, 1 }, { "ForwardVec", 1, "target", { 0.035, 0 }, 1 }, {}, { "ForwardVec", 1, "target", { 0.03, 0 }, 1 }, { "ForwardVec", 1, "target", { 0.025, 0 }, 1 }, {}, { "ForwardVec", 1, "target", { 0.02, 0 }, 1 }, { "ForwardVec", 1, "target", { 0.015, 0 }, 1 }, {}, { "ForwardVec", 1, "target", { 0.01, 0 }, 1 }, { "ForwardVec", 1, "target", { 0.005, 0 }, 1 }, {} };
            };
        };
        helmetMountedDisplay = 1;
        helmetPosition[] = { -0.035, 0.035, 0.1 };
        helmetRight[] = { 0.07, 0, 0 };
        helmetDown[] = { 0, -0.07, 0 };
    };
    class MFD_2_STATIC {
        topLeft = "mfd_2_tl";
        topRight = "mfd_2_tr";
        bottomLeft = "mfd_2_bl";
        borderLeft = 0;
        borderRight = 0;
        borderTop = 0;
        borderBottom = 0;
        color[] = { 0.9, 0.9, 0.9, 1 };
        enableParallax = 0;
        class Bones {
            class pos_laser_text {
                type = "fixed";
                pos[] = { 0.5, 0.125 };
            };
            class pos_radar_text {
                type = "fixed";
                pos[] = { 0.25, 0.125 };
            };
            class pos_range_text {
                type = "fixed";
                pos[] = { 0.25, 0.2 };
            };
            class pos_range_dist {
                type = "fixed";
                pos[] = { 0.35, 0.2 };
            };
            class pos_gridx {
                type = "fixed";
                pos[] = { 0.685, 0.664 };
            };
            class pos_gridy {
                type = "fixed";
                pos[] = { 0.785, 0.664 };
            };
        };
        class Draw {
            alpha = 0.9;
            color[] = { 0.9, 0.9, 0.9, 1 };
            condition = "on";
            class HeadingRotation {
                condition = "abs(cameraDir-heading)*( (abs(heading-cameraDir))<=355)-5";
                class HeadingHeadNumber {
                    type = "text";
                    source = "cameraDir";
                    sourceScale = 1;
                    align = "center";
                    scale = 1;
                    pos[] = { { "0.80-0.302", "0.082-0.025" }, 1 };
                    right[] = { { "0.83-0.302", "0.082-0.025" }, 1 };
                    down[] = { { "0.80-0.302", "0.113-0.025" }, 1 };
                };
                class HeadingArrow {
                    type = "line";
                    width = 2;
                    points[] = { { { 0.478, 0.045 }, 1 }, { { 0.522, 0.045 }, 1 }, { { 0.552, 0.07 }, 1 }, { { 0.522, 0.095 }, 1 }, { { 0.478, 0.095 }, 1 }, { { 0.448, 0.07 }, 1 }, { { 0.478, 0.045 }, 1 }, {} };
                };
                class HeadingScaleRight {
                    clipTL[] = { 0.55, 0.05 };
                    clipBR[] = { 0.83, 0.11 };
                    class lines {
                        type = "scale";
                        horizontal = 1;
                        source = "heading";
                        sourceScale = 1;
                        width = 4;
                        top = 0.5;
                        center = 0.5;
                        bottom = 0.85;
                        lineXleft = 0.11;
                        lineYright = 0.1;
                        lineXleftMajor = 0.11;
                        lineYrightMajor = 0.09;
                        majorLineEach = 2;
                        numberEach = 2;
                        step = 22.5;
                        stepSize = 0.075;
                        align = "center";
                        scale = 1;
                        pos[] = { 0.496, 0.05 };
                        right[] = { 0.536, 0.05 };
                        down[] = { 0.496, 0.09 };
                    };
                };
                class HeadingScaleMidle {
                    type = "scale";
                    horizontal = 1;
                    source = "heading";
                    sourceScale = 1;
                    width = 1;
                    top = 0.45;
                    center = 0.5;
                    bottom = 0.55;
                    lineXleft = 0.11;
                    lineYright = 0.1;
                    lineXleftMajor = 0.11;
                    lineYrightMajor = 0.1;
                    majorLineEach = 2;
                    step = 22.5;
                    stepSize = 0.075;
                    align = "center";
                    scale = 1;
                    numberEach = 0;
                    pos[] = { 0.47, 0.05 };
                    right[] = { 0.5, 0.05 };
                    down[] = { 0.45, 0.09 };
                };
                class HeadingScaleLeft {
                    clipTL[] = { 0.18, 0.05 };
                    clipBR[] = { 0.45, 0.11 };
                    class lines {
                        type = "scale";
                        horizontal = 1;
                        source = "heading";
                        sourceScale = 1;
                        width = 1;
                        top = 0.15;
                        center = 0.5;
                        bottom = 0.55;
                        lineXleft = 0.11;
                        lineYright = 0.1;
                        lineXleftMajor = 0.11;
                        lineYrightMajor = 0.09;
                        majorLineEach = 2;
                        numberEach = 2;
                        step = 22.5;
                        stepSize = 0.075;
                        align = "center";
                        scale = 1;
                        pos[] = { 0.146, 0.05 };
                        right[] = { 0.186, 0.05 };
                        down[] = { 0.146, 0.09 };
                    };
                };
            };
            class HeadingScaleFull {
                condition = "4-abs(cameraDir-heading)*( (abs(heading-cameraDir))<=355)";
                class HeadingScale {
                    clipTL[] = { 0.18, 0 };
                    clipBR[] = { 0.83, 1 };
                    class lines {
                        type = "scale";
                        horizontal = 1;
                        source = "heading";
                        sourceScale = 1;
                        width = 1;
                        top = 0.15;
                        center = 0.5;
                        bottom = 0.85;
                        lineXleft = 0.11;
                        lineYright = 0.1;
                        lineXleftMajor = 0.11;
                        lineYrightMajor = 0.09;
                        majorLineEach = 2;
                        numberEach = 2;
                        step = 22.5;
                        stepSize = 0.075;
                        align = "center";
                        scale = 1;
                        pos[] = { 0.146, 0.05 };
                        right[] = { 0.186, 0.05 };
                        down[] = { 0.146, 0.09 };
                    };
                };
            };
            class LaserGroup {
                condition = "laseron";
                color[] = { 1, 0, 0, 1 };
                class laserText {
                    type = "text";
                    source = "static";
                    text = "LASER";
                    scale = 1;
                    sourceScale = 1;
                    align = "right";
                    pos[] = { "pos_laser_text", { -0.03, -0.036 }, 1 };
                    right[] = { "pos_laser_text", { 0.016, -0.036 }, 1 };
                    down[] = { "pos_laser_text", { -0.03, 0.016 }, 1 };
                };
            };
            class RadarGroup {
                condition = "activeSensorsOn";
                class radarText {
                    type = "text";
                    source = "static";
                    text = "RADAR";
                    scale = 1;
                    sourceScale = 1;
                    align = "right";
                    pos[] = { "pos_radar_text", { -0.03, -0.036 }, 1 };
                    right[] = { "pos_radar_text", { 0.016, -0.036 }, 1 };
                    down[] = { "pos_radar_text", { -0.03, 0.016 }, 1 };
                };
            };
            class RangeText {
                type = "text";
                source = "static";
                text = "Range:";
                scale = 1;
                sourceScale = 1;
                align = "right";
                pos[] = { "pos_range_text", { -0.03, -0.036 }, 1 };
                right[] = { "pos_range_text", { 0.016, -0.036 }, 1 };
                down[] = { "pos_range_text", { -0.03, 0.016 }, 1 };
            };
            class RangeDist {
                type = "text";
                source = "laserDist";
                sourceScale = 1;
                sourceLength = 4;
                align = "right";
                scale = 1;
                pos[] = { "pos_range_dist", { -0.03, -0.036 }, 1 };
                right[] = { "pos_range_dist", { 0.016, -0.036 }, 1 };
                down[] = { "pos_range_dist", { -0.03, 0.016 }, 1 };
            };
            class GridX {
                type = "text";
                source = "coordinateX";
                sourceScale = 0.01;
                sourceOffset = -0.5;
                sourceLength = 3;
                align = "right";
                scale = 1;
                pos[] = { "pos_gridx", { -0.04, -0.048 }, 1 };
                right[] = { "pos_gridx", { 0.0213, -0.048 }, 1 };
                down[] = { "pos_gridx", { -0.04, 0.0213 }, 1 };
            };
            class GridY : GridX {
                source = "coordinateY";
                pos[] = { "pos_gridy", { -0.04, -0.048 }, 1 };
                right[] = { "pos_gridy", { 0.0213, -0.048 }, 1 };
                down[] = { "pos_gridy", { -0.04, 0.0213 }, 1 };
            };
        };
    };
    class MFD_3_STATIC {
        topLeft = "mfd_3_tl";
        topRight = "mfd_3_tr";
        bottomLeft = "mfd_3_bl";
        borderLeft = 0;
        borderRight = 0;
        borderTop = 0;
        borderBottom = 0;
        color[] = { 0.75, 0.75, 0.75, 1 };
        enableParallax = 0;
        class Bones {
            class pos_profile {
                type = "fixed";
                pos[] = { 0.5, 0 };
            };
            class pos_cm_label {
                type = "fixed";
                pos[] = { 0.9, 0.07 };
            };
            class pos_cm_ammo {
                type = "fixed";
                pos[] = { 0.9, 0.11 };
            };
            class pos_mastercaution {
                type = "fixed";
                pos[] = { 0.2, 0.09 };
            };
            class pos_fuel_label {
                type = "fixed";
                pos[] = { 0.65, 0.685 };
            };
            class pos_fuel_value {
                type = "fixed";
                pos[] = { 0.725, 0.685 };
            };
            class pos_fuel_lbs {
                type = "fixed";
                pos[] = { 0.8, 0.685 };
            };
        };
        class Draw {
            condition = "on";
            class MFD3 {
                class Pylon1 {
                    type = "pylonicon";
                    pos[] = { { 0.625, 0.301 }, 1 };
                    pylon = 1;
                    name = "rksla3_aw159_hma2";
                };
                class Pylon2 : Pylon1 {
                    pos[] = { { 0.375, 0.301 }, 1 };
                    pylon = 2;
                };
                class Pylon3 : Pylon1 {
                    pos[] = { { 0.758, 0.301 }, 1 };
                    pylon = 3;
                };
                class Pylon4 : Pylon1 {
                    pos[] = { { 0.242, 0.301 }, 1 };
                    pylon = 4;
                };
                class Mastercaution {
                    alpha = 0.5;
                    color[] = { 0.12, 0, 0 };
                    condition = "on";
                    points[] = { { { 0.15, 0.033 }, 1 }, { { 0.25, 0.093 }, 1 }, { { 0.25, 0.133 }, 1 }, { { 0.15, 0.133 }, 1 }, { { 0.15, 0.033 }, 1 } };
                    class MCText {
                        type = "text";
                        source = "weapon";
                        scale = 1;
                        sourceScale = 1;
                        align = "right";
                        pos[] = { "pos_mastercaution", { -0.03, -0.036 }, 1 };
                        right[] = { "pos_mastercaution", { 0.016, -0.036 }, 1 };
                        down[] = { "pos_mastercaution", { -0.03, 0.016 }, 1 };
                    };
                };
                class Fuel {
                    type = "text";
                    source = "fuel";
                    text = "%X";
                    sourceScale = 948;
                    sourceLength = 3;
                    align = "right";
                    scale = 1;
                    pos[] = { "pos_fuel_value", { -0.03, -0.036 }, 1 };
                    right[] = { "pos_fuel_value", { 0.016, -0.036 }, 1 };
                    down[] = { "pos_fuel_value", { -0.03, 0.016 }, 1 };
                };
                class BlueText {
                    alpha = 0.2;
                    color[] = { 0, 0.77, 0.77 };
                    condition = "on";
                    class LBSText {
                        type = "text";
                        source = "static";
                        text = "LBS";
                        scale = 1;
                        sourceScale = 1;
                        align = "right";
                        pos[] = { "pos_fuel_lbs", { -0.03, -0.036 }, 1 };
                        right[] = { "pos_fuel_lbs", { 0.016, -0.036 }, 1 };
                        down[] = { "pos_fuel_lbs", { -0.03, 0.016 }, 1 };
                    };
                    class FUELLabel {
                        type = "text";
                        source = "static";
                        text = "FUEL";
                        scale = 1;
                        sourceScale = 1;
                        align = "right";
                        pos[] = { "pos_fuel_label", { -0.03, -0.036 }, 1 };
                        right[] = { "pos_fuel_label", { 0.016, -0.036 }, 1 };
                        down[] = { "pos_fuel_label", { -0.03, 0.016 }, 1 };
                    };
                    class CMText {
                        type = "text";
                        source = "static";
                        text = "CM";
                        scale = 1;
                        sourceScale = 1;
                        align = "center";
                        pos[] = { "pos_cm_label", { -0.03, -0.036 }, 1 };
                        right[] = { "pos_cm_label", { 0.016, -0.036 }, 1 };
                        down[] = { "pos_cm_label", { -0.03, 0.016 }, 1 };
                    };
                };
                class Countermeasures {
                    alpha = 0.3;
                    color[] = { 0.9, 0.9, 0.9 };
                    condition = "on";
                    points[] = { { { 0.75, 0.033 }, 1 }, { { 0.85, 0.093 }, 1 }, { { 0.85, 0.133 }, 1 }, { { 0.75, 0.133 }, 1 }, { { 0.75, 0.033 }, 1 } };
                    class CMAmmo {
                        type = "text";
                        source = "cmammo";
                        sourceScale = 1;
                        sourceLength = 3;
                        align = "center";
                        scale = 1;
                        pos[] = { "pos_cm_ammo", { -0.03, -0.036 }, 1 };
                        right[] = { "pos_cm_ammo", { 0.016, -0.036 }, 1 };
                        down[] = { "pos_cm_ammo", { -0.03, 0.016 }, 1 };
                    };
                };
                class mfd_3_aircraft {
                    alpha = 0.1;
                    color[] = { 0.75, 0.75, 0.75 };
                    condition = "on";
                    clipTL[] = { 0, 1 };
                    clipBR[] = { 1, 0.769 };
                    type = "line";
                    width = 1;
                    points[] = { { "pos_profile", { 0, 0.092 }, 1 }, { "pos_profile", { 0.005, 0.093 }, 1 }, { "pos_profile", { 0.02, 0.106 }, 1 }, { "pos_profile", { 0.027, 0.126 }, 1 }, { "pos_profile", { 0.034, 0.152 }, 1 }, { "pos_profile", { 0.039, 0.179 }, 1 }, { "pos_profile", { 0.041, 0.215 }, 1 }, { "pos_profile", { 0.041, 0.282 }, 1 }, { "pos_profile", { 0.038, 0.33 }, 1 }, { "pos_profile", { 0.059, 0.33 }, 1 }, { "pos_profile", { 0.061, 0.331 }, 1 }, { "pos_profile", { 0.063, 0.335 }, 1 }, { "pos_profile", { 0.065, 0.34 }, 1 }, { "pos_profile", { 0.065, 0.364 }, 1 }, { "pos_profile", { 0.064, 0.377 }, 1 }, { "pos_profile", { 0.062, 0.381 }, 1 }, { "pos_profile", { 0.058, 0.387 }, 1 }, { "pos_profile", { 0.052, 0.383 }, 1 }, { "pos_profile", { 0.053, 0.37 }, 1 }, { "pos_profile", { 0.053, 0.34 }, 1 }, { "pos_profile", { 0.054, 0.336 }, 1 }, { "pos_profile", { 0.0545, 0.333 }, 1 }, { "pos_profile", { 0.056, 0.331 }, 1 }, { "pos_profile", { 0.059, 0.33 }, 1 }, {}, { "pos_profile", { 0.039, 0.38 }, 1 }, { "pos_profile", { 0.052, 0.38 }, 1 }, {}, { "pos_profile", { 0.002, 0.164 }, 1 }, { "pos_profile", { 0.017, 0.164 }, 1 }, { "pos_profile", { 0.021, 0.165 }, 1 }, { "pos_profile", { 0.027, 0.167 }, 1 }, { "pos_profile", { 0.031, 0.168 }, 1 }, { "pos_profile", { 0.033, 0.171 }, 1 }, { "pos_profile", { 0.036, 0.175 }, 1 }, { "pos_profile", { 0.038, 0.18 }, 1 }, { "pos_profile", { 0.035, 0.191 }, 1 }, { "pos_profile", { 0.033, 0.189 }, 1 }, { "pos_profile", { 0.031, 0.187 }, 1 }, { "pos_profile", { 0.029, 0.186 }, 1 }, { "pos_profile", { 0.026, 0.185 }, 1 }, { "pos_profile", { 0.021, 0.184 }, 1 }, { "pos_profile", { 0.016, 0.183 }, 1 }, { "pos_profile", { 0.002, 0.183 }, 1 }, { "pos_profile", { 0.002, 0.154 }, 1 }, {}, { "pos_profile", { 0, 0.186 }, 1 }, { "pos_profile", { 0.002, 0.186 }, 1 }, { "pos_profile", { 0.004, 0.188 }, 1 }, { "pos_profile", { 0.006, 0.191 }, 1 }, { "pos_profile", { 0.006, 0.244 }, 1 }, {}, { "pos_profile", { 0.006, 0.236 }, 1 }, { "pos_profile", { 0.017, 0.25 }, 1 }, { "pos_profile", { 0.022, 0.266 }, 1 }, { "pos_profile", { 0.026, 0.285 }, 1 }, { "pos_profile", { 0.026, 0.309 }, 1 }, { "pos_profile", { 0.042, 0.343 }, 1 }, { "pos_profile", { 0.0425, 0.345 }, 1 }, { "pos_profile", { 0.042, 0.364 }, 1 }, { "pos_profile", { 0.041, 0.372 }, 1 }, { "pos_profile", { 0.039, 0.38 }, 1 }, { "pos_profile", { 0.036, 0.391 }, 1 }, { "pos_profile", { 0.036, 0.416 }, 1 }, { "pos_profile", { 0.038, 0.418 }, 1 }, { "pos_profile", { 0.041, 0.424 }, 1 }, { "pos_profile", { 0.041, 0.424 }, 1 }, { "pos_profile", { 0.043, 0.43 }, 1 }, { "pos_profile", { 0.04, 0.435 }, 1 }, { "pos_profile", { 0.035, 0.437 }, 1 }, { "pos_profile", { 0.029, 0.436 }, 1 }, { "pos_profile", { 0.023, 0.433 }, 1 }, { "pos_profile", { 0.02, 0.43 }, 1 }, { "pos_profile", { 0.017, 0.426 }, 1 }, { "pos_profile", { 0.015, 0.419 }, 1 }, { "pos_profile", { 0.019, 0.412 }, 1 }, { "pos_profile", { 0.027, 0.411 }, 1 }, { "pos_profile", { 0.034, 0.415 }, 1 }, {}, { "pos_profile", { 0.024, 0.434 }, 1 }, { "pos_profile", { 0.003, 0.448 }, 1 }, { "pos_profile", { 0, 0.448 }, 1 }, {}, { "pos_profile", { 0.017, 0.439 }, 1 }, { "pos_profile", { 0.012, 0.458 }, 1 }, { "pos_profile", { 0.008, 0.562 }, 1 }, { "pos_profile", { 0.007, 0.597 }, 1 }, { "pos_profile", { 0.005, 0.636 }, 1 }, { "pos_profile", { 0.005, 0.657 }, 1 }, { "pos_profile", { 0.003, 0.67 }, 1 }, { "pos_profile", { 0, 0.67 }, 1 }, {}, { "pos_profile", { -0, 0.092 }, 1 }, { "pos_profile", { -0.005, 0.093 }, 1 }, { "pos_profile", { -0.02, 0.106 }, 1 }, { "pos_profile", { -0.027, 0.126 }, 1 }, { "pos_profile", { -0.034, 0.152 }, 1 }, { "pos_profile", { -0.039, 0.179 }, 1 }, { "pos_profile", { -0.041, 0.215 }, 1 }, { "pos_profile", { -0.041, 0.282 }, 1 }, { "pos_profile", { -0.038, 0.33 }, 1 }, { "pos_profile", { -0.059, 0.33 }, 1 }, { "pos_profile", { -0.061, 0.331 }, 1 }, { "pos_profile", { -0.063, 0.335 }, 1 }, { "pos_profile", { -0.065, 0.34 }, 1 }, { "pos_profile", { -0.065, 0.364 }, 1 }, { "pos_profile", { -0.064, 0.377 }, 1 }, { "pos_profile", { -0.062, 0.381 }, 1 }, { "pos_profile", { -0.058, 0.387 }, 1 }, { "pos_profile", { -0.052, 0.383 }, 1 }, { "pos_profile", { -0.053, 0.37 }, 1 }, { "pos_profile", { -0.053, 0.34 }, 1 }, { "pos_profile", { -0.054, 0.336 }, 1 }, { "pos_profile", { -0.0545, 0.333 }, 1 }, { "pos_profile", { -0.056, 0.331 }, 1 }, { "pos_profile", { -0.059, 0.33 }, 1 }, {}, { "pos_profile", { -0.039, 0.38 }, 1 }, { "pos_profile", { -0.052, 0.38 }, 1 }, {}, { "pos_profile", { -0.002, 0.164 }, 1 }, { "pos_profile", { -0.017, 0.164 }, 1 }, { "pos_profile", { -0.021, 0.165 }, 1 }, { "pos_profile", { -0.027, 0.167 }, 1 }, { "pos_profile", { -0.031, 0.168 }, 1 }, { "pos_profile", { -0.033, 0.171 }, 1 }, { "pos_profile", { -0.036, 0.175 }, 1 }, { "pos_profile", { -0.038, 0.18 }, 1 }, { "pos_profile", { -0.035, 0.191 }, 1 }, { "pos_profile", { -0.033, 0.189 }, 1 }, { "pos_profile", { -0.031, 0.187 }, 1 }, { "pos_profile", { -0.029, 0.186 }, 1 }, { "pos_profile", { -0.026, 0.185 }, 1 }, { "pos_profile", { -0.021, 0.184 }, 1 }, { "pos_profile", { -0.016, 0.183 }, 1 }, { "pos_profile", { -0.002, 0.183 }, 1 }, { "pos_profile", { -0.002, 0.154 }, 1 }, {}, { "pos_profile", { -0, 0.186 }, 1 }, { "pos_profile", { -0.002, 0.186 }, 1 }, { "pos_profile", { -0.004, 0.188 }, 1 }, { "pos_profile", { -0.006, 0.191 }, 1 }, { "pos_profile", { -0.006, 0.244 }, 1 }, {}, { "pos_profile", { -0.006, 0.236 }, 1 }, { "pos_profile", { -0.017, 0.25 }, 1 }, { "pos_profile", { -0.022, 0.266 }, 1 }, { "pos_profile", { -0.026, 0.285 }, 1 }, { "pos_profile", { -0.026, 0.309 }, 1 }, { "pos_profile", { -0.042, 0.343 }, 1 }, { "pos_profile", { -0.0425, 0.345 }, 1 }, { "pos_profile", { -0.042, 0.364 }, 1 }, { "pos_profile", { -0.041, 0.372 }, 1 }, { "pos_profile", { -0.039, 0.38 }, 1 }, { "pos_profile", { -0.036, 0.391 }, 1 }, { "pos_profile", { -0.036, 0.416 }, 1 }, { "pos_profile", { -0.038, 0.418 }, 1 }, { "pos_profile", { -0.041, 0.424 }, 1 }, { "pos_profile", { -0.041, 0.424 }, 1 }, { "pos_profile", { -0.043, 0.43 }, 1 }, { "pos_profile", { -0.04, 0.435 }, 1 }, { "pos_profile", { -0.035, 0.437 }, 1 }, { "pos_profile", { -0.029, 0.436 }, 1 }, { "pos_profile", { -0.023, 0.433 }, 1 }, { "pos_profile", { -0.02, 0.43 }, 1 }, { "pos_profile", { -0.017, 0.426 }, 1 }, { "pos_profile", { -0.015, 0.419 }, 1 }, { "pos_profile", { -0.019, 0.412 }, 1 }, { "pos_profile", { -0.027, 0.411 }, 1 }, { "pos_profile", { -0.034, 0.415 }, 1 }, {}, { "pos_profile", { -0.024, 0.434 }, 1 }, { "pos_profile", { -0.003, 0.448 }, 1 }, { "pos_profile", { -0, 0.448 }, 1 }, {}, { "pos_profile", { -0.017, 0.439 }, 1 }, { "pos_profile", { -0.012, 0.458 }, 1 }, { "pos_profile", { -0.008, 0.562 }, 1 }, { "pos_profile", { -0.007, 0.597 }, 1 }, { "pos_profile", { -0.005, 0.636 }, 1 }, { "pos_profile", { -0.005, 0.657 }, 1 }, { "pos_profile", { -0.003, 0.67 }, 1 }, { "pos_profile", { -0, 0.67 }, 1 }, {}, { "pos_profile", { 0.005, 0.636 }, 1 }, { "pos_profile", { 0.034, 0.638 }, 1 }, { "pos_profile", { 0.034, 0.65 }, 1 }, { "pos_profile", { 0.005, 0.657 }, 1 }, {}, { "pos_profile", { 0.008, 0.562 }, 1 }, { "pos_profile", { 0.068, 0.562 }, 1 }, { "pos_profile", { 0.064, 0.597 }, 1 }, { "pos_profile", { 0.007, 0.597 }, 1 }, {}, { "pos_profile", { -0.011, 0.562 }, 1 }, { "pos_profile", { -0.064, 0.562 }, 1 }, { "pos_profile", { -0.068, 0.601 }, 1 }, { "pos_profile", { -0.009, 0.601 }, 1 } };
                };
            };
        };
    };
    class MFD_4_STATIC {
        topLeft = "mfd_4_tl";
        topRight = "mfd_4_tr";
        bottomLeft = "mfd_4_bl";
        borderLeft = 0;
        borderRight = 0;
        borderTop = 0;
        borderBottom = 0;
        color[] = { 0.9, 0.9, 0.9, 1 };
        enableParallax = 0;
        class Bones {
            class pos_dial_asi {
                type = "fixed";
                pos[] = { 0.165, 0.105 };
            };
            class pos_dial_asi2 {
                type = "fixed";
                pos[] = { 0.282, 0.748 };
            };
            class pos_dial_alt_baro {
                type = "fixed";
                pos[] = { 0.554, 0.105 };
            };
            class pos_dial_alt_rad {
                type = "fixed";
                pos[] = { 0.554, 0.135 };
            };
            class pos_dial_mfd_horizon {
                type = "fixed";
                pos[] = { 0.321, 0.215 };
            };
            class pos_text_torque {
                type = "fixed";
                pos[] = { 0.165, 0.228 };
            };
            class pos_text_rpm {
                type = "fixed";
                pos[] = { 0.077, 0.228 };
            };
            class pos_text_hdg1 {
                type = "fixed";
                pos[] = { 0.123, 0.689 };
            };
            class pos_text_hdg2 {
                type = "fixed";
                pos[] = { 0.345, 0.465 };
            };
            class pos_text_hdg3 {
                type = "fixed";
                pos[] = { 0.62, 0.75 };
            };
            class pos_text_tgt {
                type = "fixed";
                pos[] = { 0.123, 0.715 };
            };
            class pos_text_fuel {
                type = "fixed";
                pos[] = { 0.123, 0.741 };
            };
            class pos_dial_compass {
                type = "fixed";
                pos[] = { 0.321, 0.622 };
            };
            class pos_dial_drift {
                type = "fixed";
                pos[] = { 0.82, 0.609 };
            };
            class pos_label_collective_8 {
                type = "fixed";
                pos[] = { 0.023, 0.521 };
            };
            class pos_label_collective_9 {
                type = "fixed";
                pos[] = { 0.023, 0.461 };
            };
            class pos_label_collective_10 {
                type = "fixed";
                pos[] = { 0.023, 0.401 };
            };
            class pos_label_collective_11 {
                type = "fixed";
                pos[] = { 0.023, 0.341 };
            };
            class pos_label_collective_12 {
                type = "fixed";
                pos[] = { 0.023, 0.281 };
            };
            class pos_label_rpm_2 {
                type = "fixed";
                pos[] = { 0.115, 0.544 };
            };
            class pos_label_rpm_4 {
                type = "fixed";
                pos[] = { 0.115, 0.499 };
            };
            class pos_label_rpm_6 {
                type = "fixed";
                pos[] = { 0.115, 0.454 };
            };
            class pos_label_rpm_8 {
                type = "fixed";
                pos[] = { 0.115, 0.409 };
            };
            class pos_label_rpm_10 {
                type = "fixed";
                pos[] = { 0.115, 0.364 };
            };
            class pos_label_rpm_12 {
                type = "fixed";
                pos[] = { 0.115, 0.319 };
            };
            class pos_label_rpm_14 {
                type = "fixed";
                pos[] = { 0.115, 0.274 };
            };
        };
        class Draw {
            condition = "on";
            class MFD4_White {
                class mfd4_frame_horizon {
                    alpha = 0.9;
                    type = "line";
                    width = 4;
                    points[] = { { "pos_dial_mfd_horizon", { 0, -0.137 }, 1 }, { "pos_dial_mfd_horizon", { 0.035, -0.132 }, 1 }, { "pos_dial_mfd_horizon", { 0.069, -0.119 }, 1 }, { "pos_dial_mfd_horizon", { 0.097, -0.097 }, 1 }, { "pos_dial_mfd_horizon", { 0.119, -0.069 }, 1 }, { "pos_dial_mfd_horizon", { 0.119, 0.069 }, 1 }, { "pos_dial_mfd_horizon", { 0.097, 0.097 }, 1 }, { "pos_dial_mfd_horizon", { 0.069, 0.119 }, 1 }, { "pos_dial_mfd_horizon", { 0.035, 0.132 }, 1 }, { "pos_dial_mfd_horizon", { 0, 0.137 }, 1 }, { "pos_dial_mfd_horizon", { -0.035, 0.132 }, 1 }, { "pos_dial_mfd_horizon", { -0.069, 0.119 }, 1 }, { "pos_dial_mfd_horizon", { -0.097, 0.097 }, 1 }, { "pos_dial_mfd_horizon", { -0.119, 0.069 }, 1 }, { "pos_dial_mfd_horizon", { -0.119, -0.069 }, 1 }, { "pos_dial_mfd_horizon", { -0.097, -0.097 }, 1 }, { "pos_dial_mfd_horizon", { -0.069, -0.119 }, 1 }, { "pos_dial_mfd_horizon", { -0.035, -0.132 }, 1 }, { "pos_dial_mfd_horizon", { 0, -0.137 }, 1 }, {}, { "pos_dial_mfd_horizon", { 0.122, 0 }, 1 }, { "pos_dial_mfd_horizon", { 0.137, 0 }, 1 }, {}, { "pos_dial_mfd_horizon", { -0.122, 0 }, 1 }, { "pos_dial_mfd_horizon", { -0.137, 0 }, 1 }, {}, { "pos_dial_mfd_horizon", { 0, 0.145 }, 1 }, { "pos_dial_mfd_horizon", { 0, 0.16 }, 1 }, {}, { "pos_dial_mfd_horizon", { 0.126, -0.073 }, 1 }, { "pos_dial_mfd_horizon", { 0.137, -0.08 }, 1 }, {}, { "pos_dial_mfd_horizon", { -0.126, -0.073 }, 1 }, { "pos_dial_mfd_horizon", { -0.137, -0.08 }, 1 }, {}, { "pos_dial_mfd_horizon", { 0.126, 0.073 }, 1 }, { "pos_dial_mfd_horizon", { 0.137, 0.08 }, 1 }, {}, { "pos_dial_mfd_horizon", { -0.126, 0.073 }, 1 }, { "pos_dial_mfd_horizon", { -0.137, 0.08 }, 1 }, {}, { "pos_dial_mfd_horizon", { 0.025, 0.143 }, 1 }, { "pos_dial_mfd_horizon", { 0.028, 0.158 }, 1 }, {}, { "pos_dial_mfd_horizon", { -0.025, 0.143 }, 1 }, { "pos_dial_mfd_horizon", { -0.028, 0.158 }, 1 }, {}, { "pos_dial_mfd_horizon", { 0.05, 0.137 }, 1 }, { "pos_dial_mfd_horizon", { 0.055, 0.151 }, 1 }, {}, { "pos_dial_mfd_horizon", { -0.05, 0.137 }, 1 }, { "pos_dial_mfd_horizon", { -0.055, 0.151 }, 1 }, {}, { "pos_dial_mfd_horizon", { 0.073, 0.126 }, 1 }, { "pos_dial_mfd_horizon", { 0.08, 0.139 }, 1 }, {}, { "pos_dial_mfd_horizon", { -0.073, 0.126 }, 1 }, { "pos_dial_mfd_horizon", { -0.08, 0.139 }, 1 }, {}, { "pos_dial_mfd_horizon", { 0.015, 0.176 }, 1 }, { "pos_dial_mfd_horizon", { 0.015, 0.195 }, 1 }, {}, { "pos_dial_mfd_horizon", { -0.015, 0.176 }, 1 }, { "pos_dial_mfd_horizon", { -0.015, 0.195 }, 1 }, {}, { "pos_dial_mfd_horizon", { 0.046, 0.176 }, 1 }, { "pos_dial_mfd_horizon", { 0.046, 0.195 }, 1 }, {}, { "pos_dial_mfd_horizon", { -0.046, 0.176 }, 1 }, { "pos_dial_mfd_horizon", { -0.046, 0.195 }, 1 } };
                };
                class mfd4_textreadouts {
                    alpha = 0.1;
                    class SpeedNumber {
                        type = "text";
                        align = "left";
                        scale = 1;
                        source = "speed";
                        sourceScale = 1.94384;
                        pos[] = { "pos_dial_asi", { -0.03, -0.036 }, 1 };
                        right[] = { "pos_dial_asi", { 0.012, -0.036 }, 1 };
                        down[] = { "pos_dial_asi", { -0.03, 0.016 }, 1 };
                    };
                    class ASI2 {
                        type = "text";
                        align = "left";
                        scale = 1;
                        source = "speed";
                        sourceScale = 1.94384;
                        pos[] = { "pos_dial_asi2", { -0.02, -0.024 }, 1 };
                        right[] = { "pos_dial_asi2", { 0.008, -0.024 }, 1 };
                        down[] = { "pos_dial_asi2", { -0.02, 0.008 }, 1 };
                    };
                    class AltitudeBaro {
                        type = "text";
                        align = "center";
                        scale = 1;
                        source = "altitudeASL";
                        sourceScale = 3.28084;
                        pos[] = { "pos_dial_alt_baro", { -0.03, -0.036 }, 1 };
                        right[] = { "pos_dial_alt_baro", { 0.012, -0.036 }, 1 };
                        down[] = { "pos_dial_alt_baro", { -0.03, 0.016 }, 1 };
                    };
                    class AltitudeRad {
                        type = "text";
                        align = "center";
                        scale = 1;
                        source = "altitudeAGL";
                        sourceScale = 3.28084;
                        pos[] = { "pos_dial_alt_rad", { -0.02, -0.024 }, 1 };
                        right[] = { "pos_dial_alt_rad", { 0.008, -0.024 }, 1 };
                        down[] = { "pos_dial_alt_rad", { -0.02, 0.008 }, 1 };
                    };
                    class Text_Torque {
                        type = "text";
                        align = "center";
                        scale = 100;
                        source = "rtdRotorTorque";
                        sourceScale = 227;
                        pos[] = { "pos_text_torque", { -0.02, -0.024 }, 1 };
                        right[] = { "pos_text_torque", { 0.008, -0.024 }, 1 };
                        down[] = { "pos_text_torque", { -0.02, 0.008 }, 1 };
                    };
                    class Text_rpm {
                        type = "text";
                        align = "center";
                        scale = 1;
                        source = "rpm";
                        sourceScale = 10;
                        pos[] = { "pos_text_rpm", { -0.02, -0.024 }, 1 };
                        right[] = { "pos_text_rpm", { 0.008, -0.024 }, 1 };
                        down[] = { "pos_text_rpm", { -0.02, 0.008 }, 1 };
                    };
                    class Text_hdg1 {
                        type = "text";
                        align = "left";
                        scale = 1;
                        source = "heading";
                        sourceScale = 1;
                        pos[] = { "pos_text_hdg1", { -0.02, -0.024 }, 1 };
                        right[] = { "pos_text_hdg1", { 0.008, -0.024 }, 1 };
                        down[] = { "pos_text_hdg1", { -0.02, 0.008 }, 1 };
                    };
                    class Text_hdg2 {
                        type = "text";
                        align = "center";
                        scale = 1;
                        source = "heading";
                        sourceScale = 1;
                        pos[] = { "pos_text_hdg2", { -0.025, -0.03 }, 1 };
                        right[] = { "pos_text_hdg2", { 0.01, -0.03 }, 1 };
                        down[] = { "pos_text_hdg2", { -0.025, 0.01 }, 1 };
                    };
                    class Text_hdg3 {
                        type = "text";
                        align = "center";
                        scale = 1;
                        source = "heading";
                        sourceScale = 1;
                        pos[] = { "pos_text_hdg3", { -0.025, -0.03 }, 1 };
                        right[] = { "pos_text_hdg3", { 0.01, -0.03 }, 1 };
                        down[] = { "pos_text_hdg3", { -0.025, 0.01 }, 1 };
                    };
                    class Text_tgt {
                        type = "text";
                        align = "left";
                        scale = 1;
                        source = "targetDist";
                        sourceScale = 1;
                        pos[] = { "pos_text_tgt", { -0.02, -0.024 }, 1 };
                        right[] = { "pos_text_tgt", { 0.008, -0.024 }, 1 };
                        down[] = { "pos_text_tgt", { -0.02, 0.008 }, 1 };
                    };
                    class Text_fuel {
                        type = "text";
                        align = "left";
                        source = "fuel";
                        scale = 1;
                        sourceScale = 430;
                        sourceLength = 3;
                        pos[] = { "pos_text_fuel", { -0.02, -0.024 }, 1 };
                        right[] = { "pos_text_fuel", { 0.008, -0.024 }, 1 };
                        down[] = { "pos_text_fuel", { -0.02, 0.008 }, 1 };
                    };
                };
                class label_collective_8 {
                    type = "text";
                    source = "static";
                    text = "8";
                    scale = 1;
                    sourceScale = 1;
                    align = "left";
                    pos[] = { "pos_label_collective_8", { 0.007, 0.005 }, 1 };
                    right[] = { "pos_label_collective_8", { 0.038, 0.005 }, 1 };
                    down[] = { "pos_label_collective_8", { 0.007, 0.035 }, 1 };
                };
                class label_collective_9 : label_collective_8 {
                    text = "9";
                    pos[] = { "pos_label_collective_9", { 0.007, 0.005 }, 1 };
                    right[] = { "pos_label_collective_9", { 0.038, 0.005 }, 1 };
                    down[] = { "pos_label_collective_9", { 0.007, 0.035 }, 1 };
                };
                class label_collective_10 : label_collective_8 {
                    text = "10";
                    pos[] = { "pos_label_collective_10", { 0.007, 0.005 }, 1 };
                    right[] = { "pos_label_collective_10", { 0.038, 0.005 }, 1 };
                    down[] = { "pos_label_collective_10", { 0.007, 0.035 }, 1 };
                };
                class label_collective_11 : label_collective_8 {
                    text = "11";
                    pos[] = { "pos_label_collective_11", { 0.007, 0.005 }, 1 };
                    right[] = { "pos_label_collective_11", { 0.038, 0.005 }, 1 };
                    down[] = { "pos_label_collective_11", { 0.007, 0.035 }, 1 };
                };
                class label_collective_12 : label_collective_8 {
                    text = "12";
                    pos[] = { "pos_label_collective_12", { 0.007, 0.005 }, 1 };
                    right[] = { "pos_label_collective_12", { 0.038, 0.005 }, 1 };
                    down[] = { "pos_label_collective_12", { 0.007, 0.035 }, 1 };
                };
                class label_rpm_2 {
                    type = "text";
                    source = "static";
                    text = "2";
                    scale = 1;
                    sourceScale = 1;
                    align = "left";
                    pos[] = { "pos_label_rpm_2", { 0.007, 0.005 }, 1 };
                    right[] = { "pos_label_rpm_2", { 0.038, 0.005 }, 1 };
                    down[] = { "pos_label_rpm_2", { 0.007, 0.035 }, 1 };
                };
                class label_rpm_4 : label_rpm_2 {
                    text = "4";
                    pos[] = { "pos_label_rpm_4", { 0.007, 0.005 }, 1 };
                    right[] = { "pos_label_rpm_4", { 0.038, 0.005 }, 1 };
                    down[] = { "pos_label_rpm_4", { 0.007, 0.035 }, 1 };
                };
                class label_rpm_6 : label_rpm_2 {
                    text = "6";
                    pos[] = { "pos_label_rpm_6", { 0.007, 0.005 }, 1 };
                    right[] = { "pos_label_rpm_6", { 0.038, 0.005 }, 1 };
                    down[] = { "pos_label_rpm_6", { 0.007, 0.035 }, 1 };
                };
                class label_rpm_8 : label_rpm_2 {
                    text = "8";
                    pos[] = { "pos_label_rpm_8", { 0.007, 0.005 }, 1 };
                    right[] = { "pos_label_rpm_8", { 0.038, 0.005 }, 1 };
                    down[] = { "pos_label_rpm_8", { 0.007, 0.035 }, 1 };
                };
                class label_rpm_10 : label_rpm_2 {
                    text = "10";
                    pos[] = { "pos_label_rpm_10", { 0.007, 0.005 }, 1 };
                    right[] = { "pos_label_rpm_10", { 0.038, 0.005 }, 1 };
                    down[] = { "pos_label_rpm_10", { 0.007, 0.035 }, 1 };
                };
                class label_rpm_12 : label_rpm_2 {
                    text = "12";
                    pos[] = { "pos_label_rpm_12", { 0.007, 0.005 }, 1 };
                    right[] = { "pos_label_rpm_12", { 0.038, 0.005 }, 1 };
                    down[] = { "pos_label_rpm_12", { 0.007, 0.035 }, 1 };
                };
                class label_rpm_14 : label_rpm_2 {
                    text = "14";
                    pos[] = { "pos_label_rpm_14", { 0.007, 0.005 }, 1 };
                    right[] = { "pos_label_rpm_14", { 0.038, 0.005 }, 1 };
                    down[] = { "pos_label_rpm_14", { 0.007, 0.035 }, 1 };
                };
            };
        };
    };
    class MFD_4_ACTIVE {
        topLeft = "mfd_4_tl";
        topRight = "mfd_4_tr";
        bottomLeft = "mfd_4_bl";
        borderLeft = 0;
        borderRight = 0;
        borderTop = 0;
        borderBottom = 0;
        color[] = { 0.9, 0.9, 0.9, 1 };
        enableParallax = 0;
        class material {
            ambient[] = { 3, 3, 3, 1 };
            diffuse[] = { 10, 10, 10, 1 };
            emissive[] = { 400, 200, 200, 1 };
        };
        class Bones {
            class CollectiveBone {
                type = "linear";
                source = "rtdCollective";
                sourceScale = 1;
                min = 0;
                max = 1;
                minPos[] = { 0.038, 0.244 };
                maxPos[] = { 0.038, 0.595 };
            };
            class TRQEngine1Bone {
                type = "linear";
                source = "rtdRotorTorque";
                sourceScale = 2.27;
                min = 0;
                max = 1;
                minPos[] = { 0.076, 0.244 };
                maxPos[] = { 0.076, 0.595 };
            };
            class RPMEngine1Bone {
                type = "linear";
                source = "rtdRpm1";
                sourceScale = 1.8;
                min = 0;
                max = 1;
                minPos[] = { 0.128, 0.244 };
                maxPos[] = { 0.128, 0.595 };
            };
            class RPMEngine2Bone {
                type = "linear";
                source = "rtdRpm2";
                sourceScale = 1.8;
                min = 0;
                max = 1;
                minPos[] = { 0.166, 0.244 };
                maxPos[] = { 0.166, 0.595 };
            };
            class pos_scale_left {
                type = "fixed";
                pos[] = { 0.057, 0.244 };
            };
            class pos_scale_right {
                type = "fixed";
                pos[] = { 0.147, 0.244 };
            };
            class pos_compass_dial_centre {
                type = "rotational";
                source = "heading";
                center[] = { 0.321, 0.603 };
                min = 0;
                max = 360;
                minAngle = 180;
                maxAngle = -180;
                aspectRatio = 1;
            };
            class pos_compass_centre {
                type = "rotational";
                source = "heading";
                center[] = { 0, 0 };
                min = 0;
                max = -360;
                minAngle = -180;
                maxAngle = 180;
                aspectRatio = 1;
            };
            class pos_windage_centre {
                type = "rotational";
                source = "windage";
                center[] = { 0.321, 0.603 };
                min = 0;
                max = 360;
                minAngle = -180;
                maxAngle = 180;
                aspectRatio = 1;
            };
        };
        class Draw {
            condition = "on";
            class mfd4_SCALEBARS_group_White {
                alpha = 1;
                color[] = { 0.9, 0.9, 0.9 };
                class mfd4_SCALE_BARS_LH_white {
                    type = "line";
                    width = 3;
                    points[] = { { "pos_scale_left", { 0, 0 }, 1 }, { "pos_scale_left", { 0, 0.36 }, 1 }, {}, { "pos_scale_left", { -0.024, 0 }, 1 }, { "pos_scale_left", { 0.024, 0 }, 1 }, {}, { "pos_scale_left", { -0.006, 0.03 }, 1 }, { "pos_scale_left", { 0.006, 0.03 }, 1 }, {}, { "pos_scale_left", { -0.012, 0.06 }, 1 }, { "pos_scale_left", { 0.012, 0.06 }, 1 }, {}, { "pos_scale_left", { -0.006, 0.09 }, 1 }, { "pos_scale_left", { 0.006, 0.09 }, 1 }, {}, { "pos_scale_left", { -0.012, 0.12 }, 1 }, { "pos_scale_left", { 0.012, 0.12 }, 1 }, {}, { "pos_scale_left", { -0.006, 0.15 }, 1 }, { "pos_scale_left", { 0.006, 0.15 }, 1 }, {}, { "pos_scale_left", { -0.012, 0.18 }, 1 }, { "pos_scale_left", { 0.012, 0.18 }, 1 }, {}, { "pos_scale_left", { -0.006, 0.21 }, 1 }, { "pos_scale_left", { 0.006, 0.21 }, 1 }, {}, { "pos_scale_left", { -0.012, 0.24 }, 1 }, { "pos_scale_left", { 0.012, 0.24 }, 1 }, {}, { "pos_scale_left", { -0.006, 0.27 }, 1 }, { "pos_scale_left", { 0.006, 0.27 }, 1 }, {}, { "pos_scale_left", { -0.012, 0.3 }, 1 }, { "pos_scale_left", { 0.012, 0.3 }, 1 }, {}, { "pos_scale_left", { -0.006, 0.33 }, 1 }, { "pos_scale_left", { 0.006, 0.33 }, 1 }, {}, { "pos_scale_left", { -0.024, 0.36 }, 1 }, { "pos_scale_left", { 0.024, 0.36 }, 1 } };
                };
                class mfd4_SCALE_BARS_RH_white {
                    type = "line";
                    width = 3;
                    points[] = { { "pos_scale_right", { -0.023, 0 }, 1 }, { "pos_scale_right", { 0.023, 0 }, 1 }, {}, { "pos_scale_right", { -0.023, 0.36 }, 1 }, { "pos_scale_right", { 0.023, 0.36 }, 1 }, {}, { "pos_scale_right", { 0, 0 }, 1 }, { "pos_scale_right", { 0, 0.068 }, 1 }, {}, { "pos_scale_right", { -0.007, 0.045 }, 1 }, { "pos_scale_right", { 0.007, 0.045 }, 1 }, {}, { "pos_scale_right", { -0.003, 0.023 }, 1 }, { "pos_scale_right", { 0.003, 0.023 }, 1 } };
                };
            };
            class mfd4_SCALEBARS_RH_GREEN {
                alpha = 0.1;
                color[] = { 0, 0.7, 0 };
                class RPM_RH_Scale_GREEN {
                    type = "line";
                    width = 3;
                    points[] = { { "pos_scale_right", { 0, 0.36 }, 1 }, { "pos_scale_right", { 0, 0.068 }, 1 }, {}, { "pos_scale_right", { -0.003, 0.338 }, 1 }, { "pos_scale_right", { 0.003, 0.338 }, 1 }, {}, { "pos_scale_right", { -0.007, 0.315 }, 1 }, { "pos_scale_right", { 0.007, 0.315 }, 1 }, {}, { "pos_scale_right", { -0.003, 0.293 }, 1 }, { "pos_scale_right", { 0.003, 0.293 }, 1 }, {}, { "pos_scale_right", { -0.007, 0.27 }, 1 }, { "pos_scale_right", { 0.007, 0.27 }, 1 }, {}, { "pos_scale_right", { -0.003, 0.248 }, 1 }, { "pos_scale_right", { 0.003, 0.248 }, 1 }, {}, { "pos_scale_right", { -0.007, 0.225 }, 1 }, { "pos_scale_right", { 0.007, 0.225 }, 1 }, {}, { "pos_scale_right", { -0.003, 0.203 }, 1 }, { "pos_scale_right", { 0.003, 0.203 }, 1 }, {}, { "pos_scale_right", { -0.007, 0.18 }, 1 }, { "pos_scale_right", { 0.007, 0.18 }, 1 }, {}, { "pos_scale_right", { -0.003, 0.158 }, 1 }, { "pos_scale_right", { 0.003, 0.158 }, 1 }, {}, { "pos_scale_right", { -0.007, 0.135 }, 1 }, { "pos_scale_right", { 0.007, 0.135 }, 1 }, {}, { "pos_scale_right", { -0.003, 0.113 }, 1 }, { "pos_scale_right", { 0.003, 0.113 }, 1 }, {}, { "pos_scale_right", { -0.007, 0.09 }, 1 }, { "pos_scale_right", { 0.007, 0.09 }, 1 }, {}, { "pos_scale_right", { -0.003, 0.068 }, 1 }, { "pos_scale_right", { 0.003, 0.068 }, 1 } };
                };
            };
            class SCALE_BARS_LH_Vert_Yellow {
                alpha = 0.11;
                color[] = { 0.97, 0.73, 0.04 };
                class RPM_LH_Scale_Yellow {
                    type = "line";
                    width = 10;
                    points[] = { { "pos_scale_left", { 0, 0.21 }, 1 }, { "pos_scale_left", { 0, 0.165 }, 1 } };
                };
            };
            class SCALE_BARS_LH_Vert_Green {
                alpha = 0.1;
                color[] = { 0, 0.6, 0 };
                class RPM_LH_Scale_GREEN {
                    type = "line";
                    width = 10;
                    points[] = { { "pos_scale_left", { 0, 0.165 }, 1 }, { "pos_scale_left", { 0, 0.135 }, 1 } };
                };
            };
            class SCALE_BARS_LH_LIMITS_Red {
                alpha = 0.1;
                color[] = { 0.5, 0, 0 };
                class RPM_LH_Scale_Limits_Red {
                    type = "line";
                    width = 3;
                    points[] = { { "pos_scale_left", { -0.025, 0.21 }, 1 }, { "pos_scale_left", { 0.025, 0.21 }, 1 }, {}, { "pos_scale_left", { -0.025, 0.135 }, 1 }, { "pos_scale_left", { 0.025, 0.135 }, 1 }, {}, { "pos_scale_left", { 0, 0.105 }, 1 }, { "pos_scale_left", { 0.025, 0.105 }, 1 }, { "pos_scale_left", { 0.025, 0.095 }, 1 }, { "pos_scale_left", { 0.02, 0.085 }, 1 }, { "pos_scale_left", { 0.03, 0.085 }, 1 }, { "pos_scale_left", { 0.025, 0.095 }, 1 } };
                };
                class RPM_RH_Scale_Limits_Red {
                    type = "line";
                    width = 3;
                    points[] = { { "pos_scale_right", { -0.025, 0.08 }, 1 }, { "pos_scale_right", { 0.025, 0.08 }, 1 }, {}, { "pos_scale_right", { -0.025, 0.06 }, 1 }, { "pos_scale_right", { 0.025, 0.06 }, 1 }, {}, { "pos_scale_right", { -0.025, 0.06 }, 1 }, { "pos_scale_right", { -0.03, 0.05 }, 1 }, { "pos_scale_right", { -0.02, 0.05 }, 1 }, { "pos_scale_right", { -0.025, 0.06 }, 1 }, {}, { "pos_scale_right", { 0.025, 0.06 }, 1 }, { "pos_scale_right", { 0.03, 0.05 }, 1 }, { "pos_scale_right", { 0.02, 0.05 }, 1 }, { "pos_scale_right", { 0.025, 0.06 }, 1 } };
                };
            };
            class Green_TAPES_Moving_Bars {
                alpha = 0.05;
                color[] = { 0.12, 0.34, 0.08 };
                condition = "simulRTD";
                class CollectiveLINE {
                    type = "line";
                    width = 12;
                    points[] = { { { 0.044, 0.604 }, 1 }, { "CollectiveBone", { 0.006, 0 }, 1 } };
                };
                class TRQRotorLINE {
                    type = "line";
                    width = 12;
                    points[] = { { { 0.07, 0.604 }, 1 }, { "TRQEngine1Bone", { -0.006, 0 }, 1 } };
                };
                class RPMEngine1LINE {
                    type = "line";
                    width = 12;
                    points[] = { { { 0.134, 0.604 }, 1 }, { "RPMEngine1Bone", { 0.006, 0 }, 1 } };
                };
                class RPMEngine2LINE {
                    type = "line";
                    width = 12;
                    points[] = { { { 0.16, 0.604 }, 1 }, { "RPMEngine2Bone", { -0.006, 0 }, 1 } };
                };
            };
            class Collective_CRAWLER {
                alpha = 0.9;
                condition = "simulRTD";
                class CollectiveBOX {
                    type = "line";
                    width = 2;
                    points[] = { { "CollectiveBone", { 0, 0 }, 1 }, { "CollectiveBone", { -0.013, 0.004 }, 1 }, { "CollectiveBone", { -0.024, 0.004 }, 1 }, { "CollectiveBone", { -0.024, 0.033 }, 1 }, { "CollectiveBone", { -0.003, 0.033 }, 1 }, { "CollectiveBone", { -0.003, 0.015 }, 1 }, { "CollectiveBone", { 0, 0 }, 1 } };
                };
                class CollectiveCTextLH {
                    type = "text";
                    source = "static";
                    text = "C";
                    scale = 1;
                    sourceScale = 1;
                    align = "right";
                    pos[] = { "CollectiveBone", { -0.02, 0.005 }, 1 };
                    right[] = { "CollectiveBone", { 0.011, 0.005 }, 1 };
                    down[] = { "CollectiveBone", { -0.02, 0.035 }, 1 };
                };
            };
            class TRQ_Bars_CRAWLER {
                alpha = 0.9;
                class TRQRotor {
                    type = "line";
                    width = 2;
                    points[] = { { "TRQEngine1Bone", { 0, 0 }, 1 }, { "TRQEngine1Bone", { 0.013, 0.004 }, 1 }, { "TRQEngine1Bone", { 0.024, 0.004 }, 1 }, { "TRQEngine1Bone", { 0.024, 0.033 }, 1 }, { "TRQEngine1Bone", { 0.003, 0.033 }, 1 }, { "TRQEngine1Bone", { 0.003, 0.015 }, 1 }, { "TRQEngine1Bone", { 0, 0 }, 1 } };
                };
                class TRQRotorText {
                    type = "text";
                    source = "static";
                    text = "T";
                    scale = 1;
                    sourceScale = 1;
                    align = "right";
                    pos[] = { "TRQEngine1Bone", { 0.007, 0.005 }, 1 };
                    right[] = { "TRQEngine1Bone", { 0.038, 0.005 }, 1 };
                    down[] = { "TRQEngine1Bone", { 0.007, 0.035 }, 1 };
                };
            };
            class RPM_Engine_1_CRAWLER {
                alpha = 0.9;
                class RPMEngine1BOX {
                    type = "line";
                    width = 2;
                    points[] = { { "RPMEngine1Bone", { 0, 0 }, 1 }, { "RPMEngine1Bone", { -0.013, 0.004 }, 1 }, { "RPMEngine1Bone", { -0.024, 0.004 }, 1 }, { "RPMEngine1Bone", { -0.024, 0.033 }, 1 }, { "RPMEngine1Bone", { -0.003, 0.033 }, 1 }, { "RPMEngine1Bone", { -0.003, 0.015 }, 1 }, { "RPMEngine1Bone", { 0, 0 }, 1 } };
                };
                class RPMEngine1Text {
                    type = "text";
                    source = "static";
                    text = "1";
                    scale = 1;
                    sourceScale = 1;
                    align = "right";
                    pos[] = { "RPMEngine1Bone", { -0.02, 0.005 }, 1 };
                    right[] = { "RPMEngine1Bone", { 0.011, 0.005 }, 1 };
                    down[] = { "RPMEngine1Bone", { -0.02, 0.035 }, 1 };
                };
            };
            class RPM_Engine_2_CRAWLER {
                alpha = 0.9;
                class RPMEngine2BOX {
                    type = "line";
                    width = 2;
                    points[] = { { "RPMEngine2Bone", { 0, 0 }, 1 }, { "RPMEngine2Bone", { 0.013, 0.004 }, 1 }, { "RPMEngine2Bone", { 0.024, 0.004 }, 1 }, { "RPMEngine2Bone", { 0.024, 0.033 }, 1 }, { "RPMEngine2Bone", { 0.003, 0.033 }, 1 }, { "RPMEngine2Bone", { 0.003, 0.015 }, 1 }, { "RPMEngine2Bone", { 0, 0 }, 1 } };
                };
                class RPMEngine2Text {
                    type = "text";
                    source = "static";
                    text = "2";
                    scale = 1;
                    sourceScale = 1;
                    align = "right";
                    pos[] = { "RPMEngine2Bone", { 0.007, 0.005 }, 1 };
                    right[] = { "RPMEngine2Bone", { 0.038, 0.005 }, 1 };
                    down[] = { "RPMEngine2Bone", { 0.007, 0.035 }, 1 };
                };
            };
            class compass_arrow {
                alpha = 0.3;
                color[] = { 1, 0, 0 };
                condition = "on";
                class lines {
                    type = "line";
                    width = 2;
                    points[] = { { "pos_compass_dial_centre", { -0.035, -0.058 }, 1 }, { "pos_compass_dial_centre", { 0, -0.078 }, 1 }, { "pos_compass_dial_centre", { 0.035, -0.058 }, 1 } };
                };
            };
            class Windage_arrow {
                alpha = 0.3;
                color[] = { 0, 0.65, 0.65 };
                condition = "on";
                class TRQRotorBOXback {
                    type = "line";
                    width = 2;
                    points[] = { { "pos_compass_centre", 1, "pos_windage_centre", { 0, -0.078 }, 1 }, { "pos_compass_centre", 1, "pos_windage_centre", { 0.025, -0.053 }, 1 }, { "pos_compass_centre", 1, "pos_windage_centre", { 0.025, 0.049 }, 1 }, { "pos_compass_centre", 1, "pos_windage_centre", { 0, 0.038 }, 1 }, { "pos_compass_centre", 1, "pos_windage_centre", { -0.025, 0.049 }, 1 }, { "pos_compass_centre", 1, "pos_windage_centre", { -0.025, -0.053 }, 1 }, { "pos_compass_centre", 1, "pos_windage_centre", { 0, -0.078 }, 1 }, {}, { "pos_compass_centre", 1, "pos_windage_centre", { 0.025, 0.059 }, 1 }, { "pos_compass_centre", 1, "pos_windage_centre", { 0, 0.048 }, 1 }, { "pos_compass_centre", 1, "pos_windage_centre", { -0.025, 0.059 }, 1 }, {}, { "pos_compass_centre", 1, "pos_windage_centre", { 0.025, 0.069 }, 1 }, { "pos_compass_centre", 1, "pos_windage_centre", { 0, 0.058 }, 1 }, { "pos_compass_centre", 1, "pos_windage_centre", { -0.025, 0.069 }, 1 } };
                };
            };
            class BOX_backing_RED {
                alpha = 0.2;
                color[] = { 1, 0, 0 };
                condition = "on";
                class TRQRotorBOXback {
                    type = "line";
                    width = 16;
                    points[] = { { "TRQEngine1Bone", { 0.013, 0.004 }, 1 }, { "TRQEngine1Bone", { 0.013, 0.033 }, 1 } };
                };
            };
            class BOX_backing_BLACK {
                alpha = 0.2;
                color[] = { 0.05, 0.05, 0.05 };
                condition = "on";
                class CollectiveBOXback {
                    type = "line";
                    width = 16;
                    points[] = { { "CollectiveBone", { -0.013, 0.004 }, 1 }, { "CollectiveBone", { -0.013, 0.033 }, 1 } };
                };
                class RPMEngine_1_BOXback {
                    type = "line";
                    width = 16;
                    points[] = { { "RPMEngine1Bone", { -0.013, 0.004 }, 1 }, { "RPMEngine1Bone", { -0.013, 0.033 }, 1 } };
                };
                class RPMEngine_2_BOXback {
                    type = "line";
                    width = 16;
                    points[] = { { "RPMEngine2Bone", { 0.013, 0.004 }, 1 }, { "RPMEngine2Bone", { 0.013, 0.033 }, 1 } };
                };
            };
        };
    };
    class GPS_1_STATIC {
        topLeft = "gps_1_tl";
        topRight = "gps_1_tr";
        bottomLeft = "gps_1_bl";
        borderLeft = 0;
        borderRight = 0;
        borderTop = 0;
        borderBottom = 0;
        color[] = { 0.9, 0.9, 0.9, 1 };
        enableParallax = 0;
        class Bones {
            class pos_gps_asi {
                type = "fixed";
                pos[] = { 0.3, 0.125 };
            };
            class pos_gps_wp {
                type = "fixed";
                pos[] = { 0.55, 0.125 };
            };
            class pos_gps_time {
                type = "fixed";
                pos[] = { 0.75, 0.125 };
            };
            class pos_gps_wind {
                type = "fixed";
                pos[] = { 0.3, 0.27 };
            };
            class pos_gps_wpdist {
                type = "fixed";
                pos[] = { 0.55, 0.27 };
            };
            class pos_gps_tgtdist {
                type = "fixed";
                pos[] = { 0.825, 0.27 };
            };
            class pos_gps_hdg {
                type = "fixed";
                pos[] = { 0.39, 0.49 };
            };
            class pos_gridx {
                type = "fixed";
                pos[] = { 0.685, 0.49 };
            };
            class pos_gridy {
                type = "fixed";
                pos[] = { 0.9055, 0.49 };
            };
        };
        class Draw {
            alpha = 0.6;
            color[] = { 0.9, 0.9, 0.9 };
            condition = "on";
            class GPS1 {
                class GridX {
                    type = "text";
                    source = "coordinateX";
                    sourceScale = 0.01;
                    sourceOffset = -0.5;
                    sourceLength = 3;
                    align = "right";
                    scale = 1;
                    pos[] = { "pos_gridx", { -0.12, -0.144 }, 1 };
                    right[] = { "pos_gridx", { 0.0639, -0.144 }, 1 };
                    down[] = { "pos_gridx", { -0.12, 0.0639 }, 1 };
                };
                class GridY : GridX {
                    source = "coordinateY";
                    pos[] = { "pos_gridy", { -0.12, -0.144 }, 1 };
                    right[] = { "pos_gridy", { 0.0639, -0.144 }, 1 };
                    down[] = { "pos_gridy", { -0.12, 0.0639 }, 1 };
                };
                class Text_gps_hdg {
                    type = "text";
                    align = "center";
                    scale = 1;
                    source = "heading";
                    sourceScale = 1;
                    pos[] = { "pos_gps_hdg", { -0.12, -0.144 }, 1 };
                    right[] = { "pos_gps_hdg", { 0.0639, -0.144 }, 1 };
                    down[] = { "pos_gps_hdg", { -0.12, 0.0639 }, 1 };
                };
                class gps_asi {
                    type = "text";
                    align = "left";
                    scale = 1;
                    source = "speed";
                    sourceScale = 1.94384;
                    pos[] = { "pos_gps_asi", { -0.06, -0.072 }, 1 };
                    right[] = { "pos_gps_asi", { 0.032, -0.072 }, 1 };
                    down[] = { "pos_gps_asi", { -0.06, 0.032 }, 1 };
                };
                class gps_wp {
                    type = "text";
                    align = "left";
                    scale = 1;
                    source = "WPIndex";
                    sourceScale = 1;
                    pos[] = { "pos_gps_wp", { -0.06, -0.072 }, 1 };
                    right[] = { "pos_gps_wp", { 0.032, -0.072 }, 1 };
                    down[] = { "pos_gps_wp", { -0.06, 0.032 }, 1 };
                };
                class gps_time {
                    type = "text";
                    source = "time";
                    text = "%X";
                    sourceScale = 1;
                    align = "right";
                    scale = 1;
                    pos[] = { "pos_gps_time", { -0.06, -0.072 }, 1 };
                    right[] = { "pos_gps_time", { 0.032, -0.072 }, 1 };
                    down[] = { "pos_gps_time", { -0.06, 0.032 }, 1 };
                };
                class gps_windage {
                    type = "text";
                    align = "left";
                    scale = 1;
                    source = "windage";
                    sourceScale = 1;
                    pos[] = { "pos_gps_wind", { -0.06, -0.072 }, 1 };
                    right[] = { "pos_gps_wind", { 0.032, -0.072 }, 1 };
                    down[] = { "pos_gps_wind", { -0.06, 0.032 }, 1 };
                };
                class gps_wpdist {
                    type = "text";
                    align = "left";
                    scale = 1;
                    source = "WPDist";
                    sourceScale = 1;
                    pos[] = { "pos_gps_wpdist", { -0.06, -0.072 }, 1 };
                    right[] = { "pos_gps_wpdist", { 0.032, -0.072 }, 1 };
                    down[] = { "pos_gps_wpdist", { -0.06, 0.032 }, 1 };
                };
                class gps_tgtdist {
                    type = "text";
                    source = "LarTargetDist";
                    sourceScale = 0.001;
                    scale = 1;
                    pos[] = { "pos_gps_tgtdist", { -0.06, -0.072 }, 1 };
                    right[] = { "pos_gps_tgtdist", { 0.032, -0.072 }, 1 };
                    down[] = { "pos_gps_tgtdist", { -0.06, 0.032 }, 1 };
                    align = "right";
                };
            };
        };
    };
    class MINIDIGI_RH_STATIC {
        topLeft = "minidigi_rh_tl";
        topRight = "minidigi_rh_tr";
        bottomLeft = "minidigi_rh_bl";
        borderLeft = 0;
        borderRight = 0;
        borderTop = 0;
        borderBottom = 0;
        color[] = { 0.9, 0.9, 0.9, 1 };
        enableParallax = 0;
        class Bones {
            class pos_heading_number {
                type = "fixed";
                pos[] = { 0.59, 0.097 };
            };
            class pos_speed_number {
                type = "fixed";
                pos[] = { 0.225, 0.505 };
            };
            class pos_alt_number {
                type = "fixed";
                pos[] = { 1.05, 0.505 };
            };
        };
        class Draw {
            condition = "on";
            class HeadingNumber {
                type = "text";
                source = "heading";
                sourceScale = 1;
                align = "center";
                scale = 1;
                pos[] = { "pos_heading_number", { -0.08, -0.096 }, 1 };
                right[] = { "pos_heading_number", { 0.043, -0.096 }, 1 };
                down[] = { "pos_heading_number", { -0.08, 0.043 }, 1 };
            };
            class SpeedNumber {
                type = "text";
                source = "speed";
                sourceScale = 1.94384;
                align = "center";
                scale = 1;
                pos[] = { "pos_speed_number", { -0.08, -0.096 }, 1 };
                right[] = { "pos_speed_number", { 0.043, -0.096 }, 1 };
                down[] = { "pos_speed_number", { -0.08, 0.043 }, 1 };
            };
            class altNumber {
                type = "text";
                source = "altitudeAGL";
                sourceScale = 3.28084;
                align = "left";
                scale = 1;
                pos[] = { "pos_alt_number", { -0.08, -0.096 }, 1 };
                right[] = { "pos_alt_number", { 0.043, -0.096 }, 1 };
                down[] = { "pos_alt_number", { -0.08, 0.043 }, 1 };
            };
        };
    };
    // class MFD_CDU_1_STATIC {
    //     topLeft = "cdu_lh_tl";
    //     topRight = "cdu_lh_tr";
    //     bottomLeft = "cdu_lh_bl";
    //     borderLeft = 0;
    //     borderRight = 0;
    //     borderTop = 0;
    //     borderBottom = 0;
    //     color[] = { 0.27, 0.58, 0.04, 1 };
    //     enableParallax = 0;
    //     class Bones {
    //         class pos_line1_text {
    //             type = "fixed";
    //             pos[] = { 0.1, 0.098 };
    //         };
    //         class pos_line2_text {
    //             type = "fixed";
    //             pos[] = { 0.1, 0.177 };
    //         };
    //         class pos_line3_text {
    //             type = "fixed";
    //             pos[] = { 0.1, 0.256 };
    //         };
    //         class pos_line4_text {
    //             type = "fixed";
    //             pos[] = { 0.1, 0.336 };
    //         };
    //         class pos_line5_text {
    //             type = "fixed";
    //             pos[] = { 0.1, 0.415 };
    //         };
    //         class pos_line6_text {
    //             type = "fixed";
    //             pos[] = { 0.1, 0.494 };
    //         };
    //         class pos_line7_text {
    //             type = "fixed";
    //             pos[] = { 0.1, 0.573 };
    //         };
    //         class pos_line8_text {
    //             type = "fixed";
    //             pos[] = { 0.1, 0.652 };
    //         };
    //         class pos_line9_text {
    //             type = "fixed";
    //             pos[] = { 0.1, 0.732 };
    //         };
    //         class pos_line10_text {
    //             type = "fixed";
    //             pos[] = { 0.1, 0.811 };
    //         };
    //         class pos_line11_text {
    //             type = "fixed";
    //             pos[] = { 0.1, 0.89 };
    //         };
    //     };
    //     class Draw {
    //         alpha = 0.9;
    //         color[] = { 0.9, 0.9, 0.9, 1 };
    //         condition = "on";
    //         class Line_1_lh {
    //             type = "text";
    //             source = "static";
    //             text = "-RKSL-STUDIOS---AW159-";
    //             align = "right";
    //             scale = 1;
    //             sourceScale = 1;
    //             pos[] = { "pos_line1_text", { -0.06, -0.072 }, 1 };
    //             right[] = { "pos_line1_text", { 0.032, -0.072 }, 1 };
    //             down[] = { "pos_line1_text", { -0.06, 0.032 }, 1 };
    //         };
    //         class Line_2_lh : Line_1_lh {
    //             text = "GAME OVER";
    //             pos[] = { "pos_line2_text", { -0.06, -0.072 }, 1 };
    //             right[] = { "pos_line2_text", { 0.032, -0.072 }, 1 };
    //             down[] = { "pos_line2_text", { -0.06, 0.032 }, 1 };
    //         };
    //         class Line_4_lh : Line_1_lh {
    //             text = "INSERT COIN";
    //             pos[] = { "pos_line4_text", { -0.06, -0.072 }, 1 };
    //             right[] = { "pos_line4_text", { 0.032, -0.072 }, 1 };
    //             down[] = { "pos_line4_text", { -0.06, 0.032 }, 1 };
    //         };
    //         class Line_5_lh : Line_1_lh {
    //             text = "---------------------";
    //             pos[] = { "pos_line5_text", { -0.06, -0.072 }, 1 };
    //             right[] = { "pos_line5_text", { 0.032, -0.072 }, 1 };
    //             down[] = { "pos_line5_text", { -0.06, 0.032 }, 1 };
    //         };
    //         class Line_6_lh : Line_1_lh {
    //             text = "2 PLAYER GAME";
    //             pos[] = { "pos_line6_text", { -0.06, -0.072 }, 1 };
    //             right[] = { "pos_line6_text", { 0.032, -0.072 }, 1 };
    //             down[] = { "pos_line6_text", { -0.06, 0.032 }, 1 };
    //         };
    //         class Line_7_lh : Line_1_lh {
    //             text = "---------------------";
    //             pos[] = { "pos_line7_text", { -0.06, -0.072 }, 1 };
    //             right[] = { "pos_line7_text", { 0.032, -0.072 }, 1 };
    //             down[] = { "pos_line7_text", { -0.06, 0.032 }, 1 };
    //         };
    //         class Line_9_lh : Line_1_lh {
    //             text = "---------------------";
    //             pos[] = { "pos_line9_text", { -0.06, -0.072 }, 1 };
    //             right[] = { "pos_line9_text", { 0.032, -0.072 }, 1 };
    //             down[] = { "pos_line9_text", { -0.06, 0.032 }, 1 };
    //         };
    //         class Line_10_lh : Line_1_lh {
    //             text = "<RETURN";
    //             pos[] = { "pos_line10_text", { -0.06, -0.072 }, 1 };
    //             right[] = { "pos_line10_text", { 0.032, -0.072 }, 1 };
    //             down[] = { "pos_line10_text", { -0.06, 0.032 }, 1 };
    //         };
    //         class Line_11_lh : Line_1_lh {
    //             text = "---------------------";
    //             pos[] = { "pos_line11_text", { -0.06, -0.072 }, 1 };
    //             right[] = { "pos_line11_text", { 0.032, -0.072 }, 1 };
    //             down[] = { "pos_line11_text", { -0.06, 0.032 }, 1 };
    //         };
    //     };
    // };
    // class MFD_CDU_2_STATIC {
    //     topLeft = "cdu_rh_tl";
    //     topRight = "cdu_rh_tr";
    //     bottomLeft = "cdu_rh_bl";
    //     borderLeft = 0;
    //     borderRight = 0;
    //     borderTop = 0;
    //     borderBottom = 0;
    //     color[] = { 0.27, 0.58, 0.04, 1 };
    //     enableParallax = 0;
    //     class Bones {
    //         class pos_line1_text {
    //             type = "fixed";
    //             pos[] = { 0.1, 0.098 };
    //         };
    //         class pos_line2_text {
    //             type = "fixed";
    //             pos[] = { 0.1, 0.177 };
    //         };
    //         class pos_line3_text {
    //             type = "fixed";
    //             pos[] = { 0.1, 0.256 };
    //         };
    //         class pos_line4_text {
    //             type = "fixed";
    //             pos[] = { 0.1, 0.336 };
    //         };
    //         class pos_line5_text {
    //             type = "fixed";
    //             pos[] = { 0.1, 0.415 };
    //         };
    //         class pos_line6_text {
    //             type = "fixed";
    //             pos[] = { 0.1, 0.494 };
    //         };
    //         class pos_line7_text {
    //             type = "fixed";
    //             pos[] = { 0.1, 0.573 };
    //         };
    //         class pos_line8_text {
    //             type = "fixed";
    //             pos[] = { 0.1, 0.652 };
    //         };
    //         class pos_line9_text {
    //             type = "fixed";
    //             pos[] = { 0.1, 0.732 };
    //         };
    //         class pos_line10_text {
    //             type = "fixed";
    //             pos[] = { 0.1, 0.811 };
    //         };
    //         class pos_line11_text {
    //             type = "fixed";
    //             pos[] = { 0.1, 0.89 };
    //         };
    //     };
    //     class Draw {
    //         alpha = 0.9;
    //         color[] = { 0.9, 0.9, 0.9, 1 };
    //         condition = "on";
    //         class Line_1_lh {
    //             type = "text";
    //             source = "static";
    //             text = "-RKSL-STUDIOS---AW159-";
    //             align = "Right";
    //             scale = 1;
    //             sourceScale = 1;
    //             pos[] = { "pos_line1_text", { -0.06, -0.072 }, 1 };
    //             right[] = { "pos_line1_text", { 0.032, -0.072 }, 1 };
    //             down[] = { "pos_line1_text", { -0.06, 0.032 }, 1 };
    //         };
    //         class Line_2_lh : Line_1_lh {
    //             text = "V3.050";
    //             pos[] = { "pos_line2_text", { -0.06, -0.072 }, 1 };
    //             right[] = { "pos_line2_text", { 0.032, -0.072 }, 1 };
    //             down[] = { "pos_line2_text", { -0.06, 0.032 }, 1 };
    //         };
    //         class Line_4_lh : Line_1_lh {
    //             text = "ALL RIGHTS RESERVED";
    //             pos[] = { "pos_line4_text", { -0.06, -0.072 }, 1 };
    //             right[] = { "pos_line4_text", { 0.032, -0.072 }, 1 };
    //             down[] = { "pos_line4_text", { -0.06, 0.032 }, 1 };
    //         };
    //         class Line_5_lh : Line_1_lh {
    //             text = "---------------------";
    //             pos[] = { "pos_line5_text", { -0.06, -0.072 }, 1 };
    //             right[] = { "pos_line5_text", { 0.032, -0.072 }, 1 };
    //             down[] = { "pos_line5_text", { -0.06, 0.032 }, 1 };
    //         };
    //         class Line_6_lh : Line_1_lh {
    //             text = "DO NOT REUPLOAD";
    //             pos[] = { "pos_line6_text", { -0.06, -0.072 }, 1 };
    //             right[] = { "pos_line6_text", { 0.032, -0.072 }, 1 };
    //             down[] = { "pos_line6_text", { -0.06, 0.032 }, 1 };
    //         };
    //         class Line_7_lh : Line_1_lh {
    //             text = "---------------------";
    //             pos[] = { "pos_line7_text", { -0.06, -0.072 }, 1 };
    //             right[] = { "pos_line7_text", { 0.032, -0.072 }, 1 };
    //             down[] = { "pos_line7_text", { -0.06, 0.032 }, 1 };
    //         };
    //         class Line_8_lh : Line_1_lh {
    //             text = "CONTACT RKSL";
    //             pos[] = { "pos_line8_text", { -0.06, -0.072 }, 1 };
    //             right[] = { "pos_line8_text", { 0.032, -0.072 }, 1 };
    //             down[] = { "pos_line8_text", { -0.06, 0.032 }, 1 };
    //         };
    //         class Line_9_lh : Line_1_lh {
    //             text = "ROCK@RKSLSTUDIOS";
    //             pos[] = { "pos_line9_text", { -0.06, -0.072 }, 1 };
    //             right[] = { "pos_line9_text", { 0.032, -0.072 }, 1 };
    //             down[] = { "pos_line9_text", { -0.06, 0.032 }, 1 };
    //         };
    //         class Line_10_lh : Line_1_lh {
    //             text = ".INFO  THX";
    //             pos[] = { "pos_line10_text", { -0.06, -0.072 }, 1 };
    //             right[] = { "pos_line10_text", { 0.032, -0.072 }, 1 };
    //             down[] = { "pos_line10_text", { -0.06, 0.032 }, 1 };
    //         };
    //         class Line_11_lh : Line_1_lh {
    //             text = "---------------------";
    //             pos[] = { "pos_line11_text", { -0.06, -0.072 }, 1 };
    //             right[] = { "pos_line11_text", { 0.032, -0.072 }, 1 };
    //             down[] = { "pos_line11_text", { -0.06, 0.032 }, 1 };
    //         };
    //     };
    // };
};
