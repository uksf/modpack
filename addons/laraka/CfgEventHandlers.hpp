
class Extended_Init_EventHandlers {
	class Laraka_RPG {
		class ADDON {
			init = QUOTE([_this] call EFUNC(common,randomIgla));
		};
	};
	class Laraka_Special_Suicide {
		class ADDON {
			init = QUOTE([ARR_4(_this select 0, west, false, false)] call EFUNC(common,suicide));
		};
	};
	class Laraka_Special_SuicideDeadman {
		class ADDON {
			init = QUOTE([ARR_4(_this select 0, west, true, false)] call EFUNC(common,suicide));
		};
	};
	class Laraka_Special_SuicideDiscrete {
		class ADDON {
			init = QUOTE([ARR_4(_this select 0, west, false, true)] call EFUNC(common,suicide));
		};
	};
	class Laraka_Special_SuicideDiscreteDeadman {
		class ADDON {
			init = QUOTE([ARR_4(_this select 0, west, true, true)] call EFUNC(common,suicide));
		};
	};
	class Laraka_Hilux_Unarmed_Populated {
		class ADDON {
			init = QUOTE([ARR_2(_this select 0,[ARR_5('Laraka_L', 'Laraka_AK', 'Laraka_AK', 'Laraka_PKM', 'Laraka_RPG')])] call EFUNC(common,populate));
		};
	};
	class Laraka_Uaz_Unarmed_Populated {
		class ADDON {
			init = QUOTE([ARR_2(_this select 0,[ARR_6('Laraka_L', 'Laraka_AK', 'Laraka_AK', 'Laraka_PKM', 'Laraka_RPG', 'Laraka_Warlord')])] call EFUNC(common,populate));
		};
	};
	class Laraka_CarBomb {
		class ADDON {
			init = QUOTE([ARR_3(_this select 0, west, false)] call EFUNC(common,carbomb));
		};
	};
	class Laraka_CarBomb_Deadman {
		class ADDON {
			init = QUOTE([ARR_3(_this select 0, west, true)] call EFUNC(common,carbomb));
		};
	};
	class Laraka_CarBomb_Empty {
		class ADDON {
			init = QUOTE([ARR_2(_this select 0, east)] call EFUNC(common,carbombEmpty));
		};
	};
	class Azaadi_RPG {
		class ADDON {
			init = QUOTE([_this] call EFUNC(common,randomIgla));
		};
	};
	class Azaadi_Special_Suicide {
		class ADDON {
			init = QUOTE([ARR_4(_this select 0, east, false, false)] call EFUNC(common,suicide));
		};
	};
	class Azaadi_Special_SuicideDeadman {
		class ADDON {
			init = QUOTE([ARR_4(_this select 0, east, true, false)] call EFUNC(common,suicide));
		};
	};
	class Azaadi_Special_SuicideDiscrete {
		class ADDON {
			init = QUOTE([ARR_4(_this select 0, east, false, true)] call EFUNC(common,suicide));
		};
	};
	class Azaadi_Special_SuicideDiscreteDeadman {
		class ADDON {
			init = QUOTE([ARR_4(_this select 0, east, true, true)] call EFUNC(common,suicide));
		};
	};
	class Azaadi_Hilux_Unarmed_Populated {
		class ADDON {
			init = QUOTE([ARR_4(_this select 0,[ARR_5('Azaadi_L', 'Azaadi_AK', 'Azaadi_AK', 'Azaadi_PKM', 'Azaadi_RPG')], [], 2)] call EFUNC(common,populate));
		};
	};
	class Azaadi_Uaz_Unarmed_Populated {
		class ADDON {
			init = QUOTE([ARR_4(_this select 0,[ARR_6('Azaadi_L', 'Azaadi_AK', 'Azaadi_AK', 'Azaadi_PKM', 'Azaadi_RPG', 'Azaadi_Warlord')], [], 2)] call EFUNC(common,populate));
		};
	};
	class Azaadi_CarBomb {
		class ADDON {
			init = QUOTE([ARR_3(_this select 0, east, false)] call EFUNC(common,carbomb));
		};
	};
	class Azaadi_CarBomb_Deadman {
		class ADDON {
			init = QUOTE([ARR_3(_this select 0, east, true)] call EFUNC(common,carbomb));
		};
	};
	class Azaadi_CarBomb_Empty {
		class ADDON {
			init = QUOTE([ARR_2(_this select 0, west)] call EFUNC(common,carbombEmpty));
		};
	};
};