class CfgSoundShaders {
	class UKSF_FAMAS_Shot_SoundShader {
		samples[] = {
			{ "\r3f_armes\sons\Famas_1", 1 },
			{ "\r3f_armes\sons\Famas_2", 1 },
			{ "\r3f_armes\sons\Famas_3", 1 }
		};
		volume = 1;
		range = 2000;
		rangeCurve[] = { { 0,1 },{ 100,0.8 },{ 500,0.5 },{ 2000,0 } };
	};
	class UKSF_FAMAS_Shot_Silenced_SoundShader {
		samples[] = {
			{ "A3\sounds_f\weapons\silenced\silent-18", 1 },
			{ "A3\sounds_f\weapons\silenced\silent-19", 1 },
			{ "A3\sounds_f\weapons\silenced\silent-11", 1 }
		};
		volume = 2;
		range = 250;
	};

	class UKSF_FRF2_Shot_SoundShader {
		samples[] = {
			{ "\r3f_armes\Sons\frf2", 1 }
		};
		volume = 1;
		range = 2000;
		rangeCurve[] = { { 0,1 },{ 100,0.9 },{ 500,0.6 },{ 2000,0 } };
	};
	class UKSF_FRF2_Shot_Silenced_SoundShader {
		samples[] = {
			{ "\r3f_armes\Sons\frf2_SD", 1 }
		};
		volume = 2;
		range = 250;
	};
	
	class UKSF_PGM_Shot_SoundShader {
		samples[] = {
			{ "\r3f_armes\Sons\pgm", 1 }
		};
		volume = 2;
		range = 3000;
		rangeCurve[] = { { 0,1 },{ 150,0.8 },{ 500,0.2 },{ 2000,0 } };
	};
	
	class UKSF_Minimi_Shot_SoundShader {
		samples[] = {
			{ "\r3f_armes\Sons\minimi", 1 }
		};
		volume = 1;
		range = 2000;
		rangeCurve[] = { { 0,1 },{ 100,0.8 },{ 500,0.5 },{ 2000,0 } };
	};
	class UKSF_Minimi762_Shot_SoundShader {
		samples[] = {
			{ "\r3f_armes\Sons\minimi762", 1 }
		};
		volume = 1;
		range = 2000;
		rangeCurve[] = { { 0,1 },{ 100,0.9 },{ 500,0.6 },{ 2000,0 } };
	};
};
