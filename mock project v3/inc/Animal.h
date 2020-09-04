#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal {
    protected:
    std::string m_name;
    int m_age;
    float m_weight;
    int m_sellPrice;
    int m_buyPrice;
    int m_soundMade;
    int m_soundHeard;
    int m_numOfSoundPerDay;
    int m_numReduceHappyPerDay;
    int m_numGoOutPerDay;
    int m_numDayNotGoOut;
    int m_happyIndex;
    int m_birthday;
    int m_consecutiveFedDay;
    bool m_goOut;
    static int m_numAnimal;
    int m_id;
    std::string m_type;
    public:
    // constructors
    Animal( std::string name );

    // update functions
    void updateAge( int currentAge );
    virtual void updateWeight() = 0;
    virtual void updateConsecutiveFedDay() = 0;
    // virtual void updateSoundMade() = 0;
    // virtual void updateHappyIndex() = 0;
    virtual void updateSubscribeList() = 0;
    virtual void notifySubscribers( int numSound ) = 0;
    void updateSoundHeard( int numSound );

    // behaviour functions
    // virtual void eat() = 0;
    // virtual void reproduce() = 0;
    // virtual void goOut() = 0;
    bool isGoOut();
    // virtual void die() = 0;

    // getter functions
    int getId() const;
    int getBirthday() const;
    int getAge() const;
    std::string getType() const;
};

#endif