#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(apps) = [];
GVAR(content) = [];
GVAR(mapHandlers) = [];
GVAR(overlays) = [];
GVAR(currentApp) = "";
GVAR(lastMode) = "";

GVAR(routeWaypoints) = [];
GVAR(routeLegs) = [];
GVAR(routeRoads) = false;

GVAR(elevationObserver) = [];
GVAR(elevationMode) = "visible";
GVAR(elevationEye) = 2;
GVAR(elevationRadius) = 1000;
GVAR(elevationCells) = [];
GVAR(elevationPending) = [];
GVAR(elevationCellHalf) = 0;
GVAR(elevationGround) = 0;
GVAR(elevationTotal) = 0;
GVAR(elevationVisible) = 0;
GVAR(elevationHighest) = 0;
GVAR(elevationJob) = -1;

GVAR(reportType) = [];

GVAR(markerPoint) = [];
GVAR(markerIcon) = 0;
GVAR(markerSize) = 0;
GVAR(markerDir) = 0;

GVAR(jumpZone) = [];
GVAR(jumpPlan) = [];
GVAR(jumpMode) = "HALO";
GVAR(jumpRelease) = 4000;
GVAR(jumpOpening) = JUMP_HALO_OPENING;
GVAR(jumpHeading) = -1;


GVAR(friendlyGroups) = [];

GVAR(drones) = [];
GVAR(dronePoint) = [];

GVAR(mpu5Radio) = "";
GVAR(mpu5Page) = "talkgroups";
GVAR(mpu5AudioTalkgroup) = 1;
GVAR(mpu5Refreshing) = false;
GVAR(mpu5Feeds) = [];
GVAR(mpu5FeedStatus) = "";

ADDON = true;
