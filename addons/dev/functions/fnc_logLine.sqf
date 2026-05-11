#include "..\script_component.hpp"

params [["_line", "", [""]]];

if (isNil "uksf_dev_runId") exitWith { false };
if (count _line > 4096) then { _line = (_line select [0, 4090]) + "[...]"; };

diag_log text format ["uksf_dev_logLine [%1]: %2", uksf_dev_runId, _line];
("uksf" callExtension ["devRunLog", [uksf_dev_runId, _line]]) select 0;
true
