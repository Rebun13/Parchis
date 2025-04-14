#include "box.h"
#include <stdexcept>

Vector2 Box::getPos()
{
    if(numTokens == 0)
        return posA_;
    if(numTokens == 1)
        return posB_;
    throw std::runtime_error("This box contains two tokens already!");
}

bool Box::hasBarrier() {
    return numTokens == 2;
}

void Box::draw(Color color)
{
    DrawLineStrip(&vertices_[0], vertices_.size(), color); // TODO: animation with alpha
}
