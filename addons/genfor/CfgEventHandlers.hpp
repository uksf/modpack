
class Extended_Init_EventHandlers {
	class Genfor_Air_MI8_Populated {
		class ADDON {
			init = QUOTE([ARR_3(_this select 0,[ARR_14('GENFOR_P_SL', 'GENFOR_P_R', 'GENFOR_P_R', 'GENFOR_P_R', 'GENFOR_P_MG', 'GENFOR_P_AT', 'GENFOR_P_Mark', 'GENFOR_P_B', 'GENFOR_P_ATR', 'GENFOR_P_AA', 'GENFOR_P_MG', 'GENFOR_P_MG', 'GENFOR_P_Mark', 'GENFOR_MED')], [ARR_2(0, 1))]] call EFUNC(common,populate));
		};
	};
	class Genfor_Air_MI8MTV_Populated {
		class ADDON {
			init = QUOTE([ARR_3(_this select 0,[ARR_14('GENFOR_P_SL', 'GENFOR_P_R', 'GENFOR_P_R', 'GENFOR_P_R', 'GENFOR_P_MG', 'GENFOR_P_AT', 'GENFOR_P_Mark', 'GENFOR_P_B', 'GENFOR_P_ATR', 'GENFOR_P_AA', 'GENFOR_P_MG', 'GENFOR_P_MG', 'GENFOR_P_Mark', 'GENFOR_MED')], [ARR_2(0, 1))]] call EFUNC(common,populate));
		};
	};
	class Genfor_Hilux_Unarmed_Populated {
		class ADDON {
			init = QUOTE([ARR_2(_this select 0,[ARR_5('GENFOR_SL', 'GENFOR_R', 'GENFOR_MG', 'GENFOR_AT_18', 'GENFOR_Mark')])] call EFUNC(common,populate));
		};
	};
	class Genfor_Hilux_Unarmed_Reserves_Populated {
		class ADDON {
			init = QUOTE([ARR_2(_this select 0,[ARR_5('GENFOR_Res_L', 'GENFOR_Res', 'GENFOR_Res', 'GENFOR_Res_R', 'GENFOR_Res_R')])] call EFUNC(common,populate));
		};
	};
	class Genfor_Hmmwv_Unarmed_SF_Populated {
		class ADDON {
			init = QUOTE([ARR_2(_this select 0,[ARR_3('GENFOR_SF_SL', 'GENFOR_SF_R', 'GENFOR_SF_MG')])] call EFUNC(common,populate));
		};
	};
	class Genfor_Hmmwv_Unarmed_Desert_SF_Populated {
		class ADDON {
			init = QUOTE([ARR_2(_this select 0,[ARR_3('GENFOR_SF_SL', 'GENFOR_SF_R', 'GENFOR_SF_MG')])] call EFUNC(common,populate));
		};
	};
	class Genfor_LandRover_Unarmed_Populated {
		class ADDON {
			init = QUOTE([ARR_2(_this select 0,[ARR_7('GENFOR_SL', 'GENFOR_R', 'GENFOR_R', 'GENFOR_MG', 'GENFOR_AR', 'GENFOR_Mark', 'GENFOR_AT')])] call EFUNC(common,populate));
		};
	};
	class Genfor_LandRover_Unarmed_Para_Populated {
		class ADDON {
			init = QUOTE([ARR_2(_this select 0,[ARR_7('GENFOR_P_SL', 'GENFOR_P_R', 'GENFOR_P_R', 'GENFOR_P_MG', 'GENFOR_P_MG', 'GENFOR_P_Mark', 'GENFOR_P_AT')])] call EFUNC(common,populate));
		};
	};
	class Genfor_Uaz_Unarmed_Populated {
		class ADDON {
			init = QUOTE([ARR_2(_this select 0,[ARR_6('GENFOR_SL', 'GENFOR_R',  'GENFOR_R', 'GENFOR_MG', 'GENFOR_AR', 'GENFOR_Mark')])] call EFUNC(common,populate));
		};
	};
	class Genfor_Ural_Transport_Populated {
		class ADDON {
			init = QUOTE([ARR_2(_this select 0,[ARR_12('GENFOR_SL', 'GENFOR_R',  'GENFOR_R', 'GENFOR_R', 'GENFOR_AR', 'GENFOR_MG', 'GENFOR_AR', 'GENFOR_MG', 'GENFOR_AA', 'GENFOR_AT', 'GENFOR_RTO', 'GENFOR_Mark')])] call EFUNC(common,populate));
		};
	};
	class Genfor_Ural_TransportOpen_Populated {
		class ADDON {
			init = QUOTE([ARR_2(_this select 0,[ARR_12('GENFOR_SL', 'GENFOR_R',  'GENFOR_R', 'GENFOR_R', 'GENFOR_AR', 'GENFOR_MG', 'GENFOR_AR', 'GENFOR_MG', 'GENFOR_AA', 'GENFOR_AT', 'GENFOR_RTO', 'GENFOR_Mark')])] call EFUNC(common,populate));
		};
	};

	class GENFOR_Soldier_Base {
		class ADDON {
			init = QUOTE(_this call EFUNC(common,random));
		};
	};
};