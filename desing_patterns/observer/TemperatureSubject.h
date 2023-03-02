#pragma once

#include <chrono>
#include <thread>

#include "Subject.h"

using namespace std::chrono_literals;
class TemperatureSubject : public ISubject {
public:
    void startMeasuring() {
        _t = std::thread([this]() {
            while (true) {
                std::this_thread::sleep_for(100ms);
                notify();
            }
        });
    }

private:
    std::thread _t;
};