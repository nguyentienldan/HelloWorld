#include "ResourceManager.h"

ResourceManager* ResourceManager::m_instancePtr = nullptr;

ResourceManager::ResourceManager() : m_food{50}, m_money{20} {

}

ResourceManager* ResourceManager::getInstance() {
    if ( m_instancePtr == nullptr ) {
        m_instancePtr = new ResourceManager();
    }
    return m_instancePtr;
}

int ResourceManager::getFood() const {
    return m_food;
}

int ResourceManager::getMoney() const {
    return m_money;
}

void ResourceManager::setFood( int amount ) {
    m_food += amount;
};

void ResourceManager::setMoney( int amount ) {
    m_money += amount;
};