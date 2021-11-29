class CfgGroups {
    class East {
        name = "OPFOR";
        side = 0;
        class UKSF_Base {
            name = "Base Faction";
            class Infantry {
                name = "Infantry";
                aliveCategory = "Infantry";
                class uksf_Base_Sentry {
                    faction = "UKSF_Base_Faction";
                    name = "Sentry";
                    side = 0;
                    class Unit0 {
                        position[] = { 0,0,0 };
                        rank = "CORPORAL";
                        side = 0;
                        vehicle = "uksf_Base_SL";
                    };
                    class Unit1 {
                        position[] = { 0,-3,0 };
                        rank = "PRIVATE";
                        side = 0;
                        vehicle = "uksf_Base_Rifleman";
                    };
                };
                class uksf_Base_Fireteam {
                    faction = "UKSF_Base_Faction";
                    name = "Fireteam";
                    side = 0;
                    class Unit0 {
                        position[] = { 0,0,0 };
                        rank = "CORPORAL";
                        side = 0;
                        vehicle = "uksf_Base_SL";
                    };
                    class Unit1 {
                        position[] = { 0,-3,0 };
                        rank = "PRIVATE";
                        side = 0;
                        vehicle = "uksf_Base_LAT";
                    };
                    class Unit2 {
                        position[] = { 0,-6,0 };
                        rank = "PRIVATE";
                        side = 0;
                        vehicle = "uksf_Base_Rifleman";
                    };
                    class Unit3 {
                        position[] = { 0,-9,0 };
                        rank = "PRIVATE";
                        side = 0;
                        vehicle = "uksf_Base_MG";
                    };
                };
                class uksf_Base_6 {
                    name = "6 Man Team";
                    faction = "UKSF_Base_Faction";
                    rarityGroup = 0.5;
                    side = 0;
                    class Unit0 {
                        side = 0;
                        vehicle = "uksf_Base_SL";
                        rank = "SERGEANT";
                        position[] = { 0,0,0 };
                    };
                    class Unit1 {
                        side = 0;
                        vehicle = "uksf_Base_Rifleman";
                        rank = "CORPORAL";
                        position[] = { 0,-3,0 };
                    };
                    class Unit2 {
                        side = 0;
                        vehicle = "uksf_Base_MG";
                        rank = "PRIVATE";
                        position[] = { 0,-6,0 };
                    };
                    class Unit3 {
                        side = 0;
                        vehicle = "uksf_Base_LAT";
                        rank = "PRIVATE";
                        position[] = { 0,-9,0 };
                    };
                    class Unit4 {
                        side = 0;
                        vehicle = "uksf_Base_Marksman";
                        rank = "PRIVATE";
                        position[] = { 0,-12,0 };
                    };
                    class Unit5 {
                        side = 0;
                        vehicle = "uksf_Base_Rifleman";
                        rank = "PRIVATE";
                        position[] = { 0,-15,0 };
                    };
                };
                class UKSF_Base_8 {
                    name = "Section";
                    faction = "UKSF_Base_Faction";
                    rarityGroup = 0.5;
                    side = 0;
                    class Unit0 {
                        side = 0;
                        vehicle = "uksf_Base_SL";
                        rank = "SERGEANT";
                        position[] = { 0,0,0 };
                    };
                    class Unit1 {
                        side = 0;
                        vehicle = "uksf_Base_Rifleman";
                        rank = "CORPORAL";
                        position[] = { 0,-3,0 };
                    };
                    class Unit2 {
                        side = 0;
                        vehicle = "uksf_Base_MG";
                        rank = "PRIVATE";
                        position[] = { 0,-6,0 };
                    };
                    class Unit3 {
                        side = 0;
                        vehicle = "uksf_Base_LAT";
                        rank = "PRIVATE";
                        position[] = { 0,-9,0 };
                    };
                    class Unit4 {
                        side = 0;
                        vehicle = "uksf_Base_Rifleman";
                        rank = "PRIVATE";
                        position[] = { 0,-12,0 };
                    };
                    class Unit5 {
                        side = 0;
                        vehicle = "uksf_Base_Rifleman";
                        rank = "PRIVATE";
                        position[] = { 0,-15,0 };
                    };
                    class Unit6 {
                        side = 0;
                        vehicle = "uksf_Base_LAT";
                        rank = "PRIVATE";
                        position[] = { 0,-18,0 };
                    };
                    class Unit7 {
                        side = 0;
                        vehicle = "uksf_Base_Marksman";
                        rank = "PRIVATE";
                        position[] = { 0,-21,0 };
                    };
                };
                class UKSF_Base_MGTeam {
                    name = "MG Section";
                    faction = "UKSF_Base_Faction";
                    rarityGroup = 0.5;
                    side = 0;
                    class Unit0 {
                        side = 0;
                        vehicle = "uksf_Base_SL";
                        rank = "SERGEANT";
                        position[] = { 0,0,0 };
                    };
                    class Unit1 {
                        side = 0;
                        vehicle = "uksf_Base_MG_Ammobearer";
                        rank = "PRIVATE";
                        position[] = { 0,-3,0 };
                    };
                    class Unit2 {
                        side = 0;
                        vehicle = "uksf_Base_MG";
                        rank = "PRIVATE";
                        position[] = { 0,-6,0 };
                    };
                    class Unit3 {
                        side = 0;
                        vehicle = "uksf_Base_MG_Ammobearer";
                        rank = "PRIVATE";
                        position[] = { 0,-9,0 };
                    };
                    class Unit4 {
                        side = 0;
                        vehicle = "uksf_Base_MG";
                        rank = "PRIVATE";
                        position[] = { 0,-12,0 };
                    };
                    class Unit5 {
                        side = 0;
                        vehicle = "uksf_Base_MG_Ammobearer";
                        rank = "PRIVATE";
                        position[] = { 0,-15,0 };
                    };
                    class Unit6 {
                        side = 0;
                        vehicle = "uksf_Base_MG";
                        rank = "PRIVATE";
                        position[] = { 0,-18,0 };
                    };
                    class Unit7 {
                        side = 0;
                        vehicle = "uksf_Base_HAT";
                        rank = "CORPORAL";
                        position[] = { 0,-21,0 };
                    };
                };
                class UKSF_Base_ATTeam {
                    name = "AT Section";
                    faction = "UKSF_Base_Faction";
                    rarityGroup = 0.5;
                    side = 0;
                    class Unit0 {
                        side = 0;
                        vehicle = "uksf_Base_SL";
                        rank = "SERGEANT";
                        position[] = { 0,0,0 };
                    };
                    class Unit1 {
                        side = 0;
                        vehicle = "uksf_Base_HAT";
                        rank = "PRIVATE";
                        position[] = { 0,-3,0 };
                    };
                    class Unit2 {
                        side = 0;
                        vehicle = "uksf_Base_HAT_Ammobearer";
                        rank = "PRIVATE";
                        position[] = { 0,-6,0 };
                    };
                    class Unit3 {
                        side = 0;
                        vehicle = "uksf_Base_HAT";
                        rank = "PRIVATE";
                        position[] = { 0,-9,0 };
                    };
                    class Unit4 {
                        side = 0;
                        vehicle = "uksf_Base_HAT_Ammobearer";
                        rank = "PRIVATE";
                        position[] = { 0,-12,0 };
                    };
                    class Unit5 {
                        side = 0;
                        vehicle = "uksf_Base_HAT";
                        rank = "PRIVATE";
                        position[] = { 0,-15,0 };
                    };
                    class Unit6 {
                        side = 0;
                        vehicle = "uksf_Base_HAT_Ammobearer";
                        rank = "PRIVATE";
                        position[] = { 0,-18,0 };
                    };
                    class Unit7 {
                        side = 0;
                        vehicle = "uksf_Base_Marksman";
                        rank = "CORPORAL";
                        position[] = { 0,-21,0 };
                    };
                };
                class UKSF_Base_12 {
                    name = "12 Man Group";
                    faction = "UKSF_Base_Faction";
                    rarityGroup = 0.5;
                    side = 0;
                    class Unit0 {
                        side = 0;
                        vehicle = "uksf_Base_Officer";
                        rank = "LIEUTENANT";
                        position[] = { 0,-3,0 };
                    };
                    class Unit1 {
                        side = 0;
                        vehicle = "uksf_Base_RadioOperator";
                        rank = "PRIVATE";
                        position[] = { 0,-6,0 };
                    };
                    class Unit2 {
                        side = 0;
                        vehicle = "uksf_Base_HAT";
                        rank = "PRIVATE";
                        position[] = { 0,-9,0 };
                    };
                    class Unit3 {
                        side = 0;
                        vehicle = "uksf_Base_MG";
                        rank = "PRIVATE";
                        position[] = { 0,-12,0 };
                    };
                    class Unit4 {
                        side = 0;
                        vehicle = "uksf_Base_Rifleman";
                        rank = "CORPORAL";
                        position[] = { 0,-15,0 };
                    };
                    class Unit5 {
                        side = 0;
                        vehicle = "uksf_Base_LMG";
                        rank = "PRIVATE";
                        position[] = { 0,-18,0 };
                    };
                    class Unit6 {
                        side = 0;
                        vehicle = "uksf_Base_Rifleman";
                        rank = "PRIVATE";
                        position[] = { 0,-21,0 };
                    };
                    class Unit7 {
                        side = 0;
                        vehicle = "uksf_Base_Rifleman";
                        rank = "PRIVATE";
                        position[] = { 0,-24,0 };
                    };
                    class Unit8 {
                        side = 0;
                        vehicle = "uksf_Base_Rifleman";
                        rank = "CORPORAL";
                        position[] = { 0,-27,0 };
                    };
                    class Unit9 {
                        side = 0;
                        vehicle = "uksf_Base_LAT";
                        rank = "PRIVATE";
                        position[] = { 0,-30,0 };
                    };
                    class Unit10 {
                        side = 0;
                        vehicle = "uksf_Base_Marksman";
                        rank = "PRIVATE";
                        position[] = { 0,-33,0 };
                    };
                    class Unit11 {
                        side = 0;
                        vehicle = "uksf_Base_Rifleman";
                        rank = "PRIVATE";
                        position[] = { 0,-36,0 };
                    };
                };
                class UKSF_Base_Snipers {
                    name = "Sniper Pair";
                    faction = "UKSF_Base_Faction";
                    rarityGroup = 0.5;
                    side = 0;
                    class Unit0 {
                        side = 0;
                        vehicle = "uksf_Base_Sniper";
                        rank = "CORPORAL";
                        position[] = { 0,0,0 };
                    };
                    class Unit1 {
                        side = 0;
                        vehicle = "uksf_Base_Sniper";
                        rank = "PRIVATE";
                        position[] = { 0,-3,0 };
                    };
                };
                class UKSF_Base_HQTeam {
                    name = "HQ Team";
                    faction = "UKSF_Base_Faction";
                    rarityGroup = 0.5;
                    side = 0;
                    class Unit0 {
                        side = 0;
                        vehicle = "uksf_Base_Officer";
                        rank = "LIEUTENANT";
                        position[] = { 0,0,0 };
                    };
                    class Unit1 {
                        side = 0;
                        vehicle = "uksf_Base_SL";
                        rank = "SERGEANT";
                        position[] = { 0,-3,0 };
                    };
                    class Unit2 {
                        side = 0;
                        vehicle = "uksf_Base_RadioOperator";
                        rank = "PRIVATE";
                        position[] = { 0,-6,0 };
                    };
                    class Unit3 {
                        side = 0;
                        vehicle = "uksf_Base_RadioOperator";
                        rank = "PRIVATE";
                        position[] = { 0,-9,0 };
                    };
                };
                class UKSF_Base_Crew {
                    name = "Vehicle Crew";
                    faction = "UKSF_Base_Faction";
                    rarityGroup = 0.5;
                    side = 0;
                    class Unit0 {
                        side = 0;
                        vehicle = "uksf_Base_Crewman";
                        rank = "SERGEANT";
                        position[] = { 0,0,0 };
                    };
                    class Unit1 {
                        side = 0;
                        vehicle = "uksf_Base_Crewman";
                        rank = "PRIVATE";
                        position[] = { 0,-3,0 };
                    };
                    class Unit2 {
                        side = 0;
                        vehicle = "uksf_Base_Crewman";
                        rank = "PRIVATE";
                        position[] = { 0,-6,0 };
                    };
                };
                class UKSF_Base_AATeam {
                    name = "AA Team";
                    faction = "UKSF_Base_Faction";
                    rarityGroup = 0.5;
                    side = 0;
                    class Unit0 {
                        side = 0;
                        vehicle = "uksf_Base_SL";
                        rank = "SERGEANT";
                        position[] = { 0,0,0 };
                    };
                    class Unit1 {
                        side = 0;
                        vehicle = "uksf_Base_AA";
                        rank = "PRIVATE";
                        position[] = { 0,-3,0 };
                    };
                    class Unit2 {
                        side = 0;
                        vehicle = "uksf_Base_AA";
                        rank = "PRIVATE";
                        position[] = { 0,-6,0 };
                    };
                    class Unit3 {
                        side = 0;
                        vehicle = "uksf_Base_AA";
                        rank = "PRIVATE";
                        position[] = { 0,-9,0 };
                    };
                };
                class UKSF_Base_TACP {
                    name = "TACP";
                    faction = "UKSF_Base_Faction";
                    rarityGroup = 0.5;
                    side = 0;
                    class Unit0 {
                        side = 0;
                        vehicle = "uksf_Base_SL";
                        rank = "SERGEANT";
                        position[] = { 0,0,0 };
                    };
                    class Unit1 {
                        side = 0;
                        vehicle = "uksf_Base_RadioOperator";
                        rank = "PRIVATE";
                        position[] = { 0,-3,0 };
                    };
                    class Unit2 {
                        side = 0;
                        vehicle = "uksf_Base_RadioOperator";
                        rank = "PRIVATE";
                        position[] = { 0,-6,0 };
                    };
                    class Unit3 {
                        side = 0;
                        vehicle = "uksf_Base_Sniper";
                        rank = "PRIVATE";
                        position[] = { 0,-9,0 };
                    };
                };
            };
            class Recce {
                name = "Recce";
                aliveCategory = "Recce";
                class UKSF_Base_Recce_TeamL {
                    name = "Recce Team (Light)";
                    faction = "UKSF_Base_Faction";
                    rarityGroup = 0.5;
                    side = 0;
                    class Unit0 {
                        side = 0;
                        vehicle = "uksf_Base_Recce_TL";
                        rank = "SERGEANT";
                        position[] = { 0,0,0 };
                    };
                    class Unit1 {
                        side = 0;
                        vehicle = "uksf_Base_Recce_Rifleman";
                        rank = "PRIVATE";
                        position[] = { 0,-3,0 };
                    };
                    class Unit2 {
                        side = 0;
                        vehicle = "uksf_Base_Recce_Rifleman";
                        rank = "PRIVATE";
                        position[] = { 0,-6,0 };
                    };
                    class Unit3 {
                        side = 0;
                        vehicle = "uksf_Base_Recce_Marksman";
                        rank = "PRIVATE";
                        position[] = { 0,-9,0 };
                    };
                };
                class UKSF_Base_Recce_TeamH {
                    name = "Recce Team (Heavy)";
                    faction = "UKSF_Base_Faction";
                    rarityGroup = 0.5;
                    side = 0;
                    class Unit0 {
                        side = 0;
                        vehicle = "uksf_Base_Recce_TL";
                        rank = "SERGEANT";
                        position[] = { 0,0,0 };
                    };
                    class Unit1 {
                        side = 0;
                        vehicle = "uksf_Base_Recce_LAT";
                        rank = "PRIVATE";
                        position[] = { 0,-3,0 };
                    };
                    class Unit2 {
                        side = 0;
                        vehicle = "uksf_Base_Recce_MG";
                        rank = "PRIVATE";
                        position[] = { 0,-6,0 };
                    };
                    class Unit3 {
                        side = 0;
                        vehicle = "uksf_Base_Recce_Marksman";
                        rank = "PRIVATE";
                        position[] = { 0,-9,0 };
                    };
                };
                class UKSF_Base_Recce_Full {
                    name = "Recce Team (Full)";
                    faction = "UKSF_Base_Faction";
                    rarityGroup = 0.5;
                    side = 0;
                    class Unit0 {
                        side = 0;
                        vehicle = "uksf_Base_Recce_TL";
                        rank = "SERGEANT";
                        position[] = { 0,0,0 };
                    };
                    class Unit1 {
                        side = 0;
                        vehicle = "uksf_Base_Recce_LAT";
                        rank = "PRIVATE";
                        position[] = { 0,-3,0 };
                    };
                    class Unit2 {
                        side = 0;
                        vehicle = "uksf_Base_Recce_MG";
                        rank = "PRIVATE";
                        position[] = { 0,-6,0 };
                    };
                    class Unit3 {
                        side = 0;
                        vehicle = "uksf_Base_Recce_Marksman";
                        rank = "PRIVATE";
                        position[] = { 0,-9,0 };
                    };
                    class Unit4 {
                        side = 0;
                        vehicle = "uksf_Base_Recce_RadioOperator";
                        rank = "PRIVATE";
                        position[] = { 0,-12,0 };
                    };
                    class Unit5 {
                        side = 0;
                        vehicle = "uksf_Base_Recce_Rifleman";
                        rank = "PRIVATE";
                        position[] = { 0,-15,0 };
                    };
                };
            };
            class Paratroopers {
                name = "Paratroopers";
                aliveCategory = "Paratroopers";
                class UKSF_Base_Para_Section {
                    name = "Paratrooper Section";
                    faction = "UKSF_Base_Faction";
                    rarityGroup = 0.5;
                    side = 0;
                    class Unit0 {
                        side = 0;
                        vehicle = "uksf_Base_Paratrooper_SL";
                        rank = "SERGEANT";
                        position[] = { 0,0,0 };
                    };
                    class Unit1 {
                        side = 0;
                        vehicle = "uksf_Base_Paratrooper";
                        rank = "PRIVATE";
                        position[] = { 0,-3,0 };
                    };
                    class Unit2 {
                        side = 0;
                        vehicle = "uksf_Base_Paratrooper";
                        rank = "PRIVATE";
                        position[] = { 0,-6,0 };
                    };
                    class Unit3 {
                        side = 0;
                        vehicle = "uksf_Base_Paratrooper_LAT";
                        rank = "PRIVATE";
                        position[] = { 0,-9,0 };
                    };
                    class Unit4 {
                        side = 0;
                        vehicle = "uksf_Base_Paratrooper";
                        rank = "CORPORAL";
                        position[] = { 0,-12,0 };
                    };
                    class Unit5 {
                        side = 0;
                        vehicle = "uksf_Base_Paratrooper_MG";
                        rank = "PRIVATE";
                        position[] = { 0,-15,0 };
                    };
                    class Unit6 {
                        side = 0;
                        vehicle = "uksf_Base_Paratrooper_Marksman";
                        rank = "PRIVATE";
                        position[] = { 0,-18,0 };
                    };
                    class Unit7 {
                        side = 0;
                        vehicle = "uksf_Base_Paratrooper_LAT";
                        rank = "PRIVATE";
                        position[] = { 0,-21,0 };
                    };
                };
                class UKSF_Base_Para_HQTeam {
                    name = "Paratrooper HQ Team";
                    faction = "UKSF_Base_Faction";
                    rarityGroup = 0.5;
                    side = 0;
                    class Unit0 {
                        side = 0;
                        vehicle = "uksf_Base_Paratrooper_SL";
                        rank = "LIEUTENANT";
                        position[] = { 0,0,0 };
                    };
                    class Unit1 {
                        side = 0;
                        vehicle = "uksf_Base_Paratrooper_RadioOperator";
                        rank = "PRIVATE";
                        position[] = { 0,-3,0 };
                    };
                    class Unit2 {
                        side = 0;
                        vehicle = "uksf_Base_Paratrooper_RadioOperator";
                        rank = "PRIVATE";
                        position[] = { 0,-6,0 };
                    };
                    class Unit3 {
                        side = 0;
                        vehicle = "uksf_Base_Paratrooper_LAT";
                        rank = "PRIVATE";
                        position[] = { 0,-9,0 };
                    };
                    class Unit4 {
                        side = 0;
                        vehicle = "uksf_Base_Paratrooper";
                        rank = "SERGEANT";
                        position[] = { 0,-12,0 };
                    };
                };
            };
            class SF {
                name = "Special Forces";
                aliveCategory = "Special Forces";
                class UKSF_Base_SF_StrikeTeam {
                    name = "SF Strike Team";
                    faction = "UKSF_Base_Faction";
                    rarityGroup = 0.5;
                    side = 0;
                    class Unit0 {
                        side = 0;
                        vehicle = "uksf_Base_SF_TL";
                        rank = "SERGEANT";
                        position[] = { 0,0,0 };
                    };
                    class Unit1 {
                        side = 0;
                        vehicle = "uksf_Base_SF_Operator";
                        rank = "PRIVATE";
                        position[] = { 0,-3,0 };
                    };
                    class Unit2 {
                        side = 0;
                        vehicle = "uksf_Base_SF_Operator";
                        rank = "PRIVATE";
                        position[] = { 0,-6,0 };
                    };
                    class Unit3 {
                        side = 0;
                        vehicle = "uksf_Base_SF_Operator";
                        rank = "PRIVATE";
                        position[] = { 0,-9,0 };
                    };
                };
                class UKSF_Base_SF_OverwatchTeam {
                    name = "SF Overwatch Team";
                    faction = "UKSF_Base_Faction";
                    rarityGroup = 0.5;
                    side = 0;
                    class Unit0 {
                        side = 0;
                        vehicle = "uksf_Base_SF_TL";
                        rank = "SERGEANT";
                        position[] = { 0,0,0 };
                    };
                    class Unit1 {
                        side = 0;
                        vehicle = "uksf_Base_SF_LAT";
                        rank = "PRIVATE";
                        position[] = { 0,-3,0 };
                    };
                    class Unit2 {
                        side = 0;
                        vehicle = "uksf_Base_SF_Marksman";
                        rank = "PRIVATE";
                        position[] = { 0,-6,0 };
                    };
                    class Unit3 {
                        side = 0;
                        vehicle = "uksf_Base_SF_MG";
                        rank = "PRIVATE";
                        position[] = { 0,-9,0 };
                    };
                };
                class UKSF_Base_SF_HQTeam {
                    name = "SF HQ Team";
                    faction = "UKSF_Base_Faction";
                    rarityGroup = 0.5;
                    side = 0;
                    class Unit0 {
                        side = 0;
                        vehicle = "uksf_Base_SF_Officer";
                        rank = "LIEUTENANT";
                        position[] = { 0,0,0 };
                    };
                    class Unit1 {
                        side = 0;
                        vehicle = "uksf_Base_SF_RadioOperator";
                        rank = "PRIVATE";
                        position[] = { 0,-3,0 };
                    };
                    class Unit2 {
                        side = 0;
                        vehicle = "uksf_Base_SF_Operator";
                        rank = "PRIVATE";
                        position[] = { 0,-6,0 };
                    };
                    class Unit3 {
                        side = 0;
                        vehicle = "uksf_Base_SF_Operator";
                        rank = "PRIVATE";
                        position[] = { 0,-9,0 };
                    };
                };
            };
        };
    };
};
