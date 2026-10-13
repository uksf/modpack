#define GLASS_EFFECT(BASE,TYPE) class BrokenGlass##TYPE { simulation = "particles"; type = QUOTE(BrokenGlass##TYPE##_0850_2250); position = QUOTE(BASE##_effects); intensity = 0.15; interval = 1; lifeTime = 0.05; }
#define GLASS_HITPOINT(BASE,COMPONENT) class BASE##_hitpoint { armor = 0.001; material = -1; name = QUOTE(BASE); visual = QUOTE(BASE##_hide); passThrough = 0; radius = 0.4; convexComponent = QUOTE(COMPONENT); class DestructionEffects { GLASS_EFFECT(BASE,1N); GLASS_EFFECT(BASE,2N); GLASS_EFFECT(BASE,3N); GLASS_EFFECT(BASE,4N); GLASS_EFFECT(BASE,5N); GLASS_EFFECT(BASE,6N); GLASS_EFFECT(BASE,7N); GLASS_EFFECT(BASE,1S); GLASS_EFFECT(BASE,2S); GLASS_EFFECT(BASE,3S); GLASS_EFFECT(BASE,4S); GLASS_EFFECT(BASE,5S); GLASS_EFFECT(BASE,6S); GLASS_EFFECT(BASE,7S); }; }

#define AMMO_USAGE_INFVEH aiAmmoUsageFlags = 192
#define AMMO_USAGE_INFVEHAIR aiAmmoUsageFlags = 448
#define AMMO_USAGE_INFVEHAIRARM aiAmmoUsageFlags = 960
#define AMMO_USAGE_INFVEHARM aiAmmoUsageFlags = 704

#define AMMO_USAGE_BUFF airLock = 1; \
allowAgainstInfantry = 1; \
cost = 40
