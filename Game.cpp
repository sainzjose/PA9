#include "Game.hpp"

// In order for this to work you must add an initial game state
Game::Game(int width, int height, std::string title) {
        
    data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar); // creates the render window
        
    this->run(); // calls the run method which executes the game
}

void Game::run() {
        
    float newTime, frameTime, interpolation;
    float currentTime = this->clock.getElapsedTime().asSeconds(); // amount of time that has occured since clock starter
    float accumuluator = 0.0f; // total frame time
        
    while(this->data->window.isOpen()) { // while the window is open constantly run this loop
            
        this->data->machine.processStateChanges(); // we want to process any state changes
        newTime = this->clock.getElapsedTime().asSeconds(); // gets the new time
        frameTime = newTime - currentTime; // how long it took between frames needed to handle differences in frame time
            
        if(frameTime > .25f) // restricting it so it doesn't go too high
            frameTime = .25f;
            
        currentTime = newTime;
        accumuluator += frameTime; // total of all frame times
            
        while(accumuluator >= dt) { // while the accumulator is less than or equal to delta
                
            this->data->machine.getActiveState()->handleInput(); // handle the input
            this->data->machine.getActiveState()->update(dt);
            accumuluator -= dt;
        }
            
        interpolation = accumuluator / dt;
        this->data->machine.getActiveState()->draw(interpolation);
    }
}


