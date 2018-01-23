#pragma once
#define NOMINMAX
#include <windows.h>
#include <stdio.h>
#include <cstdint>
#include <assert.h>
#include <atomic>
#include <stdlib.h>
#include <algorithm>
#include <variant>
#include <vector>
#include <functional>
#include <chrono>
#include <random>

#include "intercept.hpp"
using namespace intercept;

#include "logging.hpp"
#include "signalslot.hpp"
#include "singleton.hpp"

class uksf : public singleton<uksf> {
public:
    uksf();

    //Signal<void()> initModule;
    uksf_signal<void()> post_start;
    uksf_signal<void()> pre_init;
    uksf_signal<void()> post_init;
    uksf_signal<void()> on_frame;
    uksf_signal<void()> mission_ended;
};
