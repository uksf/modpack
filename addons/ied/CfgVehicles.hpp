class CfgVehicles {
    class Module_F;
    class GVAR(module) : Module_F {
        scope = 1;
        is3DEN = 1;
        functionPriority = 1;
        category = EGVAR(common,eden);
        class AttributesBase;
    };

    // static IEDs
    class GVAR(IEDPlacementModule) : GVAR(module) {
        scope = 2;
        displayName = "(IED) IED Placement Zone";
        // icon = "a3\ui_f\data\gui\cfg\hints\ieds_ca.paa";
        // portrait = "a3\ui_f\data\gui\cfg\hints\ieds_ca.paa";
        canSetArea = 1;
        canSetAreaHeight = 0;
        canSetAreaShape = 1;
        function = QFUNC(moduleIEDArea);
        class AttributeValues {
            size3[] = { 500, 500, -1 };
            isRectangle = 0;
        };
        class Attributes : AttributesBase {
            class GVAR(iedClasses) {
                property = QGVAR(iedClasses);
                displayName = "IED Classnames";
                tooltip = "IED class list, use magazine classnames. IED classname in eden doesn't work. Comma-separated list of class names in single quotes, no spaces";
                control = "Edit";
                defaultValue = "['IEDLandBig_Remote_Mag','IEDLandSmall_Remote_Mag','IEDUrbanSmall_Remote_Mag']";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(iedClasses),_value,true)]);
            };
            class GVAR(iedNumber) {
                property = QGVAR(iedNumber);
                displayName = "Number of IEDs";
                tooltip = "Number of IEDs to place on and/or near roads.";
                control = "EditShort";
                validate = "NUMBER";
                defaultValue = "50";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(iedNumber),_value,true)]);
            };
            class GVAR(useRoads) {
                property = QGVAR(useRoads);
                displayName = "Use roads";
                tooltip = "Tick to place IEDs only on or next to roads.";
                control = "Checkbox";
                defaultValue = true;
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(useRoads),_value,true)]);
            };
            class GVAR(iedHideChance) {
                property = QGVAR(iedHideChance);
                displayName = "IED Hidden Chance";
                tooltip = "Chance that an IED will be hidden under another object such as a cart. Only happens on IEDs at the side of the road. Set to 0 for no cover.";
                control = "Slider";
                defaultValue = "0.2";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(iedHideChance),_value,true)]);
            };
            class GVAR(iedHideClasses) {
                property = QGVAR(iedHideClasses);
                displayName = "IED Hiding Classnames";
                tooltip = "Classnames of items to hide IEDs under. Comma-separated list of class names in single quotes, no spaces";
                control = "Edit";
                defaultValue = "[]";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(iedHideClasses),_value,true)]);
            };
            class GVAR(iedSecondaryChance) {
                property = QGVAR(iedSecondaryChance);
                displayName = "Chance of secondary IEDs";
                tooltip = "Chance that an IED will have secondary IEDs nearby.";
                control = "Slider";
                defaultValue = "0.2";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(iedSecondaryChance),_value,true)]);
            };
            class GVAR(useIEDPlanters) {
                property = QGVAR(useIEDPlanters);
                displayName = "Use IED Planters";
                tooltip = "Tick to for units to place IEDs. Synchronized objects will become planters.";
                control = "Checkbox";
                defaultValue = false;
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(useIEDPlanters),_value,true)]);
            };
            class GVAR(IEDPlanterBackpackClasses) {
                property = QGVAR(IEDPlanterBackpackClasses);
                displayName = "Backpack Classnames";
                tooltip = "Backpack classnames for the planter. Comma-separated list of class names in single quotes, no spaces";
                control = "Edit";
                defaultValue = "[]";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(IEDPlanterBackpackClasses),_value,true)]);
            };
        };
    };


    // suicide IEDs
    class GVAR(suicidePlacementModule) : GVAR(module) {
        scope = 2;
        displayName = "(IED) Suicide IED Placement Zone";
        canSetArea = 1;
        canSetAreaHeight = 0;
        canSetAreaShape = 1;
        // icon = "a3\ui_f\data\gui\cfg\hints\ieds_ca.paa";
        // portrait = "a3\ui_f\data\gui\cfg\hints\ieds_ca.paa";
        function = QFUNC(moduleSuicideIEDArea);

        class Attributes : AttributesBase {
            class GVAR(suicideIEDClasses) {
                property = QGVAR(suicideIEDClasses);
                displayName = "Suicide Classnames";
                tooltip = "Civ/Soldier classnames to use for IEDs. Comma-separated list of class names in single quotes, no spaces";
                control = "Edit";
                defaultValue = "[]";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(suicideIEDClasses),_value,true)]);
            };
            class GVAR(suicideIEDItemClasses) {
                property = QGVAR(suicideIEDItemClasses);
                displayName = "Suicide Backpack Classnames";
                tooltip = "Backpack classnames for bombers not in cars. Comma-separated list of class names in single quotes, no spaces";
                control = "Edit";
                defaultValue = "[]";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(suicideIEDItemClasses),_value,true)]);
            };
            class GVAR(suicideIEDInCarBoolean) {
                property = QGVAR(suicideIEDInCarBoolean);
                displayName = "Use vehicle";
                tooltip = "Tick for suicide bombers to be in cars. Note they are placed at the start of a mission.";
                control = "Checkbox";
                defaultValue = true;
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(suicideIEDInCarBoolean),_value,true)]);
            };
            class GVAR(suicideIEDVehicleClasses) {
                property = QGVAR(suicideIEDVehicleClasses);
                displayName = "Vehicle classes";
                tooltip = "Vehicles for suicide bombers. Comma-separated list of class names in single quotes, no spaces";
                control = "Edit";
                defaultValue = "[]";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(suicideIEDVehicleClasses),_value,true)]);
            };
        };
    };

    // VBIED
    class GVAR(VBIEDPlacementModule) : GVAR(module) {
        scope = 2;
        displayName = "(IED) VBIED Placement Zone";
        // icon = "a3\ui_f\data\gui\cfg\hints\ieds_ca.paa";
        // portrait = "a3\ui_f\data\gui\cfg\hints\ieds_ca.paa";
        canSetArea = 1;
        canSetAreaHeight = 0;
        canSetAreaShape = 1;
        function = QFUNC(moduleVBIEDArea);
        class AttributeValues {
            size3[] = { 500, 500, -1 };
            isRectangle = 0;
        };
        class Attributes : AttributesBase {
            class GVAR(VBIEDVehicleClasses) {
                property = QGVAR(VBIEDVehicleClasses);
                displayName = "VBIED Classnames";
                tooltip = "Vehicle classnames to use for IEDs. Comma-separated list of class names in single quotes, no spaces";
                control = "Edit";
                defaultValue = "[]";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(VBIEDVehicleClasses),_value,true)]);
            };
            class GVAR(VBIEDNumber) {
                property = QGVAR(VBIEDNumber);
                displayName = "Number of Vehicles";
                tooltip = "Number of vehicles to place on and/or near roads.";
                control = "EditShort";
                validate = "NUMBER";
                defaultValue = "15";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(VBIEDNumber),_value,true)]);
            };
            class GVAR(VBIEDChance) {
                property = QGVAR(VBIEDChance);
                displayName = "VBIED Chance";
                tooltip = "Chance that a vehicle will be a VBIED.";
                control = "Slider";
                defaultValue = "0.2";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(VBIEDChance),_value,true)]);
            };
        };
    };

    class GVAR(IEDExclusionModule) : GVAR(module) {
        scope = 2;
        displayName = "(IED) IED Exclusion Zone";
        //icon = "a3\ui_f\data\gui\cfg\hints\ieds_ca.paa";
        //portrait = "a3\ui_f\data\gui\cfg\hints\ieds_ca.paa";
        canSetArea = 1;
        canSetAreaHeight = 0;
        canSetAreaShape = 1;
        function = QFUNC(moduleIEDExcludeArea);
        class AttributeValues {
            size3[] = { 500, 500, -1 };
            isRectangle = 0;
        };
    };
};
