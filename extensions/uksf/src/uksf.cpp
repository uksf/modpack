#include "uksf.hpp"
#include "common.hpp"

#include "modules/data/data.hpp"

void __cdecl intercept::post_start() {
    LOG_DEBUG("MAIN PRESTART");
    uksf::getInstance().postStart();
}

void __cdecl intercept::pre_init() {
    LOG_DEBUG("MAIN PREINIT");
    uksf::getInstance().preInit();
}

void __cdecl intercept::post_init() {
    LOG_DEBUG("MAIN POSTINIT");
    uksf::getInstance().postInit();
}

void __cdecl intercept::on_frame() {
    uksf::getInstance().onFrame();
}

void __cdecl intercept::mission_ended() {
    LOG_DEBUG("MAIN MISSION ENDED");
    uksf::getInstance().missionEnded();
}

uksf::uksf() {
    uksf_common::getInstance();

    uksf_data::getInstance();
}
