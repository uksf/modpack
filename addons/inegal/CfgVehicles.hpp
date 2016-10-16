class CBA_Extended_EventHandlers;
class CfgVehicles {	
	class O_Soldier_base_F;
	class O_Soldier_F;
	class Inegal_Soldier_Underwear: O_Soldier_F {
		author = "UKSF";
		scope = 1;
		scopeCurator = 0;
		displayName = "Inegal Underwear";
		model = "\A3\Characters_F\Common\basicbody";
		uniformClass = "Inegal_U_Base";
		weapons[] = {
			"Throw",
			"Put"
		};
		respawnWeapons[] = {
			"Throw",
			"Put"
		};
		magazines[]={};
		respawnMagazines[] = {};
		hiddenSelections[] = { "camo" };
		hiddenSelectionsTextures[] = { "\A3\Characters_F\Common\Data\basicbody_black_co.paa" };
	};
	class Inegal_Soldier_Base: O_Soldier_base_F {
		author = "UKSF";
		scope = 0;
		faction = "UKSF_Inegal";
		displayName = "Inegal Base";
		nakedUniform = "Inegal_U_Base";
		uniformClass = "U_B_CTRG_Soldier_urb_3_F";
		model = "\A3\characters_F\OPFOR\o_soldier_01.p3d";
		identityTypes[] = { "LanguageENGFRE_F", "Head_Euro" };
		genericNames = "FrenchMen";
		weapons[] = {};
		respawnWeapons[] = {};
		magazines[] = {};
		respawnMagazines[] = {};
		items[] = {};
		respawnItems[] = {};
		linkedItems[] = {};
		respawnLinkedItems[] = {};
		accuracy = 2.3;
		camouflage = 1.2;
		cost = 90000;
		threat[] = {1,0.1,0.1};
		class Wounds {
			tex[] = {};
			mat[] = {
				"A3\Characters_F\BLUFOR\Data\clothing1.rvmat",
				"A3\Characters_F\BLUFOR\Data\clothing1_injury.rvmat",
				"A3\Characters_F\BLUFOR\Data\clothing1_injury.rvmat",
				"A3\Characters_F\Common\Data\basicbody.rvmat",
				"A3\Characters_F\Common\Data\basicbody_injury.rvmat",
				"A3\Characters_F\Common\Data\basicbody_injury.rvmat",
				"A3\Characters_F\Common\Data\coveralls.rvmat",
				"A3\Characters_F\Common\Data\coveralls_injury.rvmat",
				"A3\Characters_F\Common\Data\coveralls_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_bald_muscular.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_black_bald_muscular.rvmat",
				"A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_hairy_muscular.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_old.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_asian_bald_muscular.rvmat",
				"A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat"
			};
		};
	};

	#include "units\CfgCombattants.hpp"
	#include "units\CfgFDF.hpp"
	#include "units\CfgDiablerie.hpp"
	#include "units\CfgRecrues.hpp"
	#include "units\CfgCrew.hpp"

	#include "vehicles\CfgLandRover.hpp"
	#include "vehicles\CfgVAB.hpp"
	#include "vehicles\CfgTRM.hpp"
	#include "vehicles\CfgVBCI.hpp"
	#include "vehicles\CfgLeclerc.hpp"
	#include "vehicles\CfgHeli.hpp"
	#include "vehicles\CfgJet.hpp"
	#include "vehicles\CfgStatic.hpp"
};