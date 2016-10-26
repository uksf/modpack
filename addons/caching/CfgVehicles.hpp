class CfgVehicles {
    class ACE_Module;
    class GVAR(moduleSettings): ACE_Module {
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
        function = QFUNC(moduleExclude);
        icon = QPATHTOF(UI\Icon_Module_CachingExclude_ca.paa);
    };
    class GVAR(moduleCachingInclude): EGVAR(common,moduleBase) {
        curatorCanAttach = 1;
        displayName = QUOTE(Caching include);
        function = QFUNC(moduleInclude);
        icon = QPATHTOF(UI\Icon_Module_CachingInclude_ca.paa);
    };
};