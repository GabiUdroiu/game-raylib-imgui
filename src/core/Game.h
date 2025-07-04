#pragma once
#include "GameState.h"
#include "entities/Player.h"
#include "entities/Enemy.h"
#include "world/Map.h"
#include "ui/play/PlayUI.h"

#include <vector>

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
    std::vector<Enemy*> enemies;
    float enemySpawnTimer = 0.0f;
    float enemySpawnInterval = 2.0f;
    
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