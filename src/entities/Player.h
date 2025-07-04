#pragma once
#include "Entity.h"
#include "raylib.h"

class Player : public Entity {
private:
    Vector2 position;
    Texture2D texture;
    float movementSpeed = 200.0f;
    Rectangle sourceRect = { 0, 0, 32, 32 }; // size of one frame or sprite in your texture
    bool facingLeft = false;
    
public:
    Player();
    ~Player();

    void LoadAssets();
    void UnloadAssets();

    void Update(float deltaTime);
    void Draw() const;

    Vector2 GetPosition() const { return position; }
    void SetPosition(Vector2 pos) { position = pos; }
    bool debug = false;
    void ToggleDebug() { debug = !debug; }

    float GetSpeed() const;
    void SetSpeed(float speed);

    float scale = 2.0f;
};
