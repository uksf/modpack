#define PATCH(name,display,creator) \
    class GVAR(DOUBLES(patch,name)) { \
        displayName = display; \
        author = creator; \
        texture = QPATHTOF(data\patches\name.paa); \
        material = "\A3\Ui_f\data\GUI\Cfg\UnitInsignia\default_insignia.rvmat"; \
        textureVehicle = ""; \
    }

class CfgUnitInsignia {
    PATCH(3lions,"3 Lions - England","Foxy");
    PATCH(blackbeard,"Blackbeard","Bohemia Interactive");
    PATCH(a1,"A-1","Foxy");
    PATCH(a2,"A-2","Foxy");
    PATCH(a3,"A-3","Foxy");
    PATCH(a4,"A-4","Foxy");
    PATCH(lamp,"Lamp","Delta");
    PATCH(squid,"Squid","Delta");
    PATCH(kestrel,"Kestrel","Delta");
    PATCH(noot,"Noot","Delta");
    PATCH(uksf,"UKSF","Delta");
    PATCH(skull,"Skull","Delta");
    PATCH(boat_troop,"Boat Troop","Delta");
    PATCH(lusty,"Lusty","Delta");
    PATCH(shower,"Shower","Delta");
    PATCH(kruger,"Kruger","Delta");
    PATCH(troop_sniper,"Troop Sniper","Delta");
    PATCH(reaper,"Reaper","Delta");
    PATCH(raider,"Raider","Delta");
    PATCH(mg,"Machine Gunner","Delta");
    PATCH(at,"Anti-Tank","Delta");
};
