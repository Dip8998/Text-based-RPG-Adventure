#include "Enemy.h"
#include <iostream>
using namespace std;

Enemy::Enemy() {}

Enemy::Enemy(int health, int meleeDamage, int rangedDamage, int healingPower)
    : Character(health, meleeDamage, rangedDamage, healingPower) {}

void Enemy::Heal(int level) {
    string enemyName = getName();
    cout << enemyName << " has chosen to Heal !! ....\n\n";
    cout << enemyName << "'s Healing Power : " << getHealingPower() << "\n";
    int additionalHeal = ((enemyName == "MURLOCS") ? getHealingPower() * 0.5 : 0);
    int enemyHealth = ((enemyName == "MURLOCS") ? 300 : 70 + level * 5);
    setHealth(std::min(enemyHealth, getHealth() + additionalHeal + getHealingPower()));
    cout << enemyName << "'s Special Ability Heal Bonus : " << additionalHeal << "\n\n";
    cout << enemyName << "'s Updated Health : " << getHealth() << "\n\n";
    cout << "=======================================================================================\n\n";
}

int Enemy::Attack(int level) {
    string enemyName = getName();
    
    cout << enemyName << " is Attacking .... SUCCESSFUL HIT !! ....\n\n";
    
    int baseDamage = getMeleeDamage() + getRangedDamage();
    int totalDamage = (1 + (rand() % 50) / 100) * baseDamage;

    
    if (level >= level4 && IsSuccessfulProbability(10)) {
        std::cout << "But Attack is Blocked !! \n";
        totalDamage = 0;
    }
    cout << "Total Damage : " << totalDamage << "\n";
    cout << "=======================================================================================\n\n";
    return totalDamage;
}