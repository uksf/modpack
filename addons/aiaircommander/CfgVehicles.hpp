class CfgVehicles {
    class Module_F;
    class GVAR(module) : Module_F {
        scope = 1;
        is3DEN = 1;
        functionPriority = 1;
        category = QUOTE(ADDON);
        class AttributesBase;
    };
    class GVAR(commanderModule) : GVAR(module) {
        scope = 2;
        displayName = "(AC) Commander Module";
        icon = "A3\ui_f\data\map\markers\nato\o_hq.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_hq.paa";
        function = QFUNC(moduleCommander);
    };
    class GVAR(airspaceCentreModule) : GVAR(module) {
        scope = 2;
        displayName = "(AC) Airspace Centre";
        icon = "A3\modules_f\data\iconmodule_ca.paa";
        portrait = "A3\modules_f\data\iconmodule_ca.paa";
        function = QFUNC(moduleAirspaceCentre);
    };
    class GVAR(enemyAirfieldModule) : GVAR(module) {
        scope = 2;
        is3DEN = 1;
        displayName = "(AC) Enemy Airfield";
        icon = "A3\ui_f\data\map\markers\nato\o_service.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_service.paa";
        function = QFUNC(moduleEnemyAirfield);
    };
    class GVAR(planeSpawnModule) : GVAR(module) {
        scope = 2;
        displayName = "(AC) Plane Spawn";
        icon = "A3\ui_f\data\map\markers\nato\o_plane.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_plane.paa";
        function = QFUNC(modulePlaneSpawn);
    };
    class GVAR(heliSpawnModule) : GVAR(module) {
        scope = 2;
        displayName = "(AC) Helicopter Spawn";
        icon = "A3\ui_f\data\map\markers\nato\o_air.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_air.paa";
        function = QFUNC(moduleHeliSpawn);
    };
    class GVAR(aaSiteModule) : GVAR(module) {
        scope = 2;
        displayName = "(AC) AA Site";
        icon = "A3\ui_f\data\map\markers\nato\o_installation.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_installation.paa";
        function = QFUNC(moduleAASite);
    };
    class GVAR(aaSpawnModule) : GVAR(module) {
        scope = 2;
        displayName = "(AC) AA Spawn";
        icon = "A3\ui_f\data\map\markers\nato\o_antiair.paa";
        portrait = "A3\ui_f\data\map\markers\nato\o_antiair.paa";
        function = QFUNC(moduleAASpawn);
    };
};
