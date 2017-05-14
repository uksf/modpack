#include "script_component.hpp"

if (!GVAR(enabled)) exitWith {
    INFO("Caching is disabled.");
    enableDynamicSimulationSystem false;
};

INFO("Caching is enabled.");
enableDynamicSimulationSystem true;
"Group" setDynamicSimulationDistance GVAR(distance);
"Vehicle" setDynamicSimulationDistance GVAR(distance);
"EmptyVehicle" setDynamicSimulationDistance 250;
"Prop" setDynamicSimulationDistance 50;
"IsMoving" setDynamicSimulationDistanceCoef 2;

[FUNC(handleCache), 2, []] call cba_fnc_addPerFrameHandler;
