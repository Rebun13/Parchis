#pragma once

#include "core/gameInterface.h"
#include "raylib.h"

class Game : public GameInterface {
public:
  Game();
  ~Game();

  /* INTERFACE */
  virtual void handleInput() final;
  virtual void draw() final;
  virtual void update() final;
  virtual void beginGame() final;
  virtual bool gameShouldClose() final;
  virtual void setClose_() final;
  virtual void setState(GameState *state) final;
  virtual void loadTexturePack(std::string path) final;
  virtual Texture2D *getTexturePack() final;
  virtual Font *getFont() final;
  // TODO: add arguments and save using settings::saveSettings()
  virtual void saveSettings() final;
  /* END INTERFACE */
  Game(const Game &) = delete;
  Game &operator=(const Game &) = delete;

private:
  GameState *state_;
  Texture2D *texture;
  bool close{false};
  Font font_;
  static Game *instance;

public:
  static GameInterface *gameInstance() {
    if (!instance) {
      instance = new Game();
    }
    return instance;
  }
};
