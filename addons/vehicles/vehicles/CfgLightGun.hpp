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
