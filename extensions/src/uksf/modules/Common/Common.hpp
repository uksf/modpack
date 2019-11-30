#pragma once

#include "../SharedComponent.hpp"

class Common : public Singleton<Common> {
public:
	Common();

    game_value cbaSettingsFncInit = game_value();
	game_value uksfPersistenceShutdown = game_value();

	void serverShutdown() const;

    static float getZoom();
	bool lineOfSight(object& target, object& source, bool zoomCheck, bool groupCheck) const;
    static side getSide(int sideNumber);
};
