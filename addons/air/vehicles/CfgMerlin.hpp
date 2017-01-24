//Merlin
class UK3CB_BAF_Merlin_HC3_Base;
class UK3CB_BAF_Merlin_HC3_Unarmed_Base : UK3CB_BAF_Merlin_HC3_Base {
    class Turrets;
};
class UK3CB_BAF_Merlin_HC3_Armed_Base : UK3CB_BAF_Merlin_HC3_Base {
    class Turrets;
};
class UK3CB_BAF_Merlin_HC3_18 : UK3CB_BAF_Merlin_HC3_Unarmed_Base {
    scope = 0;
    scopeCurator = 0;
    class Turrets : Turrets {
        class CopilotTurret;
        class CargoTurret_13;
        class CargoTurret_14;
    };
};
class UK3CB_BAF_Merlin_HC3_18_GPMG : UK3CB_BAF_Merlin_HC3_Armed_Base {
    scope = 0;
    scopeCurator = 0;
    class Turrets : Turrets {
        class RampGun;
        class DoorGunRight;
        class DoorGunLeft;
        class CopilotTurret;
    };
};
class UK3CB_BAF_Merlin_HC3_24 : UK3CB_BAF_Merlin_HC3_Unarmed_Base {
    scope = 0;
    scopeCUrator = 0;
};
class UK3CB_BAF_Merlin_HC3_32 : UK3CB_BAF_Merlin_HC3_Unarmed_Base {
    scope = 0;
    scopeCUrator = 0;
};
class UK3CB_BAF_Merlin_HC3_CSAR : UK3CB_BAF_Merlin_HC3_Armed_Base {
    scope = 0;
    scopeCUrator = 0;
};

class UKSF_Merlin : UK3CB_BAF_Merlin_HC3_18 {
    scope = 2;
    scopeCurator = 2;
    author = "UKSF";
    faction = "UKSF_Clan";
    displayname = "AW101 Merlin HC3";
    editorPreview = QPATHTOEF(common,data\previews\UKSF_Merlin.jpg);
    cyclicAsideForceCoef = 0.8;
    cyclicForwardForceCoef = 0.8;
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {
            lodTurnedIn = 1000;
            lodTurnedOut = 1000;
        };
        class CargoTurret_13 : CargoTurret_13 {};
        class CargoTurret_14 : CargoTurret_14 {};
    };
    #include "MFDMerlin.hpp"
    unitInfoType = "Rsc_UKSF_Air_Limited";
    unitInfoTypeLite = "Rsc_UKSF_Air_Limited";
    landingSoundInt0[]= { "A3\Sounds_F\vehicles\air\noises\landing_wheels_large_int1", 0.25, 1, 50 };
    landingSoundInt1[]= { "A3\Sounds_F\vehicles\air\noises\landing_wheels_large_int2", 0.25, 1, 50 };
    landingSoundInt[]= { "landingSoundInt0", 0.5, "landingSoundInt1", 0.5 };
    landingSoundOut0[]= { "A3\Sounds_F\vehicles\air\noises\landing_wheels_ext1", 0.4, 1, 50 };
    landingSoundOut1[]= { "A3\Sounds_F\vehicles\air\noises\landing_wheels_ext2", 0.4, 1, 50 };
    landingSoundOut[]= { "landingSoundOut0", 0.5, "landingSoundOut1", 0.5 };
};
class UKSF_Merlin_Armed : UK3CB_BAF_Merlin_HC3_18_GPMG {
    scope = 2;
    scopeCurator = 2;
    author = "UKSF";
    faction = "UKSF_Clan";
    displayname = "AW101 Merlin HC3 Armed";
    editorPreview = QPATHTOEF(common,data\previews\UKSF_Merlin.jpg);
    cyclicAsideForceCoef = 0.9;
    cyclicForwardForceCoef = 0.9;
    class Turrets : Turrets {
        class RampGun : RampGun {
            maxHorizontalRotSpeed = 2;
            maxVerticalRotSpeed = 2;
            maxElev = 30;
            maxOutElev = 20;
        };
        class CopilotTurret : CopilotTurret {
            lodTurnedIn = 1000;
            lodTurnedOut = 1000;
        };
        class DoorGunRight : DoorGunRight {};
        class DoorGunLeft : DoorGunLeft {};
    };
    #include "MFDMerlin.hpp"
    unitInfoType = "Rsc_UKSF_Air_Limited";
    unitInfoTypeLite = "Rsc_UKSF_Air_Limited";
    landingSoundInt0[]= { "A3\Sounds_F\vehicles\air\noises\landing_wheels_large_int1", 0.25, 1, 50 };
    landingSoundInt1[]= { "A3\Sounds_F\vehicles\air\noises\landing_wheels_large_int2", 0.25, 1, 50 };
    landingSoundInt[]= { "landingSoundInt0", 0.5, "landingSoundInt1", 0.5 };
    landingSoundOut0[]= { "A3\Sounds_F\vehicles\air\noises\landing_wheels_ext1", 0.4, 1, 50 };
    landingSoundOut1[]= { "A3\Sounds_F\vehicles\air\noises\landing_wheels_ext2", 0.4, 1, 50 };
    landingSoundOut[]= { "landingSoundOut0", 0.5, "landingSoundOut1", 0.5 };
};