# cTab

Adds an app launcher to the cTab Android dialog. The back key on the phone opens the launcher. The Home key returns to cTab's BFT page.

The launcher needs the `ctab_core.pbo` patch in `patches/@uksf_dependencies/ctab_core.pbo.json`. The patch makes `cTab_fnc_updateInterface` show no cTab page in `UKSF_` modes and raise `uksf_ctab_modeChanged` after every page change.

To add an app, register it on every client:

```sqf
["route", "Route", {
    params ["_display", "_group"];
}, {
    params ["_display", "_group"];
}] call uksf_ctab_fnc_registerApp;
```

The open code builds the app's controls inside `_group`, which fills the phone screen. The close code runs before the launcher deletes `_group`.
