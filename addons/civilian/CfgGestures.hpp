class CfgMovesBasic {
    class ManActions {
        GVAR(clearAction) = QGVAR(clearAction);
        GVAR(hvtdefault) = QGVAR(hvtdefault);
        GVAR(holdhvt) = QGVAR(holdhvt);
        GVAR(holdhvtpistol) = QGVAR(holdhvtpistol);
    };
    class Actions {
        class NoActions : ManActions {
            GVAR(clearAction)[] = { QGVAR(clearAction),"gesture" };
            GVAR(hvtdefault)[] = { QGVAR(hvtdefault),"gesture" };
            GVAR(holdhvt)[] = { QGVAR(holdhvt),"gesture" };
            GVAR(holdhvtpistol)[] = { QGVAR(holdhvtpistol),"gesture" };
        };
    };
};
class CfgGesturesMale {
    class Default;
    class States {
        class GVAR(clearAction) : Default {
            file = "";
            looped = 0;
            speed = 9.9;
            mask = "handsWeapon";
            canPullTrigger = 1;
            headBobMode = 2;
            canReload = 0;
            terminal = 0;
            preload = 1;
            disableWeapons = 0;
            disableWeaponsLong = 0;
            enableBinocular = 0;
            enableMissile = 0;
            onLadder = 0;
            showHandGun = 0;
            showWeaponAim = 0;
            showItemInHand = 1;
            showItemInRightHand = 0;
            headBobStrength = 0.2;
            rightHandIKCurve[] = { 1 };
            leftHandIKCurve[] = { 1 };
        };
        class GVAR(hvtdefault) : Default {
            file = QPATHTOF(anim\captives_anim_hvtdefault.rtm);
            looped = 1;
            speed = 1e-05;
            mask = "handsWeapon";
            disableWeapons = 1;
            disableWeaponsLong = 1;
            weaponLowered = 0;
            showWeaponAim = 0;
            showHandGun = 0;
            canPullTrigger = 0;
            canReload = 0;
            terminal = 0;
            limitGunMovement = 0;
            preload = 1;
            headBobMode = 1;
            headBobStrength = 0.001;
            interpolateTo[] = {};
            rightHandIKCurve[] = { 0 };
            leftHandIKCurve[] = { 0 };
        };
        class GVAR(holdhvt) : Default {
            file = QPATHTOF(anim\captives_anim_holdhvt.rtm);
            looped = 1;
            speed = 1e-05;
            mask = "handsWeapon";
            disableWeapons = 1;
            disableWeaponsLong = 1;
            weaponLowered = 0;
            showWeaponAim = 0;
            showHandGun = 0;
            canPullTrigger = 0;
            canReload = 0;
            terminal = 0;
            limitGunMovement = "true";
            turnSpeed = 0.1;
            limitFast = 2;
            preload = 1;
            headBobMode = 1;
            headBobStrength = 0.001;
            interpolateTo[] = {};
            leftHandIKCurve[] = { 0 };
        };
        class GVAR(holdhvtpistol) : Default {
            file = QPATHTOF(anim\captives_anim_holdhvtpistol.rtm);
            looped = 1;
            speed = 1e-05;
            mask = "handsWeapon";
            disableWeapons = 1;
            disableWeaponsLong = 1;
            weaponLowered = 0;
            showWeaponAim = 0;
            showHandGun = 0;
            canPullTrigger = 0;
            canReload = 0;
            terminal = 0;
            limitGunMovement = "true";
            turnSpeed = 0.1;
            limitFast = 2;
            preload = 1;
            headBobMode = 1;
            headBobStrength = 0.001;
            interpolateTo[] = {};
            leftHandIKCurve[] = { 0 };
        };
    };
};
