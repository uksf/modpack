#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "AFND_LargeShip"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class CfgVehicles {
    class StaticShip;
    class AFND_LargeShip : StaticShip {
        class Attributes {
            class ScreenSet1 {
                defaultValue = "'\AFND_LargeShip\textures\Bridge_Computer_Screens_co.paa'";
            };
            class ScreenSet2 : ScreenSet1 {
                defaultValue = "'\AFND_LargeShip\textures\Bridge_Computer_Screens_co.paa'";
            };
            class ScreenSet3 : ScreenSet1 {
                defaultValue = "'\AFND_LargeShip\textures\Bridge_Computer_Screens_co.paa'";
            };
            class ScreenSet4 : ScreenSet1 {
                defaultValue = "'\AFND_LargeShip\textures\Bridge_Computer_Screens_co.paa'";
            };
            class ScreenSet5 : ScreenSet1 {
                defaultValue = "'\AFND_LargeShip\textures\Bridge_Computer_Screens_co.paa'";
            };
            class ScreenSet6 : ScreenSet1 {
                defaultValue = "'\AFND_LargeShip\textures\Bridge_Computer_Screens_co.paa'";
            };
            class ScreenSet7 : ScreenSet1 {
                defaultValue = "'\AFND_LargeShip\textures\Bridge_Computer_Screens_co.paa'";
            };
            class ScreenSet8 : ScreenSet1 {
                defaultValue = "'\AFND_LargeShip\textures\Bridge_Computer_Screens_co.paa'";
            };
            class ScreenSet9 : ScreenSet1 {
                defaultValue = "'\AFND_LargeShip\textures\Bridge_Computer_Screens_co.paa'";
            };
            class ScreenSet10 : ScreenSet1 {
                defaultValue = "'\AFND_LargeShip\textures\Bridge_Computer_Screens_co.paa'";
            };
            class ScreenSet11 : ScreenSet1 {
                defaultValue = "'\AFND_LargeShip\textures\Bridge_Computer_Screens_co.paa'";
            };
            class ScreenSet12 : ScreenSet1 {
                defaultValue = "'\AFND_LargeShip\textures\Bridge_Computer_Screens_co.paa'";
            };
            class ScreenSet13 : ScreenSet1 {
                defaultValue = "'\AFND_LargeShip\textures\Bridge_Computer_Screens_co.paa'";
            };
            class ScreenSet14 : ScreenSet1 {
                defaultValue = "'\AFND_LargeShip\textures\Bridge_Computer_Screens_co.paa'";
            };
            class ScreenSet15 : ScreenSet1 {
                defaultValue = "'\AFND_LargeShip\textures\Bridge_Computer_Screens_co.paa'";
            };
            class ScreenSet16 : ScreenSet1 {
                defaultValue = "'\AFND_LargeShip\textures\Bridge_Computer_Screens_co.paa'";
            };
            class ScreenSet17 : ScreenSet1 {
                defaultValue = "'\AFND_LargeShip\textures\Bridge_Computer_Screens_co.paa'";
            };
            class ScreenSet18 : ScreenSet1 {
                defaultValue = "'\AFND_LargeShip\textures\Bridge_Computer_Screens_co.paa'";
            };
        };
    };
};
