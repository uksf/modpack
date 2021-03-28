class Truck_F;
class rksla3_aircraft_tug_base : Truck_F {
    delete editorcategory;
};
class rksla3_aircraft_tug_blufor : rksla3_aircraft_tug_base {
    faction = "CUP_B_GB";
};
class rksla3_aircraft_tug_opfor : rksla3_aircraft_tug_base {
    faction = "OPF_F";
};
class rksla3_aircraft_tug_guer : rksla3_aircraft_tug_base {
    faction = "IND_F";
};
class rksla3_aircraft_tug_civ : rksla3_aircraft_tug_base {
    faction = "CIV_F";
};
