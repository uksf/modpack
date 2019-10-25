class CfgFactionClasses {
    class NO_CATEGORY;
    class GVAR(uksf) : NO_CATEGORY {
        displayName = "UKSF";
        priority = 2;
        side = 7;
    };
    class GVAR(special) : GVAR(uksf) {
        displayName = "UKSF Special";
    };
};
