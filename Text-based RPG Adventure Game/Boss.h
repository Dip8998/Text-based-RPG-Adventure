#pragma once
#include "Player.h"

class Boss {
private:
    int health;
    int attackPower;
    int defence;
    float groundSlashProb;
    float speedDashProb;
    float healthRegenProb;
    bool dodgedNextAttack;

public:
    Boss(int h, int attkPow, int def, float groundSlash, float speedDash, float healthRegen);
    void attackPlayer(Player* player);  
    void specialAttack(Player* player);  
    void takeDamage(int damage);
    bool isAlive();
    void regenerateHealth();
    bool shouldDodgeAttack();
};
