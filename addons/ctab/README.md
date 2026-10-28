# cTab

Adds an app launcher to the cTab Android dialog. The back key on the phone opens the launcher. The Home key returns to cTab's BFT page.

The launcher needs the `ctab_core.pbo` patch in `patches/@uksf_dependencies/ctab_core.pbo.json`. The patch makes `cTab_fnc_updateInterface` show no cTab page in `UKSF_` modes and raise `uksf_ctab_modeChanged` after every page change.

The addon registers these apps:

- Route: click the map to add waypoints. Legs are straight or follow roads through `calculatePath`. Shows the length and the travel time on foot and by vehicle.
- Elevation: click the map to place an observer. Shows terrain visibility or relative height over a 40 by 40 grid. Buildings and other objects are ignored.
- Reports: TIC, TIC CLEAR, EAGLE DOWN, BDA, SALUTE, and FRAGO forms, sent through cTab messaging to chosen recipients. Grid fields are attached as map positions.
- HAHO / HALO: click the map to set the drop zone. Calculates the release point from the wind, using 67 m/s freefall, 3 m/s canopy sink, and 4.4 m/s canopy glide measured in Arma.
- Weather: time, sunrise and sunset, moon, cloud, fog, rain, wind, temperature, pressure, and humidity from ACE Weather.
- Friendly: groups that cTab shows on BFT, with grid, range, bearing, and each member's transport and state.
- Drones: friendly UAVs in cTab's UAV list. Observe a map point, escort the requester, hold, or return. The task runs where the drone is local.

Route, Elevation, HAHO / HALO, and Drones show a side panel over the BFT map. The other apps fill the screen. The dialog reopens on the last app.

To add an app, register it on every client:

```sqf
["route", "Route", {
    params ["_display", "_group"];
}, {
    params ["_display", "_group"];
}, false] call uksf_ctab_fnc_registerApp;
```

The open code builds the app's controls inside `_group`, which fills the phone screen. Pass `true` as the last argument to get a side panel over the map instead; the open code then also gets the map control as its third parameter. The close code runs before the launcher deletes `_group`.
