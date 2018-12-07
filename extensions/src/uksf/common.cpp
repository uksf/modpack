#include "common.hpp"

uksf_common::uksf_common() {
	std::queue<int> empty;
	std::swap(functionQueue, empty);

	uksf::getInstance().postStart.connect(
		[this]() {
			LOG_DEBUG("COMMON PRESTART");
		}
	);

	uksf::getInstance().preInit.connect(
		[this]() {
			LOG_DEBUG("COMMON PREINIT");
			cbaSettingsFncInit = sqf::get_variable(sqf::ui_namespace(), "CBA_Settings_fnc_init");
			uksfPersistenceShutdown = sqf::get_variable(sqf::ui_namespace(), "uksf_persistence_fnc_shutdown");
		}
	);

	uksf::getInstance().postInit.connect([this]() { LOG_DEBUG("COMMON POSTINIT"); });

	uksf::getInstance().onFrame.connect(
		[this]() {
			LOG_DEBUG("onframe");
			//threadRun = sqf::time() > int(sqf::get_variable(sqf::mission_namespace(), "CBA_common_lastTime", 0)) && !sqf::find_display(46).is_nil();
			if (!functionQueue.empty()) {
				LOCK(this);
				LOG_DEBUG("function item");
				int item = functionQueue.front();
				LOG_DEBUG(item);
				functionQueue.pop();
				UNLOCK(this);
				handleFunction(item);
			}
		}
	);
}

void uksf_common::addFunction(int functionEnum) {
	if (sqf::time() > 0) {
		LOG_DEBUG("adding function item");
		LOG_DEBUG(functionEnum);
		LOCK(this);
		functionQueue.push(functionEnum);
		UNLOCK(this);
	} else {
		handleFunction(functionEnum);
	}
}

void uksf_common::handleFunction(int functionEnum) {
	switch (functionEnum) {
		case FUNCTION_ENUM_SHUTDOWN:
			functionShutdown();
			break;
		default:
			break;
	}
}

void uksf_common::functionShutdown() {
	LOG_DEBUG("running shutdown");
	if (sqf::is_dedicated()) {
		sqf::diag_log("dedi");
		if (uksfPersistenceShutdown.type_enum() == game_data_type::CODE) {
			sqf::diag_log("function");
			sqf::call(uksfPersistenceShutdown);
		} else {
			sqf::diag_log("shutdown");
			sqf::server_command("#shutdown", "brexit");
		}
	} else {
		sqf::diag_log("hc");
		std::exit(0);
	}
}

float uksf_common::getZoom() {
	const float safeZoneW = sqf::safe_zone_w();
	const float deltaX = sqf::world_to_screen(sqf::position_camera_to_world(vector3(5000, 0, 10000)))->x - 0.5f;
	const float trigRatio = safeZoneW / 2.0f * 5000.0f / (10000.0f * deltaX);
	const float configFov = trigRatio / (safeZoneW / sqf::safe_zone_h());
	return 0.75f / configFov;
}

bool uksf_common::lineOfSight(object& target, object& source, const bool zoomCheck, const bool groupCheck) {
	std::optional<vector2> screenPosition = sqf::world_to_screen(sqf::get_pos(target));
	const bool onScreen = screenPosition.has_value() && (abs(screenPosition->x) < 1.5f && abs(screenPosition->y) < 1.5f);
	const bool visible = sqf::check_visibility(source, "VIEW", sqf::vehicle(source), sqf::eye_pos(source),
		sqf::eye_pos(target)) > 0;
	bool los = onScreen && visible;

	if (onScreen && !los && groupCheck) {
		std::vector<object> units = sqf::units(target);
		for (auto& unit : units) {
			std::optional<vector2> newScreenPosition = sqf::world_to_screen(sqf::get_pos(unit));
			const bool newOnScreen = newScreenPosition.has_value() && (abs(newScreenPosition->x) < 1.5f && abs(
				newScreenPosition->y) < 1.5f);
			los = newOnScreen && sqf::check_visibility(source, "VIEW", sqf::vehicle(source), sqf::eye_pos(source),
				sqf::eye_pos(unit)) > 0;
			if (los) {
				target = std::ref(unit);
				break;
			}
		}
	}

	if (los && zoomCheck) {
		float distanceMultiplier = 200 + 4 * 200 * std::max(0.0f, float(sqf::current_vision_mode(source) - 1));
		if (!sqf::is_kind_of(sqf::vehicle(target), "CAManBase")) { distanceMultiplier *= 2.5f; }
		const float distanceCheck = std::min(sqf::get_object_view_distance().object_distance,
			1000 + distanceMultiplier * getZoom());
		const float distance = sqf::get_pos_world(target).distance(sqf::get_pos_world(source));
		los = distance < distanceCheck;
	}

	return los;
}

side uksf_common::getSide(const int sideNumber) {
	switch (sideNumber) {
		case 1:
			return sqf::west();
		case 2:
			return sqf::independent();
		default:
			return sqf::east();
	}
}

std::string uksf_common::getTimeStamp() {
	const auto now = std::chrono::system_clock::now();
	const auto today = date::floor<days>(now);
	std::stringstream ss;
	ss << today << ' ' << make_time(now - today);
	return ss.str();
}
