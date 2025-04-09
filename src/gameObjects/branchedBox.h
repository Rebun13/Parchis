#include "box.h"

class BranchedBox : public Box
{
public:
    Box *getNextBox() override;

private:
    int playerIndex;
    Box *altNextBox;
}