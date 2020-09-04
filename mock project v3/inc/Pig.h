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
};

#endif