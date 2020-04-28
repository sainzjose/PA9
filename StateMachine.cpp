#include "StateMachine.hpp"


void StateMachine::addState(StateRef newState, bool isReplacing) {
    
    this->isAdding = true;
    this->isReplacing = isReplacing;
    this->newState = std::move(newState); // move is a copy constructor
}
    
void StateMachine::removeState() {
    
    this->isRemoving = true;
}

void StateMachine::processStateChanges() {
    
    if (this->isRemoving && !this->states.empty()) { // if removing is set to true and stack is!empty
        this->states.pop(); // pop the state
        if (!this->states.empty()) // if any states are left
            this->states.top()->resume(); // we resume the next state which is now top state
        this->isRemoving = false; // then removing is false
    }
    
    if (this->isAdding) { // if is adding is true it means we want to add a state
        if(!this->states.empty()) { // if states is not empty
            if (this->isReplacing) // if we want to replace our current state
                this->states.pop(); // pop the state
            else // if we aren't replacing it
                this->states.top()->pause(); // pause the state
        }
        this->states.push(std::move(this->newState)); // push the newState
        this->states.top()->init(); // intialize the state, set variables or loading textures
        this->isAdding = false; // we dont want to keep adding states so set to false
    }
}

StateRef &StateMachine::getActiveState() {
    
    return this->states.top(); // returns top state
}
