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
};