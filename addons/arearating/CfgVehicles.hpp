class CfgVehicles {
    class Logic;
    class Module_F : Logic {
        class AttributesBase;
    };
    class GVAR(moduleRatingArea) : Module_F {
        scope = 2;
        is3DEN = 1;
        displayName = "Rating Area";
        icon = QPATHTOF(data\ui\Icon_Module_RatingArea_ca.paa);
        portrait = QPATHTOF(data\ui\Icon_Module_RatingArea_ca.paa);
        function = QFUNC(moduleRatingArea);
        functionPriority = 25;
        canSetArea = 1;
        canSetAreaHeight = 0;
        canSetAreaShape = 1;
        category = EGVAR(common,eden);
        class AttributeValues {
            size3[] = { 2000, 2000, -1 };
            isRectangle = 0;
        };
        class Attributes : AttributesBase {
            class GVAR(displayName) {
                property = QGVAR(displayName);
                displayName = "Display name";
                tooltip = "Display name of the area to use in any player interactions";
                control = "Edit";
                defaultValue = "format ['%1', round random 99999]";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(displayName),_value,true)]);
            };

            class GVAR(ratingStart) {
                property = QGVAR(ratingStart);
                displayName = "Start rating";
                tooltip = "Starting rating value";
                control = "EditShort";
                validate = "NUMBER";
                min = 0;
                max = 100;
                defaultValue = "50";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(ratingStart),_value,true)]);
            };
            class GVAR(ratingMin) {
                property = QGVAR(ratingMin);
                displayName = "Minimum rating";
                tooltip = "The lowest rating this area can have";
                control = "EditShort";
                validate = "NUMBER";
                min = 0;
                max = 99;
                defaultValue = "0";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(ratingMin),_value,true)]);
            };
            class GVAR(ratingMax) {
                property = QGVAR(ratingMax);
                displayName = "Maximum rating";
                tooltip = "The highest rating this area can have";
                control = "EditShort";
                validate = "NUMBER";
                min = 1;
                max = 100;
                defaultValue = "100";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(ratingMax),_value,true)]);
            };

            // Good
            class GVAR(ied_planter) {
                property = QGVAR(ied_planter);
                displayName = "Rating change: IED planter killed";
                tooltip = "The value the current rating will change by when an IED planter is killed";
                control = "EditShort";
                validate = "NUMBER";
                min = -100;
                max = 100;
                defaultValue = "4";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(ied_planter),_value,true)]);
            };
            class GVAR(ied_destroyed) {
                property = QGVAR(ied_destroyed);
                displayName = "Rating change: IED destroyed";
                tooltip = "The value the current rating will change by when an IED is purposefully detonated";
                control = "EditShort";
                validate = "NUMBER";
                min = -100;
                max = 100;
                defaultValue = "2";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(ied_destroyed),_value,true)]);
            };
            class GVAR(caches_destroyed) {
                property = QGVAR(caches_destroyed);
                displayName = "Rating change: Cache destroyed";
                tooltip = "The value the current rating will change by when a cache is denied by friendly forces";
                control = "EditShort";
                validate = "NUMBER";
                min = -100;
                max = 100;
                defaultValue = "1";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(caches_destroyed),_value,true)]);
            };
            class GVAR(safehouse_destroyed) {
                property = QGVAR(safehouse_destroyed);
                displayName = "Rating change: Safehouse destroyed";
                tooltip = "The value the current rating will change by when a safehouse is destroyed by friendly forces";
                control = "EditShort";
                validate = "NUMBER";
                min = -100;
                max = 100;
                defaultValue = "5";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(safehouse_destroyed),_value,true)]);
            };

            // Bad
            class GVAR(civ_hit) {
                property = QGVAR(civ_hit);
                displayName = "Rating change: Civilian hit";
                tooltip = "The value the current rating will change by when a civilian is hit by friendly fire";
                control = "EditShort";
                validate = "NUMBER";
                min = -100;
                max = 100;
                defaultValue = "-3";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(civ_hit),_value,true)]);
            };
            class GVAR(civ_killed) {
                property = QGVAR(civ_killed);
                displayName = "Rating change: Civilian killed";
                tooltip = "The value the current rating will change by when a civilian is killed by friendly fire";
                control = "EditShort";
                validate = "NUMBER";
                min = -100;
                max = 100;
                defaultValue = "-8";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(civ_killed),_value,true)]);
            };
        };
    };
};
