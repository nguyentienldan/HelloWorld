#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <array>

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
    int m_goOutDay;
    int m_numDayHappyZero;
    std::array<int, 3> m_dayHappyZero;

    public:
    // constructors
    Animal( std::string name );

    // update functions
    void updateAge( int currentAge );
    virtual void updateWeight() = 0;
    virtual void updateConsecutiveFedDay() = 0;
    void updateHappyZeroDay();
    
    // function updateSoundMade() makes animal speaks when time's come 
    virtual void updateSoundMade() = 0;
    virtual void updateHappyIndex() = 0;
    virtual void updateSubscribeList() = 0;
    virtual void notifySubscribers( int numSound ) = 0;
    void updateSoundHeard( int numSound );
    void updateSoundMadeWithNumber( int num );

    // reset functions
    void reset();

    // behaviour functions
    virtual int eat() = 0;
    virtual void reproduce() = 0;
    int genRandomNum( int range );
    virtual void goOut();
    void goBack();
    bool isGoOut();
    virtual bool ableToSell() = 0;
    virtual void die() = 0;

    // getter functions
    std::string getName() const;
    int getId() const;
    int getBirthday() const;
    int getAge() const;
    std::string getType() const;
    std::array<int, 3> getHappyZeroDay() const;
    int getNumHappyZeroDay() const;
    int getSellPrice() const;

    void setNumHayppyZeroDay();
    void setHappyZeroDay();
};

#endif