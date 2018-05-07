#define COMPONENT radios
#define COMPONENT_BEAUTIFIED Radios
#include "\u\uksf\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS

#include "\u\uksf\addons\main\script_macros.hpp"

#define CHANNELS_SQN_7 [31, 40, 34]
#define CHANNELS_SQN_656 [31, 40, 35]
#define CHANNELS_SQN_617 [31, 40, 36]

#define INIT_RACKS(class,channels,exclude) [class, "init", {[_this select 0, channels] call FUNC(initRacks)}, true, exclude, true] call CBA_fnc_addClassEventHandler

#define INTERCOM_AIR \
    class AcreIntercoms { \
        class Intercom_1 { \
            displayName = "Crew intercom"; \
            shortName = "Crew"; \
            allowedPositions[] = {"crew"}; \
            disabledPositions[] = {}; \
            limitedPositions[] = {{"cargo", "all"}}; \
            masterPositions[] = {"driver"}; \
            numLimitedPositions = 3; \
            connectedByDefault = 1; \
        }; \
        class Intercom_2: Intercom_1 { \
            displayName = "Passenger intercom"; \
            shortName = "Passenger"; \
            allowedPositions[] = {"crew", {"cargo", "all"}}; \
            limitedPositions[] = {}; \
            numLimitedPositions = 0; \
            connectedByDefault = 0; \
        }; \
    };

#define INTERCOM_GROUND \
    class AcreIntercoms { \
        class Intercom_1 { \
            displayName = "Crew intercom"; \
            shortName = "Crew"; \
            allowedPositions[] = {"crew", {"cargo", "all"}}; \
            disabledPositions[] = {}; \
            limitedPositions[] = {}; \
            masterPositions[] = {"commander"}; \
            numLimitedPositions = 0; \
            connectedByDefault = 1; \
        }; \
    };

#define RACKS_AIR \
    class AcreRacks { \
        class Rack_1 { \
            displayName = "1"; \
            shortName = "1"; \
            componentName = "ACRE_VRC103"; \
            allowedPositions[] = {"driver", "copilot", "gunner", "commander"}; \
            disabledPositions[] = {}; \
            defaultComponents[] = {}; \
            mountedRadio = "ACRE_PRC117F"; \
            isRadioRemovable = 0; \
            intercom[] = {}; \
        }; \
        class Rack_2: Rack_1 { \
            displayName = "2"; \
            shortName = "2"; \
        }; \
        class Rack_3: Rack_1 { \
            displayName = "3"; \
            shortName = "3"; \
        }; \
    };

#define RACKS_AIR_FOUR \
    class AcreRacks { \
        class Rack_1 { \
            displayName = "1"; \
            shortName = "1"; \
            componentName = "ACRE_VRC103"; \
            allowedPositions[] = {"driver", "copilot", "gunner", "commander"}; \
            disabledPositions[] = {}; \
            defaultComponents[] = {}; \
            mountedRadio = "ACRE_PRC117F"; \
            isRadioRemovable = 0; \
            intercom[] = {}; \
        }; \
        class Rack_2: Rack_1 { \
            displayName = "2"; \
            shortName = "2"; \
        }; \
        class Rack_3: Rack_1 { \
            displayName = "3"; \
            shortName = "3"; \
        }; \
        class Rack_4: Rack_1 { \
            displayName = "4"; \
            shortName = "4"; \
        }; \
    };

#define RACKS_GROUND \
    class AcreRacks { \
        class Rack_1 { \
            displayName = "1"; \
            shortName = "1"; \
            componentName = "ACRE_VRC103"; \
            allowedPositions[] = {"crew", "external"}; \
            disabledPositions[] = {}; \
            defaultComponents[] = {}; \
            mountedRadio = "ACRE_PRC117F"; \
            isRadioRemovable = 1; \
            intercom[] = {}; \
        }; \
        class Rack_2: Rack_1 { \
            displayName = "2"; \
            shortName = "2"; \
            componentName = "ACRE_VRC110"; \
            mountedRadio = "ACRE_PRC152"; \
        }; \
        class Rack_3: Rack_1 { \
            displayName = "3"; \
            shortName = "3"; \
            mountedRadio = ""; \
        }; \
    };

#define RACKS_GROUND_APC \
    class AcreRacks { \
        class Rack_1 { \
            displayName = "1"; \
            shortName = "1"; \
            componentName = "ACRE_VRC103"; \
            allowedPositions[] = {"driver", "commander"}; \
            disabledPositions[] = {}; \
            defaultComponents[] = {}; \
            mountedRadio = "ACRE_PRC117F"; \
            isRadioRemovable = 1; \
            intercom[] = {"intercom_1"}; \
        }; \
        class Rack_2: Rack_1 { \
            displayName = "2"; \
            shortName = "2"; \
            componentName = "ACRE_VRC110"; \
            mountedRadio = "ACRE_PRC152"; \
        }; \
        class Rack_3: Rack_1 { \
            displayName = "3"; \
            shortName = "3"; \
            mountedRadio = ""; \
        }; \
    };

#define RACKS_AIR_GROUND \
    class AcreRacks { \
        class Rack_1 { \
            displayName = "1"; \
            shortName = "1"; \
            componentName = "ACRE_VRC103"; \
            allowedPositions[] = {"crew", "external"}; \
            disabledPositions[] = {}; \
            defaultComponents[] = {}; \
            mountedRadio = "ACRE_PRC117F"; \
            isRadioRemovable = 0; \
            intercom[] = {}; \
        }; \
        class Rack_2: Rack_1 { \
            displayName = "2"; \
            shortName = "2"; \
        }; \
    };
