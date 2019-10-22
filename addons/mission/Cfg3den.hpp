class Cfg3DEN {
    class Object {
        class AttributeCategories {
            class uksf_attributes {
                class Attributes {
                    class GVAR(hasSupportRadio) {
                        property = QGVAR(hasSupportRadio);
                        control = "Checkbox";
                        displayName = QUOTE(Has support radio);
                        tooltip = QUOTE(Determines if unit can support or call for support);
                        expression = QUOTE(if (!_value) then {_this setVariable [ARR_3(QQGVAR(hasSupportRadio),_value,true)];};);
                        typeName = "BOOL";
                        defaultValue = "(true)";
                        condition = "objectBrain * (1 - objectVehicle)";
                    };
                };
            };
        };
    };
};
