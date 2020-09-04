#include "TimeManager.h"

int TimeManager::m_days = 0;
int TimeManager::m_hours = 0;

// constructor
TimeManager::TimeManager() {
    m_startTime = time( nullptr );
}

void TimeManager::addSubscribers( Animal *animal ) {
    m_animalSubscribers.push_back( animal );
}

void TimeManager::removeSubscribers( Animal *animal ) {
    for ( auto it = m_animalSubscribers.begin(); it != m_animalSubscribers.end(); it++ )
        if ( (*it)->getId() == animal->getId() )
            m_animalSubscribers.erase(it);
}

void TimeManager::updateTime() {
    std::time_t currentSecond = time( nullptr );
    std::time_t currentHour = (currentSecond - m_startTime) / 3;
    m_days = static_cast<int>( currentHour / 24 );
    m_hours = static_cast<int>( currentHour % 24 );

    // update age for all animal
    for ( auto it = m_animalSubscribers.begin(); it != m_animalSubscribers.end(); it++ ) {
        (*it)->updateAge( m_days ); 
    }
}

std::array<int, 2> TimeManager::getTime() {
    std::array<int, 2> currentTime;
    currentTime[0] = m_days;
    currentTime[1] = m_hours;
    return currentTime;
}