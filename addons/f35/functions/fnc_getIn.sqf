/*
    Author:
        Tim Beswick, USAF Team

    Description:
        Run on get in

    Parameters:
        0: Plane <OBJECT>

    Return value:
        Nothing
*/
#include "script_component.hpp"

params ["_plane"];

if (!local _plane) exitWith {};

GVAR(stealthHandler) = [{
    params ["_args", "_idPFH"];
    _args params ["_plane"];

    if (!alive _plane) exitWith {
        [_idPFH] call cba_fnc_removePerFrameHandler;
    };

    if (local _plane) then {
        if ((currentWeapon _plane) isEqualTo "USAF_F35A_Master_Arm_Switch") then {
            _plane setcaptive true;
        } else {
            _plane setcaptive false;
        };
    };
}, 1, [_plane]] call cba_fnc_addPerFrameHandler;

GVAR(animationHandler) = [{
    params ["_args", "_idPFH"];
    _args params ["_plane"];

    if (!alive _plane) exitWith {
        [_idPFH] call cba_fnc_removePerFrameHandler;
    };

    if (local _plane) then {
        _internalAmraamCount = _plane ammo "USAF_AIM120I_Launcher";
        _internalGbuCount = _plane ammo "USAF_GBU31_Launcher";
        _internalGbu2Count = _plane ammo "USAF_GBU32_Launcher";
        _internalGbu3Count = _plane ammo "USAF_GBU38_Launcher";
        _internalGbu4Count = _plane ammo "USAF_AGM154A1_Launcher";
        _internalGbu5Count = _plane ammo "USAF_GBU24_Launcher";
        _internalSdbCount = _plane ammo "USAF_F35A_GBU53_int_W";
        _internal84Count = _plane ammo "USAF_CBU100_Launcher";
        _internalJAGMCount = _plane ammo "USAF_JAGM_Launcher";
        _internalAIMCount = _plane ammo "USAF_AIM120I_Launcher";

        if (
            (((currentWeapon _plane) isEqualTo "USAF_AIM120I_Launcher") and (_internalAmraamCount > 0)) ||
            {(((currentWeapon _plane) isEqualTo "USAF_GBU31_Launcher") and (_internalGbuCount > 0 ))} ||
            {(((currentWeapon _plane) isEqualTo "USAF_GBU32_Launcher") and (_internalGbu2Count > 0 ))} ||
            {(((currentWeapon _plane) isEqualTo "USAF_GBU38_Launcher") and (_internalGbu3Count > 0 ))} ||
            {(((currentWeapon _plane) isEqualTo "USAF_AGM154A1_Launcher") and (_internalGbu4Count > 0 ))} ||
            {(((currentWeapon _plane) isEqualTo "USAF_GBU24_Launcher") and (_internalGbu5Count > 0 ))} ||
            {(((currentWeapon _plane) isEqualTo "USAF_AIM120I_Launcher") and (_internalAIMCount > 0 ))} ||
            {(((currentWeapon _plane) isEqualTo "USAF_JAGM_Launcher") and (_internalJAGMCount > 0 ))} ||
            {(((currentWeapon _plane) isEqualTo "USAF_CBU100_Launcher") and (_internal84Count > 0 ))} ||
            {(((currentWeapon _plane) isEqualTo "USAF_F35A_GBU53_int_W") and (_internalSdbCount > 0 ))}
        ) then {
            _plane animate ["bayL_hatch_1",1];
            _plane animate ["bayL_hatch_1_w",1];
            _plane animate ["bayL_hatch_1_b",1];
            _plane animate ["bayR_hatch_1",1];
            _plane animate ["bayR_hatch_1_w",1];
            _plane animate ["bayR_hatch_1_b",1];

            if (
                (((currentWeapon _plane) isEqualTo "USAF_GBU31_Launcher") and (_internalGbuCount > 0 )) ||
                {(((currentWeapon _plane) isEqualTo "USAF_GBU32_Launcher") and (_internalGbu2Count > 0 ))} ||
                {(((currentWeapon _plane) isEqualTo "USAF_GBU38_Launcher") and (_internalGbu3Count > 0 ))} ||
                {(((currentWeapon _plane) isEqualTo "USAF_AGM154A1_Launcher") and (_internalGbu4Count > 0 ))} ||
                {(((currentWeapon _plane) isEqualTo "USAF_GBU24_Launcher") and (_internalGbu5Count > 0 ))} ||
                {(((currentWeapon _plane) isEqualTo "USAF_JAGM_Launcher") and (_internalJAGMCount > 0 ))} ||
                {(((currentWeapon _plane) isEqualTo "USAF_CBU100_Launcher") and (_internal84Count > 0 ))} ||
                {(((currentWeapon _plane) isEqualTo "USAF_AIM120I_Launcher") and (_internalAIMCount > 0 ))} ||
                {(((currentWeapon _plane) isEqualTo "USAF_F35A_GBU53_int_W") and (_internalSdbCount > 0 ))}
            ) then {
                _plane animate ["bayL_hatch_2",1];
                _plane animate ["bayL_hatch_2_b",1];
                _plane animate ["bayR_hatch_2",1];
                _plane animate ["bayR_hatch_2_b",1];
            } else {
                _plane animate ["bayL_hatch_2",0];
                _plane animate ["bayL_hatch_2_b",0];
                _plane animate ["bayR_hatch_2",0];
                _plane animate ["bayR_hatch_2_b",0];
            };
        } else {
            _plane animate ["bayL_hatch_1",0];
            _plane animate ["bayL_hatch_1_w",0];
            _plane animate ["bayL_hatch_1_b",0];
            _plane animate ["bayR_hatch_1",0];
            _plane animate ["bayR_hatch_1_w",0];
            _plane animate ["bayR_hatch_1_b",0];
            _plane animate ["bayL_hatch_2",0];
            _plane animate ["bayL_hatch_2_b",0];
            _plane animate ["bayR_hatch_2",0];
            _plane animate ["bayR_hatch_2_b",0];
        };
        if (velocityModelSpace _plane select 1 > 5) then {
            _plane animate ["wingtipR",0];
            _plane animate ["wingtipR_2",0];
            _plane animate ["wingtipR_1",0];
            _plane animate ["wingtipR_lip",0];
            _plane animate ["wingtipL",0];
            _plane animate ["wingtipL_2",0];
            _plane animate ["wingtipL_1",0];
            _plane animate ["wingtipL_lip",0];
        };
    };
}, 0.1, [_plane]] call cba_fnc_addPerFrameHandler;

