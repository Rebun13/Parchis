#pragma once

#include "gameMode.h"

class Rectangle;

class RegularGameMode : public GameMode
{
public:
    RegularGameMode();
    ~RegularGameMode();

    void init() final;
    void update() final;
    void draw() final;
    GameState* handleInput() final;

private:
    Rectangle buttonTwoPlayerRect {48, 240, 96, 72};
    const char *buttonTwoPlayerText {"2 Players"};
    Rectangle buttonThreePlayerRect {192, 240, 96, 72};
    const char *buttonThreePlayerText {"3 Players"};
    Rectangle buttonFourPlayerRect {336, 240, 96, 72};
    const char *buttonFourPlayerText {"4 Players"};
    Rectangle buttonPlayRect {48, 480, 176, 48};
    const char *buttonPlayText {"PLAY"};
    Rectangle buttonExitRect {256, 480, 176, 48};
    const char *buttonExitText {"EXIT"};

    int numPlayers;
    bool exitButtonClicked;
};