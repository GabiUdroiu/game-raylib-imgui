#include "Enemy.h"
#include "raymath.h"

Texture2D Enemy::textures[2] = { 0 };

Enemy::Enemy(float x, float y, int hp, int dmg, float spd)
    : Entity(hp, dmg), position{ x, y }, speed(spd) 
    {
        textureIndex = GetRandomValue(0, 1);
    }

Enemy::~Enemy() {}

void Enemy::LoadAssets() {
    textures[0] = LoadTexture("assets/enemy1.png");
    textures[1] = LoadTexture("assets/enemy2.png");
}

void Enemy::UnloadAssets() {
    for (int i = 0; i < 2; i++) {
        if (textures[i].id != 0) {
            UnloadTexture(textures[i]);
            textures[i].id = 0;
        }
    }
}

void Enemy::Update(float deltaTime, Vector2 playerPos) {
    UpdateDamageCooldown(deltaTime);

    // Simple AI: Move toward player
    Vector2 direction = Vector2Subtract(playerPos, position);
    if (Vector2Length(direction) > 1.0f) {
        direction = Vector2Normalize(direction);
        position = Vector2Add(position, Vector2Scale(direction, speed * deltaTime));
    }

    // Animation (optional)
    frameTime += deltaTime;
    if (frameTime >= frameDuration) {
        frame = (frame + 1) % 2; // Assuming 2 frames
        frameTime = 0.0f;
    }

    // Facing
    facingLeft = (playerPos.x < position.x);
}

void Enemy::Draw() const {
    Rectangle src = sourceRect;
    if (facingLeft) {
        src.width = -sourceRect.width;
        src.x += sourceRect.width;
    }

    Rectangle dest = {
        position.x,
        position.y,
        sourceRect.width * scale,
        sourceRect.height * scale
    };

    Color tint = (canTakeDamage() ? WHITE : RED);
    DrawTexturePro(textures[textureIndex], src, dest, { 0, 0 }, 0, tint);
}
