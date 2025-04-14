#pragma once

#include "raylib.h"
#include <vector>

class Box
{
public:
    enum BoxType
    {
        REGULAR_BOX,
        SAFE_BOX,
        FINAL_BOX,
        BRANCHED_BOX,
        CORNER_BOX,
    };

    Box(std::vector<Vector2> vertices, Vector2 posA, Vector2 posB) : vertices_(vertices), posA_(posA), posB_(posB) {}

    virtual Vector2 getPos();       // Returns the position the next token must be placed in
    virtual BoxType getType() = 0;  // Returns the box type: regular, safe, final or branched
    virtual bool hasBarrier();      // Returns true if the box contains a barrier
    virtual bool isSafe() { return false; } // Returns true if the box is safe
    virtual void draw(Color color); // Draw the shape of the box

private:
    int numTokens = 0;

protected:
    std::vector<Vector2> vertices_;
    Vector2 posA_;
    Vector2 posB_;
};

class RegularBox : public Box
{
public:
    RegularBox(std::vector<Vector2> vertices, Vector2 posA, Vector2 posB) : Box(vertices, posA, posB) {}
    BoxType getType() { return REGULAR_BOX; }
};

class SafeBox : public Box
{
public:
    SafeBox(std::vector<Vector2> vertices, Vector2 posA, Vector2 posB) : Box(vertices, posA, posB) {}
    BoxType getType() { return SAFE_BOX; }
    bool isSafe() { return true; }
};

class FinalBox : public Box
{
public:
    FinalBox(std::vector<Vector2> vertices, Vector2 posA, Vector2 posB) : Box(vertices, posA, posB) {}
    BoxType getType() { return FINAL_BOX; }
    bool isSafe() { return true; }
};

class BranchedBox : public Box
{
public:
    BranchedBox(std::vector<Vector2> vertices, Vector2 posA, Vector2 posB, int branchPlayer) : Box(vertices, posA, posB), branchPlayer_(branchPlayer) {}
    BoxType getType() { return BRANCHED_BOX; }
    bool isSafe() { return true; }
private:
    int branchPlayer_;
};