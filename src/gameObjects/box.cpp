#include "box.h"
#include <stdexcept>
#include <cmath>

Vector2 Box::getCenterPos()
{
    return {(posA_.x + posB_.x) / 2.f, (posA_.y + posB_.y) / 2.f};
}

void Box::draw(Color color)
{
    double currentTime = GetTime();
    color.a = static_cast<unsigned char>(std::round(255.0f * std::abs((1.0f - std::fmod(currentTime, 2.0)))));
    DrawLineStrip(&vertices_[0], vertices_.size(), color);
}
