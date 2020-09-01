#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include "TimeManager.h"

extern TimeManager timeManager;

class Animal {
    protected:
    std::string m_name;
    int m_age;
    float m_weight;
    int m_birthday;

    public:
    Animal( std::string name );
    void updateAge();
    virtual void updateWeight() = 0;
};

#endif