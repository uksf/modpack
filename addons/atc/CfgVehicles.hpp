class CBA_Extended_EventHandlers;
class CfgVehicles {
	class Land_PowerGenerator_F;
	class UKSF_ATC_Core: Land_PowerGenerator_F {
		scope = 2;
		scopeCurator = 2;
		author = "UKSF";
		faction = "UKSF_Clan";
		editorSubcategory = "UKSF_Objects";
		displayname = "ATC Core";
		model = "\z\ace\addons\fastroping\data\helper.p3d";
		class EventHandlers {
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
		};
		class ACE_Actions {
			class ACE_MainActions {
				displayName = "ATC Radar";
				position = "";
				condition = "true";
				statement = "";
				showDisabled = 1;
				priority = 1;
				distance = 5;
				class ACE_startRadar {
					displayName = "Start ATC Radar";
					condition = "!(_player getVariable [QQGVAR(isOperator), false]) && !(_target getVariable [QQGVAR(radarOn), false])";
					statement = "[_target, _player] call FUNC(loop);";
					showDisabled = 1;
					priority = 1;
				};
				class ACE_stopRadar {
					displayName = "Stop ATC Radar";
					condition = "(_player == (_target getVariable [QQGVAR(isOperator), objNull])) && (_target getVariable [QQGVAR(radarOn), false])";
					statement = "_target setVariable [QQGVAR(radarOn), false, true]; _player setVariable [QQGVAR(isOperator), false, true];";
					showDisabled = 1;
					priority = 1;
				};
				class ACE_equipPilot {
					displayName = "Equip Pilot";
					condition = "!(_player getVariable [QQGVAR(loadoutPilot), false])";
					statement = "call FUNC(equipPilot);";
					showDisabled = 1;
					priority = 1;
				};
				class ACE_equipATC {
					displayName = "Equip ATC";
					condition = "_player getVariable [QQGVAR(loadoutPilot), true]";
					statement = "call FUNC(equipATC);";
					showDisabled = 1;
					priority = 1;
				};
			};
		};
	};
	class UKSF_ATC_Station: Land_PowerGenerator_F {
		scope = 2;
		scopeCurator = 2;
		author = "UKSF";
		faction = "UKSF_Clan";
		editorSubcategory = "UKSF_Objects";
		displayname = "ATC Station";
		class EventHandlers {
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
		};
	};
};