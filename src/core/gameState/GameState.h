#pragma once

class Game;
class Input;
class InputHandler;

class GameState
{
public:
    static class LoadingState loading;
    static class MenuState menu;
    static class PlayingState playing;

    virtual ~GameState() = 0;

private:
    InputHandler *inputHandler_;

public:
    virtual void update(Game &game) = 0;
    virtual void handleInput(Game &game, Input &input) = 0;
};
