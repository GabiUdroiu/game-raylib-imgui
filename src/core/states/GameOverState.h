#pragma once
#include "raylib.h"

void Game::UpdateGameOver(float deltaTime) {
    player.UnloadAssets();
    map.Unload();
    if (IsKeyPressed(KEY_ENTER)) {
        state = GameState::Menu; // Return to Menu
    } else if (IsKeyPressed(KEY_ESCAPE)) {
        state = GameState::Exit; // Exit the game
    }
}

void Game::DrawGameOver() {
    DrawText("Game Over", 350, 280, 20, LIGHTGRAY);
}
