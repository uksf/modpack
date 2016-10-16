class I_APC_Wheeled_03_cannon_F;
class Inegal_APC_VBCI: I_APC_Wheeled_03_cannon_F {
	scope = 2;
	side = 0;
	faction = "UKSF_Inegal";
	displayName = "VBCI";
	editorPreview = QPATHTOEF(common,data\previews\Inegal_APC_VBCI.jpg);
	crew = "Inegal_Crew_C";
	typicalCargo[] = {
		"Inegal_Crew_C"
	};
	hiddenSelections[] = { "camo1", "camo2", "camo3", "camo4" };
	hiddenSelectionsTextures[] = {
		"A3\armor_f_gamma\APC_Wheeled_03\data\apc_wheeled_03_ext_co.paa",
		"A3\armor_f_gamma\APC_Wheeled_03\data\apc_wheeled_03_ext2_co.paa",
		"A3\armor_f_gamma\APC_Wheeled_03\data\rcws30_co.paa",
		"A3\armor_f_gamma\APC_Wheeled_03\data\apc_wheeled_03_ext_alpha_co.paa"
	};
	class TransportMagazines {};
	class TransportItems {};
	class TransportWeapons {};
	class TransportBackpacks {};
	class EventHandlers {
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
	};
};
