#include "TimeManager.h"

// constructors
TimeManager::TimeManager() : m_day{ 0 }, m_hour{ 0 } {
    m_startTime = time( nullptr );
}

// update functions
void TimeManager::updateTime() {
    std::time_t currentSecond = time( nullptr );
    std::time_t currentHour = (currentSecond - m_startTime) / 3;
    m_day = static_cast<int>( currentHour / 24 );
    m_hour = static_cast<int>( currentHour % 24 );
}

// getter functions
std::array<int, 2> TimeManager::getTime() {
    std::array<int, 2> currentTime;
    currentTime[0] = m_day;
    currentTime[1] = m_hour;
    return currentTime;
}