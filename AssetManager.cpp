#include "AssetManager.hpp"


void AssetManager::loadTexture(std::string name, std::string fileName) {
    
    sf::Texture tex; // local texture instance
    
    if (tex.loadFromFile(resourcePath() + fileName))  // if it successfully loads this file
        this->textures[name] = tex; // we can add it to the map of textures using name as a key
}

sf::Texture &AssetManager::getTexture(std::string name) {
    
    return this->textures.at(name); // returns reference to texture at key name
}

void AssetManager::loadFont(std::string name, std::string fileName) {
    
    sf::Font font; // local font instance
    
    if (font.loadFromFile(fileName))  // if it successfully loads this file
        this->fonts[name] = font; // we can add it to the map of textures using name as a key
}

sf::Font &AssetManager::getFont(std::string name) {
    
    return this->fonts.at(name); // returns reference to font at key name
}

