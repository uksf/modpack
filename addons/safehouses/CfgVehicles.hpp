class CfgVehicles {
    class Logic;
    class Module_F : Logic {
        class AttributesBase;
    };
    class GVAR(modulePrefabArea) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "Safehouse Prefab";
        icon = QPATHTOF(data\ui\Icon_Module_SafehousePrefab_ca.paa);
        portrait = QPATHTOF(data\ui\Icon_Module_SafehousePrefab_ca.paa);
        function = QFUNC(modulePrefabArea);
        functionPriority = 25;
        canSetArea = 1;
        canSetAreaHeight = 1;
        canSetAreaShape = 1;
        category = EGVAR(common,eden);
        class AttributeValues {
            size3[] = { 20, 20, 20 };
            isRectangle = 1;
        };
    };
    class GVAR(moduleLocation) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "Safehouse Location";
        icon = QPATHTOF(data\ui\Icon_Module_SafehouseLocation_ca.paa);
        portrait = QPATHTOF(data\ui\Icon_Module_SafehouseLocation_ca.paa);
        function = QFUNC(moduleLocation);
        functionPriority = 25;
        canSetArea = 0;
        category = EGVAR(common,eden);
        class Attributes : AttributesBase {
            class GVAR(prefabId) {
                property = QGVAR(prefabId);
                displayName = "Prefab Id (Optional)";
                tooltip = "An optional prefab id to specify a prefab for this location";
                control = "Edit";
                defaultValue = "''";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(prefabId),_value,true)]);
            };
        };
    };
};
