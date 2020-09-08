#ifndef PIG_H
#define PIG_H

#include "Animal.h"
#include "TimeManager.h"
#include "Chicken.h"
#include "MacDonald.h"

class Pig : public Animal {
    private:
    static std::vector< Animal* >m_chickenSubscribers;
    public:
    Pig( std::string name );

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
};

#endif