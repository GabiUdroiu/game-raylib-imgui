#include "raylib.h"

#ifndef RELEASE_BUILD
#include "imgui.h"
#include "rlImGui.h"
#include "extras/IconsFontAwesome6.h"
#endif

int main() {
    InitWindow(800, 600, "Setup raylib + rlImGui + CMake");

    #ifndef RELEASE_BUILD
    rlImGuiSetup(true);
    #endif

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("(Setup) Hello from raylib + CMake!", 190, 200, 20, LIGHTGRAY);

        #ifndef RELEASE_BUILD
        rlImGuiBegin();

        ImGui::Begin("Hello rlImGui");
        ImGui::Text("%s This is the rlImGui with icon", ICON_FA_BOMB);
        ImGui::End();

        rlImGuiEnd();
        #endif

        EndDrawing();
    }

    #ifndef RELEASE_BUILD
    rlImGuiShutdown();
    #endif

    CloseWindow();
    return 0;
}
