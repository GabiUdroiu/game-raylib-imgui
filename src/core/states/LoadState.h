#pragma once
#include "raylib.h"

void Game::UpdateLoad(float deltaTime) {
    // Currently nothing to load
    // Loading resources and initializing game state
    state = GameState::Menu; // Transition to Menu state
}

void Game::DrawLoad() {
    DrawText("Loading...", 350, 280, 20, LIGHTGRAY);
}
