LSD_stop = false;
private _vehicle = aten;

private _mod = "red"; 
private _modArray = ["off", "white", "red", "green", "blue"]; 
private _index = _modArray find _mod; 
private _colorData = [[0, 0, 0, 0], [1, 1, 1, 0.8], [0.9, 0.1, 0.1, 0.8], [0, 1, 0, 0.8], [0, 0, 1, 0.8]];
private _particleColor = _colorData select _index; 
private _objectFollowOld = _vehicle getVariable ["objectFollow", objNull]; 
private _particleSourceOld = _vehicle getVariable ["smokeSource", objNull]; 
deleteVehicle _objectFollowOld; 
deleteVehicle _particleSourceOld; 
if (_mod isEqualTo "off") exitWith { 
    _vehicle setVariable ["smokeMod", _mod]; 
    _vehicle setVariable ["smokeEffect", _particleEffect]; 
    _vehicle getVariable ["objectFollow", objNull]; _vehicle setVariable ["smokeSource", objNull]; 
}; 
private _objectFollow = "Land_Bucket_F" createVehicle (getPos _vehicle); 
_objectFollow attachTo [_vehicle, [0.0, -8.0, 0.0]]; 
_objectFollow hideObjectGlobal true; 
private _particleSource = "#particlesource" createVehicle (getPos _vehicle); 
_particleSource attachTo [_objectFollow, [0, 0, 0]]; 
_particleSource setParticleCircle [0, [0, 0, 0]]; 
_particleSource setParticleRandom [5, [0, 0, 0], [4, 4, 4], 0, 0.25, [0, 0, 0, 0.8], 0, 0];
_particleSource setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal", 16, 12, 8, 0], "", "Billboard",1,30,[0, 0, 0],[0, -10, 0],10, 10.00, 8, 1,[5, 10, 5],[_particleColor],[0.25],1,0,"","",_objectFollow];
_particleSource setDropInterval 0.0125;
 
_vehicle setVariable ["smokeMod", _mod]; 
_vehicle setVariable ["smokeEffect", _particleEffect]; 
_vehicle getVariable ["objectFollow", _objectFollow]; 
_vehicle setVariable ["smokeSource", _particleSource];

private _hSCount = count (getArray (configFile >> "CfgVehicles" >> typeOf _vehicle >> "hiddenSelections"));
private _hSTex = getArray (configFile >> "CfgVehicles" >> typeOf _vehicle >> "hiddenSelectionsTextures");

[{
    params ["_idPFH", "_args"];
    _args params ["_index", "_vehicle", "_hSCount", "_hSTex"];

    if (LSD_stop) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        for "_i" from 0 to (_hSCount - 1) do {
            _vehicle setObjectTextureGlobal [_i, _hSTex select _index];
        };
    };

    for "_i" from 0 to (_hSCount - 1) do {
        _vehicle setObjectTextureGlobal [_i, LSD_Colors select _index];
    };

    _index = ((_index + 1) % 7) mod count LSD_Colors;
    _args set [0, _index];
}, 0.02, [0, _vehicle, _hSCount, _hSTex]] call CBA_fnc_addPerFrameHandler;


21:52:59 Error in expression <VCM_fnc_ClstObj;
private _Foot = isNull objectParent _Unit;
if (_Foot) then
{
if>
21:52:59   Error position: <objectParent _Unit;
if (_Foot) then
{
if>
21:52:59   Error objectparent: Type Array, expected Object
21:52:59 File \Vcom\Vcom\Functions\fn_ArmStatics.sqf [VCM_fnc_ArmStatics], line 10
