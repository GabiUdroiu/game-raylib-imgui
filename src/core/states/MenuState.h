#pragma once
#include "raylib.h"

void Game::UpdateMenu(float deltaTime) {
    if (IsKeyPressed(KEY_ENTER)) {
        player.LoadAssets();
        map.LoadAssets();
        player.SetPosition({400.0f, 300.0f});
        state = GameState::Play; // Transition to Play state
    } else if (IsKeyPressed(KEY_ESCAPE)) {
        state = GameState::Exit; // Exit the game
    }
}

void Game::DrawMenu() {
    DrawText("Main Menu", 350, 280, 20, LIGHTGRAY);
}
