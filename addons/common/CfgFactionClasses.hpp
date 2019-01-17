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
    class UKSF_VR {
        displayName = "Virtual Army";
        icon = "ca\ca_pmc\flag_ion_white_co";
        priority = 1;
        side = 0;
    };
    class NO_CATEGORY;
    class GVAR(zeus_uksf): NO_CATEGORY {
        displayName = "UKSF";
        priority = 2;
        side = 7;
    };
    class GVAR(zeus_uksf_special): GVAR(zeus_uksf) {
        displayName = "UKSF Special";
    };
    class GVAR(zeus_uksf_side): GVAR(zeus_uksf) {
        displayName = "Side";
    };
};
