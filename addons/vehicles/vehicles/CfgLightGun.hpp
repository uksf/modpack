class StaticWeapon;
class StaticMortar : StaticWeapon {
    class Turrets {
        class MainTurret;
    };
};
class tbd_m119 : StaticMortar {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class ViewOptics;
        };
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
            class ViewOptics : ViewOptics {
                minAngleY = -100;
                maxAngleY = 100;
            };
        };
    };
};
