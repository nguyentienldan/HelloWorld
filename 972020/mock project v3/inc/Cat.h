#ifndef CAT_H
#define CAT_H

#include "Animal.h"
#include "TimeManager.h"
#include "Chicken.h"
#include "MacDonald.h"

class Cat : public Animal {
    private:
    static std::vector< Animal* >m_chickenAndDogSubscribers;
    int feedDay[3];
    public:
    Cat( std::string name );

    void updateSubscribeList() override;
    void notifySubscribers( int numSound ) override;
    void updateWeight() override;
    void updateConsecutiveFedDay() override;
    void updateHappyIndex() override;
    int eat() override;
    void reproduce() override;
    void goOut() override;
    void die() override;
};

#endif