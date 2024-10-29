#include "Character.h"

class Enemy : public Character {
public:
    Enemy();
    Enemy(int health, int meleeDamage, int rangedDamage, int healingPower);

    void Heal(int level) override;
    int Attack(int level) override;
};