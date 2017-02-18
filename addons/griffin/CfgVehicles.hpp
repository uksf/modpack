class CfgVehicles {
    class Helicopter;
    class Helicopter_Base_F : Helicopter {
        class Turrets;
        class HitPoints;
    };
    class Helicopter_Base_H : Helicopter_Base_F {
        class AnimationSources;
        class Turrets : Turrets {
            class CopilotTurret;
        };
        class HitPoints : HitPoints {
            class HitGlass1;
            class HitGlass2;
            class HitGlass3;
            class HitGlass4;
            class HitGlass5;
        };
    };
    class UKSF_Griffin : Helicopter_Base_H {
        scope = 2;
        scopeCurator = 2;
        side = 1;
        //editorPreview = QPATHTOEF(common,data\previews\UKSF_Griffin.jpg);
        displayName = "Griffin HT1";
        faction = "CUP_B_GB";
        model = QPATHTOF(Bell412.p3d);
        picture = QPATHTOF(UI\icon_uh1n.paa);
        icon = QPATHTOF(UI\icon_uh1n.paa);
        unitInfoType = "Rsc_UKSF_Air_Special";
        unitInfoTypeLite = "Rsc_UKSF_Air_Special";
        availableForSupportTypes[] = {};
        cargoCanEject = 1;
        slingLoadMaxCargoMass = 2000;
        showNVGCargo[] = { 0,0,1 };
        destrType = "DestructWreck";
        driveOnComponent[] = { "Skids" };
        driverCanEject = 0;
        helmetMountedDisplay = 0;
        class MFD {};
        mapSize = 15;
        maxFordingDepth = 0.75;
        altFullForce = 4000;
        altNoForce = 6000;
        supplyRadius = 0;
        enableManualFire = 0;
        class RotorLibHelicopterProperties {
            RTDconfig = QPATHTOF(GriffinHT1.xml);
            defaultCollective = 0.68;
            autoHoverCorrection[] = { 4,-3.3,0 };
            maxTorque = 2700;
            stressDamagePerSec = 0.0033333332;
            retreatBladeStallWarningSpeed = 87.5;
            maxHorizontalStabilizerLeftStress = 10000;
            maxHorizontalStabilizerRightStress = 10000;
            maxVerticalStabilizerStress = 10000;
            horizontalWingsAngleCollMin = 0;
            horizontalWingsAngleCollMax = 0;
            maxMainRotorStress = 110000;
            maxTailRotorStress = 25000;
        };
        bodyFrictionCoef = 0.5;
        selectionHRotorStill = "velka vrtule staticka";
        selectionHRotorMove = "velka vrtule blur";
        selectionVRotorStill = "mala vrtule staticka";
        selectionVRotorMove = "mala vrtule blur";
        liftForceCoef = 1.5;
        cyclicAsideForceCoef = 3;
        cyclicForwardForceCoef = 2;
        mainRotorSpeed = 1.0;
        backRotorSpeed = 6.1;
        backRotorForceCoef = 1;
        mainBladeRadius = 7.5;
        tailBladeRadius = 1;
        fuelCapacity = 400;
        fuelConsumptionRate = 0.138;
        maxSpeed = 217;
        simulation = "helicopterrtd";
        armor = 40;
        weapons[] = {};
        magazines[] = {};
        class Turrets : Turrets {
            class CopilotTurret : CopilotTurret {
                isCopilot = 1;
                proxyIndex = 1;
                gunnerName = "Co-Pilot";
                gunnerAction = "UH1Y_Gunner02";
                gunnerInAction = "UH1Y_Gunner02";
                body = "";
                gun = "";
                animationSourceBody = "";
                animationSourceGun = "";
                outGunnerMayFire = 1;
                gunBeg = "gun_end";
                gunEnd = "gun_begin";
                memoryPointGun = "gun_end";
                commanding = -1;
                weapons[] = {
                };
                magazines[] = {
                };
                primaryGunner = 1;
                minElev = -80;
                maxElev = "+25";
                initElev = 0;
                minTurn = -100;
                maxTurn = 100;
                initTurn = 0;
                gunnerCompartments = "";
                startEngine = 0;
                soundServo[] = {
                    "db-40",
                    1
                };
                memoryPointsGetInGunner = "pos codriver";
                memoryPointsGetInGunnerDir = "pos codriver dir";
                selectionFireAnim = "";
                castGunnerShadow = 1;
                viewGunnerShadow = 1;
                showgunneroptics = 0;
            };
        };
        irScanRangeMin = 0;
        irScanRangeMax = 1000;
        nightVision = 1;
        memoryPointCM[] = {
            "flare_launcher1",
            "flare_launcher2"
        };
        memoryPointCMDir[] = {
            "flare_launcher1_dir",
            "flare_launcher2_dir"
        };
        radarType = 4;
        threat[] = { 0.80000001,1,0.60000002 };
        memoryPointsGetInCargo[] = {
            "pos codriver",
            "pos cargo"
        };
        memoryPointsGetInCargoDir[] = {
            "pos codriver dir",
            "pos cargo dir"
        };
        driverAction = "UH1Y_Pilot";
        driverInAction = "UH1Y_Pilot";
        cargoAction[] = {
            "UH1Y_Cargo02",
            "UH1Y_Cargo03",
            "UH1Y_Cargo03",
            "UH1Y_Cargo02",
            "UH1Y_Cargo01",
            "UH1Y_Cargo01",
            "UH1Y_Cargo01"
        };
        cargoIsCoDriver[] = { 0,0,0,0,0,0,0 };
        driverCanSee = 31;
        gunnerCanSee = 31;
        gunnerUsesPilotView = 1;
        gunnerOpticsModel = "";
        transportSoldier = 9;
        crew = "UKSF_Clan_P";
        transportAmmo = 0;
        transportMaxMagazines = 150;
        transportMaxWeapons = 30;
        initCargoAngleY = "+10";
        minCargoAngleY = -60;
        maxCargoAngleY = "+120";
        minFireTime = 30;
        driverCompartments = "Compartment1";
        cargoCompartments[] = {
            "Compartment2"
        };
        class Exhausts {
            class Exhaust1 {
                position = "exhaust1";
                direction = "exhaust1_dir";
                effect = "ExhaustsEffectHeliCom";
            };
            class Exhaust2 {
                position = "exhaust2";
                direction = "exhaust2_dir";
                effect = "ExhaustsEffectHeliCom";
            };
        };
        class MarkerLights {
            class WhiteStill {
                name = "bily pozicni";
                color[] = { 1,1,1 };
                ambient[] = { 0.1,0.1,0.1 };
                blinking = 1;
                intensity = 75;
                blinkingPattern[] = { 0.1,0.89999998 };
                blinkingPatternGuarantee = 0;
                drawLightSize = 0.2;
                drawLightCenterSize = 0.039999999;
            };
            class RedStill {
                name = "cerveny pozicni";
                color[] = { 0.80000001,0,0 };
                ambient[] = { 0.079999998,0,0 };
                intensity = 75;
                drawLight = 1;
                drawLightSize = 0.15000001;
                drawLightCenterSize = 0.039999999;
                activeLight = 0;
                blinking = 0;
                dayLight = 0;
                useFlare = 0;
            };
            class GreenStill {
                name = "zeleny pozicni";
                color[] = { 0,0.80000001,0 };
                ambient[] = { 0,0.079999998,0 };
                intensity = 75;
                drawLight = 1;
                drawLightSize = 0.15000001;
                drawLightCenterSize = 0.039999999;
                activeLight = 0;
                blinking = 0;
                dayLight = 0;
                useFlare = 0;
            };
        };
        class Reflectors {
            class Middle {
                color[] = { 7000,7500,10000,1 };
                ambient[] = { 100,100,100,0 };
                position = "svetlo";
                direction = "svetlo konec";
                hitpoint = "svetlo";
                selection = "svetlo";
                size = 1;
                innerAngle = 20;
                outerAngle = 60;
                coneFadeCoef = 10;
                intensity = 50;
                useFlare = 1;
                dayLight = 0;
                FlareSize = 6;
                class Attenuation {
                    start = 1;
                    constant = 0;
                    linear = 0;
                    quadratic = 4;
                };
            };
        };
        dammageHalf[] = {};
        dammageFull[] = {};
        class Damage {
            tex[] = {};
            mat[] = {
                QPATHTO_R(data\uh1y_sklo.rvmat),
                QPATHTO_R(data\uh1y_sklo_damage.rvmat),
                QPATHTO_R(data\uh1y_sklo_damage.rvmat),
                QPATHTO_R(data\uh1y_sklo_in.rvmat),
                QPATHTO_R(data\uh1y_sklo_in_damage.rvmat),
                QPATHTO_R(data\uh1y_sklo_in_damage.rvmat),
                QPATHTO_R(data\uh1y_ext.rvmat),
                QPATHTO_R(data\uh1y_ext_damage.rvmat),
                QPATHTO_R(data\uh1y_ext_destruct.rvmat),
                QPATHTO_R(data\uh1y_int.rvmat),
                QPATHTO_R(data\uh1y_int_damage.rvmat),
                QPATHTO_R(data\uh1y_int_destruct.rvmat),
                QPATHTO_R(data\launcher.rvmat),
                QPATHTO_R(data\launcher.rvmat),
                QPATHTO_R(data\launcher_destruct.rvmat),
                QPATHTO_R(data\uh1y_cockpit.rvmat),
                QPATHTO_R(data\uh1y_cockpit_damage.rvmat),
                QPATHTO_R(data\uh1y_cockpit_destruct.rvmat)
            };
        };
        attenuationEffectType = "HeliAttenuation";
        soundGetIn[] = { QPATHTOF(data\sounds\heli_door_01), "db-10", 1 };
        soundGetOut[] = { QPATHTOF(data\sounds\heli_door_01), "db-10", 1, 40 };
        soundDammage[] = { QPATHTOF(data\sounds\alarm_loop1), "db-10", 1 };
        soundEngineOnInt[] = { QPATHTOF(data\sounds\int\int-start-final), "db-7", 1 };
        soundEngineOnExt[] = { QPATHTOF(data\sounds\ext\ext-motor-start), "db-7", 1, 700 };
        soundEngineOffInt[] = { QPATHTOF(data\sounds\int\int-stop-final), "db-7", 1 };
        soundEngineOffExt[] = { QPATHTOF(data\sounds\ext\ext-motor-stop), "db-7", 1, 700 };
        landingSoundInt0[] = {"A3\Sounds_F\vehicles\air\noises\landing_skids_int1_open", 1, 1, 100};
        landingSoundInt1[] = {"A3\Sounds_F\vehicles\air\noises\landing_skids_int1_open", 1, 1, 100};
        landingSoundInt[] = {"landingSoundInt0", 0.5, "landingSoundInt1", 0.5};
        landingSoundOut0[] = {"A3\Sounds_F\vehicles\air\noises\landing_skids_ext1", 1.77828, 1, 100};
        landingSoundOut1[] = {"A3\Sounds_F\vehicles\air\noises\landing_skids_ext1", 1.77828, 1, 100};
        landingSoundOut[] = {"landingSoundOut0", 0.5, "landingSoundOut1", 0.5};
        class Sounds {
            class Engine {
                sound[] = { QPATHTOF(data\sounds\ext\ext-fly-mode2), "db8", 1, 800 };
                frequency = "rotorSpeed";
                volume = "camPos*((rotorSpeed-0.72)*4)";
            };
            class RotorLowOut {
                sound[] = { QPATHTOF(data\sounds\int\int-rotor-single5b), "db8", 2, 1400 };
                frequency = "rotorSpeed";
                volume = "camPos*(0 max (rotorSpeed-0.1))";
                cone[] = { 1.6,3.1400001,2,0.5 };
            };
            class RotorHighOut {
                sound[] = { QPATHTOF(data\sounds\int\int-rotor-single5a), "db8", 2, 1600 };
                frequency = "rotorSpeed";
                volume = "camPos*10*(0 max (rotorThrust-0.9))";
                cone[] = { 1.6,3.1400001,2,0.5 };
            };
            class EngineIn {
                sound[] = { QPATHTOF(data\sounds\int\int-fly-mode7), "db0", 1 };
                frequency = "rotorSpeed";
                volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
            };
            class RotorLowIn {
                sound[] = { QPATHTOF(data\sounds\int\int-rotor-single5b), "db0", 1 };
                frequency = "rotorSpeed";
                volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))";
            };
            class RotorHighIn {
                sound[] = { QPATHTOF(data\sounds\int\int-rotor-single5a), "db0", 1 };
                frequency = "rotorSpeed";
                volume = "(1-camPos)*3*(rotorThrust-0.9)";
            };
        };
        class HitPoints : HitPoints {
            class HitGlass1 : HitGlass1 { armor = 0.25; };
            class HitGlass2 : HitGlass2 { armor = 0.25; };
            class HitGlass3 : HitGlass3 { armor = 0.25; };
            class HitGlass4 : HitGlass4 { armor = 0.25; };
            class HitGlass5 : HitGlass5 { armor = 0.25; };
            class HitVRotor {
                armor = 1.3;
                material = 51;
                name = "mala vrtule";
                visual = "mala vrtule staticka";
                passThrough = 0.5;
                radius = 0.06;
                minimalHit = 0.05;
                explosionShielding = 6;
            };
            class HitHRotor {
                armor = 2.6;
                material = 51;
                name = "velka vrtule";
                visual = "velka vrtule staticka";
                passThrough = 0.5;
                radius = 0.4;
                minimalHit = 0.09;
                explosionShielding = 2.5;
            };
            class HitFuel {
                name = "fuel tanks";
                visual = "zbytek";
                armor = 0.7;
                explosionshielding = 2;
                material = 51;
                passthrough = 1;
                minimalHit = 0.05;
                radius = 0.25;
            };
            class HitPitotTube {
                name = "Pitot Tube";
                visual = "Pitot Tube";
                armor = 0.4;
                explosionshielding = 1;
                material = 51;
                passthrough = 1;
                minimalHit = 0.3;
            };
            class HitAvionics {
                name = "instruments";
                visual = "instruments";
                armor = 1.3;
                explosionShielding = 1.5;
                material = 51;
                passthrough = 0;
                minimalHit = 0.05;
                radius = 0.4;
            };
            class HitHull {
                name = "hull";
                visual = "zbytek";
                armor = 999;
                explosionshielding = 1;
                material = 51;
                passthrough = 1;
                minimalHit = 0.05;
                depends = "Total";
                radius = 0.01;
            };
            class HitEngine1 {
                armor = 0.7;
                name = "engine1";
                visual = "zbytek";
                explosionShielding = 3;
                material = 51;
                passthrough = 1;
                minimalHit = 0.1;
                radius = 0.35;
                convexComponent = "engine_1_hit";
            };
            class HitEngine2 {
                armor = 0.7;
                name = "engine2";
                visual = "zbytek";
                explosionShielding = 3;
                material = 51;
                passthrough = 1;
                minimalHit = 0.1;
                radius = 0.35;
                convexComponent = "engine_2_hit";
            };
            class HitEngine : HitEngine2 {
                armor = 999;
                name = "engine_hit";
                convexComponent = "engine_hit";
                depends = "0.5 * (HitEngine1 + HitEngine2)";
            };
            class HitTail {
                name = "tail boom";
                visual = "zbytek";
                armor = 0.6;
                explosionshielding = 1;
                material = 51;
                passthrough = 1;
                minimalHit = 0.4;
            };
        };
    };
};