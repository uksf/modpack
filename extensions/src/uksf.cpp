#include "uksf.hpp"
#include "common.hpp"

#include "modules/data/data.hpp"

void __cdecl intercept::post_start() {
    LOG_DEBUG("MAIN PRESTART");
    uksf::get_instance().post_start();
}

void __cdecl intercept::pre_init() {
    LOG_DEBUG("MAIN PREINIT");
    uksf::get_instance().pre_init();
}

void __cdecl intercept::post_init() {
    LOG_DEBUG("MAIN POSTINIT");
    uksf::get_instance().post_init();
}

void __cdecl intercept::on_frame() {
    uksf::get_instance().on_frame();
}

void __cdecl intercept::mission_ended() {
    LOG_DEBUG("MAIN MISSION ENDED");
    uksf::get_instance().mission_ended();
}

uksf::uksf() {
    uksf_common::get_instance();

    uksf_data::get_instance();
}
