class CBA_Extended_EventHandlers_base;

class CfgVehicles {
    class Module_F;
    class GVAR(module) : Module_F {
        scope = 1;
        is3DEN = 1;
        functionPriority = 1;
        category = EGVAR(common,eden);
        class AttributesBase;
    };

    class GVAR(informantModule) : GVAR(module) {
        scope = 2;
        displayName = "Buy Informant";
        icon = "a3\Ui_f\data\IGUI\Cfg\simpleTasks\letters\i_ca.paa";
        portrait = "a3\Ui_f\data\IGUI\Cfg\simpleTasks\letters\i_ca.paa";
        canSetArea = 0;
        canSetAreaHeight = 0;
        canSetAreaShape = 0;
        function = QFUNC(moduleAddInformantInteraction);
        class Attributes : AttributesBase {
            class GVAR(informantCost) {
                property = QGVAR(informantCost);
                displayName = "Informant Cost";
                tooltip = "Cost to buy the informant. Sync one module per informant.";
                control = "Edit";
                defaultValue = "150";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(informantCost),_value,true)]);
            };
        };
    };

    class GVAR(intelTextDetailModule) : GVAR(module) {
        scope = 2;
        displayName = "Intel Text Details";
        icon = "\A3\Ui_f\data\IGUI\Cfg\simpleTasks\types\box_ca.paa";
        portrait = "\A3\Ui_f\data\IGUI\Cfg\simpleTasks\types\box_ca.paa";
        canSetArea = 0;
        canSetAreaHeight = 0;
        canSetAreaShape = 0;
        function = QFUNC(moduleSendTextMessage);
        class Attributes : AttributesBase {
            class GVAR(intelID) {
                property = QGVAR(intelID);
                control = "Edit";
                displayName = QUOTE(Intel ID);
                tooltip = QUOTE(Set Intel ID - Must be unique);
                expression = QUOTE([ARR_1(_this)] call FUNC(createIntelID));
                typeName = "STRING";
                defaultValue = "''";
                validate = "variable";
                unique = 1;
            };
            class GVAR(intelRead) {
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(intelRead), false, true)]);
            };
            class GVAR(intelTextString) {
                property = QGVAR(intelTextString);
                control = "Edit";
                displayName = QUOTE(Intel Text String);
                tooltip = QUOTE(Text message to be sent e.g. Theyre leaving the shop now);
                defaultValue = "''";
                typeName = "STRING";
                expression = QUOTE(_this setVariable [ARR_3(QQGVAR(intelTextString), _value, true)]);
            };
        };
    };
};
