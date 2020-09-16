class CBA_Extended_EventHandlers_base;

class CfgVehicles {
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
    class StaticMortar;
    class Mortar_01_base_F: StaticMortar {
        class Turrets;
    };
    class UK3CB_BAF_Static_Mortar_Base: Mortar_01_base_F {
        faction = "CUP_B_GB";
        crew = "CUP_B_BAF_Soldier_MTP";
        typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
        class Turrets: Turrets {
            class MainTurret;
        };
    };
    class UK3CB_BAF_Static_L16: UK3CB_BAF_Static_Mortar_Base {
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                gunnerAction = "UK3CB_BAF_L16_Gunner";
            };
        };
    };
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

    class UK3CB_BAF_1Rnd_60mm_Mo_Shells_spent: Thing {
        SLX_XEH_DISABLED = 0;
        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
        };
    };
    class UK3CB_BAF_1Rnd_81mm_Mo_Shells_spent: Thing {
        SLX_XEH_DISABLED = 0;
        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
        };
    };

    class AA_01_base_F;
    class GVAR(rappelling_helper): AA_01_base_F {
        editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\B_static_AA_F.jpg";
        scope = 2;
        side = 1;
        faction = "BLU_F";
        crew = "B_soldier_f";
        displayName = "Rappelling Helper";
    };

    #include "CfgVehiclesPrivate.hpp"
};
