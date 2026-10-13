class Offroad_01_base_F;
class VTOL_Base_F;
class Wall_F;
class Buoy_base_F;
class C_Uniform_ArtTShirt_01_base_F;
class B_Soldier_F;
class Strategic;
class C_man_w_worker_F_dgtl;
class I_E_Helipilot_F;
class I_E_Man_Base_F;
class O_Soldier_base_F;
class C_man_1;
class TripodScreen_CTRG_large_01;
class Land_SurvivalRadio_F;
class Animal_Base_F;
class Land_PortableLongRangeRadioMilitary_F;
class Land_PortableLongRangeRadio_F;
class Land_Portable_generator_F;
class Furniture_Residental_base_F;
class Land_Photos_V4_F;
class Photoframe_icon;
class O_T_Soldier_F;
class Land_MultiScreenComputer_01_base_F;
class Logic;
class Leaflet_05_Old_F;
class Leaflet_05_F;
class Laptop_CTRG_01;
class Land_Laptop_03_sand_F;
class Land_Laptop_03_base_F;
class Land_Laptop_03_black_F;
class Land_WhiteBoard_Orange_F;
class Land_TripodScreen_01_large_F;
class Land_powerline_02_pole_junction_nest_a_f;
class Land_Photoframe_01_F;
class Land_Photoframe_01_broken_F;
class Land_PCSet_01_screen_EdenEditor_F;
class Land_MapBoard_01_Wall_Orange_F;
class Leaflet_05_New_F;
class Land_Laptop_03_sand_NATO_F;
class Land_Laptop_03_black_NATO_F;
class Infostand_base_F;
class FloatingStructure_F;
class B_G_Soldier_GL_F;
class I_soldier_F;
class I_Soldier_base_F;
class GalleryDioramaUnit_01_base_F;
class Land_FMradio_F;
class FlowerBouquet_base_F;
class Land_Photos_V3_F;
class Land_Chemlight_Yellow_noLight;
class Land_Chemlight_Red_noLight;
class Land_Chemlight_Green_noLight;
class Land_Chemlight_Blue_noLight;
class C_man_hunter_1_F;
class Book_02_F;
class Book_01_large;
class Book_01_F;
class Book_01_small;
class B_W_Soldier_F;
class B_Soldier_TL_F;
class B_Soldier_SL_F;
class B_recon_TL_F;
class B_officer_F;
class B_CTRG_soldier_M_medic_F;
class B_Soldier_03_f;
class B_crew_F;
class B_G_Soldier_F;
class Rubber_duck_base_F;
class Land_Camping_Light_F : FloatingStructure_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Logic_attachSynchronizedObjects : Logic {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class All {
    class AnimationSources;
};
class Land_BuoyBig_F : Buoy_base_F {
    class AnimationSources {
        class light_1_source {
            source = "MarkerLight";
        };
    };
};
class AllVehicles : All {
    class NewTurret;
};
class Land : AllVehicles {};
class LandVehicle : Land {};
class Car : LandVehicle {
    class Turrets;
};
class Car_F : Car {
    class AnimationSources;
    class NewTurret;
    class Turrets {
        class MainTurret;
    };
};
