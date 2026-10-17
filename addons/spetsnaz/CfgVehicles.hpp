class CfgVehicles {
    class CUP_O_RUS_Soldier_TL;
    class GVAR(base) : CUP_O_RUS_Soldier_TL {
        author = "UKSF";
        scope = 0;
        faction = "UKSF_Spetsnaz";
        editorSubcategory = "EdSubcat_Personnel";
        displayName = "Spetsnaz Base";
        uniformClass = "CUP_U_B_CZ_DST_Kneepads_Sleeve";
        weapons[] = {};
        respawnWeapons[] = {};
        magazines[] = {};
        respawnMagazines[] = {};
        items[] = {};
        respawnItems[] = {};
        linkedItems[] = {};
        respawnLinkedItems[] = {};
    };

#include "units\CfgInfantry.hpp"
#include "units\CfgCrew.hpp"
#include "units\CfgCiv.hpp"
#include "vehicles\CfgHeli.hpp"
#include "vehicles\CfgJet.hpp"
#include "vehicles\CfgLMV.hpp"
#include "vehicles\CfgStatic.hpp"

    class B_AssaultPack_khk;
    class GVAR(medic_pack): B_AssaultPack_khk {
        scope = 1;
        class TransportMagazines {};
        class TransportItems {
            class _xx_ACE_elasticBandage {
                count = 25;
                name = "ACE_elasticBandage";
            };
            class _xx_ACE_packingBandage {
                count = 25;
                name = "ACE_packingBandage";
            };
            class _xx_ACE_bloodIV_500 {
                count = 5;
                name = "ACE_bloodIV_500";
            };
        };
        class TransportWeapons {};
    };
    class B_AssaultPack_rgr;
    class GVAR(explosive_specialist_pack): B_AssaultPack_rgr {
        scope = 1;
        class TransportMagazines {
            class _xx_APERSMine_Range_Mag {
                count = 3;
                magazine = "APERSMine_Range_Mag";
            };
            class _xx_APERSTripMine_Wire_Mag {
                count = 2;
                magazine = "APERSTripMine_Wire_Mag";
            };
        };
        class TransportItems {};
        class TransportWeapons {};
    };
    class B_AssaultPack_blk;
    class GVAR(diver_pack): B_AssaultPack_blk {
        scope = 1;
        class TransportMagazines {
            class _xx_CUP_PipeBomb_M {
                count = 1;
                magazine = "CUP_PipeBomb_M";
            };
            class _xx_CUP_30Rnd_545x39_AK74_plum_M {
                count = 2;
                magazine = "CUP_30Rnd_545x39_AK74_plum_M";
            };
        };
        class TransportItems {};
        class TransportWeapons {};
    };
};
