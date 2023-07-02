class CfgWeapons {
    class U_BasicBody;
    class UniformItem;
    class GVAR(U_Base) : U_BasicBody {
        author = "UKSF";
        scope = 1;
        displayName = "$STR_A3_Underwear1";
        picture = "\A3\characters_f\data\ui\icon_U_BasicBody_ca.paa";
        hiddenSelections[] = { "camo" };
        hiddenSelectionsTextures[] = { "\A3\Characters_F\Common\Data\basicbody_black_co.paa" };
        class ItemInfo : UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(Soldier_Underwear);
            containerClass = "Supply0";
            mass = 5;
        };
    };

    class CUP_arifle_ACRC_blk_556;
    class GVAR(ACRC_blk_556_CUP_acc_FlashlightACE_optic_MRCO_2D) : CUP_arifle_ACRC_blk_556 {
        displayName = "ACR-C (Black, 5.56x45)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "ACE_optic_MRCO_2D";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "CUP_acc_Flashlight";
            };
        };
    };
    class CUP_smg_Mac10;
    class GVAR(Mac10_suppressed) : CUP_smg_Mac10 {
        displayName = "Mac 10 (Suppressed)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "muzzle_snds_acp";
            };
        };
    };

    class CUP_srifle_LeeEnfield;
    class GVAR(LeeEnfield_no32) : CUP_srifle_LeeEnfield {
        displayName = "Lee Enfield (Scoped)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "cup_optic_no23mk2";
            };
        };
    };

    class CUP_arifle_G3A3_modern_ris_black;
    class GVAR(G3A3_modern_ris_black_burris_anpeq_flash_hider) : CUP_arifle_G3A3_modern_ris_black {
        displayName = "G3 (Commando)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_dms_weathered_f";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "cup_acc_anpeq_2_grey";
            };
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "cup_muzzle_mfsup_flashhider_762x51_black";
            };
        };
    };

    class CUP_smg_MP5A5;
    class GVAR(MP5A5_t1) : CUP_smg_MP5A5 {
        displayName = "MP5 (T1 Micro)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "cup_optic_microt1_low";
            };
        };
    };

    class CUP_arifle_G36A3_AG36;
    class GVAR(G36A3_AG36_t1_laser) : CUP_arifle_G36A3_AG36 {
        displayName = "G36 GL (T1 Micro)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "cup_optic_microt1_low";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "cup_acc_anpeq_15_black";
            };
        };
    };

    class CUP_arifle_HK416_CQB_Black;
    class GVAR(HK416_CQB_Black_t1_laser) : CUP_arifle_HK416_CQB_Black {
        displayName = "HK416 (T1 Micro)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "cup_optic_microt1_low";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "cup_acc_anpeq_15_black";
            };
        };
    };

    class CUP_arifle_HK416_Black;
    class GVAR(HK416_Black_barska_laser) : CUP_arifle_HK416_Black {
        displayName = "HK416 (Barska)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "cup_optic_ac11704_black";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "cup_acc_anpeq_15_black";
            };
        };
    };

    class CUP_srifle_VSSVintorez_VFG;
    class GVAR(VSSVintorez_VFG_pso1_laser) : CUP_srifle_VSSVintorez_VFG {
        displayName = "VSS Vintorez (PSO-1)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "cup_optic_pso_1_open";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "ace_acc_pointer_green";
            };
        };
    };

    class CUP_smg_saiga9;
    class GVAR(saiga9_1p87) : CUP_smg_saiga9 {
        displayName = "Lee Enfield (Scoped)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "cup_optic_1p87_ris";
            };
        };
    };

    class CUP_arifle_RPK74M;
    class GVAR(RPK74M_1p63_laser) : CUP_arifle_RPK74M {
        displayName = "Lee Enfield (Scoped)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "cup_optic_1p63";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "ace_acc_pointer_green";
            };
        };
    };
};
