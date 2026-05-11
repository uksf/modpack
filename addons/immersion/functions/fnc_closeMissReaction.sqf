#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Apply the close-miss reaction on the local player. Severity uses an
        inverse-square decay over engagement age:
            severity = 1 / (1 + K * age^2)

        Engagement age accumulates with each in-engagement close miss, fully
        resets after CLOSEMISS_RECOVERY_SECONDS of silence. If the player has
        fired their own weapon within CLOSEMISS_PLAYER_FIRING_WINDOW seconds
        before a fresh engagement starts, the engagement is "pre-aged" by
        CLOSEMISS_PRE_AGE_SEC seconds — modelling the soldier already being
        focused in and ready, so first rounds get reduced effect.

        The harness keybind passes a severity override so test presses
        always feel full strength.

    Parameters:
        0: Bullet pass side <SCALAR> (1 = passed on player's right, -1 = left)
        1: Severity override <SCALAR> (-1 = derive from age, 0..1 = use given)

    Return value:
        None

    Example:
        [1] call uksf_immersion_fnc_closeMissReaction
*/
params [["_bulletSide", 1, [0]], ["_severityOverride", -1, [0]]];

if (isNull ACE_player || {!alive ACE_player}) exitWith {};
if ((vehicle ACE_player) isKindOf "Air") exitWith {};

private _ageBefore = GVAR(closeMiss_engagementAge);
private _silenceSec = (diag_tickTime - GVAR(closeMiss_lastTriggerAt)) max 0;
private _firedAgo = (diag_tickTime - GVAR(closeMiss_lastFiredAt)) max 0;

private _severity = if (_severityOverride >= 0) then {
    _severityOverride
} else {
    if (_silenceSec >= CLOSEMISS_RECOVERY_SECONDS) then {
        // Long silence — fresh engagement. Pre-age if player has been firing
        // recently (already focused on the engagement).
        GVAR(closeMiss_engagementAge) = if (_firedAgo < CLOSEMISS_PLAYER_FIRING_WINDOW) then {
            CLOSEMISS_PRE_AGE_SEC
        } else {
            0
        };
    } else {
        // Continued engagement — silence ages the engagement (no recovery
        // until a full RECOVERY_SECONDS gap).
        GVAR(closeMiss_engagementAge) = GVAR(closeMiss_engagementAge) + _silenceSec;
    };
    GVAR(closeMiss_lastTriggerAt) = diag_tickTime;

    private _age = GVAR(closeMiss_engagementAge);
    1 / (1 + CLOSEMISS_DECAY_K * _age * _age)
};

private _ageAfter = GVAR(closeMiss_engagementAge);

if (_severity <= 0) exitWith {
    TRACE_3("closeMiss react SKIP",_silenceSec,_ageBefore,_ageAfter);
};

private _flinchMagnitude = _severity * (CLOSEMISS_FLINCH_MIN_DEG + random CLOSEMISS_FLINCH_RAND_DEG);
private _flinch = _flinchMagnitude * (-_bulletSide);
ACE_player setDir ((getDir ACE_player) + _flinch);

addCamShake [_severity * CLOSEMISS_SHAKE_FORCE, CLOSEMISS_SHAKE_LENGTH, CLOSEMISS_SHAKE_FREQ];

TRACE_7("closeMiss react",_bulletSide,_silenceSec,_firedAgo,_ageBefore,_ageAfter,_severity,_flinch);
