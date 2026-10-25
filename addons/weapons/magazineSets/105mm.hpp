#define CHARGE(VALUE) initSpeed = VALUE
#define CHARGE_1 CHARGE(260)
#define CHARGE_2 CHARGE(315)
#define CHARGE_3 CHARGE(365)
#define CHARGE_4 CHARGE(440)
#define CHARGE_5 CHARGE(500)
#define CHARGE_6 CHARGE(600)
#define CHARGE_7 CHARGE(708)

// HE
class tbd_mortars_105mm_round_he_charge_mag_1 : 8Rnd_82mm_Mo_shells {
    displayName = "105mm HE Charge 1";
    displayNameShort = "HE Charge 1";
    CHARGE_1;
};
class tbd_mortars_105mm_round_he_charge_mag_2 : tbd_mortars_105mm_round_he_charge_mag_1 {
    displayName = "105mm HE Charge 2";
    displayNameShort = "HE Charge 2";
    CHARGE_2;
};
class tbd_mortars_105mm_round_he_charge_mag_3 : tbd_mortars_105mm_round_he_charge_mag_1 {
    displayName = "105mm HE Charge 3";
    displayNameShort = "HE Charge 3";
    CHARGE_3;
};
class tbd_mortars_105mm_round_he_charge_mag_4 : tbd_mortars_105mm_round_he_charge_mag_1 {
    displayName = "105mm HE Charge 4";
    displayNameShort = "HE Charge 4";
    CHARGE_4;
};
class tbd_mortars_105mm_round_he_charge_mag_5 : tbd_mortars_105mm_round_he_charge_mag_1 {
    displayName = "105mm HE Charge 4 1/2";
    displayNameShort = "HE Charge 4 1/2";
    CHARGE_5;
};
class tbd_mortars_105mm_round_he_charge_mag_6 : tbd_mortars_105mm_round_he_charge_mag_1 {
    displayName = "105mm HE Charge 5";
    displayNameShort = "HE Charge 5";
    CHARGE_6;
};
class tbd_mortars_105mm_round_he_charge_mag_7 : tbd_mortars_105mm_round_he_charge_mag_1 {
    displayName = "105mm HE Charge Super";
    displayNameShort = "HE Charge Super";
    CHARGE_7;
};

// Smoke
class tbd_mortars_105mm_round_smoke_charge_mag_1 : 8Rnd_82mm_Mo_shells {
    displayName = "105mm Smoke Charge 1";
    displayNameShort = "Smoke Charge 1";
    CHARGE_1;
};
class tbd_mortars_105mm_round_smoke_charge_mag_2 : tbd_mortars_105mm_round_smoke_charge_mag_1 {
    displayName = "105mm Smoke Charge 2";
    displayNameShort = "Smoke Charge 2";
    CHARGE_2;
};
class tbd_mortars_105mm_round_smoke_charge_mag_3 : tbd_mortars_105mm_round_smoke_charge_mag_1 {
    displayName = "105mm Smoke Charge 3";
    displayNameShort = "Smoke Charge 3";
    CHARGE_3;
};
class tbd_mortars_105mm_round_smoke_charge_mag_4 : tbd_mortars_105mm_round_smoke_charge_mag_1 {
    displayName = "105mm Smoke Charge 4";
    displayNameShort = "Smoke Charge 4";
    CHARGE_4;
};
class tbd_mortars_105mm_round_smoke_charge_mag_5 : tbd_mortars_105mm_round_smoke_charge_mag_1 {
    displayName = "105mm Smoke Charge 4 1/2";
    displayNameShort = "Smoke Charge 4 1/2";
    CHARGE_5;
};
class tbd_mortars_105mm_round_smoke_charge_mag_6 : tbd_mortars_105mm_round_smoke_charge_mag_1 {
    displayName = "105mm Smoke Charge 5";
    displayNameShort = "Smoke Charge 5";
    CHARGE_6;
};
class tbd_mortars_105mm_round_smoke_charge_mag_7 : tbd_mortars_105mm_round_smoke_charge_mag_1 {
    displayName = "105mm Smoke Charge Super";
    displayNameShort = "Smoke Charge Super";
    CHARGE_7;
};

// Illumination
class tbd_mortars_105mm_round_dpicm_charge_mag_1 : 8Rnd_82mm_Mo_shells {
    displayName = "105mm Illum Charge 1";
    displayNameShort = "Illum Charge 1";
    descriptionShort = "105mm Illumination shell used in the L118";
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
    displayName = "105mm Illum Charge 4 1/2";
    displayNameShort = "Illum Charge 4 1/2";
    CHARGE_5;
};
class tbd_mortars_105mm_round_dpicm_charge_mag_6 : tbd_mortars_105mm_round_dpicm_charge_mag_1 {
    displayName = "105mm Illum Charge 5";
    displayNameShort = "Illum Charge 5";
    CHARGE_6;
};
class tbd_mortars_105mm_round_dpicm_charge_mag_7 : tbd_mortars_105mm_round_dpicm_charge_mag_1 {
    displayName = "105mm Illum Charge Super";
    displayNameShort = "Illum Charge Super";
    CHARGE_7;
};
// Laser
class tbd_mortars_105mm_round_laser_charge_mag_1 : tbd_mortars_105mm_round_he_charge_mag_1 {
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
