#include "script_component.hpp"
#include "\A3\Ui_f\hpp\defineResincl.inc"
/*
    Author:
        Tim Beswick, Gruppe Adler https://github.com/gruppe-adler/gruppe_adler_mod/tree/master/addons/ui

    Description:
        Connect to server

    Parameter(s):
        None

    Return Value:
        Nothing
*/

#define ADDRESS QUOTE(uk-sf.co.uk)
#define IP QUOTE(54.37.244.72:%1)
#define CONNECTTIMEOUT 5

onEachFrame {
    GVAR(directConnectStartTime) = diag_tickTime;
    private _displayMain = findDisplay IDD_MAIN;
    private _ctrlServerBrowser = _displayMain displayCtrl IDC_MAIN_MULTIPLAYER;
    ctrlActivate _ctrlServerBrowser;

    onEachFrame {
        ctrlActivate (findDisplay IDD_MULTIPLAYER displayCtrl IDC_MULTI_TAB_DIRECT_CONNECT);

        onEachFrame {
            private _ctrlServerAddress = findDisplay IDD_IP_ADDRESS displayCtrl 2300;
            _ctrlServerAddress controlsGroupCtrl IDC_IP_ADDRESS ctrlSetText ADDRESS;
            GVAR(directConnectPort) = uiNamespace getVariable [QGVAR(selectedPort), "2302"];
            _ctrlServerAddress controlsGroupCtrl IDC_IP_PORT ctrlSetText GVAR(directConnectPort);

            ctrlActivate (_ctrlServerAddress controlsGroupCtrl IDC_OK);

            onEachFrame {
                private _ctrlServerList = findDisplay IDD_MULTIPLAYER displayCtrl IDC_MULTI_SESSIONS;
                private _exit = for "_i" from 0 to ((lbSize _ctrlServerList) - 1) do {
                    ([_ctrlServerList lbText _i, _ctrlServerList lbData _i]) call {
                        params [["_serverName", ""], ["_serverData", ""]];

                        if (diag_tickTime > (GVAR(directConnectStartTime) + CONNECTTIMEOUT)) exitWith {
                            ERROR_1("direct connect on port %1 timed out", GVAR(directConnectPort));
                            onEachFrame {};
                            true
                        };

                        if (_serverData isEqualTo format [IP, GVAR(directConnectPort)]) exitWith {
                            findDisplay IDD_MULTIPLAYER displayCtrl IDC_MULTI_SESSIONS lbSetCurSel _i;

                            onEachFrame {
                                ctrlActivate (findDisplay IDD_MULTIPLAYER displayCtrl IDC_MULTI_JOIN);

                                onEachFrame {
                                    if (diag_tickTime > GVAR(directConnectStartTime) + CONNECTTIMEOUT) then {
                                        ERROR_1("direct connect on port %1 timed out", GVAR(directConnectPort));
                                        onEachFrame {};
                                    };

                                    if (!isNull findDisplay IDD_PASSWORD) then {
                                        private _display = findDisplay IDD_PASSWORD;
                                        private _passwordEditBoxCtrl = _display displayCtrl IDC_PASSWORD;

                                        // no password saved by CBA --> abort here so user can enter password
                                        if (!isNull _passwordEditBoxCtrl && {ctrlText _passwordEditBoxCtrl == ""}) exitWith {
                                            onEachFrame {};
                                        };
                                        
                                        ctrlActivate (_display displayCtrl IDC_OK);
                                    };

                                    if (getClientStateNumber >= 3) then {
                                        INFO_1("direct connect on port %1 successful", GVAR(directConnectPort));
                                        onEachFrame {};
                                    };
                                };
                            };

                            true
                        };

                        false
                    };

                    if (_exit) exitWith {};
                };
            };
        };
    }
};
