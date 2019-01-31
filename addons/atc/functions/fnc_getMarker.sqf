/*
    Author:
        Tim Beswick

    Description:
        Gets marker type for object

    Parameter(s):
        0: Aircraft <OBJECT>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_aircraft"];

private _markerType = "b_air";

switch (true) do {
    case (_aircraft isKindOf "UKSF_Apache_base"): {_markerType = QGVAR(apache)};
    case (_aircraft isKindOf "CUP_C130J_Base"): {_markerType = QGVAR(c130)};
    case (_aircraft isKindOf "CUP_CH47F_base"): {_markerType = QGVAR(chinook)};
    case (_aircraft isKindOf "CUP_L39_base"): {_markerType = QGVAR(l39)};
    case (_aircraft isKindOf "uksf_f35_plane_base"): {_markerType = QGVAR(f35)};
    case (_aircraft isKindOf "UK3CB_BAF_Merlin_Base"): {_markerType = QGVAR(merlin)};
    case (_aircraft isKindOf "CUP_B_UKSF_MQ9"): {_markerType = QGVAR(reaper)};
    case (_aircraft isKindOf "UK3CB_BAF_Wildcat_AH1_CAS_6A"): {_markerType = QGVAR(wildcat)};
    case (_aircraft isKindOf "UK3CB_BAF_Wildcat_AH1_CAS_8A"): {_markerType = QGVAR(wildcat)};
    case (_aircraft isKindOf "UK3CB_BAF_Wildcat_Base"): {_markerType = QGVAR(wildcat_unarmed)};
    default {_markerType = "b_air"; };
};

_markerType
