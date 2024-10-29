#pragma once
#include "Character.h"

class Player : public Character {
public:
    Player(int health, int meleeDamage, int rangedDamage, int healingPower, string name);
    void Heal(int level) override;
    int Attack(int level) override;
};
