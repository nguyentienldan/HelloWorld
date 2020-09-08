#ifndef DOG_H
#define DOG_H

#include "Animal.h"
#include "TimeManager.h"
#include "Chicken.h"
#include "MacDonald.h"
#include "Cat.h"

class Dog : public Animal {
    private:
    static std::vector< Animal* >m_chickenAndCatSubscribers;
    int feedDay[2];
    int m_intelligentIndex;
    int m_numTrainPerDay;
    public:
    Dog( std::string name );

    void updateSubscribeList() override;
    void notifySubscribers( int numSound ) override;
    void updateWeight() override;
    void updateConsecutiveFedDay() override;
    void updateHappyIndex() override;
    void updateSoundMade() override;
    int eat() override;
    void reproduce() override;
    bool ableToSell() override;
    void die() override;

    void train();
};

#endif