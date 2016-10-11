class CfgVehicles {

	class Land_PowerGenerator_F;
	class GVAR(core) : Land_PowerGenerator_F {
		scope = 2;
		scopeCurator = 2;
		faction = "UKSF_Clan";
		editorSubcategory = "UKSF_Objects";
		displayname = "ATC Station (Core)";
		author = "UKSF";
		model = "\z\ace\addons\fastroping\data\helper.p3d";
		class EventHandlers {
			class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers {};
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
					condition = "!(_player getVariable [""IsOperator"", false]) && !(_target getVariable [""RadarOn"", false])";
					statement = "[_target, _player] call UKSF_Scripts_ATC_fnc_loop;";
					showDisabled = 1;
					priority = 1;
				};
				class ACE_stopRadar {
					displayName = "Stop ATC Radar";
					condition = "(_player == (_target getVariable [""Operator"", objNull])) && (_target getVariable [""RadarOn"", false])";
					statement = "_target setVariable [""RadarOn"", false, true]; _player setVariable [""IsOperator"", false, true];";
					showDisabled = 1;
					priority = 1;
				};
				class ACE_equipPilot {
					displayName = "Equip Pilot";
					condition = "!(_player getVariable [""LoadOutPilot"", false])";
					statement = "_player call UKSF_Scripts_ATC_fnc_equipPilot";
					showDisabled = 1;
					priority = 1;
				};
				class ACE_equipATC {
					displayName = "Equip ATC";
					condition = "_player getVariable [""LoadOutPilot"", true]";
					statement = "_player call UKSF_Scripts_ATC_fnc_equipATC";
					showDisabled = 1;
					priority = 1;
				};
			};
		};
	};
	class UKSF_ATCStation : Land_PowerGenerator_F {
		scope = 2;
		scopeCurator = 2;
		faction = "UKSF_Clan";
		editorSubcategory = "UKSF_Objects";
		displayname = "ATC Station";
		_generalMacro = "UKSF_ATCStation";
		author = "UKSF";
		class EventHandlers {
			class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers {};
		};
	};
};