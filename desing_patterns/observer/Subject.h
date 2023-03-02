#pragma once

#include <vector>

#include "Observer.h"
class ISubject {
public:
    void attach(IObserver* o) { _observers.push_back(o); }

    void attach(int Topic, IObserver* o) {}

    void detach(IObserver* o);

    virtual void notify_all() final {
        for (IObserver* o : _observers) {
            o->update();
        }
    }

      virtual void notify(int Topic) final {
        if(_observers.contains(topic)) {
            for(IObserver* o: _observers[topic] ){
                o->update();
            }
        }
    }

private:
    std::unordered_map<int, IObserver*> _observers;
};