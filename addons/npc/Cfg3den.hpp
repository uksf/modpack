// One scripted slot = a topic edit + a line multiline edit. Repeated 6 times.
#define SCRIPTED_SLOT(n) \
    class GVAR(scriptedTopic##n) { \
        property = QGVAR(scriptedTopic##n); \
        control = "Edit"; \
        displayName = QUOTE(Scripted topic n); \
        tooltip = "What this scripted slot is about (helps the model route). Leave blank to skip."; \
        expression = QUOTE(_this setVariable [ARR_3(QQGVAR(scriptedTopic##n),_value,true)]); \
        typeName = "STRING"; \
        defaultValue = "''"; \
        condition = "this isKindOf 'CAManBase'"; \
    }; \
    class GVAR(scriptedLine##n) { \
        property = QGVAR(scriptedLine##n); \
        control = "EditMulti5"; \
        displayName = QUOTE(Scripted line n); \
        tooltip = "The spoken line for this scripted slot."; \
        expression = QUOTE(_this setVariable [ARR_3(QQGVAR(scriptedLine##n),_value,true)]); \
        typeName = "STRING"; \
        defaultValue = "''"; \
        condition = "this isKindOf 'CAManBase'"; \
    }

class Cfg3DEN {
    class Object {
        class AttributeCategories {
            class GVAR(category) {
                displayName = "UKSF NPC";
                collapsed = 1;
                class Attributes {
                    class GVAR(talkable) {
                        property = QGVAR(talkable);
                        control = "Checkbox";
                        displayName = "Talkable NPC";
                        tooltip = "Player can walk up and talk to this unit.";
                        expression = QUOTE(_this setVariable [ARR_3(QQGVAR(talkable),_value,true)]);
                        typeName = "BOOL";
                        defaultValue = "false";
                        condition = "this isKindOf 'CAManBase'";
                    };
                    class GVAR(mode) {
                        property = QGVAR(mode);
                        control = "Combo";
                        displayName = "Mode";
                        tooltip = "dynamic = free in-persona generation; scripted = pick from the scripted lines below.";
                        expression = QUOTE(_this setVariable [ARR_3(QQGVAR(mode),_value,true)]);
                        typeName = "STRING";
                        defaultValue = "'dynamic'";
                        condition = "this isKindOf 'CAManBase'";
                        class Values {
                            class Dynamic { name = "Dynamic"; value = "dynamic"; };
                            class Scripted { name = "Scripted"; value = "scripted"; };
                        };
                    };
                    class GVAR(voiceId) {
                        property = QGVAR(voiceId);
                        control = "Combo";
                        displayName = "Voice";
                        tooltip = "TTS voice preset.";
                        expression = QUOTE(_this setVariable [ARR_3(QQGVAR(voiceId),_value,true)]);
                        typeName = "STRING";
                        defaultValue = "'635503a3-a49d-4610-9e08-27cd390a4b28'";
                        condition = "this isKindOf 'CAManBase'";
                        class Values {
                            class George { name = "George (default)"; value = "635503a3-a49d-4610-9e08-27cd390a4b28"; };
                        };
                    };
                    class GVAR(gateRange) {
                        property = QGVAR(gateRange);
                        control = "Edit";
                        displayName = "Gate range (m)";
                        tooltip = "How close a player must be to address this NPC (effective up to 25 m).";
                        expression = QUOTE(_this setVariable [ARR_3(QQGVAR(gateRange),_value,true)]);
                        typeName = "NUMBER";
                        validate = "number";
                        defaultValue = "4";
                        condition = "this isKindOf 'CAManBase'";
                    };
                    class GVAR(gateFov) {
                        property = QGVAR(gateFov);
                        control = "Edit";
                        displayName = "Gate FOV (deg)";
                        tooltip = "Player must be looking within this cone (full angle).";
                        expression = QUOTE(_this setVariable [ARR_3(QQGVAR(gateFov),_value,true)]);
                        typeName = "NUMBER";
                        validate = "number";
                        defaultValue = "90";
                        condition = "this isKindOf 'CAManBase'";
                    };
                    class GVAR(personaName) {
                        property = QGVAR(personaName);
                        control = "Edit";
                        displayName = "Persona: name";
                        tooltip = "Character name.";
                        expression = QUOTE(_this setVariable [ARR_3(QQGVAR(personaName),_value,true)]);
                        typeName = "STRING";
                        defaultValue = "''";
                        condition = "this isKindOf 'CAManBase'";
                    };
                    class GVAR(personaRole): GVAR(personaName) {
                        property = QGVAR(personaRole);
                        displayName = "Persona: role";
                        tooltip = "e.g. guard, quartermaster, civilian.";
                        expression = QUOTE(_this setVariable [ARR_3(QQGVAR(personaRole),_value,true)]);
                    };
                    class GVAR(personaLanguage): GVAR(personaName) {
                        property = QGVAR(personaLanguage);
                        displayName = "Persona: language";
                        tooltip = "e.g. English, Arabic.";
                        expression = QUOTE(_this setVariable [ARR_3(QQGVAR(personaLanguage),_value,true)]);
                    };
                    class GVAR(personaMood): GVAR(personaName) {
                        property = QGVAR(personaMood);
                        displayName = "Persona: mood";
                        tooltip = "e.g. exhausted, on edge.";
                        expression = QUOTE(_this setVariable [ARR_3(QQGVAR(personaMood),_value,true)]);
                    };
                    class GVAR(personaAttitude): GVAR(personaName) {
                        property = QGVAR(personaAttitude);
                        displayName = "Persona: attitude";
                        tooltip = "neutral to hostile.";
                        expression = QUOTE(_this setVariable [ARR_3(QQGVAR(personaAttitude),_value,true)]);
                    };
                    class GVAR(knowledge) {
                        property = QGVAR(knowledge);
                        control = "EditMulti5";
                        displayName = "Knowledge";
                        tooltip = "Free text the NPC knows.";
                        expression = QUOTE(_this setVariable [ARR_3(QQGVAR(knowledge),_value,true)]);
                        typeName = "STRING";
                        defaultValue = "''";
                        condition = "this isKindOf 'CAManBase'";
                    };
                    SCRIPTED_SLOT(1);
                    SCRIPTED_SLOT(2);
                    SCRIPTED_SLOT(3);
                    SCRIPTED_SLOT(4);
                    SCRIPTED_SLOT(5);
                    SCRIPTED_SLOT(6);
                    class GVAR(deflection) {
                        property = QGVAR(deflection);
                        control = "EditMulti5";
                        displayName = "Scripted deflection";
                        tooltip = "Fallback line when no scripted topic matches.";
                        expression = QUOTE(_this setVariable [ARR_3(QQGVAR(deflection),_value,true)]);
                        typeName = "STRING";
                        defaultValue = "''";
                        condition = "this isKindOf 'CAManBase'";
                    };
                };
            };
        };
    };
};
