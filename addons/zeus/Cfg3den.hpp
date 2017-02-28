class Cfg3DEN {
    class Object {
        class AttributeCategories {
            class uksf_attributes {
                class Attributes {
                    class GVAR(setAllowUnconcious) {
                        property = QGVAR(setAllowUnconcious);
                        control = "Checkbox";
                        displayName = QUOTE(Allow 50/50 Unconcious);
                        tooltip = QUOTE(Allow 50/50 unconcious state);
                        expression = QUOTE(if (!is3DEN) then {[ARR_2(_this, _value)] call FUNC(setAllowUnconcious)};);
                        typeName = "BOOL";
                        defaultValue = "(false)";
                        condition = "objectBrain * (1 - objectVehicle)";
                    };
                };
            };
        };
    };
};
