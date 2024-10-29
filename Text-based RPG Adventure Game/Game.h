#include "Player.h"
#include "Enemy.h"

class Game {
public:
    int getCurrentLevel();
    void GameIntro();
    string GetPlayerName();
    void LevelSpeech(string heroName);
    void DisplayHealthStats(Character* hero, Character* enemies);
    bool PlayLevel(Character* hero);
    void PlayGame();

private:
    int currentLevel = 0;
};
