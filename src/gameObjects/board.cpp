#include "board.h"
#include "box.h"

Board::Board()
{
    texture = LoadTexture("textures/board_hr.png");
    buildBoxes();
}

Board::~Board()
{
    UnloadTexture(texture);
    clearBoxes();
}

void Board::init()
{
    // TODO: get players and set first
}

void Board::draw()
{
    DrawTextureEx(texture, position, 0, 1, WHITE);
}

void Board::clearBoxes()
{
    for (auto &&box : boxes)
    {
        delete &box;
    }
    boxes.clear();
}

void Board::buildBoxes()
{
    clearBoxes();

    struct BoxData
    {
        Vector2 v1;
        Vector2 v2;
        Vector2 v3;
        Vector2 v4;
        Vector2 p1;
        Vector2 p2;
        Box::BoxType boxType;
        int branchPlayer = -1;
    };
    std::vector<BoxData> items = {
        {{262, 442}, {321, 442}, {321, 461}, {262, 461}, {278, 451}, {305, 451}, Box::REGULAR_BOX},
        {{262, 422}, {321, 422}, {321, 441}, {262, 441}, {278, 431}, {305, 431}, Box::REGULAR_BOX},
        {{262, 402}, {321, 402}, {321, 421}, {262, 421}, {278, 411}, {305, 411}, Box::REGULAR_BOX},
        {{262, 382}, {321, 382}, {321, 401}, {262, 401}, {278, 391}, {305, 391}, Box::REGULAR_BOX},
        {{262, 362}, {321, 362}, {321, 381}, {262, 381}, {278, 371}, {305, 371}, Box::SAFE_BOX},
        {{262, 342}, {321, 342}, {321, 361}, {262, 361}, {278, 351}, {305, 351}, Box::REGULAR_BOX},
        {{262, 322}, {321, 322}, {321, 341}, {262, 341}, {278, 331}, {305, 331}, Box::REGULAR_BOX},
        {{262, 301}, {301, 302}, {320, 321}, {262, 321}, {278, 311}, {295, 311}, Box::REGULAR_BOX}, // corner

        {{302, 262}, {321, 262}, {321, 321}, {302, 302}, {311, 278}, {311, 295}, Box::REGULAR_BOX}, // corner
        {{322, 262}, {341, 262}, {341, 321}, {322, 321}, {331, 278}, {331, 305}, Box::REGULAR_BOX},
        {{342, 262}, {361, 262}, {361, 321}, {342, 321}, {351, 278}, {351, 305}, Box::REGULAR_BOX},
        {{362, 262}, {381, 262}, {381, 321}, {362, 321}, {371, 278}, {371, 305}, Box::SAFE_BOX},
        {{382, 262}, {401, 262}, {401, 321}, {382, 321}, {391, 278}, {391, 305}, Box::REGULAR_BOX},
        {{402, 262}, {421, 262}, {421, 321}, {402, 321}, {411, 278}, {411, 305}, Box::REGULAR_BOX},
        {{422, 262}, {441, 262}, {441, 321}, {422, 321}, {431, 278}, {431, 305}, Box::REGULAR_BOX},
        {{442, 262}, {461, 262}, {461, 321}, {442, 321}, {451, 278}, {451, 305}, Box::REGULAR_BOX},

        {{442, 202}, {461, 202}, {461, 261}, {442, 261}, {451, 245}, {451, 218}, Box::BRANCHED_BOX, 1}, // branch

        {{442, 142}, {461, 142}, {461, 201}, {442, 201}, {451, 185}, {451, 158}, Box::REGULAR_BOX},
        {{422, 142}, {441, 142}, {441, 201}, {422, 201}, {432, 185}, {432, 158}, Box::REGULAR_BOX},
        {{402, 142}, {421, 142}, {421, 201}, {402, 201}, {412, 185}, {412, 158}, Box::REGULAR_BOX},
        {{382, 142}, {401, 142}, {401, 201}, {382, 201}, {392, 185}, {392, 158}, Box::REGULAR_BOX},
        {{362, 142}, {381, 142}, {381, 201}, {362, 201}, {372, 185}, {372, 158}, Box::SAFE_BOX},
        {{342, 142}, {361, 142}, {361, 201}, {342, 201}, {352, 185}, {352, 158}, Box::REGULAR_BOX},
        {{322, 142}, {341, 142}, {341, 201}, {322, 201}, {332, 185}, {332, 158}, Box::REGULAR_BOX},
        {{302, 160}, {321, 141}, {321, 201}, {302, 201}, {312, 185}, {312, 168}, Box::REGULAR_BOX}, // corner
    
        {{262, 142}, {321, 142}, {302, 161}, {262, 161}, {278, 151}, {295, 151}, Box::REGULAR_BOX}, // corner
        {{262, 122}, {321, 122}, {321, 141}, {262, 141}, {278, 131}, {305, 131}, Box::REGULAR_BOX},
        {{262, 102}, {321, 102}, {321, 121}, {262, 121}, {278, 111}, {305, 111}, Box::REGULAR_BOX},
        {{262, 82}, {321, 82}, {321, 101}, {262, 101}, {278, 91}, {305, 91}, Box::SAFE_BOX},
        {{262, 62}, {321, 62}, {321, 81}, {262, 81}, {278, 71}, {305, 71}, Box::REGULAR_BOX},
        {{262, 42}, {321, 42}, {321, 61}, {262, 61}, {278, 51}, {305, 51}, Box::REGULAR_BOX},
        {{262, 22}, {321, 22}, {321, 41}, {262, 41}, {278, 31}, {305, 31}, Box::REGULAR_BOX},
        {{262, 2}, {321, 2}, {321, 21}, {262, 21}, {278, 11}, {305, 11}, Box::REGULAR_BOX},

        {{202, 2}, {261, 2}, {261, 21}, {202, 21}, {245, 11}, {218, 11}, Box::BRANCHED_BOX, 2}, // branch

        {{142, 2}, {201, 2}, {201, 21}, {142, 21}, {185, 11}, {158, 11}, Box::REGULAR_BOX},
        {{142, 22}, {201, 22}, {201, 41}, {142, 41}, {185, 31}, {158, 31}, Box::REGULAR_BOX},
        {{142, 42}, {201, 42}, {201, 61}, {142, 61}, {185, 51}, {158, 51}, Box::REGULAR_BOX},
        {{142, 62}, {201, 62}, {201, 81}, {142, 81}, {185, 71}, {158, 71}, Box::REGULAR_BOX},
        {{142, 82}, {201, 82}, {201, 101}, {142, 101}, {185, 91}, {158, 91}, Box::SAFE_BOX},
        {{142, 102}, {201, 102}, {201, 121}, {142, 121}, {185, 111}, {158, 111}, Box::REGULAR_BOX},
        {{142, 122}, {201, 122}, {201, 141}, {142, 141}, {185, 131}, {158, 131}, Box::REGULAR_BOX},
        {{142, 142}, {201, 142}, {201, 161}, {162, 162}, {185, 151}, {168, 151}, Box::REGULAR_BOX}, // corner

        {{142, 141}, {162, 161}, {161, 201}, {142, 201}, {151, 185}, {151, 168}, Box::REGULAR_BOX}, // corner
        {{122, 142}, {141, 142}, {141, 201}, {122, 201}, {131, 185}, {131, 158}, Box::REGULAR_BOX},
        {{102, 142}, {121, 142}, {121, 201}, {102, 201}, {111, 185}, {111, 158}, Box::REGULAR_BOX},
        {{82, 142}, {101, 142}, {101, 201}, {82, 201}, {91, 185}, {91, 158}, Box::SAFE_BOX},
        {{62, 142}, {81, 142}, {81, 201}, {62, 201}, {71, 185}, {71, 158}, Box::REGULAR_BOX},
        {{42, 142}, {61, 142}, {61, 201}, {42, 201}, {51, 185}, {51, 158}, Box::REGULAR_BOX},
        {{22, 142}, {41, 142}, {41, 201}, {22, 201}, {31, 185}, {31, 158}, Box::REGULAR_BOX},
        {{2, 142}, {21, 142}, {21, 201}, {2, 201}, {11, 185}, {11, 158}, Box::REGULAR_BOX},
        // Por aquí
        {{2, 202}, {21, 202}, {21, 261}, {2, 261}, {11, 218}, {11, 245}, Box::BRANCHED_BOX, 3}, // branch

        {{2, 262}, {21, 262}, {21, 321}, {2, 321}, {11, 278}, {11, 305}, Box::REGULAR_BOX},
        {{22, 262}, {41, 262}, {41, 321}, {22, 321}, {31, 278}, {31, 305}, Box::REGULAR_BOX},
        {{42, 262}, {61, 262}, {61, 321}, {42, 321}, {51, 278}, {51, 305}, Box::REGULAR_BOX},
        {{62, 262}, {81, 262}, {81, 321}, {62, 321}, {71, 278}, {71, 305}, Box::REGULAR_BOX},
        {{82, 262}, {101, 262}, {101, 321}, {82, 321}, {91, 278}, {91, 305}, Box::SAFE_BOX},
        {{102, 262}, {121, 262}, {121, 321}, {102, 321}, {111, 278}, {111, 305}, Box::REGULAR_BOX},
        {{122, 262}, {141, 262}, {141, 321}, {122, 321}, {131, 278}, {131, 305}, Box::REGULAR_BOX},
        {{142, 262}, {162, 262}, {162, 302}, {142, 321}, {151, 278}, {151, 295}, Box::REGULAR_BOX}, // corner
    
        {{161, 302}, {201, 302}, {201, 321}, {142, 322}, {185, 311}, {168, 311}, Box::REGULAR_BOX}, // corner
        {{142, 322}, {201, 322}, {201, 341}, {142, 341}, {185, 331}, {158, 331}, Box::REGULAR_BOX},
        {{142, 342}, {201, 342}, {201, 361}, {142, 361}, {185, 351}, {158, 351}, Box::REGULAR_BOX},
        {{142, 362}, {201, 362}, {201, 381}, {142, 381}, {185, 371}, {158, 371}, Box::SAFE_BOX},
        {{142, 382}, {201, 382}, {201, 401}, {142, 401}, {185, 391}, {158, 391}, Box::REGULAR_BOX},
        {{142, 402}, {201, 402}, {201, 421}, {142, 421}, {185, 411}, {158, 411}, Box::REGULAR_BOX},
        {{142, 422}, {201, 422}, {201, 441}, {142, 441}, {185, 431}, {158, 431}, Box::REGULAR_BOX},
        {{142, 442}, {201, 442}, {201, 461}, {142, 461}, {185, 451}, {158, 451}, Box::REGULAR_BOX},

        {{202, 442}, {261, 442}, {261, 461}, {202, 461}, {218, 451}, {245, 451}, Box::BRANCHED_BOX, 0}, // branch

    };
    for (BoxData item : items)
    {
        switch (item.boxType)
        {
        case Box::SAFE_BOX:
            boxes.emplace_back(std::unique_ptr<Box>(new SafeBox(
                {(Vector2){position.x + item.v1.x, position.y + item.v1.y},
                 (Vector2){position.x + item.v2.x, position.y + item.v2.y},
                 (Vector2){position.x + item.v3.x, position.y + item.v3.y},
                 (Vector2){position.x + item.v4.x, position.y + item.v4.y},
                 (Vector2){position.x + item.v1.x, position.y + item.v1.y}},
                {position.x + item.p1.x, position.y + item.p1.y}, {position.x + item.p2.x, position.y + item.p2.y})));
            break;
        case Box::BRANCHED_BOX:
            boxes.emplace_back(std::unique_ptr<Box>(new BranchedBox(
                {(Vector2){position.x + item.v1.x, position.y + item.v1.y},
                 (Vector2){position.x + item.v2.x, position.y + item.v2.y},
                 (Vector2){position.x + item.v3.x, position.y + item.v3.y},
                 (Vector2){position.x + item.v4.x, position.y + item.v4.y},
                 (Vector2){position.x + item.v1.x, position.y + item.v1.y}},
                {position.x + item.p1.x, position.y + item.p1.y}, {position.x + item.p2.x, position.y + item.p2.y}, item.branchPlayer)));
            break;
        case Box::REGULAR_BOX:
            boxes.emplace_back(std::unique_ptr<Box>(new RegularBox(
                {(Vector2){position.x + item.v1.x, position.y + item.v1.y},
                 (Vector2){position.x + item.v2.x, position.y + item.v2.y},
                 (Vector2){position.x + item.v3.x, position.y + item.v3.y},
                 (Vector2){position.x + item.v4.x, position.y + item.v4.y},
                 (Vector2){position.x + item.v1.x, position.y + item.v1.y}},
                {position.x + item.p1.x, position.y + item.p1.y}, {position.x + item.p2.x, position.y + item.p2.y})));

            break;
        default:
            break;
        }
    }
}