//AW101
class I_Heli_Transport_02_F;
class Inegal_Heli_AW101: I_Heli_Transport_02_F {
	scope = 2;
	side = 0;
	faction = "UKSF_Inegal";
	displayName = "AW101";
	editorPreview = QPATHTOEF(common,data\previews\Inegal_Heli_AW101.jpg);
	crew = "Inegal_Crew_HP";
	typicalCargo[] = {
		"Inegal_Crew_HC"
	};
	hiddenSelections[] = { "camo1", "camo2", "camo3" };
	hiddenSelectionsTextures[] = { QPATHTOF(data\blu_mohawk_co.paa), QPATHTOF(data\blu_mohawk2_co.paa), QPATHTOF(data\blu_mohawk3_co.paa) };
	class TransportMagazines {};
	class TransportItems {};
	class TransportWeapons {};
	class TransportBackpacks {};
	class EventHandlers {
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
	};
};

//AH6
class B_Heli_Light_01_armed_F;
class Inegal_Heli_AH6: B_Heli_Light_01_armed_F {
	scope = 2;
	side = 0;
	faction = "UKSF_Inegal";
	displayName = "AH-6";
	editorPreview = QPATHTOEF(common,data\previews\Inegal_Heli_AH6.jpg);
	crew = "Inegal_Crew_HP";
	typicalCargo[] = {
		"Inegal_Crew_HC"
	};
	class TransportMagazines {};
	class TransportItems {};
	class TransportWeapons {};
	class TransportBackpacks {};
};

//MH6
class B_Heli_Light_01_F;
class Inegal_Heli_MH6: B_Heli_Light_01_F {
	scope = 2;
	side = 0;
	faction = "UKSF_Inegal";
	displayName = "MH-6";
	editorPreview = QPATHTOEF(common,data\previews\Inegal_Heli_MH6.jpg);
	crew = "Inegal_Crew_HP";
	typicalCargo[] = {
		"Inegal_Crew_HC"
	};
	class TransportMagazines {};
	class TransportItems {};
	class TransportWeapons {};
	class TransportBackpacks {};
	class EventHandlers {
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
	};
};
class Inegal_Heli_FDF_MH6: Inegal_Heli_MH6 {
	displayName = "MH-6 (FDF)";
	crew = "Inegal_Crew_HP";
	typicalCargo[] = {
		"Inegal_Crew_HC"
	};
};
class Inegal_Heli_D_MH6: Inegal_Heli_MH6 {
	displayName = "MH-6 (Diablerie)";
	crew = "Inegal_Crew_HP";
	typicalCargo[] = {
		"Inegal_Crew_HC"
	};
};
