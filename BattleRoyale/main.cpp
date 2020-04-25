#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <vector>
// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

struct point {
    int x;
    int y;
};

struct platforms {
    point small[4];
    point mid[2];
    point full;
};
// window dimensions
int length = 1600;
int width = 1200;

bool checkBounds(std::vector<int>, std::vector<int>, int, int);

int main(int, char const**) {
    
    srand(time(0));
    
    sf::RenderWindow window(sf::VideoMode(length, width), "SFML window");
    window.setFramerateLimit(60);

    sf::Image icon; // Set the Icon
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    sf::Texture background, small, mid, full, soldier, bullet;
    background.loadFromFile(resourcePath() + "Background.png");
    small.loadFromFile(resourcePath() + "Platform-Small.png");
    mid.loadFromFile(resourcePath() + "Platform-Mid.png");
    full.loadFromFile(resourcePath() + "Platform-Full.png");
    soldier.loadFromFile(resourcePath() + "Soldier.png");
    bullet.loadFromFile(resourcePath() + "Bullet.png");

    sf::Sprite sBackground(background), sSmall(small), sMid(mid), sFull(full),sSoldier(soldier), sBullet;

//    sf::Music music; // Load a music to play
//    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
//        return EXIT_FAILURE;
//    }
//    music.play(); // Play the music
    
    
    platforms p;
    point bulletPos, soldierPos;

    soldierPos.x = rand() % 1580 + 10;
    soldierPos.y = 1100; // player is 100 pixels tall this will have his feet on the ground
    sSoldier.setPosition(soldierPos.x, soldierPos.y); // setting player position

    p.small[0].x = 300;
    p.small[0].y = 1000;
    p.small[1].x = 1200;
    p.small[1].y = 1000;
    p.small[2].x = 600;
    p.small[2].y = 800;
    p.small[3].x = 900;
    p.small[3].y = 800;
    p.mid[0].x = 100;
    p.mid[0].y = 600;
    p.mid[1].x = 1200;
    p.mid[1].y = 600;
    p.full.x = 500;
    p.full.y = 400;
    sFull.setPosition(p.full.x, p.full.y);
    while (window.isOpen()) // Start the game loop
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) // Close window: exit
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code ==  sf::Keyboard::Escape) // Escape pressed: exit
                window.close();
            
            if (event.type == sf::Event::KeyPressed && event.key.code ==  sf::Keyboard::A) {
                sSoldier.move(-20, 0);
                sSoldier.setTextureRect(sf::IntRect(89, 0, -89, 100));
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code ==  sf::Keyboard::D) {
                sSoldier.move(20, 0);
                sSoldier.setTextureRect(sf::IntRect(0, 0, 89, 100));
            }
            
        }

        // Clear screen
        window.clear();
        window.draw(sBackground);
        for (int i = 0; i < 4; i++) { // drawing the platforms
            sSmall.setPosition(p.small[i].x, p.small[i].y);
            window.draw(sSmall);
        }
        for (int i = 0; i < 2; i++) {
            sMid.setPosition(p.mid[i].x, p.mid[i].y);
            window.draw(sMid);
        }
        window.draw(sFull);
        window.draw(sSoldier);
        window.display(); // Update the window
    }

    return EXIT_SUCCESS;
}

bool checkBounds(std::vector<int> listX, std::vector<int> listY, int x, int y) {
    
    return true;
}
