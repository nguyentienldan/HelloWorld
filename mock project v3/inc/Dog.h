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
    public:
    Dog( std::string name );

    void updateSubscribeList() override;
    void notifySubscribers( int numSound ) override;
};

#endif