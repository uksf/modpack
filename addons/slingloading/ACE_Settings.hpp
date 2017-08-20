class ACE_Settings {
    class GVAR(enabled) {
        category = "ACE";
        displayName = QUOTE(Caching);
        description = QUOTE(Enables AI Caching);
        typeName = "BOOL";
        value = 0;
    };
    class GVAR(distance) {
        category = "ACE";
        displayName = QUOTE(Caching Distance);
        description = QUOTE(Sets caching distance in metres);
        typeName = "SCALAR";
        value = 750;
    };
};
