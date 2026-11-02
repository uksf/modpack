private _classes = ("(configName _x) select [0, 14] == 'uksf_resupply_' && getNumber (_x >> 'scope') == 2" configClasses (configFile >> "CfgVehicles")) apply { configName _x };
[2, "all", [], [], [], _classes] spawn BIS_fnc_exportEditorPreviews;
