#include "raylib.h"
#include "core/Game.h"
#include <iostream>

int main() {
    std::cout << "Starting game\n";
    Game game;
    game.Init();
    std::cout << "Game initialized\n";
    while (!game.ShouldExit()) {
        float dt = GetFrameTime();
        game.Update(dt);
        game.Draw();
    }
    CloseWindow();
    return 0;
}
