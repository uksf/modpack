#pragma once
//Courtesy of dedmen from TFAR https://github.com/michail-nikolaev/task-force-arma-3-radio/blob/1.0/ts/src/SignalSlot.hpp

template<class Sig>
class uksf_signal;

template<class ReturnType, class... Args>
class uksf_signal<ReturnType(Args...)> {
private:
    typedef std::function<ReturnType(Args...)> slot;

public:
    void connect(slot slot) {
        _slots.push_back(slot);
    }

    std::vector<ReturnType> operator() (Args... args) const {
        return emit(args...);
    }
    std::vector<ReturnType> emit(Args... args) const {
        std::vector<ReturnType> return_data;
        if (_slots.empty())
            return;
        for (auto &slot : _slots) {
            return_data.push_back(slot(args...));
        }
        return return_data;
    }
    void remove_all_slots() {
        _slots.clear();
    }
private:
    std::vector<slot> _slots{};
};

template<class... Args>
class uksf_signal<void(Args...)> {
private:
    typedef std::function<void(Args...)> Slot;

public:
    void connect(Slot slot) {
        _slots.push_back(slot);
    }

    void operator() (Args... args) const {
        return emit(args...);
    }
    void emit(Args... args) const {
        if (_slots.empty())
            return;
        for (auto &slot : _slots) {
            slot(args...);
        }
    }
    void remove_all_slots() {
        _slots.clear();
    }
private:
    std::vector<Slot> _slots{};
};
