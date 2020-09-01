#ifndef CHICKEN_H
#define CHICKEN_H

#include "Animal.h"
#include "TimeManager.h"

extern TimeManager timeManager;

class Chicken : public Animal {
    const int MAX_WEIGHT = 2;
    int feedTime;
    int feedDay[2];
    public:
    Chicken( std::string name );
    void updateWeight() override;

    void setFeedTimeAndFeedDay();
};

#endif