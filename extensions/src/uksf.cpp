#include "uksf.hpp"
#include "common.hpp"

//#include "caching.hpp"

void __cdecl intercept::pre_start() {
    LOG(DEBUG) << "MAIN PRESTART";
    uksf::getInstance().preStart();
}

void __cdecl intercept::pre_init() {
    LOG(DEBUG) << "MAIN PREINIT";
    uksf::getInstance().preInit();
}

void __cdecl intercept::post_init() {
    LOG(DEBUG) << "MAIN POSTINIT";
    uksf::getInstance().postInit();
}

void __cdecl intercept::on_frame() {
    uksf::getInstance().onFrame();
}

/*void __cdecl intercept::mission_end() {
    LOG(DEBUG) << "MAIN MISSION ENDED";
    uksf::getInstance().missionEnded();
}*/

uksf::uksf() {
    uksf_common::getInstance();

    //uksf_ai_caching::getInstance();
}
