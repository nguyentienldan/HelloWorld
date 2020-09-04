#include "Dog.h"

std::vector< Animal* > Dog::m_chickenAndCatSubscribers;

Dog::Dog( std::string name ) : Animal( name ) {
    m_type = "dog";
}

void Dog::updateSubscribeList() {
    for ( auto it = MacDonald::begin(); it != MacDonald::end(); it++ ) {
        if ( (*it)->getType() == "chicken" )
            m_chickenAndCatSubscribers.push_back( (*it) );
    }
}

void Dog::notifySubscribers( int numSound ) {
    for ( auto it = m_chickenAndCatSubscribers.begin(); it != m_chickenAndCatSubscribers.end(); it++ ) {
        (*it)->updateSoundHeard( numSound );
    }
}