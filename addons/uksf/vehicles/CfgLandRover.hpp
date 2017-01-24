//Unarmed
class Genfor_LandRover_Unarmed;
class UKSF_LandRover_Unarmed : Genfor_LandRover_Unarmed {
    scope = 2;
    side = 1;
    faction = "UKSF_Clan";
    editorPreview = QPATHTOEF(common,data\previews\UKSF_LandRover_Unarmed.jpg);
    displayName = "Land Rover";
    crew = "UKSF_Clan_R";
    typicalCargo[] = {
        "UKSF_Clan_R",
        "UKSF_Clan_R",
        "UKSF_Clan_R",
        "UKSF_Clan_R",
        "UKSF_Clan_R"
    };
};

//MG
class B_mas_cars_LR_BASE;
class B_mas_cars_LR_M2 : B_mas_cars_LR_BASE {
    class ACE_Actions;
};
class Genfor_LandRover_MG : B_mas_cars_LR_M2 {
    class ACE_Actions : ACE_Actions {
        class ACE_MainActions;
    };
};
class UKSF_LandRover_MG : Genfor_LandRover_MG {
    scope = 2;
    side = 1;
    faction = "UKSF_Clan";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_LandRover_MG.jpg);
    displayName = "Land Rover MG";
    crew = "UKSF_Clan_R";
    typicalCargo[] = {
        "UKSF_Clan_R",
        "UKSF_Clan_R",
        "UKSF_Clan_R",
        "UKSF_Clan_R",
        "UKSF_Clan_R"
    };
    class ACE_Actions : ACE_Actions {
        class ACE_MainActions : ACE_MainActions {
            class ACE_deployNetWoodland {
                displayName = "Deploy Net (Woodland)";
                condition = QUOTE(!(_target getVariable [ARR_2(QQGVAR(deployed), false)]) && (isNull (_target getVariable [ARR_2(QQGVAR(netObj), objNull)])));
                statement = QUOTE([ARR_3(_target, _player, 'CamoNet_BLUFOR_big_F')] call EFUNC(common,deployNet));
                showDisabled = 0;
                priority = 1;
            };
            class ACE_deployNetDesert {
                displayName = "Deploy Net (Desert)";
                condition = QUOTE(!(_target getVariable [ARR_2(QQGVAR(deployed), false)]) && (isNull (_target getVariable [ARR_2(QQGVAR(netObj), objNull)])));
                statement = QUOTE([ARR_3(_target, _player, 'Land_CamoNetB_NATO_EP1')] call EFUNC(common,deployNet));
                showDisabled = 0;
                priority = 1;
            };
            class ACE_concealNet {
                displayName = "Conceal Net";
                condition = QUOTE((_target getVariable [ARR_2(QQGVAR(deployed), false)]) && !(isNull (_target getVariable [ARR_2(QQGVAR(netObj), objNull)])) && ((_target distance (_target getVariable [ARR_2(QQGVAR(netObj), objNull)])) < 10));
                statement = QUOTE([ARR_2(_target, _player)] call EFUNC(common,concealNet));
                showDisabled = 0;
                priority = 1;
            };
        };
    };
};
class UKSF_LandRover_MG_Desert : UKSF_LandRover_MG {
    displayName = "Land Rover MG (D)";
    hiddenSelections[] = { "Camo1" };
    hiddenSelectionsTextures[] = { QPATHTOF(data\base_desert.paa) };
};

//GL
class B_mas_cars_LR_Mk19 : B_mas_cars_LR_M2 {
    class ACE_Actions;
};
class Genfor_LandRover_GL : B_mas_cars_LR_Mk19 {
    class ACE_Actions : ACE_Actions {
        class ACE_MainActions;
    };
};
class UKSF_LandRover_GL : Genfor_LandRover_GL {
    scope = 2;
    side = 1;
    faction = "UKSF_Clan";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_LandRover_GL.jpg);
    displayName = "Land Rover GL";
    crew = "UKSF_Clan_R";
    typicalCargo[] = {
        "UKSF_Clan_R",
        "UKSF_Clan_R",
        "UKSF_Clan_R",
        "UKSF_Clan_R",
        "UKSF_Clan_R"
    };
    class ACE_Actions : ACE_Actions {
        class ACE_MainActions : ACE_MainActions {
            class ACE_deployNetWoodland {
                displayName = "Deploy Net (Woodland)";
                condition = QUOTE(!(_target getVariable [ARR_2(QQGVAR(deployed), false)]) && (isNull (_target getVariable [ARR_2(QQGVAR(netObj), objNull)])));
                statement = QUOTE([ARR_3(_target, _player, 'CamoNet_BLUFOR_big_F')] call EFUNC(common,deployNet));
                showDisabled = 0;
                priority = 1;
            };
            class ACE_deployNetDesert {
                displayName = "Deploy Net (Desert)";
                condition = QUOTE(!(_target getVariable [ARR_2(QQGVAR(deployed), false)]) && (isNull (_target getVariable [ARR_2(QQGVAR(netObj), objNull)])));
                statement = QUOTE([ARR_3(_target, _player, 'Land_CamoNetB_NATO_EP1')] call EFUNC(common,deployNet));
                showDisabled = 0;
                priority = 1;
            };
            class ACE_concealNet {
                displayName = "Conceal Net";
                condition = QUOTE((_target getVariable [ARR_2(QQGVAR(deployed), false)]) && !(isNull (_target getVariable [ARR_2(QQGVAR(netObj), objNull)])) && ((_target distance (_target getVariable [ARR_2(QQGVAR(netObj), objNull)])) < 10));
                statement = QUOTE([ARR_2(_target, _player)] call EFUNC(common,concealNet));
                showDisabled = 0;
                priority = 1;
            };
        };
    };
};
class UKSF_LandRover_GL_Desert : UKSF_LandRover_GL {
    displayName = "Land Rover GL (D)";
    hiddenSelections[] = { "Camo1" };
    hiddenSelectionsTextures[] = { QPATHTOF(data\base_desert.paa) };
};

