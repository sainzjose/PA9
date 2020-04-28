#pragma once

#include <memory>
#include <stack>

#include "State.hpp"

typedef std::unique_ptr<State> StateRef;

class StateMachine { // will handle all of the states

public:
    StateMachine() {} // constructor
    ~StateMachine() {} // destructor
    
    void addState(StateRef newState, bool isReplacing = true); // adds a state onto a stack it will be the latest state that is running everything else is paused
    void removeState(); // manually remove top state
    void processStateChanges(); // runs at the start of each game loop at the start of cpp file
        
    StateRef &getActiveState(); // returns the top level state
        
private:
    std::stack<StateRef> states; // stack of state references
    StateRef newState; // latest state to add
    
    bool isRemoving; // if we are removing a state
    bool isAdding; // if we are adding a state
    bool isReplacing; // if we are replacing a state
};

