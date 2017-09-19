class CUP_L39_base;
class CUP_L39_CAP_Base: CUP_L39_base {
    class Turrets;
};
class CUP_B_L39_CAP_CZ: CUP_L39_CAP_Base {
    class Turrets: Turrets {
        class MainTurret;
    };
};
class UKSF_B_L39_CAP: CUP_B_L39_CAP_CZ {
    author = "UKSF";
    faction = "CUP_B_GB";
    editorPreview = QPATHTOEF(common,data\previews\UKSF_B_L39_CAP.jpg);
    crew = "UKSF_B_Pilot_617";
    typicalCargo[] = { "UKSF_B_Pilot_617","UKSF_B_Pilot_617" };
    hiddenSelectionsTextures[] = { QPATHTOF(data\l_39_body_raf.paa), QPATHTOF(data\l_39_body_1_raf.paa) };
    weapons[] = { "CUP_weapon_mastersafe", "CUP_Vacannon_GSh23L_L39", "CUP_Vmlauncher_R73_veh" };
    magazines[] = { "CUP_150Rnd_TE2_Green_Tracer_GSh23_23mm_APHE_M", "CUP_4Rnd_Missile_AA_03_F" };
    class Turrets: Turrets {
        class MainTurret: MainTurret {
            weapons[] = {};
            magazines[] = {};
        };
    };
    INVENTORY_AIRCRAFT
};
class CUP_B_L39_BMB_CZ;
class UKSF_B_L39_BMB: CUP_B_L39_BMB_CZ {
    author = "UKSF";
    faction = "CUP_B_GB";
    editorPreview = QPATHTOEF(common,data\previews\UKSF_B_L39_BMB.jpg);
    crew = "UKSF_B_Pilot_617";
    typicalCargo[] = { "UKSF_B_Pilot_617","UKSF_B_Pilot_617" };    
    hiddenSelectionsTextures[] = { QPATHTOF(data\l_39_body_raf.paa), QPATHTOF(data\l_39_body_1_raf.paa) };
    weapons[] = { "CUP_weapon_mastersafe", "CUP_Vacannon_GSh23L_L39", "CUP_Vblauncher_Fab250_veh" };
    magazines[] = { "CUP_150Rnd_TE2_Green_Tracer_GSh23_23mm_APHE_M", "CUP_4Rnd_FAB250_M" };
    INVENTORY_AIRCRAFT
};
