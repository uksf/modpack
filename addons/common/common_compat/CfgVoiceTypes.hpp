// UKSF units speak LanguageENGB_F, but no voice type lists a British voice, so the engine
// cannot match the profile speaker ("Speaker Male01_F not found in CfgVoiceTypes").
// Only Male01-05 have ENGB recordings; Male06-12 reuse them in turn.
class CfgVoiceTypes {
    class Male01_F {
        voices[] += { "Male01ENGB" };
    };
    class Male02_F {
        voices[] += { "Male02ENGB" };
    };
    class Male03_F {
        voices[] += { "Male03ENGB" };
    };
    class Male04_F {
        voices[] += { "Male04ENGB" };
    };
    class Male05_F {
        voices[] += { "Male05ENGB" };
    };
    class Male06_F {
        voices[] += { "Male01ENGB" };
    };
    class Male07_F {
        voices[] += { "Male02ENGB" };
    };
    class Male08_F {
        voices[] += { "Male03ENGB" };
    };
    class Male09_F {
        voices[] += { "Male04ENGB" };
    };
    class Male10_F {
        voices[] += { "Male05ENGB" };
    };
    class Male11_F {
        voices[] += { "Male01ENGB" };
    };
    class Male12_F {
        voices[] += { "Male02ENGB" };
    };
};
