class M_Vorona_HEAT;
class MissileBase;
class R_MRAAWS_HEAT_F;
class RocketBase;
class LaserBombCore;
class Default;
class BulletBase;
class B_19mm_HE : BulletBase {
    AMMO_USAGE_INFVEHAIR;
};
class B_30mm_HE : B_19mm_HE {
    AMMO_USAGE_INFVEHAIR;
};
class B_20mm : BulletBase {
    AMMO_USAGE_INFVEHAIR;
};
class B_25mm : BulletBase {
    AMMO_USAGE_INFVEHAIR;
};
class B_20mm_AP : BulletBase {
    AMMO_USAGE_INFVEHAIR;
};
class B_30mm_AP : BulletBase {
    AMMO_USAGE_INFVEHAIR;
};
class Gatling_30mm_HE_Plane_CAS_01_F : BulletBase {
    AMMO_USAGE_INFVEHAIR;
};
class ammo_Gun20mmAABase : BulletBase {
    AMMO_USAGE_INFVEHAIR;
};
class ammo_Gun30mmAABase : BulletBase {
    AMMO_USAGE_INFVEHAIR;
};
class ammo_Gun35mmAABase : BulletBase {
    AMMO_USAGE_INFVEHAIR;
};
class BombCore : Default {
    AMMO_USAGE_INFVEHARM;
};
class ammo_Bomb_LaserGuidedBase : LaserBombCore {
    AMMO_USAGE_INFVEHARM;
};
class R_PG32V_F : RocketBase {
    AMMO_USAGE_INFVEHAIRARM;
    AMMO_USAGE_BUFF;
};
class R_TBG32V_F : R_PG32V_F {
    AMMO_USAGE_INFVEHAIR;
    AMMO_USAGE_BUFF;
};
class R_PG7_F : RocketBase {
    AMMO_USAGE_INFVEHAIRARM;
    AMMO_USAGE_BUFF;
};
class R_MRAAWS_HE_F : R_MRAAWS_HEAT_F {
    AMMO_USAGE_INFVEHAIRARM;
    AMMO_USAGE_BUFF;
};
class M_Titan_AT : MissileBase {
    AMMO_USAGE_INFVEHARM;
};
class Missile_AGM_02_F : MissileBase {
    AMMO_USAGE_INFVEHARM;
};
class Rocket_04_HE_F : MissileBase {
    AMMO_USAGE_INFVEHAIRARM;
};
class M_Vorona_HE : M_Vorona_HEAT {
    AMMO_USAGE_INFVEHARM;
};
