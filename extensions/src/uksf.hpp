#pragma once
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN

#pragma comment(lib,"WS2_32")
#pragma comment(lib, "iphlpapi.lib")

// ReSharper disable once CppUnusedIncludeDirective
#include <WinSock2.h>

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
