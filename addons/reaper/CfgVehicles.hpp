class CfgNonAIVehicles {
	class ProxyWeapon;
	class ProxyEmpty : ProxyWeapon {
		model = "\A3\weapons_f\Empty";
		simulation = "maverickweapon";
	};
};
class CfgVehicles {
	class Man;
	class CAManBase : Man {
		class ACE_SelfActions {
			class ACE_Drone {
				displayName = "MQ-9 Control";
				condition = QUOTE(!((getConnectedUAV _player) isEqualTo objNull) && (getConnectedUAV _player) isKindOf 'UKSF_MQ9');
				statement = "";
				showDisabled = 1;
				priority = 1;
				icon = QPATHTOF(UI\icon_UKSF_MQ9.paa);
				class ACE_Drone_Behaviour {
					displayName = "Behaviour";
					condition = "";
					statement = "";
					showDisabled = 1;
					priority = 1;
					icon = QPATHTOF(UI\icon_UKSF_MQ9.paa);
					class UAV_Strike_Mode {
						displayName = "Strike";
						condition = QUOTE(!((getConnectedUAV _player) getVariable [ARR_2(QQGVAR(diveMode),false)]));
						statement = QUOTE((getConnectedUAV _player) setVariable [ARR_3(QQGVAR(diveMode),true,true)]; (getConnectedUAV _player) setVariable [ARR_3(QQGVAR(observationMode),false,true)];);
						showDisabled = 1;
						priority = 1;
					};
					class UAV_Observer_Mode {
						displayName = "Observer";
						condition = QUOTE(!((getConnectedUAV _player) getVariable [ARR_2(QQGVAR(observationMode),false)]));
						statement = QUOTE((getConnectedUAV _player) setVariable [ARR_3(QQGVAR(diveMode),false,true)]; (getConnectedUAV _player) setVariable [ARR_3(QQGVAR(observationMode),true,true)];);
						showDisabled = 1;
						priority = 1;
					};
					class UAV_Reset_Mode {
						displayName = "Reset";
						condition = QUOTE((getConnectedUAV _player) getVariable [ARR_2(QQGVAR(diveMode),false)] || (getConnectedUAV _player) getVariable [ARR_2(QQGVAR(observationMode),false)]);
						statement = QUOTE((getConnectedUAV _player) setVariable [ARR_3(QQGVAR(diveMode),false,true)]; (getConnectedUAV _player) setVariable [ARR_3(QQGVAR(observationMode),false,true)];);
						showDisabled = 1;
						priority = 1;
					};
				};
				class ACE_Drone_Altitude {
					displayName = "Altitude";
					condition = "";
					statement = "";
					showDisabled = 1;
					priority = 1;
					icon = QPATHTOF(UI\icon_UKSF_MQ9.paa);
					class UAV_Altitude_1000 {
						displayName = "1000m";
						condition = QUOTE(((getConnectedUAV _player) getVariable QQGVAR(targetHeightASL)) != 1000);
						statement = QUOTE((getConnectedUAV _player) setVariable [ARR_3(QQGVAR(targetHeightASL),1000,true)]; (getConnectedUAV _player) setVariable [ARR_3(QQGVAR(customWaypoint),true,true)];);
						showDisabled = 1;
						priority = 1;
					};
					class UAV_Altitude_1500 {
						displayName = "1500m";
						condition = QUOTE(((getConnectedUAV _player) getVariable QQGVAR(targetHeightASL)) != 1500);
						statement = QUOTE((getConnectedUAV _player) setVariable [ARR_3(QQGVAR(targetHeightASL),1500,true)]; (getConnectedUAV _player) setVariable [ARR_3(QQGVAR(customWaypoint),true,true)];);
						showDisabled = 1;
						priority = 1;
					};
					class UAV_Altitude_2000 {
						displayName = "2000m";
						condition = QUOTE(((getConnectedUAV _player) getVariable QQGVAR(targetHeightASL)) != 2000);
						statement = QUOTE((getConnectedUAV _player) setVariable [ARR_3(QQGVAR(targetHeightASL),2000,true)]; (getConnectedUAV _player) setVariable [ARR_3(QQGVAR(customWaypoint),true,true)];);
						showDisabled = 1;
						priority = 1;
					};
					class UAV_Altitude_100_Plus {
						displayName = "+100m";
						condition = "";
						statement = QUOTE(_height = ((getConnectedUAV _player) getVariable QQGVAR(targetHeightASL)) + 100; (getConnectedUAV _player) setVariable [ARR_3(QQGVAR(targetHeightASL),_height,true)];);
						showDisabled = 1;
						priority = 1;
					};
					class UAV_Altitude_100_Minus {
						displayName = "-100m";
						condition = "";
						statement = QUOTE(_height = ((getConnectedUAV _player) getVariable QQGVAR(targetHeightASL)) - 100; (getConnectedUAV _player) setVariable [ARR_3(QQGVAR(targetHeightASL),_height,true)];);
						showDisabled = 1;
						priority = 1;
					};
					class UAV_Altitude_reset {
						displayName = "Reset";
						condition = QUOTE((getConnectedUAV _player) getVariable [ARR_2(QQGVAR(customWaypoint),false)]);
						statement = QUOTE((getConnectedUAV _player) setVariable [ARR_3(QQGVAR(customWaypoint),false,true)];);
						showDisabled = 1;
						priority = 1;
					};
				};
				class ACE_Drone_Radius {
					displayName = "Loiter Radius";
					condition = QUOTE((waypointType [ARR_2(group (getConnectedUAV _player), currentWaypoint group (getConnectedUAV _player))]) == 'LOITER');
					statement = "";
					showDisabled = 1;
					priority = 1;
					icon = QPATHTOF(UI\icon_UKSF_MQ9.paa);
					class UAV_Radius_1000 {
						displayName = "1000m";
						condition = QUOTE((waypointLoiterRadius [ARR_2(group (getConnectedUAV _player), currentWaypoint group (getConnectedUAV _player))]) != 1000);
						statement = QUOTE([ARR_2(group (getConnectedUAV _player), currentWaypoint group (getConnectedUAV _player))] setWaypointLoiterRadius 1000;);
						showDisabled = 1;
						priority = 1;
					};
					class UAV_Radius_1500 {
						displayName = "1500m";
						condition = QUOTE((waypointLoiterRadius [ARR_2(group (getConnectedUAV _player), currentWaypoint group (getConnectedUAV _player))]) != 1500);
						statement = QUOTE([ARR_2(group (getConnectedUAV _player), currentWaypoint group (getConnectedUAV _player))] setWaypointLoiterRadius 1500;);
						showDisabled = 1;
						priority = 1;
					};
					class UAV_Radius_2000 {
						displayName = "2000m";
						condition = QUOTE((waypointLoiterRadius [ARR_2(group (getConnectedUAV _player), currentWaypoint group (getConnectedUAV _player))]) != 2000);
						statement = QUOTE([ARR_2(group (getConnectedUAV _player), currentWaypoint group (getConnectedUAV _player))] setWaypointLoiterRadius 2000;);
						showDisabled = 1;
						priority = 1;
					};
					class UAV_Radius_100_Plus {
						displayName = "+100m";
						condition = "";
						statement = QUOTE(_radius = (waypointLoiterRadius [ARR_2(group (getConnectedUAV _player), currentWaypoint group (getConnectedUAV _player))]) + 100; [ARR_2(group (getConnectedUAV _player), currentWaypoint group (getConnectedUAV _player))] setWaypointLoiterRadius 2000;);
						showDisabled = 1;
						priority = 1;
					};
					class UAV_Radius_100_Minus {
						displayName = "-100m";
						condition = "";
						statement = QUOTE(_radius = (waypointLoiterRadius [ARR_2(group (getConnectedUAV _player), currentWaypoint group (getConnectedUAV _player))]) - 100; [ARR_2(group (getConnectedUAV _player), currentWaypoint group (getConnectedUAV _player))] setWaypointLoiterRadius 2000;);
						showDisabled = 1;
						priority = 1;
					};
				};
				class ACE_Drone_Waypoint {
					displayName = "Waypoints";
					condition = QUOTE((count (waypoints group (getConnectedUAV _player))) > 1);
					statement = "";
					showDisabled = 1;
					priority = 1;
					icon = QPATHTOF(UI\icon_UKSF_MQ9.paa);
					class UAV_Waypoint_Loiter {
						displayName = "Loiter";
						condition = QUOTE((waypointType [ARR_2(group (getConnectedUAV _player), currentWaypoint group (getConnectedUAV _player))]) != 'LOITER');
						statement = QUOTE([ARR_2(group (getConnectedUAV _player), currentWaypoint group (getConnectedUAV _player))] setWaypointType 'LOITER'; (getConnectedUAV _player) setVariable [ARR_3(QQGVAR(diveMode),false,true)]; (getConnectedUAV _player) setVariable [ARR_3(QQGVAR(observationMode),true,true)];);
						showDisabled = 1;
						priority = 1;
					};
					class UAV_Waypoint_Move {
						displayName = "Move";
						condition = QUOTE((waypointType [ARR_2(group (getConnectedUAV _player), currentWaypoint group (getConnectedUAV _player))]) != 'MOVE');
						statement = QUOTE([ARR_2(group (getConnectedUAV _player), currentWaypoint group (getConnectedUAV _player))] setWaypointType 'MOVE'; (getConnectedUAV _player) setVariable [ARR_3(QQGVAR(diveMode),false,true)]; (getConnectedUAV _player) setVariable [ARR_3(QQGVAR(observationMode),false,true)];);
						showDisabled = 1;
						priority = 1;
					};
					class UAV_Waypoint_MoveToCrosshair {
						displayName = "Move To Crosshair";
						condition = "";
						statement = QUOTE([ARR_2(getConnectedUAV _player, false)] call FUNC(moveTo););
						showDisabled = 1;
						priority = 1;
					};
					class UAV_Waypoint_StrikeCrosshair {
						displayName = "Strike Crosshair";
						condition = "";
						statement = QUOTE([ARR_2(getConnectedUAV _player, true)] call FUNC(moveTo););
						showDisabled = 1;
						priority = 1;
					};
				};
				class ACE_Drone_Compass {
					displayName = "Compass";
					condition = "";
					statement = "";
					showDisabled = 1;
					priority = 1;
					icon = QPATHTOF(UI\icon_UKSF_MQ9.paa);
					class UAV_Compass_On {
						displayName = "On";
						condition = QUOTE(!((getConnectedUAV _player) getVariable [ARR_2(QQGVAR(compassState),false)]));
						statement = QUOTE([ARR_2(getConnectedUAV _player, true)] call FUNC(compass););
						showDisabled = 1;
						priority = 1;
					};
					class UAV_Compass_Off {
						displayName = "Off";
						condition = QUOTE((getConnectedUAV _player) getVariable [ARR_2(QQGVAR(compassState),false)]);
						statement = QUOTE([ARR_2(getConnectedUAV _player, false)] call FUNC(compass););
						showDisabled = 1;
						priority = 1;
					};
				};
			};
		};
	};

