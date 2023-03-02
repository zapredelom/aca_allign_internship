#pragma once
#include <iostream>
#include "Observer.h"

class Display : public IObserver{
    public:
        void update() override{
            std::cout<<"Display updated"<<std::endl;
        }
};