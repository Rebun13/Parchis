#pragma once

#include "core/gameInterface.h"
#include "raylib.h"
#include <memory>

class Game : public GameInterface {
public:
  Game();
  ~Game();
  static std::shared_ptr<GameInterface> gameInstance() {
    if (!instance) {
      instance = std::shared_ptr<Game>(new Game());
    }
    return std::shared_ptr<Game>(instance);
  }

  /* INTERFACE */
  virtual void handleInput() final;
  virtual void draw() final;
  virtual void update() final;
  virtual void beginGame() final;
  virtual bool gameShouldClose() final;
  virtual void setClose_() final;
  virtual GameState &getState() final;
  virtual void setState(GameState &state) final;
  virtual Font getFont() final;
  // TODO: add arguments and save using settings::saveSettings()
  virtual void saveSettings() final;
  /* END INTERFACE */
  Game(const Game &) = delete;
  Game &operator=(const Game &) = delete;

private:
  std::shared_ptr<GameState> state_;
  bool close{false};
  Font font_;
  static std::shared_ptr<Game> instance;
};
