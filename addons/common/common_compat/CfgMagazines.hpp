// Magazines on Firewill (FIR) and RKSL parents that no loaded mod defines: no model, no stats, and only the
// equally broken FIR weapons use them. Children go before their empty parents.
class CfgMagazines {
    delete FIR_AGM65D_2rnd_M;
    delete FIR_AGM65D_4rnd_M;
    delete FIR_AGM65D_6rnd_M;
    delete FIR_AGM65D_1rnd_M;
    delete FIR_AGM88_2rnd_M;
    delete FIR_AGM88_4rnd_M;
    delete FIR_AGM88_6rnd_M;
    delete FIR_AGM88_1rnd_M;
    delete FIR_AIM120_2rnd_M;
    delete FIR_AIM120_4rnd_M;
    delete FIR_AIM120_6rnd_M;
    delete FIR_AIM120_1rnd_M;
    delete FIR_AIM120_4rnd_M_TWAS;
    delete fir_AIM120_TWAS_1rnd_M;
    delete FIR_AIM9L_2rnd_M;
    delete FIR_AIM9L_1rnd_M;
    delete FIR_AIM9L_2rnd_M_TWAS;
    delete fir_AIM9L_TWAS_1rnd_M;
    delete FIR_GBU39_2rnd_M;
    delete FIR_GBU39_6rnd_M;
    delete FIR_GBU39_1rnd_M;
    delete FIR_EFA_Cannon_TWAS_150rnd_M;
    delete FIR_M61A2_TWAS_511rnd_M;
    delete FIR_gbu12_2rnd_M;
    delete FIR_gbu12_4rnd_M;
    delete FIR_gbu12_1rnd_M;
    delete FIR_gbu38_2rnd_M;
    delete FIR_gbu38_1rnd_M;
    delete GX_RKSL_BRIMSTONE_DM_X2;
    delete rksla3_mag_brimstone_dm_x3;
    // HAFM's legacy launcher magazines name ammo (RIM162_A) that HAFM no longer defines; use its current missiles.
    class VehicleMagazine;
    class RIM162_M32 : VehicleMagazine {
        ammo = "HAFM_RIM162_ESSM";
    };
    class Igla_8 : RIM162_M32 {
        ammo = "HAFM_IGLA1M";
    };
};
