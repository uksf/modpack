#define COMPONENT radios
#define COMPONENT_BEAUTIFIED Radios
#include "\u\uksf\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS

#include "\u\uksf\addons\main\script_macros.hpp"

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
    }

#define RACKS_GROUND \
    class AcreRacks { \
        class Rack_1 { \
            displayName = "R1"; \
            shortName = "R1"; \
            componentName = "ACRE_VRC103"; \
            allowedPositions[] = {"crew", "external"}; \
            disabledPositions[] = {}; \
            defaultComponents[] = {}; \
            mountedRadio = "ACRE_PRC117F"; \
            isRadioRemovable = 1; \
            intercom[] = {}; \
        }; \
        class Rack_2: Rack_1 { \
            displayName = "R2"; \
            shortName = "R2"; \
            componentName = "ACRE_VRC110"; \
            mountedRadio = "ACRE_PRC152"; \
        }; \
        class Rack_3: Rack_1 { \
            displayName = "R3"; \
            shortName = "R3"; \
            mountedRadio = ""; \
        }; \
    }

#define RACKS_GROUND_APC \
    class AcreRacks { \
        class Rack_1 { \
            displayName = "R1"; \
            shortName = "R1"; \
            componentName = "ACRE_VRC103"; \
            allowedPositions[] = {"driver", "commander"}; \
            disabledPositions[] = {}; \
            defaultComponents[] = {}; \
            mountedRadio = "ACRE_PRC117F"; \
            isRadioRemovable = 1; \
            intercom[] = {"intercom_1"}; \
        }; \
        class Rack_2: Rack_1 { \
            displayName = "R2"; \
            shortName = "R2"; \
            componentName = "ACRE_VRC110"; \
            mountedRadio = "ACRE_PRC152"; \
        }; \
        class Rack_3: Rack_1 { \
            displayName = "R3"; \
            shortName = "R3"; \
            mountedRadio = ""; \
        }; \
    }

#define RACKS_AIR_GROUND \
    class AcreRacks { \
        class Rack_1 { \
            displayName = "R1"; \
            shortName = "R1"; \
            componentName = "ACRE_VRC103"; \
            allowedPositions[] = {"crew", "external"}; \
            disabledPositions[] = {}; \
            defaultComponents[] = {}; \
            mountedRadio = "ACRE_PRC117F"; \
            isRadioRemovable = 0; \
            intercom[] = {}; \
        }; \
        class Rack_2: Rack_1 { \
            displayName = "R2"; \
            shortName = "R2"; \
        }; \
    }

#define RACK_NAME_REBRO QUOTE(RBro)
#define REBRO_MAST_POWER 50000
#define REBRO_RACK_POWER 20000

#define REBRO_TRACE_1(MESSAGE,A) if (GVAR(rebroDebugging)) then {LOG_SYS_FILELINENUMBERS('TRACE',PFORMAT_1(str diag_frameNo + ' ' + (MESSAGE),A))}
#define REBRO_TRACE_2(MESSAGE,A,B) if (GVAR(rebroDebugging)) then {LOG_SYS_FILELINENUMBERS('TRACE',PFORMAT_2(str diag_frameNo + ' ' + (MESSAGE),A,B))}
#define REBRO_TRACE_3(MESSAGE,A,B,C) if (GVAR(rebroDebugging)) then {LOG_SYS_FILELINENUMBERS('TRACE',PFORMAT_3(str diag_frameNo + ' ' + (MESSAGE),A,B,C))}
#define REBRO_TRACE_4(MESSAGE,A,B,C,D) if (GVAR(rebroDebugging)) then {LOG_SYS_FILELINENUMBERS('TRACE',PFORMAT_4(str diag_frameNo + ' ' + (MESSAGE),A,B,C,D))}
