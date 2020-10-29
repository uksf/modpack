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
#define IP 54.36.165.77
#define IP_AND_PORT QUOTE(IP:%1)
#define CONNECTTIMEOUT 3

private _passwordCache = profileNamespace getVariable ['cba_ui_ServerPasswords', [[], []]];
private _port = uiNamespace getVariable [QGVAR(selectedPort), "2302"];
private _index = (_passwordCache#0) find (format [IP_AND_PORT, _port]);
private _password = (_passwordCache#1) param [_index, ''];

if (_password != '') exitWith {
    connectToServer [QUOTE(IP), _port, _password];
};

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
                            ctrlActivate (findDisplay IDD_MULTIPLAYER displayCtrl IDC_CANCEL);
                            onEachFrame {};
                            true
                        };

                        if (_serverData isEqualTo format [IP_AND_PORT, GVAR(directConnectPort)]) exitWith {
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
