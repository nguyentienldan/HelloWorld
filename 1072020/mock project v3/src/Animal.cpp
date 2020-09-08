#include "Animal.h"
#include "TimeManager.h"

int Animal::m_numAnimal = 0;

Animal::Animal( std::string name ) : m_name{ name }, m_weight{0}, m_sellPrice{0}, m_buyPrice{0},
                                     m_soundMade{0}, m_soundHeard{0}, m_numOfSoundPerDay{1},
                                     m_numReduceHappyPerDay{1}, m_numDayNotGoOut{0}, m_happyIndex{7},
                                     m_consecutiveFedDay{0}, m_goOut{false}, m_type{ "" }, m_numDayHappyZero{0}
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

void Animal::updateHappyZeroDay() {
    std::array<int, 2> currentTime = TimeManager::getTime();
    m_dayHappyZero[m_numDayHappyZero] = currentTime[0];
    m_numDayHappyZero++;
}

void Animal::updateSoundMadeWithNumber( int num ) {
    m_soundMade += num;
}

// reset functions
void Animal::reset() {
    m_soundMade = 0;
    m_soundHeard = 0;
    m_numOfSoundPerDay = 1;
    m_numReduceHappyPerDay = 1;
    m_numGoOutPerDay = 1;
}

// getter functions
std::string Animal::getName() const {
    return m_name;
}

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

std::array<int, 3> Animal::getHappyZeroDay() const {
    return m_dayHappyZero;
}

int Animal::getNumHappyZeroDay() const {
    return m_numDayHappyZero;
}

int Animal::getSellPrice() const {
    return m_sellPrice;
}

void Animal::setNumHayppyZeroDay() {
    m_numDayHappyZero = 2;
}

void Animal::setHappyZeroDay() {
    m_dayHappyZero[0] = m_dayHappyZero[1];
    m_dayHappyZero[1] = m_dayHappyZero[2];
}

int Animal::genRandomNum( int range ) {
    srand( (unsigned)time(0) );
    int randomNumber = 0;
    do {
        randomNumber = rand() % range + 1;
    }
    while( randomNumber == 0 );
    return randomNumber;
}

void Animal::goOut() {
    std::array<int, 2>currentTime = TimeManager::getTime();
    if ( currentTime[1] >= 4 && currentTime[1] <= 23 ) {
        m_goOut = true;
        m_goOutDay = currentTime[0];
    }
}

void Animal::goBack() {
    m_goOut = false;
}

bool Animal::isGoOut() {
    return m_goOut;
}

