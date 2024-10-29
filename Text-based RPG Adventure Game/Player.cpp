#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(int health, int meleeDamage, int rangedDamage, int healingPower, std::string name)
    : Character(health, meleeDamage, rangedDamage, healingPower, name) {}

void Player::Heal(int level) {
    cout <<getName() << " increases their Health by " <<getMeleeDamage() << " XP. \n";
    setHealth(min(getHealth() + getHealingPower(), 75 + level * 25));
    cout << "Current Health : " << getHealth() << "\n\n";
}


int Player::Attack(int level) {
    cout << "\n" << getName() << " is Attacking .... SUCCESSFUL HIT !! \n\n";
    int totalDamage = 0;
    int baseDamage = getMeleeDamage() + getRangedDamage();
    int addedBonus = 0;
    int specialAbilityBonus = 0;
    cout << "\nBase Damage : " << baseDamage << "\n";
    
    switch (level) {
    case level1:
        
        addedBonus = 0.25 * this->getMeleeDamage();
        break;
    case level2:
        
        addedBonus = 0.25 * baseDamage;
        break;
    case level3:
        
        addedBonus = 0.25 * baseDamage + 0.25 * getRangedDamage();
        specialAbilityBonus = (IsSuccessfulProbability(10) ? getMeleeDamage() : 0);
        break;
    case level4:
        
        addedBonus = 0.25 * baseDamage + 0.25 * getMeleeDamage();
        break;
    case level5:

        addedBonus = 0.5 * baseDamage;
        specialAbilityBonus = (IsSuccessfulProbability(10) ? (baseDamage + addedBonus) / 4 : 0);
        break;
    case level6:
        
        addedBonus = 1.5 * baseDamage;
        break;
    default:
        break;
    }
    cout << "Added Bonus : " << addedBonus << "\n";
    cout << "SpeciaL Ability Bonus : " << specialAbilityBonus << "\n";
    totalDamage = baseDamage + addedBonus + specialAbilityBonus;
    return totalDamage;
}