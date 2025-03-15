// *Using command pattern*
// Abstract class for input commands.
// These commands define the function triggered by an input command.


class Input
{
public:
  virtual ~Input() {}
  virtual void execute() = 0;
};
