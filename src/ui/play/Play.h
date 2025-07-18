#pragma once
#include "../../entities/Player.h"

class PlayUI {
private:
    void DrawHealthBar(const Player& player);
    void DrawScore(int score);
    void DrawLevelExpBar(int level, float expPercent);

public:
    void Draw(const Player& player, int score, int level, float expPercent);
};

inline void PlayUI::Draw(const Player& player, int score, int level, float expPercent) {
    DrawHealthBar(player);
    DrawScore(score);
    DrawLevelExpBar(level, expPercent);
}

inline void PlayUI::DrawHealthBar(const Player& player) {
    int barWidth = 200;
    int barHeight = 20;
    int x = 20;
    int y = 20;

    DrawRectangle(x, y, barWidth, barHeight, DARKGRAY);

    float healthRatio = (float)player.getHealth() / player.getMaxHealth();
    DrawRectangle(x, y, (int)(barWidth * healthRatio), barHeight, RED);

    DrawText(TextFormat("HP: %d / %d", player.getHealth(), player.getMaxHealth()), x + 5, y + 2, 14, WHITE);
}

inline void PlayUI::DrawScore(int score) {
    DrawText(TextFormat("Score: %d", score), 20, 50, 18, YELLOW);
}

inline void PlayUI::DrawLevelExpBar(int level, float expPercent) {
    int footerHeight = 5;
    int screenWidth = GetScreenWidth();
    int footerY = GetScreenHeight() - footerHeight;

    DrawRectangle(0, footerY, screenWidth, footerHeight, PINK);

    int expBarWidth = (int)(screenWidth * expPercent);
    DrawRectangle(0, footerY, expBarWidth, footerHeight, RED);

    //DrawText(TextFormat("Level: %d", level), 10, footerY + 6, 20, WHITE);
}