# ATAK

Joins the UKSF ACRE MPU-5 radio to the Modern ATAK (COMSPEC) phone. Opening an MPU-5 from the ACRE radio menu opens the phone's Wave Relay app.

COMSPEC counts every item class whose name contains `MPU5` as an MPU-5, so `ACRE_MPU5` is a mesh node without a config change. ACRE carries MPU-5 voice. `cba_settings.sqf` turns off the COMSPEC voice bridge (`comspec_atak_native_mpu_voice`) and Athena (`comspec_atak_native_local_only`).

The addon is skipped when `acre_sys_mpu5` or `comspec_atak_native_main` is missing.

The addon keeps the removed cTab item classes so old persistence saves and crates still load. `ItemcTab`, `ItemAndroid`, and `ItemMicroDAGR` turn into a `COMSPEC_ATAK_Phone`, and a linked one also leaves an `ItemGPS` in the GPS slot. `ItemcTabHCam` turns into a `COMSPEC_ATAK_Camera`.

`CfgComspec.hpp` hides Athena, Discord, Resynch, YearReview, Tenant, Fiches and the civilian apps except Calculator and Notes, and blanks the Athena start splash, loading logo and ESC-menu button handlers. `i18n_en.txt` adds English for French strings that COMSPEC's own dictionary lacks; `XEH_preStart.sqf` appends it to the English dictionary chain. On Zeus display load, every `comspec_*` root context action moves under one ATAK parent. On self-interaction menu open, every `COMSPEC_*` self-action under the self root, Equipment, or Explosives moves under one ATAK self-action and keeps its own condition; a hidden stub keeps the old path so COMSPEC actions added there later still appear.
