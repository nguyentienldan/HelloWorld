#include "Chicken.h"

// constructors
Chicken::Chicken( std::string name ) : Animal( name ) {
    feedTime = 0;
    feedDay[0] = 0;
    feedDay[1] = 0;
    happyIndex = 7;
}

// update functions
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

void Chicken::updateNumSoundHeard() {
    for ( auto it = farm.begin(); it != farm.end(); it++ ) {
        m_numSoundHeard += (*it)->getSoundMade();
    }
}

// update number of sound made by time
void Chicken::updateNumSoundMade() {
    std::array<int , 2>currentTime = timeManager.getTime();
    if ( currentTime[1] == 6 && m_numSoundCanMadePerDay != 0 ) {
        std::cout << "Bawk\n";
        m_numSoundMade++;
        m_numSoundCanMadePerDay--;
    }
}

// getter and setter functions
void Chicken::setFeedTimeAndFeedDay() {
    std::array<int, 2>currentTime = timeManager.getTime();
    feedDay[feedTime] = currentTime[0];
    feedTime++;
}