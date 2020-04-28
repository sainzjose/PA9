#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

struct GameData {
        
    StateMachine machine;
    sf::RenderWindow window;
    AssetManager assets;
    InputManager input;
};
    
typedef std::shared_ptr<GameData> GameDataRef;

class Game {
        
private:
    const float dt = 1.0f/ 60.f; // framerate 60 fps
    sf::Clock clock; // required for framerate
    GameDataRef data = std::make_shared<GameData>();
    void run(); // called to start the game
public:
    Game(int width, int height, std::string title); // initializer, pass in dimensions of screen and screen name
        
};

