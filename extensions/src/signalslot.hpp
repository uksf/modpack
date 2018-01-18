#pragma once
//Courtesy of dedmen from TFAR https://github.com/michail-nikolaev/task-force-arma-3-radio/blob/1.0/ts/src/SignalSlot.hpp

template<class sig>
class Signal;

template<class ReturnType, class... Args>
class Signal<ReturnType(Args...)> {
private:
    typedef std::function<ReturnType(Args...)> Slot;

public:
    void connect(Slot slot) {
        _slots.push_back(slot);
    }

    std::vector<ReturnType> operator() (Args... args) const {
        return emit(args...);
    }
    std::vector<ReturnType> emit(Args... args) const {
        std::vector<ReturnType> returnData;
        if (_slots.empty())
            return;
        for (auto &slot : _slots) {
            returnData.push_back(slot(args...));
        }
        return returnData;
    }
    void removeAllSlots() {
        _slots.clear();
    }
private:
    std::vector<Slot> _slots{};
};

template<class... Args>
class Signal<void(Args...)> {
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
    void removeAllSlots() {
        _slots.clear();
    }
private:
    std::vector<Slot> _slots{};
};
