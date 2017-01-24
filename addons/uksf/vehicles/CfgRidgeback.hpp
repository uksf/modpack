//Ridgeback
class Wheeled_APC_F;
class blx_ridgback_base : Wheeled_APC_F {
    class Turrets;
    class HitPoints;
};
class blx_ridgback_HMG_D : blx_ridgback_base {
    scope = 0;
    class Turrets : Turrets {
        class MainTurret;
        class ObsTurret;
    };
    class HitPoints : HitPoints {
        class HitLFWheel;
        class HitLBWheel;
        class HitRFWheel;
        class HitRBWheel;
        class HitGlass1;
        class HitGlass2;
        class HitGlass3;
        class HitGlass4;
        class HitGlass5;
    };
};
class blx_ridgback_HMG_W : blx_ridgback_HMG_D {
    scope = 0;
    class Turrets : Turrets {
        class MainTurret;
        class ObsTurret;
    };
    class HitPoints : HitPoints {
        class HitLFWheel;
        class HitLBWheel;
        class HitRFWheel;
        class HitRBWheel;
        class HitGlass1;
        class HitGlass2;
        class HitGlass3;
        class HitGlass4;
        class HitGlass5;
    };
};
class UKSF_ridgback_HMG_D : blx_ridgback_HMG_D {
    author = "UKSF";
    scope = 2;
    side = 1;
    faction = "UKSF_Clan";
    displayName = "Ridgeback Desert";
    editorPreview = QPATHTOEF(common,data\previews\UKSF_ridgback_HMG_D.jpg);
    displayNameshort = "Ridgeback";
    transportSoldier = 3;
    crew = "UKSF_Clan_R";
    typicalCargo[] = {
        "UKSF_Clan_R",
        "UKSF_Clan_R"
    };
    class TransportItems {
        class _xx_ACE_EarPlugs {
            count = 6;
            name = "ACE_EarPlugs";
        };
        class _xx_ACE_fieldDressing {
            name = "ACE_fieldDressing";
            count = 8;
        };
        class _xx_ACE_packingBandage {
            name = "ACE_packingBandage";
            count = 4;
        };
        class _xx_ACE_elasticBandage {
            name = "ACE_elasticBandage";
            count = 6;
        };
        class _xx_ACE_tourniquet {
            name = "ACE_tourniquet";
            count = 2;
        };
        class _xx_ACE_Morphine {
            name = "ACE_Morphine";
            count = 6;
        };
        class _xx_ACE_epinephrine {
            name = "ACE_epinephrine";
            count = 2;
        };
    };
    class TransportMagazines {
        class _xx_SmokeShell {
            magazine = "SmokeShell";
            count = 2;
        };
        class _xx_SmokeShellGreen {
            magazine = "SmokeShellGreen";
            count = 1;
        };
        class _xx_UK3CB_BAF_556_30Rnd {
            magazine = "UK3CB_BAF_556_30Rnd";
            count = 4;
        };
    };
    class TransportWeapons {
        class _xx_UK3CB_BAF_L85A2 {
            weapon = "UK3CB_BAF_L85A2";
            count = 2;
        };
    };
    armor = 5000;
    armorStructural = 700;
    explosionShielding=0.001;
    commanderCanSee = 31;
    gunnerCanSee = 4+8+16;
    driverCanSee = 2+8+16;
    class complexGearbox {
        GearboxRatios[]= { "R1", -10.094, "N", 0, "D1", 4.1820002, "D2", 2.3180001, "D3", 1.85, "D4", 1.65, "D5", 1.45 };
        TransmissionRatios[]= { "High", 5 };
        gearBoxMode="auto";
        moveOffGear=1;
        driveString="D";
        neutralString="N";
        reverseString="R";
    };
    torqueCurve[]= {
        {0,0},
        {0.178,0.5},
        {0.25,0.85},
        {0.4,0.9},
        {0.5,1},
        {0.725,0.95},
        {0.85,0.6},
        {1,0.3}
    };
    maxSpeed=90;
    enginePower=700;
    maxOmega=350;
    peakTorque=1600;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            soundAttenuationTurret = "";
            disableSoundAttenuation = 1;
        };
        class ObsTurret : ObsTurret {
            soundAttenuationTurret = "";
            disableSoundAttenuation = 1;
        };
    };
    class ACRE {
        class attenuation {
            class Compartment1  {
                Compartment1 = 1;
                Compartment2 = 1;
                Compartment3 = 1;
                Compartment4 = 1;
            };
            class Compartment2  {
                Compartment1 = 1;
                Compartment2 = 1;
                Compartment3 = 1;
                Compartment4 = 1;
            };
            class Compartment3  {
                Compartment1 = 1;
                Compartment2 = 1;
                Compartment3 = 1;
                Compartment4 = 1;
            };
            class Compartment4  {
                Compartment1 = 1;
                Compartment2 = 1;
                Compartment3 = 1;
                Compartment4 = 1;
            };
        };
        class CVC {
            hasCVC = true;
        };
    };
    class HitPoints: HitPoints {
        class HitLFWheel: HitLFWheel {
            armor=0.2;
            name="wheel_1_1_steering";
            visual="";
            passThrough=0;
            explosionShielding=0.6;
        };
        class HitLBWheel: HitLBWheel {
            armor=0.2;
            name="wheel_1_2_steering";
            visual="";
            passThrough=0;
            explosionShielding=0.6;
        };
        class HitRFWheel: HitRFWheel {
            armor=0.2;
            name="wheel_2_1_steering";
            visual="";
            passThrough=0;
            explosionShielding=0.6;
        };
        class HitRBWheel: HitRBWheel {
            armor=0.2;
            name="wheel_2_2_steering";
            visual="";
            passThrough=0;
            explosionShielding=0.6;
        };
        class HitHull {
            armor=0.5;
            material=-1;
            name="karoserie";
            visual="";
            passThrough=0;
            minimalHit=0.15;
            explosionShielding=0.01;
            radius=0.25;
        };
        class HitFuel {
            armor=0.5;
            material=-1;
            name="palivo";
            visual="";
            passThrough=0;
            minimalHit=0.15;
            explosionShielding=0.01;
            radius=0.25;
        };
        class HitEngine {
            armor=0.5;
            material=-1;
            name="engine";
            visual="";
            passThrough=0;
            minimalHit=0.15;
            explosionShielding=0.01;
            radius=0.25;
        };
        class HitGlass1: HitGlass1 {
            armor=0.5;
            explosionShielding=1;
        };
        class HitGlass2: HitGlass2 {
            armor=0.5;
            explosionShielding=1;
        };
        class HitGlass3: HitGlass3 {
            armor=0.5;
            explosionShielding=1;
        };
        class HitGlass4: HitGlass4 {
            armor=0.5;
            explosionShielding=1;
        };
        class HitGlass5: HitGlass5 {
            armor=0.5;
            explosionShielding=1;
        };
    };
};
class UKSF_ridgback_HMG_W : blx_ridgback_HMG_W {
    author = "UKSF";
    scope = 2;
    side = 1;
    faction = "UKSF_Clan";
    displayName = "Ridgeback Woodland";
    editorPreview = QPATHTOEF(common,data\previews\UKSF_ridgback_HMG_W.jpg);
    displayNameshort = "Ridgeback";
    transportSoldier = 3;
    crew = "UKSF_Clan_R";
    typicalCargo[] = {
        "UKSF_Clan_R",
        "UKSF_Clan_R"
    };
    class TransportItems {
        class _xx_ACE_EarPlugs {
            count = 6;
            name = "ACE_EarPlugs";
        };
        class _xx_ACE_fieldDressing {
            name = "ACE_fieldDressing";
            count = 8;
        };
        class _xx_ACE_packingBandage {
            name = "ACE_packingBandage";
            count = 4;
        };
        class _xx_ACE_elasticBandage {
            name = "ACE_elasticBandage";
            count = 6;
        };
        class _xx_ACE_quikClot {
            name = "ACE_quikClot";
            count = 4;
        };
        class _xx_ACE_tourniquet {
            name = "ACE_tourniquet";
            count = 2;
        };
        class _xx_ACE_Morphine {
            name = "ACE_Morphine";
            count = 6;
        };
        class _xx_ACE_epinephrine {
            name = "ACE_epinephrine";
            count = 2;
        };
    };
    class TransportMagazines {
        class _xx_SmokeShell {
            magazine = "SmokeShell";
            count = 2;
        };
        class _xx_SmokeShellGreen {
            magazine = "SmokeShellGreen";
            count = 1;
        };
        class _xx_UK3CB_BAF_556_30Rnd {
            magazine = "UK3CB_BAF_556_30Rnd";
            count = 4;
        };
    };
    class TransportWeapons {
        class _xx_UK3CB_BAF_L85A2 {
            weapon = "UK3CB_BAF_L85A2";
            count = 2;
        };
    };
    armor = 5000;
    armorStructural = 700;
    explosionShielding=0.001;
    commanderCanSee = 31;
    gunnerCanSee = 4+8+16;
    driverCanSee = 2+8+16;
    class complexGearbox {
        GearboxRatios[]= { "R1", -10.094, "N", 0, "D1", 4.1820002, "D2", 2.3180001, "D3", 1.85, "D4", 1.65, "D5", 1.45 };
        TransmissionRatios[]= { "High", 5 };
        gearBoxMode="auto";
        moveOffGear=1;
        driveString="D";
        neutralString="N";
        reverseString="R";
    };
    torqueCurve[]= {
        {0,0},
        {0.178,0.5},
        {0.25,0.85},
        {0.4,0.9},
        {0.5,1},
        {0.725,0.95},
        {0.85,0.6},
        {1,0.3}
    };
    maxSpeed=90;
    enginePower=700;
    maxOmega=350;
    peakTorque=1600;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            soundAttenuationTurret = "";
            disableSoundAttenuation = 1;
        };
        class ObsTurret : ObsTurret {
            soundAttenuationTurret = "";
            disableSoundAttenuation = 1;
        };
    };
    class ACRE {
        class attenuation {
            class Compartment1  {
                Compartment1 = 1;
                Compartment2 = 1;
                Compartment3 = 1;
                Compartment4 = 1;
            };
            class Compartment2  {
                Compartment1 = 1;
                Compartment2 = 1;
                Compartment3 = 1;
                Compartment4 = 1;
            };
            class Compartment3  {
                Compartment1 = 1;
                Compartment2 = 1;
                Compartment3 = 1;
                Compartment4 = 1;
            };
            class Compartment4  {
                Compartment1 = 1;
                Compartment2 = 1;
                Compartment3 = 1;
                Compartment4 = 1;
            };
        };
        class CVC {
            hasCVC = true;
        };
    };
    class HitPoints: HitPoints {
        class HitLFWheel: HitLFWheel {
            armor=0.2;
            name="wheel_1_1_steering";
            visual="";
            passThrough=0;
            explosionShielding=0.6;
        };
        class HitLBWheel: HitLBWheel {
            armor=0.2;
            name="wheel_1_2_steering";
            visual="";
            passThrough=0;
            explosionShielding=0.6;
        };
        class HitRFWheel: HitRFWheel {
            armor=0.2;
            name="wheel_2_1_steering";
            visual="";
            passThrough=0;
            explosionShielding=0.6;
        };
        class HitRBWheel: HitRBWheel {
            armor=0.2;
            name="wheel_2_2_steering";
            visual="";
            passThrough=0;
            explosionShielding=0.6;
        };
        class HitHull {
            armor=0.5;
            material=-1;
            name="karoserie";
            visual="";
            passThrough=0;
            minimalHit=0.15;
            explosionShielding=0.01;
            radius=0.25;
        };
        class HitFuel {
            armor=0.5;
            material=-1;
            name="palivo";
            visual="";
            passThrough=0;
            minimalHit=0.15;
            explosionShielding=0.01;
            radius=0.25;
        };
        class HitEngine {
            armor=0.5;
            material=-1;
            name="engine";
            visual="";
            passThrough=0;
            minimalHit=0.15;
            explosionShielding=0.01;
            radius=0.25;
        };
        class HitGlass1: HitGlass1 {
            armor=0.5;
            explosionShielding=1;
        };
        class HitGlass2: HitGlass2 {
            armor=0.5;
            explosionShielding=1;
        };
        class HitGlass3: HitGlass3 {
            armor=0.5;
            explosionShielding=1;
        };
        class HitGlass4: HitGlass4 {
            armor=0.5;
            explosionShielding=1;
        };
        class HitGlass5: HitGlass5 {
            armor=0.5;
            explosionShielding=1;
        };
    };
};
class UKSF_ridgback_AMB_D : UKSF_ridgback_HMG_D {
    scope = 2;
    side = 1;
    faction = "UKSF_Clan";
    displayName = "Ridgeback Ambulance (D)";
    editorPreview = QPATHTOEF(common,data\previews\UKSF_ridgback_AMB_D.jpg);
    attendant = 1;
    hiddenSelections[] = { "fx1" };
    hiddenSelectionsTextures[] = { QPATHTOF(data\tex3AMB_co.paa) };
};
class UKSF_ridgback_AMB_W : UKSF_ridgback_HMG_W {
    scope = 2;
    side = 1;
    faction = "UKSF_Clan";
    displayName = "Ridgeback Ambulance (W)";
    editorPreview = QPATHTOEF(common,data\previews\UKSF_ridgback_AMB_W.jpg);
    attendant = 1;
    hiddenSelections[] = { "fx1" };
    hiddenSelectionsTextures[] = { QPATHTOF(data\tex3WAMB_co.paa) };
};
