#include "TemperatureSubject.h"
#include "Display.h"
#include "Heater.h"

int main() {
    TemperatureSubject* subject = new TemperatureSubject();
    Display d;
    HeaterObserver h;

    subject->attach(&d);
    subject->attach(&h);
    subject->startMeasuring();
    std::this_thread::sleep_for(10s);
}