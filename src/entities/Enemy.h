#pragma once

#include "raylib.h"
#include "Entity.h"

class Enemy : public Entity {
private:
    Vector2 position;
    float speed;

    static Texture2D textures[2]; // Shared between all Enemy instances
    int textureIndex = 0;

    Rectangle sourceRect = { 0, 0, 32, 32 }; // Default frame size
    int frame = 0;
    float frameTime = 0.0f;
    float frameDuration = 0.2f;

    float scale = 2.0f;
    bool facingLeft = false;

public:
    Enemy(float x, float y, int health, int damage, float speed);
    ~Enemy();

    void Update(float deltaTime, Vector2 playerPos);
    void Draw() const;

    Vector2 GetPosition() const { return position; }
    void SetPosition(Vector2 pos) { position = pos; }

    static void LoadAssets();
    static void UnloadAssets();
};
