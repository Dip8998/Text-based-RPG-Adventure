#include "Character.h"
#include <iostream>
using namespace std;

Character::Character() {}

Character::Character(int health, int meleeDamage, int rangedDamage, int healingPower, string name)
    : health(health), meleeDamage(meleeDamage), rangedDamage(rangedDamage), healingPower(healingPower), name(name) {}

string Character::getName() { 
    return name; 
}
int Character::getHealth() { 
    return health; 
}
int Character::getMeleeDamage() { 
    return meleeDamage; 
}
int Character::getRangedDamage() { 
    return rangedDamage; 
}
int Character::getHealingPower() { 
    return healingPower; 
}

void Character::setName(string value) { 
    name = value; 
}
void Character::setHealth(int value) { 
    health = value; 
}
void Character::setMeleeDamage(int value) { 
    meleeDamage = value; 
}
void Character::setRangedDamage(int value) { 
    rangedDamage = value; 
}
void Character::setHealingPower(int value) { 
    healingPower = value; 
}

bool Character::IsSuccessfulProbability(int prob) {
    int num = rand() % 100;
    return num < prob;
}

void Character::GetCharacterDetails() {
    cout << "\n" << name << "'s Details\n";
    cout << "Health        : " << health << "\n";
    cout << "Melee Damage  : " << meleeDamage << "\n";
    cout << "Ranged Damage : " << rangedDamage << "\n";
    cout << "Healing Power : " << healingPower << "\n";
}

int Character::Attack(int level) {
    std::cout << "Dummy Character Attack function. \n";
    return rand();
}

void Character::Heal(int level) {
    std::cout << "Dummy Character Health Healing. \n";
}
