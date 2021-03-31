#define COMPONENT resupply
#define COMPONENT_BEAUTIFIED Resupply
#include "\u\uksf\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS

#include "\u\uksf\addons\main\script_macros.hpp"

#define BOX_EXPLOSIVE class AnimationSources { \
    class Ammo_source { \
        source = "user"; \
        animPeriod = 1; \
        initPhase = 1; \
    }; \
    class AmmoOrd_source { \
        source = "user"; \
        animPeriod = 1; \
        initPhase = 0; \
    }; \
    class Grenades_source { \
        source = "user"; \
        animPeriod = 1; \
        initPhase = 1; \
    }; \
    class Support_source { \
        source = "user"; \
        animPeriod = 1; \
        initPhase = 1; \
    }; \
}; \
class SimpleObject { \
    eden = 1; \
    animate[] = {{"ammo_hide", 1}, {"ammoord_hide", 0}, {"grenades_hide", 1}, {"support_hide", 1}}; \
    hide[] = {}; \
    verticalOffset = 0.284; \
    verticalOffsetWorld = 0; \
    init = "''"; \
}; \
icon = "iconCrateOrd"

#define BOX_LAUNCHER class SimpleObject { \
    eden = 1; \
    animate[] = {}; \
    hide[] = {}; \
    verticalOffset = 0.15; \
    verticalOffsetWorld = 0; \
    init = "''"; \
}; \
model = "\A3\weapons_F\AmmoBoxes\WpnsBox_long_F"; \
icon = "iconCrateLong"
