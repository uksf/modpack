class Cfg3DEN {
    class Object {
        class AttributeCategories {
            class uksf_attributes {
                displayName = QUOTE(UKSF Options);
                collapsed = 1;
                class Attributes {};
            };
            delete Enh_AmbientAnimation;
            delete Enh_AmbientAnimationCombat;
        };
    };

    class Group {
        class AttributeCategories {
            class uksf_attributes {
                displayName = QUOTE(UKSF Options);
                collapsed = 1;
                class Attributes {
                    class VCOM_Excluded {
                        property = "VCOM_Excluded";
                        control = "Checkbox";
                        displayName = QUOTE(VCOM Exclude);
                        tooltip = QUOTE(Excludes group from VCOM);
                        expression = "if (_value) then {[{{_x setVariable ['VCOM_NOAI', _this select 1, true]; false} count (units (_this select 0));}, [_this, _value]] call CBA_fnc_execNextFrame};";
                        typeName = "BOOL";
                        defaultValue = "(false)";
                    };
                    class VCOM_DisembarkExcluded {
                        property = "VCOM_DisembarkExcluded";
                        control = "Checkbox";
                        displayName = QUOTE(VCOM Disembark Exclude);
                        tooltip = QUOTE(Excludes group from VCOM Disembark);
                        expression = "if (_value) then {[{{_x setVariable ['VCOM_DisembarkExclude', _this select 1, true]; false} count (crew (vehicle (leader (_this select 0))));}, [_this, _value]] call CBA_fnc_execNextFrame};";
                        typeName = "BOOL";
                        defaultValue = "(false)";
                    };
                    class VCOM_SupportExcluded {
                        property = "VCOM_SupportExcluded";
                        control = "Checkbox";
                        displayName = QUOTE(VCOM Support Exclude);
                        tooltip = QUOTE(Excludes group from VCOM Support);
                        expression = QUOTE(if (_value) then {[ARR_2({(_this select 0) setVariable [ARR_3(QUOTE(QUOTE(VCOM_SupportExclude)),_this select 1,true)];},[ARR_2(_this,_value)])] call CBA_fnc_execNextFrame};);
                        typeName = "BOOL";
                        defaultValue = "(false)";
                    };
                };
            };
        };
    };
};