	class Plane;
	class UAV : Plane {
		class NewTurret;
		class ViewPilot;
		class ViewOptics;
		class AnimationSources;
	};
	class UKSF_MQ9 : UAV {
		author = "UKSF";
		displayName = "MQ-9 Reaper";
		faction = "UKSF_Clan";
		icon = QPATHTOF(UI\icon_UKSF_MQ9.paa);
		picture = "\A3\Drones_F\Air_F_Gamma\UAV_02\Data\UI\UAV_02_base_F.paa";
	    editorPreview = QPATHTOEF(common,data\previews\UKSF_MQ9.jpg);
		unitInfoType = "RscOptics_AV_pilot";
		attenuationEffectType = "HeliAttenuation";
		_generalMacro = "B_UAV_02_F";
		scope = 2;
		side = 1;
		crew = "B_UAV_AI";
		typicalCargo[] = { "B_UAV_AI" };
		accuracy = 1;
		soundEngineOnInt[] = {"JSRSAPEX_P_Airsounds\UAV_2\Int_Start.ogg",0.75,1};
		soundEngineOnExt[] = {"JSRSAPEX_P_Airsounds\UAV_2\Ext_Start.ogg",0.5,1,300};
		soundEngineOffInt[] = {"JSRSAPEX_P_Airsounds\UAV_2\Int_Off.ogg",0.75,1};
		soundEngineOffExt[] = {"JSRSAPEX_P_Airsounds\UAV_2\Ext_Off.ogg",0.5,1,200};		
		class Sounds {
			class EngineLowOut {
				sound[] = {"JSRSAPEX_P_Airsounds\UAV_2\Ext_Low.ogg",0.5,1,300};
				frequency="1.0 min (rpm + 0.5)";
				volume="camPos*(rpm factor[0.95, 0])*(rpm factor[0, 0.95])";
			};
			class EngineHighOut {
				sound[] = {"JSRSAPEX_P_Airsounds\UAV_2\Ext_High.ogg",0.5,1,300};
				frequency="(rpm factor[0.5, 1.0])";
				volume="camPos*(rpm factor[0.2, 1.0])";
			};
			class ForsageOut {
				sound[] = {"JSRSAPEX_P_Airsounds\UAV_2\Ext_Idle.ogg",0.5,1,800};
				frequency="1";
				volume="engineOn*camPos*(thrust factor[0.6, 1.0])";
				cone[]={3.1400001,3.9200001,2,0.5};
			};
			class WindNoiseOut {
				sound[] = {"JSRSAPEX_P_Airsounds\UAV_2\Distance.ogg",1.9818383,1,2500};
				volume = "1*engineOn*camPos";
				frequency="(0.3+(1.005*(speed factor[1, 50])))";
			};
			class EngineLowIn {
				sound[] = {"JSRSAPEX_P_Airsounds\UAV_2\Int_Low.ogg",0.75,1};
				frequency="1.0 min (rpm + 0.5)";
				volume="(1-camPos)*(rpm factor[0.95, 0])*(rpm factor[0, 0.95])";
			};
			class EngineHighIn {
				sound[] = {"JSRSAPEX_P_Airsounds\UAV_2\Int_Idle.ogg",0.75,1};
				frequency="(rpm factor[0.5, 1.0])";
				volume="(1-camPos)*(rpm factor[0.2, 1.0])";
			};
			class ForsageIn {
				sound[] = {"JSRSAPEX_P_Airsounds\UAV_2\Int_High.ogg",0.75,1.1};
				frequency="1";
				volume="engineOn*(1-camPos)*(thrust factor[0.6, 1.0])";
			};
		};
		formationX = 30;
		formationZ = 30;
		model = "uksf_mq9\UKSF_MQ9.p3d";
		driveOnComponent[] = { "wheel_1_1", "wheel_2_1", "wheel_2_2" };
		class TransportItems {};
		uavCameraDriverPos = "PiP0_pos";
		uavCameraDriverDir = "PiP0_dir";
		uavCameraGunnerPos = "mainturret";
		uavCameraGunnerDir = "maingun";
		memoryPointLDust = "DustLeft";
		memoryPointRDust = "DustRight";
		memoryPointDriverOptics = "PiP0_pos";
		driverOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Driver_F.p3d";
		driverForceOptics = 1;
		class WingVortices {};
		class ViewPilot : ViewPilot {
			initFov = 1;
			minFov = 0.30000001;
			maxFov = 1.2;
			initAngleX = 0;
			minAngleX = -65;
			maxAngleX = 85;
			initAngleY = 0;
			minAngleY = -150;
			maxAngleY = 150;
		};
		class Viewoptics : ViewOptics {
			initAngleX = 0;
			minAngleX = 0;
			maxAngleX = 0;
			initAngleY = 0;
			minAngleY = 0;
			maxAngleY = 0;
			initFov = 1;
			minFov = 0.30000001;
			maxFov = 1.2;
			visionMode[] = { "Normal", "NVG", "Ti" };
			thermalMode[] = { 0,1 };
		};
		class AnimationSources : AnimationSources {
			class Bombs {
				source = "user";
				animPeriod = 1e-006;
				initPhase = 0;
			};
			class AT_missiles {
				source = "user";
				animPeriod = 0.99000001;
				initPhase = 1;
			};
		};
		selectionRotorMove = "propellerBlurred";
		selectionRotorStill = "propellerStatic";
		envelope[] = { 0,0.30000001,1.15,2.2,4.3499999,5.1999998,6,6.5500002,6.6500001,6.8000002,3.5999999,1.8,0 };
		maxSpeed = 382;
		landingSpeed = 85;
		altFullForce = 7000;
		altNoForce = 14000;
		wheelSteeringSensitivity = 5;
		aileronSensitivity = 0.40000001;
		elevatorSensitivity = 0.30000001;
		killFriendlyExpCoef = 0.1;
		driverCompartments = "Compartment3";
		cargoCompartments[] = { "Compartment2" };
		class Damage {
			tex[] = {};
			mat[] = {
				"uksf_mq9\data\UKSF_MQ9.rvmat",
				"uksf_mq9\data\UKSF_MQ9_damage.rvmat",
				"uksf_mq9\data\UKSF_MQ9_destruct.rvmat",
				"uksf_mq9\data\UKSF_MQ9_gearbox.rvmat",
				"uksf_mq9\data\UKSF_MQ9_gearbox_damage.rvmat",
				"uksf_mq9\data\UKSF_MQ9_gearbox_destruct.rvmat",
				"a3\data_f\default.rvmat",
				"a3\data_f\default.rvmat",
				"a3\data_f\default_destruct.rvmat"
			};
		};
		hiddenSelections[] = { "camo1" };
		hiddenSelectionsTextures[] = { "uksf_mq9\data\UKSF_MQ9_co.paa" };
		destrType = "DestructWreck";
		weapons[] = {};
		magazines[] = {};
		LockDetectionSystem = "1 + 8 + 4";
		incomingMissileDetectionSystem = 16;
		laserscanner = 1;
		DriverCanSee = "1 + 2 + 4 + 8 + 16";
		class Turrets {
			class MainTurret : NewTurret {
				isCopilot = 0;
				minElev = -85;
				maxElev = 10;
				initElev = 0;
				minTurn = -360;
				maxTurn = 360;
				initTurn = 0;
				outGunnerMayFire = "true";
				inGunnerMayFire = "true";
				commanding = -1;
				body = "mainTurret";
				gun = "mainGun";
				animationSourceBody = "mainTurret";
				animationSourceGun = "mainGun";
				memoryPointGun = "mainGun";
				memoryPointGunnerOptics = "mainGun";
				gunBeg = "laserend";
				gunEnd = "laserstart";
				gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Gunner_F.p3d";
				gunnerOpticsEffect[] = { "TankCommanderOptics1", "BWTVedit" };
				gunnerForceOptics = "true";
				turretInfoType = "Rsc_UKSF_MQ9_Turret";
				turretCanSee = "1 + 2 + 4 + 8 + 16";
				stabilizedInAxes = 3;
				enableManualFire = 1;
				weapons[] = { "Laserdesignator_mounted", "UK3CB_BAF_HellfireLauncher_K", "UK3CB_BAF_HellfireLauncher_N" };
				magazines[] = { "Laserbatteries", "UK3CB_BAF_4Rnd_Hellfire_K", "UK3CB_BAF_4Rnd_Hellfire_N" };
				GunnerCompartments = "Compartment1";
				gunnerInAction = "Disabled";
				gunnerAction = "Disabled";
				class OpticsIn {
					class WideNGS {
						opticsDisplayName = "W";
						initAngleX = 0;
						minAngleX = -35;
						maxAngleX = 10;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						initFov = 0.466;		minFov = 0.466;			maxFov = 0.466;
						visionMode[] = { "Normal", "NVG", "Ti" };
						thermalMode[] = { 0,1 };
						gunnerOpticsColor[] = { 0.15000001,1,0.15000001,1 };
						gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
						directionStabilized = 0;
						opticsPPEffects[] = { "OpticsCHAbera2", "OpticsBlur2" };
					};
					class Wide {
						opticsDisplayName = "W";
						initAngleX = 0;
						minAngleX = -35;
						maxAngleX = 10;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						initFov = 0.466;		minFov = 0.466;			maxFov = 0.466;
						visionMode[] = { "Normal", "NVG", "Ti" };
						thermalMode[] = { 0,1 };
						gunnerOpticsColor[] = { 0.15000001,1,0.15000001,1 };
						gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_w_F.p3d";
						directionStabilized = 1;
						stabilizedInAxes = 3;
						opticsPPEffects[] = { "OpticsCHAbera2", "OpticsBlur2" };
						gunnerOpticsEffect[] = { "TankCommanderOptics1", "BWTVedit" };
					};
					class WideL : Wide {
						opticsDisplayName = "WL";
						initFov = 0.2;
						minFov = 0.2;
						maxFov = 0.2;
						gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_m_F.p3d";
						gunnerOpticsColor[] = { 0,0,0,1 };
						directionStabilized = 1;
						stabilizedInAxes = 3;
						opticsPPEffects[] = { "OpticsCHAbera2", "OpticsBlur2" };
					};
					class Medium : Wide {
						opticsDisplayName = "M";
						initFov = 0.094;		minFov = 0.094;			maxFov = 0.094;
						directionStabilized = 1;
						stabilizedInAxes = 3;
						gunnerOpticsColor[] = { 0,0,0,1 };
						gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_m_F.p3d";
					};
					class Narrow : Wide {
						opticsDisplayName = "N";
						gunnerOpticsColor[] = { 0,0,0,1 };
						gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_n_F.p3d";
						directionStabilized = 1;
						stabilizedInAxes = 3;
						initFov = 0.019;		minFov = 0.019;			maxFov = 0.019;
					};
					class Narrower : Wide {
						opticsDisplayName = "N";
						gunnerOpticsColor[] = { 0,0,0,1 };
						gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_n_F.p3d";
						directionStabilized = 1;
						stabilizedInAxes = 3;
						initFov = 0.006;		minFov = 0.006;			maxFov = 0.006;		
					};
				};
				class OpticsOut {
					class Monocular {
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						initFov = 1.1;
						minFov = 0.133;
						maxFov = 1.1;
						visionMode[] = { "Normal", "NVG" };
						gunnerOpticsModel = "";
						gunnerOpticsEffect[] = {};
					};
				};
			};
		};
		class Reflectors {
			class Left {
				color[] = { 7000,7500,10000,1 };
				ambient[] = { 100,100,100,0 };
				position = "light_1_pos";
				direction = "light_1_dir";
				hitpoint = "L svetlo";
				selection = "L svetlo";
				size = 1;
				innerAngle = 20;
				outerAngle = 60;
				coneFadeCoef = 10;
				intensity = 50;
				useFlare = 1;
				dayLight = 0;
				FlareSize = 4;
				class Attenuation {
					start = 1;
					constant = 0;
					linear = 0;
					quadratic = 4;
				};
			};
		};
		class MarkerLights {
			class RedStill {
				name = "cerveny pozicni";
				color[] = { 0.80000001,0,0 };
				ambient[] = { 0.079999998,0,0 };
				intensity = 75;
				drawLight = 1;
				drawLightSize = 0.15000001;
				drawLightCenterSize = 0.039999999;
				activeLight = 0;
				blinking = 0;
				dayLight = 0;
				useFlare = 0;
			};
			class GreenStill {
				name = "zeleny pozicni";
				color[] = { 0,0.80000001,0 };
				ambient[] = { 0,0.079999998,0 };
				intensity = 75;
				drawLight = 1;
				drawLightSize = 0.15000001;
				drawLightCenterSize = 0.039999999;
				activeLight = 0;
				blinking = 0;
				dayLight = 0;
				useFlare = 0;
			};
			class WhiteBlinking {
				name = "bily pozicni blik";
				color[] = { 1,1,1,1 };
				ambient[] = { 0.2,0.2,0.2,1 };
				intensity = 75;
				blinking = 1;
				blinkingPattern[] = { 0.1,0.89999998 };
				blinkingPatternGuarantee = 0;
				drawLightSize = 0.2;
				drawLightCenterSize = 0.039999999;
			};
			class WhiteBlinking2 {
				name = "bily pozicni blik2";
				color[] = { 1,1,1,1 };
				ambient[] = { 0.2,0.2,0.2,1 };
				intensity = 75;
				blinking = 1;
				blinkingPattern[] = { 0.1,0.89999998 };
				blinkingPatternGuarantee = 0;
				drawLightSize = 0.2;
				drawLightCenterSize = 0.039999999;
			};
		};
		class CamShake {
			power = 0;
			frequency = 0;
			distance = 0;
			minSpeed = 1000;
		};
		class camShakeGForce {
			power = 0;
			frequency = 0;
			distance = 0;
			minSpeed = 1000;
		};
		class camShakeDamage {
			power = 0;
			frequency = 0;
			distance = 0;
			minSpeed = 1;
			attenuation = 0;
			duration = 0;
		};
	};
};