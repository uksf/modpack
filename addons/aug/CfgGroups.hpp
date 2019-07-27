class cfgGroups {
    class EAST {
        name = "OPFOR";
        class UKSF_AUG {
            name = "Altis Unionist Group";
            class Infantry {
                name = "Infantry";
                class GVAR(sniper_team) {
                    name = "Sniper Team";
                    faction = "UKSF_AUG";
                    side = 0;
                    class Unit0 {
                        side = 0;
                        vehicle = QGVAR(sniper);
                        rank = "PRIVATE";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 0;
                        vehicle = QGVAR(sniper);
                        rank = "PRIVATE";
                        position[] = { 0, -5, 0 };
                    };
                };
                class GVAR(fireteam) {
                    name = "Fireteam";
                    faction = "UKSF_AUG";
                    side = 0;
                    class Unit0 {
                        side = 0;
                        vehicle = QGVAR(tl);
                        rank = "PRIVATE";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 0;
                        vehicle = QGVAR(mg);
                        rank = "PRIVATE";
                        position[] = { 0, -5, 0 };
                    };
                    class Unit2 {
                        side = 0;
                        vehicle = QGVAR(at);
                        rank = "PRIVATE";
                        position[] = { 0, -10, 0 };
                    };
                    class Unit3 {
                        side = 0;
                        vehicle = QGVAR(grenadier);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                };
                class GVAR(sentry) {
                    name = "Sentry";
                    faction = "UKSF_AUG";
                    side = 0;
                    class Unit0 {
                        side = 0;
                        vehicle = QGVAR(grenadier);
                        rank = "PRIVATE";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 0;
                        vehicle = QGVAR(mg);
                        rank = "PRIVATE";
                        position[] = { 0, -5, 0 };
                    };
                };
                class GVAR(section) {
                    name = "Section";
                    faction = "UKSF_AUG";
                    side = 0;
                    class Unit0 {
                        side = 0;
                        vehicle = QGVAR(sl);
                        rank = "PRIVATE";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 0;
                        vehicle = QGVAR(at);
                        rank = "PRIVATE";
                        position[] = { 0, -5, 0 };
                    };
                    class Unit2 {
                        side = 0;
                        vehicle = QGVAR(marksman);
                        rank = "PRIVATE";
                        position[] = { 0, -10, 0 };
                    };
                    class Unit3 {
                        side = 0;
                        vehicle = QGVAR(tl);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                    class Unit4 {
                        side = 0;
                        vehicle = QGVAR(rifleman);
                        rank = "PRIVATE";
                        position[] = { 0, -20, 0 };
                    };
                    class Unit5 {
                        side = 0;
                        vehicle = QGVAR(grenadier);
                        rank = "PRIVATE";
                        position[] = { 0, -25, 0 };
                    };
                    class Unit6 {
                        side = 0;
                        vehicle = QGVAR(medic);
                        rank = "PRIVATE";
                        position[] = { 0, -30, 0 };
                    };
                    class Unit7 {
                        side = 0;
                        vehicle = QGVAR(mg);
                        rank = "PRIVATE";
                        position[] = { 0, -35, 0 };
                    };
                };
                class GVAR(aa_team) {
                    name = "AA Team";
                    faction = "UKSF_AUG";
                    side = 0;
                    class Unit0 {
                        side = 0;
                        vehicle = QGVAR(aa);
                        rank = "PRIVATE";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 0;
                        vehicle = QGVAR(aa);
                        rank = "PRIVATE";
                        position[] = { 0, -5, 0 };
                    };
                    class Unit2 {
                        side = 0;
                        vehicle = QGVAR(aa);
                        rank = "PRIVATE";
                        position[] = { 0, -10, 0 };
                    };
                };
            };
            class Motorized {
                name = "Motorized";
                class GVAR(motor_section) {
                    name = "Motor Section";
                    faction = "UKSF_AUG";
                    side = 0;
                    class Unit0 {
                        side = 0;
                        vehicle = QGVAR(landrover_gmg);
                        rank = "PRIVATE";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 0;
                        vehicle = QGVAR(landrover_mg);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                };
            };
            class Mechanized {
                name = "Mechanized";
                class GVAR(mech_section) {
                    name = "Mech Infantry Section";
                    faction = "UKSF_AUG";
                    side = 0;
                    class Unit0 {
                        side = 0;
                        vehicle = QGVAR(pandur);
                        rank = "PRIVATE";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 0;
                        vehicle = QGVAR(sl);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                    class Unit2 {
                        side = 0;
                        vehicle = QGVAR(at);
                        rank = "PRIVATE";
                        position[] = { 0, -30, 0 };
                    };
                    class Unit3 {
                        side = 0;
                        vehicle = QGVAR(marksman);
                        rank = "PRIVATE";
                        position[] = { 0, -45, 0 };
                    };
                    class Unit4 {
                        side = 0;
                        vehicle = QGVAR(tl);
                        rank = "PRIVATE";
                        position[] = { 0, -60, 0 };
                    };
                    class Unit5 {
                        side = 0;
                        vehicle = QGVAR(rifleman);
                        rank = "PRIVATE";
                        position[] = { 0, -75, 0 };
                    };
                    class Unit6 {
                        side = 0;
                        vehicle = QGVAR(grenadier);
                        rank = "PRIVATE";
                        position[] = { 0, -90, 0 };
                    };
                    class Unit7 {
                        side = 0;
                        vehicle = QGVAR(medic);
                        rank = "PRIVATE";
                        position[] = { 0, -105, 0 };
                    };
                    class Unit8 {
                        side = 0;
                        vehicle = QGVAR(mg);
                        rank = "PRIVATE";
                        position[] = { 0, -120, 0 };
                    };
                };
                class GVAR(apc_section) {
                    name = "APC Section";
                    faction = "UKSF_AUG";
                    side = 0;
                    class Unit0 {
                        side = 0;
                        vehicle = QGVAR(pandur);
                        rank = "PRIVATE";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 0;
                        vehicle = QGVAR(pandur);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                };
            };
        };
    };
};
