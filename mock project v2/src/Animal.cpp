#include "Animal.h"

// constructors
Animal::Animal( std::string name ) : m_name{name}, m_age{0}, m_weight{0}, m_numSoundHeard{0}, m_numSoundMade{0},
                                     m_numSoundCanMadePerDay{1} {
    std::array<int, 2>currentTime = timeManager.getTime();
    m_birthday = currentTime[0];
    m_prevDay = m_birthday;
}

// update functions
void Animal::updateAge() {
    std::array<int, 2>currentTime = timeManager.getTime();
    m_age = currentTime[0] - m_birthday;
}

void Animal::updateNumSoundCanMadePerDay() {
    if ( isNewDay() ) {
        m_numSoundCanMadePerDay = 1;
    }
}

// getter and setter functions
int Animal::getSoundMade() const {
    return m_numSoundMade;
}

bool Animal::isNewDay() {
    std::array<int, 2>currentTime = timeManager.getTime();
    if (m_prevDay == currentTime[0]) {
        return false;
    }
    else {
        m_prevDay = currentTime[0];
        return true;
    }
}