class Cfg3DEN {
    class Object {
        class AttributeCategories {
            class uksf_attributes {
                displayName = "UKSF Options";
                collapsed = 1;
                class Attributes {};
            };
            delete Enh_AmbientAnimation;
            delete Enh_AmbientAnimationCombat;
        };
    };
    class Logic {
        class AttributeCategories {
            class uksf_attributes {
                displayName = "UKSF Options";
                class Attributes {
                    class GVAR(id) {
                        property = QGVAR(id);
                        control = QGVAR(EditId);
                        displayName = "ID";
                        tooltip = "Unique ID for this Logic";
                        condition = "1";
                        expression = QUOTE(_this setVariable [ARR_3(QQGVAR(id),_value,true)]);
                        defaultValue = "''";
                        typeName = "STRING";
                        validate = "variable";
                        unique = 1;
                    };
                };
            };
        };
    };
    class EventHandlers {
        class ADDON {
            onMissionPreviewEnd = QUOTE([] spawn {waitUntil {!isNil QQFUNC(edenSetIdAttribute)}; call FUNC(edenSetIdAttribute) });
            onMissionLoad = QUOTE([] spawn {waitUntil {!isNil QQFUNC(edenSetIdAttribute)}; call FUNC(edenSetIdAttribute) });
            onPaste = QUOTE([] spawn {waitUntil {!isNil QQFUNC(edenSetIdAttribute)}; call FUNC(edenSetIdAttribute) });
        };
    };
    class Attributes {
        class Default;
        class Title : Default {
            class Controls;
        };
        class Edit : Title {
            class Controls : Controls {
                class Value;
            };
        };
        class GVAR(EditId) : Edit {
            class Controls : Controls {
                class Title : Title {};
                class Value : Value {
                    onLoad = QUOTE(_this spawn {disableserialization; call FUNC(edenIdAttributeChanged)});
                };
            };
        };
    };
};
