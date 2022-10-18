class Cfg3DEN {
    class Object {
        class AttributeCategories {
            class uksf_attributes {
                class Attributes {
                    class GVAR(skipRandomization) {
                        property = QGVAR(skipRandomization);
                        control = "Checkbox";
                        displayName = QUOTE(Skip Randomization);
                        tooltip = QUOTE(Skips uniform randomization for this unit);
                        expression = QUOTE(_this setVariable [ARR_3(QQGVAR(skipRandomization),_value,true)]);
                        typeName = "BOOL";
                        defaultValue = "(false)";
                        condition = "1";
                    };
                };
            };
        };
    };
};
