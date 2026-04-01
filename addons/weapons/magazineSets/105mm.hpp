#define CHARGE(VALUE) initSpeed = VALUE
#define CHARGE_1 CHARGE(100)
#define CHARGE_2 CHARGE(165)
#define CHARGE_3 CHARGE(225)
#define CHARGE_4 CHARGE(280)
#define CHARGE_5 CHARGE(330)
#define CHARGE_6 CHARGE(370)
#define CHARGE_7 CHARGE(440)

// HE
class tbd_mortars_105mm_round_he_charge_mag_1 : 8Rnd_82mm_Mo_shells {
    CHARGE_1;
};
class tbd_mortars_105mm_round_he_charge_mag_2 : tbd_mortars_105mm_round_he_charge_mag_1 {
    CHARGE_2;
};
class tbd_mortars_105mm_round_he_charge_mag_3 : tbd_mortars_105mm_round_he_charge_mag_1 {
    CHARGE_3;
};
class tbd_mortars_105mm_round_he_charge_mag_4 : tbd_mortars_105mm_round_he_charge_mag_1 {
    CHARGE_4;
};
class tbd_mortars_105mm_round_he_charge_mag_5 : tbd_mortars_105mm_round_he_charge_mag_1 {
    CHARGE_5;
};
class tbd_mortars_105mm_round_he_charge_mag_6 : tbd_mortars_105mm_round_he_charge_mag_1 {
    CHARGE_6;
};
class tbd_mortars_105mm_round_he_charge_mag_7 : tbd_mortars_105mm_round_he_charge_mag_1 {
    CHARGE_7;
};

// Smoke
class tbd_mortars_105mm_round_smoke_charge_mag_1 : 8Rnd_82mm_Mo_shells {
    CHARGE_1;
};
class tbd_mortars_105mm_round_smoke_charge_mag_2 : tbd_mortars_105mm_round_smoke_charge_mag_1 {
    CHARGE_2;
};
class tbd_mortars_105mm_round_smoke_charge_mag_3 : tbd_mortars_105mm_round_smoke_charge_mag_1 {
    CHARGE_3;
};
class tbd_mortars_105mm_round_smoke_charge_mag_4 : tbd_mortars_105mm_round_smoke_charge_mag_1 {
    CHARGE_4;
};
class tbd_mortars_105mm_round_smoke_charge_mag_5 : tbd_mortars_105mm_round_smoke_charge_mag_1 {
    CHARGE_5;
};
class tbd_mortars_105mm_round_smoke_charge_mag_6 : tbd_mortars_105mm_round_smoke_charge_mag_1 {
    CHARGE_6;
};
class tbd_mortars_105mm_round_smoke_charge_mag_7 : tbd_mortars_105mm_round_smoke_charge_mag_1 {
    CHARGE_7;
};

// Illumination
class tbd_mortars_105mm_round_dpicm_charge_mag_1 : 8Rnd_82mm_Mo_shells {
    displayName = "105mm Illum Charge 1";
    displayNameShort = "Illum Charge 1";
    descriptionShort = "105mm Illumination shell used in the L119";
    ammo = QGVAR(105mm_shell_ammo_illum);
    CHARGE_1;
};
class tbd_mortars_105mm_round_dpicm_charge_mag_2 : tbd_mortars_105mm_round_dpicm_charge_mag_1 {
    displayName = "105mm Illum Charge 2";
    displayNameShort = "Illum Charge 2";
    CHARGE_2;
};
class tbd_mortars_105mm_round_dpicm_charge_mag_3 : tbd_mortars_105mm_round_dpicm_charge_mag_1 {
    displayName = "105mm Illum Charge 3";
    displayNameShort = "Illum Charge 3";
    CHARGE_3;
};
class tbd_mortars_105mm_round_dpicm_charge_mag_4 : tbd_mortars_105mm_round_dpicm_charge_mag_1 {
    displayName = "105mm Illum Charge 4";
    displayNameShort = "Illum Charge 4";
    CHARGE_4;
};
class tbd_mortars_105mm_round_dpicm_charge_mag_5 : tbd_mortars_105mm_round_dpicm_charge_mag_1 {
    displayName = "105mm Illum Charge 5";
    displayNameShort = "Illum Charge 5";
    CHARGE_5;
};
class tbd_mortars_105mm_round_dpicm_charge_mag_6 : tbd_mortars_105mm_round_dpicm_charge_mag_1 {
    displayName = "105mm Illum Charge 6";
    displayNameShort = "Illum Charge 6";
    CHARGE_6;
};
class tbd_mortars_105mm_round_dpicm_charge_mag_7 : tbd_mortars_105mm_round_dpicm_charge_mag_1 {
    displayName = "105mm Illum Charge 7";
    displayNameShort = "Illum Charge 7";
    CHARGE_7;
};

// Laser
class tbd_mortars_105mm_round_laser_charge_mag_1 : 8Rnd_82mm_Mo_shells {
    CHARGE_1;
};
class tbd_mortars_105mm_round_laser_charge_mag_2 : tbd_mortars_105mm_round_laser_charge_mag_1 {
    CHARGE_2;
};
class tbd_mortars_105mm_round_laser_charge_mag_3 : tbd_mortars_105mm_round_laser_charge_mag_1 {
    CHARGE_3;
};
class tbd_mortars_105mm_round_laser_charge_mag_4 : tbd_mortars_105mm_round_laser_charge_mag_1 {
    CHARGE_4;
};
class tbd_mortars_105mm_round_laser_charge_mag_5 : tbd_mortars_105mm_round_laser_charge_mag_1 {
    CHARGE_5;
};
class tbd_mortars_105mm_round_laser_charge_mag_6 : tbd_mortars_105mm_round_laser_charge_mag_1 {
    CHARGE_6;
};
class tbd_mortars_105mm_round_laser_charge_mag_7 : tbd_mortars_105mm_round_laser_charge_mag_1 {
    CHARGE_7;
};
