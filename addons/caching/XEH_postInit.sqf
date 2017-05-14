#include "script_component.hpp"

if (!GVAR(enabled)) exitWith {
    INFO("Caching is disabled.");
    enableDynamicSimulationSystem false;
};

enableDynamicSimulationSystem true;
"Group" setDynamicSimulationDistance 1000;
"Vehicle" setDynamicSimulationDistance 1000;
"EmptyVehicle" setDynamicSimulationDistance 250;
"Prop" setDynamicSimulationDistance 50;
"IsMoving" setDynamicSimulationDistanceCoef 2;

[FUNC(handleCache), 2, []] call cba_fnc_addPerFrameHandler;
