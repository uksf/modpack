class CfgVehicles {
    class Module_F;
    class GVAR(module) : Module_F {
        scope = 1;
        is3DEN = 1;
        functionPriority = 1;
        category = QUOTE(ADDON);
        class AttributesBase;
    };

    class GVAR(commanderModule) : GVAR(module) {
        scope = 2;
        displayName = "(AIC) Commander";
        function = QFUNC(moduleCommander);

        class Attributes : AttributesBase {
            class GVAR(sideNumber) {
                property = QGVAR(sideNumber);
                displayName = "Commander Side";
                tooltip = "Side this commander controls";
                control = "Combo";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(sideNumber),_value,true)]);
                typeName = "NUMBER";
                defaultValue = 0;
                class values {
                    class West { name = "BLUFOR"; value = 0; };
                    class East { name = "OPFOR"; value = 1; };
                    class Independent { name = "INDEPENDENT"; value = 2; };
                };
            };

            class GVAR(faction) {
                property = QGVAR(faction);
                displayName = "Commander Faction";
                tooltip = "Faction this commander spawns from. Affects available groups, e.g. OPF_F";
                control = "Edit";
                defaultValue = "";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(faction),_value,true)]);
            };

            class GVAR(groups) {
                property = QGVAR(groups);
                displayName = "Faction Groups";
                tooltip = "CfgGroups class names, e.g. [''o_inf_fireteam'',''o_inf_section'']. Empty list means no spawning. Must be a group from the faction specified above.";
                control = "Edit";
                defaultValue = "[]";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(groups),_value,true)]);
            };

            class GVAR(loopInterval) {
                property = QGVAR(loopInterval);
                displayName = "Loop Interval (s)";
                tooltip = "How often commander evaluates objective picture";
                control = "EditShort";
                validate = "NUMBER";
                min = 5;
                max = 3600;
                defaultValue = "60";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(loopInterval),_value,true)]);
            };

            class GVAR(contactConfirmDelaySec) {
                property = QGVAR(contactConfirmDelaySec);
                displayName = "Contact Confirm Delay (s)";
                tooltip = "Delay before validating and emitting first contact report";
                control = "EditShort";
                validate = "NUMBER";
                min = 5;
                max = 180;
                defaultValue = "20";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(contactConfirmDelaySec),_value,true)]);
            };

            class GVAR(followupContactCooldownSec) {
                property = QGVAR(followupContactCooldownSec);
                displayName = "Follow-up Contact Cooldown (s)";
                tooltip = "Minimum time between follow-up contact reports per group";
                control = "EditShort";
                validate = "NUMBER";
                min = 5;
                max = 600;
                defaultValue = "30";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(followupContactCooldownSec),_value,true)]);
            };

            class GVAR(sitrepIntervalSec) {
                property = QGVAR(sitrepIntervalSec);
                displayName = "SITREP Interval (s)";
                tooltip = "How often each managed group sends a SITREP";
                control = "EditShort";
                validate = "NUMBER";
                min = 30;
                max = 3600;
                defaultValue = "180";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(sitrepIntervalSec),_value,true)]);
            };

            class GVAR(intelStaleTtlSec) {
                property = QGVAR(intelStaleTtlSec);
                displayName = "Intel Stale TTL (s)";
                tooltip = "How long enemy grid intel remains valid before decaying to unknown";
                control = "EditShort";
                validate = "NUMBER";
                min = 60;
                max = 7200;
                defaultValue = "600";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(intelStaleTtlSec),_value,true)]);
            };

            class GVAR(ineffectiveCasualtyThreshold) {
                property = QGVAR(ineffectiveCasualtyThreshold);
                displayName = "Ineffective Casualty Threshold";
                tooltip = "Casualty ratio at/above which groups are flagged RTB recommended";
                control = "EditShort";
                validate = "NUMBER";
                min = 0.1;
                max = 1;
                defaultValue = "0.5";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(ineffectiveCasualtyThreshold),_value,true)]);
            };

            class GVAR(maxWave) {
                property = QGVAR(maxWave);
                displayName = "Max Wave Size";
                tooltip = "Maximum groups committed in one wave";
                control = "Combo";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(maxWave),_value,true)]);
                typeName = "NUMBER";
                defaultValue = 3;
                class values {
                    class W1 { name = "1"; value = 1; };
                    class W2 { name = "2"; value = 2; };
                    class W3 { name = "3"; value = 3; };
                    class W4 { name = "4"; value = 4; };
                    class W5 { name = "5"; value = 5; };
                };
            };

            class GVAR(managedGroupCap) {
                property = QGVAR(managedGroupCap);
                displayName = "Managed Group Cap";
                tooltip = "Maximum alive groups this commander may manage at once";
                control = "EditShort";
                validate = "NUMBER";
                min = 1;
                max = 60;
                defaultValue = "9";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(managedGroupCap),_value,true)]);
            };

            class GVAR(gridCellSize) {
                property = QGVAR(gridCellSize);
                displayName = "Grid Cell Size (m)";
                tooltip = "Cell size used to convert 2D positions into integer grid coordinates";
                control = "EditShort";
                validate = "NUMBER";
                min = 50;
                max = 5000;
                defaultValue = "500";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(gridCellSize),_value,true)]);
            };
        };
    };

    class GVAR(objectiveModule) : GVAR(module) {
        scope = 2;
        displayName = "(AIC) Objective";
        icon = "A3\ui_f\data\map\markers\military\objective_ca.paa";
        portrait = "A3\ui_f\data\map\markers\military\objective_ca.paa";
        function = QFUNC(moduleObjective);
        canSetArea = 1;
        canSetAreaHeight = 0;
        canSetAreaShape = 1;

        class AttributeValues {
            size3[] = { 300, 300, -1 };
            isRectangle = 0;
        };

        class Attributes : AttributesBase {
            class GVAR(objectiveName) {
                property = QGVAR(objectiveName);
                displayName = "Objective Name";
                tooltip = "Friendly name for this objective";
                control = "Edit";
                defaultValue = "format ['OBJ-%1', round random 999]";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(objectiveName),_value,true)]);
            };

            class GVAR(priority) {
                property = QGVAR(priority);
                displayName = "Priority";
                tooltip = "Shared strategic priority used by commander decisions";
                control = "EditShort";
                validate = "NUMBER";
                min = 1;
                max = 100;
                defaultValue = "5";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(priority),_value,true)]);
            };

            class GVAR(initialOwner) {
                property = QGVAR(initialOwner);
                displayName = "Initial Owner";
                tooltip = "Initial owner side for this objective";
                control = "Combo";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(initialOwner),_value,true)]);
                typeName = "NUMBER";
                defaultValue = -1;
                class values {
                    class NONE { name = "NONE"; value = -1; };
                    class BLUFOR { name = "BLUFOR"; value = 0; };
                    class OPFOR { name = "OPFOR"; value = 1; };
                    class INDEP { name = "INDEPENDENT"; value = 2; };
                };
            };

            class GVAR(forcePoolGroups) {
                property = QGVAR(forcePoolGroups);
                displayName = "Force Pool (Groups)";
                tooltip = "How many group tokens this objective can commit";
                control = "EditShort";
                validate = "NUMBER";
                min = 0;
                max = 200;
                defaultValue = "6";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(forcePoolGroups),_value,true)]);
            };

            class GVAR(contestedLosingThreshold) {
                property = QGVAR(contestedLosingThreshold);
                displayName = "Contested Losing Threshold";
                tooltip = "Enemy/friendly ratio at or above which objective is contested losing";
                control = "EditShort";
                validate = "NUMBER";
                min = 1;
                max = 20;
                defaultValue = "2";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(contestedLosingThreshold),_value,true)]);
            };

            class GVAR(evalInterval) {
                property = QGVAR(evalInterval);
                displayName = "Eval Interval (s)";
                tooltip = "How often objective evaluates its local state";
                control = "EditShort";
                validate = "NUMBER";
                min = 1;
                max = 300;
                defaultValue = "10";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(evalInterval),_value,true)]);
            };
        };
    };
};
