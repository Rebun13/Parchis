class Game;
class Input;

class GameState {
public:
    static class LoadingState loading;
    static class MenuState menu;
    static class PlayingState playing;

    virtual ~GameState() {}
    virtual void handleInput(Game &game, Input input) {
        InputHandler_->execute_()
    }
    virtual void update(Game &game) {}
private:
    class InputHandler *inputHandler_;
};
