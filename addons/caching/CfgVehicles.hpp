class CfgVehicles {
    class EGVAR(common,moduleBase);
    class GVAR(moduleCachingExclude): EGVAR(common,moduleBase) {
        curatorCanAttach = 1;
        displayName = QUOTE(Caching exclude);
        function = QFUNC(moduleToggleCaching);
        icon = QPATHTOF(ui\Icon_Module_CachingExclude_ca.paa);
    };
};
