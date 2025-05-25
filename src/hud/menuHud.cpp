#include "menuHud.h"
#include "core/game.h"
#include "raylib.h"
#include <cstdlib>
#include <iostream>

MenuHud::~MenuHud() {}

MenuHud::MenuHud(int color) {
  if (color < 0 || color > 3) {
    colorIndex = 0;
  } else {
    colorIndex = color;
  }
  font = Game::getGameInstance()->getFont();
  // titleSize = MeasureTextEx(*font, title, 70, 5);
  Vector2 textSize = MeasureTextEx(*font, playButton.text.c_str(), 50, 1);
  playButton.textPositionIddle = {
      playButton.rect.x + 10,
      playButton.rect.y + (playButton.rect.height - textSize.y) / 2.f};
  playButton.textPositionSelected = playButton.textPositionIddle;
  playButton.textPositionSelected.x += tokenRadius + 20.f;
  playButton.tokenPosition = playButton.rect.y + playButton.rect.height / 2;

  textSize = MeasureTextEx(*font, settingsButton.text.c_str(), 50, 1);
  settingsButton.textPositionIddle = {
      settingsButton.rect.x + 10,
      settingsButton.rect.y + (settingsButton.rect.height - textSize.y) / 2.f};
  settingsButton.textPositionSelected = settingsButton.textPositionIddle;
  settingsButton.textPositionSelected.x += tokenRadius + 20.f;
  settingsButton.tokenPosition =
      settingsButton.rect.y + settingsButton.rect.height / 2;

  textSize = MeasureTextEx(*font, exitButton.text.c_str(), 50, 1);
  exitButton.textPositionIddle = {
      exitButton.rect.x + 10,
      exitButton.rect.y + (exitButton.rect.height - textSize.y) / 2.f};
  exitButton.textPositionSelected = exitButton.textPositionIddle;
  exitButton.textPositionSelected.x += tokenRadius + 20.f;
  exitButton.tokenPosition = exitButton.rect.y + exitButton.rect.height / 2;

  tokenPositionX = buttonLeftMargin + tokenRadius;
  tokenCurrentPosition = playButton.tokenPosition;
  tokenNextPosition = playButton.tokenPosition;
}

void MenuHud::draw() {
  DrawTextEx(*font, title.c_str(), {(480 - buttonWidth) / 2.f, 87}, 70, 5,
             {255, 255, 255, 255});

  DrawTextEx(*font, playButton.text.c_str(),
             (tokenNextPosition == playButton.tokenPosition
                  ? playButton.textPositionSelected
                  : playButton.textPositionIddle),
             50, 1, BLACK);
  DrawTextEx(*font, settingsButton.text.c_str(),
             (tokenNextPosition == settingsButton.tokenPosition
                  ? settingsButton.textPositionSelected
                  : settingsButton.textPositionIddle),
             50, 1, BLACK);
  DrawTextEx(*font, exitButton.text.c_str(),
             (tokenNextPosition == exitButton.tokenPosition
                  ? exitButton.textPositionSelected
                  : exitButton.textPositionIddle),
             50, 1, BLACK);

  DrawCircle(tokenPositionX, tokenCurrentPosition, tokenRadius,
             tokenColors[colorIndex]);
}

unsigned char MenuHud::handleInput() {
  Vector2 mousePos = GetMousePosition();
  if (CheckCollisionPointRec(mousePos, playButton.rect)) {
    moveToken(playButton.tokenPosition);
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
      return PLAY_BUTTON;
    }
  } else if (CheckCollisionPointRec(mousePos, settingsButton.rect)) {
    // TODO: play sound
    moveToken(settingsButton.tokenPosition);
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
      return SETTINGS_BUTTON;
    }
  } else if (CheckCollisionPointRec(mousePos, exitButton.rect)) {
    // TODO: play sound
    moveToken(exitButton.tokenPosition);
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
      std::cout << "HUD: EXIT BUTTON CLICKED" << std::endl;
      return EXIT_BUTTON;
    }
  }
  return -1;
}

void MenuHud::update() {
  float tokenMovement = tokenSpeed * GetFrameTime();
  if (tokenCurrentPosition != tokenNextPosition) {
    if (std::abs(tokenCurrentPosition - tokenNextPosition) < tokenMovement) {
      tokenCurrentPosition = tokenNextPosition;
    } else {
      tokenCurrentPosition +=
          (tokenCurrentPosition < tokenNextPosition ? tokenMovement
                                                    : -tokenMovement);
    }
  }
}

void MenuHud::reset() {}

void MenuHud::moveToken(float position) { tokenNextPosition = position; }