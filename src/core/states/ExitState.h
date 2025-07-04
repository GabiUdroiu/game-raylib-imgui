#pragma once
#include "../Game.h"
#include "raylib.h"

void Game::UpdateExit(float deltaTime) {
    isRunning = false;
    player.UnloadAssets();
    map.Unload();
}

void Game::DrawExit() {
    DrawText("Exiting...", 350, 280, 20, LIGHTGRAY);    
}
