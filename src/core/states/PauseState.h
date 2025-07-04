#pragma once
#include "raylib.h"

void Game::UpdatePause(float deltaTime) {
    if (IsKeyPressed(KEY_ENTER)) {
        state = GameState::Play; // Resume game
    } else if (IsKeyPressed(KEY_ESCAPE)) {
        player.UnloadAssets();
        enemies.clear();
        Enemy::UnloadAssets();
        map.Unload();
        state = GameState::Menu; // Return to Menu
    }
}

void Game::DrawPause() {
    DrawText("Game Paused", 350, 280, 20, LIGHTGRAY);
}
