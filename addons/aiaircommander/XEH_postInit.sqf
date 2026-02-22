#include "script_component.hpp"

if (isServer) then {
    [QEGVAR(zeus,registerVisualiseProvider), ["aicommander_air", {call FUNC(getVisualisationData)}]] call CBA_fnc_localEvent;
};
