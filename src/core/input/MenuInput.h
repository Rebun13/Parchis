#include "Input.h"

class StartPlaying : public Input
{
public:
    void execute()
    {
        // startPlaying(); -> setGameState, callFactory (?), makeSound, launchMatchMaker
    }
};

class OpenSettings : public Input
{
public:
    void execute()
    {
        // openSettings();
    }
};

class ExitGame : public Input
{
public:
    void execute()
    {
        // exitGame();
    }
};