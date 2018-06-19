class CfgAmmo {
    class SmokeShell;
    class GVAR(markerAmmo): SmokeShell {
        model = "\A3\Weapons_F_EPB\Ammo\B_IRstrobe_F.p3d";
        dangerRadiusHit = -1;
        suppressionRadiusHit = -1;
        typicalSpeed = 22;
        cost = 1000000;
        deflecting = 1;
        explosionTime = 0;
        timeToLive = 36000;
        grenadeFireSound[] = {};
        grenadeBurningSound[] = {};
        aiAmmoUsageFlags = "";
        effectsSmoke = "";
        whistleDist = 0;
    };
};
