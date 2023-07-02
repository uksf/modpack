class CfgGroups {
    class INDEP {
        name = "Independent";
        class ADDON {
            name = "Eastern Unionist Group";
            class Infantry {
                name = "Infantry";
                class GVAR(R_Rifle_Squad) {
                    name = "Rifle Squad";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(Squad_Leader);
                        rank = "PRIVATE";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(Rifleman_Light_AT);
                        rank = "PRIVATE";
                        position[] = { 0, -5, 0 };
                    };
                    class Unit2 {
                        side = 2;
                        vehicle = QGVAR(Rifleman);
                        rank = "PRIVATE";
                        position[] = { 0, -10, 0 };
                    };
                    class Unit3 {
                        side = 2;
                        vehicle = QGVAR(Radio_Operator);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                    class Unit4 {
                        side = 2;
                        vehicle = QGVAR(Combat_Medic);
                        rank = "PRIVATE";
                        position[] = { 0, -20, 0 };
                    };
                    class Unit5 {
                        side = 2;
                        vehicle = QGVAR(Rifleman);
                        rank = "PRIVATE";
                        position[] = { 0, -25, 0 };
                    };
                };
                class GVAR(R_Infantry_Squad) {
                    name = "Infantry Squad";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(Squad_Leader);
                        rank = "PRIVATE";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(Rifleman);
                        rank = "PRIVATE";
                        position[] = { 0, -5, 0 };
                    };
                    class Unit2 {
                        side = 2;
                        vehicle = QGVAR(Combat_Medic);
                        rank = "PRIVATE";
                        position[] = { 0, -10, 0 };
                    };
                    class Unit3 {
                        side = 2;
                        vehicle = QGVAR(LMG_Gunner);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                    class Unit4 {
                        side = 2;
                        vehicle = QGVAR(Rifleman_Light_AT);
                        rank = "PRIVATE";
                        position[] = { 0, -20, 0 };
                    };
                    class Unit5 {
                        side = 2;
                        vehicle = QGVAR(Radio_Operator);
                        rank = "PRIVATE";
                        position[] = { 0, -25, 0 };
                    };
                };
                class GVAR(R_Weapons_Squad) {
                    name = "Weapons Squad";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(Squad_Leader);
                        rank = "PRIVATE";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(Rifleman);
                        rank = "PRIVATE";
                        position[] = { 0, -5, 0 };
                    };
                    class Unit2 {
                        side = 2;
                        vehicle = QGVAR(LMG_Gunner);
                        rank = "PRIVATE";
                        position[] = { 0, -10, 0 };
                    };
                    class Unit3 {
                        side = 2;
                        vehicle = QGVAR(HMG_Gunner);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                    class Unit4 {
                        side = 2;
                        vehicle = QGVAR(Rifleman_Heavy_AT);
                        rank = "PRIVATE";
                        position[] = { 0, -20, 0 };
                    };
                    class Unit5 {
                        side = 2;
                        vehicle = QGVAR(Rifleman_AA);
                        rank = "PRIVATE";
                        position[] = { 0, -25, 0 };
                    };
                    class Unit6 {
                        side = 2;
                        vehicle = QGVAR(Combat_Medic);
                        rank = "PRIVATE";
                        position[] = { 0, -30, 0 };
                    };
                };
            };
            class Motorized {
                name = "Motorized";
                class GVAR(R_Buran_Pair) {
                    name = "Buran Pair";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(Buran_APC);
                        rank = "PRIVATE";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(Buran_APC);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                };
                class GVAR(R_Humvee_FSG) {
                    name = "Humvee FSG";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(Humvee_AGS);
                        rank = "PRIVATE";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(Humvee_Dshkm);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                    class Unit2 {
                        side = 2;
                        vehicle = QGVAR(Humvee_Dshkm);
                        rank = "PRIVATE";
                        position[] = { 0, -30, 0 };
                    };
                };
                class GVAR(R_BTR_HQ_Group) {
                    name = "BTR HQ Group";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(BTR_80A);
                        rank = "PRIVATE";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(BTR_80A);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                    class Unit2 {
                        side = 2;
                        vehicle = QGVAR(BTR_90HQ);
                        rank = "PRIVATE";
                        position[] = { 0, -30, 0 };
                    };
                };
                class GVAR(R_BTR_90_Tank_Hunters) {
                    name = "BTR 90 Tank Hunters";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(BTR_90);
                        rank = "PRIVATE";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(BTR_90);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                };
                class GVAR(R_UAZ_AA_Pair) {
                    name = "UAZ AA Pair";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(UAZ_AA);
                        rank = "PRIVATE";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(UAZ_AA);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                };
            };
            class Mechanized {
                name = "Mechanized";
                class GVAR(R_Namer_Pair) {
                    name = "Namer Pair";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(Namer);
                        rank = "MAJOR";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(Namer);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                };
                class GVAR(R_BMP3_Pair) {
                    name = "BMP3 Pair";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(BMP3);
                        rank = "MAJOR";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(BMP3);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                };
                class GVAR(R_ZSU_23_4_Pair) {
                    name = "ZSU 23 4 Pair";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(ZSU_23_4);
                        rank = "MAJOR";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(ZSU_23_4);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                };
            };
            class Armored {
                name = "Armored";
                class GVAR(R_T72_Pair) {
                    name = "T72 Pair";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(T72);
                        rank = "COLONEL";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(T72);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                };
                class GVAR(R_T55_Platoon) {
                    name = "T55 Platoon";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(T55);
                        rank = "COLONEL";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(T55);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                    class Unit2 {
                        side = 2;
                        vehicle = QGVAR(T55);
                        rank = "PRIVATE";
                        position[] = { 0, -30, 0 };
                    };
                };
                class GVAR(R_Armoured_Column) {
                    name = "Armoured Column";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(T_90A);
                        rank = "COLONEL";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(BMP3);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                    class Unit2 {
                        side = 2;
                        vehicle = QGVAR(BTR_90);
                        rank = "PRIVATE";
                        position[] = { 0, -30, 0 };
                    };
                };
                class GVAR(R_T90_Pair) {
                    name = "T90 Pair";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(T_90A);
                        rank = "COLONEL";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(T_90A);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                };
                class GVAR(R_T14_Pair) {
                    name = "T14 Pair";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(T_14_Armata);
                        rank = "COLONEL";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(T_14_Armata);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                };
            };
            class SpecOps {
                name = "Special Forces";
                class GVAR(R_SF_Team) {
                    name = "SF Team";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(SF_Teamlead);
                        rank = "COLONEL";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(SF_Rifleman);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                    class Unit2 {
                        side = 2;
                        vehicle = QGVAR(SF_Comms);
                        rank = "PRIVATE";
                        position[] = { 0, -30, 0 };
                    };
                    class Unit3 {
                        side = 2;
                        vehicle = QGVAR(SF_LMG);
                        rank = "PRIVATE";
                        position[] = { 0, -45, 0 };
                    };
                    class Unit4 {
                        side = 2;
                        vehicle = QGVAR(SF_AT);
                        rank = "PRIVATE";
                        position[] = { 0, -60, 0 };
                    };
                    class Unit5 {
                        side = 2;
                        vehicle = QGVAR(SF_Medic);
                        rank = "PRIVATE";
                        position[] = { 0, -75, 0 };
                    };
                };
                class GVAR(R_SF_Sniper_Team) {
                    name = "SF Sniper Team";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(SF_Teamlead);
                        rank = "COLONEL";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(SF_Sniper);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                    class Unit2 {
                        side = 2;
                        vehicle = QGVAR(SF_Comms);
                        rank = "PRIVATE";
                        position[] = { 0, -30, 0 };
                    };
                };
                class GVAR(R_SF_Fire_Support_Team) {
                    name = "SF Fire Support Team";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(SF_Teamlead);
                        rank = "COLONEL";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(SF_Rifleman);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                    class Unit2 {
                        side = 2;
                        vehicle = QGVAR(SF_AT);
                        rank = "PRIVATE";
                        position[] = { 0, -30, 0 };
                    };
                    class Unit3 {
                        side = 2;
                        vehicle = QGVAR(SF_LMG);
                        rank = "PRIVATE";
                        position[] = { 0, -45, 0 };
                    };
                };
                class GVAR(R_SF_Para_Team) {
                    name = "SF Para Team";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(SF_Teamlead_Para);
                        rank = "COLONEL";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(SF_Rifleman_Para);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                    class Unit2 {
                        side = 2;
                        vehicle = QGVAR(SF_LMG_Para);
                        rank = "PRIVATE";
                        position[] = { 0, -30, 0 };
                    };
                    class Unit3 {
                        side = 2;
                        vehicle = QGVAR(SF_AT_Para);
                        rank = "PRIVATE";
                        position[] = { 0, -45, 0 };
                    };
                };
            };
            class Support {
                name = "Support Infantry";

                class GVAR(R_HQ_Element) {
                    name = "HQ Element";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(Officer);
                        rank = "MAJOR";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(Radio_Operator);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                    class Unit2 {
                        side = 2;
                        vehicle = QGVAR(Combat_Medic);
                        rank = "PRIVATE";
                        position[] = { 0, -30, 0 };
                    };
                };
                class GVAR(R_Three_Man_Patrol) {
                    name = "Three Man Patrol";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(Squad_Leader);
                        rank = "MAJOR";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(LMG_Gunner);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                    class Unit2 {
                        side = 2;
                        vehicle = QGVAR(Rifleman);
                        rank = "PRIVATE";
                        position[] = { 0, -30, 0 };
                    };
                };
                class GVAR(R_AT_Team) {
                    name = "AT Team";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(Squad_Leader);
                        rank = "MAJOR";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(Rifleman_Heavy_AT);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                    class Unit2 {
                        side = 2;
                        vehicle = QGVAR(Rifleman_Light_AT);
                        rank = "PRIVATE";
                        position[] = { 0, -30, 0 };
                    };
                    class Unit3 {
                        side = 2;
                        vehicle = QGVAR(Rifleman);
                        rank = "PRIVATE";
                        position[] = { 0, -45, 0 };
                    };
                };
                class GVAR(R_AA_Team) {
                    name = "AA Team";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(Squad_Leader);
                        rank = "MAJOR";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(Rifleman_AA);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                    class Unit2 {
                        side = 2;
                        vehicle = QGVAR(Rifleman);
                        rank = "PRIVATE";
                        position[] = { 0, -30, 0 };
                    };
                    class Unit3 {
                        side = 2;
                        vehicle = QGVAR(Combat_Medic);
                        rank = "PRIVATE";
                        position[] = { 0, -45, 0 };
                    };
                };
                class GVAR(R_Machine_Gunner_Team) {
                    name = "Machine Gunner Team";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(Squad_Leader);
                        rank = "MAJOR";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(LMG_Gunner);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                    class Unit2 {
                        side = 2;
                        vehicle = QGVAR(LMG_Gunner);
                        rank = "PRIVATE";
                        position[] = { 0, -30, 0 };
                    };
                    class Unit3 {
                        side = 2;
                        vehicle = QGVAR(Combat_Medic);
                        rank = "PRIVATE";
                        position[] = { 0, -45, 0 };
                    };
                };
                class GVAR(R_Medic_Team) {
                    name = "Medic Team";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(Squad_Leader);
                        rank = "MAJOR";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(Rifleman);
                        rank = "PRIVATE";
                        position[] = { 0, -15, 0 };
                    };
                    class Unit2 {
                        side = 2;
                        vehicle = QGVAR(Combat_Medic);
                        rank = "PRIVATE";
                        position[] = { 0, -30, 0 };
                    };
                    class Unit3 {
                        side = 2;
                        vehicle = QGVAR(Combat_Medic);
                        rank = "PRIVATE";
                        position[] = { 0, -45, 0 };
                    };
                };
            };
            class Air {
                name = "Air";
                class GVAR(R_Gripen_CAP) {
                    name = "Gripen CAP";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(Gripen);
                        rank = "MAJOR";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(Gripen);
                        rank = "LIEUTENANT";
                        position[] = { 0, -30, 0 };
                    };
                    class Unit2 {
                        side = 2;
                        vehicle = QGVAR(Gripen);
                        rank = "LIEUTENANT";
                        position[] = { 0, -60, 0 };
                    };
                };
                class GVAR(R_Shikra_CAP) {
                    name = "Shikra CAP";
                    faction = QUOTE(ADDON);
                    side = 2;
                    class Unit0 {
                        side = 2;
                        vehicle = QGVAR(Shikra);
                        rank = "MAJOR";
                        position[] = { 0, -0, 0 };
                    };
                    class Unit1 {
                        side = 2;
                        vehicle = QGVAR(Shikra);
                        rank = "LIEUTENANT";
                        position[] = { 0, -30, 0 };
                    };
                    class Unit2 {
                        side = 2;
                        vehicle = QGVAR(Shikra);
                        rank = "LIEUTENANT";
                        position[] = { 0, -60, 0 };
                    };
                };
            };
        };
    };
};
