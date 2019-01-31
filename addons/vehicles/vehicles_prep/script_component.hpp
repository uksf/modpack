#define COMPONENT vehicles_prep
#include "\u\uksf\addons\main\script_mod.hpp"
#include "\u\uksf\addons\main\script_macros.hpp"

#define RESET_INVENTORY(CLASS,BASE) class CLASS : BASE { \
    delete TransportMagazines; \
    delete TransportItems; \
    delete TransportWeapons; \
    delete TransportBackpacks; \
}
