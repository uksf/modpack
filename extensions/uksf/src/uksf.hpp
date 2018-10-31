#pragma once
#define NOMINMAX

#pragma comment(lib,"WS2_32")
#pragma comment(lib, "iphlpapi.lib")

#include "singleton.hpp"

#include "intercept.hpp"
using namespace intercept;

#include "signalslot.hpp"

class uksf : public singleton<uksf> {
public:
    uksf();

    uksf_signal<void()> postStart;
    uksf_signal<void()> preInit;
    uksf_signal<void()> postInit;
    uksf_signal<void()> onFrame;
    uksf_signal<void()> missionEnded;
};
