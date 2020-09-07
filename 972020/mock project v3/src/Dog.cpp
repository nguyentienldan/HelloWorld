#include "Dog.h"

std::vector< Animal* > Dog::m_chickenAndCatSubscribers;

Dog::Dog( std::string name ) : Animal( name ) {
    m_type = "dog";
    m_intelligentIndex = 0;
    m_numTrainPerDay = 1;
}

void Dog::updateSubscribeList() {
    for ( auto it = MacDonald::begin(); it != MacDonald::end(); it++ ) {
        if ( (*it)->getType() == "chicken" )
            m_chickenAndCatSubscribers.push_back( (*it) );
    }
}

void Dog::notifySubscribers( int numSound ) {
    for ( auto it = m_chickenAndCatSubscribers.begin(); it != m_chickenAndCatSubscribers.end(); it++ ) {
        (*it)->updateSoundHeard( numSound );
    }
}

void Dog::updateConsecutiveFedDay() {
    std::array< int, 2 >currentTime = TimeManager::getTime();
    feedDay[m_consecutiveFedDay] = currentTime[0];
    m_consecutiveFedDay++;
}

void Dog::updateWeight() {
    if ( m_consecutiveFedDay == 2 ) {
        if ( feedDay[1] - feedDay[0] == 1 ) {
            m_weight += 1;
        }
        else {
            m_consecutiveFedDay = 1;
            feedDay[0] = feedDay[1];
        }
    }
}

void Dog::updateHappyIndex() {
    if ( m_goOut == true ) {
        m_happyIndex += 2;
    }
    else {
        if ( m_numDayNotGoOut == 2 ) {
            m_happyIndex -= 1;
            m_numDayNotGoOut = 0;
        }
        if ( m_soundHeard >= 5 ) {
            m_happyIndex -= 1;
            m_soundHeard = 0;
        }
    }
}

int Dog::eat() {
    if ( m_happyIndex < 3 || m_age < 3 ) {
        return 0;
    }
    else {
        return 3;
    }
}

void Dog::reproduce() {
    if ( m_age == 22 && m_weight == 7 && m_happyIndex == 10 && m_intelligentIndex == 10 ) {
        std::string name;
        std::cout << "Enter name of new dog: ";
        std::getline( std::cin, name );
        Animal* newDog = new Dog( name );
        MacDonald::addAnimal( newDog );
    }
}

void Dog::die() {
    bool isDead = false;
    if ( m_age == 25 ) {
        isDead = true;
    }
    if ( getNumHappyZeroDay() == 3 ) {
        std::array<int, 3> zeroDay = getHappyZeroDay();
        if ( zeroDay[1] - zeroDay[0] == 1 && zeroDay[2] - zeroDay[1] == 1 ) {
            isDead = true;
        }
        setHappyZeroDay();
        setNumHayppyZeroDay();
    }
    if ( isDead == true ) {
        MacDonald::removeAnimal( this );
    }
}

void Dog::train() {
    if ( m_numTrainPerDay != 0 ) {
        m_intelligentIndex += 2;
        m_numTrainPerDay--;
    }
}