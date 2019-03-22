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

class Extended_InitPost_EventHandlers {
    class CAManBase {
        class ADDON {
            init = QUOTE(call FUNC(addSelfActions));
        };
    };
    // CUP_NVG_PVS7, CUP_NVG_HMNVS, CUP_NVG_PVS14
    NONVG(CUP_Creatures_Military_ACR_Soldier_Base); // ACR
    NONVG(CUP_Creatures_Military_CDF_Soldier_Base); // CDF
    NONVG(CUP_Creatures_Military_OPFINS_Soldier_Base); // Chedaki
    NONVG(CUP_Creatures_Military_RACS_Soldier_Base); // RACS
    NONVG(CUP_Creatures_Military_RUS_Soldier_Base); // Russia
    NONVG(CUP_Creatures_Military_SLA_Soldier_Base); // SLA
    NONVG(CUP_Creatures_Military_TK_Soldier_Base); // Taki Army
    NVG(CUP_Creatures_Military_UNO_Soldier_Base,CUP_NVG_PVS7); // UN
    NVG(CUP_Creatures_Military_GER_Soldier_Base,CUP_NVG_PVS7); // Germany
    NVG(CUP_Creatures_Military_PMC_Soldier_Base,CUP_NVG_PVS14); // PMC
    NVG(CUP_Creatures_Military_PMC_Soldier_Winter_Base,CUP_NVG_PVS14); // PMC
    NVG(CUP_Creatures_Military_USA_Soldier_Base,CUP_NVG_PVS14); // US Army
    NVG(CUP_Creatures_Military_USMC_Soldier_Base,CUP_NVG_PVS14); // USMC
    NVG(CUP_Creatures_Military_FR_Soldier_Base,CUP_NVG_PVS14); // USMC
};
