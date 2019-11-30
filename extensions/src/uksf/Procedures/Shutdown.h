#pragma once
#include "../Shared/IProcedure.h"
#include "../Shared/ClientMessage.h"
#include "../Modules/Common/Common.hpp"

class ProcShutdown final : public IProcedure {
public:
	ProcShutdown() {
		this->m_Type = CLIENT_MESSAGE_TYPE::SHUTDOWN;
	}

    void call(ClientMessage message) override {
		UKSF::getInstance()->addToGameFunctionQueue([]() {
			Common::getInstance()->serverShutdown();
		});
	}
};
