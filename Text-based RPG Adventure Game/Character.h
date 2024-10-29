#pragma once
#include <string>
using namespace std;


enum Level {
    level0,
    level1,
    level2,
    level3,
    level4,
    level5,
    level6,
    level7
};

class Character {
protected:
    string name;
    int health;
    int meleeDamage;
    int rangedDamage;
    int healingPower;

public:
    Character();
    Character(int health, int meleeDamage, int rangedDamage, int healingPower, string name = "Enemy");

    
    string getName();
    int getHealth();
    int getMeleeDamage();
    int getRangedDamage();
    int getHealingPower();

    
    void setName(string value);
    void setHealth(int value);
    void setMeleeDamage(int value);
    void setRangedDamage(int value);
    void setHealingPower(int value);

    virtual int Attack(int level) = 0;
    virtual void Heal(int level) = 0;
    void GetCharacterDetails();
    bool IsSuccessfulProbability(int prob);

};
