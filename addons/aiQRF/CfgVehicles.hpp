class CfgVehicles {
    class Logic;
    class Module_F : Logic {
        class AttributesBase;
    };
    class GVAR(moduleCaller) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "QRF Caller";
        icon = "A3\Modules_F\Data\portraitsector_ca.paa";
        portrait = "A3\Modules_F\Data\portraitsector_ca.paa";
        function = QFUNC(moduleCaller);
        functionPriority = 25;
        canSetArea = 1;
        canSetAreaHeight = 0;
        canSetAreaShape = 1;
        category = EGVAR(common,eden);
        class AttributeValues {
            // size3[] = { 500, 500, -1 };
            // isRectangle = 0;
        };
    };
    class GVAR(moduleQrfGroups) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "QRF Groups";
        icon = "A3\Modules_F\Data\portraitsector_ca.paa";
        portrait = "A3\Modules_F\Data\portraitsector_ca.paa";
        function = QFUNC(moduleQrfGroups);
        functionPriority = 25;
        canSetArea = 1;
        canSetAreaHeight = 0;
        canSetAreaShape = 1;
        category = EGVAR(common,eden);
        class AttributeValues {
            // size3[] = { 500, 500, -1 };
            // isRectangle = 0;
        };
    };
};
