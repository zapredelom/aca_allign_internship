#pragma once

#include "Observer.h"

class HeaterObserver : public IObserver{
    public:
        void update() override{
            std::cout<<"HeaterObserver updated"<<std::endl;
        }
};