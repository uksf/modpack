#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

#include "initSettings.inc.sqf"

GVAR(modes) = ["circle", "ellipse", "racetrack", "cone"];
GVAR(currentMode) = "circle";
GVAR(currentModeLabel) = "Circle";
GVAR(state) = "idle";
GVAR(stage1Start) = [0, 0, 0];
GVAR(stage1End) = [0, 0, 0];
GVAR(stage2Pos) = [0, 0, 0];
GVAR(drawKeyHeld) = false;
GVAR(playerShapes) = [];
GVAR(previewMarkers) = [];
GVAR(markerID) = 100000;
GVAR(stage2DefaultSecondary) = 0;
GVAR(hintVisible) = false;
GVAR(hintPFH) = -1;

ADDON = true;
