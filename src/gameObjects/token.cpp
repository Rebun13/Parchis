#include "token.h"
#include "raylib.h"

Token::Token(unsigned char playerIndex, Color color) : playerIndex(playerIndex), color_(color) {
    pos_ = {-1000, -1000};
    newPos_ = pos_;
}

void Token::move(Vector2 newPos)
{
    newPos_ = newPos;
}

void Token::update()
{
    if(pos_.x != newPos_.x && pos_.y != newPos_.y){
        pos_ = newPos_; // TODO: animate this movement
    }
}

void Token::draw()
{
    DrawCircle(pos_.x, pos_.y, 8.0, color_);
}