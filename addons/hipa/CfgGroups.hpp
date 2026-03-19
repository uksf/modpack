class CfgGroups {
    class EAST {
        class UKSF_HIPA {
            name = "HIPA";
            class Infantry {
                name = "Infantry";
                class GVAR(Fireteam) {
                    name = "Fireteam";
                    faction = QUOTE(ADDON);
                    side = 0;
                    class Unit0 { vehicle = QGVAR(Squad_Leader); rank = "CORPORAL"; position[] = {0, 0, 0}; };
                    class Unit1 { vehicle = QGVAR(Rifleman); rank = "PRIVATE"; position[] = {5, 0, 0}; };
                    class Unit2 { vehicle = QGVAR(Rifleman_LAT); rank = "PRIVATE"; position[] = {10, 0, 0}; };
                    class Unit3 { vehicle = QGVAR(Machine_Gunner); rank = "PRIVATE"; position[] = {15, 0, 0}; };
                };
                class GVAR(Section) {
                    name = "Section";
                    faction = QUOTE(ADDON);
                    side = 0;
                    class Unit0 { vehicle = QGVAR(Squad_Leader); rank = "SERGEANT"; position[] = {0, 0, 0}; };
                    class Unit1 { vehicle = QGVAR(Rifleman); rank = "CORPORAL"; position[] = {5, -5, 0}; };
                    class Unit2 { vehicle = QGVAR(Rifleman_LAT); rank = "PRIVATE"; position[] = {10, -10, 0}; };
                    class Unit3 { vehicle = QGVAR(Machine_Gunner); rank = "PRIVATE"; position[] = {15, -15, 0}; };
                    class Unit4 { vehicle = QGVAR(Sharpshooter); rank = "PRIVATE"; position[] = {20, -20, 0}; };
                    class Unit5 { vehicle = QGVAR(Rifleman_AA); rank = "PRIVATE"; position[] = {25, -25, 0}; };
                    class Unit6 { vehicle = QGVAR(Signaller); rank = "PRIVATE"; position[] = {30, -30, 0}; };
                    class Unit7 { vehicle = QGVAR(Officer); rank = "PRIVATE"; position[] = {35, -35, 0}; };
                };
            };
            class Special_Forces {
                name = "Special Forces";
                class GVAR(SF_Team) {
                    name = "SF Team";
                    faction = QUOTE(ADDON);
                    side = 0;
                    class Unit0 { vehicle = QGVAR(sf_sfc); rank = "SERGEANT"; position[] = {0, 0, 0}; };
                    class Unit1 { vehicle = QGVAR(sf_operator); rank = "CORPORAL"; position[] = {5, 0, 0}; };
                    class Unit2 { vehicle = QGVAR(sf_autorifleman); rank = "PRIVATE"; position[] = {10, 0, 0}; };
                    class Unit3 { vehicle = QGVAR(sf_grenadier); rank = "PRIVATE"; position[] = {15, 0, 0}; };
                    class Unit4 { vehicle = QGVAR(sf_LAT); rank = "PRIVATE"; position[] = {20, 0, 0}; };
                };
            };
        };
    };
};
