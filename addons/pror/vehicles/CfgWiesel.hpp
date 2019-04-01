class I_LT_01_scout_F;
class PROR_AA_Radar : I_LT_01_scout_F {
    scope = 2;
    side = 0;
    faction = "UKSF_PROR";
    displayName = "Wiesel AA (RADAR)";
    editorPreview = QPATHTOEF(common,data\previews\PROR_AA_Radar.jpg);
    editorSubcategory = "EdSubcat_AAs";
    hiddenSelectionsTextures[] = {
        "A3\armor_f_tank\lt_01\data\lt_01_main_olive_co.paa",
        "A3\armor_f_tank\lt_01\data\lt_01_at_olive_co.paa",
        "A3\Armor_F\Data\camonet_AAF_Digi_Green_CO.paa",
        "A3\armor_f\data\cage_olive_co.paa"
    };
    crew = "PROR_Crew";
    typicalCargo[] = {
        "PROR_Crew",
        "PROR_Crew"
    };
};

class I_LT_01_AA_F;
class PROR_AA_Ozelot : I_LT_01_AA_F {
    scope = 2;
    side = 0;
    faction = "UKSF_PROR";
    displayName = "Wiesel AA (Ozelot)";
    editorPreview = QPATHTOEF(common,data\previews\PROR_AA_Ozelot.jpg);
    hiddenSelectionsTextures[] = {
        "A3\armor_f_tank\lt_01\data\lt_01_main_olive_co.paa",
        "A3\armor_f_tank\lt_01\data\lt_01_at_olive_co.paa",
        "A3\Armor_F\Data\camonet_AAF_Digi_Green_CO.paa",
        "A3\armor_f\data\cage_olive_co.paa"
    };
    crew = "PROR_Crew";
    typicalCargo[] = {
        "PROR_Crew",
        "PROR_Crew"
    };
};
