class Cfg3DEN {
    class Group {
        class AttributeCategories {
            class uksf_attributes {
                class Attributes {
                    class GVAR(excluded) {
                        property = QGVAR(excluded);
                        control = "Checkbox";
                        displayName = QUOTE(Virtualisation exclude);
                        tooltip = QUOTE(Excludes group from virtualisation);
                        expression = QUOTE(if (isServer && _value) then {_this setVariable [ARR_3(QQGVAR(excluded), true, true)]};);
                        typeName = "BOOL";
                        defaultValue = "(false)";
                    };
                };
            };
        };
    };
};
