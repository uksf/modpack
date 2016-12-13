class ACE_Settings {
    class GVAR(enabled) {
        category = "ACE";
        displayName = QUOTE(Cleanup);
        description = QUOTE(Enables cleanup of dead units/vehicles);
        typeName = "BOOL";
        value = 0;
    };
    class GVAR(delay) {
        category = "ACE";
        displayName = QUOTE(Cleanup Delay);
        description = QUOTE(Delay in seconds between death and cleanup);
        typeName = "SCALAR";
        value = 300;
    };
};
