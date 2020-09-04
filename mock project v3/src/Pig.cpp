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