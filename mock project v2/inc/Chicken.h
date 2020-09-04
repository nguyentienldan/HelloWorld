#ifndef CHICKEN_H
#define CHICKEN_H

#include "Animal.h"
#include "TimeManager.h"
#include <vector>

extern TimeManager timeManager;
extern std::vector<Animal*> farm;

class Chicken : public Animal {
    const int MAX_WEIGHT = 2;
    int feedTime;
    int feedDay[2];
    int happyIndex;
    public:
    // constructors
    Chicken( std::string name );

    // update functions
    void updateWeight() override;
    void updateNumSoundHeard() override;
    void updateNumSoundMade() override;

    // getter and setter functions
    void setFeedTimeAndFeedDay();
};

#endif