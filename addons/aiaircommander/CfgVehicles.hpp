class CfgVehicles {
    class Logic;
    class Module_F : Logic {
        class AttributesBase;
    };
    class GVAR(aiAirCommanderModule) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "Commander Module";
        icon = "A3\ui_f\data\map\markers\nato\o_hq.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_hq.paa";
        function = QFUNC(moduleAirCommanderInit);
        functionPriority = 1;
        canSetArea = 0;
        canSetAreaHeight = 0;
        canSetAreaShape = 0;
        category = GVAR(aiAirCommander);
    };
    class GVAR(aaSiteModule) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "AA Site";
        icon = "A3\ui_f\data\map\markers\nato\o_installation.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_installation.paa";
        function = QFUNC(moduleAASite);
        functionPriority = 1;
        canSetArea = 0;
        canSetAreaHeight = 0;
        canSetAreaShape = 0;
        category = GVAR(aiAirCommander);
    };
    class GVAR(aaSpawnLocationModule) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "AA Spawn Location";
        icon = "A3\ui_f\data\map\markers\nato\o_antiair.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_antiair.paa";
        function = QFUNC(moduleAASpawnLocation);
        functionPriority = 1;
        canSetArea = 0;
        canSetAreaHeight = 0;
        canSetAreaShape = 0;
        category = GVAR(aiAirCommander);
    };
    class GVAR(airspaceCentreModule) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "Airspace Centre";
        icon = "A3\modules_f\data\iconmodule_ca.paa";
        portrait = "A3\modules_f\data\iconmodule_ca.paa";
        function = QFUNC(moduleAirspaceCentre);
        functionPriority = 1;
        canSetArea = 0;
        canSetAreaHeight = 0;
        canSetAreaShape = 0;
        category = GVAR(aiAirCommander);
    };
    class GVAR(airSpawnLocationModule) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "Air Spawn Location";
        icon = "A3\ui_f\data\map\markers\nato\o_plane.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_plane.paa";
        function = QFUNC(moduleAirSpawnLocation);
        functionPriority = 1;
        canSetArea = 0;
        canSetAreaHeight = 0;
        canSetAreaShape = 0;
        category = GVAR(aiAirCommander);
    };
    class GVAR(enemyAirfieldModule) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "Enemy Airfield";
        icon = "A3\ui_f\data\map\markers\nato\o_service.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_service.paa";
        function = QFUNC(moduleEnemyAirfield);
        functionPriority = 1;
        canSetArea = 0;
        canSetAreaHeight = 0;
        canSetAreaShape = 0;
        category = GVAR(aiAirCommander);
    };
    class GVAR(heliLocationModule) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "Helicopter Spawn Location";
        icon = "A3\ui_f\data\map\markers\nato\o_air.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_air.paa";
        function = QFUNC(moduleHeliLocation);
        functionPriority = 1;
        canSetArea = 0;
        canSetAreaHeight = 0;
        canSetAreaShape = 0;
        category = GVAR(aiAirCommander);
    };
};
