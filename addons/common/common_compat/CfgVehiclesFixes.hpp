// MBG's sound sources have no parent, so they lack every base vehicle entry and have no simulation.
class Sound;
class MBG_SndSrc_DoorOpen : Sound {};
// Two FFAA buildings list a ladder whose start1/end1 points their models do not have.
class ffaa_casa_af_base;
class land_ffaa_casa_urbana_8 : ffaa_casa_af_base {
    ladders[] = {};
};
class land_ffaa_casa_hangar_2 : ffaa_casa_af_base {
    ladders[] = {};
};
