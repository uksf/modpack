# AI Commander

Ambient AI commander POC for Arma 3.

## What It Provides

- `AIC Commander` editor module
- `AIC Objective` editor module
- Objective-owned state loops (`owned_secure`, `contested`, `contested_losing`, `not_owned`)
- Commander decision loop (`attack`, `defend`, `reinforce`, `fall_back`)
- Separate patrol loop
- CfgGroups-based spawning using a faction class string
- Per-commander wave cap (1-5 groups)
- Group metadata tracking (task, count, position/grid, morale)
- Zeus debug provider for commander/objective picture

## Module Setup (Eden)

1. Place one or more `AIC Objective` modules.
2. Configure objective fields:
   - Objective name
   - Priority
   - Initial owner
   - Force pool (groups)
   - Contested losing threshold
   - Area (module area tool)
3. Place one `AIC Commander` module.
4. Configure commander fields:
   - Side
   - Faction (CfgGroups class, e.g. `OPF_F`, `BLU_F`)
   - Loop interval
   - Max wave size
   - Grid cell size
5. Synchronize all desired objective modules to the commander module.
6. Run mission on server/host.

## Runtime Behavior Notes

- Ownership flips immediately when only one side remains in objective area.
- Objective force pool is tokenized by group count.
- Groups consume a token when spawned and return token on release.
- Patrol groups come from the same objective pool budget.

## Validation

### Fast syntax validation (recommended baseline)

From repo root:

```powershell
python tools\sqf_validator.py --module aicommander
```

Expected output includes:

- `Checked 22 files`
- `Errors detected: 0`
- `SQF validation PASSED`

### Optional static linter (`tools/sqf_linter.py`)

`tools/sqf_linter.py` depends on the external Python package `sqf`.

Create and use a virtual environment:

```powershell
python -m venv .venv
.\.venv\Scripts\Activate.ps1
python -m pip install --upgrade pip
pip install git+https://github.com/LordGolias/sqf.git
```

Then run:

```powershell
python tools\sqf_linter.py -d addons\aicommander
```

If you still see `ModuleNotFoundError: No module named 'sqf'`, confirm you are using the venv interpreter:

```powershell
python -c "import sys; print(sys.executable)"
python -c "import sqf; print('sqf import OK')"
```

## Debug

This addon registers an `AI Commander` Zeus debug provider in `XEH_postInit`.
