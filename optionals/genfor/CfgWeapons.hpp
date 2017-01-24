class asdg_OpticRail1913_long;
class rhs_western_rifle_scopes_slot_long: asdg_OpticRail1913_long {};
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class SlotInfo;
class CowsSlot;
class MuzzleSlot;
class PointerSlot;
class UnderBarrelSlot;
class CfgWeapons {
    class U_BasicBody;
    class UniformItem;
    class GENFOR_U_Base: U_BasicBody {
        author = "UKSF";
        scope = 1;
        displayName = "$STR_A3_Underwear1";
        picture = "\A3\characters_f\data\ui\icon_U_BasicBody_ca.paa";
        hiddenSelections[] = { "camo" };
        hiddenSelectionsTextures[] = { "\A3\Characters_F\Common\Data\basicbody_black_co.paa" };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "GENFOR_Soldier_Underwear";
            containerClass = "Supply0";
            mass = 5;
        };
    };

    class CannonCore;
    class mas_AZP23: CannonCore {
        scope = 1;
        displayName = "AZP-23 Amur";
        nameSound = "cannon";
        cartridgePos = "eject1";
        cartridgeVel = "eject1dir";
        cursor = "emptyCursor";
        cursorAim = "mg";
        cursorAimOn = "";
        cursorSize = 1;
        canLock = 2;
        class gunParticles {
            class effect1 {
                positionName = "eject1";
                directionName = "eject1dir";
                effectName = "MachineGunCartridge2";
            };
            class effect2 {
                positionName = "eject2";
                directionName = "eject2dir";
                effectName = "MachineGunCartridge2";
            };
            class effect3 {
                positionName = "eject3";
                directionName = "eject3dir";
                effectName = "MachineGunCartridge2";
            };
            class effect4 {
                positionName = "eject4";
                directionName = "eject4dir";
                effectName = "MachineGunCartridge2";
            };
            class mg1 {
                positionName = "chase01e";
                directionName = "chase01dir";
                effectName = "MachineGun1";
            };
            class mg2 {
                positionName = "chase03e";
                directionName = "chase03dir";
                effectName = "MachineGun1";
            };
            class mg3 {
                positionName = "chase03e";
                directionName = "chase03dir";
                effectName = "MachineGun1";
            };
            class mg4 {
                positionName = "chase04e";
                directionName = "chase04dir";
                effectName = "MachineGun1";
            };
        };
        magazines[] = { "mas_200Rnd_23mm_AZP23" };
        magazineReloadTime = 14;
        modes[] = { "manual", "close", "short", "medium", "far" };
        class manual: CannonCore {
            displayName = "AZP-23 Amur";
            autoFire = 1;
            sounds[] = { "StandardSound" };
            class StandardSound {
                weaponSoundEffect = "DefaultRifle";
                begin1[] = { "\mas_vehicle\zu23\Data\Sound\2a14_1shot", 1, 1, 1400 };
                soundBegin[] = { "begin1", 1 };
            };
            reloadTime = 0.024;
            dispersion = 0.005;
            multiplier = 2;
            soundContinuous = 0;
            showToPlayer = 1;
            burst = 1;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            aiDispersionCoefX = 0.2;
            aiDispersionCoefY = 0.2;
            minRange = 1;
            minRangeProbab = 0.008;
            midRange = 2;
            midRangeProbab = 0.008;
            maxRange = 3;
            maxRangeProbab = 0.008;
        };
        class close: manual {
            showToPlayer = 0;
            soundBurst = 0;
            burst = 16;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 1000;
            minRange = 0;
            minRangeProbab = 0.04;
            midRange = 1000;
            midRangeProbab = 0.4;
            maxRange = 1600;
            maxRangeProbab = 0.2;
        };
        class short: close {
            burst = 16;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 1600;
            minRange = 1000;
            minRangeProbab = 0.3;
            midRange = 1600;
            midRangeProbab = 0.4;
            maxRange = 2200;
            maxRangeProbab = 0.3;
        };
        class medium: close {
            burst = 20;
            aiRateOfFire = 4;
            aiRateOfFireDistance = 2200;
            minRange = 1600;
            minRangeProbab = 0.2;
            midRange = 2000;
            midRangeProbab = 0.4;
            maxRange = 2800;
            maxRangeProbab = 0.2;
        };
        class far: close {
            burst = 12;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 3000;
            minRange = 1600;
            minRangeProbab = 0.2;
            midRange = 2200;
            midRangeProbab = 0.3;
            maxRange = 8500;
            maxRangeProbab = 0.0008;
        };
    };
    class mas_2A14: CannonCore {
        scope = 1;
        displayName = "2A14";
        nameSound = "cannon";
        cartridgePos = "cartridge_pos";
        cartridgeVel = "cartridge_dir";
        cursor = "emptyCursor";
        cursorAim = "mg";
        cursorAimOn = "";
        cursorSize = 1;
        canLock = 2;
        class gunParticles {
            class effect1 {
                positionName = "cartridge_pos";
                directionName = "cartridge_dir";
                effectName = "MachineGunCartridge1";
            };
        };
        magazines[] = { "mas_40Rnd_23mm_AZP85", "mas_2000Rnd_23mm_AZP85" };
        magazineReloadTime = 9;
        modes[] = { "manual", "close", "short", "medium", "far" };
        class manual: CannonCore {
            displayName = "2A14";
            autoFire = 1;
            sounds[] = { "StandardSound" };
            class StandardSound {
                weaponSoundEffect = "DefaultRifle";
                begin1[] = { "\mas_vehicle\zu23\Data\Sound\2a14_1shot", 1, 1, 1400 };
                soundBegin[] = { "begin1", 1 };
            };
            reloadTime = 0.059999999;
            dispersion = 0.005;
            multiplier = 2;
            soundContinuous = 0;
            showToPlayer = 1;
            burst = 1;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 1;
            minRangeProbab = 0.008;
            midRange = 2;
            midRangeProbab = 0.008;
            maxRange = 3;
            maxRangeProbab = 0.008;
        };
        class close: manual {
            showToPlayer = 0;
            soundBurst = 0;
            burst = 15;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 0;
            minRangeProbab = 0.04;
            midRange = 300;
            midRangeProbab = 0.5;
            maxRange = 600;
            maxRangeProbab = 0.2;
        };
        class short: close {
            burst = 10;
            aiRateOfFire = 2;
            aiRateOfFireDistance = 300;
            minRange = 400;
            minRangeProbab = 0.2;
            midRange = 600;
            midRangeProbab = 0.4;
            maxRange = 900;
            maxRangeProbab = 0.2;
        };
        class medium: close {
            burst = 7;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 600;
            minRange = 700;
            minRangeProbab = 0.2;
            midRange = 900;
            midRangeProbab = 0.4;
            maxRange = 1200;
            maxRangeProbab = 0.2;
        };
        class far: close {
            burst = 4;
            aiRateOfFire = 5;
            aiRateOfFireDistance = 1000;
            minRange = 1000;
            minRangeProbab = 0.2;
            midRange = 1200;
            midRangeProbab = 0.3;
            maxRange = 1500;
            maxRangeProbab = 0.008;
        };
    };

    class LRR_base_F;
    class srifle_LRR_F: LRR_base_F {
        class WeaponSlotsInfo;
    };
    class arifle_mas_lee: srifle_LRR_F {
        author = "UKSF";
        displayname = "Lee-Enfield No4";
        model = "\mas_us_rifle\mas_LeeEnfield";
        reloadAction = "GestureReloadLRR";
        handanim[] = { "OFP2_ManSkeleton","\mas_us_rifle\Anim\LeeEnfield.rtm" };
        magazines[] = { "5Rnd_mas_762x51_Stanag","5Rnd_mas_762x51_T_Stanag" };
        picture = "\mas_us_rifle\ui\gear_lee_x_ca.paa";
        descriptionshort = "Rifle<br />Caliber: 7.62x51 mm";
        maxZeroing = 1200;
        hasBipod = 0;
        class Library {
            libtextdesc = "The Lee Enfield bolt action, magazine fed, repeating rifle was the main firearm used by the military forces of the British Empire and Commonwealth during the first half of the 20th century. It was the British Armys standard rifle from its official adoption in 1895 until 1957. It remained in widespread British service until the early mid 1960s and the 7,62 mm L42 sniper variant remained in service until the 1990s. As a standard issue infantry rifle, it is still found in service in the armed forces of some Commonwealth nations. During the 1960s, the British Government and the Ministry of Defence converted a number of Lee Enfield No4 rifles to 7,62�51mm NATO as part of a programme to retain the Lee Enfield as a reserve weapon.";
        };
        modes[] = { "Single" };
        drySound[] = { "JSRSAPEX_P_Weaponsounds\dry\emr_dry", 0.56234097, 1, 50 };
        reloadMagazineSound[] = { "JSRSAPEX_P_Weaponsounds\Reload\emr_reload", 0.96234101, 1, 100 };
        changeFiremodeSound[] = { "JSRSAPEX_P_Weaponsounds\Noises\emr_FireMode", 0.56234097, 1, 50 };
        class Single: Mode_SemiAuto {
            dispersion = 0.00018;
            soundContinuous = 0;
            reloadTime = 1.2;
            recoil = "recoil_single_gm6";
            recoilProne = "recoil_single_prone_gm6";
            sounds[] = { "StandardSound","SilencedSound" };
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundSetShot[] = { "JPEX_EMR_Shot_SoundSet", "JPEX_EMR_Tail_SoundSet", "JPEX_FRAME_RIFLE_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_762MM" };
            };
            class SilencedSound: BaseSoundModeType {
                soundSetShot[] = { "JPEX_EMR_Shot_Silenced_SoundSet", "JPEX_EMR_Tail_Silenced_SoundSet", "JPEX_FRAME_NOISE_LAYER_762MM" };
            };
            minRange = 2;
            minRangeProbab = 0.1;
            midRange = 250;
            midRangeProbab = 0.69999999;
            maxRange = 350;
            maxRangeProbab = 0.050000001;
            aiRateOfFire = 3;
            aiRateOfFireDistance = 500;
        };
        class WeaponSlotsInfo: WeaponSlotsInfo {
            class MuzzleSlot: MuzzleSlot {
                linkProxy = "\A3\data_f\proxies\weapon_slots\MUZZLE";
                iconPicture = "\mas_us_rifle\ui\attachment_muzzle.paa";
                iconPosition[] = { 0,0.40000001 };
                iconPinpoint = "Center";
                compatibleItems[] = { "muzzle_snds_B" };
                iconScale = 0.2;
            };
            class CowsSlot: CowsSlot {
                linkProxy = "\A3\data_f\proxies\weapon_slots\TOP";
                iconPicture = "\mas_us_rifle\ui\attachment_top.paa";
                iconPosition[] = { 0.5,0.40000001 };
                iconPinpoint = "Bottom";
                compatibleitems[] = {
                    "optic_Arco",
                    "optic_aco",
                    "optic_ACO_grn",
                    "optic_hamr",
                    "optic_Holosight",
                    "optic_SOS",
                    "optic_MRCO",
                    "optic_Aco_smg",
                    "optic_Holosight_smg",
                    "optic_NVS",
                    "optic_Nightstalker",
                    "optic_tws",
                    "optic_DMS",
                    "optic_LRPS",
                    "optic_AMS_khk",
                    "optic_AMS_snd",
                    "optic_AMS",
                    "optic_KHS_blk",
                    "optic_KHS_hex",
                    "optic_KHS_old",
                    "optic_KHS_tan",
                    "UK3CB_BAF_SpecterLDS",
                    "UK3CB_BAF_SpecterLDS_3D",
                    "UK3CB_BAF_SpecterLDS_Dot",
                    "UK3CB_BAF_SpecterLDS_Dot_3D",
                    "UK3CB_BAF_Eotech",
                    "UK3CB_BAF_SUSAT",
                    "UK3CB_BAF_SUSAT_3D",
                    "UK3CB_BAF_TA31F",
                    "UK3CB_BAF_TA31F_3D",
                    "UK3CB_BAF_TA31F_Hornbill",
                    "UK3CB_BAF_TA31F_Hornbill_3D",
                    "UK3CB_BAF_TA648",
                    "UK3CB_BAF_TA648_308"
                };
                iconScale = 0.2;
            };
            class PointerSlot: PointerSlot {
                linkProxy = "\A3\data_f\proxies\weapon_slots\SIDE";
                iconPicture = "\mas_us_rifle\ui\attachment_side.paa";
                iconPinpoint = "Center";
                iconPosition[] = { 0.2,0.40000001 };
                compatibleitems[] = { "acc_flashlight","acc_pointer_IR" };
                iconScale = 0.2;
            };
            class UnderBarrelSlot: UnderBarrelSlot {
                linkProxy = "\A3\Data_f_Mark\proxies\weapon_slots\UNDERBARREL";
                iconPicture = "\mas_us_rifle\ui\attachment_bipod.paa";
                iconPinpoint = "Center";
                iconPosition[] = { 0.2,0.80000001 };
                compatibleitems[] = { "bipod_01_F_snd","bipod_01_F_blk","bipod_01_F_mtp","bipod_02_F_blk","bipod_02_F_tan","bipod_02_F_hex","bipod_03_F_blk","bipod_03_F_oli" };
                iconScale = 0.2;
            };
            mass = 80;
        };
    };
    class arifle_mas_fal: arifle_mas_lee {
        author = "UKSF";
        _generalMacro = "arifle_mas_fal";
        displayname = "FN FAL";
        model = "\mas_us_rifle\mas_fnfal";
        reloadAction = "GestureReloadSMG_02";
        handanim[] = { "OFP2_ManSkeleton","\mas_us_rifle\Anim\Handanim_fal.rtm" };
        magazines[] = { "20Rnd_762x51_Mag" };
        picture = "\mas_us_rifle\ui\gear_fal_x_ca.paa";
        descriptionshort = "Assault Rifle<br />Caliber: 7.62x51 mm";
        class Library {
            libtextdesc = "The Fusil Automatique Leger or FAL is a self loading, selective fire battle rifle produced by the Belgian armaments manufacturer Fabrique Nationale de Herstal. During the Cold War it was adopted by many North Atlantic Treaty Organization NATO countries, with the notable exception of the United States. It is one of the most widely used rifles in history, having been used by more than 90 countries. The FAL was predominantly chambered for the 7.62�51mm NATO round, and because of its prevalence and widespread use among the armed forces of many NATO countries during the Cold War it was nicknamed The right arm of the Free World. A British Commonwealth derivative of the FN FAL has been produced under licence as the L1A1 Self Loading Rifle.";
        };
        recoil = "recoil_dmr_05";
        modes[] = {
            "Single",
            "FullAuto"
        };
        class Single: Mode_SemiAuto {
            sounds[] = { "StandardSound","SilencedSound" };
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundSetShot[] = { "JPEX_EMR_Shot_SoundSet", "JPEX_EMR_Tail_SoundSet", "JPEX_FRAME_RIFLE_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_762MM" };
            };
            class SilencedSound: BaseSoundModeType {
                soundSetShot[] = { "JPEX_EMR_Shot_Silenced_SoundSet", "JPEX_EMR_Tail_Silenced_SoundSet", "JPEX_FRAME_NOISE_LAYER_762MM" };
            };
            reloadTime = 0.075000003;
            dispersion = 0.00116;
            recoil = "recoil_single_ebr";
            recoilProne = "recoil_single_prone_ebr";
            minRange = 2;
            minRangeProbab = 0.5;
            midRange = 200;
            midRangeProbab = 0.69999999;
            maxRange = 400;
            maxRangeProbab = 0.30000001;
        };
        class FullAuto: Mode_FullAuto {
            sounds[] = { "StandardSound","SilencedSound" };
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundSetShot[] = { "JPEX_EMR_Shot_SoundSet", "JPEX_EMR_Tail_SoundSet", "JPEX_FRAME_RIFLE_REFLECTORS", "JPEX_FRAME_NOISE_LAYER_762MM" };
            };
            class SilencedSound: BaseSoundModeType {
                soundSetShot[] = { "JPEX_EMR_Shot_Silenced_SoundSet", "JPEX_EMR_Tail_Silenced_SoundSet", "JPEX_FRAME_NOISE_LAYER_762MM" };
            };
            reloadTime = 0.085000001;
            dispersion = 0.00116;
            recoil = "recoil_auto_ebr";
            recoilProne = "recoil_auto_prone_ebr";
            minRange = 0;
            minRangeProbab = 0.89999998;
            midRange = 15;
            midRangeProbab = 0.69999999;
            maxRange = 30;
            maxRangeProbab = 0.1;
            aiRateOfFire = 1e-006;
        };
        class WeaponSlotsInfo: WeaponSlotsInfo {
            class MuzzleSlot: MuzzleSlot {
                linkProxy = "\A3\data_f\proxies\weapon_slots\MUZZLE";
                iconPicture = "\mas_us_rifle\ui\attachment_muzzle.paa";
                iconPosition[] = { 0,0.40000001 };
                iconPinpoint = "Center";
                compatibleItems[] = { "muzzle_snds_H" };
                iconScale = 0.2;
            };
            class CowsSlot: CowsSlot {
                linkProxy = "\A3\data_f\proxies\weapon_slots\TOP";
                iconPicture = "\mas_us_rifle\ui\attachment_top2.paa";
                iconPosition[] = { 0.5,0.30000001 };
                iconPinpoint = "Bottom";
                compatibleitems[] = {
                    "optic_Arco",
                    "optic_aco",
                    "optic_ACO_grn",
                    "optic_hamr",
                    "optic_Holosight",
                    "optic_SOS",
                    "optic_MRCO",
                    "optic_Aco_smg",
                    "optic_Holosight_smg",
                    "optic_NVS",
                    "optic_Nightstalker",
                    "optic_tws",
                    "optic_DMS",
                    "optic_LRPS",
                    "optic_AMS_khk",
                    "optic_AMS_snd",
                    "optic_AMS",
                    "optic_KHS_blk",
                    "optic_KHS_hex",
                    "optic_KHS_old",
                    "optic_KHS_tan",
                    "UK3CB_BAF_SpecterLDS",
                    "UK3CB_BAF_SpecterLDS_3D",
                    "UK3CB_BAF_SpecterLDS_Dot",
                    "UK3CB_BAF_SpecterLDS_Dot_3D",
                    "UK3CB_BAF_Eotech",
                    "UK3CB_BAF_SUSAT",
                    "UK3CB_BAF_SUSAT_3D",
                    "UK3CB_BAF_TA31F",
                    "UK3CB_BAF_TA31F_3D",
                    "UK3CB_BAF_TA31F_Hornbill",
                    "UK3CB_BAF_TA31F_Hornbill_3D",
                    "UK3CB_BAF_TA648",
                    "UK3CB_BAF_TA648_308"
                };
                iconScale = 0.2;
            };
            class PointerSlot: PointerSlot {
                linkProxy = "\A3\data_f\proxies\weapon_slots\SIDE";
                iconPicture = "\mas_us_rifle\ui\attachment_side.paa";
                iconPinpoint = "Center";
                iconPosition[] = { 0.2,0.40000001 };
                compatibleitems[] = { "acc_flashlight","acc_pointer_IR" };
                iconScale = 0.2;
            };
            class UnderBarrelSlot: UnderBarrelSlot {
                linkProxy = "\A3\Data_f_Mark\proxies\weapon_slots\UNDERBARREL";
                iconPicture = "\mas_us_rifle\ui\attachment_bipod.paa";
                iconPinpoint = "Center";
                iconPosition[] = { 0.2,0.80000001 };
                compatibleitems[] = { "bipod_01_F_snd","bipod_01_F_blk","bipod_01_F_mtp","bipod_02_F_blk","bipod_02_F_tan","bipod_02_F_hex","bipod_03_F_blk","bipod_03_F_oli" };
                iconScale = 0.2;
            };
            mass = 80;
        };
    };    

    class rhs_weap_ak74m_camo_npz;
    class rhs_weap_ak74m_camo_npz_acog: rhs_weap_ak74m_camo_npz {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "UK3CB_BAF_TA31F_3D";
            };
        };
    };
    class rhs_weap_ak74m_gp25_npz;
    class rhs_weap_ak74m_gp25_npz_acog: rhs_weap_ak74m_gp25_npz {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "UK3CB_BAF_TA31F_3D";
            };
        };
    };
    class arifle_mas_m4;
    class arifle_mas_m4_acog: arifle_mas_m4 {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "UK3CB_BAF_TA31F_3D";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "acc_flashlight";
            };
        };
    };
    class arifle_mas_m4c;
    class arifle_mas_m4c_holo: arifle_mas_m4c {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_Holosight";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "acc_flashlight";
            };
            class LinkedItemsMuzzle {
                slot = "MuzzleSlot";
                item = "muzzle_snds_M";
            };
        };
    };
    class rhs_weap_ak105_npz;
    class rhs_weap_ak105_npz_acog: rhs_weap_ak105_npz {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "UK3CB_BAF_TA31F_3D";
            };
        };
    };
    class arifle_mas_m4_gl;
    class arifle_mas_m4_gl_acog: arifle_mas_m4_gl {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "UK3CB_BAF_TA31F_3D";
            };
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "acc_flashlight";
            };
        };
    };
    class rhs_weap_ak103;
    class rhs_weap_ak103_pso: rhs_weap_ak103 {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "rhs_acc_pso1m21";
            };
        };
    };
    class srifle_DMR_06_camo_F;
    class srifle_DMR_06_camo_F_dms : srifle_DMR_06_camo_F {
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_DMS";
            };
        };
    };
    class launch_O_Titan_F;
    class rhs_weap_strela: launch_O_Titan_F {
        scope = 0;
    };
    class Launcher_Base_F;
    class rhs_weap_rpg7: Launcher_Base_F {
        minRange = 10;
        midRange = 400;
        maxRange = 900;
    };
};