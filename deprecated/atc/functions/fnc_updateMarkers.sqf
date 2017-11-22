/*
    Author:
        Tim Beswick

    Description:
        Updates radar markers

    Parameter(s):
        0: Object <OBJECT>
        1: Targets <ARRAY>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_object", "_targets"];

for "_i" from 0 to ((count _targets) - 1) do {
    _curtarget = _targets select _i;
    _curtargetname = getText (configFile >> 'cfgVehicles' >> typeOf _curtarget >> 'displayName');
    _curtargetmkr = (format ["%1%2",str(_curtarget),_i]);
    _speed = ((speed _curtarget)/1.852);
    _alt = (((getPosATL _curtarget) select 2)*3.28084);
    _altS = (((getPosASL _curtarget) select 2)*3.28084);
    _curtargetdir = if (round(getDir _curtarget) >= 360) then {0} else {round(getDir _curtarget)};
    if (alive _curtarget) then {
        _g = createMarkerLocal [_curtargetmkr,_curtarget];
        _curtargetmkr setMarkerPosLocal (getPos _curtarget);
        _g setMarkerShapeLocal "ICON";
        _curtargetmkr setMarkerTextLocal format ["%1: %2knts %3ft-agl %4ft-asl %5°",_curtargetname,round(_speed),round(_alt),round(_altS),_curtargetdir];
        _curtargetmkr setMarkerDirLocal _curtargetdir;
        switch (true) do {
            case (_curtarget isKindOf "UK3CB_BAF_Apache_AH1"): { _curtargetmkr setMarkerTypeLocal "UKSF_M_apache" };
            case (_curtarget isKindOf "UKSF_C130J_Transport"): { _curtargetmkr setMarkerTypeLocal "UKSF_M_c130" };
            case (_curtarget isKindOf "UKSF_C130J_Cargo"): { _curtargetmkr setMarkerTypeLocal "UKSF_M_c130" };
            case (_curtarget isKindOf "UKSF_Chinook_M134"): { _curtargetmkr setMarkerTypeLocal "UKSF_M_chinook" };
            case (_curtarget isKindOf "UKSF_Chinook_M134M240"): { _curtargetmkr setMarkerTypeLocal "UKSF_M_chinook" };
            case (_curtarget isKindOf "EAWS_EF2000"): { _curtargetmkr setMarkerTypeLocal "UKSF_M_typhoon" };
            case (_curtarget isKindOf "UKSF_Griffin"): { _curtargetmkr setMarkerTypeLocal "UKSF_M_griffin" };
            case (_curtarget isKindOf "UK3CB_BAF_Merlin_HC3_Base"): { _curtargetmkr setMarkerTypeLocal "UKSF_M_merlin" };
            case (_curtarget isKindOf "UKSF_MQ9"): { _curtargetmkr setMarkerTypeLocal "UKSF_M_reaper" };
            case (_curtarget isKindOf "UK3CB_BAF_Wildcat_AH1_CAS_8A"): { _curtargetmkr setMarkerTypeLocal "UKSF_M_wildcat" };
            case (_curtarget isKindOf "UK3CB_BAF_Wildcat_AH1_HEL_8A"): { _curtargetmkr setMarkerTypeLocal "UKSF_M_wildcat" };
            case (_curtarget isKindOf "UK3CB_BAF_Wildcat_AH1_TRN_8A"): { _curtargetmkr setMarkerTypeLocal "UKSF_M_wildcat_unarmed" };
            case (_curtarget isKindOf "bwi_a3_su25_base"): { _curtargetmkr setMarkerTypeLocal "UKSF_M_su25" };
            case (_curtarget isKindOf "sab_SU34_BASE"): { _curtargetmkr setMarkerTypeLocal "UKSF_M_su34" };
            case (_curtarget isKindOf "mas_Mi8_Base"): { _curtargetmkr setMarkerTypeLocal "UKSF_M_mi8" };
            case (_curtarget isKindOf "mas_Mi24_Base"): { _curtargetmkr setMarkerTypeLocal "UKSF_M_mi24" };
            default { _curtargetmkr setMarkerTypeLocal "b_air"; };
        };
        if (((side player) getFriend (side _curtarget)) < 0.6) then {
            _curtargetmkr setMarkerColorLocal "ColorRed";
        } else {
            _curtargetmkr setMarkerColorLocal "ColorBlue";
        };
        _curtargetmkr setMarkerAlphaLocal 1;

        _allMarkers = player getVariable [QGVAR(markers), []];
        _allMarkers pushBack _curtargetmkr;
        player setVariable [QGVAR(markers), _allMarkers, true];
    } else {
        if (markerColor _curtargetmkr != "") then {
            _allMarkers = player getVariable [QGVAR(markers), []];
            _allMarkers = _allMarkers - [_curtargetmkr];
            player setVariable [QGVAR(markers), _allMarkers, true];
            deleteMarker _curtargetmkr;
        };
    };
};
