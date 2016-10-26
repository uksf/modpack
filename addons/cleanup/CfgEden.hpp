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
                        expression = QUOTE(if (_value) then {[ARR_2({(_this select 0) setVariable [ARR_3(QUOTE(QGVAR(excluded)),_this select 1,true)];},[ARR_2(_this,_value)])] call CBA_fnc_execNextFrame};);
                        typeName = "BOOL";
                        defaultValue = "(false)";
                    };
                };
            };
        };
    };
};
