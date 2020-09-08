#include "MacDonald.h"

std::vector< Animal* > MacDonald::m_farm;

MacDonald::MacDonald() {
    m_resource = ResourceManager::getInstance();
}

std::vector<Animal*>::iterator MacDonald::begin() {
    return m_farm.begin();
}

std::vector<Animal*>::iterator MacDonald::end() {
    return m_farm.end();
}

void MacDonald::feed( std::string option ) {
    if ( option == "animals" ) {
        for ( auto it = m_farm.begin(); it != m_farm.end(); it++ ) {
            int foodNeed = (*it)->eat();
            if ( foodNeed > m_resource->getFood() ) {
                std::cout << "Not enough food to feed animal\n";
                break;
            }
            else {
                (*it)->updateConsecutiveFedDay();
                (*it)->updateWeight();
                m_resource->setFood( -foodNeed );
            }
        }
    }
    else if ( option == "chickens" ) {
        for ( auto it = m_farm.begin(); it != m_farm.end(); it++ ) {
            if ( (*it)->getType() == "chicken" ) {
                int foodNeed = (*it)->eat();
                if ( foodNeed > m_resource->getFood() ) {
                    std::cout << "Not enough food to feed animal\n";
                    break;
                }
                else {
                    (*it)->updateConsecutiveFedDay();
                    (*it)->updateWeight();
                    m_resource->setFood( -foodNeed );
                }
            }
        }
    }
    else if ( option == "cats" ) {
        for ( auto it = m_farm.begin(); it != m_farm.end(); it++ ) {
            if ( (*it)->getType() == "cat" ) {
                int foodNeed = (*it)->eat();
                if ( foodNeed > m_resource->getFood() ) {
                    std::cout << "Not enough food to feed animal\n";
                    break;
                }
                else {
                    (*it)->updateConsecutiveFedDay();
                    (*it)->updateWeight();
                    m_resource->setFood( -foodNeed );
                }
            }
        }
    }
    else if ( option == "dogs" ) {
        for ( auto it = m_farm.begin(); it != m_farm.end(); it++ ) {
            if ( (*it)->getType() == "dog" ) {
                int foodNeed = (*it)->eat();
                if ( foodNeed > m_resource->getFood() ) {
                    std::cout << "Not enough food to feed animal\n";
                    break;
                }
                else {
                    (*it)->updateConsecutiveFedDay();
                    (*it)->updateWeight();
                    m_resource->setFood( -foodNeed );
                }
            }
        }
    }
    else if ( option == "pigs" ) {
        for ( auto it = m_farm.begin(); it != m_farm.end(); it++ ) {
            if ( (*it)->getType() == "pig" ) {
                int foodNeed = (*it)->eat();
                if ( foodNeed > m_resource->getFood() ) {
                    std::cout << "Not enough food to feed animal\n";
                    break;
                }
                else {
                    (*it)->updateConsecutiveFedDay();
                    (*it)->updateWeight();
                    m_resource->setFood( -foodNeed );
                }
            }
        }
    }
    else {
        for ( auto it = m_farm.begin(); it != m_farm.end(); it++ ) {
            if ( (*it)->getName() == option ) {
                int foodNeed = (*it)->eat();
                if ( foodNeed > m_resource->getFood() ) {
                    std::cout << "Not enough food to feed animal\n";
                    break;
                }
                else {
                    (*it)->updateConsecutiveFedDay();
                    (*it)->updateWeight();
                    m_resource->setFood( -foodNeed );
                }
            }
        }
    }
}

void MacDonald::report( std::string option ) {
    if ( option == "all" ) {
        for ( auto it = m_farm.begin(); it != m_farm.end(); it++ ) {
            std::cout << (*it)->getType() << '\t' << (*it)->getName() << '\n';
        }
        std::cout << "Money: " << m_resource->getMoney() << "\tFood: " << m_resource->getFood() << '\n';
    }
    else if ( option == "resource" ) {
        std::cout << "Money: " << m_resource->getMoney() << "\tFood: " << m_resource->getFood() << '\n';
    }
    else if ( option == "animals" ) {
        for ( auto it = m_farm.begin(); it != m_farm.end(); it++ ) {
            std::cout << (*it)->getType() << '\t' << (*it)->getName() << '\n';
        }
    }
    else {
        std::cout << "Wrong option\n";
    }
}

