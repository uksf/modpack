//Unarmed
class Genfor_Hilux_Unarmed;
class Laraka_Hilux_Unarmed: Genfor_Hilux_Unarmed {
	faction = "UKSF_Laraka";
	displayName = "Hilux";
	crew = "Laraka_AK";
	typicalCargo[] = {
		"Laraka_L",
		"Laraka_AK",
		"Laraka_AK",
		"Laraka_PKM",
		"Laraka_RPG"
	};
};
class Laraka_Hilux_Unarmed_Populated: Genfor_Hilux_Unarmed {
	faction = "UKSF_Laraka";
	displayName = "Hilux (Populated)";
	crew = "Laraka_AK";
	typicalCargo[] = {
		"Laraka_L",
		"Laraka_AK",
		"Laraka_AK",
		"Laraka_PKM",
		"Laraka_RPG"
	};
	class EventHandlers {
		class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
	};
};

//DSHKM
class Genfor_Hilux_MG;
class Laraka_Hilux_DSHKM: Genfor_Hilux_MG {
	faction = "UKSF_Laraka";
	displayName = "Hilux DSHKM";
	crew = "Laraka_AK";
	typicalCargo[] = {
		"Laraka_AK"
	};
};

//Unarmed
class Azaadi_Hilux_Unarmed : Laraka_Hilux_Unarmed {
	faction = "UKSF_Azaadi";
	side = 2;
	crew = "Azaadi_AK";
	typicalCargo[] = {
		"Azaadi_L",
		"Azaadi_AK",
		"Azaadi_AK",
		"Azaadi_PKM",
		"Azaadi_RPG"
	};
};
class Azaadi_Hilux_Unarmed_Populated : Laraka_Hilux_Unarmed {
	faction = "UKSF_Azaadi";
	displayName = "Hilux (Populated)";
	side = 2;
	crew = "Azaadi_AK";
	typicalCargo[] = {
		"Azaadi_L",
		"Azaadi_AK",
		"Azaadi_AK",
		"Azaadi_PKM",
		"Azaadi_RPG"
	};
};

//DSHKM
class Azaadi_Hilux_DSHKM : Laraka_Hilux_DSHKM {
	faction = "UKSF_Azaadi";
	side = 2;
	crew = "Azaadi_AK";
	typicalCargo[] = {
		"Azaadi_AK"
	};
};
