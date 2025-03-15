#include "InputHandler.h"
#include <string>

class Input;
class Rectangle;

class MenuInputHandler : public InputHandler
{
public:
    MenuInputHandler(
        Rectangle playButton,
        Rectangle settingsButton,
        Rectangle exitButton);
    Input *handleInput();

private:
    Input *touch_play;
    Input *touch_settings;
    Input *touch_exit;

    Rectangle playButton_;
    std::string playButtonLabel_ = "Play"; 
    Rectangle settingsButton_;
    std::string settingsButtonLabel_ = "Settings"; 
    Rectangle exitButton_;
    std::string exitButtonLabel_ = "Exit";
};
