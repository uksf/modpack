class CfgVehicles {
    class EGVAR(common,module);
    class GVAR(moduleSettings): EGVAR(common,module) {
        scope = 2;
        displayName = QUOTE(Persistence);
        icon = QPATHTOF(UI\Icon_Module_Persistence_ca.paa);
        category = "UKSF";
        function = QFUNC(initModuleSettings);
        functionPriority = 1;
        isGlobal = 1;
        isTriggerActivated = 0;
        author = QUOTE(UKSF);
        class Arguments {
            class id {
                displayName = QUOTE(Persistence ID);
                description = QUOTE(ID for persistence database. Keep this the same across campaign missions.);
                typeName = "STRING";
                defaultValue = "DEFAULTWILLNOTLOAD";
            };
        };
        class ModuleDescription {
            description = QUOTE(Persistence settings);
        };
    };
};
