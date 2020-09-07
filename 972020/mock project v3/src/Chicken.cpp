#include "Chicken.h"

std::vector< Animal* > Chicken::m_catSubscribers;

Chicken::Chicken( std::string name ) : Animal( name ), feedDay{0, 0} {
    m_type = "chicken";
}

void Chicken::updateSubscribeList() {
    for ( auto it = MacDonald::begin(); it != MacDonald::end(); it++ ) {
        if ( (*it)->getType() == "cat" )
            m_catSubscribers.push_back( (*it) );
    }
}

void Chicken::notifySubscribers( int numSound ) {
    for ( auto it = m_catSubscribers.begin(); it != m_catSubscribers.end(); it++ ) {
        if ( (*it)->isGoOut() == false ) {
            (*it)->updateSoundHeard( numSound );
        }
    }
}

void Chicken::updateConsecutiveFedDay() {
    std::array< int, 2 >currentTime = TimeManager::getTime();
    feedDay[m_consecutiveFedDay] = currentTime[0];
    m_consecutiveFedDay++;
}

void Chicken::updateWeight() {
    if ( m_consecutiveFedDay == 2 ) {
        if ( feedDay[1] - feedDay[0] == 1 ) {
            m_weight += 0.2;
        }
        else {
            m_consecutiveFedDay = 1;
            feedDay[0] = feedDay[1];
        }
    }
}

void Chicken::updateHappyIndex() {
    if ( m_goOut == true ) {
        m_happyIndex += 2;
    }
    else {
        if ( m_numDayNotGoOut == 2 ) {
            m_happyIndex -= 1;
            m_numDayNotGoOut = 0;
        }
        if ( m_soundHeard >= 10 ) {
            m_happyIndex -= 1;
            m_soundHeard = 0;
        }
    }
    if ( m_happyIndex == 0 ) {
        updateHappyZeroDay();
    }
}

int Chicken::eat() {
    if ( m_happyIndex < 3 ) {
        return 0;
    }
    else {
        return 1;
    }
}

void Chicken::reproduce() {
    if ( m_age == 13 && m_weight == 2 && m_happyIndex == 10 ) {
        int numberOfChild = genRandomNum( 3 );
        for ( int i = 1; i <= numberOfChild; i++ ) {
            std::string name;
            std::cout << "Enter name of new chicken: ";
            std::getline( std::cin, name );
            Animal* newChicken = new Chicken( name );
            MacDonald::addAnimal( newChicken );
        }
    }
}

void Chicken::die() {
    bool isDead = false;
    if ( m_age == 15 ) {
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