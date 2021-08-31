class CfgVehicles {
    class Module_F;
    class GVAR(module) : Module_F {
        scope = 1;
        is3DEN = 1;
        functionPriority = 1;
        category = EGVAR(common,eden);
        class AttributesBase;
    };
    class GVAR(cacheAreaModule) : GVAR(module) {
        scope = 2;
        displayName = "(Caches) Spawn Module";
        function = QFUNC(moduleInitCaches);
        canSetArea = 1;
        canSetAreaHeight = 0;
        canSetAreaShape = 1;
         class AttributeValues {
            size3[] = { 500, 500, -1 };
            isRectangle = 0;
        };
        class Attributes : AttributesBase {
            class GVAR(cacheNumber) {
                property = QGVAR(cacheNumber);
                displayName = "Number of caches";
                tooltip = "Number of caches to spawn in the area";
                control = "Editshort";
                validate = "NUMBER";
                defaultValue = "3";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(cacheNumber),_value,true)]);
            };
            class GVAR(cachePoolString) {
                property = QGVAR(cachePoolString);
                displayName = "Cache Box Pool";
                tooltip = "Class names of crates/boxes to use as caches. Comma-separated list of class names in single quotes, no spaces";
                control = "Edit";
                defaultValue = "[]";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(cachePoolString),_value,true)]);
            };
            class GVAR(cacheContentPoolString) {
                property = QGVAR(cacheContentPoolString);
                displayName = "Content Pool";
                tooltip = "Class names of content to be placed in caches. Random amount of each item will be used. Comma-separated list of class names in single quotes, no spaces";
                control = "Edit";
                defaultValue = "[]";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(cacheContentPoolString),_value,true)]);
            };
        };
    };
};
