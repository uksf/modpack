class CfgVehicles {
    class O_G_Soldier_F;
    class GVAR(base) : O_G_Soldier_F {
        author = "UKSF";
        scope = 0;
        faction = "UKSF_AUG";
        editorSubcategory = "EdSubcat_Personnel";
        displayName = "AUG Base";
        uniformClass = "U_OG_Guerilla1_1";
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
#include "vehicles\CfgAPC.hpp"
#include "vehicles\CfgHeli.hpp"
#include "vehicles\CfgJet.hpp"
#include "vehicles\CfgKamaz.hpp"
#include "vehicles\CfgLR.hpp"

    class G_FieldPack_LAT;
    class GVAR(at_pack): G_FieldPack_LAT {
        scope = 1;
        class TransportMagazines {
            class _xx_MRAWS_HEAT_F {
                count = 1;
                magazine = "MRAWS_HEAT_F";
            };
            class _xx_MRAWS_HE_F {
                count = 1;
                magazine = "MRAWS_HE_F";
            };
        };
        class TransportItems {};
        class TransportWeapons {};
    };
    class GVAR(aa_pack): G_FieldPack_LAT {
        scope = 1;
        class TransportMagazines {
            class _xx_Titan_AA {
                count = 1;
                magazine = "Titan_AA";
            };
        };
        class TransportItems {};
        class TransportWeapons {};
    };
    class B_TacticalPack_oli;
    class GVAR(mg_pack): B_TacticalPack_oli {
        scope = 1;
        class TransportMagazines {
            class _xx_CUP_100Rnd_TE4_LRT4_762x54_PK_Tracer_Yellow_M {
                count = 2;
                magazine = "CUP_100Rnd_TE4_LRT4_762x54_PK_Tracer_Yellow_M";
            };
        };
        class TransportItems {};
        class TransportWeapons {};
    };
    class GVAR(medic_pack): B_TacticalPack_oli {
        scope = 1;
        class TransportMagazines {};
        class TransportItems {
            class _xx_ACE_packingBandage {
                count = 20;
                name = "ACE_packingBandage";
            };
            class _xx_ACE_bloodIV_250 {
                count = 4;
                name = "ACE_bloodIV_250";
            };
            class _xx_ACE_bloodIV_500 {
                count = 2;
                name = "ACE_bloodIV_500";
            };
            class _xx_ACE_surgicalKit {
                count = 1;
                name = "ACE_surgicalKit";
            };
            class _xx_ACE_personalAidKit {
                count = 1;
                name = "ACE_personalAidKit";
            };
        };
        class TransportWeapons {};
    };
};
