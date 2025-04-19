#pragma once
#include "raylib.h"

class Game;
class Hud;

class GameState
{
public:
    virtual void handleInput(Vector2 coord, Game &game) = 0;
    virtual void update(Game &game) = 0;
    virtual void draw() = 0;
    virtual void init() = 0;
};

class MenuState : public GameState
{
public:
    MenuState() {}
    ~MenuState();
    void init();
    void handleInput(Vector2 coord, Game &game) override;
    void update(Game &game) override;
    void draw() override;

private:
    Hud *hud;
};

class PlayingState : public GameState
{
public:
    PlayingState() {}
    ~PlayingState();
    void init() override;
    void handleInput(Vector2 coord, Game &game) override;
    void handleNetwork();
    void update(Game &game) override;
    void draw() override;

private:
    class Board *board;
    double tick_dt;
    Hud *hud;
    class Client *gameClient;
};

class SettingsState : public GameState
{
public:
    SettingsState() {}
    ~SettingsState();
    void init() override;
    void handleInput(Vector2 coord, Game &game) override;
    void update(Game &game) override;
    void draw() override;

private:
    Hud *hud;
};
