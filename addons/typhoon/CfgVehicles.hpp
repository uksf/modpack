class DefaultVehicleSystemsDisplayManagerRight;
class DefaultVehicleSystemsDisplayManagerLeft;
class SensorTemplateActiveRadar;
class SensorTemplateAntiRadiation;
class SensorTemplateIR;
class SensorTemplateLaser;
class SensorTemplateMan;
class SensorTemplateNV;
class SensorTemplatePassiveRadar;
class SensorTemplateVisual;
class SensorTemplateDataLink;
class CfgVehicles {
    class Plane_Base_F;
    class Plane_Fighter_01_Base_F;
	class B_Plane_Fighter_01_F: Plane_Fighter_01_Base_F {
        class EventHandlers;
    };
    class pook_EF2000: B_Plane_Fighter_01_F {
        class textureSources {};
        textureList[] = {};
		brakeDistance = 200; // 150
		acceleration = 500; // 475
		maxSpeed = 2495; // 1500
		fuelCapacity = 1500; // 500     
        draconicTorqueXCoef[] = {4, 5.1, 6.1, 7, 7.7, 8.3, 9, 9.1, 9.2, 9.2, 9.2};
        draconicTorqueYCoef[] = {5.5, 4, 2, 0.5, 0.1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        thrustCoef[] = {1.76, 1.69, 1.62, 1.68, 1.89, 1.96, 2.11, 2.15, 2.05, 1.96, 1.92, 1.62, 1.4, 1.2, 1.1, 0};
        envelope[] = {0, 0.43, 0.97, 1.72, 2.69, 3.87, 5.27, 6.89, 8.72, 9.7, 9.6, 9.2, 8.5, 8.2, 8, 8};
		class ViewPilot {
			initFov = 0.7;
			minFov = 0.25;
			maxFov = 1;
			initAngleX = 0;
			minAngleX = -75;
			maxAngleX = 85;
			initAngleY = 0;
			minAngleY = -170;
			maxAngleY = 170;
            minMoveX = -0.2;
            maxMoveX = 0.2;
            minMoveY = -0.025;
            maxMoveY = 0.1;
            minMoveZ = -0.2;
            maxMoveZ = 0.2;
            speedZoomMaxSpeed = 0;
            speedZoomMaxFOV = 1;
		};
		class pilotCamera {
			class OpticsIn {
				class Wide {
					opticsDisplayName = "WFOV";
					initAngleX = 0;
					minAngleX = 0;
					maxAngleX = 0;
					initAngleY = 0;
					minAngleY = 0;
					maxAngleY = 0;
					initFov = "(75 / 120)";
					minFov = "(75 / 120)";
					maxFov = "(75 / 120)";
					directionStabilized = 1;
					visionMode[] = {"Normal", "NVG", "Ti"};
					thermalMode[] = {0, 1};
					gunnerOpticsModel = "\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
					opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
				};
				class Medium: Wide {
					opticsDisplayName = "MFOV";
					initFov = "(30 / 120)";
					minFov = "(30 / 120)";
					maxFov = "(30 / 120)";
					gunnerOpticsModel = "\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_medium_F.p3d";
				};
				class Small: Wide {
					opticsDisplayName = "SFOV";
					initFov = "(6 / 120)";
					minFov = "(6 / 120)";
					maxFov = "(6 / 120)";
					gunnerOpticsModel = "\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_medium_F.p3d";
				};
				class Narrow: Wide {
					opticsDisplayName = "NFOV";
					initFov = "(2 / 120)";
					minFov = "(2 / 120)";
					maxFov = "(2 / 120)";
					gunnerOpticsModel = "\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
				};
				showMiniMapInOptics = 1;
				showUAVViewInOptics = 0;
				showSlingLoadManagerInOptics = 0;
			};
			minTurn = -180;
			maxTurn = 180;
			initTurn = 0;
			minElev = -10;
			maxElev = 90;
			initElev = 25;
            maxXRotSpeed = 1;
            maxYRotSpeed = 1;
            maxMouseXRotSpeed = 0.5;
            maxMouseYRotSpeed = 0.5;
            pilotOpticsShowCursor = 1;
            controllable = 1;
		};
        epeImpulseDamageCoef = 5;
		armor = 60;
        lockDetectionSystem = "4 + 8";
        incomingMissileDetectionSystem = "8 + 16";
        altFullForce = 8000;
        altNoForce = 19812;
		insideSoundCoef = 0.0316228;
        soundEngineOnInt[] = {QPATHTOF(data\sounds\typhoon_engine_start_int), 1, 1};
        soundEngineOnExt[] = {QPATHTOF(data\sounds\typhoon_engine_start_ext), 1.75, 1, 500};
        soundEngineOffInt[] = {QPATHTOF(data\sounds\typhoon_engine_stop_int), 1, 1};
        soundEngineOffExt[] = {QPATHTOF(data\sounds\typhoon_engine_stop_ext), 1.75, 1, 500};
        soundGetIn[] = {"A3\Sounds_F\vehicles\air\CAS_01\getin_wipeout", 1, 1, 40};
        soundGetOut[] = {"A3\Sounds_F\air\Plane_Fighter_03\getout", 1, 1, 40};
        cabinOpenSound[] = {"A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_01\FX_Plane_Fighter_01_cabine_open_ext", 3.16228, 1, 40};
        cabinCloseSound[] = {"A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_01\FX_Plane_Fighter_01_cabine_close_ext", 3.16228, 1, 40};
        cabinOpenSoundInternal[] = {"A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_01\FX_Plane_Fighter_01_cabine_open_int", 10, 1, 40};
        cabinCloseSoundInternal[] = {"A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_01\FX_Plane_Fighter_01_cabine_close_int", 10, 1, 40};
        soundLocked[] = {"A3\Sounds_F_Jets\vehicles\air\Shared\FX_Plane_Jet_lockedOn1", 1, 1};
        soundIncommingMissile[] = {QPATHTOF(data\sounds\incoming), 1, 1.5};
        soundSetSonicBoom[] = {QGVAR(soundSet_sonicBoom)};
        class Sounds {
            soundSets[] = {
                QGVAR(soundSet_engineLowExt),
                QGVAR(soundSet_engineHighExt),
                QGVAR(soundSet_forsageExt),
                QGVAR(soundSet_engineLowInt),
                QGVAR(soundSet_engineHighInt),
                QGVAR(soundSet_forsageInt),
                "Plane_Fighter_02_EngineExt_Middle_SoundSet",
                "Plane_Fighter_02_EngineExt_Dist_Front_SoundSet",
                "Plane_Fighter_02_EngineExt_Dist_Rear_SoundSet",
                "Plane_Fighter_02_WindNoiseExt_SoundSet",
                "Plane_Fighter_02_WindNoiseInt_SoundSet",
                "Plane_Fighter_02_VelocityInt_SoundSet"
            };
        };
        class Components {
			class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
				defaultDisplay = "MinimapDisplay";
				class Components {
					class SensorDisplay {
						componentType = "SensorsDisplayComponent";
						range[] = {64000,32000,16000,8000,4000,2000};
						resource = "RscCustomInfoSensors";
					};
                    class MinimapDisplay {
                        componentType = "MinimapDisplayComponent";
                        resource = "RscCustomInfoMiniMap";
                    };
					class VehicleMissileDisplay {
						componentType = "TransportFeedDisplayComponent";
						source = "Missile";
					};
					class VehiclePrimaryGunnerDisplay {
						componentType = "TransportFeedDisplayComponent";
						source = "PrimaryGunner";
					};
					class EmptyDisplay {
						componentType = "EmptyDisplayComponent";
					};
				};
			};
			class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight {
				defaultDisplay = "SensorsDisplay";
				class Components {
					class SensorsDisplay {
						componentType = "SensorsDisplayComponent";
						range[] = {64000,32000,16000,8000,4000,2000};
						resource = "RscCustomInfoSensors";
					};
					class MinimapDisplay {
						componentType = "MinimapDisplayComponent";
						resource = "RscCustomInfoMiniMap";
					};
					class VehicleMissileDisplay {
						componentType = "TransportFeedDisplayComponent";
						source = "Missile";
					};
					class EmptyDisplay {
						componentType = "EmptyDisplayComponent";
					};
				};
			};
			class SensorsManagerComponent {
				class Components {
					class ActiveRadarComponent: SensorTemplateActiveRadar {
						class AirTarget {
							maxRange = 64000;
							minRange = 64000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						class GroundTarget {
							maxRange = 32000;
							minRange = 32000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						aimDown = 0;
						animDirection = "";
						allowsMarking = 1;
						angleRangeHorizontal = 60;
						angleRangeVertical = 60;
						groundNoiseDistanceCoef = 0.1;
						maxGroundNoiseDistance = 200;
						maxSpeedThreshold = 40;
						maxTrackableATL = -1;
						maxTrackableSpeed = -1;
						minSpeedThreshold = 0;
						minTrackableATL = -1;
						minTrackableSpeed = -1;
						typeRecognitionDistance = 64000;
					};
					class IRSensorComponent: SensorTemplateIR {
						allowsMarking = 1;
						angleRangeHorizontal = 26;
						angleRangeVertical = 20;
						animDirection = "pilotCamera_pos";
						maxTrackableSpeed = 500;
						class AirTarget {
							maxRange = 5000;
							minRange = 500;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget {
							maxRange = 3000;
							minRange = 500;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
					};
					class LaserSensorComponent: SensorTemplateLaser {
						allowsMarking = 1;
						angleRangeHorizontal = 180;
						angleRangeVertical = 180;
						animDirection = "pilotCamera_pos";
						class AirTarget {
							maxRange = 6000;
							minRange = 6000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						class GroundTarget {
							maxRange = 8000;
							minRange = 8000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
					};
					class PassiveRadarSensorComponent: SensorTemplateAntiRadiation {
						aimDown = 0;
						allowsMarking = 1;
						angleRangeHorizontal = 360;
						angleRangeVertical = 360;
						animDirection = "";
						color[] = {0.5,1,0.5,0.5};
						groundNoiseDistanceCoef = -1;
						maxGroundNoiseDistance = -1;
						maxSpeedThreshold = 0;
						minSpeedThreshold = 0;
						typeRecognitionDistance = 64000;
						maxFogSeeThrough = 1;
						class AirTarget {
							maxRange = 64000;
							minRange = 64000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						class GroundTarget {
							maxRange = 64000;
							minRange = 64000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
					};
					class VisualSensorComponent: SensorTemplateVisual {
						aimDown = 0;
						allowsMarking = 1;
						angleRangeHorizontal = 26;
						angleRangeVertical = 20;
						animDirection = "pilotCamera_pos";
						groundNoiseDistanceCoef = -1;
						maxFogSeeThrough = 0.94;
						maxGroundNoiseDistance = -1;
						nightRangeCoef = 0;
						typeRecognitionDistance = 4000;
						class AirTarget {
							maxRange = 4000;
							minRange = 500;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget {
							maxRange = 3000;
							minRange = 500;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
					};
					class NVSensorComponent: SensorTemplateNV {};
                    class DataLinkSensorComponent: SensorTemplateDataLink {};
				};
			};
			class TransportPylonsComponent {
				UIPicture = "\pook_EF2000\wep\pylon\loadout.paa";
				class Pylons {
					class Pylon1 {
						maxweight = 365;
						attachment = "EF2K_IRIS_T_x1";
						hardpoints[] = {"EF2K_SRAAM"};
						priority = 13;
						UIposition[] = {0.01,0.2};
					};
					class Pylon2: Pylon1 {
						mirroredMissilePos = 1;
						UIposition[] = {0.65,0.2};
					};
					class Pylon3 {
						maxweight = 450;
						attachment = "EF2K_Brimstone_mag3x";
						hardpoints[] = {"EF2K_SRAAM","EF2K_MRAAM","EF2K_BRIM","B_BOMB_PYLON","B_GBU12_DUAL_RAIL","I_GBU12_DUAL_RAIL"};
						priority = 2;
						UIposition[] = {0.01,0.35};
					};
					class Pylon4: Pylon3 {
						mirroredMissilePos = 3;
						UIposition[] = {0.675,0.35};
					};
					class Pylon5 {
						maxweight = 950;
						attachment = "EF2K_fueltank";
						hardpoints[] = {"EF2K_MRAAM","EF2K_FUEL","EF2K_BRIM","B_BOMB_PYLON","EF2K_RKT"};
						priority = 1;
						UIposition[] = {0.05,0.425};
					};
					class Pylon6: Pylon5 {
						mirroredMissilePos = 5;
						UIposition[] = {0.575,0.425};
					};
					class Pylon7 {
						maxweight = 1000;
						attachment = "PylonRack_Bomb_GBU12_x2";
						hardpoints[] = {"EF2K_MRAAM","EF2K_SCALP","EF2K_BRIM","B_BOMB_PYLON","B_GBU12_DUAL_RAIL","I_GBU12_DUAL_RAIL"};
						priority = 1;
						UIposition[] = {0.2,0.5};
					};
					class Pylon8: Pylon7 {
						mirroredMissilePos = 7;
						UIposition[] = {0.45,0.5};
					};
					class Pylon9 {
						maxweight = 230;
						attachment = "EF2K_AIM120_Fuselage";
						hardpoints[] = {"EF2K_FUSELAGE"};
						priority = 1;
						UIposition[] = {0.01,0.075};
					};
					class Pylon10: Pylon9 {
						mirroredMissilePos = 9;
						UIposition[] = {0.65,0.075};
					};
					class Pylon11: Pylon9 {
						mirroredMissilePos = 9;
						UIposition[] = {0.2,0.075};
					};
					class Pylon12: Pylon9 {
						mirroredMissilePos = 9;
						UIposition[] = {0.45,0.075};
					};
					class Pylon13 {
						maxweight = 2000;
						attachment = "EF2K_LITENING_POD";
						hardpoints[] = {"EF2K_CENTERLINE"};
						priority = 1;
						UIposition[] = {0.32,0.375};
					};
				};
				class Presets {
					class Empty {
						displayName = "Empty";
						attachment[] = {};
					};
					class Default {
						displayName = "Default";
						attachment[] = {"EF2K_IRIS_T_x1", "EF2K_IRIS_T_x1", "EF2K_Brimstone_mag3x", "EF2K_Brimstone_mag3x", "EF2K_fueltank", "EF2K_fueltank","PylonRack_Bomb_GBU12_x2", "PylonRack_Bomb_GBU12_x2", "EF2K_AIM120_Fuselage", "EF2K_AIM120_Fuselage", "EF2K_AIM120_Fuselage", "EF2K_AIM120_Fuselage", "EF2K_LITENING_POD"};
					};
					class Strike {
						displayName = "Strike";
						attachment[] = {"EF2K_ASRAAM_x1", "EF2K_ASRAAM_x1", "EF2K_Brimstone_mag3x", "EF2K_Brimstone_mag3x", "EF2K_fueltank", "EF2K_fueltank", "EF2K_SCALP_mag1x", "EF2K_SCALP_mag1x", "EF2K_AIM120_Fuselage", "EF2K_AIM120_Fuselage", "EF2K_AIM120_Fuselage", "EF2K_AIM120_Fuselage", "EF2K_SCALP_mag1x"};
					};
					class AT {
						displayName = "AT";
						attachment[] = {"EF2K_ASRAAM_x1", "EF2K_ASRAAM_x1", "EF2K_Brimstone_mag3x", "EF2K_Brimstone_mag3x", "EF2K_Brimstone_mag3x", "EF2K_Brimstone_mag3x", "EF2K_Brimstone_mag3x", "EF2K_Brimstone_mag3x", "EF2K_AIM120_Fuselage", "EF2K_AIM120_Fuselage", "EF2K_AIM120_Fuselage", "EF2K_AIM120_Fuselage", "EF2K_CL_fueltank"};
					};
					class CAS {
						displayName = "CAS";
						attachment[] = {"EF2K_ASRAAM_x1", "EF2K_ASRAAM_x1", "EF2K_Bomb_Mk82HD_x2", "EF2K_Bomb_Mk82HD_x2", "EF2K_Brimstone_mag3x", "EF2K_Brimstone_mag3x", "PylonRack_Bomb_GBU12_x2", "PylonRack_Bomb_GBU12_x2", "EF2K_AIM120_Fuselage", "EF2K_AIM120_Fuselage", "EF2K_AIM120_Fuselage", "EF2K_AIM120_Fuselage", "EF2K_CL_fueltank"};
					};
					class SEAD {
						displayName = "SEAD";
						attachment[] = {"EF2K_IRIS_T_x1", "EF2K_IRIS_T_x1", "EF2K_AGM88_mag1x", "EF2K_AGM88_mag1x", "EF2K_BL755_x2", "EF2K_BL755_x2", "EF2K_AGM88_mag1x", "EF2K_AGM88_mag1x", "EF2K_ASPIDE_Fuselage", "EF2K_ASPIDE_Fuselage", "EF2K_ASPIDE_Fuselage", "EF2K_ASPIDE_Fuselage", "EF2K_CL_fueltank"};
					};
					class DEAD {
						displayName = "DEAD";
						attachment[] = {"EF2K_IRIS_T_x1", "EF2K_IRIS_T_x1", "EF2K_Brimstone_mag3x", "EF2K_Brimstone_mag3x", "EF2K_BL755_x2", "EF2K_BL755_x2", "EF2K_AGM88_mag1x", "EF2K_AGM88_mag1x", "EF2K_ASPIDE_Fuselage", "EF2K_ASPIDE_Fuselage", "EF2K_ASPIDE_Fuselage", "EF2K_ASPIDE_Fuselage", "EF2K_CL_fueltank"};
					};
					class CAP {
						displayName = "CAP";
						attachment[] = {"EF2K_ASRAAM_x1", "EF2K_ASRAAM_x1", "EF2K_IRIS_T_x1", "EF2K_IRIS_T_x1", "EF2K_ASPIDE_x1", "EF2K_ASPIDE_x1", "EF2K_ASPIDE_x1", "EF2K_ASPIDE_x1", "EF2K_AIM120_Fuselage", "EF2K_AIM120_Fuselage", "EF2K_AIM120_Fuselage", "EF2K_AIM120_Fuselage", "EF2K_CL_fueltank"};
					};
				};
			};
		};
        receiveRemoteTargets = 1;
        reportRemoteTargets = 1;
        reportOwnPosition = 1;
		weapons[] = {"CUP_weapon_mastersafe", "EF2K_CMFlareLauncher", "EF2K_BK27"};
		magazines[] = {"240Rnd_CMFlare_Chaff_Magazine", "EF2K_150Rnd_BK27"};
        class EventHandlers: EventHandlers {
			class pook_EF2000 {
                init = "";
				dammaged = "";
				engine = "";
				hit = "";
				incomingMissile = "";
				landedTouchDown = "";
            };
		};
        class UserActions {
			class Plane_Eject_UserAction {
				priority = 1;
				shortcut = "Eject";
				displayName = "$STR_A3_action_eject";
				condition = "player in this";
				statement = "[this] spawn BIS_fnc_planeEjection";
				position = "tns_ejection_seat";
				radius = 10;
				onlyforplayer = 1;
				showWindow = 0;
				hideOnUse = 1;
			};
			class ARMRadarDetect {
				displayName = "SEAD - Activate ELS";
				position = "zamerny";
				showWindow = 0;
				radius = 4;
				priority = 2;
				onlyForPlayer = 0;
				shortcut = "AutoHover";
				condition = "(alive this) && (player == (driver this)) && (this GetVariable 'ELS_Active') == 0";
				statement = "[this] execVM '\pook_EF2000\scripts\ARMRadarDetect.sqf';";
			};
			class ARMRadarEngage {
				displayName = "SEAD - Engage ARM Indirect Fire Mode";
				position = "zamerny";
				showWindow = 0;
				radius = 4;
				priority = 2;
				onlyForPlayer = 0;
				shortcut = "AutoHoverCancel";
				condition = "(alive this) && (player == (driver this)) && (this GetVariable 'ELS_Active') == 1";
				statement = "[this] execVM '\pook_EF2000\scripts\ARMRadarEngage.sqf';";
			};
			class ARMRadarEngageSecondary {
				displayName = "SEAD - Engage ARM Detect and Auto-Fire";
				position = "zamerny";
				showWindow = 0;
				radius = 4;
				priority = 1;
				onlyForPlayer = 0;
				shortcut = "";
				condition = "(alive this) && (player == (driver this)) && (this GetVariable 'ELS_Active') == 1";
				statement = "[this] execVM '\pook_EF2000\scripts\ARMRadarDetectandFire.sqf';";
			};
			class ARMRadarCancel {
				displayName = "SEAD - Cancel ELS";
				position = "zamerny";
				showWindow = 0;
				radius = 4;
				priority = 2;
				shortcut = "LockTarget";
				onlyForPlayer = 0;
				condition = "(alive this) && (player == (driver this)) && (this GetVariable 'ELS_Active') == 1";
				statement = "[this] execVM '\pook_EF2000\scripts\ARMRadarCancel.sqf';";
			};
			class nightmarker_on {
				displayName = "Nav Markers On";
				position = "zamerny";
				showWindow = 0;
				radius = 6;
				priority = 5;
				onlyForPlayer = 0;
				shortcut = "";
				condition = "this animationPhase 'night_marker' > 0.9";
				statement = "this animate ['night_marker',0]";
			};
			class nightmarker_off {
				displayName = "Nav Markers Off";
				position = "zamerny";
				showWindow = 0;
				radius = 6;
				priority = 5;
				onlyForPlayer = 0;
				shortcut = "";
				condition = "this animationPhase 'night_marker' < 0.1";
				statement = "this animate ['night_marker',1]";
			};
			class MFD_TV_on {
				displayName = "MFD TV On";
				position = "zamerny";
				showWindow = 0;
				radius = 6;
				priority = 7;
				onlyForPlayer = 0;
				shortcut = "";
				condition = "this animationPhase 'MFD_TV' > 0.9";
				statement = "this animate ['MFD_TV',0]";
			};
			class MFD_TV_off {
				displayName = "MFD TV Off";
				position = "zamerny";
				showWindow = 0;
				radius = 6;
				priority = 7;
				onlyForPlayer = 0;
				shortcut = "";
				condition = "this animationPhase 'MFD_TV' < 0.1";
				statement = "this animate ['MFD_TV',1]";
			};
			class droptanks {
				displayName = "Jettison Fuel Tanks";
				position = "zamerny";
				showWindow = 0;
				hideOnUse = 1;
				radius = 4;
				priority = -1;
				onlyForPlayer = 0;
				shortcut = "";
				condition = QUOTE([this] call FUNC(canJettisonFuelTanks));
				statement = QUOTE([this] call FUNC(jettisonFuelTanks));
			};
			delete siphonTanks;
            delete Extend_TRD1;
			delete Extend_TRD2;
			delete noseconeUp;
			delete noseconeDown;
			delete RetractRefuelBoom;
			delete ExtendRefuelBoom;
			delete lamp_test;
			delete BBH_L;
			delete BBH_M;
			delete BBH_H;
			delete BBH_E;
			delete BBH_O;
		};
    };
    class pook_EF2000_BLUFOR: pook_EF2000 {
		scope = 0;
		scopeCurator = 0;
	};
	class pook_EF2000_INDFOR: pook_EF2000_BLUFOR {
		scope = 0;
		scopeCurator = 0;
	};
	class pook_EF2000_OPFOR: pook_EF2000_BLUFOR {
		scope = 0;
		scopeCurator = 0;
	};
    class GVAR(typhoon): pook_EF2000_BLUFOR {
		scope = 2;
		scopeCurator = 2;
        displayName = "Typhoon FGR4";
		side = 1;
		faction = "CUP_B_GB";
		crew = "UKSF_B_Pilot_617";
		typicalCargo[] = {"UKSF_B_Pilot_617"};
		hiddenSelectionsTextures[] = { QPATHTOF(data\top_UK1.paa) };
    };

    class B_Ejection_Seat_Plane_Fighter_01_F;
	class pook_EF2K_EJECT_SEAT_BLUFOR: B_Ejection_Seat_Plane_Fighter_01_F {
		disableInventory = 1;
		class TransportWeapons {};
		class TransportMagazines {};
		class TransportItems {};
	};
};
