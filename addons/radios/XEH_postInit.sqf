#include "script_component.hpp"

call FUNC(registerDebugProviders);
call FUNC(setChannelNames);

[FUNC(handleCustomSignal)] call acre_api_fnc_setCustomSignalFunc;
