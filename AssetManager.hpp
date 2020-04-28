#pragma once

#include <map>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp" // given to us by the SFML template on Xcode

class AssetManager {
private:
    std::map<std::string, sf::Texture> textures;
    std::map<std::string, sf::Font> fonts;
    
public:
    AssetManager() {} // constructor
    ~AssetManager() {} // destructor
    
    void loadTexture(std::string name, std::string fileName);
    sf::Texture &getTexture(std::string name); // takes the name of the tecture and will return ref to that tecture
    void loadFont(std::string name, std::string fileName);
    sf::Font &getFont(std::string name);
    
};


