class Cfg3DEN {
    class Group {
        class AttributeCategories {
            class uksf_attributes {
                class Attributes {
                    class GVAR(excluded) {
                        property = QGVAR(excluded);
                        control = "Checkbox";
                        displayName = QUOTE(Caching exclude);
                        tooltip = QUOTE(Excludes group from caching);
                        expression = QUOTE(if (isServer && _value) then {[ARR_2({_this call FUNC(disableCache)},_this)] call CBA_fnc_execNextFrame;};);
                        typeName = "BOOL";
                        defaultValue = "(false)";
                    };
                };
            };
        };
    };
};
