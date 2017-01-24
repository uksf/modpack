//SU-25
class bwi_a3_su25_base;
class bwi_a3_su25_str: bwi_a3_su25_base {
    scope = 0;
    scopeCurator = 0;
};
class bwi_a3_su25t_str: bwi_a3_su25_base {
    scope = 0;
    scopeCurator = 0;
};
class Genfor_Air_SU25K: bwi_a3_su25_str {
    scope = 2;
    faction = "UKSF_Genfor";
    displayName = "Su-25K";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Air_SU25K.jpg);
    crew = "GENFOR_FP";
};
class Genfor_Air_SU25T: bwi_a3_su25t_str {
    scope = 2;
    faction = "UKSF_Genfor";
    displayName = "Su-25T";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Air_SU25T.jpg);
    crew = "GENFOR_FP";
};

//SU-35
class sab_SU34_BASE;
class sab_SU34_I_CAP: sab_SU34_BASE {
    scope = 0;
    scopeCurator = 0;
};
class sab_SU34_I_CAS: sab_SU34_I_CAP {
    scope = 0;
    scopeCurator = 0;
};
class sab_SU34_O_CAS: sab_SU34_I_CAS {
    scope = 0;
    scopeCurator = 0;
};
class sab_SU34_O_CAS_CRU: sab_SU34_O_CAS {
    scope = 0;
    scopeCurator = 0;
};
class Genfor_Air_SU34: sab_SU34_O_CAS_CRU {
    scope = 2;
    scopeCurator = 2;
    faction = "UKSF_Genfor";
    displayName = "Su-34";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Air_SU34.jpg);
    crew = "GENFOR_FP";
    typicalCargo[] = { "GENFOR_FP" };
};

//Scope 0
class bwi_a3_su25: bwi_a3_su25_base {
    scope = 0;
    scopeCurator = 0;
};
class bwi_a3_su25t: bwi_a3_su25_base {
    scope = 0;
    scopeCurator = 0;
};
class bwi_a3_su25_iraq: bwi_a3_su25_base {
    scope = 0;
    scopeCurator = 0;
};
class bwi_a3_su25_cdf: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_geo: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_ukr: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_str_iraq: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_str_cdf: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_str_geo: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_str_ukr: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_cap: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25t_cap: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_cap_iraq: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_cap_geo: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_cap_ukr: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_bmb: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25t_bmb: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_bmb_iraq: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_bmb_cdf: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_bmb_geo: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_bmb_ukr: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_as: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25t_as: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_as_iraq: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_ap: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25t_ap: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_ap_iraq: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_ap_geo: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_sead: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25t_sead: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_fer: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25t_fer: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_fer_iraq: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_fer_cdf: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_fer_geo: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_fer_ukr: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_cas: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25t_cas: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_cas_iraq: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_cas_cdf: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_cas_ukr: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_cas_geo: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_atk: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25t_atk: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_atk_iraq: bwi_a3_su25_base {
    scope = 0;
};
class bwi_a3_su25_atk_geo: bwi_a3_su25_base {
    scope = 0;
};

class sab_SU34_CIV: sab_SU34_BASE {
    scope = 0;
    scopeCurator = 0;
};
class sab_SU34_CIV_2: sab_SU34_CIV {
    scope = 0;
    scopeCurator = 0;
};
class sab_SU34_I_LGB: sab_SU34_I_CAP {
    scope = 0;
    scopeCurator = 0;
};
class sab_SU34_I_BMB: sab_SU34_I_CAP {
    scope = 0;
    scopeCurator = 0;
};
class sab_SU34_I_AGM: sab_SU34_I_CAP {
    scope = 0;
    scopeCurator = 0;
};
class sab_SU34_O_CAP: sab_SU34_BASE {
    scope = 0;
    scopeCurator = 0;
};
class sab_SU34_O_CAP_CRU: sab_SU34_O_CAP {
    scope = 0;
    scopeCurator = 0;
};
class sab_SU34_O_CAP_CRU_BLK: sab_SU34_O_CAP_CRU {
    scope = 0;
    scopeCurator = 0;
};
class sab_SU34_O_BMB: sab_SU34_O_CAP {
    scope = 0;
    scopeCurator = 0;
};
class sab_SU34_O_AGM: sab_SU34_O_CAP {
    scope = 0;
    scopeCurator = 0;
};
class sab_SU34_O_LGB: sab_SU34_O_CAP {
    scope = 0;
    scopeCurator = 0;
};
class sab_SU34_O_LGB_CRU: sab_SU34_O_LGB {
    scope = 0;
    scopeCurator = 0;
};
class sab_SU34_O_BMB_CRU: sab_SU34_O_BMB {
    scope = 0;
    scopeCurator = 0;
};
class sab_SU34_O_AGM_CRU: sab_SU34_O_AGM {
    scope = 0;
    scopeCurator = 0;
};
class sab_SU34_O_CAP_g: sab_SU34_O_CAP {
    scope = 0;
    scopeCurator = 0;
};
class sab_SU34_O_CAP_CRU_AF: sab_SU34_O_CAP_CRU {
    scope = 0;
    scopeCurator = 0;
};
