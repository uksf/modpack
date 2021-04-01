# Custom events

UKSF mods make use of [CBA Custom Events](https://github.com/CBATeam/CBA_A3/wiki/Custom-Events-System).

Some events are designed to be raised, rather than handled, and as such the list
has been split into two sections.

Not all events are listed, as many are not designed to be used outisde of their
specific purpose.

Events are sorted by module with their fully qualified name.

## Events that should be handled

An event that should be handled is one which your code can hook into to provide
a certain behaviour on top of the default behaviour.

**Note:** default behaviour cannot be overwritten.

For example, you would handle an event by adding an event handler:

```sqf
["uksf_mission_hitRaw", {
    params ["_unit", "_shooter"];

    hint format ["%1 was hit by %2", _unit, _shooter];
}] call CBA_fnc_addEventHandler;
```

This would display a hint when an AI is shot, on the same client as where the AI
is local.

### Mission (Handle)

#### uksf_mission_hitRaw

- Raised when a unit is hit and passes the following conditions:
  - Unit is local to the client where this runs
  - Unit is not a player
- Parameters: [
    `_unit` \<OBJECT\>,
    `_shooter` \<OBJECT\>
  ]

#### uksf_mission_hitFiltered

- Raised when a unit is hit and passes the following conditions:
  - Conditions for `uksf_mission_hitRaw`
  - Unit has a support radio (`uksf_mission_hasSupportRadio` variable set to
    `true` on the unit)
  - Shooter is not in an air vehicle
  - Shooter is not going faster than 30 kmh
  - Distance between unit and shooter is less than 1km
- **Note:** If the `uksf_mission_hitFiltered` is raised, then the
  `uksf_mission_hitRaw` is also raised beforehand. Only use ONE of these events
- Handled by the base AI support and AI artillery support behaviours
- Parameters: [
    `_unit` \<OBJECT\>,
    `_shooter` \<OBJECT\>
  ]

#### uksf_mission_reTask

- Raised when a group completes their support tasking
- Handled by the base AI support to send a group back on patrol
- Parameters: [
    `_group` \<OBJECT\>,
    `_patrolPosition` \<ARRAY\>
  ]

### Persistence (Handle)

#### uksf_persistence_firstKilled

- Raised when a player joins the server and reaches the spawn point selection
  screen
- Handled by persistence to create their redeploy point if there is data saved
- Can only be raised where `player` is `local`
- Parameters: [
    `_data` \<ARRAY\>
  ]

#### uksf_persistence_firstRespawn

- Is raised when a player joins the server and spawns at a spawn point
- Handled by persistence to load saved player data if player spawned at their
  redeploy point
- Can only be raised where `player` is `local`
- Parameters: none

---

## Events that should be raised

An event that should be raised is one which your code should execute, in order
to have some default behaviour run.

**Note:** default raises cannot be overwritten.

An event designed to be raised can still be handled if your use case requires
it.

For example, you would raise an event by using the relevant
[CBA event raiser function](https://github.com/CBATeam/CBA_A3/wiki/Custom-Events-System#raise-custom-events):

```sqf
["uksf_common_addObjectsToCurators", [player]] call CBA_fnc_serverEvent;
```

This would add the player object to all curators.

### Arsenal

#### uksf_arsenal_addArsenal

- Adds an arsenal action to the given object with local effect
- Raised when a UKSF arsenal crate `uksf_resupply_arsenal` is created, and when the
  `Add full ACE Arsenal` module is placed on an object
- Parameters: [
    `_crate` \<OBJECT\>
  ]

#### uksf_arsenal_removeArsenal

- Removes an arsenal action from the given object with local effect
- Raised when the `Add full ACE Arsenal` and `Remove ACE Arsenal` modules are
  placed on an object
- In the case of the `Add full ACE Arsenal` module, this event is raised before
  the `uksf_arsenal_addArsenal` event
- Parameters: [
    `_object` \<OBJECT\>
  ]

### Caching

#### uksf_caching_disableCache

- Calls the `uksf_caching_fnc_disableCache` function, which forces an object out
  of caching
- Raised when any object is killed, and when an object is excluded from caching
  via the EDEN attribute and the zeus module `Caching exclude`
- Can only be raised onto the `server`. If it is not, it will be raised onto the
  server by the `uksf_caching_fnc_disableCache` function
- Parameters: [
    `_group` \<OBJECT or GROUP\>
  ]

#### uksf_caching_cache

- Caches the given group
- Group may be uncached by a client again unless the group is excluded from
  caching
- Raised when a group is cached by the server
- Can only be raised onto the `server`
- Parameters: [
    `_group` \<GROUP\>
  ]

#### uksf_caching_uncache

- Uncaches the given group
- Group may be cached by the server again unless the group is excluded from
  caching
- Raised when a group is uncached by a client
- Can only be raised onto the `server`
- Parameters: [
    `_group` \<GROUP\>
  ]

#### uksf_caching_setCacheState

- Sets the simulation and hidden state of the units of the given group
- If the group is in a vehicle, the units of other groups in the vehicle will
  also be set to the same state
- State may be overridden by a client or the server unless the group is excluded
  from caching
- Raised when a group is cached or uncached
- Can only be raised onto the `server`
- Parameters: [
    `_group` \<GROUP\>,
    `_state` \<BOOLEAN\>
  ]

### Cleanup

#### uksf_cleanup_addKilled

- Adds the object to a list of objects to delete after a delay
- Raised when any object is killed when not excluded from cleanup, and when an
  object is added to cleanup by the zeus module `Cleanup exclude` and was
  previously excluded from cleanup
- Can only be raised onto the `server`
- Parameters: [
    `_object` \<OBJECT\>
  ]

### Common

#### uksf_common_addObjectsToCurators

- Adds the object to the objects visible to curators
- Raised when a group is spawned by `uksf_mission_fnc_spawnGroup`, and when the
  zeus module `Add all objects` is placed on an object
- Parameters: [
    `_objects` \<ARRAY\>
  ]

#### uksf_common_deleteEmptyGroups

- Deletes all empty groups
- Raised every 5 minutes, and when inside the `uksf_common_waitAndDelete` event
  handler
- Parameters: none

#### uksf_common_hint

- Displays a hint
- Raised on curator login, logout, and kick
- Can only be raised onto clients
- Parameters: [
    `_message` \<STRING\>,
    `_admin` \<BOOLEAN\> (Optional)
  ]
- The `_admin` parameter will ensure the hint is only displayed on clients that
  are considred admins

#### uksf_common_log

- Logs the given message to the RPT log
- Raised on curator login and logout, and when a curator opens the arsenal of a
  player
- Parameters: [
    `_message` \<STRING\>
  ]

#### uksf_common_setSideRelation

- Sets the how friendly one side is with another side
- Only sets relations from first side to second. For the second side to consider
  the first side in the same way, the event should be run again with the sides
  reversed
- Raised by the `Toggle ... Relations` zeus modules
- Can only be raised onto the `server`
- Parameters: [
    `_side1` \<SIDE\>,
    `_side2` \<SIDE\>,
    `_value` \<SCALAR\>
  ]

#### uksf_common_textTiles

- Displays a vanilla [text tile](https://community.bistudio.com/wiki/BIS_fnc_textTiles)
- Raised on curator login, logout, and kick
- Can only be raised onto clients
- Parameters: Same as [BIS_fnc_textTiles](https://community.bistudio.com/wiki/BIS_fnc_textTiles)

#### uksf_common_waitAndDelete

- Waits for the given delay then deletes an object
- Can only be raised onto the `server`
- Parameters: [
    `_delay` \<SCALAR\>,
    `_object` \<OBJECT\>
  ]

### Curator

#### uksf_curator_setCuratorsLocked

- Sets whether curator login is locked or unlocked
- Raised from the `Lock Curators` and `Unlock Curators` interactions
- Can only be raised onto the `server`
- Parameters: [
    `_locked` \<BOOLEAN\>
  ]

### Mission (Raise)

#### uksf_mission_initPatrol

- Creates a patrol pool at the given location of the given faction
- Raised by the `Spawn Area` EDEN module
- Can only be raised onto the `server`
- Parameters: [
    `_position` \<MARKER or TRIGGER or LOCATION\>,
    `_maxGroupsActive` \<SCALAR\> (Optional, Default: 5),
    `_groupPoolSize` \<SCALAR\> (Optional, Default: 10),
    `_factionName` \<STRING\> (Optional, Default: "OPF_F")
  ]

#### uksf_mission_fireMission

- Runs a fire mission for a given artillery object
- Raised by the `uksf_mission_fnc_artillerySupport` function
- Can only be raised where `_artillery` is `local`
- Parameters: [
    `_caller` \<OBJECT\>,
    `_artillery` \<OBJECT\>,
    `_targetPosition` \<ARRAY\>,
    `_stage` \<OBJECT\> (Optional, Don't specify unless skipping a stage, Default: 0),
    `_previousPosition` \<ARRAY\> (Optional, Required if stage is not 0),
    `_spread` \<SCALAR\> (Optional, Required if stage is not 0, Overwritten if stage 0 runs first)
  ]
- The `_stage` parameter determines the type of fire mission. Stage 0 Check
  round (far), Stage 1 Check round (near), Stage 2 Barrage (close)
- A stage will always call the next stage in the sequence, apart from stage 2

### Persistence (Raise)

#### uksf_persistence_addLogisticsMarker

- Adds the object as a persistence marker
- Raised when a persistence marker is thrown, and when a persistence marker is
  loaded from a persistence save
- Can only be raised onto the `server`
- Parameters: [`_object` \<OBJECT\>]

#### uksf_persistence_markObjectAsPersistent

- Marks a vehicle as persistent so it will be saved
- Raised by the EDEN attribute `Marks vehicle as persistent`, when a player
  disconnects and they are in a vehicle, when a vehicle is within the distance
  of a player or persistence marker to be saved, and when a persistent vehicle
  is loaded from a persistence save
- Can only be raised onto the `server`
- Parameters: [`_object` \<OBJECT\>]

#### uksf_persistence_shutdown

- Shuts the server down and ensures persistence data is saved
- Raised by the `Save and Shutdown` interaction
- Can only be raised onto the `server`
- Parameters: none

### Special

#### uksf_special_movingTarget

- Makes an object a moving target
- Can only be raised where `_target` is `local`
- Parameters: [
    `_target` \<OBJECT\>,
    `_direction` \<SCALAR\>,
    `_distance` \<SCALAR\>,
    `_speed` \<SCALAR\>,
    `_timeout` \<SCALAR\> (Optional, Default: 10),
    `_pause` \<SCALAR\> (Optional, Default: 2)
  ]

### Zeus

#### uksf_zeus_moveInCargo

- Moves the given unit into the cargo of the given vehicle
- Parameters: [`_unit` \<OBJECT\>, `_vehicle_` \<OBJECT\>]

#### uksf_zeus_paraDrop

- Paradrops the given units from a C-130
- Can only be raised onto the `server`
- Parameters: [
    `_units` \<ARRAY\>,
    `_positionStart` \<ARRAY\>,
    `_positionEnd` \<ARRAY\>,
    `_altitude` \<SCALAR\> (Optional, Default: 2000)
  ]
