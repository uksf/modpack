
class CfgSettings {
    class CBA {
        class Versioning {
            class UKSF {
                class dependencies {
                    //UKSF will hard exit if this is missing
                    CBA[] = {"cba_main", REQUIRED_CBA_VERSION, "(true)"};
                };
            };
        };
    };
};
