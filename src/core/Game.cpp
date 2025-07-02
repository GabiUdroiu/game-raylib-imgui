#include "Game.h"
#include "raylib.h"

#ifndef RELEASE_BUILD
#include "imgui.h"
#include "rlImGui.h"
#include "extras/IconsFontAwesome6.h"
#endif

Game::Game() : state(GameState::Load), isRunning(true) {}

void Game::Init() {
    InitWindow(800, 600, "My Game");
    SetTargetFPS(60);
    SetExitKey(KEY_NULL);
    #ifndef RELEASE_BUILD
    rlImGuiSetup(true);  // 'true' enables default font, you can configure it differently if you want
    #endif
}

void Game::Update(float deltaTime) {
    if (WindowShouldClose()) {
        isRunning = false;
        return;
    }

    switch (state) {
        case GameState::Load:
            // Currently nothing to load
            // Loading resources and initializing game state
            state = GameState::Menu; // Transition to Menu state
            break;
        case GameState::Menu:
            // Handle Menu Logic
            if (IsKeyPressed(KEY_ENTER)) {
                 state = GameState::Play; // Transition to Pause state
            } else if (IsKeyPressed(KEY_ESCAPE)) {
                state = GameState::Exit; // Exit the game
            }
            break;
        case GameState::Play:
            // Handle Game Play Logic
            if (IsKeyPressed(KEY_ESCAPE)) {
                state = GameState::Pause; // Transition to Pause state
            }
            break;  
        case GameState::Pause:
            // Handle Pause Logic
            if (IsKeyPressed(KEY_ENTER)) {
                state = GameState::Play; // Resume game
            } else if (IsKeyPressed(KEY_ESCAPE)) {
                state = GameState::Menu; // Return to Menu
            }
            break;
        case GameState::GameOver:
            // Handle Game Over Logic
            break;
        case GameState::Exit:
            isRunning = false; // Exit the game
            break;
        default:
            // Handle unexpected state
            break;
    }
}

void Game::Draw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    switch (state) {
        case GameState::Load:
            DrawText("Loading...", 350, 280, 20, LIGHTGRAY);
            break;
        case GameState::Menu:
            DrawText("Main Menu", 350, 280, 20, LIGHTGRAY);
            break;
        case GameState::Play:
            DrawText("Game Playing", 350, 280, 20, LIGHTGRAY);
            break;
        case GameState::Pause:
            DrawText("Game Paused", 350, 280, 20, LIGHTGRAY);
            break;
        case GameState::GameOver:
            DrawText("Game Over", 350, 280, 20, LIGHTGRAY);
            break;
        case GameState::Exit:
            DrawText("Exiting...", 350, 280, 20, LIGHTGRAY);
            break;
    }

    #ifndef RELEASE_BUILD
    rlImGuiBegin();

    ImGui::Begin("Debug Info");

    // Just print the integer value of the enum
    ImGui::Text("Current GameState: %d", int(state));

    ImGui::End();
    rlImGuiEnd();
    #endif
    EndDrawing();
}

bool Game::ShouldExit() const {
    return !isRunning;
}

Game::~Game() {
    CloseWindow();
    #ifndef RELEASE_BUILD
    rlImGuiShutdown();
    #endif
    // Additional cleanup if necessary
}