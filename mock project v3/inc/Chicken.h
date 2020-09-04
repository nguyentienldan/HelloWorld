#ifndef CHICKEN_H
#define CHICKEN_H

#include "Animal.h"
#include "TimeManager.h"
#include "Cat.h"
#include "MacDonald.h"

class Chicken : public Animal {
    private:
    static std::vector< Animal* >m_catSubscribers;
    int feedDay[2];
    public:
    Chicken( std::string name );

    void updateSubscribeList() override;
    void notifySubscribers( int numSound ) override;
    void updateWeight() override;
    void updateConsecutiveFedDay() override;
};

#endif