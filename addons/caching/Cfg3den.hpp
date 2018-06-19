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
                        expression = QUOTE(if (_value) then {[ARR_2({[ARR_2(QQGVAR(disableCache),_this)] call CBA_fnc_serverEvent;},_this)] call CBA_fnc_execNextFrame};);
                        typeName = "BOOL";
                        defaultValue = "(false)";
                    };
                };
            };
        };
    };
};
