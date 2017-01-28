/*
    Author:
        Tim Beswick

    Description:
        Selects group from given faction

    Parameters:
        0: Faction Name <SCALAR>

    Return value:
        Array of units <ARRAY>
		
    Called from:
        _selectedGroup = ["Inegal"] call UKSF_Mission_fnc_selectGroup;
*/
params ["_factionName", "_selectedGroup"];

_rand = random 10;
switch (_rand) do {
    default {
        switch (_factionName) do {
		    case ("Genfor"): {
				_randomUnit = selectRandom ["4","6","8","10","6_Res","4_Res","ATSquad","MGSquad","InfSection","SniperTeam"];
				_selectedGroup = call compile format ["(configFile >> ""CfgGroups"" >> ""East"" >> ""UKSF_Genfor"" >> ""Infantry"" >> ""Genfor_%1"")", _randomUnit];
		    };
			case ("Laraka"): {
				_randomUnit = selectRandom ["2","4","6","8","10"];
				_selectedGroup = call compile format ["(configFile >> ""CfgGroups"" >> ""East"" >> ""UKSF_Laraka"" >> ""Infantry"" >> ""Laraka_%1"")", _randomUnit];
		    };
			case ("Inegal"): {
				_randomUnit = selectRandom ["4","6","8","10","4_Rec","6_Rec","AATeam","ATSquad","InfSection","MGSquad","SniperTeam","SuppSection"];
				_selectedGroup = call compile format ["(configFile >> ""CfgGroups"" >> ""East"" >> ""UKSF_Inegal"" >> ""Infantry"" >> ""Inegal_%1"")", _randomUnit];
		    };
			default {
			    _selectedGroup = [];
			};
		};
    };
	case (10): {
		switch (_factionName) do {
		    case ("Genfor"): {
				_randomUnit = selectRandom ["6_Para","4_Para","6_SF","4_SF","2_SF"];
				_selectedGroup = call compile format ["(configFile >> ""CfgGroups"" >> ""East"" >> ""UKSF_Genfor"" >> ""SpecOps"" >> ""Genfor_%1"")", _randomUnit];
		    };
			case ("Laraka"): {
				_randomUnit = selectRandom ["2","4","6","8","10"];
				_selectedGroup = call compile format ["(configFile >> ""CfgGroups"" >> ""East"" >> ""UKSF_Laraka"" >> ""Infantry"" >> ""Laraka_%1"")", _randomUnit];
		    };
			case ("Inegal"): {
				_randomUnit = selectRandom ["4","6","8","10","4_Rec","6_Rec","AATeam","ATSquad","InfSection","MGSquad","SniperTeam","SuppSection"];
				_selectedGroup = call compile format ["(configFile >> ""CfgGroups"" >> ""East"" >> ""UKSF_Inegal"" >> ""SpecOps"" >> ""Inegal_%1"")", _randomUnit];
		    };
			default {
			    _selectedGroup = [];
			};
		};
	};
};

_selectedGroup