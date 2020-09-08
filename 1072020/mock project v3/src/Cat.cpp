#include "Cat.h"

std::vector< Animal* > Cat::m_chickenAndDogSubscribers;

Cat::Cat( std::string name ) : Animal( name ) {
    m_type = "cat";
    m_sellPrice = 4;
}

void Cat::updateSubscribeList() {
    for ( auto it = MacDonald::begin(); it != MacDonald::end(); it++ ) {
        if ( (*it)->getType() == "chicken" || (*it)->getType() == "dog" )
            m_chickenAndDogSubscribers.push_back( (*it) );
    }
}

void Cat::notifySubscribers( int numSound ) {
    for ( auto it = m_chickenAndDogSubscribers.begin(); it != m_chickenAndDogSubscribers.end(); it++ ) {
        (*it)->updateSoundHeard( numSound );
    }
}

void Cat::updateConsecutiveFedDay() {
    std::array< int, 2 >currentTime = TimeManager::getTime();
    feedDay[m_consecutiveFedDay] = currentTime[0];
    m_consecutiveFedDay++;
}

void Cat::updateWeight() {
    if ( m_consecutiveFedDay == 3 ) {
        if ( feedDay[1] - feedDay[0] == 1 && feedDay[2] - feedDay[1] == 1 ) {
            m_weight += 1;
        }
        else {
            m_consecutiveFedDay = 2;
            feedDay[0] = feedDay[1];
            feedDay[1] = feedDay[2];
        }
    }
}

void Cat::updateHappyIndex() {
    if ( m_goOut == true ) {
        m_happyIndex += 2;
    }
    else {
        if ( m_numDayNotGoOut == 2 ) {
            m_happyIndex -= 1;
            m_numDayNotGoOut = 0;
        }
        if ( m_soundHeard >= 15 ) {
            m_happyIndex -= 1;
            m_soundHeard = 0;
        }
    }
}

void Cat::updateSoundMade() {
    std::array<int, 2>currentTime = TimeManager::getTime();
    if ( m_numOfSoundPerDay != 0 && currentTime[1] == 1 ) {
        m_soundMade++;
        m_numOfSoundPerDay--;
    }
}

int Cat::eat() {
    if ( m_happyIndex < 3 || m_age < 2 ) {
        return 0;
    }
    else {
        m_soundMade++;
        return 1;
    }
}

void Cat::reproduce() {
    if ( m_age == 18 && m_weight == 4 && m_happyIndex == 10 ) {
        std::string name;
        std::cout << "Enter name of new cat: ";
        std::getline( std::cin, name );
        Animal* newCat = new Cat( name );
        newCat->updateSoundMadeWithNumber(2);
        MacDonald::addAnimal( newCat );
    }
}

void Cat::goOut() {
    m_goOut = true;
}

bool Cat::ableToSell() {
    if ( m_age > 10 ) {
        return true;
    }
    return false;
}

void Cat::die() {
    bool isDead = false;
    if ( m_age == 20 ) {
        isDead = true;
    }
    if ( getNumHappyZeroDay() == 3 ) {
        std::array<int, 3> zeroDay = getHappyZeroDay();
        if ( zeroDay[1] - zeroDay[0] == 1 && zeroDay[2] - zeroDay[1] == 1 ) {
            isDead = true;
        }
        setHappyZeroDay();
        setNumHayppyZeroDay();
    }
    if ( isDead == true ) {
        updateSoundMadeWithNumber(3);
        MacDonald::removeAnimal( this );
    }
}