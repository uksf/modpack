class cfgGroups {
    class EAST {
        name = "OPFOR";
        class UKSF_Spetsnaz {
            name = "Spetsnaz";
            class Motorized {
                name = "Motorized";
                class GVAR(mobility_team) {
                    name = "Mobility Team";
                    faction = "UKSF_Spetsnaz";
                    side = 0;
                    class Unit0 {
                        side = 0;
                        vehicle = QGVAR(lmv);
                        rank = "PRIVATE";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 0;
                        vehicle = QGVAR(lmv);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                };
            };
            class SpecOps {
                name = "Special Forces";
                class GVAR(spec_ops_team) {
                    name = "Spec Ops Team";
                    faction = "UKSF_Spetsnaz";
                    side = 0;
                    class Unit0 {
                        side = 0;
                        vehicle = QGVAR(tl);
                        rank = "COLONEL";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 0;
                        vehicle = QGVAR(medic);
                        rank = "COLONEL";
                        position[] = { 0, -15, 0 };
                    };
                    class Unit2 {
                        side = 0;
                        vehicle = QGVAR(marksman);
                        rank = "COLONEL";
                        position[] = { 0, -30, 0 };
                    };
                    class Unit3 {
                        side = 0;
                        vehicle = QGVAR(mg);
                        rank = "COLONEL";
                        position[] = { 0, -45, 0 };
                    };
                    class Unit4 {
                        side = 0;
                        vehicle = QGVAR(explosive_specialist);
                        rank = "COLONEL";
                        position[] = { 0, -60, 0 };
                    };
                    class Unit5 {
                        side = 0;
                        vehicle = QGVAR(at);
                        rank = "COLONEL";
                        position[] = { 0, -75, 0 };
                    };
                };
                class GVAR(sniper_pair) {
                    name = "Sniper Pair";
                    faction = "UKSF_Spetsnaz";
                    side = 0;
                    class Unit0 {
                        side = 0;
                        vehicle = QGVAR(sniper);
                        rank = "COLONEL";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 0;
                        vehicle = QGVAR(sniper);
                        rank = "COLONEL";
                        position[] = { 0, -15, 0 };
                    };
                };
                class GVAR(undercover_civlians) {
                    name = "Undercover Team (Civilian)";
                    faction = "UKSF_Spetsnaz";
                    side = 0;
                    class Unit0 {
                        side = 0;
                        vehicle = QGVAR(civ_undercover_1);
                        rank = "COLONEL";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 0;
                        vehicle = QGVAR(civ_undercover_2);
                        rank = "COLONEL";
                        position[] = { 0, -15, 0 };
                    };
                    class Unit2 {
                        side = 0;
                        vehicle = QGVAR(civ_undercover_3);
                        rank = "COLONEL";
                        position[] = { 0, -30, 0 };
                    };
                    class Unit3 {
                        side = 0;
                        vehicle = QGVAR(civ_undercover_4);
                        rank = "COLONEL";
                        position[] = { 0, -45, 0 };
                    };
                };
                class GVAR(dive_team) {
                    name = "Dive Team";
                    faction = "UKSF_Spetsnaz";
                    side = 0;
                    class Unit0 {
                        side = 0;
                        vehicle = QGVAR(diver);
                        rank = "COLONEL";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 0;
                        vehicle = QGVAR(diver);
                        rank = "COLONEL";
                        position[] = { 0, -15, 0 };
                    };
                    class Unit2 {
                        side = 0;
                        vehicle = QGVAR(diver);
                        rank = "COLONEL";
                        position[] = { 0, -30, 0 };
                    };
                    class Unit3 {
                        side = 0;
                        vehicle = QGVAR(diver);
                        rank = "COLONEL";
                        position[] = { 0, -45, 0 };
                    };
                };
            };
        };
    };
};
