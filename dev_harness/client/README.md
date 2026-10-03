# Visual client harness

Runs SQF in a real, windowed Arma 3 client and returns its log lines and screenshots. Use it for
anything you have to see: models, textures, UV layouts, animations, particles, lights, UI.
For config reads and SQF return values, the dev-run server (`../submit.js`) is lighter.

```bash
node dev_harness/client/run.js test.sqf --mods dev-air --sheet --timeout 420
```

- `--mods`: `vanilla` (default, about 25 s), a preset in `mods/` (`dev`, `dev-air`; about 95 s),
  or a file with one mod folder per line.
- `--world`: mission world, default `VR`. The player stands at [100,100]; place test objects yourself.
- `--out`: screenshot folder, default `shots/` next to the test file. `--sheet` adds `sheet.jpg`.
- `--keep`: keep the temporary mod with the packed mission.

Exit code 0 when the test reached `call vc_fnc_done`. The last line is JSON:
`{state: done|exited|hung|timeout, seconds, rpt, shots}`. `hung` means Windows reported the window
"Not Responding" for 45 s. Shots taken before a failure are still returned.

## Writing a test

The test runs scheduled after the player exists. HUD, radio and the player body are hidden.

```sqf
private _v = createVehicle ["uksf_air_typhoon_raf", [100, 140, 0], [], 0, "CAN_COLLIDE"];
uiSleep 4;                                         // let the model and textures stream in
[_v, 45, 20] call vc_fnc_orbit; "fl" call vc_fnc_shot;   // azimuth from the nose, elevation, auto distance
[_v, 180, 8, 7, 0.5] call vc_fnc_orbit; "nozzles" call vc_fnc_shot;   // 7 m, zoomed
[eyeASL, targetASL, 0.35] call vc_fnc_cam;         // any camera
"any text" call vc_fnc_log;                        // [vclient] line in the output
call vc_fnc_done;
```

## How it works

1. The mission in `mission/` plus the test file are packed into `@uksf_vclient/addons/uksf_vclient.pbo`
   in a temporary folder. Nothing is written to the Arma folder.
2. `arma3_x64.exe` (not the BattlEye launcher) starts with `-window -noPause -noSound
   -name=uksfdevclient -init=playMission['','\uksf_vclient\vclient.VR']`.
3. `screenshot` writes PNGs to `Documents\Arma 3 - Other Profiles\uksfdevclient\Screenshots`, named
   with this run's id, so parallel runs from other sessions never collide. The runner moves only its
   own files to `--out`. They are full window resolution, the frame the client rendered.
4. The runner reads this run's RPT, then kills only its own PID.

## Gotchas

- `playMission` needs a PBO path. An absolute folder path makes Arma quit silently with
  "Shutdown normally".
- Other sessions run their own Arma clients. Never kill `arma3_x64` by name. If a run reports
  "vanished without a shutdown line", some other script killed it.
- `-noPause` keeps rendering when the window has no focus, and `-noSound` keeps the test silent; a
  visual test has no use for audio. The window may be behind
  other windows; `screenshot` reads the game's own frame, not the desktop.
- Wait about 4 s after `createVehicle` and 1.5 s after each camera move (the helpers do the second).
- Model space for `modelToWorld` is x right, y forward, z up, about the model's centre, not the ground.
