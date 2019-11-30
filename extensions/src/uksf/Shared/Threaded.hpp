#pragma once
#include "Shared.hpp"

template <class T>
class Threaded {
public:
    Threaded() {
        /*UKSF::getInstance()->missionEnded.connect([this]() {
            this->stopThread();
        });*/
    }

    virtual ~Threaded() {
        stopThread();
    }

    virtual void initThread() {}
    virtual void function() {}

protected:
    std::thread _thread;
    bool _threadStop = true;
    bool initOnly = false;

    void startThread() {
        _threadStop = false;
        _thread = std::thread(&Threaded<T>::threadFunction, this);
        _thread.detach();
    }

    void stopThread() {
        if (_thread.joinable()) {
            _threadStop = true;
            _thread.join();
        }
    }

    void threadFunction() {
        initThread();
        if (initOnly) return;
        while (!_threadStop) {
            if (masterThreadRun) {
                function();
            }
        }
    }
};
