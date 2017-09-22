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
                    class VCOM_SupportExcluded {
                        property = "VCOM_SupportExcluded";
                        control = "Checkbox";
                        displayName = QUOTE(VCOM Support Exclude);
                        tooltip = QUOTE(Excludes group from VCOM Support);
                        expression = QUOTE(if (_value) then {[ARR_2({(_this select 0) setVariable [ARR_3(QUOTE(QUOTE(VCOM_SupportExclude)),_this select 1,true)];},[ARR_2(_this,_value)])] call cba_fnc_execNextFrame};);
                        typeName = "BOOL";
                        defaultValue = "(false)";
                    };
                };
            };
        };
    };
};
