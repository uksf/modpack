class Cfg3DEN {
    class Object {
        class AttributeCategories {
            class uksf_attributes {
                class Attributes {
                    class GVAR(hasRadio) {
                        property = QGVAR(hasRadio);
                        control = "Checkbox";
                        displayName = QUOTE(Has radio);
                        tooltip = QUOTE(Determines if group can support);
                        expression = QUOTE(if (!_value) then {_this setVariable [ARR_3(QQGVAR(hasRadio),_value,true)];};);
                        typeName = "BOOL";
                        defaultValue = "(true)";
                        condition = "objectBrain * (1 - objectVehicle)";
                    };
                };
            };
        };
    };
};
