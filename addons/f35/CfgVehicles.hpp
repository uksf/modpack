class CfgVehicles {
    class Plane_Base_F;
    class Motorcycle;
    class StaticAmmocart;
    class USAF_F35A: Plane_Base_F {
        scope = 2;
        scopeCurator = 2;
        displayName = "F-35A";
        side = 1;
        faction = "CUP_B_GB";
        crew = "UKSF_B_Pilot_617";
        typicalCargo[] = { "UKSF_B_Pilot_617" };
        editorPreview = QPATHTOEF(common,data\previews\USAF_F35A.jpg);
        hiddenSelections[] = { "rendertarget0", "screen_1", "screen_2", "screen_3", "screen_4", "screen_5", "screen_6", "camo1", "camo2", "camo3", "camo4" };
        hiddenSelectionsTextures[] = { "#(rgb,8,8,3)color(0,0,0,0)", "", "", "", "", "", "", QPATHTOF(data\F-35Auk.paa), QPATHTOF(data\f_35c_ext_2_co.paa), QPATHTOF(data\f_35c_ext_3_co.paa), QPATHTOF(data\f35_glass_ca.paa) };
        weapons[] = {
            "USAF_F35A_CMFlareLauncher",
            "USAF_F35A_Master_Arm_Switch",
            "USAF_F35A_CANNON_W",
            "USAF_AIM9X_Launcher",
            "USAF_AIM120I_Launcher",
            "USAF_GBU12_Launcher",
            "USAF_F35A_GBU53_int_W",
            "USAF_AGM154A1_Launcher"
        };
        magazines[] = {
            "300Rnd_CMFlare_Chaff_Magazine",
            "USAF_F35A_CANNON_M",
            "USAF_1Rnd_StationR",
            "USAF_1Rnd_StationL",
            "USAF_1Rnd_Station2",
            "USAF_1Rnd_Station2",
            "USAF_1Rnd_Station1",
            "USAF_1Rnd_Station1",
            "USAF_1Rnd_AIM9X",
            "USAF_1Rnd_AIM9X",
            "USAF_1Rnd_AGM154A1",
            "USAF_1Rnd_AGM154A1",
            "USAF_Empty",
            "USAF_Empty",
            "USAF_Empty",
            "USAF_Empty",
            "USAF_1Rnd_GBU12",
            "USAF_1Rnd_GBU12",
            "USAF_1Rnd_AIM120I",
            "USAF_1Rnd_AIM120I",
            "USAF_F35A_8Rnd_GBU53_M",
            "USAF_F35A_8Rnd_GBU53_M",
            "USAF_F35A_8Rnd_GBU53_M",
            "USAF_F35A_8Rnd_GBU53_M",
            "USAF_F35A_8Rnd_GBU53_M",
            "USAF_F35A_8Rnd_GBU53_M",
            "USAF_F35A_8Rnd_GBU53_M",
            "USAF_F35A_8Rnd_GBU53_M",
            "USAF_empty",
            "USAF_empty",
            "USAF_empty",
            "USAF_empty",
            "USAF_empty",
            "USAF_empty",
            "USAF_empty",
            "USAF_empty"
        };
        maxSpeed = 1930;
        unitInfoType = "Rsc_UKSF_F35_Limited";
        unitInfoTypeLite = "Rsc_UKSF_F35_Limited";
        attenuationEffectType = "PlaneAttenuation";
        soundGetIn[] = { "A3\sounds_F\air\Plane_Fighter_03\getin", 0.562341, 1 };
        soundGetOut[] = { "A3\sounds_F\air\Plane_Fighter_03\getout", 0.562341, 1, 40 };
        soundDammage[] = { "", 0.562341, 1 };
        soundEngineOnInt[] = { QPATHTOF(data\sound\f_startup_int.wss), 1.0, 1.0 };
        soundEngineOnExt[] = { QPATHTOF(data\sound\f_enginestart_ext.wss), 15, 1.0, 700 };
        soundEngineOffInt[] = { QPATHTOF(data\sound\f_shutdown_int.wss), 1.0, 1.0 };
        soundEngineOffExt[] = { QPATHTOF(data\sound\f_shutdown_ext.wss), 10, 1.0, 500 };
        soundLocked[] = { "\A3\sounds_F\weapons\Rockets\locked_1", 0.1, 1 };
        soundIncommingMissile[] = { "\A3\sounds_F\weapons\Rockets\locked_3", 0.1, 1.5 };
        soundGearUp[] = { "A3\sounds_F_EPC\CAS_02\gear_up", 0.794328, 1.0, 150 };
        soundGearDown[] = { "A3\sounds_F_EPC\CAS_02\gear_down", 0.794328, 1.0, 150 };
        soundFlapsUp[] = { "A3\sounds_F_EPC\CAS_02\Flaps_Up", 0.630957, 1.0, 100 };
        soundFlapsDown[] = { "A3\sounds_F_EPC\CAS_02\Flaps_Down", 0.630957, 1.0, 100 };
        class sounds {
            class EngineLowOut {
                sound[] = { QPATHTOF(data\sound\f_engine_ext.wss), 12, 1.0, 1250 };
                frequency = "1.0 min (rpm + 0.5)";
                volume = "engineOn*camPos*(thrust factor[1.0, 1.0])*(thrust factor[1.0, 0.3])";
                cone[] = { 3.0, 3.92, 1.9, 0.5 };
            };
            class EngineHighOut {
                sound[] = { QPATHTOF(data\sound\ext_low_var1.wss), 20, 1.0, 3500 };
                frequency = "1";
                volume = "engineOn*camPos*(speed factor [50,100])";
                cone[] = { 3.14, 3.92, 2.0, 0.5 };
            };
            class ForsageOut {
                sound[] = { QPATHTOF(data\sound\forsagevar4.wss), 17, 0.99, 2500 };
                frequency = "1";
                volume = "engineOn*camPos*(thrust factor[0.6, 1.0])";
                cone[] = { 3.14, 3.92, 2.0, 0.5 };
            };
            class ActuatorForsageOut {
                sound[] = { QPATHTOF(data\sound\actuatorforsage.wss), 16, 0.99, 400 };
                frequency = "1";
                volume = "engineOn*camPos*(thrust factor[0.6, 1.0])";
                cone[] = { 3.14, 3.92, 2.0, 0.5 };
            };
            class WindNoiseOut {
                sound[] = { QPATHTOF(data\sound\f_windnoise_ext.wss), 0.562341, 1.0, 150 };
                frequency = "(0.1+(1.2*(speed factor[1, 150])))";
                volume = "camPos*(speed factor[1, 150])";
            };
            class DistantPlaneOut {
                sound[] = { QPATHTOF(data\sound\16_distant.wss), 12, 1.0, 5000 };
                frequency = "1";
                volume = "engineOn*camPos*(thrust factor[0.6, 1.0])";
                cone[] = { 3.14, 3.92, 2.0, 0.5 };
            };
            class EngineLowIn {
                sound[] = { QPATHTOF(data\sound\f_engine_int.wss), db2, 1.0 };
                frequency = "1.0 min (rpm + 0.5)";
                volume = "(1-camPos)*(rpm factor[0.85, 1.0])";
            };
            class EngineHighIn {
                sound[] = { QPATHTOF(data\sound\f_forsage_int.wss), db2, 1.2 };
                frequency = "1";
                volume = "(1-camPos)*(rpm factor[0.85, 1.0])";
            };
            class ForsageIn {
                sound[] = { QPATHTOF(data\sound\f_forsage_int.wss), db3, 1.0 };
                frequency = "1";
                volume = "(1-camPos)*(engineOn*(thrust factor[0.6, 1.0]))";
            };
            class WindNoiseIn {
                sound[] = { QPATHTOF(data\sound\f_windnoise_int.wss), db - 1, 1.0 };
                frequency = "(0.1+(1.2*(speed factor[1, 150])))";
                volume = "(1-camPos)*(speed factor[1, 150])";
            };
            class RainExt {
                sound[] = { "A3\sounds_F\vehicles\noises\rain1_ext", db5, 1.0, 100 };
                frequency = 1;
                volume = "camPos * rain * (speed factor[50, 0])";
            };
            class RainInt {
                sound[] = { "A3\sounds_F\vehicles\noises\rain1_int", db0, 1.0, 100 };
                frequency = 1;
                volume = "(1-camPos) * rain * (speed factor[50, 0])";
            };
        };
        class MFD {
            class AirplaneHUD {
                enableParallax = 1;
                class Pos10Vector {
                    type = "vector";
                    pos0[] = { 0.5,0.5 };
                    pos10[] = { 0.71132398,0.79310501 };
                };
                topLeft = "HUD LH";
                topRight = "HUD PH";
                bottomLeft = "HUD LD";
                borderLeft = 0;
                borderRight = 0;
                borderTop = 0;
                borderBottom = 0;
                color[] = { 0.15000001,1,0.15000001,0.1 };
                class Bones {
                    class text_debug {
                        type = "fixed";
                        pos[] = { 0.75,0.75 };
                    };
                    class ForwardVec {
                        type = "vector";
                        source = "forward";
                        pos0[] = { 0,0 };
                        pos10[] = { 0.21132436,0.29310483 };
                    };
                    class ForwardVecX {
                        type = "vector";
                        source = "forward";
                        pos0[] = { 0,0 };
                        pos10[] = { 0.21132436,0 };
                    };
                    class ForwardVecY {
                        type = "vector";
                        source = "forward";
                        pos0[] = { 0,0 };
                        pos10[] = { 0,0.29310483 };
                    };
                    class PlaneW {
                        type = "fixed";
                        pos[] = { 0.5,0.5 };
                    };
                    class center {
                        type = "fixed";
                        pos[] = 
                        {
                            0.5,
                            "PoxY0Center"
                        };
                    };
                    class horizon_data {
                        type = "fixed";
                        pos[] = { 0.215,0.45050001 };
                    };
                    class waypointIndicator {
                        type = "linear";
                        source = "heading";
                        sourceScale = 1;
                        min = 0;
                        max = 360;
                        minPos[] = { 0,0 };
                        maxPos[] = { 7.1999998,0 };
                    };
                    class speedIndicator {
                        type = "fixed";
                        pos[] = { 0.205,0.27500001 };
                    };
                    class altIndicator {
                        type = "fixed";
                        pos[] = { 0.79500002,0.27500001 };
                    };
                    class emconIndicator {
                        type = "fixed";
                        pos[] = { 0.79000002,0.80000001 };
                    };
                    class weaponIndicator {
                        type = "fixed";
                        pos[] = { 0.20999999,0.80000001 };
                    };
                    class bottomIndicator {
                        type = "fixed";
                        pos[] = { 0.5,0.94999999 };
                    };
                    class weaponAim: Pos10Vector {
                        source = "weapon";
                    };
                    class Target: Pos10Vector {
                        source = "target";
                    };
                    class Velocity: Pos10Vector {
                        type = "vector";
                        source = "velocity";
                        pos0[] = { 0.5,0.5 };
                        pos10[] = { 0.71132398,0.79310501 };
                    };
                    class ILS_H {
                        type = "ils";
                        pos0[] = { 0.5,0.5 };
                        pos3[] = { 0.56339699,0.5 };
                    };
                    class ILS_W: ILS_H {
                        pos3[] = { 0.5,0.58793098 };
                    };
                    class Level0: Pos10Vector {
                        pos0[] = { 0.5,0.5 };
                        pos10[] = { 0.83811897,0.88103598 };
                        type = "horizon";
                        angle = 0;
                    };
                    class HorizonBankRot {
                        type = "rotational";
                        source = "horizonBank";
                        center[] = { 0.5,0.5 };
                        min = -1.0472;
                        max = 1.0472;
                        minAngle = -60;
                        maxAngle = 60;
                        aspectRatio = 1.3888888;
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
                    class LevelP55: Level0 {
                        angle = 55;
                    };
                    class LevelM55: Level0 {
                        angle = -55;
                    };
                    class LevelP60: Level0 {
                        angle = 60;
                    };
                    class LevelM60: Level0 {
                        angle = -60;
                    };
                    class LevelP65: Level0 {
                        angle = 65;
                    };
                    class LevelM65: Level0 {
                        angle = -65;
                    };
                    class LevelP70: Level0 {
                        angle = 70;
                    };
                    class LevelM70: Level0 {
                        angle = -70;
                    };
                    class LevelP75: Level0 {
                        angle = 75;
                    };
                    class LevelM75: Level0 {
                        angle = -75;
                    };
                    class LevelP80: Level0 {
                        angle = 80;
                    };
                    class LevelM80: Level0 {
                        angle = -80;
                    };
                    class LevelP85: Level0 {
                        angle = 85;
                    };
                    class LevelM85: Level0 {
                        angle = -85;
                    };
                    class LevelP90: Level0 {
                        angle = 90;
                    };
                    class LevelM90: Level0 {
                        angle = -90;
                    };
                };
                class Draw {
                    alpha = 0.40000001;
                    color[] = { 0.15000001,1,0.15000001 };
                    condition = "on";
                    class centerPoint {
                        type = "line";
                        width = 4;
                        points[] = 
                        {

                            {
                                "PlaneW",
                                { 0,-0.0024999999 },
                                1
                            },

                            {
                                "PlaneW",
                                { 0,0.0024999999 },
                                1
                            },
                            {},

                            {
                                "PlaneW",
                                { 0.0020000001,0 },
                                1
                            },

                            {
                                "PlaneW",
                                { -0.0020000001,0 },
                                1
                            },
                            {}
                        };
                    };
                    class flightPathVector {
                        clipTL[] = { 0,1 };
                        clipBR[] = { 1,0 };
                        type = "line";
                        width = 4;
                        points[] = 
                        {

                            {
                                "Velocity",
                                1,
                                "ForwardVec",
                                { 0,0.0138699 },
                                1
                            },

                            {
                                "Velocity",
                                1,
                                "ForwardVec",
                                { 0.0025881899,0.0133973 },
                                1
                            },

                            {
                                "Velocity",
                                1,
                                "ForwardVec",
                                { 0.0049999999,0.0120117 },
                                1
                            },

                            {
                                "Velocity",
                                1,
                                "ForwardVec",
                                { 0.0070710699,0.0098075001 },
                                1
                            },

                            {
                                "Velocity",
                                1,
                                "ForwardVec",
                                { 0.0086602503,0.0069349501 },
                                1
                            },

                            {
                                "Velocity",
                                1,
                                "ForwardVec",
                                { 0.0096592596,0.0035897901 },
                                1
                            },

                            {
                                "Velocity",
                                1,
                                "ForwardVec",
                                { 0.0099999998,-6.0627298e-010 },
                                1
                            },

                            {
                                "Velocity",
                                1,
                                "ForwardVec",
                                { 0.0096592596,-0.0035898001 },
                                1
                            },

                            {
                                "Velocity",
                                1,
                                "ForwardVec",
                                { 0.0086602503,-0.0069349501 },
                                1
                            },

                            {
                                "Velocity",
                                1,
                                "ForwardVec",
                                { 0.0070710699,-0.0098075001 },
                                1
                            },

                            {
                                "Velocity",
                                1,
                                "ForwardVec",
                                { 0.0049999999,-0.0120117 },
                                1
                            },

                            {
                                "Velocity",
                                1,
                                "ForwardVec",
                                { 0.0025881899,-0.0133973 },
                                1
                            },

                            {
                                "Velocity",
                                1,
                                "ForwardVec",
                                { -8.7422802e-010,-0.0138699 },
                                1
                            },

                            {
                                "Velocity",
                                1,
                                "ForwardVec",
                                { -0.0025881899,-0.0133973 },
                                1
                            },

                            {
                                "Velocity",
                                1,
                                "ForwardVec",
                                { -0.0049999999,-0.0120117 },
                                1
                            },

                            {
                                "Velocity",
                                1,
                                "ForwardVec",
                                { -0.0070710699,-0.0098075001 },
                                1
                            },

                            {
                                "Velocity",
                                1,
                                "ForwardVec",
                                { -0.0086602503,-0.0069349501 },
                                1
                            },

                            {
                                "Velocity",
                                1,
                                "ForwardVec",
                                { -0.0096592596,-0.0035897901 },
                                1
                            },

                            {
                                "Velocity",
                                1,
                                "ForwardVec",
                                { -0.0099999998,1.65397e-010 },
                                1
                            },

                            {
                                "Velocity",
                                1,
                                "ForwardVec",
                                { -0.0096592596,0.0035898001 },
                                1
                            },

                            {
                                "Velocity",
                                1,
                                "ForwardVec",
                                { -0.0086602503,0.0069349599 },
                                1
                            },

                            {
                                "Velocity",
                                1,
                                "ForwardVec",
                                { -0.0070710699,0.0098075001 },
                                1
                            },

                            {
                                "Velocity",
                                1,
                                "ForwardVec",
                                { -0.0049999999,0.0120117 },
                                1
                            },

                            {
                                "Velocity",
                                1,
                                "ForwardVec",
                                { -0.0025881899,0.0133973 },
                                1
                            },

                            {
                                "Velocity",
                                1,
                                "ForwardVec",
                                { 1.74846e-009,0.0138699 },
                                1
                            },
                            {},

                            {
                                "Velocity",
                                1,
                                "ForwardVec",
                                { 0.029999999,0 },
                                1
                            },

                            {
                                "Velocity",
                                1,
                                "ForwardVec",
                                { 0.0099999998,0 },
                                1
                            },
                            {},

                            {
                                "Velocity",
                                1,
                                "ForwardVec",
                                { -0.029999999,0 },
                                1
                            },

                            {
                                "Velocity",
                                1,
                                "ForwardVec",
                                { -0.0099999998,0 },
                                1
                            },
                            {},

                            {
                                "Velocity",
                                1,
                                "ForwardVec",
                                { 0,-0.027739801 },
                                1
                            },

                            {
                                "Velocity",
                                1,
                                "ForwardVec",
                                { 0,-0.0138699 },
                                1
                            },
                            {}
                        };
                    };
                    class Horizon {
                        class Horizon_1 {
                            clipTL[] = { 0.26300001,0.112 };
                            clipBR[] = { 1,1 };
                            class Level0_1 {
                                type = "line";
                                width = 4;
                                points[] = 
                                {

                                    {
                                        "Level0",
                                        { 2,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "Level0",
                                        { 0.079999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "level0",
                                        { -0.079999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "level0",
                                        { -2,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                        };
                        class Horizon_2 {
                            clipTL[] = { 0,0.112 };
                            clipBR[] = { 0.213,1 };
                            class Level0_2 {
                                type = "line";
                                width = 4;
                                points[] = 
                                {

                                    {
                                        "Level0",
                                        { 2,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "Level0",
                                        { 0.079999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "level0",
                                        { -0.079999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "level0",
                                        { -2,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                        };
                        class Horizon_3 {
                            clipTL[] = { 0.213,0.112 };
                            clipBR[] = { 0.26300001,0.45100001 };
                            class Level0_3 {
                                type = "line";
                                width = 4;
                                points[] = 
                                {

                                    {
                                        "Level0",
                                        { 2,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "Level0",
                                        { 0.079999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "level0",
                                        { -0.079999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "level0",
                                        { -2,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                        };
                        class Horizon_4 {
                            clipTL[] = { 0.213,0.54049999 };
                            clipBR[] = { 0.26300001,1 };
                            class Level0_4 {
                                type = "line";
                                width = 4;
                                points[] = 
                                {

                                    {
                                        "Level0",
                                        { 2,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "Level0",
                                        { 0.079999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "level0",
                                        { -0.079999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "level0",
                                        { -2,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                        };
                        clipTL[] = { 0,0.112 };
                        clipBR[] = { 1,1 };
                        class HorizonLadder {
                            class LevelM5 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelM5",
                                        { -0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM5",
                                        { -0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM5",
                                        { -0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM5",
                                        { -0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM5",
                                        { -0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM5",
                                        { -0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM5",
                                        { -0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM5",
                                        { -0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM5",
                                        { -0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM5",
                                        { -0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM5",
                                        { -0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM5",
                                        { -0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM5",
                                        { -0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM5",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM5",
                                        { 0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM5",
                                        { 0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM5",
                                        { 0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM5",
                                        { 0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM5",
                                        { 0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM5",
                                        { 0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM5",
                                        { 0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM5",
                                        { 0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM5",
                                        { 0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM5",
                                        { 0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM5",
                                        { 0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM5",
                                        { 0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM5",
                                        { 0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM5",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALM_1_5 {
                                type = "text";
                                source = "static";
                                text = -5;
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM5",
                                    { 0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM5",
                                    { 0.24250001,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM5",
                                    { 0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALM_2_5 {
                                type = "text";
                                source = "static";
                                text = -5;
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM5",
                                    { -0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM5",
                                    { -0.1675,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM5",
                                    { -0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelP5 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelP5",
                                        { -0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP5",
                                        { -0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP5",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelP5",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP5",
                                        { 0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP5",
                                        { 0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALP_1_5 {
                                type = "text";
                                source = "static";
                                text = "5";
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP5",
                                    { -0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP5",
                                    { -0.1675,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP5",
                                    { -0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALP_2_5 {
                                type = "text";
                                source = "static";
                                text = "5";
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP5",
                                    { 0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP5",
                                    { 0.24250001,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP5",
                                    { 0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelM10 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelM10",
                                        { -0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM10",
                                        { -0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM10",
                                        { -0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM10",
                                        { -0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM10",
                                        { -0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM10",
                                        { -0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM10",
                                        { -0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM10",
                                        { -0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM10",
                                        { -0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM10",
                                        { -0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM10",
                                        { -0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM10",
                                        { -0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM10",
                                        { -0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM10",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM10",
                                        { 0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM10",
                                        { 0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM10",
                                        { 0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM10",
                                        { 0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM10",
                                        { 0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM10",
                                        { 0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM10",
                                        { 0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM10",
                                        { 0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM10",
                                        { 0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM10",
                                        { 0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM10",
                                        { 0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM10",
                                        { 0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM10",
                                        { 0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM10",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALM_1_10 {
                                type = "text";
                                source = "static";
                                text = -10;
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM10",
                                    { 0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM10",
                                    { 0.24250001,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM10",
                                    { 0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALM_2_10 {
                                type = "text";
                                source = "static";
                                text = -10;
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM10",
                                    { -0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM10",
                                    { -0.1675,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM10",
                                    { -0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelP10 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelP10",
                                        { -0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP10",
                                        { -0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP10",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelP10",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP10",
                                        { 0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP10",
                                        { 0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALP_1_10 {
                                type = "text";
                                source = "static";
                                text = "10";
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP10",
                                    { -0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP10",
                                    { -0.1675,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP10",
                                    { -0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALP_2_10 {
                                type = "text";
                                source = "static";
                                text = "10";
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP10",
                                    { 0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP10",
                                    { 0.24250001,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP10",
                                    { 0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelM15 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelM15",
                                        { -0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM15",
                                        { -0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM15",
                                        { -0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM15",
                                        { -0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM15",
                                        { -0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM15",
                                        { -0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM15",
                                        { -0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM15",
                                        { -0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM15",
                                        { -0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM15",
                                        { -0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM15",
                                        { -0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM15",
                                        { -0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM15",
                                        { -0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM15",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM15",
                                        { 0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM15",
                                        { 0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM15",
                                        { 0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM15",
                                        { 0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM15",
                                        { 0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM15",
                                        { 0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM15",
                                        { 0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM15",
                                        { 0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM15",
                                        { 0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM15",
                                        { 0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM15",
                                        { 0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM15",
                                        { 0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM15",
                                        { 0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM15",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALM_1_15 {
                                type = "text";
                                source = "static";
                                text = -15;
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM15",
                                    { 0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM15",
                                    { 0.24250001,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM15",
                                    { 0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALM_2_15 {
                                type = "text";
                                source = "static";
                                text = -15;
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM15",
                                    { -0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM15",
                                    { -0.1675,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM15",
                                    { -0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelP15 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelP15",
                                        { -0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP15",
                                        { -0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP15",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelP15",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP15",
                                        { 0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP15",
                                        { 0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALP_1_15 {
                                type = "text";
                                source = "static";
                                text = "15";
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP15",
                                    { -0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP15",
                                    { -0.1675,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP15",
                                    { -0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALP_2_15 {
                                type = "text";
                                source = "static";
                                text = "15";
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP15",
                                    { 0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP15",
                                    { 0.24250001,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP15",
                                    { 0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelM20 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelM20",
                                        { -0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM20",
                                        { -0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM20",
                                        { -0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM20",
                                        { -0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM20",
                                        { -0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM20",
                                        { -0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM20",
                                        { -0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM20",
                                        { -0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM20",
                                        { -0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM20",
                                        { -0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM20",
                                        { -0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM20",
                                        { -0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM20",
                                        { -0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM20",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM20",
                                        { 0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM20",
                                        { 0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM20",
                                        { 0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM20",
                                        { 0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM20",
                                        { 0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM20",
                                        { 0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM20",
                                        { 0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM20",
                                        { 0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM20",
                                        { 0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM20",
                                        { 0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM20",
                                        { 0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM20",
                                        { 0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM20",
                                        { 0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM20",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALM_1_20 {
                                type = "text";
                                source = "static";
                                text = -20;
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM20",
                                    { 0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM20",
                                    { 0.24250001,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM20",
                                    { 0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALM_2_20 {
                                type = "text";
                                source = "static";
                                text = -20;
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM20",
                                    { -0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM20",
                                    { -0.1675,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM20",
                                    { -0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelP20 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelP20",
                                        { -0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP20",
                                        { -0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP20",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelP20",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP20",
                                        { 0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP20",
                                        { 0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALP_1_20 {
                                type = "text";
                                source = "static";
                                text = "20";
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP20",
                                    { -0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP20",
                                    { -0.1675,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP20",
                                    { -0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALP_2_20 {
                                type = "text";
                                source = "static";
                                text = "20";
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP20",
                                    { 0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP20",
                                    { 0.24250001,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP20",
                                    { 0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelM25 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelM25",
                                        { -0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM25",
                                        { -0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM25",
                                        { -0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM25",
                                        { -0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM25",
                                        { -0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM25",
                                        { -0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM25",
                                        { -0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM25",
                                        { -0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM25",
                                        { -0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM25",
                                        { -0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM25",
                                        { -0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM25",
                                        { -0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM25",
                                        { -0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM25",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM25",
                                        { 0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM25",
                                        { 0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM25",
                                        { 0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM25",
                                        { 0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM25",
                                        { 0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM25",
                                        { 0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM25",
                                        { 0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM25",
                                        { 0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM25",
                                        { 0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM25",
                                        { 0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM25",
                                        { 0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM25",
                                        { 0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM25",
                                        { 0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM25",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALM_1_25 {
                                type = "text";
                                source = "static";
                                text = -25;
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM25",
                                    { 0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM25",
                                    { 0.24250001,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM25",
                                    { 0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALM_2_25 {
                                type = "text";
                                source = "static";
                                text = -25;
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM25",
                                    { -0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM25",
                                    { -0.1675,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM25",
                                    { -0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelP25 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelP25",
                                        { -0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP25",
                                        { -0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP25",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelP25",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP25",
                                        { 0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP25",
                                        { 0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALP_1_25 {
                                type = "text";
                                source = "static";
                                text = "25";
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP25",
                                    { -0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP25",
                                    { -0.1675,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP25",
                                    { -0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALP_2_25 {
                                type = "text";
                                source = "static";
                                text = "25";
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP25",
                                    { 0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP25",
                                    { 0.24250001,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP25",
                                    { 0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelM30 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelM30",
                                        { -0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM30",
                                        { -0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM30",
                                        { -0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM30",
                                        { -0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM30",
                                        { -0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM30",
                                        { -0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM30",
                                        { -0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM30",
                                        { -0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM30",
                                        { -0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM30",
                                        { -0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM30",
                                        { -0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM30",
                                        { -0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM30",
                                        { -0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM30",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM30",
                                        { 0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM30",
                                        { 0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM30",
                                        { 0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM30",
                                        { 0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM30",
                                        { 0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM30",
                                        { 0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM30",
                                        { 0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM30",
                                        { 0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM30",
                                        { 0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM30",
                                        { 0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM30",
                                        { 0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM30",
                                        { 0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM30",
                                        { 0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM30",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALM_1_30 {
                                type = "text";
                                source = "static";
                                text = -30;
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM30",
                                    { 0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM30",
                                    { 0.24250001,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM30",
                                    { 0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALM_2_30 {
                                type = "text";
                                source = "static";
                                text = -30;
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM30",
                                    { -0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM30",
                                    { -0.1675,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM30",
                                    { -0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelP30 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelP30",
                                        { -0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP30",
                                        { -0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP30",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelP30",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP30",
                                        { 0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP30",
                                        { 0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALP_1_30 {
                                type = "text";
                                source = "static";
                                text = "30";
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP30",
                                    { -0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP30",
                                    { -0.1675,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP30",
                                    { -0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALP_2_30 {
                                type = "text";
                                source = "static";
                                text = "30";
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP30",
                                    { 0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP30",
                                    { 0.24250001,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP30",
                                    { 0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelM35 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelM35",
                                        { -0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM35",
                                        { -0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM35",
                                        { -0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM35",
                                        { -0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM35",
                                        { -0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM35",
                                        { -0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM35",
                                        { -0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM35",
                                        { -0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM35",
                                        { -0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM35",
                                        { -0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM35",
                                        { -0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM35",
                                        { -0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM35",
                                        { -0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM35",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM35",
                                        { 0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM35",
                                        { 0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM35",
                                        { 0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM35",
                                        { 0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM35",
                                        { 0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM35",
                                        { 0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM35",
                                        { 0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM35",
                                        { 0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM35",
                                        { 0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM35",
                                        { 0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM35",
                                        { 0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM35",
                                        { 0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM35",
                                        { 0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM35",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALM_1_35 {
                                type = "text";
                                source = "static";
                                text = -35;
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM35",
                                    { 0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM35",
                                    { 0.24250001,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM35",
                                    { 0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALM_2_35 {
                                type = "text";
                                source = "static";
                                text = -35;
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM35",
                                    { -0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM35",
                                    { -0.1675,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM35",
                                    { -0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelP35 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelP35",
                                        { -0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP35",
                                        { -0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP35",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelP35",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP35",
                                        { 0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP35",
                                        { 0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALP_1_35 {
                                type = "text";
                                source = "static";
                                text = "35";
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP35",
                                    { -0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP35",
                                    { -0.1675,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP35",
                                    { -0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALP_2_35 {
                                type = "text";
                                source = "static";
                                text = "35";
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP35",
                                    { 0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP35",
                                    { 0.24250001,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP35",
                                    { 0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelM40 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelM40",
                                        { -0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM40",
                                        { -0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM40",
                                        { -0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM40",
                                        { -0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM40",
                                        { -0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM40",
                                        { -0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM40",
                                        { -0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM40",
                                        { -0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM40",
                                        { -0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM40",
                                        { -0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM40",
                                        { -0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM40",
                                        { -0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM40",
                                        { -0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM40",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM40",
                                        { 0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM40",
                                        { 0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM40",
                                        { 0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM40",
                                        { 0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM40",
                                        { 0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM40",
                                        { 0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM40",
                                        { 0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM40",
                                        { 0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM40",
                                        { 0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM40",
                                        { 0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM40",
                                        { 0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM40",
                                        { 0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM40",
                                        { 0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM40",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALM_1_40 {
                                type = "text";
                                source = "static";
                                text = -40;
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM40",
                                    { 0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM40",
                                    { 0.24250001,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM40",
                                    { 0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALM_2_40 {
                                type = "text";
                                source = "static";
                                text = -40;
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM40",
                                    { -0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM40",
                                    { -0.1675,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM40",
                                    { -0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelP40 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelP40",
                                        { -0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP40",
                                        { -0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP40",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelP40",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP40",
                                        { 0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP40",
                                        { 0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALP_1_40 {
                                type = "text";
                                source = "static";
                                text = "40";
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP40",
                                    { -0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP40",
                                    { -0.1675,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP40",
                                    { -0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALP_2_40 {
                                type = "text";
                                source = "static";
                                text = "40";
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP40",
                                    { 0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP40",
                                    { 0.24250001,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP40",
                                    { 0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelM45 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelM45",
                                        { -0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM45",
                                        { -0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM45",
                                        { -0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM45",
                                        { -0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM45",
                                        { -0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM45",
                                        { -0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM45",
                                        { -0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM45",
                                        { -0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM45",
                                        { -0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM45",
                                        { -0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM45",
                                        { -0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM45",
                                        { -0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM45",
                                        { -0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM45",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM45",
                                        { 0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM45",
                                        { 0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM45",
                                        { 0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM45",
                                        { 0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM45",
                                        { 0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM45",
                                        { 0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM45",
                                        { 0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM45",
                                        { 0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM45",
                                        { 0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM45",
                                        { 0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM45",
                                        { 0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM45",
                                        { 0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM45",
                                        { 0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM45",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALM_1_45 {
                                type = "text";
                                source = "static";
                                text = -45;
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM45",
                                    { 0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM45",
                                    { 0.24250001,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM45",
                                    { 0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALM_2_45 {
                                type = "text";
                                source = "static";
                                text = -45;
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM45",
                                    { -0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM45",
                                    { -0.1675,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM45",
                                    { -0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelP45 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelP45",
                                        { -0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP45",
                                        { -0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP45",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelP45",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP45",
                                        { 0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP45",
                                        { 0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALP_1_45 {
                                type = "text";
                                source = "static";
                                text = "45";
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP45",
                                    { -0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP45",
                                    { -0.1675,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP45",
                                    { -0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALP_2_45 {
                                type = "text";
                                source = "static";
                                text = "45";
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP45",
                                    { 0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP45",
                                    { 0.24250001,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP45",
                                    { 0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelM50 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelM50",
                                        { -0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM50",
                                        { -0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM50",
                                        { -0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM50",
                                        { -0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM50",
                                        { -0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM50",
                                        { -0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM50",
                                        { -0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM50",
                                        { -0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM50",
                                        { -0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM50",
                                        { -0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM50",
                                        { -0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM50",
                                        { -0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM50",
                                        { -0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM50",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM50",
                                        { 0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM50",
                                        { 0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM50",
                                        { 0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM50",
                                        { 0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM50",
                                        { 0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM50",
                                        { 0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM50",
                                        { 0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM50",
                                        { 0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM50",
                                        { 0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM50",
                                        { 0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM50",
                                        { 0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM50",
                                        { 0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM50",
                                        { 0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM50",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALM_1_50 {
                                type = "text";
                                source = "static";
                                text = -50;
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM50",
                                    { 0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM50",
                                    { 0.24250001,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM50",
                                    { 0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALM_2_50 {
                                type = "text";
                                source = "static";
                                text = -50;
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM50",
                                    { -0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM50",
                                    { -0.1675,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM50",
                                    { -0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelP50 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelP50",
                                        { -0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP50",
                                        { -0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP50",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelP50",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP50",
                                        { 0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP50",
                                        { 0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALP_1_50 {
                                type = "text";
                                source = "static";
                                text = "50";
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP50",
                                    { -0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP50",
                                    { -0.1675,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP50",
                                    { -0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALP_2_50 {
                                type = "text";
                                source = "static";
                                text = "50";
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP50",
                                    { 0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP50",
                                    { 0.24250001,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP50",
                                    { 0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelM55 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelM55",
                                        { -0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM55",
                                        { -0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM55",
                                        { -0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM55",
                                        { -0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM55",
                                        { -0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM55",
                                        { -0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM55",
                                        { -0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM55",
                                        { -0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM55",
                                        { -0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM55",
                                        { -0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM55",
                                        { -0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM55",
                                        { -0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM55",
                                        { -0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM55",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM55",
                                        { 0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM55",
                                        { 0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM55",
                                        { 0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM55",
                                        { 0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM55",
                                        { 0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM55",
                                        { 0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM55",
                                        { 0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM55",
                                        { 0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM55",
                                        { 0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM55",
                                        { 0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM55",
                                        { 0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM55",
                                        { 0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM55",
                                        { 0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM55",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALM_1_55 {
                                type = "text";
                                source = "static";
                                text = -55;
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM55",
                                    { 0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM55",
                                    { 0.24250001,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM55",
                                    { 0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALM_2_55 {
                                type = "text";
                                source = "static";
                                text = -55;
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM55",
                                    { -0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM55",
                                    { -0.1675,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM55",
                                    { -0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelP55 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelP55",
                                        { -0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP55",
                                        { -0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP55",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelP55",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP55",
                                        { 0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP55",
                                        { 0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALP_1_55 {
                                type = "text";
                                source = "static";
                                text = "55";
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP55",
                                    { -0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP55",
                                    { -0.1675,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP55",
                                    { -0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALP_2_55 {
                                type = "text";
                                source = "static";
                                text = "55";
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP55",
                                    { 0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP55",
                                    { 0.24250001,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP55",
                                    { 0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelM60 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelM60",
                                        { -0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM60",
                                        { -0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM60",
                                        { -0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM60",
                                        { -0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM60",
                                        { -0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM60",
                                        { -0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM60",
                                        { -0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM60",
                                        { -0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM60",
                                        { -0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM60",
                                        { -0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM60",
                                        { -0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM60",
                                        { -0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM60",
                                        { -0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM60",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM60",
                                        { 0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM60",
                                        { 0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM60",
                                        { 0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM60",
                                        { 0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM60",
                                        { 0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM60",
                                        { 0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM60",
                                        { 0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM60",
                                        { 0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM60",
                                        { 0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM60",
                                        { 0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM60",
                                        { 0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM60",
                                        { 0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM60",
                                        { 0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM60",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALM_1_60 {
                                type = "text";
                                source = "static";
                                text = -60;
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM60",
                                    { 0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM60",
                                    { 0.24250001,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM60",
                                    { 0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALM_2_60 {
                                type = "text";
                                source = "static";
                                text = -60;
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM60",
                                    { -0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM60",
                                    { -0.1675,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM60",
                                    { -0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelP60 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelP60",
                                        { -0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP60",
                                        { -0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP60",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelP60",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP60",
                                        { 0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP60",
                                        { 0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALP_1_60 {
                                type = "text";
                                source = "static";
                                text = "60";
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP60",
                                    { -0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP60",
                                    { -0.1675,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP60",
                                    { -0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALP_2_60 {
                                type = "text";
                                source = "static";
                                text = "60";
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP60",
                                    { 0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP60",
                                    { 0.24250001,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP60",
                                    { 0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelM65 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelM65",
                                        { -0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM65",
                                        { -0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM65",
                                        { -0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM65",
                                        { -0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM65",
                                        { -0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM65",
                                        { -0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM65",
                                        { -0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM65",
                                        { -0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM65",
                                        { -0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM65",
                                        { -0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM65",
                                        { -0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM65",
                                        { -0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM65",
                                        { -0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM65",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM65",
                                        { 0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM65",
                                        { 0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM65",
                                        { 0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM65",
                                        { 0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM65",
                                        { 0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM65",
                                        { 0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM65",
                                        { 0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM65",
                                        { 0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM65",
                                        { 0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM65",
                                        { 0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM65",
                                        { 0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM65",
                                        { 0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM65",
                                        { 0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM65",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALM_1_65 {
                                type = "text";
                                source = "static";
                                text = -65;
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM65",
                                    { 0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM65",
                                    { 0.24250001,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM65",
                                    { 0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALM_2_65 {
                                type = "text";
                                source = "static";
                                text = -65;
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM65",
                                    { -0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM65",
                                    { -0.1675,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM65",
                                    { -0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelP65 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelP65",
                                        { -0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP65",
                                        { -0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP65",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelP65",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP65",
                                        { 0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP65",
                                        { 0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALP_1_65 {
                                type = "text";
                                source = "static";
                                text = "65";
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP65",
                                    { -0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP65",
                                    { -0.1675,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP65",
                                    { -0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALP_2_65 {
                                type = "text";
                                source = "static";
                                text = "65";
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP65",
                                    { 0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP65",
                                    { 0.24250001,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP65",
                                    { 0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelM70 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelM70",
                                        { -0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM70",
                                        { -0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM70",
                                        { -0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM70",
                                        { -0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM70",
                                        { -0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM70",
                                        { -0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM70",
                                        { -0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM70",
                                        { -0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM70",
                                        { -0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM70",
                                        { -0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM70",
                                        { -0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM70",
                                        { -0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM70",
                                        { -0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM70",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM70",
                                        { 0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM70",
                                        { 0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM70",
                                        { 0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM70",
                                        { 0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM70",
                                        { 0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM70",
                                        { 0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM70",
                                        { 0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM70",
                                        { 0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM70",
                                        { 0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM70",
                                        { 0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM70",
                                        { 0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM70",
                                        { 0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM70",
                                        { 0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM70",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALM_1_70 {
                                type = "text";
                                source = "static";
                                text = -70;
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM70",
                                    { 0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM70",
                                    { 0.24250001,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM70",
                                    { 0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALM_2_70 {
                                type = "text";
                                source = "static";
                                text = -70;
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM70",
                                    { -0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM70",
                                    { -0.1675,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM70",
                                    { -0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelP70 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelP70",
                                        { -0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP70",
                                        { -0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP70",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelP70",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP70",
                                        { 0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP70",
                                        { 0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALP_1_70 {
                                type = "text";
                                source = "static";
                                text = "70";
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP70",
                                    { -0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP70",
                                    { -0.1675,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP70",
                                    { -0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALP_2_70 {
                                type = "text";
                                source = "static";
                                text = "70";
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP70",
                                    { 0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP70",
                                    { 0.24250001,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP70",
                                    { 0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelM75 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelM75",
                                        { -0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM75",
                                        { -0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM75",
                                        { -0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM75",
                                        { -0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM75",
                                        { -0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM75",
                                        { -0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM75",
                                        { -0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM75",
                                        { -0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM75",
                                        { -0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM75",
                                        { -0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM75",
                                        { -0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM75",
                                        { -0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM75",
                                        { -0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM75",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM75",
                                        { 0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM75",
                                        { 0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM75",
                                        { 0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM75",
                                        { 0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM75",
                                        { 0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM75",
                                        { 0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM75",
                                        { 0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM75",
                                        { 0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM75",
                                        { 0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM75",
                                        { 0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM75",
                                        { 0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM75",
                                        { 0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM75",
                                        { 0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM75",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALM_1_75 {
                                type = "text";
                                source = "static";
                                text = -75;
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM75",
                                    { 0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM75",
                                    { 0.24250001,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM75",
                                    { 0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALM_2_75 {
                                type = "text";
                                source = "static";
                                text = -75;
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM75",
                                    { -0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM75",
                                    { -0.1675,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM75",
                                    { -0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelP75 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelP75",
                                        { -0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP75",
                                        { -0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP75",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelP75",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP75",
                                        { 0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP75",
                                        { 0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALP_1_75 {
                                type = "text";
                                source = "static";
                                text = "75";
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP75",
                                    { -0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP75",
                                    { -0.1675,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP75",
                                    { -0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALP_2_75 {
                                type = "text";
                                source = "static";
                                text = "75";
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP75",
                                    { 0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP75",
                                    { 0.24250001,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP75",
                                    { 0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelM80 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelM80",
                                        { -0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM80",
                                        { -0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM80",
                                        { -0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM80",
                                        { -0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM80",
                                        { -0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM80",
                                        { -0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM80",
                                        { -0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM80",
                                        { -0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM80",
                                        { -0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM80",
                                        { -0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM80",
                                        { -0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM80",
                                        { -0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM80",
                                        { -0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM80",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM80",
                                        { 0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM80",
                                        { 0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM80",
                                        { 0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM80",
                                        { 0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM80",
                                        { 0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM80",
                                        { 0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM80",
                                        { 0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM80",
                                        { 0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM80",
                                        { 0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM80",
                                        { 0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM80",
                                        { 0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM80",
                                        { 0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM80",
                                        { 0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM80",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALM_1_80 {
                                type = "text";
                                source = "static";
                                text = -80;
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM80",
                                    { 0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM80",
                                    { 0.24250001,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM80",
                                    { 0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALM_2_80 {
                                type = "text";
                                source = "static";
                                text = -80;
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM80",
                                    { -0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM80",
                                    { -0.1675,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM80",
                                    { -0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelP80 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelP80",
                                        { -0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP80",
                                        { -0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP80",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelP80",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP80",
                                        { 0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP80",
                                        { 0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALP_1_80 {
                                type = "text";
                                source = "static";
                                text = "80";
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP80",
                                    { -0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP80",
                                    { -0.1675,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP80",
                                    { -0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALP_2_80 {
                                type = "text";
                                source = "static";
                                text = "80";
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP80",
                                    { 0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP80",
                                    { 0.24250001,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP80",
                                    { 0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelM85 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelM85",
                                        { -0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM85",
                                        { -0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM85",
                                        { -0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM85",
                                        { -0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM85",
                                        { -0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM85",
                                        { -0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM85",
                                        { -0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM85",
                                        { -0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM85",
                                        { -0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM85",
                                        { -0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM85",
                                        { -0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM85",
                                        { -0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM85",
                                        { -0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM85",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM85",
                                        { 0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM85",
                                        { 0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM85",
                                        { 0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM85",
                                        { 0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM85",
                                        { 0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM85",
                                        { 0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM85",
                                        { 0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM85",
                                        { 0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM85",
                                        { 0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM85",
                                        { 0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM85",
                                        { 0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM85",
                                        { 0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM85",
                                        { 0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM85",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALM_1_85 {
                                type = "text";
                                source = "static";
                                text = -85;
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM85",
                                    { 0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM85",
                                    { 0.24250001,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM85",
                                    { 0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALM_2_85 {
                                type = "text";
                                source = "static";
                                text = -85;
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM85",
                                    { -0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM85",
                                    { -0.1675,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM85",
                                    { -0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelP85 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelP85",
                                        { -0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP85",
                                        { -0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP85",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelP85",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP85",
                                        { 0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP85",
                                        { 0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALP_1_85 {
                                type = "text";
                                source = "static";
                                text = "85";
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP85",
                                    { -0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP85",
                                    { -0.1675,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP85",
                                    { -0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALP_2_85 {
                                type = "text";
                                source = "static";
                                text = "85";
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP85",
                                    { 0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP85",
                                    { 0.24250001,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP85",
                                    { 0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelM90 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelM90",
                                        { -0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM90",
                                        { -0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM90",
                                        { -0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM90",
                                        { -0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM90",
                                        { -0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM90",
                                        { -0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM90",
                                        { -0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM90",
                                        { -0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM90",
                                        { -0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM90",
                                        { -0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM90",
                                        { -0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM90",
                                        { -0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM90",
                                        { -0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM90",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM90",
                                        { 0.18000001,-0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM90",
                                        { 0.18000001,-0.0049999999 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM90",
                                        { 0.175,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM90",
                                        { 0.16500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM90",
                                        { 0.155,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM90",
                                        { 0.145,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM90",
                                        { 0.13500001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM90",
                                        { 0.125,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM90",
                                        { 0.115,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM90",
                                        { 0.105,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM90",
                                        { 0.094999999,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM90",
                                        { 0.085000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelM90",
                                        { 0.075000003,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelM90",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALM_1_90 {
                                type = "text";
                                source = "static";
                                text = -90;
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM90",
                                    { 0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM90",
                                    { 0.24250001,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM90",
                                    { 0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALM_2_90 {
                                type = "text";
                                source = "static";
                                text = -90;
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelM90",
                                    { -0.205,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelM90",
                                    { -0.1675,-0.039999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelM90",
                                    { -0.205,0.0099999998 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class LevelP90 {
                                type = "line";
                                width = 1.2;
                                points[] = 
                                {

                                    {
                                        "LevelP90",
                                        { -0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP90",
                                        { -0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP90",
                                        { -0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },
                                    {},

                                    {
                                        "LevelP90",
                                        { 0.064999998,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP90",
                                        { 0.18000001,0 },
                                        1,
                                        "ForwardVec",
                                        1
                                    },

                                    {
                                        "LevelP90",
                                        { 0.18000001,0.015 },
                                        1,
                                        "ForwardVec",
                                        1
                                    }
                                };
                            };
                            class VALP_1_90 {
                                type = "text";
                                source = "static";
                                text = "90";
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP90",
                                    { -0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP90",
                                    { -0.1675,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP90",
                                    { -0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                            class VALP_2_90 {
                                type = "text";
                                source = "static";
                                text = "90";
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "LevelP90",
                                    { 0.205,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                right[] = 
                                {
                                    "LevelP90",
                                    { 0.24250001,-0.02 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                                down[] = 
                                {
                                    "LevelP90",
                                    { 0.205,0.029999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                };
                            };
                        };
                    };
                    class Horizon_data {
                        class hAlpha {
                            class aText {
                                type = "text";
                                source = "static";
                                text = "a";
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "horizon_data",
                                    { 0,0 },
                                    1
                                };
                                right[] = 
                                {
                                    "horizon_data",
                                    { 0.022500001,0 },
                                    1
                                };
                                down[] = 
                                {
                                    "horizon_data",
                                    { 0,0.029999999 },
                                    1
                                };
                            };
                            class aValue {
                                type = "text";
                                source = "static";
                                text = "3.8";
                                align = "center";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "horizon_data",
                                    { 0.035,0 },
                                    1
                                };
                                right[] = 
                                {
                                    "horizon_data",
                                    { 0.055500001,0 },
                                    1
                                };
                                down[] = 
                                {
                                    "horizon_data",
                                    { 0.035,0.029999999 },
                                    1
                                };
                            };
                        };
                        class hMach {
                            class mText {
                                type = "text";
                                source = "static";
                                text = "M";
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "horizon_data",
                                    { 0,0.030999999 },
                                    1
                                };
                                right[] = 
                                {
                                    "horizon_data",
                                    { 0.022500001,0.030999999 },
                                    1
                                };
                                down[] = 
                                {
                                    "horizon_data",
                                    { 0,0.061000001 },
                                    1
                                };
                            };
                            class mValue {
                                type = "text";
                                source = "speed";
                                align = "center";
                                scale = 1;
                                sourceScale = 0.28799999;
                                pos[] = 
                                {
                                    "horizon_data",
                                    { 0.035,0.030999999 },
                                    1
                                };
                                right[] = 
                                {
                                    "horizon_data",
                                    { 0.055500001,0.030999999 },
                                    1
                                };
                                down[] = 
                                {
                                    "horizon_data",
                                    { 0.035,0.061000001 },
                                    1
                                };
                            };
                        };
                        class hGforce {
                            class gText {
                                type = "text";
                                source = "static";
                                text = "G";
                                align = "right";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "horizon_data",
                                    { 0,0.061999999 },
                                    1
                                };
                                right[] = 
                                {
                                    "horizon_data",
                                    { 0.022500001,0.061999999 },
                                    1
                                };
                                down[] = 
                                {
                                    "horizon_data",
                                    { 0,0.092 },
                                    1
                                };
                            };
                            class gValue {
                                type = "text";
                                source = "static";
                                text = "1.4";
                                align = "center";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "horizon_data",
                                    { 0.035,0.061999999 },
                                    1
                                };
                                right[] = 
                                {
                                    "horizon_data",
                                    { 0.055500001,0.061999999 },
                                    1
                                };
                                down[] = 
                                {
                                    "horizon_data",
                                    { 0.035,0.092 },
                                    1
                                };
                            };
                        };
                    };
                    class speedIndicator {
                        class indicatorBox {
                            type = "line";
                            width = 4;
                            points[] = 
                            {

                                {
                                    "speedIndicator",
                                    { 0,0 },
                                    1
                                },

                                {
                                    "speedIndicator",
                                    { 0,0.048960801 },
                                    1
                                },

                                {
                                    "speedIndicator",
                                    { 0.068834998,0.048960801 },
                                    1
                                },

                                {
                                    "speedIndicator",
                                    { 0.068834998,0 },
                                    1
                                },

                                {
                                    "speedIndicator",
                                    { 0,0 },
                                    1
                                }
                            };
                        };
                        class speedKnots {
                            type = "text";
                            source = "speed";
                            scale = 1;
                            sourceScale = 1.94384;
                            align = "center";
                            pos[] = 
                            {
                                "speedIndicator",
                                { 0.034417499,-0.00385 },
                                1
                            };
                            right[] = 
                            {
                                "speedIndicator",
                                { 0.069417499,-0.00385 },
                                1
                            };
                            down[] = 
                            {
                                "speedIndicator",
                                { 0.034417499,0.046149999 },
                                1
                            };
                        };
                        class text_GS {
                            type = "text";
                            source = "static";
                            text = "GS";
                            scale = 1;
                            sourceScale = 1;
                            align = "right";
                            pos[] = 
                            {
                                "speedIndicator",
                                { 0,0.050299998 },
                                1
                            };
                            right[] = 
                            {
                                "speedIndicator",
                                { 0.022500001,0.050299998 },
                                1
                            };
                            down[] = 
                            {
                                "speedIndicator",
                                { 0,0.080300003 },
                                1
                            };
                        };
                        class speedGround {
                            type = "text";
                            source = "speed";
                            scale = 1;
                            sourceScale = 1.94384;
                            align = "left";
                            pos[] = 
                            {
                                "speedIndicator",
                                { 0.068834998,0.050299998 },
                                1
                            };
                            right[] = 
                            {
                                "speedIndicator",
                                { 0.091334999,0.050299998 },
                                1
                            };
                            down[] = 
                            {
                                "speedIndicator",
                                { 0.068834998,0.080300003 },
                                1
                            };
                        };
                    };
                    class altIndicator {
                        class indicatorBox {
                            type = "line";
                            width = 4;
                            points[] = 
                            {

                                {
                                    "altIndicator",
                                    { 0,0 },
                                    1
                                },

                                {
                                    "altIndicator",
                                    { 0,0.048960801 },
                                    1
                                },

                                {
                                    "altIndicator",
                                    { -0.087191001,0.048960801 },
                                    1
                                },

                                {
                                    "altIndicator",
                                    { -0.087191001,0 },
                                    1
                                },

                                {
                                    "altIndicator",
                                    { 0,0 },
                                    1
                                }
                            };
                        };
                        class altFeet {
                            type = "text";
                            source = "altitudeASL";
                            scale = 1;
                            sourceScale = 3.2808399;
                            align = "center";
                            pos[] = 
                            {
                                "altIndicator",

                                {
                                    -0.0435955,
                                    "-0.00385)"
                                },
                                1
                            };
                            right[] = 
                            {
                                "altIndicator",

                                {
                                    "-0.0085955)",
                                    -0.00385
                                },
                                1
                            };
                            down[] = 
                            {
                                "altIndicator",
                                { -0.0435955,0.046149999 },
                                1
                            };
                        };
                        class text_R {
                            type = "text";
                            source = "static";
                            text = "R";
                            scale = 1;
                            sourceScale = 1;
                            align = "right";
                            pos[] = 
                            {
                                "altIndicator",
                                { -0.077191003,0.050299998 },
                                1
                            };
                            right[] = 
                            {
                                "altIndicator",
                                { -0.054691002,0.050299998 },
                                1
                            };
                            down[] = 
                            {
                                "altIndicator",
                                { -0.077191003,0.080300003 },
                                1
                            };
                        };
                        class altRadar {
                            type = "text";
                            source = "altitudeAGL";
                            scale = 1;
                            sourceScale = 3.2808399;
                            align = "left";
                            pos[] = 
                            {
                                "altIndicator",

                                {
                                    -0.0099999998,
                                    "0.0353  + (    0.03     / 2))"
                                },
                                1
                            };
                            right[] = 
                            {
                                "altIndicator",
                                { 0.0125,0.050299998 },
                                1
                            };
                            down[] = 
                            {
                                "altIndicator",
                                { -0.0099999998,0.080300003 },
                                1
                            };
                        };
                    };
                    class emconIndicator {
                        class emcon {
                            type = "text";
                            source = "static";
                            text = "EMCON";
                            align = "center";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = 
                            {
                                "emconIndicator",
                                { 0,0 },
                                1
                            };
                            right[] = 
                            {
                                "emconIndicator",

                                {
                                    "0.03*0.75",
                                    0
                                },
                                1
                            };
                            down[] = 
                            {
                                "emconIndicator",
                                { 0,0.029999999 },
                                1
                            };
                        };
                        class emconValue {
                            type = "text";
                            source = "static";
                            text = "DL 014";
                            align = "center";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = 
                            {
                                "emconIndicator",
                                { 0,0.029999999 },
                                1
                            };
                            right[] = 
                            {
                                "emconIndicator",

                                {
                                    "0.03*0.75",
                                    0.029999999
                                },
                                1
                            };
                            down[] = 
                            {
                                "emconIndicator",

                                {
                                    0,
                                    "0.03*2"
                                },
                                1
                            };
                        };
                    };
                    class weaponIndicator {
                        class aamCondition {
                            condition = "AAmissile";
                            class aamIndicator {
                                type = "text";
                                source = "static";
                                text = "AA";
                                align = "center";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "weaponIndicator",
                                    { 0,0 },
                                    1
                                };
                                right[] = 
                                {
                                    "weaponIndicator",

                                    {
                                        "0.03*0.75",
                                        0
                                    },
                                    1
                                };
                                down[] = 
                                {
                                    "weaponIndicator",
                                    { 0,0.029999999 },
                                    1
                                };
                            };
                        };
                        class agmCondition {
                            condition = "ATmissile";
                            class agmIndicator {
                                type = "text";
                                source = "static";
                                text = "AG";
                                align = "center";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "weaponIndicator",
                                    { 0,0 },
                                    1
                                };
                                right[] = 
                                {
                                    "weaponIndicator",

                                    {
                                        "0.03*0.75",
                                        0
                                    },
                                    1
                                };
                                down[] = 
                                {
                                    "weaponIndicator",
                                    { 0,0.029999999 },
                                    1
                                };
                            };
                        };
                        class bombCondition {
                            condition = "bomb";
                            class bombIndicator {
                                type = "text";
                                source = "static";
                                text = "AG";
                                align = "center";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "weaponIndicator",
                                    { 0,0 },
                                    1
                                };
                                right[] = 
                                {
                                    "weaponIndicator",

                                    {
                                        "0.03*0.75",
                                        0
                                    },
                                    1
                                };
                                down[] = 
                                {
                                    "weaponIndicator",
                                    { 0,0.029999999 },
                                    1
                                };
                            };
                        };
                        class weaponValue {
                            type = "text";
                            source = "weapon";
                            align = "center";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = 
                            {
                                "weaponIndicator",
                                { 0,0.029999999 },
                                1
                            };
                            right[] = 
                            {
                                "weaponIndicator",

                                {
                                    "0.03*0.75",
                                    0.029999999
                                },
                                1
                            };
                            down[] = 
                            {
                                "weaponIndicator",

                                {
                                    0,
                                    "0.03 * 2"
                                },
                                1
                            };
                        };
                        class armIndicator {
                            type = "text";
                            source = "static";
                            text = "ARM";
                            align = "center";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = 
                            {
                                "weaponIndicator",

                                {
                                    0,
                                    "0.03 * 2"
                                },
                                1
                            };
                            right[] = 
                            {
                                "weaponIndicator",

                                {
                                    "0.03*0.75",
                                    "0.03 * 2"
                                },
                                1
                            };
                            down[] = 
                            {
                                "weaponIndicator",

                                {
                                    0,
                                    "0.03 * 3"
                                },
                                1
                            };
                        };
                    };
                    class planeHeading {
                        class headingScroll {
                            type = "scale";
                            horizontal = 1;
                            source = "heading";
                            sourceScale = 0.1;
                            width = 2;
                            top = 0;
                            center = 0.5;
                            bottom = 1;
                            lineXleft = 0.105;
                            lineYright = 0.094999999;
                            lineXleftMajor = 0.11;
                            lineYrightMajor = 0.090000004;
                            majorLineEach = 2;
                            numberEach = 2;
                            step = 0.5;
                            stepsize = 0.1;
                            align = "center";
                            scale = 1;
                            pos[] = { 0,0.045000002 };
                            right[] = { 0.029999999,0.045000002 };
                            down[] = { 0,0.085000001 };
                        };
                        class headingIndicator {
                            type = "text";
                            source = "heading";
                            sourceScale = 1;
                            scale = 1;
                            align = "center";
                            pos[] = 
                            {
                                { 0.5,0.0049999999 },
                                1
                            };
                            right[] = 
                            {
                                { 0.52999997,0.0049999999 },
                                1
                            };
                            down[] = 
                            {
                                { 0.5,0.045000002 },
                                1
                            };
                        };
                        class headingIndicatorBox {
                            type = "line";
                            width = 2;
                            points[] = 
                            {

                                {
                                    { 0.477,0.0099999998 },
                                    1
                                },

                                {
                                    { 0.523,0.0099999998 },
                                    1
                                },

                                {
                                    { 0.523,0.041000001 },
                                    1
                                },

                                {
                                    { 0.477,0.041000001 },
                                    1
                                },

                                {
                                    { 0.477,0.0099999998 },
                                    1
                                },
                                {},

                                {
                                    { 0.493,0.041000001 },
                                    1
                                },

                                {
                                    { 0.5,0.050000001 },
                                    1
                                },

                                {
                                    { 0.50700003,0.041000001 },
                                    1
                                }
                            };
                        };
                        class waypointMarkers {
                            class waypointIndicator68 {
                                class value_1_group68 {
                                    clipTL[] = { 0.523,0 };
                                    clipBR[] = { 1,1 };
                                    class value_168 {
                                        type = "text";
                                        source = "static";
                                        text = 68;
                                        sourceScale = 1;
                                        scale = 1;
                                        align = "center";
                                        pos[] = 
                                        {
                                            "waypointIndicator",
                                            { 1.86,0.0049999999 },
                                            1
                                        };
                                        right[] = 
                                        {
                                            "waypointIndicator",
                                            { 1.89,0.0049999999 },
                                            1
                                        };
                                        down[] = 
                                        {
                                            "waypointIndicator",
                                            { 1.86,0.045000002 },
                                            1
                                        };
                                    };
                                };
                                class value_2_group68 {
                                    clipTL[] = { 0,0 };
                                    clipBR[] = { 0.477,1 };
                                    class value_268 {
                                        type = "text";
                                        source = "static";
                                        text = 68;
                                        sourceScale = 1;
                                        scale = 1;
                                        align = "center";
                                        pos[] = 
                                        {
                                            "waypointIndicator",
                                            { -5.3400002,0.0049999999 },
                                            1
                                        };
                                        right[] = 
                                        {
                                            "waypointIndicator",
                                            { -5.3099999,0.0049999999 },
                                            1
                                        };
                                        down[] = 
                                        {
                                            "waypointIndicator",
                                            { -5.3400002,0.045000002 },
                                            1
                                        };
                                    };
                                };
                                class value_3_group68 {
                                    clipTL[] = { 0,0 };
                                    clipBR[] = { 0.477,1 };
                                    class value_368 {
                                        type = "text";
                                        source = "static";
                                        text = 68;
                                        sourceScale = 1;
                                        scale = 1;
                                        align = "center";
                                        pos[] = 
                                        {
                                            "waypointIndicator",
                                            { 1.86,0.0049999999 },
                                            1
                                        };
                                        right[] = 
                                        {
                                            "waypointIndicator",
                                            { 1.89,0.0049999999 },
                                            1
                                        };
                                        down[] = 
                                        {
                                            "waypointIndicator",
                                            { 1.86,0.045000002 },
                                            1
                                        };
                                    };
                                };
                                class value_4_group68 {
                                    clipTL[] = { 0.523,0 };
                                    clipBR[] = { 1,1 };
                                    class value_468 {
                                        type = "text";
                                        source = "static";
                                        text = 68;
                                        sourceScale = 1;
                                        scale = 1;
                                        align = "center";
                                        pos[] = 
                                        {
                                            "waypointIndicator",
                                            { -5.3400002,0.0049999999 },
                                            1
                                        };
                                        right[] = 
                                        {
                                            "waypointIndicator",
                                            { -5.3099999,0.0049999999 },
                                            1
                                        };
                                        down[] = 
                                        {
                                            "waypointIndicator",
                                            { -5.3400002,0.045000002 },
                                            1
                                        };
                                    };
                                };
                                class box68 {
                                    type = "line";
                                    width = 2;
                                    points[] = 
                                    {

                                        {
                                            "waypointIndicator",
                                            { 1.883,0.041000001 },
                                            1
                                        },

                                        {
                                            "waypointIndicator",
                                            { 1.837,0.041000001 },
                                            1
                                        },
                                        {},

                                        {
                                            "waypointIndicator",
                                            { 1.86,0.041000001 },
                                            1
                                        },

                                        {
                                            "waypointIndicator",
                                            { 1.86,0.052999999 },
                                            1
                                        },
                                        {},

                                        {
                                            "waypointIndicator",
                                            { -5.3169999,0.041000001 },
                                            1
                                        },

                                        {
                                            "waypointIndicator",
                                            { -5.3629999,0.041000001 },
                                            1
                                        },
                                        {},

                                        {
                                            "waypointIndicator",
                                            { -5.3400002,0.041000001 },
                                            1
                                        },

                                        {
                                            "waypointIndicator",
                                            { -5.3400002,0.052999999 },
                                            1
                                        }
                                    };
                                };
                            };
                            class waypointIndicator279 {
                                class value_1_group279 {
                                    clipTL[] = { 0.523,0 };
                                    clipBR[] = { 1,1 };
                                    class value_1279 {
                                        type = "text";
                                        source = "static";
                                        text = 279;
                                        sourceScale = 1;
                                        scale = 1;
                                        align = "center";
                                        pos[] = 
                                        {
                                            "waypointIndicator",
                                            { 6.0799999,0.0049999999 },
                                            1
                                        };
                                        right[] = 
                                        {
                                            "waypointIndicator",
                                            { 6.1100001,0.0049999999 },
                                            1
                                        };
                                        down[] = 
                                        {
                                            "waypointIndicator",
                                            { 6.0799999,0.045000002 },
                                            1
                                        };
                                    };
                                };
                                class value_2_group279 {
                                    clipTL[] = { 0,0 };
                                    clipBR[] = { 0.477,1 };
                                    class value_2279 {
                                        type = "text";
                                        source = "static";
                                        text = 279;
                                        sourceScale = 1;
                                        scale = 1;
                                        align = "center";
                                        pos[] = 
                                        {
                                            "waypointIndicator",
                                            { -1.12,0.0049999999 },
                                            1
                                        };
                                        right[] = 
                                        {
                                            "waypointIndicator",
                                            { -1.09,0.0049999999 },
                                            1
                                        };
                                        down[] = 
                                        {
                                            "waypointIndicator",
                                            { -1.12,0.045000002 },
                                            1
                                        };
                                    };
                                };
                                class value_3_group279 {
                                    clipTL[] = { 0,0 };
                                    clipBR[] = { 0.477,1 };
                                    class value_3279 {
                                        type = "text";
                                        source = "static";
                                        text = 279;
                                        sourceScale = 1;
                                        scale = 1;
                                        align = "center";
                                        pos[] = 
                                        {
                                            "waypointIndicator",
                                            { 6.0799999,0.0049999999 },
                                            1
                                        };
                                        right[] = 
                                        {
                                            "waypointIndicator",
                                            { 6.1100001,0.0049999999 },
                                            1
                                        };
                                        down[] = 
                                        {
                                            "waypointIndicator",
                                            { 6.0799999,0.045000002 },
                                            1
                                        };
                                    };
                                };
                                class value_4_group279 {
                                    clipTL[] = { 0.523,0 };
                                    clipBR[] = { 1,1 };
                                    class value_4279 {
                                        type = "text";
                                        source = "static";
                                        text = 279;
                                        sourceScale = 1;
                                        scale = 1;
                                        align = "center";
                                        pos[] = 
                                        {
                                            "waypointIndicator",
                                            { -1.12,0.0049999999 },
                                            1
                                        };
                                        right[] = 
                                        {
                                            "waypointIndicator",
                                            { -1.09,0.0049999999 },
                                            1
                                        };
                                        down[] = 
                                        {
                                            "waypointIndicator",
                                            { -1.12,0.045000002 },
                                            1
                                        };
                                    };
                                };
                                class box279 {
                                    type = "line";
                                    width = 2;
                                    points[] = 
                                    {

                                        {
                                            "waypointIndicator",
                                            { 6.1030002,0.041000001 },
                                            1
                                        },

                                        {
                                            "waypointIndicator",
                                            { 6.0570002,0.041000001 },
                                            1
                                        },
                                        {},

                                        {
                                            "waypointIndicator",
                                            { 6.0799999,0.041000001 },
                                            1
                                        },

                                        {
                                            "waypointIndicator",
                                            { 6.0799999,0.052999999 },
                                            1
                                        },
                                        {},

                                        {
                                            "waypointIndicator",
                                            { -1.097,0.041000001 },
                                            1
                                        },

                                        {
                                            "waypointIndicator",
                                            { -1.143,0.041000001 },
                                            1
                                        },
                                        {},

                                        {
                                            "waypointIndicator",
                                            { -1.12,0.041000001 },
                                            1
                                        },

                                        {
                                            "waypointIndicator",
                                            { -1.12,0.052999999 },
                                            1
                                        }
                                    };
                                };
                            };
                        };
                    };
                    class bankRot {
                        class bankRotScale {
                            type = "line";
                            width = 2;
                            points[] = 
                            {

                                {
                                    "ForwardVec",
                                    1,
                                    "planeW",
                                    { -0.259808,0.208049 },
                                    1
                                },

                                {
                                    "ForwardVec",
                                    1,
                                    "planeW",
                                    { -0.26846799,0.214983 },
                                    1
                                },
                                {},

                                {
                                    "ForwardVec",
                                    1,
                                    "planeW",
                                    { -0.22294299,0.27842301 },
                                    1
                                },

                                {
                                    "ForwardVec",
                                    1,
                                    "planeW",
                                    { -0.23037501,0.28770399 },
                                    1
                                },
                                {},

                                {
                                    "ForwardVec",
                                    1,
                                    "planeW",
                                    { -0.17633601,0.33662999 },
                                    1
                                },

                                {
                                    "ForwardVec",
                                    1,
                                    "planeW",
                                    { -0.18221299,0.34785101 },
                                    1
                                },
                                {},

                                {
                                    "ForwardVec",
                                    1,
                                    "planeW",
                                    { -0.122021,0.380124 },
                                    1
                                },

                                {
                                    "ForwardVec",
                                    1,
                                    "planeW",
                                    { -0.12608799,0.39279401 },
                                    1
                                },
                                {},

                                {
                                    "ForwardVec",
                                    1,
                                    "planeW",
                                    { -0.0623735,0.407004 },
                                    1
                                },

                                {
                                    "ForwardVec",
                                    1,
                                    "planeW",
                                    { -0.064452603,0.420571 },
                                    1
                                },
                                {},

                                {
                                    "ForwardVec",
                                    1,
                                    "planeW",
                                    { 0.0623735,0.407004 },
                                    1
                                },

                                {
                                    "ForwardVec",
                                    1,
                                    "planeW",
                                    { 0.064452603,0.420571 },
                                    1
                                },
                                {},

                                {
                                    "ForwardVec",
                                    1,
                                    "planeW",
                                    { 0.122021,0.380124 },
                                    1
                                },

                                {
                                    "ForwardVec",
                                    1,
                                    "planeW",
                                    { 0.12608799,0.39279401 },
                                    1
                                },
                                {},

                                {
                                    "ForwardVec",
                                    1,
                                    "planeW",
                                    { 0.17633601,0.33662999 },
                                    1
                                },

                                {
                                    "ForwardVec",
                                    1,
                                    "planeW",
                                    { 0.18221299,0.34785101 },
                                    1
                                },
                                {},

                                {
                                    "ForwardVec",
                                    1,
                                    "planeW",
                                    { 0.22294299,0.27842301 },
                                    1
                                },

                                {
                                    "ForwardVec",
                                    1,
                                    "planeW",
                                    { 0.23037501,0.28770399 },
                                    1
                                },
                                {},

                                {
                                    "ForwardVec",
                                    1,
                                    "planeW",
                                    { 0.259808,0.208049 },
                                    1
                                },

                                {
                                    "ForwardVec",
                                    1,
                                    "planeW",
                                    { 0.26846799,0.214983 },
                                    1
                                }
                            };
                        };
                        class bankRotZero {
                            type = "text";
                            source = "static";
                            text = "0";
                            align = "center";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = 
                            {
                                "ForwardVec",
                                1,
                                "planeW",
                                { 0,0.40000001 },
                                1
                            };
                            right[] = 
                            {
                                "ForwardVec",
                                1,
                                "planeW",
                                { 0.029999999,0.40000001 },
                                1
                            };
                            down[] = 
                            {
                                "ForwardVec",
                                1,
                                "planeW",
                                { 0,0.435 },
                                1
                            };
                        };
                        class HorizonBankRot {
                            type = "line";
                            width = 2;
                            points[] = 
                            {

                                {
                                    "HorizonBankRot",
                                    { 0,-0.28999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                },

                                {
                                    "HorizonBankRot",
                                    { 0.0099999998,-0.27268001 },
                                    1,
                                    "ForwardVec",
                                    1
                                },

                                {
                                    "HorizonBankRot",
                                    { -0.0099999998,-0.27268001 },
                                    1,
                                    "ForwardVec",
                                    1
                                },

                                {
                                    "HorizonBankRot",
                                    { 0,-0.28999999 },
                                    1,
                                    "ForwardVec",
                                    1
                                }
                            };
                        };
                    };
                    class bottomIndicator {
                        class stallIndicator {
                            condition = "stall";
                            blinkingPattern[] = { 0.2,0.2 };
                            blinkingStartsOn = 1;
                            class stallText {
                                type = "text";
                                source = "static";
                                text = "STALL";
                                align = "center";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "bottomIndicator",
                                    { 0,-0.15000001 },
                                    1
                                };
                                right[] = 
                                {
                                    "bottomIndicator",
                                    { 0.037500001,-0.15000001 },
                                    1
                                };
                                down[] = 
                                {
                                    "bottomIndicator",

                                    {
                                        0,
                                        "0.05 - 0.15"
                                    },
                                    1
                                };
                            };
                        };
                        class gearIndicator {
                            condition = "ils";
                            class gearText {
                                type = "text";
                                source = "static";
                                text = "GEAR";
                                align = "center";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "bottomIndicator",
                                    { -0.1,0 },
                                    1
                                };
                                right[] = 
                                {
                                    "bottomIndicator",
                                    { -0.07,0 },
                                    1
                                };
                                down[] = 
                                {
                                    "bottomIndicator",
                                    { -0.1,0.039999999 },
                                    1
                                };
                            };
                        };
                        class flapsIndicator {
                            condition = "flaps";
                            class flapsText {
                                type = "text";
                                source = "static";
                                text = "FLAPS";
                                align = "center";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "bottomIndicator",
                                    { 0.1,0 },
                                    1
                                };
                                right[] = 
                                {
                                    "bottomIndicator",
                                    { 0.13,0 },
                                    1
                                };
                                down[] = 
                                {
                                    "bottomIndicator",
                                    { 0.1,0.039999999 },
                                    1
                                };
                            };
                        };
                        class gunIndicator {
                            condition = "mgun";
                            class gunText {
                                type = "text";
                                source = "static";
                                text = "GUN";
                                align = "center";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = 
                                {
                                    "bottomIndicator",
                                    { 0,0 },
                                    1
                                };
                                right[] = 
                                {
                                    "bottomIndicator",
                                    { 0.029999999,0 },
                                    1
                                };
                                down[] = 
                                {
                                    "bottomIndicator",
                                    { 0,0.039999999 },
                                    1
                                };
                            };
                        };
                        class noGunIndicator {
                            condition = "ils";
                            class conditionGun {
                                condition = "mgun";
                                class noGunCross {
                                    type = "line";
                                    width = 2;
                                    points[] = 
                                    {

                                        {
                                            "bottomIndicator",
                                            { -0.029999999,0.0099999998 },
                                            1
                                        },

                                        {
                                            "bottomIndicator",
                                            { 0.029999999,0.035 },
                                            1
                                        },
                                        {},

                                        {
                                            "bottomIndicator",
                                            { 0.029999999,0.0099999998 },
                                            1
                                        },

                                        {
                                            "bottomIndicator",
                                            { -0.029999999,0.035 },
                                            1
                                        }
                                    };
                                };
                            };
                        };
                    };
                    class MGun {
                        condition = "mgun";
                        class Circle {
                            type = "line";
                            width = 1;
                            points[] = 
                            {

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0,0.069349498 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0.012941,0.066986501 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0.025,0.0600584 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0.0353553,0.049037501 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0.043301299,0.034674801 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0.048296299,0.017949 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0.050000001,-3.0313601e-009 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0.048296299,-0.017949 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0.043301299,-0.034674801 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0.0353553,-0.049037501 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0.025,-0.0600584 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0.0129409,-0.066986501 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -4.3711399e-009,-0.069349498 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -0.012941,-0.066986501 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -0.025,-0.0600584 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -0.0353553,-0.049037501 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -0.043301299,-0.034674801 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -0.048296299,-0.017949 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -0.050000001,8.2698498e-010 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -0.048296299,0.017949 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -0.043301299,0.034674801 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -0.0353553,0.049037501 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -0.025,0.060058501 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -0.0129409,0.066986501 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 8.7422798e-009,0.069349498 },
                                    1
                                },
                                {},

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0,-0.00050000002 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0,0.00050000002 },
                                    1
                                },
                                {},

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0.050000001,0 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0.059999999,0 },
                                    1
                                },
                                {},

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0.025,0.0600584 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0.029999999,0.072070099 },
                                    1
                                },
                                {},

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0.043301299,0.034674801 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0.0519615,0.041609701 },
                                    1
                                },
                                {},

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",

                                    {
                                        0,
                                        "0.05/(0.2113243709752/0.2931048289372)"
                                    },
                                1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",

                                    {
                                        0,
                                        "0.06/(0.2113243709752/0.2931048289372)"
                                    },
                                1
                                },
                                {},

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0.043301299,-0.034674801 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0.0519615,-0.041609701 },
                                    1
                                },
                                {},

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0.025,-0.0600584 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0.029999999,-0.072070099 },
                                    1
                                },
                                {},

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -0.050000001,0 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -0.059999999,0 },
                                    1
                                },
                                {},

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -0.025,-0.0600584 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -0.029999999,-0.072070099 },
                                    1
                                },
                                {},

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -0.043301299,-0.034674801 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -0.0519615,-0.041609701 },
                                    1
                                },
                                {},

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",

                                    {
                                        0,
                                        "-0.05 / (0.2113243709752/0.2931048289372)"
                                    },
                                1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",

                                    {
                                        0,
                                        "-0.06 / (0.2113243709752/0.2931048289372)"
                                    },
                                1
                                },
                                {},

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -0.043301299,0.034674801 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -0.0519615,0.041609701 },
                                    1
                                },
                                {},

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -0.025,0.060058501 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -0.029999999,0.072070099 },
                                    1
                                }
                            };
                        };
                    };
                    class PlaneW_AA {
                        condition = "AAmissile";
                        class reticle {
                            type = "line";
                            width = 2;
                            points[] = 
                            {

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0,0.208049 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0.038822901,0.200959 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0.075000003,0.18017501 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0.106066,0.147113 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0.129904,0.104024 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0.144889,0.053846899 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0.15000001,-9.0940899e-009 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0.144889,-0.053846899 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0.129904,-0.104024 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0.106066,-0.147113 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0.075000003,-0.18017501 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 0.0388228,-0.200959 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -1.31134e-008,-0.208049 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -0.038822901,-0.200959 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -0.075000003,-0.18017501 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -0.106066,-0.147113 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -0.129904,-0.104024 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -0.144889,-0.053846899 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -0.15000001,2.4809499e-009 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -0.144889,0.053847 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -0.129904,0.104024 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -0.106066,0.147113 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -0.075000003,0.18017501 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { -0.0388228,0.200959 },
                                    1
                                },

                                {
                                    "weaponAim",
                                    1,
                                    "ForwardVec",
                                    { 2.62268e-008,0.208049 },
                                    1
                                },
                                {},

                                {
                                    "ForwardVec",
                                    1,
                                    "PlaneW",
                                    1,
                                    { -0.039999999,0 },
                                    1
                                },

                                {
                                    "ForwardVec",
                                    1,
                                    "PlaneW",
                                    1,
                                    { -0.016000001,0 },
                                    1
                                },

                                {
                                    "ForwardVec",
                                    1,
                                    "PlaneW",
                                    1,
                                    { -0.0080000004,0.02 },
                                    1
                                },

                                {
                                    "ForwardVec",
                                    1,
                                    "PlaneW",
                                    1,
                                    { 0,0 },
                                    1
                                },

                                {
                                    "ForwardVec",
                                    1,
                                    "PlaneW",
                                    1,
                                    { 0.0080000004,0.02 },
                                    1
                                },

                                {
                                    "ForwardVec",
                                    1,
                                    "PlaneW",
                                    1,
                                    { 0.016000001,0 },
                                    1
                                },

                                {
                                    "ForwardVec",
                                    1,
                                    "PlaneW",
                                    1,
                                    { 0.039999999,0 },
                                    1
                                }
                            };
                        };
                    };
                    class PlaneW_bomb {
                        condition = "bomb";
                        class reticle {
                            type = "line";
                            width = 2;
                            points[] = 
                            {

                                {
                                    "ForwardVec",
                                    1,
                                    "PlaneW",
                                    1,
                                    { -0.039999999,0 },
                                    1
                                },

                                {
                                    "ForwardVec",
                                    1,
                                    "PlaneW",
                                    1,
                                    { -0.016000001,0 },
                                    1
                                },

                                {
                                    "ForwardVec",
                                    1,
                                    "PlaneW",
                                    1,
                                    { -0.0080000004,0.02 },
                                    1
                                },

                                {
                                    "ForwardVec",
                                    1,
                                    "PlaneW",
                                    1,
                                    { 0,0 },
                                    1
                                },

                                {
                                    "ForwardVec",
                                    1,
                                    "PlaneW",
                                    1,
                                    { 0.0080000004,0.02 },
                                    1
                                },

                                {
                                    "ForwardVec",
                                    1,
                                    "PlaneW",
                                    1,
                                    { 0.016000001,0 },
                                    1
                                },

                                {
                                    "ForwardVec",
                                    1,
                                    "PlaneW",
                                    1,
                                    { 0.039999999,0 },
                                    1
                                }
                            };
                        };
                    };
                    class PlaneW_AT {
                        condition = "ATmissile";
                        class reticle {
                            type = "line";
                            width = 2;
                            points[] = 
                            {

                                {
                                    "ForwardVec",
                                    1,
                                    "PlaneW",
                                    1,
                                    { -0.039999999,0 },
                                    1
                                },

                                {
                                    "ForwardVec",
                                    1,
                                    "PlaneW",
                                    1,
                                    { -0.016000001,0 },
                                    1
                                },

                                {
                                    "ForwardVec",
                                    1,
                                    "PlaneW",
                                    1,
                                    { -0.0080000004,0.02 },
                                    1
                                },

                                {
                                    "ForwardVec",
                                    1,
                                    "PlaneW",
                                    1,
                                    { 0,0 },
                                    1
                                },

                                {
                                    "ForwardVec",
                                    1,
                                    "PlaneW",
                                    1,
                                    { 0.0080000004,0.02 },
                                    1
                                },

                                {
                                    "ForwardVec",
                                    1,
                                    "PlaneW",
                                    1,
                                    { 0.016000001,0 },
                                    1
                                },

                                {
                                    "ForwardVec",
                                    1,
                                    "PlaneW",
                                    1,
                                    { 0.039999999,0 },
                                    1
                                }
                            };
                        };
                    };
                    class RadarTargets {
                        type = "radar";
                        pos0[] = { 0.5,0.5 };
                        pos10[] = { 0.71132398,0.79310501 };
                        width = 2;
                        points[] = 
                        {

                            {
                                "ForwardVec",
                                { -0.02,-0.027739801 },
                                1
                            },

                            {
                                "ForwardVec",
                                { 0.02,-0.027739801 },
                                1
                            },

                            {
                                "ForwardVec",
                                { 0.02,0.027739801 },
                                1
                            },

                            {
                                "ForwardVec",
                                { -0.02,0.027739801 },
                                1
                            },

                            {
                                "ForwardVec",
                                { -0.02,-0.027739801 },
                                1
                            }
                        };
                    };
                };
                helmetMountedDisplay = 1;
                helmetPosition[] = { -0.039999999,0.029999999,0.1 };
                helmetRight[] = { 0.079999998,0,0 };
                helmetDown[] = { 0,-0.059999999,0 };
            };
        };
        class UserActions {
            class F35_afterburner_on {
                displayName = "<t color = '#fb7904'>Afterburner On</t>";
                priority = 100;
                shortcut = "User1";
                condition = "((this animationPhase ""switch_afterburner"") isEqualTo 0) && (player in this) && (isEngineOn this) && (speed this > 5)";
                statement = QUOTE([this] call FUNC(afterburner););
                position = "pilotcontrol";
                radius = 10;
                onlyforplayer = 1;
                showWindow = 0;
                hideOnUse = 1;
            };            
            class F35_afterburner_off {
                displayName = "<t color = '#fb7904'>Afterburner Off</t>";
                shortcut = "User1";
                condition = QUOTE(((this animationPhase 'switch_afterburner') isEqualTo 1) && player in this);
                statement = "this animate [""switch_afterburner"",0];";
                position = "pilotcontrol";
                radius = 10;
                priority = 99;
                onlyforplayer = 1;
                showWindow = 0;
                hideOnUse = 1;
            };
            class DAS_ON {
                displayName = "(DAS) AESA OFF";
                position = "pilotcontrol";
                radius = 15;
                shortcut = "User4";
                condition = "player isEqualTo driver this && (This getVariable [""USAF_DAS_ENABLED"",false])";
                statement = "[this] execVM ""\usaf_F35a\scripts\DAS.sqf"";";
                onlyforplayer = "False";
            };
            class DAS_OFF: DAS_ON {
                displayName = "(DAS) AESA ON";
                position = "pilotcontrol";
                radius = 15;
                shortcut = "User4";
                condition = "player isEqualTo driver this && !(this getVariable [""USAF_DAS_ENABLED"",false])";
                statement = "[this] execVM ""\usaf_F35a\scripts\DAS.sqf"";";
                onlyforplayer = "False";
            };
            class VRD_ON {
                displayName = "(DAS) Spherical Coverage OFF";
                position = "pilotcontrol";
                radius = 15;
                shortcut = "User4";
                condition = "player isEqualTo driver this && (This getVariable [""USAF_VRD_ENABLED"",false])";
                statement = "[this] execVM ""\usaf_F35a\scripts\VRD.sqf"";";
                onlyforplayer = "False";
            };
            class VRD_OFF: VRD_ON {
                displayName = "(DAS) Spherical Coverage ON";
                position = "pilotcontrol";
                radius = 15;
                shortcut = "User4";
                condition = "player isEqualTo driver this && !(this getVariable [""USAF_VRD_ENABLED"",false])";
                statement = "[this] execVM ""\usaf_F35a\scripts\VRD.sqf"";";
                onlyforplayer = "False";
            };
            class ECM {
                displayName = "(EWS) Electronic Warfare System";
                onlyforplayer = 0;
                position = "pilotcontrol";
                radius = 25;
                showWindow = 0;
                condition = "player isEqualTo driver this";
                statement = "[this] execvm ""\USAF_F35A\scripts\ECM_INIT.sqf""";
            };
            class Eject {
                displayName = "<t color = '#ff0000'>Eject</t>";
                priority = 50;
                shortcut = "Eject";
                condition = "player isEqualTo driver this";
                statement = QUOTE([this] call FUNC(ejection));
                position = "pilotcontrol";
                radius = 10;
                onlyforplayer = 1;
                showWindow = 0;
                hideOnUse = 1;
            };
            class service_menu {
                displayName = "<t color = '#739eff'>Service Menu</t>";
                position = "pilotcontrol";
                onlyforplayer = 1;
                showWindow = 0;
                shortcut = "User4";
                priority = 100;
                hideOnUse = 1;
                radius = 5;
                condition = QUOTE([this] call FUNC(serviceCheck));
                statement = QUOTE(call FUNC(loadoutMenu));
            };
            class USAF_F35A_GPS_targeting_system {
                displayName = "(EOTS) Electro-Optical Targeting System";
                shortcut = "User3";
                position = "pilotcontrol";
                radius = 10;
                onlyforplayer = 1;
                showWindow = 0;
                hideOnUse = 1;
                condition = "player in this and ((""USAF_F35A_8Rnd_GBU53_M"" in magazines this) or (""USAF_1Rnd_GBU31"" in magazines this) or (""USAF_1Rnd_GBU32"" in magazines this) or (""USAF_1Rnd_AGM154A"" in magazines this) or (""USAF_1Rnd_GBU12"" in magazines this))";
                statement = "[this] spawn USAF_F35A_fnc_USAF_F35A_GPS_TARGETING_INIT";
            };
            class SEAD {
                displayName = "(SEAD) System";
                onlyforplayer = 0;
                position = "pilotcontrol";
                radius = 25;
                showWindow = 0;
                condition = "('USAF_1Rnd_AGM88' in magazines this)";
                statement = QUOTE([this] call FUNC(AGM88));
            };
            class formationLights {
                displayName = "Formation Lights On";
                position = "pilot";
                priority = 4;
                radius = 20;
                showWindow = 0;
                hideOnUse = 1;
                onlyforplayer = 1;
                condition = "player in this and this animationPhase ""FormationLights"" > 0.5";
                statement = "this animate [""FormationLights"",0];";
            };
            class unFormationLights {
                displayName = "Formation Lights Off";
                position = "pilot";
                priority = 4;
                radius = 20;
                showWindow = 0;
                hideOnUse = 1;
                onlyforplayer = 1;
                condition = "player in this and this animationPhase ""FormationLights"" < 0.5";
                statement = "this animate [""FormationLights"",1];";
            };
            delete retractrefueling;
            delete extendrefueling;
        };
        class EventHandlers {
            class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
        };
    };
    class USAF_F35A_ejection_seat: Motorcycle {
        faction = "CUP_B_GB";
        crew = "B_pilot_F";
        scope = 1;
        scopeCurator = 0;
        explosionEffect = "";
        class DestructionEffects {};
        destrType = "";
        hullDamageCauseExplosion = 0;
        class EventHandlers {
            class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
        };
    };
    class Missilecart_base: StaticAmmocart {
        faction = "CUP_B_GB";
        crew = "";
        editorSubcategory = QEGVAR(common,objects);
        class EventHandlers {
            class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
        };
    };
    class USAF_editorMissileObjects;
    class USAF_MK77: USAF_editorMissileObjects {
        icon = "";
    };
    class LaserTarget;
    class USAF_F35A_GPSTarget: LaserTarget {
        scope = 2;
        scopeCurator = 2;
        faction = "CUP_B_GB";
        editorSubcategory = QEGVAR(common,objects);
    };
    class Plane;
    class CUP_F35B_base: Plane {
        maxSpeed = 1930;
        envelope[] = { 0, 1.75, 5.9, 7, 9.8, 10.3, 10.5, 10.9, 9.2, 7.8, 5, 3.8, 0.5, 0 };
        aileronSensitivity=1.2;
        armor = 90;
        damageResistance = 0.004;
        unitInfoType = "Rsc_UKSF_F35_Limited";
        unitInfoTypeLite = "Rsc_UKSF_F35_Limited";
        attenuationEffectType = "PlaneAttenuation";
        soundGetIn[] = { "A3\sounds_F\air\Plane_Fighter_03\getin", 0.562341, 1 };
        soundGetOut[] = { "A3\sounds_F\air\Plane_Fighter_03\getout", 0.562341, 1, 40 };
        soundDammage[] = { "", 0.562341, 1 };
        soundEngineOnInt[] = { QPATHTOF(data\sound\f_startup_int.wss), 1.0, 1.0 };
        soundEngineOnExt[] = { QPATHTOF(data\sound\f_enginestart_ext.wss), 15, 1.0, 700 };
        soundEngineOffInt[] = { QPATHTOF(data\sound\f_shutdown_int.wss), 1.0, 1.0 };
        soundEngineOffExt[] = { QPATHTOF(data\sound\f_shutdown_ext.wss), 10, 1.0, 500 };
        soundLocked[] = { "\A3\sounds_F\weapons\Rockets\locked_1", 0.1, 1 };
        soundIncommingMissile[] = { "\A3\sounds_F\weapons\Rockets\locked_3", 0.1, 1.5 };
        soundGearUp[] = { "A3\sounds_F_EPC\CAS_02\gear_up", 0.794328, 1.0, 150 };
        soundGearDown[] = { "A3\sounds_F_EPC\CAS_02\gear_down", 0.794328, 1.0, 150 };
        soundFlapsUp[] = { "A3\sounds_F_EPC\CAS_02\Flaps_Up", 0.630957, 1.0, 100 };
        soundFlapsDown[] = { "A3\sounds_F_EPC\CAS_02\Flaps_Down", 0.630957, 1.0, 100 };
        class sounds {
            class EngineLowOut {
                sound[] = { QPATHTOF(data\sound\f_engine_ext.wss), 12, 1.0, 1250 };
                frequency = "1.0 min (rpm + 0.5)";
                volume = "engineOn*camPos*(thrust factor[1.0, 1.0])*(thrust factor[1.0, 0.3])";
                cone[] = { 3.0, 3.92, 1.9, 0.5 };
            };
            class EngineHighOut {
                sound[] = { QPATHTOF(data\sound\ext_low_var1.wss), 20, 1.0, 3500 };
                frequency = "1";
                volume = "engineOn*camPos*(speed factor [50,100])";
                cone[] = { 3.14, 3.92, 2.0, 0.5 };
            };
            class ForsageOut {
                sound[] = { QPATHTOF(data\sound\forsagevar4.wss), 17, 0.99, 2500 };
                frequency = "1";
                volume = "engineOn*camPos*(thrust factor[0.6, 1.0])";
                cone[] = { 3.14, 3.92, 2.0, 0.5 };
            };
            class ActuatorForsageOut {
                sound[] = { QPATHTOF(data\sound\actuatorforsage.wss), 16, 0.99, 400 };
                frequency = "1";
                volume = "engineOn*camPos*(thrust factor[0.6, 1.0])";
                cone[] = { 3.14, 3.92, 2.0, 0.5 };
            };
            class WindNoiseOut {
                sound[] = { QPATHTOF(data\sound\f_windnoise_ext.wss), 0.562341, 1.0, 150 };
                frequency = "(0.1+(1.2*(speed factor[1, 150])))";
                volume = "camPos*(speed factor[1, 150])";
            };
            class DistantPlaneOut {
                sound[] = { QPATHTOF(data\sound\16_distant.wss), 12, 1.0, 5000 };
                frequency = "1";
                volume = "engineOn*camPos*(thrust factor[0.6, 1.0])";
                cone[] = { 3.14, 3.92, 2.0, 0.5 };
            };
            class EngineLowIn {
                sound[] = { QPATHTOF(data\sound\f_engine_int.wss), db2, 1.0 };
                frequency = "1.0 min (rpm + 0.5)";
                volume = "(1-camPos)*(rpm factor[0.85, 1.0])";
            };
            class EngineHighIn {
                sound[] = { QPATHTOF(data\sound\f_forsage_int.wss), db2, 1.2 };
                frequency = "1";
                volume = "(1-camPos)*(rpm factor[0.85, 1.0])";
            };
            class ForsageIn {
                sound[] = { QPATHTOF(data\sound\f_forsage_int.wss), db3, 1.0 };
                frequency = "1";
                volume = "(1-camPos)*(engineOn*(thrust factor[0.6, 1.0]))";
            };
            class WindNoiseIn {
                sound[] = { QPATHTOF(data\sound\f_windnoise_int.wss), db - 1, 1.0 };
                frequency = "(0.1+(1.2*(speed factor[1, 150])))";
                volume = "(1-camPos)*(speed factor[1, 150])";
            };
            class RainExt {
                sound[] = { "A3\sounds_F\vehicles\noises\rain1_ext", db5, 1.0, 100 };
                frequency = 1;
                volume = "camPos * rain * (speed factor[50, 0])";
            };
            class RainInt {
                sound[] = { "A3\sounds_F\vehicles\noises\rain1_int", db0, 1.0, 100 };
                frequency = 1;
                volume = "(1-camPos) * rain * (speed factor[50, 0])";
            };
        };
    };
};
