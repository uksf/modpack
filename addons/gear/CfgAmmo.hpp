class CfgAmmo{
	class B_762x51_Ball;
	class B_762x51_Tracer_Red;
	class UK3CB_BAF_762_Ball: B_762x51_Ball {
		ACE_bulletMass = 10.0438;
		hit = 14;
		caliber = 1.6;
	};
	class UK3CB_BAF_762_Ball_Tracer_Red: B_762x51_Tracer_Red {
		ACE_bulletMass = 10.0438;
		hit = 14;
		caliber = 1.6;
	};
	class UK3CB_BAF_762_Ball_EL: UK3CB_BAF_762_Ball {
		hit = 12;
		tracerEndTime = 4.15957;
	};
	class UK3CB_BAF_762_Ball_Tracer_Red_EL: UK3CB_BAF_762_Ball_Tracer_Red {
		hit = 12;
		tracerEndTime = 4.15957;
	};
};