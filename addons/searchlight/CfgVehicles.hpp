class CfgVehicles {
    class Module_F;
    class GVAR(module) : Module_F {
        scope = 1;
        is3DEN = 1;
        functionPriority = 1;
        category = EGVAR(common,eden);
        // class AttributesBase;
    };
    class GVAR(swingSearchlightsModule) : GVAR(module) {
        scope = 2;
        displayName = "Swing Searchlights";
        icon = "A3\ui_f\data\map\markers\military\box_ca.paa";
        portrait = "A3\ui_f\data\map\markers\military\box_ca.paa";
        function = QFUNC(useSearchlight);
    };
};
