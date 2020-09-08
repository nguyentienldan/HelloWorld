#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

class ResourceManager {
    private:
    static ResourceManager* m_instancePtr;
    int m_food;
    int m_money;

    ResourceManager();
    public:
    static ResourceManager* getInstance();
    int getFood() const;
    int getMoney() const;
    void setFood( int amount );
    void setMoney( int amount );
};

#endif