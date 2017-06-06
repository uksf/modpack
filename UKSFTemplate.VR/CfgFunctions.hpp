class CfgFunctions {
	class uksf_spawn {
		class spawn {
			file = "functions\spawn";
			class postInit { file = "postInit.sqf"; postInit = 1; };
			class getGroups {};
            class initPatrol {};
            class assignID {};
			class selectGroup {};
			class spawnGroup {};
		};
	};
	class uksf_support {
		class support {
			file = "functions\support";
			class nearbySupport {};
			class reTask {};
		};
	};
};
