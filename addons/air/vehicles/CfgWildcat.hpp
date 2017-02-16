class CUP_AW159_Unarmed_Base: Helicopter_Base_H {
    scope = 1;
    scopeCurator = 0;
    maxspeed = 311;
    landingSoundInt0[]= { "A3\Sounds_F\vehicles\air\noises\landing_wheels_small_int1", 0.25, 1, 50 };
    landingSoundInt1[]= { "A3\Sounds_F\vehicles\air\noises\landing_wheels_small_int2", 0.25, 1, 50 };
    landingSoundInt[]= { "landingSoundInt0", 0.5, "landingSoundInt1", 0.5 };
    landingSoundOut0[]= { "A3\Sounds_F\vehicles\air\noises\landing_wheels_ext1", 0.4, 1, 50 };
    landingSoundOut1[]= { "A3\Sounds_F\vehicles\air\noises\landing_wheels_ext2", 0.4, 1, 50 };
    landingSoundOut[]= { "landingSoundOut0", 0.5, "landingSoundOut1", 0.5 };
    unitInfoType = "Rsc_UKSF_Air_Limited";
    unitInfoTypeLite = "Rsc_UKSF_Air_Limited";
    #include "MFDGeneral.hpp"
    class ACE_Actions : ACE_Actions {
        class ACE_MainActions: ACE_MainActions {
            position = "[0,0,1.5]";
        };
    };
};
class CUP_B_AW159_Unarmed_GB: CUP_AW159_Unarmed_Base {
    scope = 1;
    scopeCurator = 0;
};
class CUP_B_AW159_Unarmed_BAF: CUP_B_AW159_Unarmed_GB {
    scope = 1;
    scopeCurator = 0;
};
class CUP_B_AW159_Unarmed_RN_Blackcat;
class CUP_B_Wildcat_Unarmed_RN_Blackcat: CUP_B_AW159_Unarmed_RN_Blackcat {
    scope = 1;
    scopeCurator = 0;
};
class CUP_B_AW159_Hellfire_GB: CUP_AW159_Unarmed_Base {
    scope = 1;
    scopeCurator = 0;
};
class CUP_B_AW159_Hellfire_RN_Grey: CUP_AW159_Unarmed_Base {
    #include "MFDCAS.hpp"
};
class CUP_B_AW159_Hellfire_RN_Blackcat: CUP_AW159_Unarmed_Base {
    scope = 1;
    scopeCurator = 0;
};
class CUP_B_AW159_Cannon_GB: CUP_AW159_Unarmed_Base {
    scope = 1;
    scopeCurator = 0;
};
class CUP_B_AW159_Cannon_RN_Grey: CUP_AW159_Unarmed_Base {
    #include "MFDCAS.hpp"
};
class CUP_B_AW159_Cannon_RN_Blackcat: CUP_AW159_Unarmed_Base {
    scope = 1;
    scopeCurator = 0;
};
class CUP_I_Wildcat_Hellfire_Armed_Green_AAF: CUP_AW159_Unarmed_Base {
    #include "MFDCAS.hpp"
};
class CUP_I_Wildcat_Cannon_Armed_Green_AAF: CUP_AW159_Unarmed_Base {
    #include "MFDCAS.hpp"
};
class CUP_I_Wildcat_Cannon_Armed_Digital_AAF: CUP_AW159_Unarmed_Base {
    #include "MFDCAS.hpp"
};
