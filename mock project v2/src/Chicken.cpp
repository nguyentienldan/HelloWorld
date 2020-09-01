#include "Chicken.h"

Chicken::Chicken( std::string name ) : Animal( name ) {
    feedTime = 0;
    feedDay[0] = 0;
    feedDay[1] = 0;
}

void Chicken::updateWeight() {
    if ( feedTime == 2 ) {
        if ( feedDay[1] - feedDay[0] == 1 ) {
            m_weight += 0.2;
            feedTime = 0;
            feedDay[0] = 0;
            feedDay[1] = 0;
        }
        else {
            feedTime = 1;
            feedDay[0] = feedDay[1];
        }
    }
}

void Chicken::setFeedTimeAndFeedDay() {
    std::array<int, 2>currentTime = timeManager.getTime();
    feedDay[feedTime] = currentTime[0];
    feedTime++;
}