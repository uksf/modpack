#pragma once
#include <mutex>

class Lockable {
public:
	virtual ~Lockable() = default;
	std::mutex m_lockable_mutex;
};
