#pragma once
#include <mutex>

template <typename T>
class singleton {
    singleton(const singleton&) = delete;
    singleton(singleton&&) = delete;
    singleton& operator=(const singleton&) = delete;
    singleton& operator=(singleton&&) = delete;
	std::recursive_mutex m_lockable_mutex;

public:
    static T& getInstance() noexcept { return _singletonInstance; }

	void lock() {
		m_lockable_mutex.lock();
	};

	void unlock() {
		m_lockable_mutex.unlock();
	};

protected:
    singleton() {}
    static T _singletonInstance;
    static bool _initialized;
};

template <typename T>
T singleton<T>::_singletonInstance;

template <typename T>
bool singleton<T>::_initialized = false;
