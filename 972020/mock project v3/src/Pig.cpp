#include "Pig.h"

std::vector< Animal* > Pig::m_chickenSubscribers;

Pig::Pig( std::string name ) : Animal( name ) {
    m_type = "pig";
}

void Pig::updateSubscribeList() {
    for ( auto it = MacDonald::begin(); it != MacDonald::end(); it++ ) {
        if ( (*it)->getType() == "chicken" )
            m_chickenSubscribers.push_back( (*it) );
    }
}

void Pig::notifySubscribers( int numSound ) {
    for ( auto it = m_chickenSubscribers.begin(); it != m_chickenSubscribers.end(); it++ ) {
        (*it)->updateSoundHeard( numSound );
    }
}

void Pig::updateConsecutiveFedDay() {
}

void Pig::updateWeight() {
    m_weight += 1;
}

void Pig::updateHappyIndex() {
}

int Pig::eat() {
    if ( m_age < 2 ) {
        return 0;
    }
    else {
        return 7;
    }
}

void Pig::reproduce() {
    if ( m_age == 20 && m_weight == 10 ) {
        int numberOfChild = genRandomNum( 2 );
        for ( int i = 1; i <= numberOfChild; i++ ) {
            std::string name;
            std::cout << "Enter name of new pig: ";
            std::getline( std::cin, name );
            Animal* newPig = new Pig( name );
            MacDonald::addAnimal( newPig );
        }
    }
}

void Pig::die() {
    bool isDead = false;
    if ( m_age == 22 ) {
        isDead = true;
    }
    if ( isDead == true ) {
        MacDonald::removeAnimal( this );
    }
}