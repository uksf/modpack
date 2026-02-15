# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

UKSF Modpack — a collection of Arma 3 addons (mods) for the UKSF community, built on the CBA (Community Base Addons) framework following ACE3/ACRE2 conventions. The primary language is **SQF**, Bohemia Interactive's scripting language for Arma 3. Config files use Arma's C-like class definition syntax (`.cpp`/`.hpp`).

- **Prefix**: `uksf`
- **Main prefix (P-drive path segment)**: `u` → full path: `\u\uksf\addons\<component>\`
- **Build tools are mixed**: HEMTT for dev addon builds (`hemtt.toml`), Python scripts for validation, MSBuild for C++ extensions

## Build and Validation Commands

Build tooling is mixed — use what fits the task:

```bash
# Build dev PBOs (HEMTT, from project root)
./hemtt.exe pack

# Build PBOs via Python fallback (uses makepbo)
python3 tools/build.py

# Compile C++ Intercept extension (requires MSBuild/Visual Studio, x64 Release)
python3 tools/build.py compile

# Validate SQF syntax (brackets, semicolons, tabs)
python3 tools/sqf_validator.py
python3 tools/sqf_validator.py -m <addon_name>   # single addon

# Validate config file syntax (.cpp/.hpp)
python3 tools/config_style_checker.py
python3 tools/config_style_checker.py -m <addon_name>

# Lint SQF (uses sqflint, may have false positives)
python3 tools/sqf_linter.py -d addons/

# Dev environment setup (creates P-drive and Arma directory symlinks)
python3 tools/setup.py
```

**CI (GitHub Actions on PRs)**: runs `sqf_validator.py`, `config_style_checker.py`, BOM check, and sqflint.

## Key Validation Rules

- **No tabs** — spaces only in all `.sqf`, `.cpp`, `.hpp` files (validators flag tabs as errors)
- **Semicolons after closing braces** — `};` not `}` when ending code blocks in SQF
- **Balanced brackets** — validators check `()`, `[]`, `{}` balance
- **No BOM** — files must not have byte order marks

## Architecture

### How It Works

The game reads `config.cpp` files — this is the entry point for everything. Configs define addon metadata (`CfgPatches`), register event handlers (`CfgEventHandlers`), and override/extend game classes (`CfgVehicles`, `CfgWeapons`, etc.). From there, XEH event handlers bootstrap SQF functions that implement the actual behavior.

Most development work falls into two categories:
1. **Config overrides** — modifying existing game/mod classes in `.cpp`/`.hpp` files (vehicles, weapons, equipment, factions)
2. **SQF functions** — writing new scripted functionality in `functions/fnc_*.sqf` files

### Addon Structure

Each addon lives in `addons/<component>/` and compiles to `addons/uksf_<component>.pbo`. The `loadOrder` addon declares all external mod dependencies and forces load ordering. The `main` addon provides shared macro definitions, versioning, and mod metadata. All other addons depend on `uksf_main` or `uksf_common`.

Standard addon layout:
```
addons/<component>/
  $PBOPREFIX$              # Contains path: u\uksf\addons\<component>
  script_component.hpp     # Defines COMPONENT, includes script_mod.hpp and script_macros.hpp
  config.cpp               # CfgPatches (addon metadata), includes other Cfg*.hpp files
  CfgEventHandlers.hpp     # XEH registration (Extended Event Handlers)
  XEH_preStart.sqf         # Runs once at game start — includes XEH_PREP.hpp
  XEH_preInit.sqf          # Runs at mission start before init — PREP functions, register events, init vars
  XEH_postInit.sqf         # Runs after mission init — keybinds, player event handlers, per-frame handlers
  XEH_PREP.hpp             # List of PREP(functionName) calls
  initSettings.sqf         # CBA settings registration (CBA_fnc_addSetting / CBA_settings_fnc_init)
  functions/               # SQF function files: fnc_<name>.sqf
  data/                    # Textures, models, previews
```

Addons without scripted behavior (config-only, e.g. `gear`, `units`, `weapons`) may omit XEH files and functions/.

### Dependency Chain

`loadOrder` (external deps) → `main` (macros, version) → `common` (shared utilities) → feature addons

### Configuration Modes

`addons/main/script_configuration.hpp` defines `CONFIGURATION` as one of `'development'`, `'rc'`, or `'release'`. The `optionals/rc/` addon is built for release candidate testing. Macros `CONFIGURATION_IS_DEVELOPMENT`, `CONFIGURATION_IS_RC`, `CONFIGURATION_IS_RELEASE` are available for conditional logic.

### C++ Extension (extensions/)

An Intercept-based C++ DLL providing access to things SQF cannot do — filesystem, networking, HTTP server. Built as a Visual Studio solution (`uksf.sln`, x64 Release, MSBuild). Uses Poco for HTTP, easylogging++ for logging. **Do not modify unless explicitly requested** — this is not where day-to-day development happens.

## CBA Macro System

All SQF and config files must `#include "script_component.hpp"` as their first line. This pulls in the macro system via `script_mod.hpp` → `script_macros.hpp` → CBA's `script_macros_common.hpp` and `script_xeh.hpp`.

### Critical Macros

