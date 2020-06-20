# Modes

There are 2 modes for dynamic AI patrols:

- Basic - runs with global settings defined with CBA settings, for everyone across the whole map
- Area - runs with settings defined in the Eden module, for everyone in the module area

Both modes are subject to safe zones, whereby dynamic patrols will not spawn when players are within a configurable distance from safe zones, which are UKSF respawn points.

Both modes can make use of the exclude and include zone modules placed in Eden, to further define the allowed spawn areas.
These areas check for the presence of players, before doing any dynamic patrol spawning.
These zones can be used as follows:

- Only include zones - dynamic patrols will only spawn when players are in these zones
- Only exclude zones - dynamic patrols will only spawn when players are outside these zones
- Both include and exclude zones - dynamic patrols will only spawn when players are inside the include zones (exclude zones are ignored)
- Exclude zones inside include zones - dynamic patrols will only spawn when players are inside the include zones, but not when players are also inside the exclude zones

## Basic Mode

Basic dynamic patrols will use the settings defined in CBA settings to spawn patrols near to players, anywhere on the map.

See the `cba_settings.sqf` file in `UKSFTemplate.VR` for details on the configurable settings to control the basic mode.

## Dynamic Mode

The `Dynamic Patrol Area` Eden module allows for the creation of a dynamic patrol area.

Dynamic patrols will only spawn when players are inside these zones.

When any `Dynamic Patrol Area` modules exist, basic spawning mode is disabled.

Exclude zone area modules can be used to exclude areas within a patrol area module.

Include areas are ignored in this mode.

Global AI group limits still apply, controlled by the `uksf_mission_dynamicPatrolGroupLimit` CBA setting (default 10)

All the settings for the zone module are the same as the basic mode CBA settings, but apply only to that zone. The same default values and value ranges apply.

For the unit and vehicle pool settings, these can be left blank or as an empty array, in which case the global setting will be used.
