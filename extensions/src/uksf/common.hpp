#pragma once
#include "uksf.hpp"
#include "logging.hpp"

#include "date.h"
using namespace date;

#include <random>
#include <queue>

#define LOG_DEBUG(A) LOG(INFO) << A

#define LOCK(x) x->lock();
#define UNLOCK(x) x->unlock();

#define FUNCTION_ENUM_SHUTDOWN 1

static auto reng = std::default_random_engine{};

class uksf_common : public singleton<uksf_common> {
public:
    uksf_common();

    game_value cbaSettingsFncInit = game_value();
    game_value uksfPersistenceShutdown = game_value();
	bool threadRun = false;

	void addFunction(int functionEnum);
	void handleFunction(int functionEnum);

	void functionShutdown();

    float getZoom();
    bool lineOfSight(object& target, object& source, bool zoomCheck, bool groupCheck);
    side getSide(int sideNumber);
    // std::string getTimeStamp();

private:
	std::queue<int> functionQueue;
};
