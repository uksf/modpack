class I_mas_cars_Ural_Base;
class I_mas_cars_Ural_BM21_Base;
class I_mas_cars_Ural_ZU23_Base;

//Transport
class I_mas_cars_Ural: I_mas_cars_Ural_Base {
	scope = 0;
};
class O_mas_cars_Ural: I_mas_cars_Ural {
	scope = 0;
};
class Genfor_Ural_Transport: O_mas_cars_Ural {
	scope = 2;
	side = 0;
	faction = "UKSF_Genfor";
	editorPreview = QPATHTOEF(common,data\previews\Genfor_Ural_Transport.jpg);
	editorSubcategory = QEGVAR(common,support);
	displayName = "Ural";
	crew = "GENFOR_R";
	typicalCargo[] = {
		"GENFOR_R"
	};
	class TransportMagazines {};
	class TransportItems {};
	class TransportWeapons {};
	class TransportBackpacks {};
};
class Genfor_Ural_Transport_Populated: Genfor_Ural_Transport {
	displayName = "Ural (Populated)";
	class EventHandlers {
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
	};
};

//Transport open
class I_mas_cars_Ural_open: I_mas_cars_Ural {
	scope = 0;
};
class O_mas_cars_Ural_open: I_mas_cars_Ural_open {
	scope = 0;
};
class Genfor_Ural_TransportOpen: O_mas_cars_Ural_open {
	scope = 2;
	side = 0;
	faction = "UKSF_Genfor";
	displayName = "Ural Open";
	editorPreview = QPATHTOEF(common,data\previews\Genfor_Ural_TransportOpen.jpg);
	editorSubcategory = QEGVAR(common,support);
	crew = "GENFOR_R";
	typicalCargo[] = {
		"GENFOR_R"
	};
	class TransportMagazines {};
	class TransportItems {};
	class TransportWeapons {};
	class TransportBackpacks {};
};
class Genfor_Ural_TransportOpen_Populated: Genfor_Ural_TransportOpen {
	displayName = "Ural Open (Populated)";
	class EventHandlers {
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
	};
};

//Ammo
class I_mas_cars_Ural_ammo: I_mas_cars_Ural_Base {
	scope = 0;
};
class O_mas_cars_Ural_ammo: I_mas_cars_Ural_ammo {
	scope = 0;
};
class Genfor_Ural_Ammo: O_mas_cars_Ural_ammo {
	scope = 2;
	side = 0;
	faction = "UKSF_Genfor";
	displayName = "Ural Ammo";
	editorPreview = QPATHTOEF(common,data\previews\Genfor_Ural_Ammo.jpg);
	editorSubcategory = QEGVAR(common,support);
	crew = "GENFOR_R";
	typicalCargo[] = {
		"GENFOR_R"
	};
	class TransportMagazines {};
	class TransportItems {};
	class TransportWeapons {};
	class TransportBackpacks {};
};

//Repair
class I_mas_cars_Ural_repair: I_mas_cars_Ural_Base {
	scope = 0;
};
class O_mas_cars_Ural_repair: I_mas_cars_Ural_repair {
	scope = 0;
};
class Genfor_Ural_Repair: O_mas_cars_Ural_repair {
	scope = 2;
	side = 0;
	faction = "UKSF_Genfor";
	displayName = "Ural Repair";
	editorPreview = QPATHTOEF(common,data\previews\Genfor_Ural_Repair.jpg);
	editorSubcategory = QEGVAR(common,support);
	crew = "GENFOR_R";
	typicalCargo[] = {
		"GENFOR_R"
	};
	class TransportMagazines {};
	class TransportItems {};
	class TransportWeapons {};
	class TransportBackpacks {};
};

//Refuel
class I_mas_cars_Ural_fuel: I_mas_cars_Ural_Base {
	scope = 0;
};
class O_mas_cars_Ural_fuel: I_mas_cars_Ural_fuel {
	scope = 0;
};
class Genfor_Ural_Fuel: O_mas_cars_Ural_fuel {
	scope = 2;
	side = 0;
	faction = "UKSF_Genfor";
	displayName = "Ural Fuel";
	editorPreview = QPATHTOEF(common,data\previews\Genfor_Ural_Fuel.jpg);
	editorSubcategory = QEGVAR(common,support);
	crew = "GENFOR_R";
	typicalCargo[] = {
		"GENFOR_R"
	};
	class TransportMagazines {};
	class TransportItems {};
	class TransportWeapons {};
	class TransportBackpacks {};
};

//BM21
class I_mas_cars_Ural_BM21: I_mas_cars_Ural_BM21_Base {
	scope = 0;
};
class O_mas_cars_Ural_BM21: I_mas_cars_Ural_BM21 {
	scope = 0;
};
class Genfor_Ural_BM21: O_mas_cars_Ural_BM21 {
	scope = 2;
	side = 0;
	faction = "UKSF_Genfor";
	displayName = "Ural BM21";
	editorPreview = QPATHTOEF(common,data\previews\Genfor_Ural_BM21.jpg);
	editorSubcategory = QEGVAR(common,support);
	crew = "GENFOR_R";
	typicalCargo[] = {
		"GENFOR_R"
	};
	class TransportMagazines {};
	class TransportItems {};
	class TransportWeapons {};
	class TransportBackpacks {};
};

//ZSU
class I_mas_cars_Ural_ZU23: I_mas_cars_Ural_ZU23_Base {
	scope = 0;
};
class O_mas_cars_Ural_ZU23: I_mas_cars_Ural_ZU23 {
	scope = 0;
};
class Genfor_Ural_ZSU: O_mas_cars_Ural_ZU23 {
	scope = 2;
	side = 0;
	faction = "UKSF_Genfor";
	displayName = "Ural ZSU";
	editorPreview = QPATHTOEF(common,data\previews\Genfor_Ural_ZSU.jpg);
	editorSubcategory = QEGVAR(common,support);
	crew = "GENFOR_R";
	typicalCargo[] = {
		"GENFOR_R"
	};
	radarType = 2;
	class TransportMagazines {};
	class TransportItems {};
	class TransportWeapons {};
	class TransportBackpacks {};
	class EventHandlers {
		init = "(_this select 0) setSkill [""aimingAccuracy"", 0.01]; (_this select 0) setSkill [""aimingSpeed"", 0.01]; (_this select 0) setSkill [""aimingshake"", 0.01]; (_this select 0) setSkill [""spotTime"", 1];";
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
	};
};
