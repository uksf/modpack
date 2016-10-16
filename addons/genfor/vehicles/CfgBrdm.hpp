//BRDM2
class mas_BRDM2_BASE;
class I_mas_BRDM2: mas_BRDM2_BASE {
	scope = 0;
};
class O_mas_BRDM2: I_mas_BRDM2 {
	scope = 0;
};
class Genfor_Brdm_BRDM2: O_mas_BRDM2 {
	scope = 2;
	side = 0;
	faction = "UKSF_Genfor";
	editorPreview = QPATHTOEF(common,data\previews\Genfor_Brdm_BRDM2.jpg);
	displayName = "BRDM2";
	crew = "GENFOR_TC";
	typicalCargo[] = {
		"GENFOR_R"
	};
	class TransportMagazines {};
	class TransportItems {};
	class TransportWeapons {};
	class TransportBackpacks {};
};

//BTR60
class mas_BTR60_Base;
class I_mas_BTR60: mas_BTR60_Base {
	scope = 0;
};
class O_mas_BTR60: I_mas_BTR60 {
	scope = 0;
};
class Genfor_Brdm_BTR60: O_mas_BTR60 {
	scope = 2;
	side = 0;
	faction = "UKSF_Genfor";
	editorPreview = QPATHTOEF(common,data\previews\Genfor_Brdm_BTR60.jpg);
	displayname = "BTR60";
	crew = "GENFOR_TC";
	typicalCargo[] = {
		"GENFOR_R"
	};
	class TransportMagazines {};
	class TransportItems {};
	class TransportWeapons {};
	class TransportBackpacks {};
};