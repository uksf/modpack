#pragma once

template <typename T>
class singleton {
    singleton(const singleton&) = delete;
    singleton(singleton&&) = delete;
    singleton& operator=(const singleton&) = delete;
    singleton& operator=(singleton&&) = delete;

public:
    static T& get_instance() noexcept { return _singleton_instance; }

protected:
    singleton() {}
    static T _singleton_instance;
    static bool _initialized;
};

template <typename T>
T singleton<T>::_singleton_instance;

template <typename T>
bool singleton<T>::_initialized = false;
