class CfgWeapons {
    class CannonCore;
    class USAF_F35A_CANNON_W: CannonCore {
        class manual: CannonCore {
            reloadTime = 0.1;
            class StandardSound {
                soundSetShot[] = { "DS_20mmgatling_Shot_SoundSet","DS_sniper1_tail_soundset" };
            };
            soundContinuous = 0;
        };
    };
};
