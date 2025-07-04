#pragma once
#include "GameState.h"
#include "entities/Player.h"
#include "world/Map.h"
#include "ui/play/PlayUI.h"

class Game {
public:
    Game();
    ~Game();

    void Init();
    void Update(float deltaTime);
    void Draw();
    bool ShouldExit() const;

private:
    GameState state;
    Player player;
    Map map;
    PlayUI playUI;

    bool isRunning;

    void UpdateLoad(float deltaTime);
    void UpdateMenu(float deltaTime);
    void UpdatePlay(float deltaTime);
    void UpdatePause(float deltaTime);
    void UpdateGameOver(float deltaTime);
    void UpdateExit(float deltaTime);

    void DrawLoad();
    void DrawMenu();
    void DrawPlay();
    void DrawPause();
    void DrawGameOver();
    void DrawExit();
};