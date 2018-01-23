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
#include <future>

#include "intercept.hpp"
using namespace intercept;

#include "logging.hpp"
#include "signalslot.hpp"
#include "singleton.hpp"

class uksf : public singleton<uksf> {
public:
    uksf();

    //Signal<void()> initModule;
    uksf_signal<void()> postStart;
    uksf_signal<void()> preInit;
    uksf_signal<void()> postInit;
    uksf_signal<void()> onFrame;
    uksf_signal<void()> missionEnded;
};
