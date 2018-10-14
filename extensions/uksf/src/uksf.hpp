#pragma once
#define NOMINMAX

#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/Net/HTTPBasicCredentials.h"
#include "Poco/StreamCopier.h"
#include "json.hpp"
#pragma comment(lib,"WS2_32")
#pragma comment(lib, "iphlpapi.lib")

#include "singleton.hpp"

#include "intercept.hpp"
using namespace intercept;

#include "signalslot.hpp"

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
