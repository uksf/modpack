class Extended_PreStart_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preStart));
    };
};

class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preInit));
    };
};

class Extended_PostInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_postInit));
    };
};

class Extended_Init_EventHandlers {
    class CAManBase {
        class ADDON {
            init = QUOTE(_this call FUNC(addAction));
        };
    };
    // CUP_NVG_PVS7, CUP_NVG_HMNVS, CUP_NVG_PVS14
    NVG(CUP_Creatures_Military_ACR_Soldier_Base,CUP_NVG_PVS7); // ACR
    NVG(CUP_Creatures_Military_CDF_Soldier_Base,CUP_NVG_PVS7); // CDF
    NVG(CUP_Creatures_Military_UNO_Soldier_Base,CUP_NVG_PVS7); // CDF
    //NVG(CUP_Creatures_Military_OPFINS_Soldier_Base,CUP_NVG_PVS7); // Chedaki
    NVG(CUP_Creatures_Military_GER_Soldier_Base,CUP_NVG_PVS7); // Germany
    NVG(CUP_Creatures_Military_PMC_Soldier_Base,CUP_NVG_PVS14); // PMC
    NVG(CUP_Creatures_Military_PMC_Soldier_Winter_Base,CUP_NVG_PVS14); // PMC
    NVG(CUP_Creatures_Military_RACS_Soldier_Base,CUP_NVG_PVS7); // RACS
    NVG(CUP_Creatures_Military_RUS_Soldier_Base,CUP_NVG_PVS7); // Russia
    NVG(CUP_Creatures_Military_SLA_Soldier_Base,CUP_NVG_PVS7); // SLA
    NVG(CUP_Creatures_Military_TK_Soldier_Base,CUP_NVG_PVS7); // Taki Army
    NVG(CUP_Creatures_Military_USA_Soldier_Base,CUP_NVG_PVS14); // US Army
    NVG(CUP_Creatures_Military_USMC_Soldier_Base,CUP_NVG_PVS14); // USMC
    NVG(CUP_Creatures_Military_FR_Soldier_Base,CUP_NVG_PVS14); // USMC
};
