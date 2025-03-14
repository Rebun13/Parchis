class Input;

class InputHandler
{
public:
    Input* virtual handleInput() = 0;
    void virtual bindInput() = 0;
};
