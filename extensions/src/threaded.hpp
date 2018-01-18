#pragma once

template <class T>
class threaded {
public:
    threaded() {
        /*uksf_ai::getInstance().missionEnded.connect([this]() {
            singleton<T>::getInstance().stopServerThread();
            singleton<T>::getInstance().stopClientThread();
        });*/
    };

    virtual ~threaded() {
        stopServerThread();
        stopClientThread();
    };

    virtual void serverFunction() {};
    virtual void clientFunction() {};

protected:
    std::thread _serverThread, _clientThread;
    bool _serverThreadStop = true;
    bool _clientThreadStop = true;

    void startServerThread() {
        _serverThreadStop = false;
        _serverThread = std::thread(&threaded<T>::serverThreadFunction, this);
        _serverThread.detach();
    };

    void startClientThread() {
        _clientThreadStop = false;
        _clientThread = std::thread(&threaded<T>::clientThreadFunction, this);
        _clientThread.detach();
    };

    void stopServerThread() {
        if (_serverThread.joinable()) {
            _serverThreadStop = true;
            _serverThread.join();
        }
    };

    void stopClientThread() {
        if (_clientThread.joinable()) {
            _clientThreadStop = true;
            _clientThread.join();
        }
    };

    void serverThreadFunction() {
        while (!_serverThreadStop) {
            if (uksf_common::thread_run) {
                serverFunction();
            }
        }
    };

    void clientThreadFunction() {
        while (!_clientThreadStop) {
            if (uksf_common::thread_run) {
                clientFunction();
            }
        }
    };
};
