#ifndef MACDONALD_H
#define MACDONALD_H

#include "Animal.h"
#include <vector>

class MacDonald {
    private:
    static std::vector<Animal*> m_farm;
    public:
    static std::vector<Animal*>::iterator begin();
    static std::vector<Animal*>::iterator end();
    void feedAnimal();
    static void addAnimal( Animal* newAnimal );
    static void removeAnimal( Animal* animal );
};

#endif