//Medical
class B_mas_cars_LR_Unarmed;
class B_mas_cars_LR_Med : B_mas_cars_LR_Unarmed {
    class ACE_Actions;
};
class Genfor_LandRover_Medical : B_mas_cars_LR_Med {
    class ACE_Actions : ACE_Actions {
        class ACE_MainActions;
    };
};
class UKSF_LandRover_Medical : Genfor_LandRover_Medical {
    scope = 2;
    side = 1;
    faction = "UKSF_Clan";
    displayName = "Land Rover Medical";
    editorPreview = QPATHTOEF(common,data\previews\UKSF_LandRover_Medical.jpg);
    attendant = 1;
    crew = "UKSF_Clan_R";
    typicalCargo[] = {
        "UKSF_Clan_R",
        "UKSF_Clan_R",
        "UKSF_Clan_MED",
        "UKSF_Clan_MED",
        "UKSF_Clan_MED"
    };
    class TransportItems {
        class _xx_ACE_EarPlugs {
            name = "ACE_EarPlugs";
            count = 10;
        };
        class _xx_ACE_packingBandage {
            name = "ACE_packingBandage";
            count = 50;
        };
        class _xx_ACE_elasticBandage {
            name = "ACE_elasticBandage";
            count = 50;
        };
        class _xx_ACE_morphine {
            name = "ACE_morphine";
            count = 30;
        };
        class _xx_ACE_epinephrine {
            name = "ACE_epinephrine";
            count = 30;
        };
        class _xx_ACE_bloodIVItem {
            name = "ACE_bloodIVItem";
            count = 20;
        };
        class _xx_ACE_personalAidKit {
            name = "ACE_personalAidKit";
            count = 10;
        };
    };
    class ACE_Actions : ACE_Actions {
        class ACE_MainActions : ACE_MainActions {
            class ACE_deployNetWoodland {
                displayName = "Deploy Medical Net (Woodland)";
                condition = QUOTE(!(_target getVariable [ARR_2(QQGVAR(deployed), false)]) && (isNull (_target getVariable [ARR_2(QQGVAR(netObj), objNull)])));
                statement = "";
                class ACE_left {
                    displayName = "Left";
                    condition = QUOTE(!(_target getVariable [ARR_2(QQGVAR(deployed), false)]) && (isNull (_target getVariable [ARR_2(QQGVAR(netObj), objNull)])));
                    statement = QUOTE([ARR_4(_target, _player, 'CamoNet_BLUFOR_open_F', [ARR_3(-2.75,0,-1)])] call EFUNC(common,deployNetMedical));
                    showDisabled = 0;
                    priority = 1;
                };
                class ACE_right {
                    displayName = "Right";
                    condition = QUOTE(!(_target getVariable [ARR_2(QQGVAR(deployed), false)]) && (isNull (_target getVariable [ARR_2(QQGVAR(netObj), objNull)])));
                    statement = QUOTE([ARR_4(_target, _player, 'CamoNet_BLUFOR_open_F', [ARR_3(1.75,0,-1)])] call EFUNC(common,deployNetMedical));
                    showDisabled = 0;
                    priority = 1;
                };
            };
            class ACE_deployNetDesert {
                displayName = "Deploy Medical Net (Desert)";
                condition = QUOTE(!(_target getVariable [ARR_2(QQGVAR(deployed), false)]) && (isNull (_target getVariable [ARR_2(QQGVAR(netObj), objNull)])));
                statement = "";
                class ACE_left {
                    displayName = "Left";
                    condition = QUOTE(!(_target getVariable [ARR_2(QQGVAR(deployed), false)]) && (isNull (_target getVariable [ARR_2(QQGVAR(netObj), objNull)])));
                    statement = QUOTE([ARR_4(_target, _player, 'Land_CamoNetVar_NATO_EP1', [ARR_3(-2.75,0,-1)])] call EFUNC(common,deployNetMedical));
                    showDisabled = 0;
                    priority = 1;
                };
                class ACE_right {
                    displayName = "Right";
                    condition = QUOTE(!(_target getVariable [ARR_2(QQGVAR(deployed), false)]) && (isNull (_target getVariable [ARR_2(QQGVAR(netObj), objNull)])));
                    statement = QUOTE([ARR_4(_target, _player, 'Land_CamoNetVar_NATO_EP1', [ARR_3(1.75,0,-1)])] call EFUNC(common,deployNetMedical));
                    showDisabled = 0;
                    priority = 1;
                };
            };
            class ACE_concealNet {
                displayName = "Conceal Medical Net";
                condition = QUOTE((_target getVariable [ARR_2(QQGVAR(deployed), false)]) && !(isNull (_target getVariable [ARR_2(QQGVAR(netObj), objNull)])) && ((_target distance (_target getVariable [ARR_2(QQGVAR(netObj), objNull)])) < 10));
                statement = QUOTE([ARR_2(_target, _player)] call EFUNC(common,concealNet));
                showDisabled = 0;
                priority = 1;
            };
        };
    };
};
