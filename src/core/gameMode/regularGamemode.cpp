#include "regularGamemode.h"
#include "core/game.h"
#include "gameObjects/board.h"
#include "raylib.h"
#include "hud/buttons.h"
#include "style/colors.h"

RegularGameMode::RegularGameMode()
{
    gameStarted = false;
    exitButtonClicked = false;
    numPlayers = 0;
}

RegularGameMode::~RegularGameMode()
{
}

void RegularGameMode::init()
{
    board = new Board(numPlayers);
    gameStarted = true;
}

void RegularGameMode::update()
{
    board->update();
}

void RegularGameMode::draw()
{
    if (!gameStarted)
    {
        // TODO: selector of number of players
        if (drawButton(buttonTwoPlayerRect.x, buttonTwoPlayerRect.y,
                       buttonTwoPlayerRect.width, buttonTwoPlayerRect.height,
                       buttonTwoPlayerText,
                       numPlayers == 2 ? GetThemeColor(PRIMARY_COLOR_PRESS) : GetThemeColor(PRIMARY_COLOR),
                       GetThemeColor(PRIMARY_COLOR_HOVER), GetThemeColor(PRIMARY_COLOR_PRESS)))
        {
            numPlayers = 2;
        }
        if (drawButton(buttonThreePlayerRect.x, buttonThreePlayerRect.y,
                       buttonThreePlayerRect.width, buttonThreePlayerRect.height,
                       buttonThreePlayerText,
                       numPlayers == 3 ? GetThemeColor(PRIMARY_COLOR_PRESS) : GetThemeColor(PRIMARY_COLOR),
                       GetThemeColor(PRIMARY_COLOR_HOVER), GetThemeColor(PRIMARY_COLOR_PRESS)))
        {
            numPlayers = 3;
        }
        if (drawButton(buttonFourPlayerRect.x, buttonFourPlayerRect.y,
                       buttonFourPlayerRect.width, buttonFourPlayerRect.height,
                       buttonFourPlayerText,
                       numPlayers == 4 ? GetThemeColor(PRIMARY_COLOR_PRESS) :  GetThemeColor(PRIMARY_COLOR),
                       GetThemeColor(PRIMARY_COLOR_HOVER), GetThemeColor(PRIMARY_COLOR_PRESS)))
        {
            numPlayers = 4;
        }
        // TODO: start game button
        if (drawButton(buttonPlayRect.x, buttonPlayRect.y,
                       buttonPlayRect.width, buttonPlayRect.height,
                       buttonPlayText,
                       GetThemeColor(PRIMARY_COLOR),
                       GetThemeColor(PRIMARY_COLOR_HOVER), GetThemeColor(PRIMARY_COLOR_PRESS)))
        {
            gameStarted = true;
            init();
        }
        if (drawButton(buttonExitRect.x, buttonExitRect.y,
                       buttonExitRect.width, buttonExitRect.height,
                       buttonExitText,
                       GetThemeColor(SECONDARY_COLOR),
                       GetThemeColor(SECONDARY_COLOR_HOVER), GetThemeColor(SECONDARY_COLOR_PRESS)))
        {
            exitButtonClicked = true;
        }
    }
    else
    {
        // TODO: draw board, tokens and hud.setState(
    }
}

void RegularGameMode::handleInput()
{
    std::unique_ptr<GameInterface> game = Game::getGameInstance();
    if(!gameStarted && exitButtonClicked) {
        game->setState(Game::menu);
        delete this;
    }
    board->update();
}