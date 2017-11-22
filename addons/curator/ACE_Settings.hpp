class ACE_Settings {
    class GVAR(curatorsMax) {
        category = "ACE";
        displayName = QUOTE(Maximum Curators);
        description = QUOTE(Maximum number of curators allowed);
        typeName = "SCALAR";
        value = 2;
    };
    class GVAR(curatorsLocked) {
        category = "ACE";
        displayName = QUOTE(Curators Locked);
        description = QUOTE(Locks access to curators on mission start);
        typeName = "BOOL";
        value = 0;
    };
};
