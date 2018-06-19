class Cfg3DEN {
    class Object {
        class AttributeCategories {
            class uksf_attributes {
                class Attributes {
                    class GVAR(persistent) {
                        property = QGVAR(persistent);
                        control = "Checkbox";
                        displayName = QUOTE(Persistent);
                        tooltip = QUOTE(Marks vehicle as persistent);
                        expression = QUOTE(if (!is3DEN && {isServer} && {_value}) then {_this call FUNC(markVehicleAsPersistent)};);
                        typeName = "BOOL";
                        defaultValue = "false";
                        condition = "(1 - objectBrain) * objectVehicle";
                    };
                };
            };
        };
    };
};
