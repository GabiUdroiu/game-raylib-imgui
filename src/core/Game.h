#include "GameState.h"
//#include "../ui/UiManager.h"

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
    //UiManager uiManager;
    bool isRunning;
};