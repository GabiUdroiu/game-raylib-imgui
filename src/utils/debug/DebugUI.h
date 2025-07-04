#pragma once
#include "rlImGui.h"
#include "imgui.h"
#include "../../core/Game.h" // for Player and GameState

extern Player player;  
extern Map map;
extern bool debug;     // declare debug flag

void ToggleDebug();
void InitDebugUI();
void ShutdownDebugUI();
void DrawDebugUI(GameState currentState, Player& player, Map& map);
