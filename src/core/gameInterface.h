#pragma once

#include <memory>

class GameInterface
{
public:
    virtual ~GameInterface() = default;
    virtual void handleInput() = 0;
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void beginGame() = 0;
    virtual bool gameShouldClose() = 0;
    virtual void setClose_() = 0;
    virtual void saveSettings() = 0;

    static std::unique_ptr<GameInterface> createGameInstance();
};
