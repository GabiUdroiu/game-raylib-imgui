#include "debugUI.h"

bool debug = false; 

void ToggleDebug() {
    debug = !debug;
}

void InitDebugUI() {
    rlImGuiSetup(true);
}

void ShutdownDebugUI() {
    rlImGuiShutdown();
}

void DrawDebugUI(GameState currentState, Player& player, Map& map) {
    rlImGuiBegin();
    ImGui::Begin("Debug Info");
    ImGui::Text("Current GameState: %d", int(currentState));
    ImGui::Checkbox("Player Debug", &player.debug);
    ImGui::Checkbox("Map Debug", &map.debug);

    float speed = player.GetSpeed();
    ImGui::Text("Speed:");
    ImGui::SameLine();

    // Slider (dragging)
    if (ImGui::SliderFloat("##speedSlider", &speed, 10.0f, 1000.0f)) {
        player.SetSpeed(speed);
    }

    ImGui::SameLine();

    // Input field (typing)
    if (ImGui::InputFloat("##speedInput", &speed, 1.0f, 10.0f, "%.1f")) {
        player.SetSpeed(speed);
    }
    
    ImGui::End();
    rlImGuiEnd();
}
