#pragma once

#include "Shared.hpp"

class IProcedure {
public:
	virtual void call(ClientMessage message) = 0;

	void setType(const CLIENT_MESSAGE_TYPE value) {
		this->m_Type = value;
	}

	CLIENT_MESSAGE_TYPE getType() const {
		return this->m_Type;
	}

protected:
    ~IProcedure() = default;
    CLIENT_MESSAGE_TYPE m_Type = CLIENT_MESSAGE_TYPE::EMPTY_PROCEDURE;
};
