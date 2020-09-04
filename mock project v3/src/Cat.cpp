#include "Cat.h"

std::vector< Animal* > Cat::m_chickenAndDogSubscribers;

Cat::Cat( std::string name ) : Animal( name ) {
    m_type = "cat";
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