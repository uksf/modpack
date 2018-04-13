class CfgVehicles {
    class CargoNet_01_ammo_base_F;
    class UKSF_S_Empty: CargoNet_01_ammo_base_F {
        author = "UKSF";
        faction = "CUP_B_GB";
        scope = 2;
        scopeCurator = 2;
        editorCategory = QEGVAR(common,UKSF);
        editorSubcategory = QEGVAR(common,support);
        displayName = "Supply Crate (Empty)";
        editorPreview = QPATHTOEF(common,data\previews\UKSF_S_Empty.jpg);
        maximumLoad = 100000;
        ace_cargo_hasCargo = 1;
        ace_cargo_space = 20;
        hiddenSelectionsTextures[] = { "\A3\Weapons_F\Ammoboxes\Data\AmmoBox_CO.paa","\A3\Weapons_F\Ammoboxes\Data\AmmoBox_signs_CA.paa" };
        class TransportMagazines {};
        class TransportWeapons {};
        class TransportItems {};
        class TransportBackpacks {};
    };
    class UKSF_S_Ammo: UKSF_S_Empty {
        displayName = "Supply Crate (Ammo)";
        class TransportMagazines {
            class _xx_UK3CB_BAF_556_30Rnd {
                magazine = "UK3CB_BAF_556_30Rnd";
                count = 50;
            };
            class _xx_UK3CB_BAF_556_30Rnd_T {
                magazine = "UK3CB_BAF_556_30Rnd_T";
                count = 50;
            };
            class _xx_UK3CB_BAF_556_200Rnd {
                magazine = "UK3CB_BAF_556_200Rnd";
                count = 15;
            };
            class _xx_UK3CB_BAF_556_200Rnd_T {
                magazine = "UK3CB_BAF_556_200Rnd_T";
                count = 15;
            };
            class _xx_UK3CB_BAF_762_100Rnd {
                magazine = "UK3CB_BAF_762_100Rnd";
                count = 15;
            };
            class _xx_UK3CB_BAF_762_100Rnd_T {
                magazine = "UK3CB_BAF_762_100Rnd_T";
                count = 15;
            };
            class _xx_UK3CB_BAF_762_L42A1_20Rnd {
                magazine = "UK3CB_BAF_762_L42A1_20Rnd";
                count = 20;
            };
            class _xx_UK3CB_BAF_762_L42A1_20Rnd_T {
                magazine = "UK3CB_BAF_762_L42A1_20Rnd_T";
                count = 10;
            };
            class _xx_UK3CB_BAF_338_5Rnd {
                magazine = "UK3CB_BAF_338_5Rnd";
                count = 10;
            };
            class _xx_1Rnd_HE_Grenade_shell {
                magazine = "1Rnd_HE_Grenade_shell";
                count = 40;
            };
            class _xx_HandGrenade {
                magazine = "HandGrenade";
                count = 20;
            };
            class _xx_UK3CB_BAF_SmokeShell {
                magazine = "UK3CB_BAF_SmokeShell";
                count = 20;
            };
            class _xx_UK3CB_BAF_SmokeShellRed {
                magazine = "UK3CB_BAF_SmokeShellRed";
                count = 20;
            };
            class _xx_UK3CB_BAF_SmokeShellGreen {
                magazine = "UK3CB_BAF_SmokeShellGreen";
                count = 20;
            };
        };
        class TransportWeapons {
            class _xx_UK3CB_BAF_NLAW_Launcher {
                weapon = "UK3CB_BAF_NLAW_Launcher";
                count = 5;
            };
            class _xx_UK3CB_BAF_AT4_CS_AT_Launcher {
                weapon = "UK3CB_BAF_AT4_CS_AT_Launcher";
                count = 5;
            };
            class _xx_UK3CB_BAF_Javelin_Slung_Tube {
                weapon = "UK3CB_BAF_Javelin_Slung_Tube";
                count = 5;
            };
        };
    };
    class UKSF_S_Medic: UKSF_S_Empty {
        displayName = "Supply Crate (Medical)";
        class TransportItems {
            class _xx_ACE_packingBandage {
                name = "ACE_packingBandage";
                count = 50;
            };
            class _xx_ACE_elasticBandage {
                name = "ACE_elasticBandage";
                count = 50;
            };
            class _xx_ACE_quikclot {
                name = "ACE_quikclot";
                count = 50;
            };
            class _xx_ACE_epinephrine {
                name = "ACE_epinephrine";
                count = 30;
            };
            class _xx_ACE_morphine {
                name = "ACE_morphine";
                count = 30;
            };
            class _xx_ACE_bloodIV_500 {
                name = "ACE_bloodIV_500";
                count = 20;
            };
            class _xx_ACE_tourniquet {
                name = "ACE_tourniquet";
                count = 10;
            };
            class _xx_ACE_ACE_atropine {
                name = "ACE_atropine";
                count = 20;
            };
            class _xx_ACE_ACE_adenosinee {
                name = "ACE_adenosine";
                count = 20;
            };
            class _xx_ACE_bloodIV {
                name = "ACE_bloodIV";
                count = 20;
            };
            class _xx_ACE_personalAidKit {
                name = "ACE_personalAidKit";
                count = 1;
            };
            class _xx_ACE_surgicalKit {
                name = "ACE_surgicalKit";
                count = 1;
            };
        };
    };
    class UKSF_S_AmmoMedic: UKSF_S_Empty {
        displayName = "Supply Crate (Ammo & Medical)";
        class TransportMagazines {
            class _xx_UK3CB_BAF_556_30Rnd {
                magazine = "UK3CB_BAF_556_30Rnd";
                count = 30;
            };
            class _xx_UK3CB_BAF_556_30Rnd_T {
                magazine = "UK3CB_BAF_556_30Rnd_T";
                count = 10;
            };
            class _xx_UK3CB_BAF_556_200Rnd {
                magazine = "UK3CB_BAF_556_200Rnd";
                count = 10;
            };
            class _xx_UK3CB_BAF_556_200Rnd_T {
                magazine = "UK3CB_BAF_556_200Rnd_T";
                count = 10;
            };
            class _xx_UK3CB_BAF_762_100Rnd {
                magazine = "UK3CB_BAF_762_100Rnd";
                count = 10;
            };
            class _xx_UK3CB_BAF_762_100Rnd_T {
                magazine = "UK3CB_BAF_762_100Rnd_T";
                count = 10;
            };
            class _xx_UK3CB_BAF_762_L42A1_20Rnd {
                magazine = "UK3CB_BAF_762_L42A1_20Rnd";
                count = 10;
            };
            class _xx_UK3CB_BAF_762_L42A1_20Rnd_T {
                magazine = "UK3CB_BAF_762_L42A1_20Rnd_T";
                count = 10;
            };
            class _xx_UK3CB_BAF_338_5Rnd {
                magazine = "UK3CB_BAF_338_5Rnd";
                count = 10;
            };
            class _xx_1Rnd_HE_Grenade_shell {
                magazine = "1Rnd_HE_Grenade_shell";
                count = 30;
            };
            class _xx_HandGrenade {
                magazine = "HandGrenade";
                count = 20;
            };
            class _xx_UK3CB_BAF_SmokeShell {
                magazine = "UK3CB_BAF_SmokeShell";
                count = 10;
            };
            class _xx_UK3CB_BAF_SmokeShellRed {
                magazine = "UK3CB_BAF_SmokeShellRed";
                count = 10;
            };
            class _xx_UK3CB_BAF_SmokeShellGreen {
                magazine = "UK3CB_BAF_SmokeShellGreen";
                count = 10;
            };
        };
        class TransportWeapons {
            class _xx_UK3CB_BAF_NLAW_Launcher {
                weapon = "UK3CB_BAF_NLAW_Launcher";
                count = 3;
            };
            class _xx_UK3CB_BAF_Javelin_Slung_Tube {
                weapon = "UK3CB_BAF_Javelin_Slung_Tube";
                count = 3;
            };
        };
        class TransportItems {
            class _xx_ACE_packingBandage {
                name = "ACE_packingBandage";
                count = 30;
            };
            class _xx_ACE_elasticBandage {
                name = "ACE_elasticBandage";
                count = 30;
            };
            class _xx_ACE_quikclot {
                name = "ACE_quikclot";
                count = 30;
            };
            class _xx_ACE_epinephrine {
                name = "ACE_epinephrine";
                count = 10;
            };
            class _xx_ACE_morphine {
                name = "ACE_morphine";
                count = 15;
            };
            class _xx_ACE_bloodIV_500 {
                name = "ACE_bloodIV_500";
                count = 10;
            };
            class _xx_ACE_ACE_atropine {
                name = "ACE_atropine";
                count = 10;
            };
            class _xx_ACE_ACE_adenosinee {
                name = "ACE_adenosine";
                count = 10;
            };
        };
    };
    class UKSF_S_Radios: UKSF_S_Empty {
        displayName = "ACRE Radios";
        class eventhandlers {
            init = "this addItemCargoGlobal [""ACRE_PRC117F"", 10]";
            class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
        };
        class TransportItems {
            class _xx_ACRE_PRC177F {
                name = "ACRE_PRC117F";
                count = 10;
            };
            class _xx_ACRE_PRC152 {
                name = "ACRE_PRC152";
                count = 25;
            };
            class _xx_ACRE_PRC343 {
                name = "ACRE_PRC343";
                count = 25;
            };
        };
        class TransportBackpacks {
            class _xx_UKSF_RadioPack {
                backpack = "B_Parachute";
                count = 5;
            };
        };
    };
    class UKSF_S_Arsenal: UKSF_S_Empty {
        displayName = "Supply Crate (Arsenal)";
    };

    class CUP_USBasicAmmunitionBox;
    class CUP_USLaunchersBox: CUP_USBasicAmmunitionBox {
        class TransportMagazines {
            class _xx_M136_M {
                magazine = "CUP_M136_M";
                count = 45;
            };
            class _xx_Stinger_M {
                magazine = "CUP_Stinger_M";
                count = 4;
            };
            class _xx_SMAW_HEAA_M {
                magazine = "CUP_SMAW_HEAA_M";
                count = 3;
            };
            class _xx_SMAW_HEDP_M {
                magazine = "CUP_SMAW_HEDP_M";
                count = 3;
            };
        };
        class TransportWeapons {
            class _xx_M136 {
                weapon = "CUP_M136";
                count = 15;
            };
            class _xx_Stinger {
                weapon = "CUP_Stinger";
                count = 4;
            };
            class _xx_UK3CB_BAF_Javelin_Slung_Tube {
                weapon = "UK3CB_BAF_Javelin_Slung_Tube";
                count = 1;
            };
            class _xx_UK3CB_BAF_Javelin_CLU {
                weapon = "UK3CB_BAF_Javelin_CLU";
                count = 1;
            };
            class _xx_SMAW {
                weapon = "CUP_SMAW";
                count = 2;
            };
        };
    };

    class CUP_ReammoBox_EP1;
    class CUP_USLaunchers_EP1: CUP_ReammoBox_EP1 {
        class TransportMagazines {
            class _xx_M136_M {
                magazine = "CUP_M136_M";
                count = 20;
            };
            class _xx_MAAWS_HEAT_M {
                magazine = "CUP_MAAWS_HEAT_M";
                count = 10;
            };
            class _xx_MAAWS_HEDP_M {
                magazine = "CUP_MAAWS_HEDP_M";
                count = 10;
            };
            class _xx_Stinger_M {
                magazine = "CUP_Stinger_M";
                count = 10;
            };
            class _xx_1Rnd_HE_M203 {
                magazine = "CUP_1Rnd_HE_M203";
                count = 80;
            };
            class _xx_6Rnd_HE_M203 {
                magazine = "CUP_6Rnd_HE_M203";
                count = 30;
            };
            class _xx_6Rnd_FlareWhite_M203 {
                magazine = "CUP_6Rnd_FlareWhite_M203";
                count = 30;
            };
            class _xx_6Rnd_FlareGreen_M203 {
                magazine = "CUP_6Rnd_FlareGreen_M203";
                count = 30;
            };
            class _xx_6Rnd_FlareRed_M203 {
                magazine = "CUP_6Rnd_FlareRed_M203";
                count = 30;
            };
            class _xx_6Rnd_FlareYellow_M203 {
                magazine = "CUP_6Rnd_FlareYellow_M203";
                count = 30;
            };
            class _xx_6Rnd_Smoke_M203 {
                magazine = "CUP_6Rnd_Smoke_M203";
                count = 30;
            };
            class _xx_6Rnd_SmokeRed_M203 {
                magazine = "CUP_6Rnd_SmokeRed_M203";
                count = 30;
            };
            class _xx_6Rnd_SmokeGreen_M203 {
                magazine = "CUP_6Rnd_SmokeGreen_M203";
                count = 30;
            };
            class _xx_6Rnd_SmokeYellow_M203 {
                magazine = "CUP_6Rnd_SmokeYellow_M203";
                count = 30;
            };
            class _xx_1Rnd_StarFlare_White_M203 {
                magazine = "CUP_1Rnd_StarFlare_White_M203";
                count = 10;
            };
            class _xx_1Rnd_StarFlare_Red_M203 {
                magazine = "CUP_1Rnd_StarFlare_Red_M203";
                count = 10;
            };
            class _xx_1Rnd_StarFlare_Green_M203 {
                magazine = "CUP_1Rnd_StarFlare_Green_M203";
                count = 10;
            };
            class _xx_1Rnd_StarCluster_White_M203 {
                magazine = "CUP_1Rnd_StarCluster_White_M203";
                count = 10;
            };
            class _xx_1Rnd_StarCluster_Red_M203 {
                magazine = "CUP_1Rnd_StarCluster_Red_M203";
                count = 10;
            };
            class _xx_1Rnd_StarCluster_Green_M203 {
                magazine = "CUP_1Rnd_StarCluster_Green_M203";
                count = 10;
            };
            class _xx_HandGrenade_M67 {
                magazine = "CUP_HandGrenade_M67";
                count = 50;
            };
        };
        class TransportWeapons {
            class _xx_M136 {
                weapon = "CUP_M136";
                count = 2;
            };
            class _xx_UK3CB_BAF_Javelin_Slung_Tube {
                weapon = "UK3CB_BAF_Javelin_Slung_Tube";
                count = 1;
            };
            class _xx_UK3CB_BAF_Javelin_CLU {
                weapon = "UK3CB_BAF_Javelin_CLU";
                count = 1;
            };
            class _xx_MAAWS {
                weapon = "CUP_MAAWS";
                count = 2;
            };
            class _xx_Stinger {
                weapon = "CUP_Stinger";
                count = 2;
            };
            class _xx_M32_EP1 {
                weapon = "CUP_M32_EP1";
                count = 2;
            };
            class _xx_Mk13_EP1 {
                weapon = "CUP_Mk13_EP1";
                count = 4;
            };
        };
    };

    class StaticWeapon;
    class StaticMGWeapon: StaticWeapon {
        class Turrets;
    };
    class UK3CB_BAF_Static_MG_Base: StaticMGWeapon {
        faction = "CUP_B_GB";
        crew = "CUP_B_BAF_Soldier_MTP";
        typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
        class Turrets: Turrets {
            class MainTurret;
        };
    };
    class UK3CB_BAF_Static_L7A2_Base: UK3CB_BAF_Static_MG_Base {
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                weapons[] = { "CUP_Vlmg_M240_veh" };
            };
        };
    };
    class UK3CB_BAF_Static_L7A2_Low;
    class UK3CB_BAF_Static_L7A2_Deployed_Low: UK3CB_BAF_Static_L7A2_Low {
        faction = "CUP_B_GB";
        crew = "CUP_B_BAF_Soldier_MTP";
    };
    class UK3CB_BAF_Static_L7A2_Mid;
    class UK3CB_BAF_Static_L7A2_Deployed_Mid: UK3CB_BAF_Static_L7A2_Mid {
        faction = "CUP_B_GB";
        crew = "CUP_B_BAF_Soldier_MTP";
    };
    class UK3CB_BAF_Static_L7A2_High;
    class UK3CB_BAF_Static_L7A2_Deployed_High: UK3CB_BAF_Static_L7A2_High {
        faction = "CUP_B_GB";
        crew = "CUP_B_BAF_Soldier_MTP";
    };
    class UK3CB_BAF_Static_L111A1_Base: UK3CB_BAF_Static_MG_Base {
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                weapons[] = { "CUP_Vhmg_M2_veh" };
            };
        };
    };
    class UK3CB_BAF_Static_L111A1_Low;
    class UK3CB_BAF_Static_L111A1_Deployed_Low: UK3CB_BAF_Static_L111A1_Low {
        faction = "CUP_B_GB";
        crew = "CUP_B_BAF_Soldier_MTP";
    };
    class UK3CB_BAF_Static_L111A1_Mid;
    class UK3CB_BAF_Static_L111A1_Deployed_Mid: UK3CB_BAF_Static_L111A1_Mid {
        faction = "CUP_B_GB";
        crew = "CUP_B_BAF_Soldier_MTP";
    };
    class UK3CB_BAF_Static_L111A1_High;
    class UK3CB_BAF_Static_L111A1_Deployed_High: UK3CB_BAF_Static_L111A1_High {
        faction = "CUP_B_GB";
        crew = "CUP_B_BAF_Soldier_MTP";
    };
    class UK3CB_BAF_Static_L134A1_Base: UK3CB_BAF_Static_MG_Base {
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                weapons[] = { "CUP_Vgmg_MK19_veh" };
            };
        };
    };
    class UK3CB_BAF_Static_L134A1_Low;
    class UK3CB_BAF_Static_L134A1_Deployed_Low: UK3CB_BAF_Static_L134A1_Low {
        faction = "CUP_B_GB";
        crew = "CUP_B_BAF_Soldier_MTP";
    };
    class UK3CB_BAF_Static_L134A1_Mid;
    class UK3CB_BAF_Static_L134A1_Deployed_Mid: UK3CB_BAF_Static_L134A1_Mid {
        faction = "CUP_B_GB";
        crew = "CUP_B_BAF_Soldier_MTP";
    };
    class UK3CB_BAF_Static_L134A1_High;
    class UK3CB_BAF_Static_L134A1_Deployed_High: UK3CB_BAF_Static_L134A1_High {
        faction = "CUP_B_GB";
        crew = "CUP_B_BAF_Soldier_MTP";
    };
    class Mortar_01_base_F;
    class UK3CB_BAF_Static_Mortar_Base: Mortar_01_base_F {
        faction = "CUP_B_GB";
        crew = "CUP_B_BAF_Soldier_MTP";
        typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
    };
    class UK3CB_BAF_Static_L16;
    class UK3CB_BAF_Static_L16_Deployed: UK3CB_BAF_Static_L16 {
        faction = "CUP_B_GB";
        crew = "CUP_B_BAF_Soldier_MTP";
    };
    class UK3CB_BAF_Static_M6;
    class UK3CB_BAF_Static_M6_Deployed: UK3CB_BAF_Static_M6 {
        faction = "CUP_B_GB";
        crew = "CUP_B_BAF_Soldier_MTP";
    };

    class ace_rearm_defaultCarriedObject;
    class GVAR(ACE_Hellfire_AGM114): ace_rearm_defaultCarriedObject {
        model = QPATHTOF(data\AGM114\AGM114Hellfire_proxy.p3d);
    };

    class ACE_Explosives_Place_DemoCharge;
    class ACE_Explosives_Place_BreachCharge: ACE_Explosives_Place_DemoCharge {
        author = "UKSF";
        displayName = "Breach Charge";
    };
    class DemoCharge_F;
    class BreachCharge_F: DemoCharge_F {
        author = "UKSF";
        displayName = "Breach Charge";
        ammo = "BreachCharge_Remote_Ammo";
    };

    class Thing;
    class ACE_Chemlight_IR_Marker: Thing {
        brightness = 10;
        class NVGMarker {
            diffuse[] = {0.1, 0.1, 0.1};
            ambient[] = {0.1, 0.1, 0.1};
            brightness = 0.4;
            name = "pozicni blik";
            drawLight = 0;
            drawLightSize = 0;
            drawLightCenterSize = 0;
            activeLight = 0;
            blinking = 0;
            dayLight = 0;
            onlyInNvg = 1;
            useFlare = 0;
        };
    };

    #include "CfgVehiclesPrivate.hpp"
};
