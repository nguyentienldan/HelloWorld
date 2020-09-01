#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H

#include <ctime>
#include <array>

class TimeManager {
    private:
    int m_day;
    int m_hour;
    std::time_t m_startTime;
    
    public:
    // constructors
    TimeManager();

    // update functions
    void updateTime();

    // getter functions
    std::array<int, 2> getTime();
};

#endif