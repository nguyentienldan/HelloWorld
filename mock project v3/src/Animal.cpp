#include "Animal.h"
#include "TimeManager.h"

int Animal::m_numAnimal = 0;

Animal::Animal( std::string name ) : m_name{ name }, m_weight{0}, m_sellPrice{0}, m_buyPrice{0},
                                     m_soundMade{0}, m_soundHeard{0}, m_numOfSoundPerDay{1},
                                     m_numReduceHappyPerDay{1}, m_numDayNotGoOut{0}, m_happyIndex{7},
                                     m_consecutiveFedDay{0}, m_goOut{false}, m_type{ "" }
{
    // initialize id for animal
    m_numAnimal++;
    m_id = m_numAnimal;

    // initialize birthday for animal
    std::array< int, 2 >birthday = TimeManager::getTime();
    m_birthday = birthday[0];
}

// update functions
void Animal::updateAge( int currentDay ) {
    m_age = currentDay - m_birthday;
}

void Animal::updateSoundHeard( int numSound ) {
    m_soundHeard += numSound;
}

// getter functions
int Animal::getId() const {
    return m_id;
}

int Animal::getBirthday() const {
    return m_birthday;
}

int Animal::getAge() const {
    return m_age;
}

std::string Animal::getType() const {
    return m_type;
}