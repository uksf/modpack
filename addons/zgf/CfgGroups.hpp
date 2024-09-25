class cfgGroups {
    class Indep {
        name = "Independent";
        class ZGF {
            name = "Zardashan Government Forces";
            class Infantry {
                name = "Infantry";
                class GVAR(2_Man_Team) {
                    name = "2 Man Team";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(soldier_gp25);
                        rank = "PRIVATE";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(soldier_sks);
                        rank = "PRIVATE";
                        position[] = { 0, -5, 0 };
                    };
                };
                class GVAR(4_man_team) {
                    name = "4 Man Team";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(soldier_gp25);
                        rank = "PRIVATE";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(soldier_akn);
                        rank = "PRIVATE";
                        position[] = { 0, -5, 0 };
                    };
                    class Unit2 {
                        side = 2;
                        vehicle = QGVAR(soldier_aa);
                        rank = "PRIVATE";
                        position[] = { 0, -10, 0 };
                    };
                    class Unit3 {
                        side = 2;
                        vehicle = QGVAR(soldier_MG);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                };
                class GVAR(6_man_team) {
                    name = "6 Man Team";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(soldier_gp25);
                        rank = "PRIVATE";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(soldier_akn);
                        rank = "PRIVATE";
                        position[] = { 0, -5, 0 };
                    };
                    class Unit2 {
                        side = 2;
                        vehicle = QGVAR(soldier_MG);
                        rank = "PRIVATE";
                        position[] = { 0, -10, 0 };
                    };
                    class Unit3 {
                        side = 2;
                        vehicle = QGVAR(soldier_akn);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                    class Unit4 {
                        side = 2;
                        vehicle = QGVAR(soldier_LAT);
                        rank = "PRIVATE";
                        position[] = { 0, -20, 0 };
                    };
                    class Unit5 {
                        side = 2;
                        vehicle = QGVAR(soldier_sks);
                        rank = "PRIVATE";
                        position[] = { 0, -25, 0 };
                    };
                };
                class GVAR(8_man_team) {
                    name = "8 Man Team";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(soldier_gp25);
                        rank = "PRIVATE";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(soldier_akn);
                        rank = "PRIVATE";
                        position[] = { 0, -5, 0 };
                    };
                    class Unit2 {
                        side = 2;
                        vehicle = QGVAR(soldier_MG);
                        rank = "PRIVATE";
                        position[] = { 0, -10, 0 };
                    };
                    class Unit3 {
                        side = 2;
                        vehicle = QGVAR(soldier_akn);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                    class Unit4 {
                        side = 2;
                        vehicle = QGVAR(soldier_LAT);
                        rank = "PRIVATE";
                        position[] = { 0, -20, 0 };
                    };
                    class Unit5 {
                        side = 2;
                        vehicle = QGVAR(soldier_sks);
                        rank = "PRIVATE";
                        position[] = { 0, -25, 0 };
                    };
                    class Unit6 {
                        side = 2;
                        vehicle = QGVAR(soldier_enfield);
                        rank = "PRIVATE";
                        position[] = { 0, -30, 0 };
                    };
                    class Unit7 {
                        side = 2;
                        vehicle = QGVAR(soldier_LAT);
                        rank = "PRIVATE";
                        position[] = { 0, -35, 0 };
                    };
                };
                class GVAR(AT_Team) {
                    name = "RPG Team";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(soldier_sks);
                        rank = "PRIVATE";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(soldier_LAT);
                        rank = "PRIVATE";
                        position[] = { 0, -5, 0 };
                    };
                    class Unit2 {
                        side = 2;
                        vehicle = QGVAR(soldier_LAT);
                        rank = "PRIVATE";
                        position[] = { 0, -10, 0 };
                    };
                };
                class GVAR(MG_Team) {
                    name = "MG Team";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(soldier_enfield);
                        rank = "PRIVATE";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(soldier_MG);
                        rank = "PRIVATE";
                        position[] = { 0, -5, 0 };
                    };
                    class Unit2 {
                        side = 2;
                        vehicle = QGVAR(soldier_MG);
                        rank = "PRIVATE";
                        position[] = { 0, -10, 0 };
                    };
                    class Unit3 {
                        side = 2;
                        vehicle = QGVAR(soldier_gp25);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                };
                class GVAR(AA_Team) {
                    name = "AA Team";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(soldier_gp25);
                        rank = "PRIVATE";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(soldier_aa);
                        rank = "PRIVATE";
                        position[] = { 0, -5, 0 };
                    };
                    class Unit2 {
                        side = 2;
                        vehicle = QGVAR(soldier_aa);
                        rank = "PRIVATE";
                        position[] = { 0, -10, 0 };
                    };
                    class Unit3 {
                        side = 2;
                        vehicle = QGVAR(soldier_LAT);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                };
            };
        };
    };
};
