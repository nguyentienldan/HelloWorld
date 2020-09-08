#ifndef MACDONALD_H
#define MACDONALD_H

#include "Animal.h"
#include "ResourceManager.h"
#include "Chicken.h"
#include "Dog.h"
#include "Cat.h"
#include "Pig.h"
#include <vector>

class MacDonald {
    private:
    static std::vector<Animal*> m_farm;
    ResourceManager *m_resource;
    public:
    MacDonald();
    static std::vector<Animal*>::iterator begin();
    static std::vector<Animal*>::iterator end();
    void feed( std::string option );
    void report( std::string option );
    void letOut( std::string option );
    void letBack( std::string option );
    void buy( std::string type, std::string name );
    void sell( std::string type, std::string name = "" );

    void updateFarm();
    static void addAnimal( Animal* newAnimal );
    static void removeAnimal( Animal* animal );

};

#endif