void MacDonald::letOut( std::string option ) {
    if ( option == "animals" ) {
        for ( auto it = m_farm.begin(); it != m_farm.end(); it++ ) {
            (*it)->goOut();
        }
    }
    else if ( option == "chickens" ) {
        for ( auto it = m_farm.begin(); it != m_farm.end(); it++ ) {
            if ( (*it)->getType() == "chicken" ) {
                (*it)->goOut();
            }
        }
    }
    else if ( option == "cats" ) {
        for ( auto it = m_farm.begin(); it != m_farm.end(); it++ ) {
            if ( (*it)->getType() == "cat" ) {
                (*it)->goOut();
            }
        }
    }
    else if ( option == "dogs" ) {
        for ( auto it = m_farm.begin(); it != m_farm.end(); it++ ) {
            if ( (*it)->getType() == "dog" ) {
                (*it)->goOut();
            }
        }
    }
    else if ( option == "pigs" ) {
        for ( auto it = m_farm.begin(); it != m_farm.end(); it++ ) {
            if ( (*it)->getType() == "pig" ) {
                (*it)->goOut();
            }
        }
    }
    else {
        for ( auto it = m_farm.begin(); it != m_farm.end(); it++ ) {
            if ( (*it)->getName() == option ) {
                (*it)->goOut();
            }
        }
    }
}

void MacDonald::letBack( std::string option ) {
    if ( option == "animals" ) {
        for ( auto it = m_farm.begin(); it != m_farm.end(); it++ ) {
            (*it)->goBack();
        }
    }
    else if ( option == "chickens" ) {
        for ( auto it = m_farm.begin(); it != m_farm.end(); it++ ) {
            if ( (*it)->getType() == "chicken" ) {
                (*it)->goBack();
            }
        }
    }
    else if ( option == "cats" ) {
        for ( auto it = m_farm.begin(); it != m_farm.end(); it++ ) {
            if ( (*it)->getType() == "cat" ) {
                (*it)->goBack();
            }
        }
    }
    else if ( option == "dogs" ) {
        for ( auto it = m_farm.begin(); it != m_farm.end(); it++ ) {
            if ( (*it)->getType() == "dog" ) {
                (*it)->goBack();
            }
        }
    }
    else if ( option == "pigs" ) {
        for ( auto it = m_farm.begin(); it != m_farm.end(); it++ ) {
            if ( (*it)->getType() == "pig" ) {
                (*it)->goBack();
            }
        }
    }
    else {
        for ( auto it = m_farm.begin(); it != m_farm.end(); it++ ) {
            if ( (*it)->getName() == option ) {
                (*it)->goBack();
            }
        }
    }
}

void MacDonald::buy( std::string type, std::string name ) {
    Animal *newAnimal = nullptr;
    if ( type == "chicken" ) {
        newAnimal = new Chicken( name );
        m_resource->setMoney(-4);
    }
    else if ( type == "cat" ) {
        newAnimal = new Cat( name );
        m_resource->setMoney(-7);

    }
    else if ( type == "dog" ) {
        newAnimal = new Dog( name );
        m_resource->setMoney(-8);
    }
    else if ( type == "pig" ) {
        newAnimal = new Pig( name );
        m_resource->setMoney(-6);
    }
    if ( newAnimal != nullptr ) {
        addAnimal( newAnimal );
    } 
}

void MacDonald::sell( std::string type, std::string name ) {
    if ( name == "" ) {
        for ( auto it = m_farm.begin(); it != m_farm.end(); it++ ) {
            if ( (*it)->getType() == type && (*it)->ableToSell() ) {
                m_resource->setMoney( (*it)->getSellPrice() );
                m_farm.erase(it);
            }
        }
    }
    else {
        for ( auto it = m_farm.begin(); it != m_farm.end(); it++ ) {
            if ( (*it)->getType() == type && (*it)->getName() == name && (*it)->ableToSell() ) {
                m_resource->setMoney( (*it)->getSellPrice() );
                m_farm.erase(it);
            }
        }
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