| Macro | Expands to | Usage |
|-------|-----------|-------|
| `ADDON` | `uksf_<component>` | Addon class name in CfgPatches |
| `COMPONENT` | raw component name | Defined in each script_component.hpp |
| `GVAR(name)` | `uksf_<component>_name` | Component-scoped global variable |
| `QGVAR(name)` | `"uksf_<component>_name"` | Quoted string version of GVAR |
| `EGVAR(other,name)` | `uksf_other_name` | Cross-component variable reference |
| `QEGVAR(other,name)` | `"uksf_other_name"` | Quoted string cross-component reference |
| `FUNC(name)` | `uksf_<component>_fnc_name` | Reference to function in current component |
| `EFUNC(other,name)` | `uksf_other_fnc_name` | Reference to function in another component |
| `DFUNC(name)` | `uksf_<component>_fnc_name` | For function definition (used in PREP) |
| `PREP(name)` | Compiles `functions/fnc_name.sqf` | Function preparation (called in XEH_PREP.hpp) |
| `QPATHTOF(path)` | Quoted path to file in addon | File path resolution |
| `QUOTE(x)` | `"x"` | String quoting |
| `ARR_N(...)` | comma-separated args | Required when passing arrays inside macros (ARR_2 through ARR_17) |

### script_component.hpp Template

```cpp
#define COMPONENT mycomponent
#define COMPONENT_BEAUTIFIED My Component
#include "\u\uksf\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS

#include "\u\uksf\addons\main\script_macros.hpp"
```

## SQF Code Conventions

### Function File Pattern

Every function file follows this structure:
```sqf
#include "script_component.hpp"
/*
    Author:
        Name

    Description:
        What the function does

    Parameter(s):
        0: Description <TYPE>
        1: Description <TYPE> (Optional)

    Return Value:
        Description
*/
params [["_param1", defaultValue], ["_param2", defaultValue, [typeCheck]]];

// Function body
```

### Event System

Uses CBA event handlers for inter-component and networked communication:
```sqf
// Register event handler (in XEH_preInit.sqf)
[QGVAR(eventName), {call FUNC(handler)}] call CBA_fnc_addEventHandler;

// Fire events
[QGVAR(eventName), [args]] call CBA_fnc_localEvent;      // Local machine only
[QGVAR(eventName), [args]] call CBA_fnc_globalEvent;      // All machines
[QGVAR(eventName), [args]] call CBA_fnc_serverEvent;      // Server only

// Cross-component events use QEGVAR
[QEGVAR(common,addObjectsToCurators), [[objects]]] call CBA_fnc_serverEvent;
```

### Execution Context Patterns

```sqf
if (isServer) then { /* server-only logic */ };
if (hasInterface) then { /* player client logic */ };
if (!isServer && !hasInterface) then { /* headless client */ };
if (is3DEN) then { /* Eden Editor only */ };
if (isMultiplayer) then { /* MP only */ };
```

### CBA Settings

Settings registered in `initSettings.sqf` using:
```sqf
[QGVAR(settingName), "CHECKBOX", ["Display Name", "Tooltip"], ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)], defaultValue, scope] call CBA_fnc_addSetting;
// scope: 0 = client, 1 = server, 2 = mission
```

### XEH_preInit.sqf Skeleton

```sqf
#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

// Register CBA events, initialize variables, include settings
#include "initSettings.sqf"

ADDON = true;
```

The `ADDON = false; ... ADDON = true;` pattern is mandatory — CBA uses this to track initialization state.

### Scheduler Patterns

```sqf
// Per-frame handler (runs every frame or at interval)
[{/* code */}, interval, [args]] call CBA_fnc_addPerFrameHandler;

// Delayed execution
[{/* code */}, [args], delay] call CBA_fnc_waitAndExecute;
```

### Custom Macros (defined in script_macros.hpp)

- `WHITELISTED` / `ADMIN_OR_WHITELISTED` — permission checks against UID whitelist
- `ALL_PLAYERS` — all players minus headless clients
- `MACRO_ADDWEAPON`, `MACRO_ADDITEM`, `MACRO_ADDMAGAZINE`, `MACRO_ADDBACKPACK` — inventory config shortcuts
- `DEPRECATE_CLASS(CLASS,BASE)` / `HIDE_CLASS(CLASS,BASE)` — mark classes as deprecated/hidden
- `INVENTORY_EMPTY` / `RESET_INVENTORY` — clear vehicle inventory configs
- `DEBUG` / `DEBUG_1..8` — conditional debug logging (enabled via `DEBUG_MODE_FULL`)
- `UKSF_DEPRECATED(old,version,new)` — runtime deprecation warnings

## SQF Reference Documentation

- **Scripting Commands**: https://community.bistudio.com/wiki/Category:Arma_3:_Scripting_Commands
- **Event Handlers**: https://community.bistudio.com/wiki/Arma_3:_Event_Handlers

## Adding a New Addon

1. Create `addons/<name>/` directory
2. Create `$PBOPREFIX$` containing `u\uksf\addons\<name>`
3. Create `script_component.hpp` with `COMPONENT` and `COMPONENT_BEAUTIFIED` defines
4. Create `config.cpp` with `CfgPatches` class declaring `requiredAddons[] = {"uksf_common"};`
5. If scripted: create `CfgEventHandlers.hpp`, `XEH_preStart.sqf`, `XEH_preInit.sqf`, `XEH_PREP.hpp`
6. Place functions in `functions/fnc_<name>.sqf` and register with `PREP(<name>)` in `XEH_PREP.hpp`
7. Settings go in `initSettings.sqf`, included from `XEH_preInit.sqf`
