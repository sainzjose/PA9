#pragma once


class State {
public:
    virtual void init() = 0; // initialize the state
    virtual void handleInput() = 0; // handle all input on the particular state
    virtual void update(float dt) = 0; // update any variables after input from the user
    virtual void draw(float dt) = 0; // draw application after input has been handled/updated
    virtual void pause() { } // will record when you pause the game
    virtual void resume() { } // will record when you resume the game
};

