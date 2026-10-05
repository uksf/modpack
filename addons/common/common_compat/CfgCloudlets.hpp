// Vanilla ejected-case effects name MachineGunCartridge2Med and HeavyGunCartridge1Med, which no addon defines.
// Blastcore's "0.06 * randomGen" interval does not compile in the cartridge effects; the base rate stays.
class CfgCloudlets {
    class MachineGunCartridge;
    class MachineGunCartridge1;
    class MachineGunCartridge2;
    class MachineGunCartridge338;
    class HeavyGunCartridge1;
    class MachineGunCartridgeMed : MachineGunCartridge {
        interval = 0.06;
    };
    class MachineGunCartridge1Med : MachineGunCartridge1 {
        interval = 0.06;
    };
    class MachineGunCartridge338Med : MachineGunCartridge338 {
        interval = 0.06;
    };
    class MachineGunCartridge2Med : MachineGunCartridge2 {
        interval = 0.06;
        lifeTime = 6;
    };
    class HeavyGunCartridge1Med : HeavyGunCartridge1 {
        interval = 0.06;
        lifeTime = 6;
    };
};
