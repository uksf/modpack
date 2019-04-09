class MFD {
    // class AirplaneHUD {
    //     topLeft = "HUD LH";
    //     topRight = "HUD PH";
    //     bottomLeft = "HUD LD";
    //     class Pos10Vector {
    //         type = "vector";
    //         pos0[] = { 0.5, 0.38 };
    //         pos10[] = { 1.47, 1.48 };
    //     };
    //     borderLeft = 0;
    //     borderRight = 0;
    //     borderTop = 0;
    //     borderBottom = 0;
    //     color[] = { 0, 2, 0, 1 };
    //     class Bones {
    //         class PlaneW {
    //             type = "fixed";
    //             pos[] = { 0.4975, 0.38 };
    //         };
    //         class Center {
    //             type = "fixed";
    //             pos[] = { 0.4975, "(0.383)" };
    //         };
    //         class Velocity {
    //             type = "vector";
    //             source = "velocity";
    //             pos0[] = { 0.5, 0.383 };
    //             pos10[] = { 1.47, 1.483 };
    //         };
    //         class ASL_Instrument {
    //             type = "rotational";
    //             source = "altitudeASL";
    //             center[] = { 0.9, 0.340206 };
    //             min = 0;
    //             max = 20000;
    //             minAngle = 0;
    //             maxAngle = 72000;
    //             aspectRatio = 1.13402;
    //         };
    //         class Speed_Instrument : ASL_Instrument {
    //             source = "speed";
    //             center[] = { 0.1, 0.340206 };
    //             max = 555.556;
    //             maxAngle = 7200;
    //         };
    //         class HorizonBankRot {
    //             type = "rotational";
    //             source = "horizonBank";
    //             center[] = { 0.4975, 0.38 };
    //             min = -0.5236;
    //             max = 0.5236;
    //             minAngle = 159.25;
    //             maxAngle = 200.75;
    //             aspectRatio = 1;
    //         };
    //         class Level0 {
    //             pos0[] = { 0.4975, 0.38 };
    //             pos10[] = { 1.4675, 1.48 };
    //             type = "horizon";
    //             angle = 0;
    //         };
    //         class LevelP5 : Level0 {
    //             angle = 5;
    //         };
    //         class LevelM5 : Level0 {
    //             angle = -5;
    //         };
    //         class LevelP10 : Level0 {
    //             angle = 10;
    //         };
    //         class LevelM10 : Level0 {
    //             angle = -10;
    //         };
    //         class LevelP15 : Level0 {
    //             angle = 15;
    //         };
    //         class LevelM15 : Level0 {
    //             angle = -15;
    //         };
    //         class LevelP20 : Level0 {
    //             angle = 20;
    //         };
    //         class LevelM20 : Level0 {
    //             angle = -20;
    //         };
    //         class LevelP25 : Level0 {
    //             angle = 25;
    //         };
    //         class LevelM25 : Level0 {
    //             angle = -25;
    //         };
    //         class LevelP30 : Level0 {
    //             angle = 30;
    //         };
    //         class LevelM30 : Level0 {
    //             angle = -30;
    //         };
    //         class LevelP35 : Level0 {
    //             angle = 35;
    //         };
    //         class LevelM35 : Level0 {
    //             angle = -35;
    //         };
    //         class LevelP40 : Level0 {
    //             angle = 40;
    //         };
    //         class LevelM40 : Level0 {
    //             angle = -40;
    //         };
    //         class LevelP45 : Level0 {
    //             angle = 45;
    //         };
    //         class LevelM45 : Level0 {
    //             angle = -45;
    //         };
    //         class LevelP50 : Level0 {
    //             angle = 50;
    //         };
    //         class LevelM50 : Level0 {
    //             angle = -50;
    //         };
    //         class LevelP55 : Level0 {
    //             angle = 55;
    //         };
    //         class LevelM55 : Level0 {
    //             angle = -55;
    //         };
    //         class LevelP60 : Level0 {
    //             angle = 60;
    //         };
    //         class LevelM60 : Level0 {
    //             angle = -60;
    //         };
    //         class LevelP65 : Level0 {
    //             angle = 65;
    //         };
    //         class LevelM65 : Level0 {
    //             angle = -65;
    //         };
    //         class LevelP70 : Level0 {
    //             angle = 70;
    //         };
    //         class LevelM70 : Level0 {
    //             angle = -70;
    //         };
    //         class LevelP75 : Level0 {
    //             angle = 75;
    //         };
    //         class LevelM75 : Level0 {
    //             angle = -75;
    //         };
    //         class LevelP80 : Level0 {
    //             angle = 80;
    //         };
    //         class LevelM80 : Level0 {
    //             angle = -80;
    //         };
    //         class LevelP85 : Level0 {
    //             angle = 85;
    //         };
    //         class LevelM85 : Level0 {
    //             angle = -85;
    //         };
    //         class LevelP90 : Level0 {
    //             angle = 90;
    //         };
    //         class LevelM90 : Level0 {
    //             angle = -90;
    //         };
    //     };
    //     class Draw {
    //         alpha = 1;
    //         color[] = { 0, 2, 0 };
    //         condition = "on";
    //         class PlaneW {
    //             type = "line";
    //             points[] = { { "PlaneW", { -0.03, 0 }, 1 }, { "PlaneW", { -0.01, 0 }, 1 }, {}, { "PlaneW", { 0.03, 0 }, 1 }, { "PlaneW", { 0.01, 0 }, 1 }, {}, { "PlaneW", { 0, -0.0340206 }, 1 }, { "PlaneW", { 0, -0.0113402 }, 1 }, {}, { "PlaneW", { 0, 0.0340206 }, 1 }, { "PlaneW", { 0, 0.0113402 }, 1 } };
    //         };
    //         class PlaneHeading {
    //             type = "line";
    //             points[] = { { "Velocity", { 0, -0.0226804 }, 1 }, { "Velocity", { 0.014, -0.0158763 }, 1 }, { "Velocity", { 0.02, 0 }, 1 }, { "Velocity", { 0.014, 0.0158763 }, 1 }, { "Velocity", { 0, 0.0226804 }, 1 }, { "Velocity", { -0.014, 0.0158763 }, 1 }, { "Velocity", { -0.02, 0 }, 1 }, { "Velocity", { -0.014, -0.0158763 }, 1 }, { "Velocity", { 0, -0.0226804 }, 1 }, {}, { "Velocity", { 0.04, 0 }, 1 }, { "Velocity", { 0.02, 0 }, 1 }, {}, { "Velocity", { -0.04, 0 }, 1 }, { "Velocity", { -0.02, 0 }, 1 }, {}, { "Velocity", { 0, -0.0453608 }, 1 }, { "Velocity", { 0, -0.0226804 }, 1 } };
    //         };
    //         class Static {
    //             type = "line";
    //             points[] = { { { 0.0925, 0.445103 }, 1 }, { { 0.1075, 0.445103 }, 1 }, {}, { { 0.1, 0.436598 }, 1 }, { { 0.1, 0.453608 }, 1 }, {}, { { 0.14687, 0.42507 }, 1 }, { { 0.16187, 0.42507 }, 1 }, {}, { { 0.15437, 0.416564 }, 1 }, { { 0.15437, 0.433575 }, 1 }, {}, { { 0.180473, 0.372621 }, 1 }, { { 0.195473, 0.372621 }, 1 }, {}, { { 0.187973, 0.364116 }, 1 }, { { 0.187973, 0.381126 }, 1 }, {}, { { 0.180473, 0.307791 }, 1 }, { { 0.195473, 0.307791 }, 1 }, {}, { { 0.187973, 0.299286 }, 1 }, { { 0.187973, 0.316296 }, 1 }, {}, { { 0.14687, 0.255343 }, 1 }, { { 0.16187, 0.255343 }, 1 }, {}, { { 0.15437, 0.246838 }, 1 }, { { 0.15437, 0.263848 }, 1 }, {}, { { 0.0925, 0.235309 }, 1 }, { { 0.1075, 0.235309 }, 1 }, {}, { { 0.1, 0.226804 }, 1 }, { { 0.1, 0.243814 }, 1 }, {}, { { 0.0381299, 0.255343 }, 1 }, { { 0.0531299, 0.255343 }, 1 }, {}, { { 0.0456299, 0.246838 }, 1 }, { { 0.0456299, 0.263848 }, 1 }, {}, { { 0.00452728, 0.307791 }, 1 }, { { 0.0195273, 0.307791 }, 1 }, {}, { { 0.0120273, 0.299286 }, 1 }, { { 0.0120273, 0.316296 }, 1 }, {}, { { 0.00452728, 0.372621 }, 1 }, { { 0.0195273, 0.372621 }, 1 }, {}, { { 0.0120273, 0.364116 }, 1 }, { { 0.0120273, 0.381126 }, 1 }, {}, { { 0.0381299, 0.42507 }, 1 }, { { 0.0531299, 0.42507 }, 1 }, {}, { { 0.0456299, 0.416564 }, 1 }, { { 0.0456299, 0.433575 }, 1 }, {}, { "Speed_Instrument", { 0, 0.065 }, 1 }, { "Speed_Instrument", { 0, 0.085 }, 1 }, {}, { { 0.8925, 0.445103 }, 1 }, { { 0.9075, 0.445103 }, 1 }, {}, { { 0.9, 0.436598 }, 1 }, { { 0.9, 0.453608 }, 1 }, {}, { { 0.94687, 0.42507 }, 1 }, { { 0.96187, 0.42507 }, 1 }, {}, { { 0.95437, 0.416564 }, 1 }, { { 0.95437, 0.433575 }, 1 }, {}, { { 0.980473, 0.372621 }, 1 }, { { 0.995473, 0.372621 }, 1 }, {}, { { 0.987973, 0.364116 }, 1 }, { { 0.987973, 0.381126 }, 1 }, {}, { { 0.980473, 0.307791 }, 1 }, { { 0.995473, 0.307791 }, 1 }, {}, { { 0.987973, 0.299286 }, 1 }, { { 0.987973, 0.316296 }, 1 }, {}, { { 0.94687, 0.255343 }, 1 }, { { 0.96187, 0.255343 }, 1 }, {}, { { 0.95437, 0.246838 }, 1 }, { { 0.95437, 0.263848 }, 1 }, {}, { { 0.8925, 0.235309 }, 1 }, { { 0.9075, 0.235309 }, 1 }, {}, { { 0.9, 0.226804 }, 1 }, { { 0.9, 0.243814 }, 1 }, {}, { { 0.83813, 0.255343 }, 1 }, { { 0.85313, 0.255343 }, 1 }, {}, { { 0.84563, 0.246838 }, 1 }, { { 0.84563, 0.263848 }, 1 }, {}, { { 0.804527, 0.307791 }, 1 }, { { 0.819527, 0.307791 }, 1 }, {}, { { 0.812027, 0.299286 }, 1 }, { { 0.812027, 0.316296 }, 1 }, {}, { { 0.804527, 0.372621 }, 1 }, { { 0.819527, 0.372621 }, 1 }, {}, { { 0.812027, 0.364116 }, 1 }, { { 0.812027, 0.381126 }, 1 }, {}, { { 0.83813, 0.42507 }, 1 }, { { 0.85313, 0.42507 }, 1 }, {}, { { 0.84563, 0.416564 }, 1 }, { { 0.84563, 0.433575 }, 1 }, {}, { "ASL_Instrument", { 0, 0.065 }, 1 }, { "ASL_Instrument", { 0, 0.085 }, 1 }, {}, { { 0.5, 0.107732 }, 1 }, { { 0.51, 0.130412 }, 1 }, { { 0.49, 0.130412 }, 1 }, { { 0.5, 0.107732 }, 1 }, {}, { { 0.619959, 0.715263 }, 1 }, { { 0.631439, 0.746694 }, 1 }, {}, { { 0.58291, 0.741475 }, 1 }, { { 0.588087, 0.763383 }, 1 }, {}, { { 0.540574, 0.751025 }, 1 }, { { 0.543184, 0.773512 }, 1 }, {}, { { 0.4975, 0.742887 }, 1 }, { { 0.4975, 0.776907 }, 1 }, {}, { { 0.454426, 0.751025 }, 1 }, { { 0.451816, 0.773512 }, 1 }, {}, { { 0.41209, 0.741475 }, 1 }, { { 0.406913, 0.763383 }, 1 }, {}, { { 0.375041, 0.715263 }, 1 }, { { 0.363561, 0.746694 }, 1 } };
    //         };
    //         class HorizonBankRot {
    //             type = "line";
    //             points[] = { { "HorizonBankRot", { 0, 0.396907 }, 1 }, { "HorizonBankRot", { 0.01, 0.419588 }, 1 }, { "HorizonBankRot", { -0.01, 0.419588 }, 1 }, { "HorizonBankRot", { 0, 0.396907 }, 1 } };
    //         };
    //         class Horizont {
    //             clipTL[] = { 0.0, 0.15 };
    //             clipBR[] = { 1.0, 0.75 };
    //             class Dimmed {
    //                 class Level0 {
    //                     type = "line";
    //                     points[] = { { "Level0", { 0.4, 0.0 }, 1 }, { "Level0", { 0.05, 0.0 }, 1 }, {}, { "Level0", { -0.05, 0.0 }, 1 }, { "Level0", { -0.4, 0.0 }, 1 } };
    //                 };
    //                 class LevelM5 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM5", { -0.2, 0.005 }, 1 }, { "LevelM5", { -0.17, 0.004 }, 1 }, {}, { "LevelM5", { -0.14, 0.003 }, 1 }, { "LevelM5", { -0.11, 0.002 }, 1 }, {}, { "LevelM5", { -0.08, 0.001 }, 1 }, { "LevelM5", { -0.05, 0 }, 1 }, { "LevelM5", { -0.05, -0.03 }, 1 }, {}, { "LevelM5", { 0.05, -0.03 }, 1 }, { "LevelM5", { 0.05, 0 }, 1 }, { "LevelM5", { 0.08, 0.001 }, 1 }, {}, { "LevelM5", { 0.11, 0.002 }, 1 }, { "LevelM5", { 0.14, 0.003 }, 1 }, {}, { "LevelM5", { 0.17, 0.004 }, 1 }, { "LevelM5", { 0.2, 0.005 }, 1 } };
    //                 };
    //                 class VALM_1_5 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -5;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM5", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM5", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM5", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP5 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP5", { -0.2, 0.03 }, 1 }, { "LevelP5", { -0.2, 0 }, 1 }, { "LevelP5", { -0.05, 0 }, 1 }, {}, { "LevelP5", { 0.05, 0 }, 1 }, { "LevelP5", { 0.2, 0 }, 1 }, { "LevelP5", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_5 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "5";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP5", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP5", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP5", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM10 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM10", { -0.2, 0.01 }, 1 }, { "LevelM10", { -0.17, 0.008 }, 1 }, {}, { "LevelM10", { -0.14, 0.006 }, 1 }, { "LevelM10", { -0.11, 0.004 }, 1 }, {}, { "LevelM10", { -0.08, 0.002 }, 1 }, { "LevelM10", { -0.05, 0 }, 1 }, { "LevelM10", { -0.05, -0.03 }, 1 }, {}, { "LevelM10", { 0.05, -0.03 }, 1 }, { "LevelM10", { 0.05, 0 }, 1 }, { "LevelM10", { 0.08, 0.002 }, 1 }, {}, { "LevelM10", { 0.11, 0.004 }, 1 }, { "LevelM10", { 0.14, 0.006 }, 1 }, {}, { "LevelM10", { 0.17, 0.008 }, 1 }, { "LevelM10", { 0.2, 0.01 }, 1 } };
    //                 };
    //                 class VALM_1_10 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -10;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM10", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM10", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM10", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP10 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP10", { -0.2, 0.03 }, 1 }, { "LevelP10", { -0.2, 0 }, 1 }, { "LevelP10", { -0.05, 0 }, 1 }, {}, { "LevelP10", { 0.05, 0 }, 1 }, { "LevelP10", { 0.2, 0 }, 1 }, { "LevelP10", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_10 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "10";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP10", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP10", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP10", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM15 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM15", { -0.2, 0.015 }, 1 }, { "LevelM15", { -0.17, 0.012 }, 1 }, {}, { "LevelM15", { -0.14, 0.009 }, 1 }, { "LevelM15", { -0.11, 0.006 }, 1 }, {}, { "LevelM15", { -0.08, 0.003 }, 1 }, { "LevelM15", { -0.05, 0 }, 1 }, { "LevelM15", { -0.05, -0.03 }, 1 }, {}, { "LevelM15", { 0.05, -0.03 }, 1 }, { "LevelM15", { 0.05, 0 }, 1 }, { "LevelM15", { 0.08, 0.003 }, 1 }, {}, { "LevelM15", { 0.11, 0.006 }, 1 }, { "LevelM15", { 0.14, 0.009 }, 1 }, {}, { "LevelM15", { 0.17, 0.012 }, 1 }, { "LevelM15", { 0.2, 0.015 }, 1 } };
    //                 };
    //                 class VALM_1_15 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -15;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM15", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM15", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM15", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP15 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP15", { -0.2, 0.03 }, 1 }, { "LevelP15", { -0.2, 0 }, 1 }, { "LevelP15", { -0.05, 0 }, 1 }, {}, { "LevelP15", { 0.05, 0 }, 1 }, { "LevelP15", { 0.2, 0 }, 1 }, { "LevelP15", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_15 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "15";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP15", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP15", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP15", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM20 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM20", { -0.2, 0.02 }, 1 }, { "LevelM20", { -0.17, 0.016 }, 1 }, {}, { "LevelM20", { -0.14, 0.012 }, 1 }, { "LevelM20", { -0.11, 0.008 }, 1 }, {}, { "LevelM20", { -0.08, 0.004 }, 1 }, { "LevelM20", { -0.05, 0 }, 1 }, { "LevelM20", { -0.05, -0.03 }, 1 }, {}, { "LevelM20", { 0.05, -0.03 }, 1 }, { "LevelM20", { 0.05, 0 }, 1 }, { "LevelM20", { 0.08, 0.004 }, 1 }, {}, { "LevelM20", { 0.11, 0.008 }, 1 }, { "LevelM20", { 0.14, 0.012 }, 1 }, {}, { "LevelM20", { 0.17, 0.016 }, 1 }, { "LevelM20", { 0.2, 0.02 }, 1 } };
    //                 };
    //                 class VALM_1_20 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -20;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM20", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM20", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM20", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP20 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP20", { -0.2, 0.03 }, 1 }, { "LevelP20", { -0.2, 0 }, 1 }, { "LevelP20", { -0.05, 0 }, 1 }, {}, { "LevelP20", { 0.05, 0 }, 1 }, { "LevelP20", { 0.2, 0 }, 1 }, { "LevelP20", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_20 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "20";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP20", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP20", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP20", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM25 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM25", { -0.2, 0.025 }, 1 }, { "LevelM25", { -0.17, 0.02 }, 1 }, {}, { "LevelM25", { -0.14, 0.015 }, 1 }, { "LevelM25", { -0.11, 0.01 }, 1 }, {}, { "LevelM25", { -0.08, 0.005 }, 1 }, { "LevelM25", { -0.05, 0 }, 1 }, { "LevelM25", { -0.05, -0.03 }, 1 }, {}, { "LevelM25", { 0.05, -0.03 }, 1 }, { "LevelM25", { 0.05, 0 }, 1 }, { "LevelM25", { 0.08, 0.005 }, 1 }, {}, { "LevelM25", { 0.11, 0.01 }, 1 }, { "LevelM25", { 0.14, 0.015 }, 1 }, {}, { "LevelM25", { 0.17, 0.02 }, 1 }, { "LevelM25", { 0.2, 0.025 }, 1 } };
    //                 };
    //                 class VALM_1_25 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -25;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM25", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM25", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM25", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP25 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP25", { -0.2, 0.03 }, 1 }, { "LevelP25", { -0.2, 0 }, 1 }, { "LevelP25", { -0.05, 0 }, 1 }, {}, { "LevelP25", { 0.05, 0 }, 1 }, { "LevelP25", { 0.2, 0 }, 1 }, { "LevelP25", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_25 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "25";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP25", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP25", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP25", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM30 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM30", { -0.2, 0.03 }, 1 }, { "LevelM30", { -0.17, 0.024 }, 1 }, {}, { "LevelM30", { -0.14, 0.018 }, 1 }, { "LevelM30", { -0.11, 0.012 }, 1 }, {}, { "LevelM30", { -0.08, 0.006 }, 1 }, { "LevelM30", { -0.05, 0 }, 1 }, { "LevelM30", { -0.05, -0.03 }, 1 }, {}, { "LevelM30", { 0.05, -0.03 }, 1 }, { "LevelM30", { 0.05, 0 }, 1 }, { "LevelM30", { 0.08, 0.006 }, 1 }, {}, { "LevelM30", { 0.11, 0.012 }, 1 }, { "LevelM30", { 0.14, 0.018 }, 1 }, {}, { "LevelM30", { 0.17, 0.024 }, 1 }, { "LevelM30", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALM_1_30 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -30;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM30", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM30", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM30", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP30 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP30", { -0.2, 0.03 }, 1 }, { "LevelP30", { -0.2, 0 }, 1 }, { "LevelP30", { -0.05, 0 }, 1 }, {}, { "LevelP30", { 0.05, 0 }, 1 }, { "LevelP30", { 0.2, 0 }, 1 }, { "LevelP30", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_30 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "30";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP30", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP30", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP30", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM35 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM35", { -0.2, 0.035 }, 1 }, { "LevelM35", { -0.17, 0.028 }, 1 }, {}, { "LevelM35", { -0.14, 0.021 }, 1 }, { "LevelM35", { -0.11, 0.014 }, 1 }, {}, { "LevelM35", { -0.08, 0.007 }, 1 }, { "LevelM35", { -0.05, 0 }, 1 }, { "LevelM35", { -0.05, -0.03 }, 1 }, {}, { "LevelM35", { 0.05, -0.03 }, 1 }, { "LevelM35", { 0.05, 0 }, 1 }, { "LevelM35", { 0.08, 0.007 }, 1 }, {}, { "LevelM35", { 0.11, 0.014 }, 1 }, { "LevelM35", { 0.14, 0.021 }, 1 }, {}, { "LevelM35", { 0.17, 0.028 }, 1 }, { "LevelM35", { 0.2, 0.035 }, 1 } };
    //                 };
    //                 class VALM_1_35 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -35;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM35", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM35", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM35", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP35 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP35", { -0.2, 0.03 }, 1 }, { "LevelP35", { -0.2, 0 }, 1 }, { "LevelP35", { -0.05, 0 }, 1 }, {}, { "LevelP35", { 0.05, 0 }, 1 }, { "LevelP35", { 0.2, 0 }, 1 }, { "LevelP35", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_35 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "35";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP35", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP35", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP35", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM40 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM40", { -0.2, 0.04 }, 1 }, { "LevelM40", { -0.17, 0.032 }, 1 }, {}, { "LevelM40", { -0.14, 0.024 }, 1 }, { "LevelM40", { -0.11, 0.016 }, 1 }, {}, { "LevelM40", { -0.08, 0.008 }, 1 }, { "LevelM40", { -0.05, 0 }, 1 }, { "LevelM40", { -0.05, -0.03 }, 1 }, {}, { "LevelM40", { 0.05, -0.03 }, 1 }, { "LevelM40", { 0.05, 0 }, 1 }, { "LevelM40", { 0.08, 0.008 }, 1 }, {}, { "LevelM40", { 0.11, 0.016 }, 1 }, { "LevelM40", { 0.14, 0.024 }, 1 }, {}, { "LevelM40", { 0.17, 0.032 }, 1 }, { "LevelM40", { 0.2, 0.04 }, 1 } };
    //                 };
    //                 class VALM_1_40 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -40;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM40", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM40", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM40", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP40 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP40", { -0.2, 0.03 }, 1 }, { "LevelP40", { -0.2, 0 }, 1 }, { "LevelP40", { -0.05, 0 }, 1 }, {}, { "LevelP40", { 0.05, 0 }, 1 }, { "LevelP40", { 0.2, 0 }, 1 }, { "LevelP40", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_40 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "40";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP40", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP40", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP40", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM45 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM45", { -0.2, 0.045 }, 1 }, { "LevelM45", { -0.17, 0.036 }, 1 }, {}, { "LevelM45", { -0.14, 0.027 }, 1 }, { "LevelM45", { -0.11, 0.018 }, 1 }, {}, { "LevelM45", { -0.08, 0.009 }, 1 }, { "LevelM45", { -0.05, 0 }, 1 }, { "LevelM45", { -0.05, -0.03 }, 1 }, {}, { "LevelM45", { 0.05, -0.03 }, 1 }, { "LevelM45", { 0.05, 0 }, 1 }, { "LevelM45", { 0.08, 0.009 }, 1 }, {}, { "LevelM45", { 0.11, 0.018 }, 1 }, { "LevelM45", { 0.14, 0.027 }, 1 }, {}, { "LevelM45", { 0.17, 0.036 }, 1 }, { "LevelM45", { 0.2, 0.045 }, 1 } };
    //                 };
    //                 class VALM_1_45 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -45;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM45", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM45", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM45", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP45 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP45", { -0.2, 0.03 }, 1 }, { "LevelP45", { -0.2, 0 }, 1 }, { "LevelP45", { -0.05, 0 }, 1 }, {}, { "LevelP45", { 0.05, 0 }, 1 }, { "LevelP45", { 0.2, 0 }, 1 }, { "LevelP45", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_45 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "45";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP45", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP45", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP45", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM50 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM50", { -0.2, 0.05 }, 1 }, { "LevelM50", { -0.17, 0.04 }, 1 }, {}, { "LevelM50", { -0.14, 0.03 }, 1 }, { "LevelM50", { -0.11, 0.02 }, 1 }, {}, { "LevelM50", { -0.08, 0.01 }, 1 }, { "LevelM50", { -0.05, 0 }, 1 }, { "LevelM50", { -0.05, -0.03 }, 1 }, {}, { "LevelM50", { 0.05, -0.03 }, 1 }, { "LevelM50", { 0.05, 0 }, 1 }, { "LevelM50", { 0.08, 0.01 }, 1 }, {}, { "LevelM50", { 0.11, 0.02 }, 1 }, { "LevelM50", { 0.14, 0.03 }, 1 }, {}, { "LevelM50", { 0.17, 0.04 }, 1 }, { "LevelM50", { 0.2, 0.05 }, 1 } };
    //                 };
    //                 class VALM_1_50 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -50;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM50", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM50", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM50", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP50 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP50", { -0.2, 0.03 }, 1 }, { "LevelP50", { -0.2, 0 }, 1 }, { "LevelP50", { -0.05, 0 }, 1 }, {}, { "LevelP50", { 0.05, 0 }, 1 }, { "LevelP50", { 0.2, 0 }, 1 }, { "LevelP50", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_50 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "50";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP50", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP50", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP50", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM55 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM55", { -0.2, 0.055 }, 1 }, { "LevelM55", { -0.17, 0.044 }, 1 }, {}, { "LevelM55", { -0.14, 0.033 }, 1 }, { "LevelM55", { -0.11, 0.022 }, 1 }, {}, { "LevelM55", { -0.08, 0.011 }, 1 }, { "LevelM55", { -0.05, 0 }, 1 }, { "LevelM55", { -0.05, -0.03 }, 1 }, {}, { "LevelM55", { 0.05, -0.03 }, 1 }, { "LevelM55", { 0.05, 0 }, 1 }, { "LevelM55", { 0.08, 0.011 }, 1 }, {}, { "LevelM55", { 0.11, 0.022 }, 1 }, { "LevelM55", { 0.14, 0.033 }, 1 }, {}, { "LevelM55", { 0.17, 0.044 }, 1 }, { "LevelM55", { 0.2, 0.055 }, 1 } };
    //                 };
    //                 class VALM_1_55 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -55;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM55", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM55", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM55", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP55 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP55", { -0.2, 0.03 }, 1 }, { "LevelP55", { -0.2, 0 }, 1 }, { "LevelP55", { -0.05, 0 }, 1 }, {}, { "LevelP55", { 0.05, 0 }, 1 }, { "LevelP55", { 0.2, 0 }, 1 }, { "LevelP55", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_55 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "55";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP55", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP55", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP55", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM60 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM60", { -0.2, 0.06 }, 1 }, { "LevelM60", { -0.17, 0.048 }, 1 }, {}, { "LevelM60", { -0.14, 0.036 }, 1 }, { "LevelM60", { -0.11, 0.024 }, 1 }, {}, { "LevelM60", { -0.08, 0.012 }, 1 }, { "LevelM60", { -0.05, 0 }, 1 }, { "LevelM60", { -0.05, -0.03 }, 1 }, {}, { "LevelM60", { 0.05, -0.03 }, 1 }, { "LevelM60", { 0.05, 0 }, 1 }, { "LevelM60", { 0.08, 0.012 }, 1 }, {}, { "LevelM60", { 0.11, 0.024 }, 1 }, { "LevelM60", { 0.14, 0.036 }, 1 }, {}, { "LevelM60", { 0.17, 0.048 }, 1 }, { "LevelM60", { 0.2, 0.06 }, 1 } };
    //                 };
    //                 class VALM_1_60 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -60;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM60", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM60", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM60", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP60 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP60", { -0.2, 0.03 }, 1 }, { "LevelP60", { -0.2, 0 }, 1 }, { "LevelP60", { -0.05, 0 }, 1 }, {}, { "LevelP60", { 0.05, 0 }, 1 }, { "LevelP60", { 0.2, 0 }, 1 }, { "LevelP60", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_60 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "60";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP60", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP60", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP60", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM65 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM65", { -0.2, 0.065 }, 1 }, { "LevelM65", { -0.17, 0.052 }, 1 }, {}, { "LevelM65", { -0.14, 0.039 }, 1 }, { "LevelM65", { -0.11, 0.026 }, 1 }, {}, { "LevelM65", { -0.08, 0.013 }, 1 }, { "LevelM65", { -0.05, 0 }, 1 }, { "LevelM65", { -0.05, -0.03 }, 1 }, {}, { "LevelM65", { 0.05, -0.03 }, 1 }, { "LevelM65", { 0.05, 0 }, 1 }, { "LevelM65", { 0.08, 0.013 }, 1 }, {}, { "LevelM65", { 0.11, 0.026 }, 1 }, { "LevelM65", { 0.14, 0.039 }, 1 }, {}, { "LevelM65", { 0.17, 0.052 }, 1 }, { "LevelM65", { 0.2, 0.065 }, 1 } };
    //                 };
    //                 class VALM_1_65 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -65;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM65", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM65", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM65", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP65 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP65", { -0.2, 0.03 }, 1 }, { "LevelP65", { -0.2, 0 }, 1 }, { "LevelP65", { -0.05, 0 }, 1 }, {}, { "LevelP65", { 0.05, 0 }, 1 }, { "LevelP65", { 0.2, 0 }, 1 }, { "LevelP65", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_65 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "65";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP65", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP65", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP65", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM70 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM70", { -0.2, 0.07 }, 1 }, { "LevelM70", { -0.17, 0.056 }, 1 }, {}, { "LevelM70", { -0.14, 0.042 }, 1 }, { "LevelM70", { -0.11, 0.028 }, 1 }, {}, { "LevelM70", { -0.08, 0.014 }, 1 }, { "LevelM70", { -0.05, 0 }, 1 }, { "LevelM70", { -0.05, -0.03 }, 1 }, {}, { "LevelM70", { 0.05, -0.03 }, 1 }, { "LevelM70", { 0.05, 0 }, 1 }, { "LevelM70", { 0.08, 0.014 }, 1 }, {}, { "LevelM70", { 0.11, 0.028 }, 1 }, { "LevelM70", { 0.14, 0.042 }, 1 }, {}, { "LevelM70", { 0.17, 0.056 }, 1 }, { "LevelM70", { 0.2, 0.07 }, 1 } };
    //                 };
    //                 class VALM_1_70 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -70;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM70", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM70", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM70", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP70 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP70", { -0.2, 0.03 }, 1 }, { "LevelP70", { -0.2, 0 }, 1 }, { "LevelP70", { -0.05, 0 }, 1 }, {}, { "LevelP70", { 0.05, 0 }, 1 }, { "LevelP70", { 0.2, 0 }, 1 }, { "LevelP70", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_70 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "70";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP70", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP70", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP70", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM75 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM75", { -0.2, 0.075 }, 1 }, { "LevelM75", { -0.17, 0.06 }, 1 }, {}, { "LevelM75", { -0.14, 0.045 }, 1 }, { "LevelM75", { -0.11, 0.03 }, 1 }, {}, { "LevelM75", { -0.08, 0.015 }, 1 }, { "LevelM75", { -0.05, 0 }, 1 }, { "LevelM75", { -0.05, -0.03 }, 1 }, {}, { "LevelM75", { 0.05, -0.03 }, 1 }, { "LevelM75", { 0.05, 0 }, 1 }, { "LevelM75", { 0.08, 0.015 }, 1 }, {}, { "LevelM75", { 0.11, 0.03 }, 1 }, { "LevelM75", { 0.14, 0.045 }, 1 }, {}, { "LevelM75", { 0.17, 0.06 }, 1 }, { "LevelM75", { 0.2, 0.075 }, 1 } };
    //                 };
    //                 class VALM_1_75 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -75;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM75", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM75", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM75", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP75 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP75", { -0.2, 0.03 }, 1 }, { "LevelP75", { -0.2, 0 }, 1 }, { "LevelP75", { -0.05, 0 }, 1 }, {}, { "LevelP75", { 0.05, 0 }, 1 }, { "LevelP75", { 0.2, 0 }, 1 }, { "LevelP75", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_75 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "75";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP75", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP75", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP75", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM80 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM80", { -0.2, 0.08 }, 1 }, { "LevelM80", { -0.17, 0.064 }, 1 }, {}, { "LevelM80", { -0.14, 0.048 }, 1 }, { "LevelM80", { -0.11, 0.032 }, 1 }, {}, { "LevelM80", { -0.08, 0.016 }, 1 }, { "LevelM80", { -0.05, 0 }, 1 }, { "LevelM80", { -0.05, -0.03 }, 1 }, {}, { "LevelM80", { 0.05, -0.03 }, 1 }, { "LevelM80", { 0.05, 0 }, 1 }, { "LevelM80", { 0.08, 0.016 }, 1 }, {}, { "LevelM80", { 0.11, 0.032 }, 1 }, { "LevelM80", { 0.14, 0.048 }, 1 }, {}, { "LevelM80", { 0.17, 0.064 }, 1 }, { "LevelM80", { 0.2, 0.08 }, 1 } };
    //                 };
    //                 class VALM_1_80 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -80;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM80", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM80", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM80", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP80 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP80", { -0.2, 0.03 }, 1 }, { "LevelP80", { -0.2, 0 }, 1 }, { "LevelP80", { -0.05, 0 }, 1 }, {}, { "LevelP80", { 0.05, 0 }, 1 }, { "LevelP80", { 0.2, 0 }, 1 }, { "LevelP80", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_80 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "80";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP80", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP80", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP80", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM85 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM85", { -0.2, 0.085 }, 1 }, { "LevelM85", { -0.17, 0.068 }, 1 }, {}, { "LevelM85", { -0.14, 0.051 }, 1 }, { "LevelM85", { -0.11, 0.034 }, 1 }, {}, { "LevelM85", { -0.08, 0.017 }, 1 }, { "LevelM85", { -0.05, 0 }, 1 }, { "LevelM85", { -0.05, -0.03 }, 1 }, {}, { "LevelM85", { 0.05, -0.03 }, 1 }, { "LevelM85", { 0.05, 0 }, 1 }, { "LevelM85", { 0.08, 0.017 }, 1 }, {}, { "LevelM85", { 0.11, 0.034 }, 1 }, { "LevelM85", { 0.14, 0.051 }, 1 }, {}, { "LevelM85", { 0.17, 0.068 }, 1 }, { "LevelM85", { 0.2, 0.085 }, 1 } };
    //                 };
    //                 class VALM_1_85 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -85;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM85", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM85", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM85", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP85 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP85", { -0.2, 0.03 }, 1 }, { "LevelP85", { -0.2, 0 }, 1 }, { "LevelP85", { -0.05, 0 }, 1 }, {}, { "LevelP85", { 0.05, 0 }, 1 }, { "LevelP85", { 0.2, 0 }, 1 }, { "LevelP85", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_85 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "85";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP85", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP85", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP85", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM90 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM90", { -0.2, 0.09 }, 1 }, { "LevelM90", { -0.17, 0.072 }, 1 }, {}, { "LevelM90", { -0.14, 0.054 }, 1 }, { "LevelM90", { -0.11, 0.036 }, 1 }, {}, { "LevelM90", { -0.08, 0.018 }, 1 }, { "LevelM90", { -0.05, 0 }, 1 }, { "LevelM90", { -0.05, -0.03 }, 1 }, {}, { "LevelM90", { 0.05, -0.03 }, 1 }, { "LevelM90", { 0.05, 0 }, 1 }, { "LevelM90", { 0.08, 0.018 }, 1 }, {}, { "LevelM90", { 0.11, 0.036 }, 1 }, { "LevelM90", { 0.14, 0.054 }, 1 }, {}, { "LevelM90", { 0.17, 0.072 }, 1 }, { "LevelM90", { 0.2, 0.09 }, 1 } };
    //                 };
    //                 class VALM_1_90 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -90;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM90", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM90", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM90", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP90 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP90", { -0.2, 0.03 }, 1 }, { "LevelP90", { -0.2, 0 }, 1 }, { "LevelP90", { -0.05, 0 }, 1 }, {}, { "LevelP90", { 0.05, 0 }, 1 }, { "LevelP90", { 0.2, 0 }, 1 }, { "LevelP90", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_90 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "90";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP90", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP90", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP90", { -0.18, 0.082 }, 1 };
    //                 };
    //             };
    //         };
    //         class SpeedNumber {
    //             type = "text";
    //             source = "speed";
    //             sourceScale = 1.94384;
    //             align = "center";
    //             scale = 1;
    //             pos[] = { { 0.1, 0.311856 }, 1 };
    //             right[] = { { 0.16, 0.311856 }, 1 };
    //             down[] = { { 0.1, 0.368557 }, 1 };
    //         };
    //         class AltNumber : SpeedNumber {
    //             source = "altitudeASL";
    //             sourceScale = 3.28084;
    //             pos[] = { { 0.9, 0.311856 }, 1 };
    //             right[] = { { 0.96, 0.311856 }, 1 };
    //             down[] = { { 0.9, 0.368557 }, 1 };
    //         };
    //         class AltNumberAGL {
    //             class Text {
    //                 type = "text";
    //                 source = "static";
    //                 text = "H";
    //                 align = "left";
    //                 scale = 1;
    //                 pos[] = { { 0.8, 0.53866 }, 1 };
    //                 right[] = { { 0.86, 0.53866 }, 1 };
    //                 down[] = { { 0.8, 0.595361 }, 1 };
    //             };
    //             class Box {
    //                 type = "line";
    //                 points[] = { { { 0.81, 0.595361 }, 1 }, { { 1, 0.595361 }, 1 }, { { 1, 0.53866 }, 1 }, { { 0.81, 0.53866 }, 1 }, { { 0.81, 0.595361 }, 1 } };
    //             };
    //             class AltNumber {
    //                 type = "text";
    //                 source = "altitudeAGL";
    //                 sourceScale = 3.28084;
    //                 align = "left";
    //                 scale = 1;
    //                 pos[] = { { 0.99, 0.53866 }, 1 };
    //                 right[] = { { 1.05, 0.53866 }, 1 };
    //                 down[] = { { 0.99, 0.595361 }, 1 };
    //             };
    //         };
    //         class Gear {
    //             condition = "ils";
    //             class Text {
    //                 class Text {
    //                     type = "text";
    //                     source = "static";
    //                     text = "GEAR";
    //                     align = "left";
    //                     scale = 1;
    //                     pos[] = { { 0.99, 0.822165 }, 1 };
    //                     right[] = { { 1.05, 0.822165 }, 1 };
    //                     down[] = { { 0.99, 0.878866 }, 1 };
    //                 };
    //             };
    //         };
    //         class Flaps {
    //             condition = "flaps";
    //             class FlapsText {
    //                 class Text {
    //                     type = "text";
    //                     source = "static";
    //                     text = "FLAPS";
    //                     align = "left";
    //                     scale = 1;
    //                     pos[] = { { 0.99, 0.878866 }, 1 };
    //                     right[] = { { 1.05, 0.878866 }, 1 };
    //                     down[] = { { 0.99, 0.935567 }, 1 };
    //                 };
    //             };
    //         };
    //         class Lights {
    //             condition = "lights";
    //             class Highlighted {
    //                 class Text {
    //                     type = "text";
    //                     source = "static";
    //                     text = "LIGHTS";
    //                     align = "right";
    //                     scale = 1;
    //                     pos[] = { { 0.01, 0.822165 }, 1 };
    //                     right[] = { { 0.07, 0.822165 }, 1 };
    //                     down[] = { { 0.01, 0.878866 }, 1 };
    //                 };
    //             };
    //         };
    //         class CollisionLights {
    //             condition = "collisionlights";
    //             class Highlighted {
    //                 class Text {
    //                     type = "text";
    //                     source = "static";
    //                     text = "ANTI-COL";
    //                     align = "right";
    //                     scale = 1;
    //                     pos[] = { { 0.01, 0.878866 }, 1 };
    //                     right[] = { { 0.07, 0.878866 }, 1 };
    //                     down[] = { { 0.01, 0.935567 }, 1 };
    //                 };
    //             };
    //         };
    //         class Stall {
    //             condition = "stall";
    //             color[] = { 1.0, 0.0, 0.0 };
    //             blinkingPattern[] = { 0.2, 0.2 };
    //             blinkingStartsOn = 1;
    //             class Text {
    //                 type = "text";
    //                 source = "static";
    //                 text = "STALL";
    //                 align = "center";
    //                 scale = 1;
    //                 pos[] = { { 0.5, 0.204124 }, 1 };
    //                 right[] = { { 0.56, 0.204124 }, 1 };
    //                 down[] = { { 0.5, 0.260825 }, 1 };
    //             };
    //         };
    //         class HeadingScale {
    //             type = "scale";
    //             horizontal = 1;
    //             source = "Heading";
    //             sourceScale = 0.1;
    //             top = 0.2;
    //             center = 0.5;
    //             bottom = 0.8;
    //             lineXleft = 0.102062;
    //             lineYright = 0.0907216;
    //             lineXleftMajor = 0.102062;
    //             lineYrightMajor = 0.0793814;
    //             majorLineEach = 5;
    //             numberEach = 5;
    //             step = 0.2;
    //             StepSize = 0.03;
    //             align = "center";
    //             scale = 1;
    //             pos[] = { 0.2, 0.0198454 };
    //             right[] = { 0.26, 0.0198454 };
    //             down[] = { 0.2, 0.0765464 };
    //         };
    //     };
    // };
    // class AirplaneHUD2 {
    //     topLeft = "HUD2 LH";
    //     topRight = "HUD2 PH";
    //     bottomLeft = "HUD2 LD";
    //     class Pos10Vector {
    //         type = "vector";
    //         pos0[] = { 0.5, 0.38 };
    //         pos10[] = { 1.47, 1.48 };
    //     };
    //     borderLeft = 0;
    //     borderRight = 0;
    //     borderTop = 0;
    //     borderBottom = 0;
    //     color[] = { 0, 2, 0, 1 };
    //     class Bones {
    //         class PlaneW {
    //             type = "fixed";
    //             pos[] = { 0.4975, 0.38 };
    //         };
    //         class Center {
    //             type = "fixed";
    //             pos[] = { 0.4975, "(0.383)" };
    //         };
    //         class Velocity {
    //             type = "vector";
    //             source = "velocity";
    //             pos0[] = { 0.5, 0.383 };
    //             pos10[] = { 1.47, 1.483 };
    //         };
    //         class ASL_Instrument {
    //             type = "rotational";
    //             source = "altitudeASL";
    //             center[] = { 0.9, 0.340206 };
    //             min = 0;
    //             max = 20000;
    //             minAngle = 0;
    //             maxAngle = 72000;
    //             aspectRatio = 1.13402;
    //         };
    //         class Speed_Instrument : ASL_Instrument {
    //             source = "speed";
    //             center[] = { 0.1, 0.340206 };
    //             max = 555.556;
    //             maxAngle = 7200;
    //         };
    //         class HorizonBankRot {
    //             type = "rotational";
    //             source = "horizonBank";
    //             center[] = { 0.4975, 0.38 };
    //             min = -0.5236;
    //             max = 0.5236;
    //             minAngle = 159.25;
    //             maxAngle = 200.75;
    //             aspectRatio = 1;
    //         };
    //         class Level0 {
    //             pos0[] = { 0.4975, 0.38 };
    //             pos10[] = { 1.4675, 1.48 };
    //             type = "horizon";
    //             angle = 0;
    //         };
    //         class LevelP5 : Level0 {
    //             angle = 5;
    //         };
    //         class LevelM5 : Level0 {
    //             angle = -5;
    //         };
    //         class LevelP10 : Level0 {
    //             angle = 10;
    //         };
    //         class LevelM10 : Level0 {
    //             angle = -10;
    //         };
    //         class LevelP15 : Level0 {
    //             angle = 15;
    //         };
    //         class LevelM15 : Level0 {
    //             angle = -15;
    //         };
    //         class LevelP20 : Level0 {
    //             angle = 20;
    //         };
    //         class LevelM20 : Level0 {
    //             angle = -20;
    //         };
    //         class LevelP25 : Level0 {
    //             angle = 25;
    //         };
    //         class LevelM25 : Level0 {
    //             angle = -25;
    //         };
    //         class LevelP30 : Level0 {
    //             angle = 30;
    //         };
    //         class LevelM30 : Level0 {
    //             angle = -30;
    //         };
    //         class LevelP35 : Level0 {
    //             angle = 35;
    //         };
    //         class LevelM35 : Level0 {
    //             angle = -35;
    //         };
    //         class LevelP40 : Level0 {
    //             angle = 40;
    //         };
    //         class LevelM40 : Level0 {
    //             angle = -40;
    //         };
    //         class LevelP45 : Level0 {
    //             angle = 45;
    //         };
    //         class LevelM45 : Level0 {
    //             angle = -45;
    //         };
    //         class LevelP50 : Level0 {
    //             angle = 50;
    //         };
    //         class LevelM50 : Level0 {
    //             angle = -50;
    //         };
    //         class LevelP55 : Level0 {
    //             angle = 55;
    //         };
    //         class LevelM55 : Level0 {
    //             angle = -55;
    //         };
    //         class LevelP60 : Level0 {
    //             angle = 60;
    //         };
    //         class LevelM60 : Level0 {
    //             angle = -60;
    //         };
    //         class LevelP65 : Level0 {
    //             angle = 65;
    //         };
    //         class LevelM65 : Level0 {
    //             angle = -65;
    //         };
    //         class LevelP70 : Level0 {
    //             angle = 70;
    //         };
    //         class LevelM70 : Level0 {
    //             angle = -70;
    //         };
    //         class LevelP75 : Level0 {
    //             angle = 75;
    //         };
    //         class LevelM75 : Level0 {
    //             angle = -75;
    //         };
    //         class LevelP80 : Level0 {
    //             angle = 80;
    //         };
    //         class LevelM80 : Level0 {
    //             angle = -80;
    //         };
    //         class LevelP85 : Level0 {
    //             angle = 85;
    //         };
    //         class LevelM85 : Level0 {
    //             angle = -85;
    //         };
    //         class LevelP90 : Level0 {
    //             angle = 90;
    //         };
    //         class LevelM90 : Level0 {
    //             angle = -90;
    //         };
    //     };
    //     class Draw {
    //         alpha = 1;
    //         color[] = { 0, 2, 0 };
    //         condition = "on";
    //         class PlaneW {
    //             type = "line";
    //             points[] = { { "PlaneW", { -0.03, 0 }, 1 }, { "PlaneW", { -0.01, 0 }, 1 }, {}, { "PlaneW", { 0.03, 0 }, 1 }, { "PlaneW", { 0.01, 0 }, 1 }, {}, { "PlaneW", { 0, -0.0340206 }, 1 }, { "PlaneW", { 0, -0.0113402 }, 1 }, {}, { "PlaneW", { 0, 0.0340206 }, 1 }, { "PlaneW", { 0, 0.0113402 }, 1 } };
    //         };
    //         class PlaneHeading {
    //             type = "line";
    //             points[] = { { "Velocity", { 0, -0.0226804 }, 1 }, { "Velocity", { 0.014, -0.0158763 }, 1 }, { "Velocity", { 0.02, 0 }, 1 }, { "Velocity", { 0.014, 0.0158763 }, 1 }, { "Velocity", { 0, 0.0226804 }, 1 }, { "Velocity", { -0.014, 0.0158763 }, 1 }, { "Velocity", { -0.02, 0 }, 1 }, { "Velocity", { -0.014, -0.0158763 }, 1 }, { "Velocity", { 0, -0.0226804 }, 1 }, {}, { "Velocity", { 0.04, 0 }, 1 }, { "Velocity", { 0.02, 0 }, 1 }, {}, { "Velocity", { -0.04, 0 }, 1 }, { "Velocity", { -0.02, 0 }, 1 }, {}, { "Velocity", { 0, -0.0453608 }, 1 }, { "Velocity", { 0, -0.0226804 }, 1 } };
    //         };
    //         class Static {
    //             type = "line";
    //             points[] = { { { 0.0925, 0.445103 }, 1 }, { { 0.1075, 0.445103 }, 1 }, {}, { { 0.1, 0.436598 }, 1 }, { { 0.1, 0.453608 }, 1 }, {}, { { 0.14687, 0.42507 }, 1 }, { { 0.16187, 0.42507 }, 1 }, {}, { { 0.15437, 0.416564 }, 1 }, { { 0.15437, 0.433575 }, 1 }, {}, { { 0.180473, 0.372621 }, 1 }, { { 0.195473, 0.372621 }, 1 }, {}, { { 0.187973, 0.364116 }, 1 }, { { 0.187973, 0.381126 }, 1 }, {}, { { 0.180473, 0.307791 }, 1 }, { { 0.195473, 0.307791 }, 1 }, {}, { { 0.187973, 0.299286 }, 1 }, { { 0.187973, 0.316296 }, 1 }, {}, { { 0.14687, 0.255343 }, 1 }, { { 0.16187, 0.255343 }, 1 }, {}, { { 0.15437, 0.246838 }, 1 }, { { 0.15437, 0.263848 }, 1 }, {}, { { 0.0925, 0.235309 }, 1 }, { { 0.1075, 0.235309 }, 1 }, {}, { { 0.1, 0.226804 }, 1 }, { { 0.1, 0.243814 }, 1 }, {}, { { 0.0381299, 0.255343 }, 1 }, { { 0.0531299, 0.255343 }, 1 }, {}, { { 0.0456299, 0.246838 }, 1 }, { { 0.0456299, 0.263848 }, 1 }, {}, { { 0.00452728, 0.307791 }, 1 }, { { 0.0195273, 0.307791 }, 1 }, {}, { { 0.0120273, 0.299286 }, 1 }, { { 0.0120273, 0.316296 }, 1 }, {}, { { 0.00452728, 0.372621 }, 1 }, { { 0.0195273, 0.372621 }, 1 }, {}, { { 0.0120273, 0.364116 }, 1 }, { { 0.0120273, 0.381126 }, 1 }, {}, { { 0.0381299, 0.42507 }, 1 }, { { 0.0531299, 0.42507 }, 1 }, {}, { { 0.0456299, 0.416564 }, 1 }, { { 0.0456299, 0.433575 }, 1 }, {}, { "Speed_Instrument", { 0, 0.065 }, 1 }, { "Speed_Instrument", { 0, 0.085 }, 1 }, {}, { { 0.8925, 0.445103 }, 1 }, { { 0.9075, 0.445103 }, 1 }, {}, { { 0.9, 0.436598 }, 1 }, { { 0.9, 0.453608 }, 1 }, {}, { { 0.94687, 0.42507 }, 1 }, { { 0.96187, 0.42507 }, 1 }, {}, { { 0.95437, 0.416564 }, 1 }, { { 0.95437, 0.433575 }, 1 }, {}, { { 0.980473, 0.372621 }, 1 }, { { 0.995473, 0.372621 }, 1 }, {}, { { 0.987973, 0.364116 }, 1 }, { { 0.987973, 0.381126 }, 1 }, {}, { { 0.980473, 0.307791 }, 1 }, { { 0.995473, 0.307791 }, 1 }, {}, { { 0.987973, 0.299286 }, 1 }, { { 0.987973, 0.316296 }, 1 }, {}, { { 0.94687, 0.255343 }, 1 }, { { 0.96187, 0.255343 }, 1 }, {}, { { 0.95437, 0.246838 }, 1 }, { { 0.95437, 0.263848 }, 1 }, {}, { { 0.8925, 0.235309 }, 1 }, { { 0.9075, 0.235309 }, 1 }, {}, { { 0.9, 0.226804 }, 1 }, { { 0.9, 0.243814 }, 1 }, {}, { { 0.83813, 0.255343 }, 1 }, { { 0.85313, 0.255343 }, 1 }, {}, { { 0.84563, 0.246838 }, 1 }, { { 0.84563, 0.263848 }, 1 }, {}, { { 0.804527, 0.307791 }, 1 }, { { 0.819527, 0.307791 }, 1 }, {}, { { 0.812027, 0.299286 }, 1 }, { { 0.812027, 0.316296 }, 1 }, {}, { { 0.804527, 0.372621 }, 1 }, { { 0.819527, 0.372621 }, 1 }, {}, { { 0.812027, 0.364116 }, 1 }, { { 0.812027, 0.381126 }, 1 }, {}, { { 0.83813, 0.42507 }, 1 }, { { 0.85313, 0.42507 }, 1 }, {}, { { 0.84563, 0.416564 }, 1 }, { { 0.84563, 0.433575 }, 1 }, {}, { "ASL_Instrument", { 0, 0.065 }, 1 }, { "ASL_Instrument", { 0, 0.085 }, 1 }, {}, { { 0.5, 0.107732 }, 1 }, { { 0.51, 0.130412 }, 1 }, { { 0.49, 0.130412 }, 1 }, { { 0.5, 0.107732 }, 1 }, {}, { { 0.619959, 0.715263 }, 1 }, { { 0.631439, 0.746694 }, 1 }, {}, { { 0.58291, 0.741475 }, 1 }, { { 0.588087, 0.763383 }, 1 }, {}, { { 0.540574, 0.751025 }, 1 }, { { 0.543184, 0.773512 }, 1 }, {}, { { 0.4975, 0.742887 }, 1 }, { { 0.4975, 0.776907 }, 1 }, {}, { { 0.454426, 0.751025 }, 1 }, { { 0.451816, 0.773512 }, 1 }, {}, { { 0.41209, 0.741475 }, 1 }, { { 0.406913, 0.763383 }, 1 }, {}, { { 0.375041, 0.715263 }, 1 }, { { 0.363561, 0.746694 }, 1 } };
    //         };
    //         class HorizonBankRot {
    //             type = "line";
    //             points[] = { { "HorizonBankRot", { 0, 0.396907 }, 1 }, { "HorizonBankRot", { 0.01, 0.419588 }, 1 }, { "HorizonBankRot", { -0.01, 0.419588 }, 1 }, { "HorizonBankRot", { 0, 0.396907 }, 1 } };
    //         };
    //         class Horizont {
    //             clipTL[] = { 0.0, 0.15 };
    //             clipBR[] = { 1.0, 0.75 };
    //             class Dimmed {
    //                 class Level0 {
    //                     type = "line";
    //                     points[] = { { "Level0", { 0.4, 0.0 }, 1 }, { "Level0", { 0.05, 0.0 }, 1 }, {}, { "Level0", { -0.05, 0.0 }, 1 }, { "Level0", { -0.4, 0.0 }, 1 } };
    //                 };
    //                 class LevelM5 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM5", { -0.2, 0.005 }, 1 }, { "LevelM5", { -0.17, 0.004 }, 1 }, {}, { "LevelM5", { -0.14, 0.003 }, 1 }, { "LevelM5", { -0.11, 0.002 }, 1 }, {}, { "LevelM5", { -0.08, 0.001 }, 1 }, { "LevelM5", { -0.05, 0 }, 1 }, { "LevelM5", { -0.05, -0.03 }, 1 }, {}, { "LevelM5", { 0.05, -0.03 }, 1 }, { "LevelM5", { 0.05, 0 }, 1 }, { "LevelM5", { 0.08, 0.001 }, 1 }, {}, { "LevelM5", { 0.11, 0.002 }, 1 }, { "LevelM5", { 0.14, 0.003 }, 1 }, {}, { "LevelM5", { 0.17, 0.004 }, 1 }, { "LevelM5", { 0.2, 0.005 }, 1 } };
    //                 };
    //                 class VALM_1_5 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -5;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM5", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM5", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM5", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP5 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP5", { -0.2, 0.03 }, 1 }, { "LevelP5", { -0.2, 0 }, 1 }, { "LevelP5", { -0.05, 0 }, 1 }, {}, { "LevelP5", { 0.05, 0 }, 1 }, { "LevelP5", { 0.2, 0 }, 1 }, { "LevelP5", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_5 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "5";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP5", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP5", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP5", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM10 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM10", { -0.2, 0.01 }, 1 }, { "LevelM10", { -0.17, 0.008 }, 1 }, {}, { "LevelM10", { -0.14, 0.006 }, 1 }, { "LevelM10", { -0.11, 0.004 }, 1 }, {}, { "LevelM10", { -0.08, 0.002 }, 1 }, { "LevelM10", { -0.05, 0 }, 1 }, { "LevelM10", { -0.05, -0.03 }, 1 }, {}, { "LevelM10", { 0.05, -0.03 }, 1 }, { "LevelM10", { 0.05, 0 }, 1 }, { "LevelM10", { 0.08, 0.002 }, 1 }, {}, { "LevelM10", { 0.11, 0.004 }, 1 }, { "LevelM10", { 0.14, 0.006 }, 1 }, {}, { "LevelM10", { 0.17, 0.008 }, 1 }, { "LevelM10", { 0.2, 0.01 }, 1 } };
    //                 };
    //                 class VALM_1_10 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -10;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM10", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM10", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM10", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP10 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP10", { -0.2, 0.03 }, 1 }, { "LevelP10", { -0.2, 0 }, 1 }, { "LevelP10", { -0.05, 0 }, 1 }, {}, { "LevelP10", { 0.05, 0 }, 1 }, { "LevelP10", { 0.2, 0 }, 1 }, { "LevelP10", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_10 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "10";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP10", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP10", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP10", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM15 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM15", { -0.2, 0.015 }, 1 }, { "LevelM15", { -0.17, 0.012 }, 1 }, {}, { "LevelM15", { -0.14, 0.009 }, 1 }, { "LevelM15", { -0.11, 0.006 }, 1 }, {}, { "LevelM15", { -0.08, 0.003 }, 1 }, { "LevelM15", { -0.05, 0 }, 1 }, { "LevelM15", { -0.05, -0.03 }, 1 }, {}, { "LevelM15", { 0.05, -0.03 }, 1 }, { "LevelM15", { 0.05, 0 }, 1 }, { "LevelM15", { 0.08, 0.003 }, 1 }, {}, { "LevelM15", { 0.11, 0.006 }, 1 }, { "LevelM15", { 0.14, 0.009 }, 1 }, {}, { "LevelM15", { 0.17, 0.012 }, 1 }, { "LevelM15", { 0.2, 0.015 }, 1 } };
    //                 };
    //                 class VALM_1_15 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -15;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM15", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM15", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM15", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP15 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP15", { -0.2, 0.03 }, 1 }, { "LevelP15", { -0.2, 0 }, 1 }, { "LevelP15", { -0.05, 0 }, 1 }, {}, { "LevelP15", { 0.05, 0 }, 1 }, { "LevelP15", { 0.2, 0 }, 1 }, { "LevelP15", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_15 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "15";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP15", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP15", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP15", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM20 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM20", { -0.2, 0.02 }, 1 }, { "LevelM20", { -0.17, 0.016 }, 1 }, {}, { "LevelM20", { -0.14, 0.012 }, 1 }, { "LevelM20", { -0.11, 0.008 }, 1 }, {}, { "LevelM20", { -0.08, 0.004 }, 1 }, { "LevelM20", { -0.05, 0 }, 1 }, { "LevelM20", { -0.05, -0.03 }, 1 }, {}, { "LevelM20", { 0.05, -0.03 }, 1 }, { "LevelM20", { 0.05, 0 }, 1 }, { "LevelM20", { 0.08, 0.004 }, 1 }, {}, { "LevelM20", { 0.11, 0.008 }, 1 }, { "LevelM20", { 0.14, 0.012 }, 1 }, {}, { "LevelM20", { 0.17, 0.016 }, 1 }, { "LevelM20", { 0.2, 0.02 }, 1 } };
    //                 };
    //                 class VALM_1_20 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -20;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM20", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM20", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM20", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP20 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP20", { -0.2, 0.03 }, 1 }, { "LevelP20", { -0.2, 0 }, 1 }, { "LevelP20", { -0.05, 0 }, 1 }, {}, { "LevelP20", { 0.05, 0 }, 1 }, { "LevelP20", { 0.2, 0 }, 1 }, { "LevelP20", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_20 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "20";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP20", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP20", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP20", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM25 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM25", { -0.2, 0.025 }, 1 }, { "LevelM25", { -0.17, 0.02 }, 1 }, {}, { "LevelM25", { -0.14, 0.015 }, 1 }, { "LevelM25", { -0.11, 0.01 }, 1 }, {}, { "LevelM25", { -0.08, 0.005 }, 1 }, { "LevelM25", { -0.05, 0 }, 1 }, { "LevelM25", { -0.05, -0.03 }, 1 }, {}, { "LevelM25", { 0.05, -0.03 }, 1 }, { "LevelM25", { 0.05, 0 }, 1 }, { "LevelM25", { 0.08, 0.005 }, 1 }, {}, { "LevelM25", { 0.11, 0.01 }, 1 }, { "LevelM25", { 0.14, 0.015 }, 1 }, {}, { "LevelM25", { 0.17, 0.02 }, 1 }, { "LevelM25", { 0.2, 0.025 }, 1 } };
    //                 };
    //                 class VALM_1_25 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -25;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM25", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM25", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM25", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP25 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP25", { -0.2, 0.03 }, 1 }, { "LevelP25", { -0.2, 0 }, 1 }, { "LevelP25", { -0.05, 0 }, 1 }, {}, { "LevelP25", { 0.05, 0 }, 1 }, { "LevelP25", { 0.2, 0 }, 1 }, { "LevelP25", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_25 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "25";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP25", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP25", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP25", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM30 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM30", { -0.2, 0.03 }, 1 }, { "LevelM30", { -0.17, 0.024 }, 1 }, {}, { "LevelM30", { -0.14, 0.018 }, 1 }, { "LevelM30", { -0.11, 0.012 }, 1 }, {}, { "LevelM30", { -0.08, 0.006 }, 1 }, { "LevelM30", { -0.05, 0 }, 1 }, { "LevelM30", { -0.05, -0.03 }, 1 }, {}, { "LevelM30", { 0.05, -0.03 }, 1 }, { "LevelM30", { 0.05, 0 }, 1 }, { "LevelM30", { 0.08, 0.006 }, 1 }, {}, { "LevelM30", { 0.11, 0.012 }, 1 }, { "LevelM30", { 0.14, 0.018 }, 1 }, {}, { "LevelM30", { 0.17, 0.024 }, 1 }, { "LevelM30", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALM_1_30 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -30;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM30", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM30", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM30", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP30 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP30", { -0.2, 0.03 }, 1 }, { "LevelP30", { -0.2, 0 }, 1 }, { "LevelP30", { -0.05, 0 }, 1 }, {}, { "LevelP30", { 0.05, 0 }, 1 }, { "LevelP30", { 0.2, 0 }, 1 }, { "LevelP30", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_30 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "30";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP30", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP30", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP30", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM35 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM35", { -0.2, 0.035 }, 1 }, { "LevelM35", { -0.17, 0.028 }, 1 }, {}, { "LevelM35", { -0.14, 0.021 }, 1 }, { "LevelM35", { -0.11, 0.014 }, 1 }, {}, { "LevelM35", { -0.08, 0.007 }, 1 }, { "LevelM35", { -0.05, 0 }, 1 }, { "LevelM35", { -0.05, -0.03 }, 1 }, {}, { "LevelM35", { 0.05, -0.03 }, 1 }, { "LevelM35", { 0.05, 0 }, 1 }, { "LevelM35", { 0.08, 0.007 }, 1 }, {}, { "LevelM35", { 0.11, 0.014 }, 1 }, { "LevelM35", { 0.14, 0.021 }, 1 }, {}, { "LevelM35", { 0.17, 0.028 }, 1 }, { "LevelM35", { 0.2, 0.035 }, 1 } };
    //                 };
    //                 class VALM_1_35 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -35;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM35", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM35", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM35", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP35 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP35", { -0.2, 0.03 }, 1 }, { "LevelP35", { -0.2, 0 }, 1 }, { "LevelP35", { -0.05, 0 }, 1 }, {}, { "LevelP35", { 0.05, 0 }, 1 }, { "LevelP35", { 0.2, 0 }, 1 }, { "LevelP35", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_35 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "35";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP35", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP35", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP35", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM40 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM40", { -0.2, 0.04 }, 1 }, { "LevelM40", { -0.17, 0.032 }, 1 }, {}, { "LevelM40", { -0.14, 0.024 }, 1 }, { "LevelM40", { -0.11, 0.016 }, 1 }, {}, { "LevelM40", { -0.08, 0.008 }, 1 }, { "LevelM40", { -0.05, 0 }, 1 }, { "LevelM40", { -0.05, -0.03 }, 1 }, {}, { "LevelM40", { 0.05, -0.03 }, 1 }, { "LevelM40", { 0.05, 0 }, 1 }, { "LevelM40", { 0.08, 0.008 }, 1 }, {}, { "LevelM40", { 0.11, 0.016 }, 1 }, { "LevelM40", { 0.14, 0.024 }, 1 }, {}, { "LevelM40", { 0.17, 0.032 }, 1 }, { "LevelM40", { 0.2, 0.04 }, 1 } };
    //                 };
    //                 class VALM_1_40 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -40;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM40", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM40", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM40", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP40 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP40", { -0.2, 0.03 }, 1 }, { "LevelP40", { -0.2, 0 }, 1 }, { "LevelP40", { -0.05, 0 }, 1 }, {}, { "LevelP40", { 0.05, 0 }, 1 }, { "LevelP40", { 0.2, 0 }, 1 }, { "LevelP40", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_40 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "40";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP40", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP40", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP40", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM45 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM45", { -0.2, 0.045 }, 1 }, { "LevelM45", { -0.17, 0.036 }, 1 }, {}, { "LevelM45", { -0.14, 0.027 }, 1 }, { "LevelM45", { -0.11, 0.018 }, 1 }, {}, { "LevelM45", { -0.08, 0.009 }, 1 }, { "LevelM45", { -0.05, 0 }, 1 }, { "LevelM45", { -0.05, -0.03 }, 1 }, {}, { "LevelM45", { 0.05, -0.03 }, 1 }, { "LevelM45", { 0.05, 0 }, 1 }, { "LevelM45", { 0.08, 0.009 }, 1 }, {}, { "LevelM45", { 0.11, 0.018 }, 1 }, { "LevelM45", { 0.14, 0.027 }, 1 }, {}, { "LevelM45", { 0.17, 0.036 }, 1 }, { "LevelM45", { 0.2, 0.045 }, 1 } };
    //                 };
    //                 class VALM_1_45 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -45;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM45", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM45", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM45", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP45 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP45", { -0.2, 0.03 }, 1 }, { "LevelP45", { -0.2, 0 }, 1 }, { "LevelP45", { -0.05, 0 }, 1 }, {}, { "LevelP45", { 0.05, 0 }, 1 }, { "LevelP45", { 0.2, 0 }, 1 }, { "LevelP45", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_45 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "45";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP45", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP45", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP45", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM50 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM50", { -0.2, 0.05 }, 1 }, { "LevelM50", { -0.17, 0.04 }, 1 }, {}, { "LevelM50", { -0.14, 0.03 }, 1 }, { "LevelM50", { -0.11, 0.02 }, 1 }, {}, { "LevelM50", { -0.08, 0.01 }, 1 }, { "LevelM50", { -0.05, 0 }, 1 }, { "LevelM50", { -0.05, -0.03 }, 1 }, {}, { "LevelM50", { 0.05, -0.03 }, 1 }, { "LevelM50", { 0.05, 0 }, 1 }, { "LevelM50", { 0.08, 0.01 }, 1 }, {}, { "LevelM50", { 0.11, 0.02 }, 1 }, { "LevelM50", { 0.14, 0.03 }, 1 }, {}, { "LevelM50", { 0.17, 0.04 }, 1 }, { "LevelM50", { 0.2, 0.05 }, 1 } };
    //                 };
    //                 class VALM_1_50 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -50;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM50", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM50", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM50", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP50 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP50", { -0.2, 0.03 }, 1 }, { "LevelP50", { -0.2, 0 }, 1 }, { "LevelP50", { -0.05, 0 }, 1 }, {}, { "LevelP50", { 0.05, 0 }, 1 }, { "LevelP50", { 0.2, 0 }, 1 }, { "LevelP50", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_50 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "50";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP50", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP50", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP50", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM55 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM55", { -0.2, 0.055 }, 1 }, { "LevelM55", { -0.17, 0.044 }, 1 }, {}, { "LevelM55", { -0.14, 0.033 }, 1 }, { "LevelM55", { -0.11, 0.022 }, 1 }, {}, { "LevelM55", { -0.08, 0.011 }, 1 }, { "LevelM55", { -0.05, 0 }, 1 }, { "LevelM55", { -0.05, -0.03 }, 1 }, {}, { "LevelM55", { 0.05, -0.03 }, 1 }, { "LevelM55", { 0.05, 0 }, 1 }, { "LevelM55", { 0.08, 0.011 }, 1 }, {}, { "LevelM55", { 0.11, 0.022 }, 1 }, { "LevelM55", { 0.14, 0.033 }, 1 }, {}, { "LevelM55", { 0.17, 0.044 }, 1 }, { "LevelM55", { 0.2, 0.055 }, 1 } };
    //                 };
    //                 class VALM_1_55 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -55;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM55", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM55", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM55", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP55 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP55", { -0.2, 0.03 }, 1 }, { "LevelP55", { -0.2, 0 }, 1 }, { "LevelP55", { -0.05, 0 }, 1 }, {}, { "LevelP55", { 0.05, 0 }, 1 }, { "LevelP55", { 0.2, 0 }, 1 }, { "LevelP55", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_55 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "55";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP55", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP55", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP55", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM60 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM60", { -0.2, 0.06 }, 1 }, { "LevelM60", { -0.17, 0.048 }, 1 }, {}, { "LevelM60", { -0.14, 0.036 }, 1 }, { "LevelM60", { -0.11, 0.024 }, 1 }, {}, { "LevelM60", { -0.08, 0.012 }, 1 }, { "LevelM60", { -0.05, 0 }, 1 }, { "LevelM60", { -0.05, -0.03 }, 1 }, {}, { "LevelM60", { 0.05, -0.03 }, 1 }, { "LevelM60", { 0.05, 0 }, 1 }, { "LevelM60", { 0.08, 0.012 }, 1 }, {}, { "LevelM60", { 0.11, 0.024 }, 1 }, { "LevelM60", { 0.14, 0.036 }, 1 }, {}, { "LevelM60", { 0.17, 0.048 }, 1 }, { "LevelM60", { 0.2, 0.06 }, 1 } };
    //                 };
    //                 class VALM_1_60 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -60;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM60", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM60", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM60", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP60 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP60", { -0.2, 0.03 }, 1 }, { "LevelP60", { -0.2, 0 }, 1 }, { "LevelP60", { -0.05, 0 }, 1 }, {}, { "LevelP60", { 0.05, 0 }, 1 }, { "LevelP60", { 0.2, 0 }, 1 }, { "LevelP60", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_60 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "60";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP60", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP60", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP60", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM65 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM65", { -0.2, 0.065 }, 1 }, { "LevelM65", { -0.17, 0.052 }, 1 }, {}, { "LevelM65", { -0.14, 0.039 }, 1 }, { "LevelM65", { -0.11, 0.026 }, 1 }, {}, { "LevelM65", { -0.08, 0.013 }, 1 }, { "LevelM65", { -0.05, 0 }, 1 }, { "LevelM65", { -0.05, -0.03 }, 1 }, {}, { "LevelM65", { 0.05, -0.03 }, 1 }, { "LevelM65", { 0.05, 0 }, 1 }, { "LevelM65", { 0.08, 0.013 }, 1 }, {}, { "LevelM65", { 0.11, 0.026 }, 1 }, { "LevelM65", { 0.14, 0.039 }, 1 }, {}, { "LevelM65", { 0.17, 0.052 }, 1 }, { "LevelM65", { 0.2, 0.065 }, 1 } };
    //                 };
    //                 class VALM_1_65 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -65;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM65", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM65", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM65", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP65 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP65", { -0.2, 0.03 }, 1 }, { "LevelP65", { -0.2, 0 }, 1 }, { "LevelP65", { -0.05, 0 }, 1 }, {}, { "LevelP65", { 0.05, 0 }, 1 }, { "LevelP65", { 0.2, 0 }, 1 }, { "LevelP65", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_65 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "65";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP65", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP65", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP65", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM70 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM70", { -0.2, 0.07 }, 1 }, { "LevelM70", { -0.17, 0.056 }, 1 }, {}, { "LevelM70", { -0.14, 0.042 }, 1 }, { "LevelM70", { -0.11, 0.028 }, 1 }, {}, { "LevelM70", { -0.08, 0.014 }, 1 }, { "LevelM70", { -0.05, 0 }, 1 }, { "LevelM70", { -0.05, -0.03 }, 1 }, {}, { "LevelM70", { 0.05, -0.03 }, 1 }, { "LevelM70", { 0.05, 0 }, 1 }, { "LevelM70", { 0.08, 0.014 }, 1 }, {}, { "LevelM70", { 0.11, 0.028 }, 1 }, { "LevelM70", { 0.14, 0.042 }, 1 }, {}, { "LevelM70", { 0.17, 0.056 }, 1 }, { "LevelM70", { 0.2, 0.07 }, 1 } };
    //                 };
    //                 class VALM_1_70 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -70;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM70", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM70", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM70", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP70 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP70", { -0.2, 0.03 }, 1 }, { "LevelP70", { -0.2, 0 }, 1 }, { "LevelP70", { -0.05, 0 }, 1 }, {}, { "LevelP70", { 0.05, 0 }, 1 }, { "LevelP70", { 0.2, 0 }, 1 }, { "LevelP70", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_70 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "70";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP70", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP70", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP70", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM75 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM75", { -0.2, 0.075 }, 1 }, { "LevelM75", { -0.17, 0.06 }, 1 }, {}, { "LevelM75", { -0.14, 0.045 }, 1 }, { "LevelM75", { -0.11, 0.03 }, 1 }, {}, { "LevelM75", { -0.08, 0.015 }, 1 }, { "LevelM75", { -0.05, 0 }, 1 }, { "LevelM75", { -0.05, -0.03 }, 1 }, {}, { "LevelM75", { 0.05, -0.03 }, 1 }, { "LevelM75", { 0.05, 0 }, 1 }, { "LevelM75", { 0.08, 0.015 }, 1 }, {}, { "LevelM75", { 0.11, 0.03 }, 1 }, { "LevelM75", { 0.14, 0.045 }, 1 }, {}, { "LevelM75", { 0.17, 0.06 }, 1 }, { "LevelM75", { 0.2, 0.075 }, 1 } };
    //                 };
    //                 class VALM_1_75 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -75;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM75", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM75", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM75", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP75 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP75", { -0.2, 0.03 }, 1 }, { "LevelP75", { -0.2, 0 }, 1 }, { "LevelP75", { -0.05, 0 }, 1 }, {}, { "LevelP75", { 0.05, 0 }, 1 }, { "LevelP75", { 0.2, 0 }, 1 }, { "LevelP75", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_75 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "75";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP75", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP75", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP75", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM80 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM80", { -0.2, 0.08 }, 1 }, { "LevelM80", { -0.17, 0.064 }, 1 }, {}, { "LevelM80", { -0.14, 0.048 }, 1 }, { "LevelM80", { -0.11, 0.032 }, 1 }, {}, { "LevelM80", { -0.08, 0.016 }, 1 }, { "LevelM80", { -0.05, 0 }, 1 }, { "LevelM80", { -0.05, -0.03 }, 1 }, {}, { "LevelM80", { 0.05, -0.03 }, 1 }, { "LevelM80", { 0.05, 0 }, 1 }, { "LevelM80", { 0.08, 0.016 }, 1 }, {}, { "LevelM80", { 0.11, 0.032 }, 1 }, { "LevelM80", { 0.14, 0.048 }, 1 }, {}, { "LevelM80", { 0.17, 0.064 }, 1 }, { "LevelM80", { 0.2, 0.08 }, 1 } };
    //                 };
    //                 class VALM_1_80 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -80;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM80", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM80", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM80", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP80 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP80", { -0.2, 0.03 }, 1 }, { "LevelP80", { -0.2, 0 }, 1 }, { "LevelP80", { -0.05, 0 }, 1 }, {}, { "LevelP80", { 0.05, 0 }, 1 }, { "LevelP80", { 0.2, 0 }, 1 }, { "LevelP80", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_80 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "80";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP80", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP80", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP80", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM85 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM85", { -0.2, 0.085 }, 1 }, { "LevelM85", { -0.17, 0.068 }, 1 }, {}, { "LevelM85", { -0.14, 0.051 }, 1 }, { "LevelM85", { -0.11, 0.034 }, 1 }, {}, { "LevelM85", { -0.08, 0.017 }, 1 }, { "LevelM85", { -0.05, 0 }, 1 }, { "LevelM85", { -0.05, -0.03 }, 1 }, {}, { "LevelM85", { 0.05, -0.03 }, 1 }, { "LevelM85", { 0.05, 0 }, 1 }, { "LevelM85", { 0.08, 0.017 }, 1 }, {}, { "LevelM85", { 0.11, 0.034 }, 1 }, { "LevelM85", { 0.14, 0.051 }, 1 }, {}, { "LevelM85", { 0.17, 0.068 }, 1 }, { "LevelM85", { 0.2, 0.085 }, 1 } };
    //                 };
    //                 class VALM_1_85 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -85;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM85", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM85", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM85", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP85 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP85", { -0.2, 0.03 }, 1 }, { "LevelP85", { -0.2, 0 }, 1 }, { "LevelP85", { -0.05, 0 }, 1 }, {}, { "LevelP85", { 0.05, 0 }, 1 }, { "LevelP85", { 0.2, 0 }, 1 }, { "LevelP85", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_85 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "85";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP85", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP85", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP85", { -0.18, 0.082 }, 1 };
    //                 };
    //                 class LevelM90 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelM90", { -0.2, 0.09 }, 1 }, { "LevelM90", { -0.17, 0.072 }, 1 }, {}, { "LevelM90", { -0.14, 0.054 }, 1 }, { "LevelM90", { -0.11, 0.036 }, 1 }, {}, { "LevelM90", { -0.08, 0.018 }, 1 }, { "LevelM90", { -0.05, 0 }, 1 }, { "LevelM90", { -0.05, -0.03 }, 1 }, {}, { "LevelM90", { 0.05, -0.03 }, 1 }, { "LevelM90", { 0.05, 0 }, 1 }, { "LevelM90", { 0.08, 0.018 }, 1 }, {}, { "LevelM90", { 0.11, 0.036 }, 1 }, { "LevelM90", { 0.14, 0.054 }, 1 }, {}, { "LevelM90", { 0.17, 0.072 }, 1 }, { "LevelM90", { 0.2, 0.09 }, 1 } };
    //                 };
    //                 class VALM_1_90 {
    //                     type = "text";
    //                     source = "static";
    //                     text = -90;
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelM90", { -0.18, -0.082 }, 1 };
    //                     right[] = { "LevelM90", { -0.1, -0.082 }, 1 };
    //                     down[] = { "LevelM90", { -0.18, -0.032 }, 1 };
    //                 };
    //                 class LevelP90 : Level0 {
    //                     type = "line";
    //                     points[] = { { "LevelP90", { -0.2, 0.03 }, 1 }, { "LevelP90", { -0.2, 0 }, 1 }, { "LevelP90", { -0.05, 0 }, 1 }, {}, { "LevelP90", { 0.05, 0 }, 1 }, { "LevelP90", { 0.2, 0 }, 1 }, { "LevelP90", { 0.2, 0.03 }, 1 } };
    //                 };
    //                 class VALP_1_90 {
    //                     type = "text";
    //                     source = "static";
    //                     text = "90";
    //                     align = "right";
    //                     scale = 1;
    //                     sourceScale = 1;
    //                     pos[] = { "LevelP90", { -0.18, 0.032 }, 1 };
    //                     right[] = { "LevelP90", { -0.1, 0.032 }, 1 };
    //                     down[] = { "LevelP90", { -0.18, 0.082 }, 1 };
    //                 };
    //             };
    //         };
    //         class SpeedNumber {
    //             type = "text";
    //             source = "speed";
    //             sourceScale = 1.94384;
    //             align = "center";
    //             scale = 1;
    //             pos[] = { { 0.1, 0.311856 }, 1 };
    //             right[] = { { 0.16, 0.311856 }, 1 };
    //             down[] = { { 0.1, 0.368557 }, 1 };
    //         };
    //         class AltNumber : SpeedNumber {
    //             source = "altitudeASL";
    //             sourceScale = 3.28084;
    //             pos[] = { { 0.9, 0.311856 }, 1 };
    //             right[] = { { 0.96, 0.311856 }, 1 };
    //             down[] = { { 0.9, 0.368557 }, 1 };
    //         };
    //         class AltNumberAGL {
    //             class Text {
    //                 type = "text";
    //                 source = "static";
    //                 text = "H";
    //                 align = "left";
    //                 scale = 1;
    //                 pos[] = { { 0.8, 0.53866 }, 1 };
    //                 right[] = { { 0.86, 0.53866 }, 1 };
    //                 down[] = { { 0.8, 0.595361 }, 1 };
    //             };
    //             class Box {
    //                 type = "line";
    //                 points[] = { { { 0.81, 0.595361 }, 1 }, { { 1, 0.595361 }, 1 }, { { 1, 0.53866 }, 1 }, { { 0.81, 0.53866 }, 1 }, { { 0.81, 0.595361 }, 1 } };
    //             };
    //             class AltNumber {
    //                 type = "text";
    //                 source = "altitudeAGL";
    //                 sourceScale = 3.28084;
    //                 align = "left";
    //                 scale = 1;
    //                 pos[] = { { 0.99, 0.53866 }, 1 };
    //                 right[] = { { 1.05, 0.53866 }, 1 };
    //                 down[] = { { 0.99, 0.595361 }, 1 };
    //             };
    //         };
    //         class Gear {
    //             condition = "ils";
    //             class Highlighted {
    //                 class Text {
    //                     type = "text";
    //                     source = "static";
    //                     text = "GEAR";
    //                     align = "left";
    //                     scale = 1;
    //                     pos[] = { { 0.99, 0.822165 }, 1 };
    //                     right[] = { { 1.05, 0.822165 }, 1 };
    //                     down[] = { { 0.99, 0.878866 }, 1 };
    //                 };
    //             };
    //         };
    //         class Flaps {
    //             condition = "flaps";
    //             class Highlighted {
    //                 class Text {
    //                     type = "text";
    //                     source = "static";
    //                     text = "FLAPS";
    //                     align = "left";
    //                     scale = 1;
    //                     pos[] = { { 0.99, 0.878866 }, 1 };
    //                     right[] = { { 1.05, 0.878866 }, 1 };
    //                     down[] = { { 0.99, 0.935567 }, 1 };
    //                 };
    //             };
    //         };
    //         class Lights {
    //             condition = "lights";
    //             class Highlighted {
    //                 class Text {
    //                     type = "text";
    //                     source = "static";
    //                     text = "LIGHTS";
    //                     align = "right";
    //                     scale = 1;
    //                     pos[] = { { 0.01, 0.822165 }, 1 };
    //                     right[] = { { 0.07, 0.822165 }, 1 };
    //                     down[] = { { 0.01, 0.878866 }, 1 };
    //                 };
    //             };
    //         };
    //         class CollisionLights {
    //             condition = "collisionlights";
    //             class Highlighted {
    //                 class Text {
    //                     type = "text";
    //                     source = "static";
    //                     text = "ANTI-COL";
    //                     align = "right";
    //                     scale = 1;
    //                     pos[] = { { 0.01, 0.878866 }, 1 };
    //                     right[] = { { 0.07, 0.878866 }, 1 };
    //                     down[] = { { 0.01, 0.935567 }, 1 };
    //                 };
    //             };
    //         };
    //         class Stall {
    //             condition = "stall";
    //             color[] = { 1.0, 0.0, 0.0 };
    //             blinkingPattern[] = { 0.2, 0.2 };
    //             blinkingStartsOn = 1;
    //             class Text {
    //                 type = "text";
    //                 source = "static";
    //                 text = "STALL";
    //                 align = "center";
    //                 scale = 1;
    //                 pos[] = { { 0.5, 0.204124 }, 1 };
    //                 right[] = { { 0.56, 0.204124 }, 1 };
    //                 down[] = { { 0.5, 0.260825 }, 1 };
    //             };
    //         };
    //         class HeadingScale {
    //             type = "scale";
    //             horizontal = 1;
    //             source = "Heading";
    //             sourceScale = 0.1;
    //             top = 0.2;
    //             center = 0.5;
    //             bottom = 0.8;
    //             lineXleft = 0.102062;
    //             lineYright = 0.0907216;
    //             lineXleftMajor = 0.102062;
    //             lineYrightMajor = 0.0793814;
    //             majorLineEach = 5;
    //             numberEach = 5;
    //             step = 0.2;
    //             StepSize = 0.03;
    //             align = "center";
    //             scale = 1;
    //             pos[] = { 0.2, 0.0198454 };
    //             right[] = { 0.26, 0.0198454 };
    //             down[] = { 0.2, 0.0765464 };
    //         };
    //     };
    // };
    class AirplaneHUD {
        enableParallax = 0;
        helmetMountedDisplay = 1;
        helmetPosition[] = { -0.04, 0.04, 0.1 };
        helmetRight[] = { 0.08, 0, 0 };
        helmetDown[] = { 0, -0.08, 0 };
        class Pos10Vector {
            type = "vector";
            pos0[] = { 0.5, 0.5 };
            pos10[] = { 1.225, 1.1 };
        };
        topLeft = "HUD_top_left";
        topRight = "HUD_top_right";
        bottomLeft = "HUD_bottom_left";
        borderLeft = 0;
        borderRight = 0;
        borderTop = 0;
        borderBottom = 0;
        color[] = { 0.082, 0.408, 0.039, 1 };
        class Bones {
            class PlaneW {
                type = "fixed";
                pos[] = { 0.5, 0.5 };
                pos10[] = { 0.774, 0.77 };
            };
            class Velocity : Pos10Vector {
                type = "vector";
                source = "velocityToView";
                pos0[] = { 0.5, 0.5 };
                pos10[] = { 0.774, 0.77 };
            };
            class PlaneOrientation {
                type = "vector";
                source = "forward";
                pos[] = { 0.5, 0.5 };
                pos0[] = { 0.5, 0.5 };
                pos10[] = { 0.774, 0.77 };
            };
            class Limit0109 {
                type = "limit";
                limits[] = { 0.1, 0.1, 0.9, 0.9 };
            };
            class LimitWaypoint {
                type = "limit";
                limits[] = { 0.2, 0.1, 0.8, 0.1 };
            };
            class WPPoint {
                type = "vector";
                source = "WPPoint";
                pos0[] = { 0.5, 0.5 };
                pos10[] = { 0.774, 0.77 };
            };
            class WPPointToView : WPPoint {
                source = "WPPointToView";
            };
            class Airport1 {
                type = "vector";
                source = "airportCorner1ToView";
                pos0[] = { 0.5, 0.5 };
                pos10[] = { 0.774, 0.77 };
            };
            class Airport2 : Airport1 {
                source = "airportCorner2ToView";
            };
            class Airport3 : Airport1 {
                source = "airportCorner3ToView";
            };
            class Airport4 : Airport1 {
                source = "airportCorner4ToView";
            };
            class ILS_H {
                type = "ils";
                pos0[] = { 0.5, 0.5 };
                pos3[] = { 0.5822, 0.5 };
            };
            class ILS_W : ILS_H {
                pos3[] = { 0.5, 0.581 };
            };
            class HorizonBankRot {
                type = "rotational";
                source = "horizonBank";
                center[] = { 0.5, 0.5 };
                min = "-rad(30)";
                max = "rad(30)";
                minAngle = "180.25-30";
                maxAngle = "180.75+30";
                aspectRatio = 1;
            };
            class Level0 : Pos10Vector {
                pos0[] = { 0.5, 0.5 };
                pos10[] = { 0.884, 0.88 };
                type = "horizontoview";
                angle = 0;
            };
            class LevelP5 : Level0 {
                angle = 5;
            };
            class LevelM5 : Level0 {
                angle = -5;
            };
            class LevelP10 : Level0 {
                angle = 10;
            };
            class LevelM10 : Level0 {
                angle = -10;
            };
            class LevelP15 : Level0 {
                angle = 15;
            };
            class LevelM15 : Level0 {
                angle = -15;
            };
            class LevelP20 : Level0 {
                angle = 20;
            };
            class LevelM20 : Level0 {
                angle = -20;
            };
            class LevelP25 : Level0 {
                angle = 25;
            };
            class LevelM25 : Level0 {
                angle = -25;
            };
            class LevelP30 : Level0 {
                angle = 30;
            };
            class LevelM30 : Level0 {
                angle = -30;
            };
            class LevelP35 : Level0 {
                angle = 35;
            };
            class LevelM35 : Level0 {
                angle = -35;
            };
            class LevelP40 : Level0 {
                angle = 40;
            };
            class LevelM40 : Level0 {
                angle = -40;
            };
            class LevelP45 : Level0 {
                angle = 45;
            };
            class LevelM45 : Level0 {
                angle = -45;
            };
            class LevelP50 : Level0 {
                angle = 50;
            };
            class LevelM50 : Level0 {
                angle = -50;
            };
            class LevelP60 : Level0 {
                angle = 60;
            };
            class LevelM60 : Level0 {
                angle = -60;
            };
            class LevelP70 : Level0 {
                angle = 70;
            };
            class LevelM70 : Level0 {
                angle = -70;
            };
            class LevelP80 : Level0 {
                angle = 80;
            };
            class LevelM80 : Level0 {
                angle = -80;
            };
            class LevelP90 : Level0 {
                angle = 90;
            };
            class LevelM90 : Level0 {
                angle = -90;
            };
        };
        class Draw {
            width = 1;
            color[] = { 0.18, 1, 0.18 };
            alpha = 1;
            condition = "on";
            class PlaneW {
                clipTL[] = { 0, 1 };
                clipBR[] = { 1, 0 };
                type = "line";
                width = 3;
                points[] = { { "PlaneOrientation", { -0.04, 0 }, 1 }, { "PlaneOrientation", { -0.015, 0 }, 1 }, { "PlaneOrientation", { -0.0075, 0.015 }, 1 }, { "PlaneOrientation", { 0, 0 }, 1 }, { "PlaneOrientation", { 0.0075, 0.015 }, 1 }, { "PlaneOrientation", { 0.015, 0 }, 1 }, { "PlaneOrientation", { 0.04, 0 }, 1 } };
            };
            class PlaneMovementCrosshair {
                type = "line";
                width = 3;
                points[] = { { "Velocity", { 0, -0.02 }, 1 }, { "Velocity", { 0.01, -0.01732 }, 1 }, { "Velocity", { 0.01732, -0.01 }, 1 }, { "Velocity", { 0.02, 0 }, 1 }, { "Velocity", { 0.01732, 0.01 }, 1 }, { "Velocity", { 0.01, 0.01732 }, 1 }, { "Velocity", { 0, 0.02 }, 1 }, { "Velocity", { -0.01, 0.01732 }, 1 }, { "Velocity", { -0.01732, 0.01 }, 1 }, { "Velocity", { -0.02, 0 }, 1 }, { "Velocity", { -0.01732, -0.01 }, 1 }, { "Velocity", { -0.01, -0.01732 }, 1 }, { "Velocity", { 0, -0.02 }, 1 }, {}, { "Velocity", { 0.04, 0 }, 1 }, { "Velocity", { 0.02, 0 }, 1 }, {}, { "Velocity", { -0.04, 0 }, 1 }, { "Velocity", { -0.02, 0 }, 1 }, {}, { "Velocity", { 0, -0.04 }, 1 }, { "Velocity", { 0, -0.02 }, 1 } };
            };
            class Flaps {
                condition = "flaps";
                class FlapsText {
                    type = "text";
                    source = "static";
                    text = "FLAPS";
                    align = "left";
                    scale = 1;
                    pos[] = { { 0.932, 0.92 }, 1 };
                    right[] = { { 0.987, 0.92 }, 1 };
                    down[] = { { 0.932, 0.965 }, 1 };
                };
            };
            class ILS {
                condition = "ils";
                class GearText {
                    type = "text";
                    source = "static";
                    text = "GEAR";
                    align = "left";
                    scale = 1;
                    pos[] = { { 0.932, 0.84 }, 1 };
                    right[] = { { 0.987, 0.84 }, 1 };
                    down[] = { { 0.932, 0.885 }, 1 };
                };
                class Glideslope {
                    clipTL[] = { 0, 0 };
                    clipBR[] = { 1, 1 };
                    class ILS {
                        type = "line";
                        width = 2;
                        points[] = { { "ILS_W", { -0.12, 0 }, 1 }, { "ILS_W", { 0.12, 0 }, 1 }, {}, { "ILS_W", { -0.12, -0.0118248 }, 1 }, { "ILS_W", { -0.12, 0.0118248 }, 1 }, {}, { "ILS_W", { -0.06, -0.00886861 }, 1 }, { "ILS_W", { -0.06, 0.00886861 }, 1 }, {}, { "ILS_W", { 0, -0.0118248 }, 1 }, { "ILS_W", { 0, 0.0118248 }, 1 }, {}, { "ILS_W", { 0.06, -0.00886861 }, 1 }, { "ILS_W", { 0.06, 0.00886861 }, 1 }, {}, { "ILS_W", { 0.12, -0.0118248 }, 1 }, { "ILS_W", { 0.12, 0.0118248 }, 1 }, {}, { "ILS_H", { 0, -0.118248 }, 1 }, { "ILS_H", { 0, 0.118248 }, 1 }, {}, { "ILS_H", { -0.012, -0.118248 }, 1 }, { "ILS_H", { 0.012, -0.118248 }, 1 }, {}, { "ILS_H", { -0.009, -0.0591241 }, 1 }, { "ILS_H", { 0.009, -0.0591241 }, 1 }, {}, { "ILS_H", { -0.012, 0 }, 1 }, { "ILS_H", { 0.012, 0 }, 1 }, {}, { "ILS_H", { -0.009, 0.0591241 }, 1 }, { "ILS_H", { 0.009, 0.0591241 }, 1 }, {}, { "ILS_H", { -0.012, 0.118248 }, 1 }, { "ILS_H", { 0.012, 0.118248 }, 1 } };
                    };
                    class airport {
                        type = "line";
                        points[] = { { "airport1", 1 }, { "airport2", 1 }, { "airport4", 1 }, { "airport3", 1 }, { "airport1", 1 } };
                    };
                };
            };
            class IncomingMissile {
                condition = "incomingmissile";
                blinkingPattern[] = { 0.3, 0.3 };
                blinkingStartsOn = 1;
                class Text {
                    type = "text";
                    source = "static";
                    text = "!INCOMING MISSILE!";
                    align = "center";
                    scale = 1;
                    pos[] = { { 0.485, 0.216788 }, 1 };
                    right[] = { { 0.545, 0.216788 }, 1 };
                    down[] = { { 0.485, 0.266058 }, 1 };
                };
            };
            class StallGroup {
                type = "group";
                condition = "stall";
                color[] = { 1, 0, 0 };
                blinkingPattern[] = { 0.2, 0.2 };
                blinkingStartsOn = 1;
                class StallText {
                    type = "text";
                    source = "static";
                    text = "STALL";
                    align = "center";
                    scale = 1;
                    pos[] = { { 0.5, 0.25 }, 1 };
                    right[] = { { 0.54, 0.25 }, 1 };
                    down[] = { { 0.5, 0.29 }, 1 };
                };
            };
            class MainCenterLine1 {
                type = "line";
                width = 3;
                points[] = { { "PlaneW", { -0.49, "0 + 0.025" }, 1 }, { "PlaneW", { -0.49, 0 }, 1 }, { "PlaneW", { -0.45, 0 }, 1 } };
            };
            class MainCenterLine2 {
                type = "line";
                width = 3;
                points[] = { { "PlaneW", { -0.33, 0 }, 1 }, { "PlaneW", { -0.25, 0 }, 1 } };
            };
            class MainCenterLine3 {
                type = "line";
                width = 3;
                points[] = { { "PlaneW", { 0.49, "0 + 0.025" }, 1 }, { "PlaneW", { 0.49, 0 }, 1 }, { "PlaneW", { 0.25, 0 }, 1 } };
            };
            class SpeedIndicatorBox {
                type = "line";
                width = 3;
                points[] = { { "PlaneW", { -0.49, -0.25 }, 1 }, { "PlaneW", { -0.49, -0.2 }, 1 }, { "PlaneW", { -0.3, -0.2 }, 1 }, { "PlaneW", { -0.3, -0.25 }, 1 }, { "PlaneW", { -0.49, -0.25 }, 1 } };
            };
            class SpeedNumber {
                type = "text";
                source = "speed";
                sourceScale = 3.6;
                align = "center";
                scale = 1;
                pos[] = { "PlaneW", { -0.4, -0.25 }, 1 };
                right[] = { "PlaneW", { -0.3, -0.25 }, 1 };
                down[] = { "PlaneW", { -0.4, -0.2 }, 1 };
            };
            class AltitudeIndicatorBox {
                type = "line";
                width = 3;
                points[] = { { "PlaneW", { 0.49, -0.25 }, 1 }, { "PlaneW", { 0.49, -0.2 }, 1 }, { "PlaneW", { 0.3, -0.2 }, 1 }, { "PlaneW", { 0.3, -0.25 }, 1 }, { "PlaneW", { 0.49, -0.25 }, 1 } };
            };
            class AltitudeNumberASL {
                type = "text";
                source = "altitudeASL";
                sourceScale = 1;
                align = "center";
                scale = 1;
                pos[] = { "PlaneW", { 0.4, -0.25 }, 1 };
                right[] = { "PlaneW", { 0.48, -0.25 }, 1 };
                down[] = { "PlaneW", { 0.4, -0.2 }, 1 };
            };
            class AltitudeRadarText {
                type = "text";
                source = "static";
                text = "R";
                align = "left";
                scale = 1;
                sourceScale = 1;
                pos[] = { "PlaneW", { 0.32, -0.192 }, 1 };
                right[] = { "PlaneW", { "+0.32 + 0.04", -0.192 }, 1 };
                down[] = { "PlaneW", { 0.32, "-0.192 + 0.041" }, 1 };
            };
            class AltitudeNumberAGL {
                type = "text";
                source = "altitudeAGL";
                sourceScale = 1;
                sourceLength = 4;
                sourceOffset = -2;
                align = "left";
                scale = 1;
                pos[] = { "PlaneW", { 0.48, -0.19 }, 1 };
                right[] = { "PlaneW", { 0.54, -0.19 }, 1 };
                down[] = { "PlaneW", { 0.48, -0.15 }, 1 };
            };
            class PitchNumber {
                type = "text";
                source = "horizonDive";
                sourceScale = 57.2958;
                align = "right";
                scale = 1;
                pos[] = { "PlaneW", { -0.39, -0.076 }, 1 };
                right[] = { "PlaneW", { "-0.39 + 0.04", -0.076 }, 1 };
                down[] = { "PlaneW", { -0.39, "-0.076 + 0.05" }, 1 };
            };
            class PitchText {
                type = "text";
                source = "static";
                text = "P:";
                align = "left";
                scale = 1;
                pos[] = { "PlaneW", { -0.41, -0.076 }, 1 };
                right[] = { "PlaneW", { "-0.41 + 0.04", -0.076 }, 1 };
                down[] = { "PlaneW", { -0.41, "-0.076 + 0.05" }, 1 };
            };
            class RollNumber {
                type = "text";
                source = "horizonBank";
                sourceScale = 57.2958;
                align = "right";
                scale = 1;
                pos[] = { "PlaneW", { -0.39, -0.025 }, 1 };
                right[] = { "PlaneW", { "-0.39 + 0.04", -0.025 }, 1 };
                down[] = { "PlaneW", { -0.39, "-0.025 + 0.05" }, 1 };
            };
            class RollText {
                type = "text";
                source = "static";
                text = "R:";
                align = "left";
                scale = 1;
                pos[] = { "PlaneW", { -0.41, -0.025 }, 1 };
                right[] = { "PlaneW", { "-0.41 + 0.04", -0.025 }, 1 };
                down[] = { "PlaneW", { -0.41, "-0.025 + 0.05" }, 1 };
            };
            class ClimbNumber {
                type = "text";
                source = "vspeed";
                sourceScale = 1;
                align = "right";
                scale = 1;
                pos[] = { "PlaneW", { -0.39, 0.026 }, 1 };
                right[] = { "PlaneW", { "-0.39 + 0.04", 0.026 }, 1 };
                down[] = { "PlaneW", { -0.39, "+0.026 + 0.05" }, 1 };
            };
            class ClimbText {
                type = "text";
                source = "static";
                text = "C:";
                align = "left";
                scale = 1;
                pos[] = { "PlaneW", { -0.41, 0.026 }, 1 };
                right[] = { "PlaneW", { "-0.41 + 0.04", 0.026 }, 1 };
                down[] = { "PlaneW", { -0.41, "+0.026 + 0.05" }, 1 };
            };
            class HeadingArrow {
                type = "line";
                width = 3;
                points[] = { { "WPPoint", 1, "LimitWaypoint", 1, { -0.02, 0.042 }, 1 }, { "WPPoint", 1, "LimitWaypoint", 1, { 0, 0.022 }, 1 }, { "WPPoint", 1, "LimitWaypoint", 1, { 0.02, 0.042 }, 1 } };
            };
            class WP {
                condition = "wpvalid";
                class WPdist {
                    type = "text";
                    source = "wpdist";
                    sourceScale = 0.001;
                    sourcePrecision = 1;
                    align = "right";
                    scale = 1;
                    pos[] = { { 0.924, 0.505018 }, 1 };
                    down[] = { { 0.924, 0.542464 }, 1 };
                    right[] = { { 0.964, 0.505018 }, 1 };
                };
                class WPIndex {
                    type = "text";
                    source = "wpIndex";
                    sourceScale = 1;
                    sourceLength = 2;
                    align = "right";
                    scale = 1;
                    pos[] = { { 0.877, 0.505018 }, 1 };
                    right[] = { { 0.917, 0.505018 }, 1 };
                    down[] = { { 0.877, 0.542464 }, 1 };
                };
                class WPstatic {
                    type = "text";
                    source = "static";
                    text = "WP";
                    scale = 1;
                    sourceScale = 1;
                    align = "right";
                    pos[] = { { "0.825+0.01", 0.5065 }, 1 };
                    right[] = { { 0.875, 0.5065 }, 1 };
                    down[] = { { "0.825+0.01", 0.5415 }, 1 };
                };
                class WPKM {
                    type = "text";
                    source = "static";
                    text = ":";
                    scale = 1;
                    sourceScale = 1;
                    align = "left";
                    pos[] = { { "0.825+0.09", 0.5065 }, 1 };
                    right[] = { { 0.955, 0.5065 }, 1 };
                    down[] = { { "0.825+0.09", 0.5415 }, 1 };
                };
            };
            class HeadingRotation {
                class HeadingHeadNumber {
                    type = "text";
                    source = "cameraDir";
                    sourceScale = 1;
                    align = "center";
                    scale = 1;
                    pos[] = { { "0.80-0.302", "0.082+0.065" }, 1 };
                    right[] = { { "0.83-0.302", "0.082+0.065" }, 1 };
                    down[] = { { "0.80-0.302", "0.113+0.065" }, 1 };
                };
                class HeadingArrow {
                    type = "line";
                    width = 3;
                    points[] = { { { 0.488, 0.141 }, 1 }, { { 0.512, 0.141 }, 1 }, { { 0.542, 0.161 }, 1 }, { { 0.512, 0.181 }, 1 }, { { 0.488, 0.181 }, 1 }, { { 0.458, 0.161 }, 1 }, { { 0.488, 0.141 }, 1 }, {} };
                };
            };
            class HeadingScale {
                type = "scale";
                NeverEatSeaWeed = 1;
                horizontal = 1;
                source = "heading";
                sourceScale = 1;
                width = 3;
                top = 0.1;
                center = 0.5;
                bottom = 0.9;
                lineXleft = 0.105;
                lineYright = 0.115;
                lineXleftMajor = 0.095;
                lineYrightMajor = 0.115;
                majorLineEach = 5;
                numberEach = 5;
                step = "18 / 9";
                stepSize = "(0.70 - 0.3) / 15";
                align = "center";
                scale = 1;
                pos[] = { 0.096, 0.0546 };
                right[] = { 0.143, 0.0546 };
                down[] = { 0.096, 0.093 };
            };
            class HeadingIndicatorBox {
                type = "line";
                width = 3;
                points[] = { { "PlaneW", { -0.035, -0.455 }, 1 }, { "PlaneW", { -0.035, -0.5 }, 1 }, { "PlaneW", { 0.035, -0.5 }, 1 }, { "PlaneW", { 0.035, -0.455 }, 1 }, { "PlaneW", { -0.035, -0.455 }, 1 } };
            };
            class HeadingIndicatorArrow {
                type = "polygon";
                points[] = { { { "PlaneW", { -0.015, -0.455 }, 1 }, { "PlaneW", { 0, -0.445 }, 1 }, { "PlaneW", { 0.015, -0.455 }, 1 } } };
            };
            class HeadingNumber {
                type = "text";
                source = "heading";
                sourceScale = 1;
                align = "center";
                scale = 1;
                pos[] = { "PlaneW", { 0, "(-0.5			)" }, 1 };
                right[] = { "PlaneW", { 0.03, "(-0.5			)" }, 1 };
                down[] = { "PlaneW", { 0, "(-0.5 + 0.045	)" }, 1 };
            };
            class HorizonBankRot {
                type = "line";
                width = 2;
                points[] = { { "HorizonBankRot", { 0, "0.39421001-0.109" }, 1 }, { "HorizonBankRot", { 0.01, "0.41673699-0.109" }, 1 }, { "HorizonBankRot", { -0.01, "0.41673699-0.109" }, 1 }, { "HorizonBankRot", { 0, "0.39421001-0.109" }, 1 } };
            };
            class HorizonBankRotLines {
                type = "line";
                width = 3;
                points[] = { { { 0.619959, 0.712986 }, 1 }, { { 0.631439, 0.744203 }, 1 }, {}, { { 0.58291, 0.739019 }, 1 }, { { 0.588087, 0.760778 }, 1 }, {}, { { 0.540574, 0.748504 }, 1 }, { { 0.543184, 0.770838 }, 1 }, {}, { { 0.4975, 0.740421 }, 1 }, { { 0.4975, 0.77421 }, 1 }, {}, { { 0.454426, 0.748504 }, 1 }, { { 0.451816, 0.770838 }, 1 }, {}, { { 0.41209, 0.739019 }, 1 }, { { 0.406913, 0.760778 }, 1 }, {}, { { 0.375041, 0.712986 }, 1 }, { { 0.363561, 0.744203 }, 1 } };
            };
            class Horizont {
                clipTL[] = { 0.2, 0.2 };
                clipBR[] = { 0.8, 0.8 };
                class Dimmed {
                    class Level0 {
                        type = "line";
                        width = 3;
                        points[] = { { "Level0", { 0.75, 0 }, 1 }, { "Level0", { 0.065, 0 }, 1 }, {}, { "Level0", { -0.065, 0 }, 1 }, { "Level0", { -0.75, 0 }, 1 } };
                    };
                };
                class Ladder {
                    class Limiter {
                        class Level0 {
                            type = "line";
                            width = 2;
                            points[] = {};
                        };
                        class LevelM5 : Level0 {
                            type = "line";
                            points[] = { { "LevelM5", { -0.235, -0.02 }, 1 }, { "LevelM5", { -0.235, 0 }, 1 }, {}, { "LevelM5", { -0.22, 0 }, 1 }, { "LevelM5", { -0.205, 0 }, 1 }, {}, { "LevelM5", { -0.19, 0 }, 1 }, { "LevelM5", { -0.175, 0 }, 1 }, {}, { "LevelM5", { -0.16, 0 }, 1 }, { "LevelM5", { -0.145, 0 }, 1 }, {}, { "LevelM5", { -0.13, 0 }, 1 }, { "LevelM5", { -0.115, 0 }, 1 }, {}, { "LevelM5", { -0.1, 0 }, 1 }, { "LevelM5", { -0.085, 0 }, 1 }, {}, { "LevelM5", { -0.07, 0 }, 1 }, { "LevelM5", { -0.055, 0 }, 1 }, {}, {}, { "LevelM5", { 0.235, -0.02 }, 1 }, { "LevelM5", { 0.235, 0 }, 1 }, {}, { "LevelM5", { 0.22, 0 }, 1 }, { "LevelM5", { 0.205, 0 }, 1 }, {}, { "LevelM5", { 0.19, 0 }, 1 }, { "LevelM5", { 0.175, 0 }, 1 }, {}, { "LevelM5", { 0.16, 0 }, 1 }, { "LevelM5", { 0.145, 0 }, 1 }, {}, { "LevelM5", { 0.13, 0 }, 1 }, { "LevelM5", { 0.115, 0 }, 1 }, {}, { "LevelM5", { 0.1, 0 }, 1 }, { "LevelM5", { 0.085, 0 }, 1 }, {}, { "LevelM5", { 0.07, 0 }, 1 }, { "LevelM5", { 0.055, 0 }, 1 }, {} };
                        };
                        class VALM_1_5 {
                            type = "text";
                            source = "static";
                            text = -5;
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelM5", { -0.26, -0.032 }, 1 };
                            right[] = { "LevelM5", { -0.2, -0.032 }, 1 };
                            down[] = { "LevelM5", { -0.26, 0.018 }, 1 };
                        };
                        class VALM_1_5_R {
                            type = "text";
                            source = "static";
                            text = -5;
                            align = "right";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelM5", { 0.26, -0.032 }, 1 };
                            right[] = { "LevelM5", { 0.32, -0.032 }, 1 };
                            down[] = { "LevelM5", { 0.26, 0.018 }, 1 };
                        };
                        class LevelP5 : Level0 {
                            type = "line";
                            points[] = { { "LevelP5", { "-0.22-0.015", 0.02 }, 1 }, { "LevelP5", { "-0.22-0.015", 0 }, 1 }, { "LevelP5", { -0.06, 0 }, 1 }, {}, { "LevelP5", { 0.06, 0 }, 1 }, { "LevelP5", { "+0.22+0.015", 0 }, 1 }, { "LevelP5", { "+0.22+0.015", 0.02 }, 1 } };
                        };
                        class VALP_1_5 {
                            type = "text";
                            source = "static";
                            text = "5";
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelP5", { -0.26, -0.017 }, 1 };
                            right[] = { "LevelP5", { -0.2, -0.017 }, 1 };
                            down[] = { "LevelP5", { -0.26, 0.033 }, 1 };
                        };
                        class VALP_1_5_R {
                            type = "text";
                            source = "static";
                            text = "5";
                            align = "right";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelP5", { 0.26, -0.017 }, 1 };
                            right[] = { "LevelP5", { 0.32, -0.017 }, 1 };
                            down[] = { "LevelP5", { 0.26, 0.033 }, 1 };
                        };
                        class LevelM10 : Level0 {
                            type = "line";
                            points[] = { { "LevelM10", { -0.235, -0.02 }, 1 }, { "LevelM10", { -0.235, 0 }, 1 }, {}, { "LevelM10", { -0.22, 0 }, 1 }, { "LevelM10", { -0.205, 0 }, 1 }, {}, { "LevelM10", { -0.19, 0 }, 1 }, { "LevelM10", { -0.175, 0 }, 1 }, {}, { "LevelM10", { -0.16, 0 }, 1 }, { "LevelM10", { -0.145, 0 }, 1 }, {}, { "LevelM10", { -0.13, 0 }, 1 }, { "LevelM10", { -0.115, 0 }, 1 }, {}, { "LevelM10", { -0.1, 0 }, 1 }, { "LevelM10", { -0.085, 0 }, 1 }, {}, { "LevelM10", { -0.07, 0 }, 1 }, { "LevelM10", { -0.055, 0 }, 1 }, {}, {}, { "LevelM10", { 0.235, -0.02 }, 1 }, { "LevelM10", { 0.235, 0 }, 1 }, {}, { "LevelM10", { 0.22, 0 }, 1 }, { "LevelM10", { 0.205, 0 }, 1 }, {}, { "LevelM10", { 0.19, 0 }, 1 }, { "LevelM10", { 0.175, 0 }, 1 }, {}, { "LevelM10", { 0.16, 0 }, 1 }, { "LevelM10", { 0.145, 0 }, 1 }, {}, { "LevelM10", { 0.13, 0 }, 1 }, { "LevelM10", { 0.115, 0 }, 1 }, {}, { "LevelM10", { 0.1, 0 }, 1 }, { "LevelM10", { 0.085, 0 }, 1 }, {}, { "LevelM10", { 0.07, 0 }, 1 }, { "LevelM10", { 0.055, 0 }, 1 }, {} };
                        };
                        class VALM_1_10 {
                            type = "text";
                            source = "static";
                            text = -10;
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelM10", { -0.26, -0.032 }, 1 };
                            right[] = { "LevelM10", { -0.2, -0.032 }, 1 };
                            down[] = { "LevelM10", { -0.26, 0.018 }, 1 };
                        };
                        class VALM_1_10_R {
                            type = "text";
                            source = "static";
                            text = -10;
                            align = "right";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelM10", { 0.26, -0.032 }, 1 };
                            right[] = { "LevelM10", { 0.32, -0.032 }, 1 };
                            down[] = { "LevelM10", { 0.26, 0.018 }, 1 };
                        };
                        class LevelP10 : Level0 {
                            type = "line";
                            points[] = { { "LevelP10", { "-0.22-0.015", 0.02 }, 1 }, { "LevelP10", { "-0.22-0.015", 0 }, 1 }, { "LevelP10", { -0.06, 0 }, 1 }, {}, { "LevelP10", { 0.06, 0 }, 1 }, { "LevelP10", { "+0.22+0.015", 0 }, 1 }, { "LevelP10", { "+0.22+0.015", 0.02 }, 1 } };
                        };
                        class VALP_1_10 {
                            type = "text";
                            source = "static";
                            text = "10";
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelP10", { -0.26, -0.017 }, 1 };
                            right[] = { "LevelP10", { -0.2, -0.017 }, 1 };
                            down[] = { "LevelP10", { -0.26, 0.033 }, 1 };
                        };
                        class VALP_1_10_R {
                            type = "text";
                            source = "static";
                            text = "10";
                            align = "right";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelP10", { 0.26, -0.017 }, 1 };
                            right[] = { "LevelP10", { 0.32, -0.017 }, 1 };
                            down[] = { "LevelP10", { 0.26, 0.033 }, 1 };
                        };
                        class LevelM15 : Level0 {
                            type = "line";
                            points[] = { { "LevelM15", { -0.235, -0.02 }, 1 }, { "LevelM15", { -0.235, 0 }, 1 }, {}, { "LevelM15", { -0.22, 0 }, 1 }, { "LevelM15", { -0.205, 0 }, 1 }, {}, { "LevelM15", { -0.19, 0 }, 1 }, { "LevelM15", { -0.175, 0 }, 1 }, {}, { "LevelM15", { -0.16, 0 }, 1 }, { "LevelM15", { -0.145, 0 }, 1 }, {}, { "LevelM15", { -0.13, 0 }, 1 }, { "LevelM15", { -0.115, 0 }, 1 }, {}, { "LevelM15", { -0.1, 0 }, 1 }, { "LevelM15", { -0.085, 0 }, 1 }, {}, { "LevelM15", { -0.07, 0 }, 1 }, { "LevelM15", { -0.055, 0 }, 1 }, {}, {}, { "LevelM15", { 0.235, -0.02 }, 1 }, { "LevelM15", { 0.235, 0 }, 1 }, {}, { "LevelM15", { 0.22, 0 }, 1 }, { "LevelM15", { 0.205, 0 }, 1 }, {}, { "LevelM15", { 0.19, 0 }, 1 }, { "LevelM15", { 0.175, 0 }, 1 }, {}, { "LevelM15", { 0.16, 0 }, 1 }, { "LevelM15", { 0.145, 0 }, 1 }, {}, { "LevelM15", { 0.13, 0 }, 1 }, { "LevelM15", { 0.115, 0 }, 1 }, {}, { "LevelM15", { 0.1, 0 }, 1 }, { "LevelM15", { 0.085, 0 }, 1 }, {}, { "LevelM15", { 0.07, 0 }, 1 }, { "LevelM15", { 0.055, 0 }, 1 }, {} };
                        };
                        class VALM_1_15 {
                            type = "text";
                            source = "static";
                            text = -15;
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelM15", { -0.26, -0.032 }, 1 };
                            right[] = { "LevelM15", { -0.2, -0.032 }, 1 };
                            down[] = { "LevelM15", { -0.26, 0.018 }, 1 };
                        };
                        class VALM_1_15_R {
                            type = "text";
                            source = "static";
                            text = -15;
                            align = "right";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelM15", { 0.26, -0.032 }, 1 };
                            right[] = { "LevelM15", { 0.32, -0.032 }, 1 };
                            down[] = { "LevelM15", { 0.26, 0.018 }, 1 };
                        };
                        class LevelP15 : Level0 {
                            type = "line";
                            points[] = { { "LevelP15", { "-0.22-0.015", 0.02 }, 1 }, { "LevelP15", { "-0.22-0.015", 0 }, 1 }, { "LevelP15", { -0.06, 0 }, 1 }, {}, { "LevelP15", { 0.06, 0 }, 1 }, { "LevelP15", { "+0.22+0.015", 0 }, 1 }, { "LevelP15", { "+0.22+0.015", 0.02 }, 1 } };
                        };
                        class VALP_1_15 {
                            type = "text";
                            source = "static";
                            text = "15";
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelP15", { -0.26, -0.017 }, 1 };
                            right[] = { "LevelP15", { -0.2, -0.017 }, 1 };
                            down[] = { "LevelP15", { -0.26, 0.033 }, 1 };
                        };
                        class VALP_1_15_R {
                            type = "text";
                            source = "static";
                            text = "15";
                            align = "right";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelP15", { 0.26, -0.017 }, 1 };
                            right[] = { "LevelP15", { 0.32, -0.017 }, 1 };
                            down[] = { "LevelP15", { 0.26, 0.033 }, 1 };
                        };
                        class LevelM20 : Level0 {
                            type = "line";
                            points[] = { { "LevelM20", { -0.235, -0.02 }, 1 }, { "LevelM20", { -0.235, 0 }, 1 }, {}, { "LevelM20", { -0.22, 0 }, 1 }, { "LevelM20", { -0.205, 0 }, 1 }, {}, { "LevelM20", { -0.19, 0 }, 1 }, { "LevelM20", { -0.175, 0 }, 1 }, {}, { "LevelM20", { -0.16, 0 }, 1 }, { "LevelM20", { -0.145, 0 }, 1 }, {}, { "LevelM20", { -0.13, 0 }, 1 }, { "LevelM20", { -0.115, 0 }, 1 }, {}, { "LevelM20", { -0.1, 0 }, 1 }, { "LevelM20", { -0.085, 0 }, 1 }, {}, { "LevelM20", { -0.07, 0 }, 1 }, { "LevelM20", { -0.055, 0 }, 1 }, {}, {}, { "LevelM20", { 0.235, -0.02 }, 1 }, { "LevelM20", { 0.235, 0 }, 1 }, {}, { "LevelM20", { 0.22, 0 }, 1 }, { "LevelM20", { 0.205, 0 }, 1 }, {}, { "LevelM20", { 0.19, 0 }, 1 }, { "LevelM20", { 0.175, 0 }, 1 }, {}, { "LevelM20", { 0.16, 0 }, 1 }, { "LevelM20", { 0.145, 0 }, 1 }, {}, { "LevelM20", { 0.13, 0 }, 1 }, { "LevelM20", { 0.115, 0 }, 1 }, {}, { "LevelM20", { 0.1, 0 }, 1 }, { "LevelM20", { 0.085, 0 }, 1 }, {}, { "LevelM20", { 0.07, 0 }, 1 }, { "LevelM20", { 0.055, 0 }, 1 }, {} };
                        };
                        class VALM_1_20 {
                            type = "text";
                            source = "static";
                            text = -20;
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelM20", { -0.26, -0.032 }, 1 };
                            right[] = { "LevelM20", { -0.2, -0.032 }, 1 };
                            down[] = { "LevelM20", { -0.26, 0.018 }, 1 };
                        };
                        class VALM_1_20_R {
                            type = "text";
                            source = "static";
                            text = -20;
                            align = "right";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelM20", { 0.26, -0.032 }, 1 };
                            right[] = { "LevelM20", { 0.32, -0.032 }, 1 };
                            down[] = { "LevelM20", { 0.26, 0.018 }, 1 };
                        };
                        class LevelP20 : Level0 {
                            type = "line";
                            points[] = { { "LevelP20", { "-0.22-0.015", 0.02 }, 1 }, { "LevelP20", { "-0.22-0.015", 0 }, 1 }, { "LevelP20", { -0.06, 0 }, 1 }, {}, { "LevelP20", { 0.06, 0 }, 1 }, { "LevelP20", { "+0.22+0.015", 0 }, 1 }, { "LevelP20", { "+0.22+0.015", 0.02 }, 1 } };
                        };
                        class VALP_1_20 {
                            type = "text";
                            source = "static";
                            text = "20";
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelP20", { -0.26, -0.017 }, 1 };
                            right[] = { "LevelP20", { -0.2, -0.017 }, 1 };
                            down[] = { "LevelP20", { -0.26, 0.033 }, 1 };
                        };
                        class VALP_1_20_R {
                            type = "text";
                            source = "static";
                            text = "20";
                            align = "right";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelP20", { 0.26, -0.017 }, 1 };
                            right[] = { "LevelP20", { 0.32, -0.017 }, 1 };
                            down[] = { "LevelP20", { 0.26, 0.033 }, 1 };
                        };
                        class LevelM25 : Level0 {
                            type = "line";
                            points[] = { { "LevelM25", { -0.235, -0.02 }, 1 }, { "LevelM25", { -0.235, 0 }, 1 }, {}, { "LevelM25", { -0.22, 0 }, 1 }, { "LevelM25", { -0.205, 0 }, 1 }, {}, { "LevelM25", { -0.19, 0 }, 1 }, { "LevelM25", { -0.175, 0 }, 1 }, {}, { "LevelM25", { -0.16, 0 }, 1 }, { "LevelM25", { -0.145, 0 }, 1 }, {}, { "LevelM25", { -0.13, 0 }, 1 }, { "LevelM25", { -0.115, 0 }, 1 }, {}, { "LevelM25", { -0.1, 0 }, 1 }, { "LevelM25", { -0.085, 0 }, 1 }, {}, { "LevelM25", { -0.07, 0 }, 1 }, { "LevelM25", { -0.055, 0 }, 1 }, {}, {}, { "LevelM25", { 0.235, -0.02 }, 1 }, { "LevelM25", { 0.235, 0 }, 1 }, {}, { "LevelM25", { 0.22, 0 }, 1 }, { "LevelM25", { 0.205, 0 }, 1 }, {}, { "LevelM25", { 0.19, 0 }, 1 }, { "LevelM25", { 0.175, 0 }, 1 }, {}, { "LevelM25", { 0.16, 0 }, 1 }, { "LevelM25", { 0.145, 0 }, 1 }, {}, { "LevelM25", { 0.13, 0 }, 1 }, { "LevelM25", { 0.115, 0 }, 1 }, {}, { "LevelM25", { 0.1, 0 }, 1 }, { "LevelM25", { 0.085, 0 }, 1 }, {}, { "LevelM25", { 0.07, 0 }, 1 }, { "LevelM25", { 0.055, 0 }, 1 }, {} };
                        };
                        class VALM_1_25 {
                            type = "text";
                            source = "static";
                            text = -25;
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelM25", { -0.26, -0.032 }, 1 };
                            right[] = { "LevelM25", { -0.2, -0.032 }, 1 };
                            down[] = { "LevelM25", { -0.26, 0.018 }, 1 };
                        };
                        class VALM_1_25_R {
                            type = "text";
                            source = "static";
                            text = -25;
                            align = "right";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelM25", { 0.26, -0.032 }, 1 };
                            right[] = { "LevelM25", { 0.32, -0.032 }, 1 };
                            down[] = { "LevelM25", { 0.26, 0.018 }, 1 };
                        };
                        class LevelP25 : Level0 {
                            type = "line";
                            points[] = { { "LevelP25", { "-0.22-0.015", 0.02 }, 1 }, { "LevelP25", { "-0.22-0.015", 0 }, 1 }, { "LevelP25", { -0.06, 0 }, 1 }, {}, { "LevelP25", { 0.06, 0 }, 1 }, { "LevelP25", { "+0.22+0.015", 0 }, 1 }, { "LevelP25", { "+0.22+0.015", 0.02 }, 1 } };
                        };
                        class VALP_1_25 {
                            type = "text";
                            source = "static";
                            text = "25";
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelP25", { -0.26, -0.017 }, 1 };
                            right[] = { "LevelP25", { -0.2, -0.017 }, 1 };
                            down[] = { "LevelP25", { -0.26, 0.033 }, 1 };
                        };
                        class VALP_1_25_R {
                            type = "text";
                            source = "static";
                            text = "25";
                            align = "right";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelP25", { 0.26, -0.017 }, 1 };
                            right[] = { "LevelP25", { 0.32, -0.017 }, 1 };
                            down[] = { "LevelP25", { 0.26, 0.033 }, 1 };
                        };
                        class LevelM30 : Level0 {
                            type = "line";
                            points[] = { { "LevelM30", { -0.235, -0.02 }, 1 }, { "LevelM30", { -0.235, 0 }, 1 }, {}, { "LevelM30", { -0.22, 0 }, 1 }, { "LevelM30", { -0.205, 0 }, 1 }, {}, { "LevelM30", { -0.19, 0 }, 1 }, { "LevelM30", { -0.175, 0 }, 1 }, {}, { "LevelM30", { -0.16, 0 }, 1 }, { "LevelM30", { -0.145, 0 }, 1 }, {}, { "LevelM30", { -0.13, 0 }, 1 }, { "LevelM30", { -0.115, 0 }, 1 }, {}, { "LevelM30", { -0.1, 0 }, 1 }, { "LevelM30", { -0.085, 0 }, 1 }, {}, { "LevelM30", { -0.07, 0 }, 1 }, { "LevelM30", { -0.055, 0 }, 1 }, {}, {}, { "LevelM30", { 0.235, -0.02 }, 1 }, { "LevelM30", { 0.235, 0 }, 1 }, {}, { "LevelM30", { 0.22, 0 }, 1 }, { "LevelM30", { 0.205, 0 }, 1 }, {}, { "LevelM30", { 0.19, 0 }, 1 }, { "LevelM30", { 0.175, 0 }, 1 }, {}, { "LevelM30", { 0.16, 0 }, 1 }, { "LevelM30", { 0.145, 0 }, 1 }, {}, { "LevelM30", { 0.13, 0 }, 1 }, { "LevelM30", { 0.115, 0 }, 1 }, {}, { "LevelM30", { 0.1, 0 }, 1 }, { "LevelM30", { 0.085, 0 }, 1 }, {}, { "LevelM30", { 0.07, 0 }, 1 }, { "LevelM30", { 0.055, 0 }, 1 }, {} };
                        };
                        class VALM_1_30 {
                            type = "text";
                            source = "static";
                            text = -30;
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelM30", { -0.26, -0.032 }, 1 };
                            right[] = { "LevelM30", { -0.2, -0.032 }, 1 };
                            down[] = { "LevelM30", { -0.26, 0.018 }, 1 };
                        };
                        class VALM_1_30_R {
                            type = "text";
                            source = "static";
                            text = -30;
                            align = "right";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelM30", { 0.26, -0.032 }, 1 };
                            right[] = { "LevelM30", { 0.32, -0.032 }, 1 };
                            down[] = { "LevelM30", { 0.26, 0.018 }, 1 };
                        };
                        class LevelP30 : Level0 {
                            type = "line";
                            points[] = { { "LevelP30", { "-0.22-0.015", 0.02 }, 1 }, { "LevelP30", { "-0.22-0.015", 0 }, 1 }, { "LevelP30", { -0.06, 0 }, 1 }, {}, { "LevelP30", { 0.06, 0 }, 1 }, { "LevelP30", { "+0.22+0.015", 0 }, 1 }, { "LevelP30", { "+0.22+0.015", 0.02 }, 1 } };
                        };
                        class VALP_1_30 {
                            type = "text";
                            source = "static";
                            text = "30";
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelP30", { -0.26, -0.017 }, 1 };
                            right[] = { "LevelP30", { -0.2, -0.017 }, 1 };
                            down[] = { "LevelP30", { -0.26, 0.033 }, 1 };
                        };
                        class VALP_1_30_R {
                            type = "text";
                            source = "static";
                            text = "30";
                            align = "right";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelP30", { 0.26, -0.017 }, 1 };
                            right[] = { "LevelP30", { 0.32, -0.017 }, 1 };
                            down[] = { "LevelP30", { 0.26, 0.033 }, 1 };
                        };
                        class LevelM35 : Level0 {
                            type = "line";
                            points[] = { { "LevelM35", { -0.235, -0.02 }, 1 }, { "LevelM35", { -0.235, 0 }, 1 }, {}, { "LevelM35", { -0.22, 0 }, 1 }, { "LevelM35", { -0.205, 0 }, 1 }, {}, { "LevelM35", { -0.19, 0 }, 1 }, { "LevelM35", { -0.175, 0 }, 1 }, {}, { "LevelM35", { -0.16, 0 }, 1 }, { "LevelM35", { -0.145, 0 }, 1 }, {}, { "LevelM35", { -0.13, 0 }, 1 }, { "LevelM35", { -0.115, 0 }, 1 }, {}, { "LevelM35", { -0.1, 0 }, 1 }, { "LevelM35", { -0.085, 0 }, 1 }, {}, { "LevelM35", { -0.07, 0 }, 1 }, { "LevelM35", { -0.055, 0 }, 1 }, {}, {}, { "LevelM35", { 0.235, -0.02 }, 1 }, { "LevelM35", { 0.235, 0 }, 1 }, {}, { "LevelM35", { 0.22, 0 }, 1 }, { "LevelM35", { 0.205, 0 }, 1 }, {}, { "LevelM35", { 0.19, 0 }, 1 }, { "LevelM35", { 0.175, 0 }, 1 }, {}, { "LevelM35", { 0.16, 0 }, 1 }, { "LevelM35", { 0.145, 0 }, 1 }, {}, { "LevelM35", { 0.13, 0 }, 1 }, { "LevelM35", { 0.115, 0 }, 1 }, {}, { "LevelM35", { 0.1, 0 }, 1 }, { "LevelM35", { 0.085, 0 }, 1 }, {}, { "LevelM35", { 0.07, 0 }, 1 }, { "LevelM35", { 0.055, 0 }, 1 }, {} };
                        };
                        class VALM_1_35 {
                            type = "text";
                            source = "static";
                            text = -35;
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelM35", { -0.26, -0.032 }, 1 };
                            right[] = { "LevelM35", { -0.2, -0.032 }, 1 };
                            down[] = { "LevelM35", { -0.26, 0.018 }, 1 };
                        };
                        class VALM_1_35_R {
                            type = "text";
                            source = "static";
                            text = -35;
                            align = "right";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelM35", { 0.26, -0.032 }, 1 };
                            right[] = { "LevelM35", { 0.32, -0.032 }, 1 };
                            down[] = { "LevelM35", { 0.26, 0.018 }, 1 };
                        };
                        class LevelP35 : Level0 {
                            type = "line";
                            points[] = { { "LevelP35", { "-0.22-0.015", 0.02 }, 1 }, { "LevelP35", { "-0.22-0.015", 0 }, 1 }, { "LevelP35", { -0.06, 0 }, 1 }, {}, { "LevelP35", { 0.06, 0 }, 1 }, { "LevelP35", { "+0.22+0.015", 0 }, 1 }, { "LevelP35", { "+0.22+0.015", 0.02 }, 1 } };
                        };
                        class VALP_1_35 {
                            type = "text";
                            source = "static";
                            text = "35";
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelP35", { -0.26, -0.017 }, 1 };
                            right[] = { "LevelP35", { -0.2, -0.017 }, 1 };
                            down[] = { "LevelP35", { -0.26, 0.033 }, 1 };
                        };
                        class VALP_1_35_R {
                            type = "text";
                            source = "static";
                            text = "35";
                            align = "right";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelP35", { 0.26, -0.017 }, 1 };
                            right[] = { "LevelP35", { 0.32, -0.017 }, 1 };
                            down[] = { "LevelP35", { 0.26, 0.033 }, 1 };
                        };
                        class LevelM40 : Level0 {
                            type = "line";
                            points[] = { { "LevelM40", { -0.235, -0.02 }, 1 }, { "LevelM40", { -0.235, 0 }, 1 }, {}, { "LevelM40", { -0.22, 0 }, 1 }, { "LevelM40", { -0.205, 0 }, 1 }, {}, { "LevelM40", { -0.19, 0 }, 1 }, { "LevelM40", { -0.175, 0 }, 1 }, {}, { "LevelM40", { -0.16, 0 }, 1 }, { "LevelM40", { -0.145, 0 }, 1 }, {}, { "LevelM40", { -0.13, 0 }, 1 }, { "LevelM40", { -0.115, 0 }, 1 }, {}, { "LevelM40", { -0.1, 0 }, 1 }, { "LevelM40", { -0.085, 0 }, 1 }, {}, { "LevelM40", { -0.07, 0 }, 1 }, { "LevelM40", { -0.055, 0 }, 1 }, {}, {}, { "LevelM40", { 0.235, -0.02 }, 1 }, { "LevelM40", { 0.235, 0 }, 1 }, {}, { "LevelM40", { 0.22, 0 }, 1 }, { "LevelM40", { 0.205, 0 }, 1 }, {}, { "LevelM40", { 0.19, 0 }, 1 }, { "LevelM40", { 0.175, 0 }, 1 }, {}, { "LevelM40", { 0.16, 0 }, 1 }, { "LevelM40", { 0.145, 0 }, 1 }, {}, { "LevelM40", { 0.13, 0 }, 1 }, { "LevelM40", { 0.115, 0 }, 1 }, {}, { "LevelM40", { 0.1, 0 }, 1 }, { "LevelM40", { 0.085, 0 }, 1 }, {}, { "LevelM40", { 0.07, 0 }, 1 }, { "LevelM40", { 0.055, 0 }, 1 }, {} };
                        };
                        class VALM_1_40 {
                            type = "text";
                            source = "static";
                            text = -40;
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelM40", { -0.26, -0.032 }, 1 };
                            right[] = { "LevelM40", { -0.2, -0.032 }, 1 };
                            down[] = { "LevelM40", { -0.26, 0.018 }, 1 };
                        };
                        class VALM_1_40_R {
                            type = "text";
                            source = "static";
                            text = -40;
                            align = "right";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelM40", { 0.26, -0.032 }, 1 };
                            right[] = { "LevelM40", { 0.32, -0.032 }, 1 };
                            down[] = { "LevelM40", { 0.26, 0.018 }, 1 };
                        };
                        class LevelP40 : Level0 {
                            type = "line";
                            points[] = { { "LevelP40", { "-0.22-0.015", 0.02 }, 1 }, { "LevelP40", { "-0.22-0.015", 0 }, 1 }, { "LevelP40", { -0.06, 0 }, 1 }, {}, { "LevelP40", { 0.06, 0 }, 1 }, { "LevelP40", { "+0.22+0.015", 0 }, 1 }, { "LevelP40", { "+0.22+0.015", 0.02 }, 1 } };
                        };
                        class VALP_1_40 {
                            type = "text";
                            source = "static";
                            text = "40";
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelP40", { -0.26, -0.017 }, 1 };
                            right[] = { "LevelP40", { -0.2, -0.017 }, 1 };
                            down[] = { "LevelP40", { -0.26, 0.033 }, 1 };
                        };
                        class VALP_1_40_R {
                            type = "text";
                            source = "static";
                            text = "40";
                            align = "right";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelP40", { 0.26, -0.017 }, 1 };
                            right[] = { "LevelP40", { 0.32, -0.017 }, 1 };
                            down[] = { "LevelP40", { 0.26, 0.033 }, 1 };
                        };
                        class LevelM45 : Level0 {
                            type = "line";
                            points[] = { { "LevelM45", { -0.235, -0.02 }, 1 }, { "LevelM45", { -0.235, 0 }, 1 }, {}, { "LevelM45", { -0.22, 0 }, 1 }, { "LevelM45", { -0.205, 0 }, 1 }, {}, { "LevelM45", { -0.19, 0 }, 1 }, { "LevelM45", { -0.175, 0 }, 1 }, {}, { "LevelM45", { -0.16, 0 }, 1 }, { "LevelM45", { -0.145, 0 }, 1 }, {}, { "LevelM45", { -0.13, 0 }, 1 }, { "LevelM45", { -0.115, 0 }, 1 }, {}, { "LevelM45", { -0.1, 0 }, 1 }, { "LevelM45", { -0.085, 0 }, 1 }, {}, { "LevelM45", { -0.07, 0 }, 1 }, { "LevelM45", { -0.055, 0 }, 1 }, {}, {}, { "LevelM45", { 0.235, -0.02 }, 1 }, { "LevelM45", { 0.235, 0 }, 1 }, {}, { "LevelM45", { 0.22, 0 }, 1 }, { "LevelM45", { 0.205, 0 }, 1 }, {}, { "LevelM45", { 0.19, 0 }, 1 }, { "LevelM45", { 0.175, 0 }, 1 }, {}, { "LevelM45", { 0.16, 0 }, 1 }, { "LevelM45", { 0.145, 0 }, 1 }, {}, { "LevelM45", { 0.13, 0 }, 1 }, { "LevelM45", { 0.115, 0 }, 1 }, {}, { "LevelM45", { 0.1, 0 }, 1 }, { "LevelM45", { 0.085, 0 }, 1 }, {}, { "LevelM45", { 0.07, 0 }, 1 }, { "LevelM45", { 0.055, 0 }, 1 }, {} };
                        };
                        class VALM_1_45 {
                            type = "text";
                            source = "static";
                            text = -45;
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelM45", { -0.26, -0.032 }, 1 };
                            right[] = { "LevelM45", { -0.2, -0.032 }, 1 };
                            down[] = { "LevelM45", { -0.26, 0.018 }, 1 };
                        };
                        class VALM_1_45_R {
                            type = "text";
                            source = "static";
                            text = -45;
                            align = "right";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelM45", { 0.26, -0.032 }, 1 };
                            right[] = { "LevelM45", { 0.32, -0.032 }, 1 };
                            down[] = { "LevelM45", { 0.26, 0.018 }, 1 };
                        };
                        class LevelP45 : Level0 {
                            type = "line";
                            points[] = { { "LevelP45", { "-0.22-0.015", 0.02 }, 1 }, { "LevelP45", { "-0.22-0.015", 0 }, 1 }, { "LevelP45", { -0.06, 0 }, 1 }, {}, { "LevelP45", { 0.06, 0 }, 1 }, { "LevelP45", { "+0.22+0.015", 0 }, 1 }, { "LevelP45", { "+0.22+0.015", 0.02 }, 1 } };
                        };
                        class VALP_1_45 {
                            type = "text";
                            source = "static";
                            text = "45";
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelP45", { -0.26, -0.017 }, 1 };
                            right[] = { "LevelP45", { -0.2, -0.017 }, 1 };
                            down[] = { "LevelP45", { -0.26, 0.033 }, 1 };
                        };
                        class VALP_1_45_R {
                            type = "text";
                            source = "static";
                            text = "45";
                            align = "right";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelP45", { 0.26, -0.017 }, 1 };
                            right[] = { "LevelP45", { 0.32, -0.017 }, 1 };
                            down[] = { "LevelP45", { 0.26, 0.033 }, 1 };
                        };
                        class LevelM50 : Level0 {
                            type = "line";
                            points[] = { { "LevelM50", { -0.235, -0.02 }, 1 }, { "LevelM50", { -0.235, 0 }, 1 }, {}, { "LevelM50", { -0.22, 0 }, 1 }, { "LevelM50", { -0.205, 0 }, 1 }, {}, { "LevelM50", { -0.19, 0 }, 1 }, { "LevelM50", { -0.175, 0 }, 1 }, {}, { "LevelM50", { -0.16, 0 }, 1 }, { "LevelM50", { -0.145, 0 }, 1 }, {}, { "LevelM50", { -0.13, 0 }, 1 }, { "LevelM50", { -0.115, 0 }, 1 }, {}, { "LevelM50", { -0.1, 0 }, 1 }, { "LevelM50", { -0.085, 0 }, 1 }, {}, { "LevelM50", { -0.07, 0 }, 1 }, { "LevelM50", { -0.055, 0 }, 1 }, {}, {}, { "LevelM50", { 0.235, -0.02 }, 1 }, { "LevelM50", { 0.235, 0 }, 1 }, {}, { "LevelM50", { 0.22, 0 }, 1 }, { "LevelM50", { 0.205, 0 }, 1 }, {}, { "LevelM50", { 0.19, 0 }, 1 }, { "LevelM50", { 0.175, 0 }, 1 }, {}, { "LevelM50", { 0.16, 0 }, 1 }, { "LevelM50", { 0.145, 0 }, 1 }, {}, { "LevelM50", { 0.13, 0 }, 1 }, { "LevelM50", { 0.115, 0 }, 1 }, {}, { "LevelM50", { 0.1, 0 }, 1 }, { "LevelM50", { 0.085, 0 }, 1 }, {}, { "LevelM50", { 0.07, 0 }, 1 }, { "LevelM50", { 0.055, 0 }, 1 }, {} };
                        };
                        class VALM_1_50 {
                            type = "text";
                            source = "static";
                            text = -50;
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelM50", { -0.26, -0.032 }, 1 };
                            right[] = { "LevelM50", { -0.2, -0.032 }, 1 };
                            down[] = { "LevelM50", { -0.26, 0.018 }, 1 };
                        };
                        class VALM_1_50_R {
                            type = "text";
                            source = "static";
                            text = -50;
                            align = "right";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelM50", { 0.26, -0.032 }, 1 };
                            right[] = { "LevelM50", { 0.32, -0.032 }, 1 };
                            down[] = { "LevelM50", { 0.26, 0.018 }, 1 };
                        };
                        class LevelP50 : Level0 {
                            type = "line";
                            points[] = { { "LevelP50", { "-0.22-0.015", 0.02 }, 1 }, { "LevelP50", { "-0.22-0.015", 0 }, 1 }, { "LevelP50", { -0.06, 0 }, 1 }, {}, { "LevelP50", { 0.06, 0 }, 1 }, { "LevelP50", { "+0.22+0.015", 0 }, 1 }, { "LevelP50", { "+0.22+0.015", 0.02 }, 1 } };
                        };
                        class VALP_1_50 {
                            type = "text";
                            source = "static";
                            text = "50";
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelP50", { -0.26, -0.017 }, 1 };
                            right[] = { "LevelP50", { -0.2, -0.017 }, 1 };
                            down[] = { "LevelP50", { -0.26, 0.033 }, 1 };
                        };
                        class VALP_1_50_R {
                            type = "text";
                            source = "static";
                            text = "50";
                            align = "right";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelP50", { 0.26, -0.017 }, 1 };
                            right[] = { "LevelP50", { 0.32, -0.017 }, 1 };
                            down[] = { "LevelP50", { 0.26, 0.033 }, 1 };
                        };
                        class LevelM60 : Level0 {
                            type = "line";
                            points[] = { { "LevelM60", { -0.235, -0.02 }, 1 }, { "LevelM60", { -0.235, 0 }, 1 }, {}, { "LevelM60", { -0.22, 0 }, 1 }, { "LevelM60", { -0.205, 0 }, 1 }, {}, { "LevelM60", { -0.19, 0 }, 1 }, { "LevelM60", { -0.175, 0 }, 1 }, {}, { "LevelM60", { -0.16, 0 }, 1 }, { "LevelM60", { -0.145, 0 }, 1 }, {}, { "LevelM60", { -0.13, 0 }, 1 }, { "LevelM60", { -0.115, 0 }, 1 }, {}, { "LevelM60", { -0.1, 0 }, 1 }, { "LevelM60", { -0.085, 0 }, 1 }, {}, { "LevelM60", { -0.07, 0 }, 1 }, { "LevelM60", { -0.055, 0 }, 1 }, {}, {}, { "LevelM60", { 0.235, -0.02 }, 1 }, { "LevelM60", { 0.235, 0 }, 1 }, {}, { "LevelM60", { 0.22, 0 }, 1 }, { "LevelM60", { 0.205, 0 }, 1 }, {}, { "LevelM60", { 0.19, 0 }, 1 }, { "LevelM60", { 0.175, 0 }, 1 }, {}, { "LevelM60", { 0.16, 0 }, 1 }, { "LevelM60", { 0.145, 0 }, 1 }, {}, { "LevelM60", { 0.13, 0 }, 1 }, { "LevelM60", { 0.115, 0 }, 1 }, {}, { "LevelM60", { 0.1, 0 }, 1 }, { "LevelM60", { 0.085, 0 }, 1 }, {}, { "LevelM60", { 0.07, 0 }, 1 }, { "LevelM60", { 0.055, 0 }, 1 }, {} };
                        };
                        class VALM_1_60 {
                            type = "text";
                            source = "static";
                            text = -60;
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelM60", { -0.26, -0.032 }, 1 };
                            right[] = { "LevelM60", { -0.2, -0.032 }, 1 };
                            down[] = { "LevelM60", { -0.26, 0.018 }, 1 };
                        };
                        class VALM_1_60_R {
                            type = "text";
                            source = "static";
                            text = -60;
                            align = "right";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelM60", { 0.26, -0.032 }, 1 };
                            right[] = { "LevelM60", { 0.32, -0.032 }, 1 };
                            down[] = { "LevelM60", { 0.26, 0.018 }, 1 };
                        };
                        class LevelP60 : Level0 {
                            type = "line";
                            points[] = { { "LevelP60", { "-0.22-0.015", 0.02 }, 1 }, { "LevelP60", { "-0.22-0.015", 0 }, 1 }, { "LevelP60", { -0.06, 0 }, 1 }, {}, { "LevelP60", { 0.06, 0 }, 1 }, { "LevelP60", { "+0.22+0.015", 0 }, 1 }, { "LevelP60", { "+0.22+0.015", 0.02 }, 1 } };
                        };
                        class VALP_1_60 {
                            type = "text";
                            source = "static";
                            text = "60";
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelP60", { -0.26, -0.017 }, 1 };
                            right[] = { "LevelP60", { -0.2, -0.017 }, 1 };
                            down[] = { "LevelP60", { -0.26, 0.033 }, 1 };
                        };
                        class VALP_1_60_R {
                            type = "text";
                            source = "static";
                            text = "60";
                            align = "right";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelP60", { 0.26, -0.017 }, 1 };
                            right[] = { "LevelP60", { 0.32, -0.017 }, 1 };
                            down[] = { "LevelP60", { 0.26, 0.033 }, 1 };
                        };
                        class LevelM70 : Level0 {
                            type = "line";
                            points[] = { { "LevelM70", { -0.235, -0.02 }, 1 }, { "LevelM70", { -0.235, 0 }, 1 }, {}, { "LevelM70", { -0.22, 0 }, 1 }, { "LevelM70", { -0.205, 0 }, 1 }, {}, { "LevelM70", { -0.19, 0 }, 1 }, { "LevelM70", { -0.175, 0 }, 1 }, {}, { "LevelM70", { -0.16, 0 }, 1 }, { "LevelM70", { -0.145, 0 }, 1 }, {}, { "LevelM70", { -0.13, 0 }, 1 }, { "LevelM70", { -0.115, 0 }, 1 }, {}, { "LevelM70", { -0.1, 0 }, 1 }, { "LevelM70", { -0.085, 0 }, 1 }, {}, { "LevelM70", { -0.07, 0 }, 1 }, { "LevelM70", { -0.055, 0 }, 1 }, {}, {}, { "LevelM70", { 0.235, -0.02 }, 1 }, { "LevelM70", { 0.235, 0 }, 1 }, {}, { "LevelM70", { 0.22, 0 }, 1 }, { "LevelM70", { 0.205, 0 }, 1 }, {}, { "LevelM70", { 0.19, 0 }, 1 }, { "LevelM70", { 0.175, 0 }, 1 }, {}, { "LevelM70", { 0.16, 0 }, 1 }, { "LevelM70", { 0.145, 0 }, 1 }, {}, { "LevelM70", { 0.13, 0 }, 1 }, { "LevelM70", { 0.115, 0 }, 1 }, {}, { "LevelM70", { 0.1, 0 }, 1 }, { "LevelM70", { 0.085, 0 }, 1 }, {}, { "LevelM70", { 0.07, 0 }, 1 }, { "LevelM70", { 0.055, 0 }, 1 }, {} };
                        };
                        class VALM_1_70 {
                            type = "text";
                            source = "static";
                            text = -70;
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelM70", { -0.26, -0.032 }, 1 };
                            right[] = { "LevelM70", { -0.2, -0.032 }, 1 };
                            down[] = { "LevelM70", { -0.26, 0.018 }, 1 };
                        };
                        class VALM_1_70_R {
                            type = "text";
                            source = "static";
                            text = -70;
                            align = "right";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelM70", { 0.26, -0.032 }, 1 };
                            right[] = { "LevelM70", { 0.32, -0.032 }, 1 };
                            down[] = { "LevelM70", { 0.26, 0.018 }, 1 };
                        };
                        class LevelP70 : Level0 {
                            type = "line";
                            points[] = { { "LevelP70", { "-0.22-0.015", 0.02 }, 1 }, { "LevelP70", { "-0.22-0.015", 0 }, 1 }, { "LevelP70", { -0.06, 0 }, 1 }, {}, { "LevelP70", { 0.06, 0 }, 1 }, { "LevelP70", { "+0.22+0.015", 0 }, 1 }, { "LevelP70", { "+0.22+0.015", 0.02 }, 1 } };
                        };
                        class VALP_1_70 {
                            type = "text";
                            source = "static";
                            text = "70";
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelP70", { -0.26, -0.017 }, 1 };
                            right[] = { "LevelP70", { -0.2, -0.017 }, 1 };
                            down[] = { "LevelP70", { -0.26, 0.033 }, 1 };
                        };
                        class VALP_1_70_R {
                            type = "text";
                            source = "static";
                            text = "70";
                            align = "right";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelP70", { 0.26, -0.017 }, 1 };
                            right[] = { "LevelP70", { 0.32, -0.017 }, 1 };
                            down[] = { "LevelP70", { 0.26, 0.033 }, 1 };
                        };
                        class LevelM80 : Level0 {
                            type = "line";
                            points[] = { { "LevelM80", { -0.235, -0.02 }, 1 }, { "LevelM80", { -0.235, 0 }, 1 }, {}, { "LevelM80", { -0.22, 0 }, 1 }, { "LevelM80", { -0.205, 0 }, 1 }, {}, { "LevelM80", { -0.19, 0 }, 1 }, { "LevelM80", { -0.175, 0 }, 1 }, {}, { "LevelM80", { -0.16, 0 }, 1 }, { "LevelM80", { -0.145, 0 }, 1 }, {}, { "LevelM80", { -0.13, 0 }, 1 }, { "LevelM80", { -0.115, 0 }, 1 }, {}, { "LevelM80", { -0.1, 0 }, 1 }, { "LevelM80", { -0.085, 0 }, 1 }, {}, { "LevelM80", { -0.07, 0 }, 1 }, { "LevelM80", { -0.055, 0 }, 1 }, {}, {}, { "LevelM80", { 0.235, -0.02 }, 1 }, { "LevelM80", { 0.235, 0 }, 1 }, {}, { "LevelM80", { 0.22, 0 }, 1 }, { "LevelM80", { 0.205, 0 }, 1 }, {}, { "LevelM80", { 0.19, 0 }, 1 }, { "LevelM80", { 0.175, 0 }, 1 }, {}, { "LevelM80", { 0.16, 0 }, 1 }, { "LevelM80", { 0.145, 0 }, 1 }, {}, { "LevelM80", { 0.13, 0 }, 1 }, { "LevelM80", { 0.115, 0 }, 1 }, {}, { "LevelM80", { 0.1, 0 }, 1 }, { "LevelM80", { 0.085, 0 }, 1 }, {}, { "LevelM80", { 0.07, 0 }, 1 }, { "LevelM80", { 0.055, 0 }, 1 }, {} };
                        };
                        class VALM_1_80 {
                            type = "text";
                            source = "static";
                            text = -80;
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelM80", { -0.26, -0.032 }, 1 };
                            right[] = { "LevelM80", { -0.2, -0.032 }, 1 };
                            down[] = { "LevelM80", { -0.26, 0.018 }, 1 };
                        };
                        class VALM_1_80_R {
                            type = "text";
                            source = "static";
                            text = -80;
                            align = "right";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelM80", { 0.26, -0.032 }, 1 };
                            right[] = { "LevelM80", { 0.32, -0.032 }, 1 };
                            down[] = { "LevelM80", { 0.26, 0.018 }, 1 };
                        };
                        class LevelP80 : Level0 {
                            type = "line";
                            points[] = { { "LevelP80", { "-0.22-0.015", 0.02 }, 1 }, { "LevelP80", { "-0.22-0.015", 0 }, 1 }, { "LevelP80", { -0.06, 0 }, 1 }, {}, { "LevelP80", { 0.06, 0 }, 1 }, { "LevelP80", { "+0.22+0.015", 0 }, 1 }, { "LevelP80", { "+0.22+0.015", 0.02 }, 1 } };
                        };
                        class VALP_1_80 {
                            type = "text";
                            source = "static";
                            text = "80";
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelP80", { -0.26, -0.017 }, 1 };
                            right[] = { "LevelP80", { -0.2, -0.017 }, 1 };
                            down[] = { "LevelP80", { -0.26, 0.033 }, 1 };
                        };
                        class VALP_1_80_R {
                            type = "text";
                            source = "static";
                            text = "80";
                            align = "right";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelP80", { 0.26, -0.017 }, 1 };
                            right[] = { "LevelP80", { 0.32, -0.017 }, 1 };
                            down[] = { "LevelP80", { 0.26, 0.033 }, 1 };
                        };
                        class LevelM90 : Level0 {
                            type = "line";
                            points[] = { { "LevelM90", { -0.235, -0.02 }, 1 }, { "LevelM90", { -0.235, 0 }, 1 }, {}, { "LevelM90", { -0.22, 0 }, 1 }, { "LevelM90", { -0.205, 0 }, 1 }, {}, { "LevelM90", { -0.19, 0 }, 1 }, { "LevelM90", { -0.175, 0 }, 1 }, {}, { "LevelM90", { -0.16, 0 }, 1 }, { "LevelM90", { -0.145, 0 }, 1 }, {}, { "LevelM90", { -0.13, 0 }, 1 }, { "LevelM90", { -0.115, 0 }, 1 }, {}, { "LevelM90", { -0.1, 0 }, 1 }, { "LevelM90", { -0.085, 0 }, 1 }, {}, { "LevelM90", { -0.07, 0 }, 1 }, { "LevelM90", { -0.055, 0 }, 1 }, {}, {}, { "LevelM90", { 0.235, -0.02 }, 1 }, { "LevelM90", { 0.235, 0 }, 1 }, {}, { "LevelM90", { 0.22, 0 }, 1 }, { "LevelM90", { 0.205, 0 }, 1 }, {}, { "LevelM90", { 0.19, 0 }, 1 }, { "LevelM90", { 0.175, 0 }, 1 }, {}, { "LevelM90", { 0.16, 0 }, 1 }, { "LevelM90", { 0.145, 0 }, 1 }, {}, { "LevelM90", { 0.13, 0 }, 1 }, { "LevelM90", { 0.115, 0 }, 1 }, {}, { "LevelM90", { 0.1, 0 }, 1 }, { "LevelM90", { 0.085, 0 }, 1 }, {}, { "LevelM90", { 0.07, 0 }, 1 }, { "LevelM90", { 0.055, 0 }, 1 }, {} };
                        };
                        class VALM_1_90 {
                            type = "text";
                            source = "static";
                            text = -90;
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelM90", { -0.26, -0.032 }, 1 };
                            right[] = { "LevelM90", { -0.2, -0.032 }, 1 };
                            down[] = { "LevelM90", { -0.26, 0.018 }, 1 };
                        };
                        class VALM_1_90_R {
                            type = "text";
                            source = "static";
                            text = -90;
                            align = "right";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelM90", { 0.26, -0.032 }, 1 };
                            right[] = { "LevelM90", { 0.32, -0.032 }, 1 };
                            down[] = { "LevelM90", { 0.26, 0.018 }, 1 };
                        };
                        class LevelP90 : Level0 {
                            type = "line";
                            points[] = { { "LevelP90", { "-0.22-0.015", 0.02 }, 1 }, { "LevelP90", { "-0.22-0.015", 0 }, 1 }, { "LevelP90", { -0.06, 0 }, 1 }, {}, { "LevelP90", { 0.06, 0 }, 1 }, { "LevelP90", { "+0.22+0.015", 0 }, 1 }, { "LevelP90", { "+0.22+0.015", 0.02 }, 1 } };
                        };
                        class VALP_1_90 {
                            type = "text";
                            source = "static";
                            text = "90";
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelP90", { -0.26, -0.017 }, 1 };
                            right[] = { "LevelP90", { -0.2, -0.017 }, 1 };
                            down[] = { "LevelP90", { -0.26, 0.033 }, 1 };
                        };
                        class VALP_1_90_R {
                            type = "text";
                            source = "static";
                            text = "90";
                            align = "right";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = { "LevelP90", { 0.26, -0.017 }, 1 };
                            right[] = { "LevelP90", { 0.32, -0.017 }, 1 };
                            down[] = { "LevelP90", { 0.26, 0.033 }, 1 };
                        };
                    };
                };
            };
        };
    };
};
