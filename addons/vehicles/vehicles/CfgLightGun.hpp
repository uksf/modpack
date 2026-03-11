class StaticWeapon;
class StaticMortar : StaticWeapon {
    class Turrets;
};
class tbd_m119 : StaticMortar {
    class Turrets : Turrets {
        class MainTurret;
    };
};
class GVAR(L119) : tbd_m119 {
    faction = "CUP_B_GB";
    displayName = "L119";
    crew = "CUP_B_BAF_Soldier_MTP";
    mass = 2130;
    ace_artillerytables_showRangetable = 1;
    ace_artillerytables_showGunLaying = 1;
    ace_artillerytables_applyCorrections = 1;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            elevationMode = 1;
            initCamElev = 0;
            minCamElev = -35;
            maxCamElev = 35;
            minTurn = -180;
            maxTurn = 180;
            initTurn = 0;
            minElev = -5;
            maxElev = 80;
            initElev = 10;
            cameraDir = "look";
            discreteDistance[] = {};
            discreteDistanceCameraPoint[] = { "gunnerview" };
            gunnerForceOptics = 0;
            memoryPointGunnerOptics = "gunnerview";
            gunnerUsesPilotView = 0;
            class ViewOptics {
                initAngleX = 0;
                minAngleX = -30;
                maxAngleX = 30;
                initAngleY = 0;
                minAngleY = -10;
                maxAngleY = 100;
                initFov = 0.15;
                minFov = 0.0077778;
                maxFov = 0.15;
            };
        };
    };
};

// Test variant: L119 with Sholef (M4 Scorcher / MBT_01_arty_base_F) turret config
class GVAR(L119_test_sholef) : tbd_m119 {
    faction = "CUP_B_GB";
    displayName = "L119 (Sholef Turret Test)";
    crew = "CUP_B_BAF_Soldier_MTP";
    mass = 2130;
    ace_artillerytables_showRangetable = 1;
    ace_artillerytables_showGunLaying = 1;
    ace_artillerytables_applyCorrections = 1;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            // Sholef turret properties (flattened from MBT_01_arty_base_F MainTurret)
            gunnerForceOptics = 0;
            usePip = 2;
            selectionFireAnim = "";
            forceHideGunner = 0;
            gunnerAction = "M119pose"; // kept from tbd_m119 (Sholef uses Gunner_MBT_01_arty_F_out)
            gunnerInAction = "M119pose"; // kept compatible with L119 model
            gunnerGetInAction = "GetInLow";
            gunnerGetOutAction = "GetOutLow";
            LODTurnedIn = 1000;
            LODOpticsIn = 0;
            soundServo[] = {"\x\tbd_m119\addons\m119\tbd_m119\sounds\wheels.ogg", 1, 1, 20};
            soundServoVertical[] = {"\x\tbd_m119\addons\m119\tbd_m119\sounds\metalsqueal.ogg", 5, 1, 35};
            minElev = -5;
            maxElev = 80;
            initElev = 10;
            elevationMode = 3; // Sholef uses 3 (auto), L119 normally uses 1
            maxHorizontalRotSpeed = 0.78;
            maxVerticalRotSpeed = 0.26;
            memoryPointGunnerOptics = "gunnerview";
            cameraDir = "look";
            turretInfoType = "RscWeaponRangeArtilleryAuto";
            minTurn = -180;
            maxTurn = 180;
            initTurn = 0;
            initCamElev = 0;
            minCamElev = -35;
            maxCamElev = 35;
            gunnerUsesPilotView = 0;
            discreteDistance[] = {};
            discreteDistanceCameraPoint[] = { "gunnerview" };
            class OpticsIn {
                class Wide {
                    gunnerOpticsModel = "\A3\Weapons_F\acc\reticle_mortar_01_f.p3d";
                    initFov = 0.174;
                    minFov = 0.0077778;
                    maxFov = 0.14;
                    visionMode[] = {"Normal", "NVG"};
                };
            };
        };
    };
};

// Test variant: L119 with L16 / Mk6 Mortar (Mortar_01_base_F) turret config
class GVAR(L119_test_l16) : tbd_m119 {
    faction = "CUP_B_GB";
    displayName = "L119 (L16 Turret Test)";
    crew = "CUP_B_BAF_Soldier_MTP";
    mass = 2130;
    ace_artillerytables_showRangetable = 1;
    ace_artillerytables_showGunLaying = 1;
    ace_artillerytables_applyCorrections = 1;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            // Mortar_01_base_F (Mk6/L16) turret properties (flattened)
            gunnerAction = "M119pose"; // L16 uses UK3CB_BAF_L16_Gunner, base Mk6 uses Mortar_Gunner
            gunnergetInAction = "";
            gunnergetOutAction = "";
            elevationMode = 1;
            initCamElev = 0;
            minCamElev = -35;
            maxCamElev = 35;
            minTurn = -180;
            maxTurn = 180;
            initTurn = 0;
            cameraDir = "look";
            discreteDistance[] = {};
            discreteDistanceCameraPoint[] = { "eye" }; // Mk6 uses "eye" not "gunnerview"
            gunnerForceOptics = 0;
            memoryPointGunnerOptics = "eye"; // Mk6 uses "eye" not "gunnerview"
            gunnerOpticsModel = "\A3\Weapons_F\acc\reticle_Mortar_01_F.p3d";
            disableSoundAttenuation = 1;
            gunnerUsesPilotView = 0;
            minElev = -5;
            maxElev = 80;
            initElev = 10;
            ejectDeadGunner = 1;
            usepip = 2;
            turretInfoType = "ACE_Mk6_RscWeaponRangeArtillery";
            discreteDistanceInitIndex = 0;
            class ViewOptics {
                initAngleX = 0;
                minAngleX = -30;
                maxAngleX = 30;
                initAngleY = 0;
                minAngleY = -100; // Mk6 allows -100 to 100 (full vertical range)
                maxAngleY = 100;
                initFov = 0.174;
                minFov = 0.0077778;
                maxFov = 0.14;
                visionMode[] = {"Normal", "NVG"};
            };
        };
    };
};
