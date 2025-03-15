class Input;
// Input handler binds the inputs to a input command (Input derivates)
class InputHandler
{
public:
    virtual Input* handleInput() = 0;
    virtual void bindInput() = 0;
};
