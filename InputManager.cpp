#include "InputManager.hpp"

/*Description: Checks to see if a sprite is clicked*/
bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window) {
    
    if (sf::Mouse::isButtonPressed(button)) {  // if the mouse button is being pressed
        // check if it has collided over the particular sprite
        sf::IntRect tempRect(object.getPosition().x , object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);
            if (tempRect.contains(sf::Mouse::getPosition(window)))  // check if mouse is inside of the rectangle
                return true;
        }
    return false;
}
    
sf::Vector2i getMousePosition(sf::RenderWindow &window) {
        
    return sf::Mouse::getPosition(window);
}

