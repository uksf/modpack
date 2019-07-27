class CfgFactionClasses {
    class UKSF_GB {
        displayName = "British Army (UKSF)";
        icon = "a3\data_f\Flags\flag_uk_co.paa";
        flag = "a3\data_f\Flags\flag_uk_co.paa";
        priority = 1;
        side = 0;
    };
    class UKSF_Inegal {
        displayName = "Inegal";
        icon = "\A3\Structures_F\Mil\Flags\Data\Mast_civ_CO.paa";
        priority = 1;
        side = 0;
    };
    class UKSF_PROR {
        displayName = "Peoples Republic of Rosche";
        icon = "\A3\Structures_F\Mil\Flags\Data\Mast_civ_CO.paa";
        priority = 1;
        side = 0;
    };
    class UKSF_Spetsnaz {
        displayName = "Spetsnaz";
        icon = "\a3\Data_F_Enoch\FactionIcons\icon_RUS_CA.paa";
        priority = 1;
        side = 0;
    };
    class UKSF_AUG {
        displayName = "Altis Unionist Group";
        icon = "\a3\Data_f\Flags\flag_Altis_co.paa";
        priority = 1;
        side = 0;
    };
    class UKSF_VR {
        displayName = "Virtual Army";
        icon = "ca\ca_pmc\flag_ion_white_co";
        priority = 1;
        side = 0;
    };
    class NO_CATEGORY;
    class GVAR(zeus_uksf) : NO_CATEGORY {
        displayName = "UKSF";
        priority = 2;
        side = 7;
    };
    class GVAR(zeus_uksf_special) : GVAR(zeus_uksf) {
        displayName = "UKSF Special";
    };
    class GVAR(zeus_uksf_side) : GVAR(zeus_uksf) {
        displayName = "Side";
    };
    class OPF_R_F {
        displayName = "Spetsnaz (Future)";
        priority = 3;
        side = 0;
        icon = "\a3\Data_F_Enoch\FactionIcons\icon_RUS_CA.paa";
        flag = "\a3\Data_F_Enoch\Flags\flag_RUS_co.paa";
    };
};
