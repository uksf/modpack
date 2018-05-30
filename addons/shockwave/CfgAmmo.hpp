class CfgAmmo {
	class Default;
	class BulletCore;
	class BulletBase: Bulletcore {};
	class ShellCore {
		shockwaveFunction = QFUNC(120mm);
	};
	class FlareCore;
	class ShotDeployCore;
	class SubmunitionCore;
	class SubmunitionBase: SubmunitionCore{};
	class MissileCore {
		shockwaveFunction = QFUNC(BigRocket);
	};
	class Gatling_30mm_HE_Plane_CAS_01_F: BulletBase {
		shockwaveFunction = QFUNC(SmallRocket);
	};
	class GrenadeCore {
		shockwaveFunction = QFUNC(Grenade);
	};
	class BombCore {
		shockwaveFunction = QFUNC(BigRocket);
	};
	class LaserBombCore {
		shockwaveFunction = QFUNC(BigBomb);
	};
	class RocketCore {
		shockwaveFunction = QFUNC(SmallRocket);
	};
	class MineCore;
	class BoundingMineCore;
	class DirectionalBombCore;
	class PipeBombCore;
	class ShellBase: ShellCore {
	};
	class MissileBase: MissileCore {
		shockwaveFunction = QFUNC(BigRocket);
	};
	class RocketBase: RocketCore {
		shockwaveFunction = QFUNC(SmallRocket);
	};
	class Grenade: Default {
		shockwaveFunction = QFUNC(Grenade);
	};
	class GrenadeHand: Grenade {};
	class SmokeShell: GrenadeHand {
		shockwaveFunction = "";
	};
	class GrenadeBase: GrenadeCore {
		shockwaveFunction = QFUNC(Grenade);
	};
	class FuelExplosion: Default {
		shockwaveFunction = QFUNC(FuelExploSmall);
	};
	class FuelExplosionBig: FuelExplosion {
		shockwaveFunction = QFUNC(FuelExploBig);
	};
	class HelicopterExploSmall: ShellBase {
		shockwaveFunction = QFUNC(FuelExploSmall);
	};
	class HelicopterExploBig: HelicopterExploSmall {
		shockwaveFunction = QFUNC(FuelExploBig);
	};
	class SmallSecondary: HelicopterExploSmall {
		shockwaveFunction = QFUNC(Grenade);
	};
	class B_19mm_HE: BulletBase {
		shockwaveFunction = QFUNC(Grenade);
	};
	class B_30mm_HE: B_19mm_HE {
		shockwaveFunction = QFUNC(Grenade);
	};
	class B_30mm_HE_Tracer_Red: B_30mm_HE {
		shockwaveFunction = QFUNC(Grenade);
	};
	class B_30mm_HE_Tracer_Green: B_30mm_HE {
		shockwaveFunction = QFUNC(Grenade);
	};
	class B_30mm_HE_Tracer_Yellow: B_30mm_HE {
		shockwaveFunction = QFUNC(Grenade);
	};
	class B_30mm_MP: B_30mm_HE {
		shockwaveFunction = QFUNC(Grenade);
	};
	class B_30mm_MP_Tracer_Red: B_30mm_MP {
		shockwaveFunction = QFUNC(Grenade);
	};
	class B_30mm_MP_Tracer_Green: B_30mm_MP {
		shockwaveFunction = QFUNC(Grenade);
	};
	class B_30mm_MP_Tracer_Yellow: B_30mm_MP {
		shockwaveFunction = QFUNC(Grenade);
	};
	class B_40mm_GPR: B_30mm_HE {
		shockwaveFunction = QFUNC(Grenade);
	};
	class B_40mm_GPR_Tracer_Red: B_40mm_GPR	 {
		shockwaveFunction = QFUNC(Grenade);
	};
	class B_40mm_GPR_Tracer_Green: B_40mm_GPR {
		shockwaveFunction = QFUNC(Grenade);
	};
	class B_40mm_GPR_Tracer_Yellow: B_40mm_GPR {
		shockwaveFunction = QFUNC(Grenade);
	};
	class B_20mm: BulletBase {
		shockwaveFunction = QFUNC(Grenade);
	};
	class B_20mm_Tracer_Red: B_20mm	 {
		shockwaveFunction = QFUNC(Grenade);
	};
	class B_25mm: BulletBase {
		shockwaveFunction = QFUNC(Grenade);
	};
	class B_30mm_AP: BulletBase {
		shockwaveFunction = QFUNC(Grenade);
	};
	class B_30mm_AP_Tracer_Red: B_30mm_AP {
		shockwaveFunction = QFUNC(Grenade);
	};
	class B_30mm_AP_Tracer_Green: B_30mm_AP {
		shockwaveFunction = QFUNC(Grenade);
	};
	class B_30mm_AP_Tracer_Yellow: B_30mm_AP {
		shockwaveFunction = QFUNC(Grenade);
	};
	class B_30mm_APFSDS: B_30mm_AP {
		shockwaveFunction = QFUNC(Grenade);
	};
	class B_30mm_APFSDS_Tracer_Red: B_30mm_APFSDS {
		shockwaveFunction = QFUNC(Grenade);
	};
	class B_30mm_APFSDS_Tracer_Green: B_30mm_APFSDS {
		shockwaveFunction = QFUNC(Grenade);
	};
	class B_30mm_APFSDS_Tracer_Yellow: B_30mm_APFSDS {
		shockwaveFunction = QFUNC(Grenade);
	};
	class B_40mm_APFSDS: B_30mm_APFSDS {
		shockwaveFunction = QFUNC(SmallRocket);
	};
	class B_35mm_AA: BulletBase {
		shockwaveFunction = QFUNC(Grenade);
	};
	class M_PG_AT: MissileBase {
		shockwaveFunction = QFUNC(SmallRocket);
	};
	class M_AT: M_PG_AT {
		shockwaveFunction = QFUNC(SmallRocket);
	};
	class M_Mo_82mm_AT: MissileBase {
		shockwaveFunction = QFUNC(Mortar);
	};
	class M_Mo_82mm_AT_LG: M_Mo_82mm_AT {
		shockwaveFunction = QFUNC(Mortar);
	};
	class M_Mo_120mm_AT: MissileBase {
		shockwaveFunction = QFUNC(120mm);
	};
	class M_Mo_120mm_AT_LG: M_Mo_120mm_AT {
		shockwaveFunction = QFUNC(120mm);
	};
	class M_RPG32_F: MissileBase {
		shockwaveFunction = QFUNC(SmallRocket);
	};
	class M_RPG32_AA_F: M_RPG32_F {
		shockwaveFunction = QFUNC(SmallRocket);
	};
	class M_NLAW_AT_F: MissileBase {
		shockwaveFunction = QFUNC(SmallRocket);
	};
	class M_Scalpel_AT: MissileBase {
		shockwaveFunction = QFUNC(SmallRocket);
	};
	class M_Scalpel_AT_hidden: M_Scalpel_AT {
		shockwaveFunction = QFUNC(SmallRocket);
	};
	class M_Titan_AA: MissileBase {
		shockwaveFunction = QFUNC(SmallRocket);
	};
	class M_Zephyr: M_Titan_AA {
		shockwaveFunction = QFUNC(SmallRocket);
	};
	class M_Zephyr_Mi06: M_Zephyr {
		shockwaveFunction = QFUNC(SmallRocket);
	};
	class M_Air_AA: MissileBase {
		shockwaveFunction = QFUNC(SmallRocket);
	};
	class M_Air_AA_MI02: M_Air_AA {
		shockwaveFunction = QFUNC(SmallRocket);
	};
	class M_Titan_AT: MissileBase {
		shockwaveFunction = QFUNC(SmallRocket);
	};
	class M_Titan_AP: M_Titan_AT {
		shockwaveFunction = QFUNC(SmallRocket);
	};
	class M_Air_AT: M_Titan_AT {
		shockwaveFunction = QFUNC(SmallRocket);
	};
	class R_80mm_HE: RocketBase {
		shockwaveFunction = QFUNC(Mortar);
	};
	class R_60mm_HE: R_80mm_HE {
		shockwaveFunction = QFUNC(SmallRocket);
	};
	class R_230mm_HE: SubmunitionBase {
		shockwaveFunction = QFUNC(BigRocket);
	};
	class R_230mm_fly: ShellBase {
		shockwaveFunction = QFUNC(BigRocket);
	};
	class Sh_120mm_HE: ShellBase {
		shockwaveFunction = QFUNC(120mm);
	};
	class Sh_120mm_HE_Tracer_Red: Sh_120mm_HE {
		shockwaveFunction = QFUNC(120mm);
	};
	class Sh_120mm_HE_Tracer_Green: Sh_120mm_HE {
		shockwaveFunction = QFUNC(120mm);
	};
	class Sh_120mm_HE_Tracer_Yellow: Sh_120mm_HE {
		shockwaveFunction = QFUNC(120mm);
	};
	class Sh_120mm_APFSDS: ShellBase {
		shockwaveFunction = QFUNC(120mm);
	};
	class Sh_120mm_APFSDS_Tracer_Red: Sh_120mm_APFSDS {
		shockwaveFunction = QFUNC(120mm);
	};
	class Sh_120mm_APFSDS_Tracer_Green: Sh_120mm_APFSDS {
		shockwaveFunction = QFUNC(120mm);
	};
	class Sh_120mm_APFSDS_Tracer_Yellow: Sh_120mm_APFSDS {
		shockwaveFunction = QFUNC(120mm);
	};
	class Sh_155mm_AMOS: ShellBase {
		shockwaveFunction = QFUNC(Arty);
	};
	class Sh_82mm_AMOS: Sh_155mm_AMOS {
		shockwaveFunction = QFUNC(Mortar);
	};
	class Sh_82mm_AMOS_guided: SubmunitionBase {
		shockwaveFunction = QFUNC(Mortar);
	};
	class Sh_82mm_AMOS_LG: Sh_82mm_AMOS_guided {
		shockwaveFunction = QFUNC(Mortar);
	};
	class Sh_155mm_AMOS_guided: Sh_82mm_AMOS_guided {
		shockwaveFunction = QFUNC(Arty);
	};
	class Sh_155mm_AMOS_LG: Sh_82mm_AMOS_LG {
		shockwaveFunction = QFUNC(Arty);
	};
	class G_40mm_HE: GrenadeBase {
		shockwaveFunction = QFUNC(Grenade);
	};
	class G_20mm_HE: G_40mm_HE {
		shockwaveFunction = QFUNC(Grenade);
	};
	class G_40mm_HEDP: G_40mm_HE {
		shockwaveFunction = QFUNC(Grenade);
	};
	class MineBase: MineCore {
		shockwaveFunction = QFUNC(Grenade);
	};
	class BoundingMineBase: BoundingMineCore {
		shockwaveFunction = QFUNC(Grenade);
	};
	class DirectionalBombBase: DirectionalBombCore {
		shockwaveFunction = QFUNC(Grenade);
	};
	class PipeBombBase: PipeBombCore {
		shockwaveFunction = QFUNC(Satchel);
	};
	class ATMine_Range_Ammo: MineBase {
		shockwaveFunction = QFUNC(Grenade);
	};
	class UnderwaterMine_Range_Ammo: MineBase {};
	class UnderwaterMineAB_Range_Ammo: UnderwaterMine_Range_Ammo {};
	class UnderwaterMinePDM_Range_Ammo: UnderwaterMine_Range_Ammo {};
	class APERSMine_Range_Ammo: MineBase {
		shockwaveFunction = QFUNC(Grenade);
	};
	class APERSBoundingMine_Range_Ammo: BoundingMineBase {
		shockwaveFunction = QFUNC(Grenade);
	};
	class SLAMDirectionalMine_Wire_Ammo: DirectionalBombBase {
		shockwaveFunction = QFUNC(Grenade);
	};
	class APERSTripMine_Wire_Ammo: DirectionalBombBase {
		shockwaveFunction = QFUNC(Grenade);
	};
	class ClaymoreDirectionalMine_Remote_Ammo: DirectionalBombBase {
		shockwaveFunction = QFUNC(Grenade);
	};
	class SatchelCharge_Remote_Ammo: PipeBombBase {
		shockwaveFunction = QFUNC(Satchel);
	};
	class DemoCharge_Remote_Ammo: PipeBombBase {
		shockwaveFunction = QFUNC(Satchel);
	};
	class IEDUrbanBig_Remote_Ammo: PipeBombBase {
		shockwaveFunction = QFUNC(Satchel);
	};
	class IEDLandBig_Remote_Ammo: PipeBombBase {
		shockwaveFunction = QFUNC(Satchel);
	};
	class IEDUrbanSmall_Remote_Ammo: PipeBombBase {
		shockwaveFunction = "L_fnc_ExShake_IED";
	};
	class IEDLandSmall_Remote_Ammo: PipeBombBase {
		shockwaveFunction = "L_fnc_ExShake_IED";
	};
	class Bomb_04_F: LaserBombCore {
		shockwaveFunction = QFUNC(BigBomb);
	};
	class Bo_GBU12_LGB: LaserBombCore {
		shockwaveFunction = QFUNC(BigBomb);
	};
	class Bo_Mk82: BombCore {
		shockwaveFunction = QFUNC(BigBomb);
	};
};
