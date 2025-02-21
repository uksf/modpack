class CfgVehicles {
    class Logic;
    class Module_F : Logic {
        class AttributesBase;
    };
    class GVAR(moduleSectroControl) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "UKSF Sector Control";
        // icon = QPATHTOF(data\ui\Icon_Module_RatingArea_ca.paa);
        // portrait = QPATHTOF(data\ui\Icon_Module_RatingArea_ca.paa);
        function = QFUNC(moduleSectorPFH);
        functionPriority = 25;
        canSetArea = 1;
        canSetAreaHeight = 0;
        canSetAreaShape = 1;
        category = EGVAR(common,eden);
        class AttributeValues {
            size3[] = { 50, 50, -1 };
            isRectangle = 0;
        };
        class Attributes : AttributesBase {
            class GVAR(displayName) {
                property = QGVAR(displayName);
                displayName = "Display name";
                tooltip = "Name of the sector";
                control = "Edit";
                defaultValue = "Alpha";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(displayName),_value,true)]);
            };

            class GVAR(condition) {
                property = QGVAR(condition);
                displayName = "Condition";
                tooltip = "Must return true before sector is visible and able to be captured. Must return true or false.";
                defaultValue = "'true'";
                value = "'true'";
                control = "EditCodeMulti3";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(condition),_value,true)]);
            };
            class GVAR(currentOwner) {
                property = QGVAR(currentOwner);
                displayName = "Current Owner";
                tooltip = "Who owns the sector at the start.";
                control = "Combo";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(currentOwner),_value,true)]);
                typeName = "NUMBER";
                defaultValue = 0;
                class values {
                    class East {
                        name = "OPFOR";
                        value = 0;
                    };
                    class West {
                        name = "BLUFOR";
                        value = 1;
                    };
                    class None {
                        name = "NO-ONE";
                        value = 2;
                    };
                };
            };
            class GVAR(timeToCapture) {
                property = QGVAR(timeToCapture);
                displayName = "Time to Capture";
                tooltip = "How long it takes to capture a point in seconds. Min 30, Max 300.";
                control = "EditShort";
                validate = "NUMBER";
                min = 30;
                max = 300;
                defaultValue = "120";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(timeToCapture),_value,true)]);
            };
            class GVAR(requiredDominance) {
                property = QGVAR(requiredDominance);
                displayName = "Required Dominance";
                tooltip = "How many more units are needed by one side to start a capture e.g. 0.25 is 25%. Numbers between 0.1 and 1.";
                control = "EditShort";
                validate = "NUMBER";
                min = 0.1;
                max = 1;
                defaultValue = "0.25";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(requiredDominance),_value,true)]);
            };
            class GVAR(lockAfterCapture) {
                property = QGVAR(lockAfterCapture);
                displayName = "Lock after Capture";
                tooltip = "Stops any other force from being able to capture the sector";
                control = "Combo";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(lockAfterCapture),_value,true)]);
                typeName = "NUMBER";
                defaultValue = 0;
                class values {
                    class false {
                        name = "FALSE";
                        value = 0;
                    };
                    class true {
                        name = "TRUE";
                        value = 1;
                    };
                };
            };
        };
    };
};
