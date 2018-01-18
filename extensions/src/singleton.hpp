#pragma once

template<typename T>
class singleton {
    singleton(const singleton&) = delete;
    singleton(singleton&&) = delete;
    singleton& operator=(const singleton&) = delete;
    singleton& operator=(singleton&&) = delete;

public:
    static T& getInstance() noexcept {
        return _singletonInstance;
    }

protected:
    singleton() {}
    static T _singletonInstance;
    static bool _initialized;
};

template<typename T>
T singleton<T>::_singletonInstance;

template<typename T>
bool singleton<T>::_initialized = false;
