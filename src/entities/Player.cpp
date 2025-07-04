#include "Player.h"
#include "raylib.h"
#include "raymath.h"
Player::Player() : Entity(100, 10), movementSpeed(200.0f), position{0.0f, 0.0f} { texture = { 0 };}

Player::~Player() {
    UnloadAssets();
}

void Player::LoadAssets() {
    if (texture.id == 0)
        texture = LoadTexture("assets/player.png");
}

void Player::UnloadAssets() {
    if (texture.id != 0) {
        UnloadTexture(texture);
        texture.id = 0;
    }
}

void Player::Update(float deltaTime) {
    UpdateDamageCooldown(deltaTime);

    if (IsKeyDown(KEY_W)) position.y -= movementSpeed * deltaTime;
    if (IsKeyDown(KEY_S)) position.y += movementSpeed * deltaTime;
    if (IsKeyDown(KEY_A)) position.x -= movementSpeed * deltaTime;
    if (IsKeyDown(KEY_D)) position.x += movementSpeed * deltaTime;

    position.x = Clamp(position.x, 0, 800 - 64);
    position.y = Clamp(position.y, 5, 600 - 64 - 10); // Hardcoded
    Vector2 mouse = GetMousePosition();
    if (mouse.x < position.x + sourceRect.width * scale / 2) {
        facingLeft = true;
    } else {
        facingLeft = false;
    }
}

void Player::Draw() const {
    Rectangle src = sourceRect;
    
    if (facingLeft) {
        src.width = -sourceRect.width;
        src.x += sourceRect.width; // Shift to flip correctly
    }    

    Rectangle destRec = {
        position.x, 
        position.y, 
        sourceRect.width * scale, 
        sourceRect.height * scale
    };

    Vector2 origin = { 0.0f, 0.0f }; // top-left origin
    float rotation = 0.0f;

    Color tintColor = WHITE; // or RED if damaged, etc.

    // Draw player sprite (no flipping here; add if you want)
    
    DrawTexturePro(texture, src, destRec, origin, rotation, tintColor);

    // Debug rectangles
    #ifndef RELEASE_BUILD
    if (debug) {
        Rectangle damageableArea = { position.x + 12, position.y + 12, 40, 40 };
        DrawRectangleLinesEx(destRec, 1, ORANGE);
        DrawRectangleLinesEx(damageableArea, 1, RED);
    }
    #endif
}

float Player::GetSpeed() const {
    return movementSpeed;
}

void Player::SetSpeed(float speed) {
    movementSpeed = speed;
}

