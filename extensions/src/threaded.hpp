#pragma once

template <class T>
class threaded {
public:
    threaded() {
        uksf::get_instance().mission_ended.connect([this]() {
            singleton<T>::get_instance().stop_thread();
        });
    }

    virtual ~threaded() {
        stop_thread();
    }

    virtual void function() {}

protected:
    std::thread _thread;
    bool _thread_stop = true;

    void start_thread() {
        _thread_stop = false;
        _thread = std::thread(&threaded<T>::thread_function, this);
        _thread.detach();
    }

    void stop_thread() {
        if (_thread.joinable()) {
            _thread_stop = true;
            _thread.join();
        }
    }

    void thread_function() { while (!_thread_stop) { if (uksf_common::thread_run) { function(); } } }
};
