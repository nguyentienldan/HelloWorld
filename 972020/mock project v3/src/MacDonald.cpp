#include "MacDonald.h"

std::vector< Animal* > MacDonald::m_farm;

std::vector<Animal*>::iterator MacDonald::begin() {
    return m_farm.begin();
}

std::vector<Animal*>::iterator MacDonald::end() {
    return m_farm.end();
}

void MacDonald::feedAnimal() {
    for ( auto it = m_farm.begin(); it != m_farm.end(); it++ ) {
        (*it)->updateConsecutiveFedDay();
        (*it)->updateWeight();
    }
}

void MacDonald::addAnimal( Animal* newAnimal ) {
    m_farm.push_back( newAnimal );
}

void MacDonald::removeAnimal( Animal* animal ) {
    for ( auto it = m_farm.begin(); it != m_farm.end(); it++ ) {
        if ( (*it)->getId() == animal->getId() ) {
            m_farm.erase(it);
        }
    }
}