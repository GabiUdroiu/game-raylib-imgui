#pragma once
#include "raylib.h"

#include "ui/play/PlayUI.h"

void Game::UpdatePlay(float deltaTime) {
    player.Update(deltaTime);
    if (IsKeyPressed(KEY_ESCAPE)) {
        state = GameState::Pause;
    }
}

void Game::DrawPlay() {
    DrawText("Game Playing", 350, 280, 20, LIGHTGRAY);
    map.Draw();
    player.Draw();
    playUI.Draw(player, 0, 1, 0);

}
