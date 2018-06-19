class CfgWeapons {
    class GrenadeLauncher;
    class Throw: GrenadeLauncher {
        muzzles[] += {QGVAR(markerMuzzle)};

        class ThrowMuzzle;
        class GVAR(markerMuzzle): ThrowMuzzle {
            magazines[] = {QGVAR(marker)};
        };
    };
};
