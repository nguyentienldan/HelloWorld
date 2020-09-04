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
        (*it)->updateSoundHeard( numSound );
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