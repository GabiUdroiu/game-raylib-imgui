#pragma once

#include <iostream>

class Entity {
protected:
    int health;
    int maxHealth;
    int damage;
    float damageCooldown = 0.0f;
    const float damageInterval = 0.5f;
    const float damageTintDuration = 0.2f; // how long to show red tint

public:
    Entity(int hp = 100, int dmg = 10) : health(hp), maxHealth(hp), damage(dmg) {}
    virtual ~Entity() = default;

    virtual void Update(float deltaTime) {
        UpdateDamageCooldown(deltaTime);
    }

    virtual void Draw() const {}

    bool takeDamage(int amount) {
        if (damageCooldown <= 0.0f && health > 0) {
            health -= amount;
            if (health < 0) health = 0;
            damageCooldown = damageInterval;
            std::cout << "Entity took " << amount << " damage. Health now " << health << "\n";
            return true;
        }
        return false;
    }

    void UpdateDamageCooldown(float deltaTime) {
        if (damageCooldown > 0.0f)
            damageCooldown -= deltaTime;
    }

    bool canTakeDamage() const { return damageCooldown <= 0.0f; }

    int getHealth() const { return health; }

    int getMaxHealth() const { return maxHealth; }

    int getDamage() const { return damage; }

    bool isAlive() const { return health > 0; }
};

