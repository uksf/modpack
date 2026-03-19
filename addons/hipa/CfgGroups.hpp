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
                    class Unit1 { vehicle = QGVAR(Rifleman); rank = "PRIVATE"; position[] = {0, -5, 0}; };
                    class Unit2 { vehicle = QGVAR(Rifleman_LAT); rank = "PRIVATE"; position[] = {0, -10, 0}; };
                    class Unit3 { vehicle = QGVAR(Machine_Gunner); rank = "PRIVATE"; position[] = {0, -15, 0}; };
                };
                class GVAR(Section) {
                    name = "Section";
                    faction = QUOTE(ADDON);
                    side = 0;
                    class Unit0 { vehicle = QGVAR(Squad_Leader); rank = "SERGEANT"; position[] = {0, 0, 0}; };
                    class Unit1 { vehicle = QGVAR(Rifleman); rank = "CORPORAL"; position[] = {0, -5, 0}; };
                    class Unit2 { vehicle = QGVAR(Rifleman_LAT); rank = "PRIVATE"; position[] = {0, -10, 0}; };
                    class Unit3 { vehicle = QGVAR(Machine_Gunner); rank = "PRIVATE"; position[] = {0, -15, 0}; };
                    class Unit4 { vehicle = QGVAR(Sharpshooter); rank = "PRIVATE"; position[] = {0, -20, 0}; };
                    class Unit5 { vehicle = QGVAR(Rifleman_AA); rank = "PRIVATE"; position[] = {0, -25, 0}; };
                    class Unit6 { vehicle = QGVAR(Signaller); rank = "PRIVATE"; position[] = {0, -30, 0}; };
                    class Unit7 { vehicle = QGVAR(Officer); rank = "PRIVATE"; position[] = {0, -35, 0}; };
                };
                class GVAR(Combat_HQ) {
                    name = "Combat HQ";
                    faction = QUOTE(ADDON);
                    side = 0;
                    class Unit0 { vehicle = QGVAR(Officer); rank = "LIEUTENANT"; position[] = {0, 0, 0}; };
                    class Unit1 { vehicle = QGVAR(Signaller); rank = "CORPORAL"; position[] = {0, -5, 0}; };
                    class Unit2 { vehicle = QGVAR(Squad_Leader); rank = "SERGEANT"; position[] = {0, -10, 0}; };
                    class Unit3 { vehicle = QGVAR(Rifleman); rank = "PRIVATE"; position[] = {0, -15, 0}; };
                };
                class GVAR(MG_Squad) {
                    name = "MG Squad";
                    faction = QUOTE(ADDON);
                    side = 0;
                    class Unit0 { vehicle = QGVAR(Squad_Leader); rank = "SERGEANT"; position[] = {0, 0, 0}; };
                    class Unit1 { vehicle = QGVAR(Rifleman); rank = "PRIVATE"; position[] = {0, -5, 0}; };
                    class Unit2 { vehicle = QGVAR(Rifleman); rank = "PRIVATE"; position[] = {0, -10, 0}; };
                    class Unit3 { vehicle = QGVAR(Rifleman); rank = "PRIVATE"; position[] = {0, -15, 0}; };
                    class Unit4 { vehicle = QGVAR(Machine_Gunner); rank = "PRIVATE"; position[] = {0, -20, 0}; };
                    class Unit5 { vehicle = QGVAR(Machine_Gunner); rank = "PRIVATE"; position[] = {0, -25, 0}; };
                    class Unit6 { vehicle = QGVAR(Machine_Gunner); rank = "PRIVATE"; position[] = {0, -30, 0}; };
                    class Unit7 { vehicle = QGVAR(Rifleman_HAT); rank = "PRIVATE"; position[] = {0, -35, 0}; };
                };
                class GVAR(AA_Team) {
                    name = "AA Team";
                    faction = QUOTE(ADDON);
                    side = 0;
                    class Unit0 { vehicle = QGVAR(Squad_Leader); rank = "SERGEANT"; position[] = {0, 0, 0}; };
                    class Unit1 { vehicle = QGVAR(Rifleman_AA); rank = "PRIVATE"; position[] = {0, -5, 0}; };
                    class Unit2 { vehicle = QGVAR(Rifleman_AA); rank = "PRIVATE"; position[] = {0, -10, 0}; };
                    class Unit3 { vehicle = QGVAR(Rifleman_AA); rank = "PRIVATE"; position[] = {0, -15, 0}; };
                };
                class GVAR(Team_2Man) {
                    name = "2-Man Team";
                    faction = QUOTE(ADDON);
                    side = 0;
                    class Unit0 { vehicle = QGVAR(Squad_Leader); rank = "CORPORAL"; position[] = {0, 0, 0}; };
                    class Unit1 { vehicle = QGVAR(Rifleman); rank = "PRIVATE"; position[] = {0, -5, 0}; };
                };
                class GVAR(Sniper_Pair) {
                    name = "Sniper Pair";
                    faction = QUOTE(ADDON);
                    side = 0;
                    class Unit0 { vehicle = QGVAR(Sniper); rank = "CORPORAL"; position[] = {0, 0, 0}; };
                    class Unit1 { vehicle = QGVAR(Sniper); rank = "PRIVATE"; position[] = {0, -5, 0}; };
                };
                class GVAR(AT_Team) {
                    name = "AT Team";
                    faction = QUOTE(ADDON);
                    side = 0;
                    class Unit0 { vehicle = QGVAR(Squad_Leader); rank = "SERGEANT"; position[] = {0, 0, 0}; };
                    class Unit1 { vehicle = QGVAR(Rifleman_HAT); rank = "PRIVATE"; position[] = {0, -5, 0}; };
                    class Unit2 { vehicle = QGVAR(Rifleman_HAT); rank = "PRIVATE"; position[] = {0, -10, 0}; };
                    class Unit3 { vehicle = QGVAR(Rifleman_LAT); rank = "PRIVATE"; position[] = {0, -15, 0}; };
                    class Unit4 { vehicle = QGVAR(Rifleman_LAT); rank = "PRIVATE"; position[] = {0, -20, 0}; };
                    class Unit5 { vehicle = QGVAR(Machine_Gunner); rank = "PRIVATE"; position[] = {0, -25, 0}; };
                    class Unit6 { vehicle = QGVAR(Rifleman); rank = "PRIVATE"; position[] = {0, -30, 0}; };
                    class Unit7 { vehicle = QGVAR(Rifleman); rank = "PRIVATE"; position[] = {0, -35, 0}; };
                };
                class GVAR(M119_Battery) {
                    name = "M119 Battery";
                    faction = QUOTE(ADDON);
                    side = 0;
                    class Unit0 { vehicle = QGVAR(M119); rank = "CORPORAL"; position[] = {0, 0, 0}; };
                    class Unit1 { vehicle = QGVAR(M119); rank = "CORPORAL"; position[] = {0, -5, 0}; };
                    class Unit2 { vehicle = QGVAR(M119); rank = "CORPORAL"; position[] = {0, -10, 0}; };
                    class Unit3 { vehicle = QGVAR(Squad_Leader); rank = "LIEUTENANT"; position[] = {0, -15, 0}; };
                    class Unit4 { vehicle = QGVAR(Signaller); rank = "SERGEANT"; position[] = {0, -20, 0}; };
                    class Unit5 { vehicle = QGVAR(Rifleman); rank = "PRIVATE"; position[] = {0, -25, 0}; };
                    class Unit6 { vehicle = QGVAR(Rifleman); rank = "PRIVATE"; position[] = {0, -30, 0}; };
                    class Unit7 { vehicle = QGVAR(Rifleman); rank = "PRIVATE"; position[] = {0, -35, 0}; };
                    class Unit8 { vehicle = QGVAR(Rifleman); rank = "PRIVATE"; position[] = {0, -40, 0}; };
                    class Unit9 { vehicle = QGVAR(Rifleman); rank = "PRIVATE"; position[] = {0, -45, 0}; };
                    class Unit10 { vehicle = QGVAR(Rifleman); rank = "PRIVATE"; position[] = {0, -50, 0}; };
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
            class Armoured {
                name = "Armoured Assets";
                class GVAR(Boxer_HMG_Patrol) {
                    name = "Boxer HMG Patrol";
                    faction = QUOTE(ADDON);
                    side = 0;
                    class Unit0 { vehicle = QGVAR(Boxer_HMG); rank = "CORPORAL"; position[] = {0, 0, 0}; };
                    class Unit1 { vehicle = QGVAR(Squad_Leader); rank = "SERGEANT"; position[] = {10, -5, 0}; };
                    class Unit2 { vehicle = QGVAR(Rifleman); rank = "PRIVATE"; position[] = {15, -10, 0}; };
                    class Unit3 { vehicle = QGVAR(Rifleman_LAT); rank = "PRIVATE"; position[] = {20, -15, 0}; };
                    class Unit4 { vehicle = QGVAR(Machine_Gunner); rank = "PRIVATE"; position[] = {25, -20, 0}; };
                    class Unit5 { vehicle = QGVAR(Sharpshooter); rank = "PRIVATE"; position[] = {30, -25, 0}; };
                    class Unit6 { vehicle = QGVAR(Rifleman_AA); rank = "PRIVATE"; position[] = {35, -30, 0}; };
                };
                class GVAR(Boxer_GMG_Patrol) {
                    name = "Boxer GMG Patrol";
                    faction = QUOTE(ADDON);
                    side = 0;
                    class Unit0 { vehicle = QGVAR(Boxer_GMG); rank = "CORPORAL"; position[] = {0, 0, 0}; };
                    class Unit1 { vehicle = QGVAR(Squad_Leader); rank = "SERGEANT"; position[] = {10, -5, 0}; };
                    class Unit2 { vehicle = QGVAR(Rifleman); rank = "PRIVATE"; position[] = {15, -10, 0}; };
                    class Unit3 { vehicle = QGVAR(Rifleman_LAT); rank = "PRIVATE"; position[] = {20, -15, 0}; };
                    class Unit4 { vehicle = QGVAR(Machine_Gunner); rank = "PRIVATE"; position[] = {25, -20, 0}; };
                    class Unit5 { vehicle = QGVAR(Sharpshooter); rank = "PRIVATE"; position[] = {30, -25, 0}; };
                    class Unit6 { vehicle = QGVAR(Rifleman_AA); rank = "PRIVATE"; position[] = {35, -30, 0}; };
                };
                class GVAR(MTVR_Troop_Transport) {
                    name = "MTVR Troop Transport";
                    faction = QUOTE(ADDON);
                    side = 0;
                    class Unit0 { vehicle = QGVAR(MTVR); rank = "CORPORAL"; position[] = {0, 0, 0}; };
                    class Unit1 { vehicle = QGVAR(Rifleman); rank = "PRIVATE"; position[] = {5, 0, 0}; };
                    class Unit2 { vehicle = QGVAR(Rifleman); rank = "PRIVATE"; position[] = {10, 0, 0}; };
                    class Unit3 { vehicle = QGVAR(Rifleman); rank = "PRIVATE"; position[] = {15, 0, 0}; };
                    class Unit4 { vehicle = QGVAR(Rifleman); rank = "PRIVATE"; position[] = {20, 0, 0}; };
                    class Unit5 { vehicle = QGVAR(Rifleman); rank = "PRIVATE"; position[] = {25, 0, 0}; };
                    class Unit6 { vehicle = QGVAR(Rifleman); rank = "PRIVATE"; position[] = {30, 0, 0}; };
                    class Unit7 { vehicle = QGVAR(Rifleman); rank = "PRIVATE"; position[] = {35, 0, 0}; };
                    class Unit8 { vehicle = QGVAR(Rifleman); rank = "PRIVATE"; position[] = {40, 0, 0}; };
                    class Unit9 { vehicle = QGVAR(Rifleman); rank = "PRIVATE"; position[] = {45, 0, 0}; };
                    class Unit10 { vehicle = QGVAR(Rifleman); rank = "PRIVATE"; position[] = {50, 0, 0}; };
                };
                class GVAR(Tank_Platoon_Mixed) {
                    name = "Tank Platoon (Mixed)";
                    faction = QUOTE(ADDON);
                    side = 0;
                    class Unit0 { vehicle = QGVAR(Leopard2A6); rank = "LIEUTENANT"; position[] = {0, 0, 0}; };
                    class Unit1 { vehicle = QGVAR(Leopard2A6); rank = "SERGEANT"; position[] = {10, 0, 0}; };
                    class Unit2 { vehicle = QGVAR(T55); rank = "CORPORAL"; position[] = {20, 0, 0}; };
                    class Unit3 { vehicle = QGVAR(T55); rank = "CORPORAL"; position[] = {30, 0, 0}; };
                };
                class GVAR(Tank_Platoon_Heavy) {
                    name = "Tank Platoon (Heavy)";
                    faction = QUOTE(ADDON);
                    side = 0;
                    class Unit0 { vehicle = QGVAR(Leopard2A6); rank = "LIEUTENANT"; position[] = {0, 0, 0}; };
                    class Unit1 { vehicle = QGVAR(Leopard2A6); rank = "SERGEANT"; position[] = {10, 0, 0}; };
                    class Unit2 { vehicle = QGVAR(Leopard2A6); rank = "CORPORAL"; position[] = {20, 0, 0}; };
                    class Unit3 { vehicle = QGVAR(Leopard2A6); rank = "CORPORAL"; position[] = {30, 0, 0}; };
                };
                class GVAR(Tank_Platoon_Light) {
                    name = "Tank Platoon (Light)";
                    faction = QUOTE(ADDON);
                    side = 0;
                    class Unit0 { vehicle = QGVAR(T55); rank = "LIEUTENANT"; position[] = {0, 0, 0}; };
                    class Unit1 { vehicle = QGVAR(T55); rank = "SERGEANT"; position[] = {10, 0, 0}; };
                    class Unit2 { vehicle = QGVAR(T55); rank = "CORPORAL"; position[] = {20, 0, 0}; };
                    class Unit3 { vehicle = QGVAR(T55); rank = "CORPORAL"; position[] = {30, 0, 0}; };
                };
                class GVAR(Tank_Platoon_AA) {
                    name = "Tank Platoon (AA)";
                    faction = QUOTE(ADDON);
                    side = 0;
                    class Unit0 { vehicle = QGVAR(Leopard2A6); rank = "LIEUTENANT"; position[] = {0, 0, 0}; };
                    class Unit1 { vehicle = QGVAR(Leopard2A6); rank = "SERGEANT"; position[] = {10, 0, 0}; };
                    class Unit2 { vehicle = QGVAR(T55); rank = "CORPORAL"; position[] = {20, 0, 0}; };
                    class Unit3 { vehicle = QGVAR(APC_AA); rank = "CORPORAL"; position[] = {30, 0, 0}; };
                };
            };
        };
    };
};
