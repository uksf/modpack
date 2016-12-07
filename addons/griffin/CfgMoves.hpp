class CfgMovesBasic {
	class DefaultDie;
	class ManActions {
		UH1Y_Pilot = "UH1Y_Pilot";
		UH1Y_Gunner = "UH1Y_Gunner";
		UH1Y_Gunner02 = "UH1Y_Gunner02";
		UH1Y_Cargo01 = "UH1Y_Cargo01";
		UH1Y_Cargo02 = "UH1Y_Cargo02";
		UH1Y_Cargo03 = "UH1Y_Cargo03";
	};
};
class CfgMovesMaleSdr : CfgMovesBasic {
	class States {
		class Crew;
		class KIA_UH1Y_Pilot : DefaultDie {
			actions = "DeadActions";
			file = QPATHTOF(anims\KIA_UH1Y_Pilot.rtm);
			speed = 0.5;
			looped = 0;
			terminal = 1;
			soundEnabled = 0;
			connectTo[] = { "Unconscious", 0.1 };
		};
		class UH1Y_Pilot : Crew {
			file = QPATHTOF(anims\UH1Y_Pilot.rtm);
			interpolateTo[] = { "KIA_UH1Y_Pilot", 1 };
		};
		class KIA_UH1Y_Gunner : DefaultDie {
			actions = "DeadActions";
			file = QPATHTOF(anims\KIA_UH1Y_Gunner01.rtm);
			speed = 0.5;
			looped = 0;
			terminal = 1;
			soundEnabled = 0;
			connectTo[] = { "Unconscious", 0.1 };
		};
		class UH1Y_Gunner : Crew {
			file = QPATHTOF(anims\UH1Y_Gunner.rtm);
			interpolateTo[] = { "KIA_UH1Y_Gunner", 1 };
		};
		class KIA_UH1Y_Gunner02 : DefaultDie {
			actions = "DeadActions";
			file = QPATHTOF(anims\KIA_UH1Y_Pilot.rtm);
			speed = 0.5;
			looped = 0;
			terminal = 1;
			soundEnabled = 0;
			connectTo[] = { "Unconscious", 0.1 };
		};
		class UH1Y_Gunner02 : Crew {
			file = QPATHTOF(anims\UH1Y_Pilot.rtm);
			interpolateTo[] = { "KIA_UH1Y_Gunner02", 1 };
		};
		class KIA_UH1Y_Cargo01 : DefaultDie {
			actions = "DeadActions";
			file = QPATHTOF(anims\KIA_cargo_01.rtm);
			speed = 0.5;
			looped = 0;
			terminal = 1;
			soundEnabled = 0;
			connectTo[] = { "Unconscious", 0.1 };
		};
		class UH1Y_Cargo01 : Crew {
			file = QPATHTOF(anims\cargo_01.rtm);
			interpolateTo[] = { "KIA_UH1Y_Cargo01", 0.1 };
			connectTo[] = { "UH1Y_Cargo01", 0.30000001, "UH1Y_Cargo01_V1", 0.1, "UH1Y_Cargo01_V2", 0.1, "UH1Y_Cargo01_V3", 0.1 };
			equivalentTo = "UH1Y_Cargo01";
			variantsAI[] = { "UH1Y_Cargo01", 0.40000001, "UH1Y_Cargo01_V1", 0.2, "UH1Y_Cargo01_V2", 0.2, "UH1Y_Cargo01_V3", 0.2 };
			variantAfter[] = { 5,10,20 };
			speed = 0.30000001;
		};
		class UH1Y_Cargo01_V1 : UH1Y_Cargo01 {
			file = QPATHTOF(anims\cargo_01nadech.rtm);
			interpolateTo[] = { "KIA_UH1Y_Cargo01", 1 };
			connectTo[] = { "UH1Y_Cargo01", 0.1 };
			speed = 0.39500001;
			looped = 0;
			variantAfter[] = { 5,5,5 };
		};
		class UH1Y_Cargo01_V2 : UH1Y_Cargo01_V1 {
			file = QPATHTOF(anims\cargo_01poposed.rtm);
			speed = 0.588;
		};
		class UH1Y_Cargo01_V3 : UH1Y_Cargo01_V1 {
			file = QPATHTOF(anims\cargo_01presunruky.rtm);
			speed = 0.491;
		};
		class KIA_UH1Y_Cargo02 : KIA_UH1Y_Cargo01 {
			file = QPATHTOF(anims\KIA_cargo_02.rtm);
		};
		class UH1Y_Cargo02 : Crew {
			file = QPATHTOF(anims\cargo_02.rtm);
			interpolateTo[] = { "KIA_UH1Y_Cargo02", 0.1 };
			connectTo[] = { "UH1Y_Cargo02", 0.30000001, "UH1Y_Cargo02_V1", 0.1, "UH1Y_Cargo02_V2", 0.1, "UH1Y_Cargo02_V3", 0.1 };
			equivalentTo = "UH1Y_Cargo02";
			variantsAI[] = { "UH1Y_Cargo02", 0.40000001, "UH1Y_Cargo02_V1", 0.2, "UH1Y_Cargo02_V2", 0.2, "UH1Y_Cargo02_V3", 0.2 };
			variantAfter[] = { 5,10,20 };
			speed = 0.30000001;
		};
		class UH1Y_Cargo02_V1 : UH1Y_Cargo02 {
			file = QPATHTOF(anims\cargo_02poposed.rtm);
			interpolateTo[] = { "KIA_UH1Y_Cargo02", 1 };
			connectTo[] = { "UH1Y_Cargo02", 0.1 };
			speed = 0.65200001;
			looped = 0;
			variantAfter[] = { 5,5,5 };
		};
		class UH1Y_Cargo02_V2 : UH1Y_Cargo02_V1 {
			file = QPATHTOF(anims\cargo_02predklon.rtm);
			speed = 0.3125;
		};
		class UH1Y_Cargo02_V3 : UH1Y_Cargo02_V1 {
			file = QPATHTOF(anims\cargo_02presunruky.rtm);
			speed = 0.37;
		};
		class KIA_UH1Y_Cargo03 : KIA_UH1Y_Cargo01 {
			file = QPATHTOF(anims\KIA_cargo_03.rtm);
		};
		class UH1Y_Cargo03 : Crew {
			file = QPATHTOF(anims\cargo_03.rtm);
			interpolateTo[] = { "KIA_UH1Y_Cargo03", 0.1 };
			connectTo[] = { "UH1Y_Cargo03", 0.30000001, "UH1Y_Cargo03_V1", 0.1, "UH1Y_Cargo03_V2", 0.1, "UH1Y_Cargo03_V3", 0.1 };
			equivalentTo = "UH1Y_Cargo03";
			variantsAI[] = { "UH1Y_Cargo03", 0.40000001, "UH1Y_Cargo03_V1", 0.1, "UH1Y_Cargo03_V2", 0.25, "UH1Y_Cargo03_V3", 0.25 };
			variantAfter[] = { 5,10,20 };
			speed = 0.30000001;
		};
		class UH1Y_Cargo03_V1 : UH1Y_Cargo03 {
			file = QPATHTOF(anims\cargo_03predklon.rtm);
			interpolateTo[] = { "KIA_UH1Y_Cargo03", 1 };
			connectTo[] = { "UH1Y_Cargo03", 0.1 };
			speed = 0.37;
			looped = 0;
			variantAfter[] = { 5,5,5 };
		};
		class UH1Y_Cargo03_V2 : UH1Y_Cargo03_V1 {
			file = QPATHTOF(anims\cargo_03presunruky.rtm);
			speed = 0.37;
			variantAfter[] = { 5,5,5 };
		};
		class UH1Y_Cargo03_V3 : UH1Y_Cargo03_V1 {
			file = QPATHTOF(anims\cargo_03protazenizad.rtm);
			speed = 0.491;
			variantAfter[] = { 5,5,5 };
		};
	};
};