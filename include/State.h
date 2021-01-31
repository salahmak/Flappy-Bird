#ifndef STATE_H
#define STATE_H

namespace GameWrapper
{
class State
{
  public:
  	State(){};
    virtual void Init() = 0;
    virtual void Update(float dt) = 0;
    virtual void HandleInput() = 0;
    virtual void Draw(float dt) = 0;
    virtual void Pause() = 0;
    virtual void Resume() = 0;
};
} // namespace GameWrapper

#endif // STATE_H
