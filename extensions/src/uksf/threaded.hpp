#pragma once

template <class T>
class threaded {
public:
    threaded() {
        uksf::getInstance().missionEnded.connect([this]() {
            singleton<T>::getInstance().stopThread();
        });
    }

    virtual ~threaded() {
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
        _thread = std::thread(&threaded<T>::threadFunction, this);
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
            if (uksf_common::getInstance().threadRun) {
                function();
            }
        }
    }
};
