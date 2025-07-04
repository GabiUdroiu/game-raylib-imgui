#include "Game.h"
#include "raylib.h"
#include "entities/Player.h"

#include "states/LoadState.h"
#include "states/MenuState.h"
#include "states/PlayState.h"
#include "states/PauseState.h"
#include "states/GameOverState.h"
#include "states/ExitState.h"

#ifndef RELEASE_BUILD
#include "imgui.h"
#include "rlImGui.h"
#include "extras/IconsFontAwesome6.h"
#include "utils/debug/DebugUI.h"
#endif

Game::Game() : state(GameState::Load), isRunning(true) {}

void Game::Init() {
    InitWindow(800, 600, "Raygame");
    SetTargetFPS(1000);
    SetExitKey(KEY_NULL);
    
    #ifndef RELEASE_BUILD
    InitDebugUI();
    #endif
}

void Game::Update(float deltaTime) {
    if (WindowShouldClose()) {
        isRunning = false;
        return;
    }

    switch (state) {
        case GameState::Load: UpdateLoad(deltaTime); break;
        case GameState::Menu: UpdateMenu(deltaTime); break;
        case GameState::Play: UpdatePlay(deltaTime); break;
        case GameState::Pause: UpdatePause(deltaTime); break;
        case GameState::GameOver: UpdateGameOver(deltaTime); break;
        case GameState::Exit: UpdateExit(deltaTime); break;
    }
}

void Game::Draw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    switch (state) {
        case GameState::Load: DrawLoad(); break;
        case GameState::Menu: DrawMenu(); break;
        case GameState::Play: DrawPlay(); break;
        case GameState::Pause: DrawPause(); break;
        case GameState::GameOver: DrawGameOver(); break;
        case GameState::Exit: DrawExit(); break;
    }

    #ifndef RELEASE_BUILD
    DrawDebugUI(state, player, map);
    #endif
    EndDrawing();
}

bool Game::ShouldExit() const {
    return !isRunning;
}

Game::~Game() {
    player.UnloadAssets();
    #ifndef RELEASE_BUILD
    ShutdownDebugUI();
    #endif
    CloseWindow();
    // Additional cleanup if necessary
}