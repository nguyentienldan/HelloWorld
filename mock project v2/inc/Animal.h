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
    int m_numSoundHeard;
    int m_numSoundMade;
    int m_numSoundCanMadePerDay;

    // variable to check if new day has came
    int m_prevDay;

    public:
    // constructors
    Animal( std::string name );

    // update functions
    void updateAge();
    virtual void updateWeight() = 0;
    virtual void updateNumSoundHeard() = 0;
    virtual void updateNumSoundMade() = 0;
    void updateNumSoundCanMadePerDay();

    // getter and setter functions
    int getSoundMade() const;

    bool isNewDay();
};

#endif