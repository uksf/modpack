class CfgGroups {
    class East {
        name = "OPFOR";
        side = 0;
        class UKSF_PROR {
            name = "Peoples Republic of Rosche";
            class Infantry {
                name = "Infantry";
                aliveCategory = "Infantry";
                // Regular
                class PROR_InfSection {
                    faction = "UKSF_PROR";
                    name = "Infantry Section";
                    side = 0;
                    class Unit0 {
                        position[] = { 0, 0, 0 };
                        rank = "SERGEANT";
                        side = 0;
                        vehicle = "PROR_AR";
                    };
                    class Unit1 {
                        position[] = { 5, -5, 0 };
                        rank = "CORPORAL";
                        side = 0;
                        vehicle = "PROR_SL";
                    };
                    class Unit2 {
                        position[] = { -5, -5, 0 };
                        rank = "PRIVATE";
                        side = 0;
                        vehicle = "PROR_Rfn";
                    };
                    class Unit3 {
                        position[] = { 10, -10, 0 };
                        rank = "PRIVATE";
                        side = 0;
                        vehicle = "PROR_Rfn";
                    };
                    class Unit4 {
                        position[] = { -10, -10, 0 };
                        rank = "PRIVATE";
                        side = 0;
                        vehicle = "PROR_AT_L";
                    };
                    class Unit5 {
                        position[] = { 15, -15, 0 };
                        rank = "CORPORAL";
                        side = 0;
                        vehicle = "PROR_Rfn";
                    };
                    class Unit6 {
                        position[] = { -15, -15, 0 };
                        rank = "PRIVATE";
                        side = 0;
                        vehicle = "PROR_AR";
                    };
                    class Unit7 {
                        position[] = { 20, -20, 0 };
                        rank = "PRIVATE";
                        side = 0;
                        vehicle = "PROR_Rfn";
                    };
                };
            };
            // class Armored {
            //     name = "Armored";
            //     aliveCategory = "Armored";
            //     class Inegal_Tank_Section {
            //         name = "Leclerc Section";
            //         faction = "UKSF_Inegal";
            //         rarityGroup = 0.5;
            //         side = 0;
            //         class Unit0 {
            //             side = 0;
            //             vehicle = "Inegal_Tank_Leclerc";
            //             rank = "MAJOR";
            //             position[] = { 0, 0, 0 };
            //         };
            //         class Unit1 {
            //             side = 0;
            //             vehicle = "Inegal_Tank_Leclerc";
            //             rank = "LIEUTENANT";
            //             position[] = { -10, -10, 0 };
            //         };
            //     };
            //     class Inegal_Tank_Platoon {
            //         name = "Leclerc Platoon";
            //         faction = "UKSF_Inegal";
            //         rarityGroup = 0.5;
            //         side = 0;
            //         class Unit0 {
            //             side = 0;
            //             vehicle = "Inegal_Tank_Leclerc";
            //             rank = "MAJOR";
            //             position[] = { 0, 0, 0 };
            //         };
            //         class Unit1 {
            //             side = 0;
            //             vehicle = "Inegal_Tank_Leclerc";
            //             rank = "LIEUTENANT";
            //             position[] = { -10, -10, 0 };
            //         };
            //         class Unit2 {
            //             side = 0;
            //             vehicle = "Inegal_Tank_Leclerc";
            //             rank = "LIEUTENANT";
            //             position[] = { -20, -20, 0 };
            //         };
            //         class Unit3 {
            //             side = 0;
            //             vehicle = "Inegal_Tank_Leclerc";
            //             rank = "LIEUTENANT";
            //             position[] = { 10, -10, 0 };
            //         };
            //     };
            // };
            // class Mechanized {
            //     name = "Mechanized";
            //     aliveCategory = "Mechanized";
            //     class Inegal_VBCI {
            //         name = "VBCI Group";
            //         faction = "UKSF_Inegal";
            //         rarityGroup = 0.5;
            //         side = 0;
            //         class Unit0 {
            //             side = 0;
            //             vehicle = "Inegal_APC_VBCI";
            //             rank = "LIEUTENANT";
            //             position[] = { 0, 0, 0 };
            //         };
            //         class Unit1 {
            //             side = 0;
            //             vehicle = "Inegal_APC_VBCI";
            //             rank = "PRIVATE";
            //             position[] = { -10, -10, 0 };
            //         };
            //     };
            // };
            // class Motorized {
            //     name = "Motorized";
            //     aliveCategory = "Motorized";
            //     class Inegal_VAB_Convoy {
            //         name = "VAB Convoy";
            //         faction = "UKSF_Inegal";
            //         rarityGroup = 0.5;
            //         side = 0;
            //         class Unit0 {
            //             side = 0;
            //             vehicle = "Inegal_VAB_HMG";
            //             rank = "LIEUTENANT";
            //             position[] = { 0, 0, 0 };
            //         };
            //         class Unit1 {
            //             side = 0;
            //             vehicle = "Inegal_VAB_Unarmed";
            //             rank = "PRIVATE";
            //             position[] = { 0, -10, 0 };
            //         };
            //         class Unit2 {
            //             side = 0;
            //             vehicle = "Inegal_VAB_Unarmed";
            //             rank = "CORPORAL";
            //             position[] = { 0, -20, 0 };
            //         };
            //         class Unit3 {
            //             side = 0;
            //             vehicle = "Inegal_VAB_GMG";
            //             rank = "CORPORAL";
            //             position[] = { 0, -30, 0 };
            //         };
            //     };
            //     class Inegal_LR_Convoy {
            //         name = "Land Rover Convoy";
            //         faction = "UKSF_Inegal";
            //         rarityGroup = 0.5;
            //         side = 0;
            //         class Unit0 {
            //             side = 0;
            //             vehicle = "Inegal_LandRover_MG";
            //             rank = "LIEUTENANT";
            //             position[] = { 0, 0, 0 };
            //         };
            //         class Unit1 {
            //             side = 0;
            //             vehicle = "Inegal_LandRover_Unarmed";
            //             rank = "PRIVATE";
            //             position[] = { 0, -10, 0 };
            //         };
            //         class Unit2 {
            //             side = 0;
            //             vehicle = "Inegal_LandRover_Unarmed";
            //             rank = "CORPORAL";
            //             position[] = { 0, -20, 0 };
            //         };
            //         class Unit3 {
            //             side = 0;
            //             vehicle = "Inegal_LandRover_GL";
            //             rank = "CORPORAL";
            //             position[] = { 0, -30, 0 };
            //         };
            //     };
            //     class Inegal_VAB_Team {
            //         name = "VAB Team";
            //         faction = "UKSF_Inegal";
            //         rarityGroup = 0.5;
            //         side = 0;
            //         class Unit0 {
            //             side = 0;
            //             vehicle = "Inegal_VAB_HMG";
            //             rank = "LIEUTENANT";
            //             position[] = { 0, 0, 0 };
            //         };
            //         class Unit1 {
            //             side = 0;
            //             vehicle = "Inegal_VAB_GMG";
            //             rank = "PRIVATE";
            //             position[] = { 0, -10, 0 };
            //         };
            //     };
            //     class Inegal_LR_Team {
            //         name = "Land Rover Team";
            //         faction = "UKSF_Inegal";
            //         rarityGroup = 0.5;
            //         side = 0;
            //         class Unit0 {
            //             side = 0;
            //             vehicle = "Inegal_LandRover_MG";
            //             rank = "LIEUTENANT";
            //             position[] = { 0, 0, 0 };
            //         };
            //         class Unit1 {
            //             side = 0;
            //             vehicle = "Inegal_LandRover_GL";
            //             rank = "PRIVATE";
            //             position[] = { 0, -10, 0 };
            //         };
            //     };
            // };
            // class SpecOps {
            //     name = "SpecOps";
            //     aliveCategory = "SpecOps";
            // };
            // class Support {
            //     name = "Support";
            //     aliveCategory = "Support";
            //     class Inegal_TRM {
            //         name = "TRM Troop";
            //         faction = "UKSF_Inegal";
            //         rarityGroup = 0.5;
            //         side = 0;
            //         class Unit0 {
            //             side = 0;
            //             vehicle = "Inegal_TRM_Covered";
            //             rank = "LIEUTENANT";
            //             position[] = { 0, 0, 0 };
            //         };
            //         class Unit1 {
            //             side = 0;
            //             vehicle = "Inegal_TRM_Open";
            //             rank = "PRIVATE";
            //             position[] = { 0, -20, 0 };
            //         };
            //     };
            // };
            // class Air {
            //     name = "Air";
            //     aliveCategory = "Air";
            //     class Inegal_AH6 {
            //         name = "AH6 Flight";
            //         faction = "UKSF_Inegal";
            //         rarityGroup = 0.5;
            //         side = 0;
            //         class Unit0 {
            //             side = 0;
            //             vehicle = "Inegal_Heli_AH6";
            //             rank = "LIEUTENANT";
            //             position[] = { 0, 0, 0 };
            //         };
            //         class Unit1 {
            //             side = 0;
            //             vehicle = "Inegal_Heli_MH6";
            //             rank = "PRIVATE";
            //             position[] = { 10, 0, 0 };
            //         };
            //     };
            //     class Inegal_AW101 {
            //         name = "AW101 Flight";
            //         faction = "UKSF_Inegal";
            //         rarityGroup = 0.5;
            //         side = 0;
            //         class Unit0 {
            //             side = 0;
            //             vehicle = "Inegal_Heli_AH6";
            //             rank = "LIEUTENANT";
            //             position[] = { 0, 0, 0 };
            //         };
            //         class Unit1 {
            //             side = 0;
            //             vehicle = "Inegal_Heli_AW101";
            //             rank = "PRIVATE";
            //             position[] = { 30, 0, 0 };
            //         };
            //     };
            //     class Inegal_Fighter {
            //         name = "L-159 Flight";
            //         faction = "UKSF_Inegal";
            //         rarityGroup = 0.5;
            //         side = 0;
            //         class Unit0 {
            //             side = 0;
            //             vehicle = "Inegal_Jet_A149";
            //             rank = "LIEUTENANT";
            //             position[] = { 0, 0, 0 };
            //         };
            //         class Unit1 {
            //             side = 0;
            //             vehicle = "Inegal_Jet_A149";
            //             rank = "PRIVATE";
            //             position[] = { 30, 0, 0 };
            //         };
            //     };
            // };
        };
    };
};
