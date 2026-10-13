if (isServer) exitWith {
    ["lc_killTargets", {
        params ["_killer"];
        {
            if (alive _x) then {[_x, [1, true, _killer, _killer]] remoteExec ["setDamage", _x]};
        } forEach (lc_statsTargets select [0, 2]);
        [{["killed", str ((lc_statsTargets select [0, 2]) apply {alive _x})] call lc_fnc_log}, [], 2] call CBA_fnc_waitAndExecute;
    }] call CBA_fnc_addEventHandler;

    [{!isNil "lc_hcOwner" && {(allPlayers select {!(_x isKindOf "HeadlessClient_F")}) isNotEqualTo []}}, {
        private _player = (allPlayers select {!(_x isKindOf "HeadlessClient_F")})#0;
        private _base = getPosATL _player;
        private _fnc_ai = {
            params ["_type", "_offset"];
            private _group = createGroup [east, true];
            _group setVariable ["acex_headless_blacklist", true, true];
            private _unit = _group createUnit [_type, _base vectorAdd _offset, [], 0, "CAN_COLLIDE"];
            removeAllWeapons _unit;
            _unit disableAI "ALL";
            _unit
        };
        private _ai1 = ["O_Soldier_F", [0, 15, 0]] call _fnc_ai;
        private _ai2 = ["O_Soldier_AR_F", [6, 15, 0]] call _fnc_ai;
        (group _ai2) setGroupOwner lc_hcOwner;
        private _tank = createVehicle ["B_MBT_01_cannon_F", _base vectorAdd [-25, 40, 0], [], 0, "CAN_COLLIDE"];
        _tank setVariable ["ace_cookoff_enable", false, true];
        private _car = createVehicle ["B_MRAP_01_F", _base vectorAdd [-10, 0, 0], [], 0, "NONE"];
        lc_statsTargets = [_ai1, _ai2, _tank, _car];
        publicVariable "lc_statsTargets";
        [{
            params ["_ai1", "_ai2"];
            ["aiOwners", format ["%1 %2 hc=%3", owner _ai1, owner _ai2, lc_hcOwner]] call lc_fnc_log;
            lc_statsGo = true;
            publicVariable "lc_statsGo";
        }, [_ai1, _ai2], 5] call CBA_fnc_waitAndExecute;
    }] call CBA_fnc_waitUntilAndExecute;
};

if (!hasInterface) exitWith {};

[{!isNil "lc_statsGo" && {alive player}}, {
    lc_statsAim = objNull;
    lc_statsShots = 0;
    player addEventHandler ["Fired", {
        params ["", "", "", "", "", "", "_projectile"];
        lc_statsShots = lc_statsShots + 1;
        if (isNull lc_statsAim) exitWith {};
        private _target = lc_statsAim;
        private _infantry = _target isKindOf "CAManBase";
        private _aim = if (_infantry) then {_target modelToWorldVisualWorld (_target selectionPosition "spine3")} else {(getPosASL _target) vectorAdd [0, 0, 1.5]};
        private _dir = vectorNormalized (_aim vectorDiff ((getPosASL player) vectorAdd [0, 0, 1.5]));
        _projectile setPosASL (_aim vectorDiff (_dir vectorMultiply ([25, 3] select _infantry)));
        _projectile setVectorDir _dir;
        _projectile setVelocity (_dir vectorMultiply ((vectorMagnitude velocity _projectile) max 150));
    }];
    [] spawn {
        lc_statsTargets params ["_ai1", "_ai2", "_tank", "_car"];
        private _fnc_fire = {
            params ["_target", "_weapon"];
            lc_statsAim = _target;
            if (currentWeapon player != _weapon) then {
                player selectWeapon _weapon;
                sleep 4;
            };
            private _mode = (getArray (configFile >> "CfgWeapons" >> _weapon >> "modes"))#0;
            player forceWeaponFire [_weapon, [_mode, _weapon] select (_mode == "this")];
            sleep 2;
            lc_statsAim = objNull;
        };
        private _rifle = primaryWeapon player;
        player addWeapon "launch_RPG32_F";
        player addSecondaryWeaponItem "RPG32_F";
        player selectWeapon _rifle;
        sleep 3;
        [_ai1, _rifle] call _fnc_fire;
        [_ai2, _rifle] call _fnc_fire;
        [_tank, "launch_RPG32_F"] call _fnc_fire;
        player selectWeapon _rifle;
        sleep 4;
        ["lc_note", ["fired", str ((lc_statsTargets select [0, 2]) apply {alive _x})]] call CBA_fnc_serverEvent;
        ["lc_killTargets", [player]] call CBA_fnc_serverEvent;
        sleep 3;

        private _position = (getPosATL player) vectorAdd [3, 0, 0];
        [player, _position, 0, "DemoCharge_Remote_Mag", "Command", []] call ace_explosives_fnc_placeExplosive;
        private _defused = [player, _position vectorAdd [2, 0, 0], 0, "DemoCharge_Remote_Mag", "Command", []] call ace_explosives_fnc_placeExplosive;
        sleep 1;
        [player, _defused] call ace_explosives_fnc_defuseExplosive;

        [player, 0.2, "leftarm", "bullet"] call ace_medical_fnc_addDamageToUnit;
        sleep 2;
        [player, true, 5, true] call ace_medical_fnc_setUnconscious;
        sleep 3;
        ["ace_medical_FatalVitals", player] call CBA_fnc_localEvent;
        sleep 3;
        [player, ace_medical_STATE_MACHINE, "CardiacArrest", "Comatose", {}, "lc"] call CBA_statemachine_fnc_manualTransition;
        sleep 3;
        ["ace_medical_Revive", player] call CBA_fnc_localEvent;
        sleep 2;
        [player] call ace_medical_treatment_fnc_fullHealLocal;
        sleep 5;
        ["lc_note", ["medical", str [lifeState player, alive player]]] call CBA_fnc_serverEvent;

        for "_i" from 1 to 3 do {
            player setPosATL ((getPosATL player) vectorAdd [30, 0, 0]);
            sleep 11;
        };
        player moveInDriver _car;
        sleep 2;
        for "_i" from 1 to 3 do {
            _car setPosATL ((getPosATL _car) vectorAdd [0, 150, 0]);
            _car setFuel ((fuel _car) - 0.1);
            sleep 11;
        };
        moveOut player;
        sleep 3;
        player forceWeaponFire [_rifle, "Single"];
        sleep 1;
        ["lc_note", ["statsDone", str [getPlayerUID player, lc_statsShots, count uksf_statistics_eventBuffer]]] call CBA_fnc_serverEvent;
    };
}] call CBA_fnc_waitUntilAndExecute;
