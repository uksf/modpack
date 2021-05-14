class Cfg3DEN {
    class Object {
        class AttributeCategories {
            class uksf_attributes {
                class Attributes {
                    class GVAR(persistent) {
                        property = QGVAR(persistent);
                        control = QGVAR(Checkbox);
                        displayName = QUOTE(Persistent);
                        tooltip = QUOTE(Marks object as persistent);
                        expression = "";
                        typeName = "BOOL";
                        defaultValue = "false";
                        condition = "(1 - objectBrain)";
                    };
                    class GVAR(persistenceID) {
                        property = QGVAR(persistenceID);
                        control = QGVAR(Edit);
                        displayName = QUOTE(Persistence ID);
                        tooltip = QUOTE(Set persistence ID - Must be unique);
                        expression = QUOTE(if (!is3DEN && {isServer}) then {[ARR_2(_this,_value)] call FUNC(markObjectAsPersistent) };);
                        typeName = "STRING";
                        defaultValue = "''";
                        validate = "variable";
                        unique = 1;
                        condition = "(1 - objectBrain)";
                    };
                };
            };
        };
    };
    class EventHandlers {
        class ADDON {
            onMissionPreviewEnd = QUOTE([] spawn {waitUntil {!isNil QQFUNC(edenAttributeChanged)}; call FUNC(edenAttributeChanged) });
            onMissionLoad = QUOTE([] spawn {waitUntil {!isNil QQFUNC(edenAttributeChanged)}; call FUNC(edenAttributeChanged) });
        };
    };
    class Attributes {
        class Default;
        class Title : Default {
            class Controls;
        };
        class Checkbox : Title {
            class Controls : Controls {
                class Title;
                class Value;
            };
        };
        class GVAR(Checkbox) : Checkbox {
            class Controls : Controls {
                class Title : Title {};
                class Value : Value {
                    onCheckedChanged = QUOTE(call FUNC(checkboxChanged));
                    onLoad = QUOTE(_this spawn {disableserialization; call FUNC(checkboxChanged)});
                };
            };
        };
        class Edit : Title {
            class Controls : Controls {
                class Title;
                class Value;
            };
        };
        class GVAR(Edit) : Edit {
            class Controls : Controls {
                class Title : Title {
                    show = 0;
                };
                class Value : Value {
                    show = 0;
                };
            };
        };
    };
};
