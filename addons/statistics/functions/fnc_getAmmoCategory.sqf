#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Classifies an ammo class into one of three categories for stats bucketing:
        "ballistic", "explosive", or "other". Results are cached per ammo class in
        GVAR(ammoCategoryCache) to avoid repeated config reads on the hot path.

        Classification rules, evaluated in order:
        1. Simulation whitelist — known "other" sims (smoke, illum, CM, laser, deploy, NVG marker)
        2. Simulation whitelist — known "ballistic" sims (shotBullet, shotSpread)
        3. Simulation whitelist — known "explosive" sims (shell, missile, rocket, grenade,
           submunitions, mines, bombs)
        4. Fallback — if simulation is unrecognised (e.g. modded ammo), check explosive /
           indirectHit / indirectHitRange fields on the config; nonzero → "explosive",
           else "other".

    Parameters:
        0: Ammo classname <STRING>

    Return Value:
        Category <STRING> — one of "ballistic", "explosive", "other"

    Example:
        ["B_556x45_Ball"] call uksf_statistics_fnc_getAmmoCategory
*/
params [["_ammo", "", [""]]];

if (_ammo isEqualTo "") exitWith {"other"};

private _cached = GVAR(ammoCategoryCache) get _ammo;
if (!isNil "_cached") exitWith {_cached};

private _cfg = configFile >> "CfgAmmo" >> _ammo;
private _simulation = getText (_cfg >> "simulation");

private _category = call {
    if (_simulation in ["shotSmoke", "shotSmokeX", "shotIlluminating", "shotCM", "shotLaser", "shotDeploy", "shotNVGMarker"]) exitWith {"other"};
    if (_simulation in ["shotBullet", "shotSpread"]) exitWith {"ballistic"};
    if (_simulation in ["shotShell", "shotMissile", "shotRocket", "shotGrenade", "shotSubmunitions", "shotMine", "shotBoundingMine", "shotDirectionalBomb", "shotTimeBomb"]) exitWith {"explosive"};

    // Fallback for unrecognised simulations (modded ammo etc.)
    if (getNumber (_cfg >> "explosive") > 0) exitWith {"explosive"};
    if (getNumber (_cfg >> "indirectHit") > 0) exitWith {"explosive"};
    if (getNumber (_cfg >> "indirectHitRange") > 0) exitWith {"explosive"};

    "other"
};

GVAR(ammoCategoryCache) set [_ammo, _category];
_category
