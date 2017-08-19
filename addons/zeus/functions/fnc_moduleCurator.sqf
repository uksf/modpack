 /*
    Author:
        Bohemia Interactive, edited by ACE, edited by Tim Beswick

    Description:
        Module function for initalizing zeus
        Edited to remove eagle and global ascension message
        Added "zeusUnitAssigned" event call
        Removed adding of addons

    Parameter(s):
        0: The module logic <LOGIC>
        1: Synchronized units <ARRAY>
        2: Activated <BOOL>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_logic", "_units", "_activated"];

if (_activated) then {
    
    // --- Terminate when not created on the server
    if (!isServer && {local _logic} && {isNull (getAssignedCuratorUnit _logic)}) exitwith {
        [format ["%1 is trying to create curator logic ModuleCurator_F", profilename], "bis_fnc_error", false] call bis_fnc_mp;
        deletevehicle _logic;
    };

    // --- Get curator owner
    private _ownerVar = _logic getVariable ["owner", ""];
    private _ownerUID = parseNumber _ownerVar;
    if (cheatsEnabled) then {
        private _ownerVarArray = toArray _ownerVar;
        _ownerVarArray resize 3;
        if (toString _ownerVarArray isEqualTo "DEV") then {_ownerUID = 1;};
    };
    if (_ownerVar isEqualTo "" && {!isMultiplayer}) then {
        // ["Curator owner not defined, player used instead in singleplayer."] call bis_fnc_error;
        _ownerVar = player call bis_fnc_objectvar;
    };
    if (_ownerUID > 0 && {!isMultiplayer}) then {
        _ownerVar = player call bis_fnc_objectvar;
    };
    private _isAdmin = _ownerVar isEqualTo "#adminLogged" || _ownerVar isEqualTo "#adminVoted";

    // --- Wipe out the variable so clients can't access it
    _logic setVariable ["owner", nil];

    waitUntil {!isNil QEGVAR(common,addons)};
    _logic addcuratoraddons (EGVAR(common,addons) - (curatorAddons _logic));

    // --- Server
    if (isserver) then {
        // --- Prepare admin variable
        private _adminVar = "";
        if (_isAdmin) then {
            _letters = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"];
            _adminVar = "admin_";
            for "_i" from 0 to 9 do {_adminVar = _adminVar + selectRandom _letters};
            _logic setVariable ["adminVar", _adminVar, true];
        };

        // --- Handle ownership
        [_logic, _ownerVar, _ownerUID, _adminVar] spawn {
            scriptname "BIS_fnc_moduleCurator: Owner";

            params ["_logic", "_ownerVar", "_ownerUID", "_adminVar"];

            if (_adminVar != "") then {_ownerVar = _adminVar;};

            private _forced = _logic getVariable ["forced", 0] > 0;
            private _name = _logic getVariable ["name", ""];
            if (_name isEqualTo "") then {_name = localize "STR_A3_curator";};

            // --- Wait until mission starts
            waitUntil {time > 0}; // NOTE: DO NOT CHANGE TO CBA_missionTime, IT BREAKS THE MODULE

            // --- Refresh addon list, so it's broadcasted to clients
            waitUntil {!isNil QEGVAR(common,addons)};
            _logic addcuratoraddons (EGVAR(common,addons) - (curatorAddons _logic));

            while {true} do {
                // --- Wait for player to become Zeus
                switch true do {
                    case (_ownerUID > 0): {
                        waitUntil {
                            sleep 0.01;
                            {getPlayerUID _x isEqualTo _ownerVar} count playableUnits > 0 || isNull _logic
                        };
                    };
                    default {
                        waitUntil {isPlayer (missionNamespace getVariable [_ownerVar, objnull]) || isNull _logic};
                    };
                };
                if (isNull _logic) exitwith {};

                // --- Assign
                private _player = objnull;
                switch true do {
                    case (_ownerUID > 0): {
                        {
                            if (getPlayerUID _x isEqualTo _ownerVar) exitwith {_player = _x;}; false
                        } count playableUnits;
                    };
                    default {
                        _player = missionNamespace getVariable [_ownerVar, objnull];
                    };
                };

                waitUntil {unassignCurator _logic; isNull (getAssignedCuratorUnit _logic) || isNull _logic};
                waitUntil {_player assignCurator _logic; (getAssignedCuratorUnit _logic) isEqualTo _player || isNull _logic};
                if (isNull _logic) exitwith {};

                [_logic, "curatorUnitAssigned", [_logic, _player]] call bis_fnc_callscriptedeventhandler;

                // Added by ace_zeus
                ["ace_zeus_zeusUnitAssigned", [_logic, _player]] call CBA_fnc_globalEvent;

                // --- Wait for player to stop being Zeus
                switch true do {
                    case (_ownerUID > 0): {
                        waitUntil {
                            sleep 0.01;
                            {getPlayerUID _x isEqualTo _ownerVar} count playableUnits isEqualTo 0 || isNull _logic
                        };
                    };
                    default {
                        waitUntil {_player != missionNamespace getVariable [_ownerVar, objnull] || isNull _logic};
                    };
                };
                if (isNull _logic) exitwith {};

                // --- Unassign
                waitUntil {unassignCurator _logic; isNull (getAssignedCuratorUnit _logic) || isNull _logic};
                if (isNull _logic) exitwith {};
            };
        };
    };

    // --- Player
    if (hasinterface) then {
        waitUntil {local player};
        private _serverCommand = if (_ownerVar isEqualTo "#adminLogged") then {"#shutdown"} else {"#kick"};

        // --- Black effect until the interface is open
        private _forced = _logic getVariable ["forced", 0] > 0;
        if (_forced) then {
            private _isCurator = switch true do {
                case (_ownerUID > 0): {
                    getPlayerUID player isEqualTo _ownerVar
                };
                case (_isAdmin): {
                    isserver || serverCommandAvailable _serverCommand
                };
                default {
                    player isEqualTo missionNamespace getVariable [_ownerVar, objnull]
                };
            };
            if (_isCurator) then {
                [true, true] spawn bis_fnc_forceCuratorInterface;
                ("RscDisplayCurator" call bis_fnc_rscLayer) cuttext ["", "black in", 1e10];
            };
        };
        // --- Check if player is server admin
        if (_isAdmin) then {
            private _adminVar = _logic getVariable ["adminVar", ""];
            _logic setVariable ["adminVar", nil];
            if (isserver) then {
                // --- Host
                missionNamespace setVariable [_adminVar, player];
            } else {
                // --- Client
                [_logic, _adminVar, _serverCommand] spawn {
                    scriptname "BIS_fnc_moduleCurator: Admin check";

                    params ["_logic", "_adminVar", "_serverCommand"];
                    while {true} do {
                        waitUntil {sleep 0.1; serverCommandAvailable _serverCommand};
                        missionNamespace setVariable [_adminVar, player];
                        publicVariable _adminVar;
                        private _respawn = player addEventHandler ["respawn", format ["%1 = _this select 0; publicVariable '%1';", _adminVar]];

                        waitUntil {sleep 0.1; !serverCommandAvailable _serverCommand};
                        missionNamespace setVariable [_adminVar, objnull];
                        publicVariable _adminVar;
                        player removeEventHandler ["respawn", _respawn];
                    };
                };
            };
        };

        [_logic] spawn {
            private _logic = (_this select 0);
            waitUntil {alive player};

            // --- Show warning when Zeus key is not assigned
            if (count (actionkeys "curatorInterface") isEqualTo 0) then {
                [
                    format [
                        localize "str_a3_cfgvehicles_modulecurator_f_keyNotAssigned", 
                        (["IGUI", "WARNING_RGB"] call bis_fnc_displaycolorget) call bis_fnc_colorRGBAtoHTML
                    ]
                ] call bis_fnc_guiMessage;
            };
        };


        _logic addEventHandler ["CuratorObjectPlaced", {_this call bis_fnc_curatorObjectPlaced}];
        _logic addEventHandler ["CuratorObjectPlaced", {_this call Achilles_fnc_HandleCuratorObjectPlaced}];
        _logic addEventHandler ["curatorObjectEdited", {_this call bis_fnc_curatorObjectEdited}];
        _logic addEventHandler ["CuratorObjectEdited", {_this call Achilles_fnc_HandleCuratorObjectEdited}];
        _logic addEventHandler ["CuratorGroupPlaced", {_this call Achilles_fnc_HandleCuratorGroupPlaced}];
        _logic addEventHandler ["curatorWaypointPlaced", {_this call bis_fnc_curatorWaypointPlaced}];
        _logic addEventHandler ["curatorFeedbackMessage", {_this call bis_fnc_showCuratorFeedbackMessage}];
        _logic addEventHandler ["curatorObjectDoubleClicked", {(_this select 1) call bis_fnc_showCuratorAttributes}];
        _logic addEventHandler ["CuratorObjectDoubleClicked", {_this call Achilles_fnc_HandleCuratorObjectDoubleClicked}];
        _logic addEventHandler ["curatorGroupDoubleClicked", {(_this select 1) call bis_fnc_showCuratorAttributes}];
        _logic addEventHandler ["curatorWaypointDoubleClicked", {(_this select 1) call bis_fnc_showCuratorAttributes}];
        _logic addEventHandler ["curatorMarkerDoubleClicked", {(_this select 1) call bis_fnc_showCuratorAttributes}];
            
        _logic setVariable ["BIS_fnc_curatorAttributesplayer", ["%ALL"]];
        _logic setVariable ["BIS_fnc_curatorAttributesobject", ["%ALL"]];
        _logic setVariable ["BIS_fnc_curatorAttributesgroup", ["%ALL"]];
        _logic setVariable ["BIS_fnc_curatorAttributeswaypoint", ["%ALL"]];
        _logic setVariable ["BIS_fnc_curatorAttributesmarker", ["%ALL"]];

        [] call Achilles_fnc_setCuratorVisionModes;

        player call bis_fnc_curatorRespawn;
    };
};
