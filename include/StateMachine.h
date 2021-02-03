#ifndef STATE_MACHINE_CPP
#define STATE_MACHINE_CPP

#include "State.h"
#include <memory>
#include <stack>

namespace GameWrapper
{

// typedef State *StateRef;
typedef std::unique_ptr<State> StateRef;

class StateMachine
{
  public:
    StateMachine() {}
    ~StateMachine() {}

    void AddState(StateRef newState, bool isReplacing = true);
    void RemoveState();

    void ProcessStateChanges();

    StateRef& GetActiveState();

  private:
    std::stack<StateRef> _states;
    StateRef _newState;

    bool _isRemoving;
    bool _isReplacing;
    bool _isAdding;
};

} // GameWrapper

#endif // STATE_MACHINE_CPP
