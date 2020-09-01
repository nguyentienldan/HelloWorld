#include "Animal.h"

// constructors
Animal::Animal( std::string name ) : m_name{name}, m_age{0}, m_weight{} {
    std::array<int, 2>currentTime = timeManager.getTime();
    m_birthday = currentTime[0];
}

// update functions
void Animal::updateAge() {
    std::array<int, 2>currentTime = timeManager.getTime();
    m_age = currentTime[0] - m_birthday;
}