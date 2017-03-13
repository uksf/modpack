class CfgVehicles {
    class EGVAR(common,module);
    class GVAR(moduleSettings): EGVAR(common,module) {
        scope = 2;
        displayName = QUOTE(Caching);
        icon = QPATHTOF(UI\Icon_Module_Caching_ca.paa);
        category = "UKSF";
        function = QFUNC(initModuleSettings);
        functionPriority = 1;
        isGlobal = 1;
        isTriggerActivated = 0;
        author = QUOTE(UKSF);
        class Arguments {
            class enabled {
                displayName = QUOTE(Caching);
                description = QUOTE(Enables AI Caching);
                typeName = "BOOL";
                defaultValue = 0;
            };
            class distance {
                displayName = QUOTE(Caching Distance);
                description = QUOTE(Sets caching distance in metres);
                typeName = "NUMBER";
                defaultValue = 1250;
            };
        };
        class ModuleDescription {
            description = QUOTE(AI Caching settings);
        };
    };

    class EGVAR(common,moduleBase);
    class GVAR(moduleCachingExclude): EGVAR(common,moduleBase) {
        curatorCanAttach = 1;
        displayName = QUOTE(Caching exclude);
        function = QFUNC(moduleToggleCaching);
        icon = QPATHTOF(UI\Icon_Module_CachingExclude_ca.paa);
    };
    class GVAR(moduleCachingInclude): EGVAR(common,moduleBase) {
        curatorCanAttach = 1;
        displayName = QUOTE(Caching include);
        function = QFUNC(moduleToggleCaching);
        icon = QPATHTOF(UI\Icon_Module_CachingInclude_ca.paa);
    };
};
