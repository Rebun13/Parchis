#include "InputHandler.h"

class Input;

class MenuInputHandler : public InputHandler
{
public:
    Input* handleInput();

private:
    Input *touch_play;
    Input *touch_settings;
    Input *touch_exit;
}