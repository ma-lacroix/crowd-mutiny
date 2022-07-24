#ifndef _HUD_H_
#define _HUD_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

class Hud {
private:
    sf::Text text;
    sf::Font font;
    std::string msg1;
    std::string msg2;
    bool status;
    sf::Vector2f position;
public:
    Hud(sf::Vector2f, std::string, std::string);
    ~Hud();
    void switchMsg();
    void draw(sf::RenderWindow&);
};

#endif