if (isNil "F22_initstate") then {
    for "_i" from 1 to 11 do {  _plane setVariable [(format["screen_%1",_i]),'off',true]; };
    F22_initstate = true;
};
if ((getpos _plane select 2) > 15 and driver _plane isEqualTo player) then {
    for "_i" from 1 to 11 do {  _plane setVariable [(format["screen_%1",_i]),'on',true]; };
};

GVAR(screenHandler) = [{
    params ["_args", "_idPFH"];
    _args params ["_plane"];

    if (!alive _plane) exitWith {
        [_idPFH] call cba_fnc_removePerFrameHandler;
    };

    if (local _plane) then {
        if ((isengineon _plane) && (driver _plane isEqualTo player)) then {
            for "_i" from 1 to 11 do {  _plane setVariable [(format["screen_%1",_i]),'on',true]; };
        } else {
            for "_i" from 1 to 11 do {  _plane setVariable [(format["screen_%1",_i]),'off',true]; };
        };

        if (_plane getVariable ["screen_1",'off'] isEqualTo 'off') then {_plane setobjecttexture [1,"\USAF_F35A\data\black_co.paa"];} else {_plane setobjecttexture [1,"\USAF_F35A\data\aircraft_mfd2_co.paa"];};
        if (_plane getVariable ["screen_2",'off'] isEqualTo 'off') then {_plane setobjecttexture [2,"\USAF_F35A\data\black_co.paa"];} else {_plane setobjecttexture [2,"\USAF_F35A\data\aircraft_mfd1F_co.paa"];};
        if (_plane getVariable ["screen_3",'off'] isEqualTo 'off') then {_plane setobjecttexture [3,"\USAF_F35A\data\black_co.paa"];} else {_plane setobjecttexture [3,"\USAF_F35A\data\aircraft_mfd3_co.paa"];};
        if (_plane getVariable ["screen_4",'off'] isEqualTo 'off') then {_plane setobjecttexture [4,"\USAF_F35A\data\black_co.paa"];} else {_plane setobjecttexture [4,"\USAF_F35A\data\aircraft_mfd4_co.paa"];};
        if (_plane getVariable ["screen_5",'off'] isEqualTo 'off') then {_plane setobjecttexture [5,"\USAF_F35A\data\black_co.paa"];} else {_plane setobjecttexture [5,"\USAF_F35A\data\f_35c_mfd_co.paa"];};
        if (_plane getVariable ["screen_6",'off'] isEqualTo 'off') then {_plane setobjecttexture [6,"\USAF_F35A\data\black_co.paa"];} else {_plane setobjecttexture [6,"\USAF_F35A\data\f_35c_mfd_co.paa"];};
    };
}, 0, [_plane]] call cba_fnc_addPerFrameHandler;

[_plane] call FUNC(sonicBoom);
