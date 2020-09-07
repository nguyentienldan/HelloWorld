#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H

#include <ctime>
#include <vector>
#include <array>
#include "Animal.h"

class TimeManager {
    private:
    static int m_days;
    static int m_hours;
    std::time_t m_startTime;
    std::vector< Animal* > m_animalSubscribers;
    
    public:
    TimeManager();
    void addSubscribers( Animal *animal );
    void removeSubscribers( Animal *animal );
    void updateTime();
    static std::array< int, 2 > getTime();
};

#endif