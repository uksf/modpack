#include "Shared/Shared.hpp"
#include "UKSF.hpp"

INITIALIZE_EASYLOGGINGPP

// ReSharper disable once CppInconsistentNaming
int __cdecl intercept::api_version() {
	return 1;
}

void InitLogging() {
	spdlog::set_pattern("[%H:%M:%S]-{%l}- %v");
	try {
		logging::logfile = spdlog::rotating_logger_mt("logfile", "logs/uksf_dll.log", 1024000, 10);
		logging::logfile->flush_on(spdlog::level::info);
	} catch (const spdlog::spdlog_ex&) {
		spdlog::set_level(spdlog::level::off);
		logging::logfile = spdlog::stdout_logger_mt("Intercept Core");
	}
}

void CleanupLogging() {
	if (logging::logfile) {
		logging::logfile->flush();
	}
	spdlog::drop_all();
}

void init() {
	InitLogging();

	logMessage("#####################################################################################");
	logMessage("UKSF Intercept DLL Loaded");

	UKSF::getInstance();
}

void stop() {
	logMessage("#####################################################################################");
	logMessage("UKSF Intercept DLL Stopping");

	UKSF::getInstance()->stop();

	CleanupLogging();
}

// ReSharper disable once CppInconsistentNaming
// ReSharper disable once CppParameterMayBeConst
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	switch (ul_reason_for_call) {
		case DLL_PROCESS_ATTACH:
			init();
			break;
		case DLL_PROCESS_DETACH:
			stop();
			break;
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		default:
			break;
	}
	return TRUE;
}
