class CfgVehicles {
    class Logic;
    class Module_F: Logic {
        class AttributesBase;
    };
    class GVAR(moduleSpawnArea): Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "Spawn Area";
        icon = "A3\Modules_F\Data\portraitsector_ca.paa";
        portrait = "A3\Modules_F\Data\portraitsector_ca.paa";
        function = QFUNC(moduleSpawn);
        functionPriority = 25;
        canSetArea = 1;
        canSetAreaHeight = 0;
        canSetAreaShape = 1;
        category = EGVAR(common,eden);
        class AttributeValues {
            size3[] = {500, 500, -1};
            isRectangle = 0;
        };
        class Attributes: AttributesBase {
            class GVAR(maxGroups) {
                property = QGVAR(maxGroups);
                displayName = "Max Spawned Groups";
                tooltip = "Defines the maximum number of groups that will be spawned in the area at one time.";
                control = "Edit";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(maxGroups),_value,true)]);
                defaultValue = "4";
            };
            class GVAR(groupPool) {
                property = QGVAR(groupPool);
                displayName = "Group Pool Size";
                tooltip = "Defines the total number of groups that will spawn in this area.";
                control = "Edit";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(groupPool),_value,true)]);
                defaultValue = "8";
            };
            class GVAR(faction) {
                property = QGVAR(faction);
                displayName = "Faction Class Name";
                tooltip = "Determines the faction of the groups which spawn. Must be the class name.";
                control = "Edit";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(faction),_value,true)]);
                defaultValue = "OPF_F";
            };
        };
    };
    class GVAR(modulePatrolBlacklistArea): Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "Patrol Blacklist Area";
        icon = "A3\Modules_F\Data\portraitsector_ca.paa";
        portrait = "A3\Modules_F\Data\portraitsector_ca.paa";
        function = QFUNC(modulePatrolBlacklistArea);
        functionPriority = 25;
        canSetArea = 1;
        canSetAreaHeight = 0;
        canSetAreaShape = 1;
        category = EGVAR(common,eden);
        class AttributeValues {
            size3[] = {500, 500, -1};
            isRectangle = 0;
        };
    };
};
