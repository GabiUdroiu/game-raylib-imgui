#pragma once
#include "raylib.h"

#include "ui/play/Play.h"

void Game::UpdatePlay(float deltaTime) {
    player.Update(deltaTime);

    // Handle enemy spawning
    enemySpawnTimer += deltaTime;
    if (enemySpawnTimer >= enemySpawnInterval) {
        enemySpawnTimer = 0.0f;

        float x = float(GetRandomValue(0, 800 - 64));
        float y = float(GetRandomValue(0, 600 - 64));
        int health = GetRandomValue(40, 100);
        int damage = GetRandomValue(5, 20);
        float speed = GetRandomValue(50, 190);

        enemies.push_back(new Enemy(x, y, health, damage, speed));
    }

    // Update enemies
    for (Enemy* e : enemies) {
        e->Update(deltaTime, player.GetPosition());
    }

    // Pause
    if (IsKeyPressed(KEY_ESCAPE)) {
        state = GameState::Pause;
    }
}

void Game::DrawPlay() {
    DrawText("Game Playing", 350, 280, 20, LIGHTGRAY);

    map.Draw();
    
    for (Enemy* e : enemies) {
        e->Draw();
    }

    player.Draw();
    playUI.Draw(player, 0, 1, 0);
}

