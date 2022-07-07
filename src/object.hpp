#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

class Object {
private:    
    int speed;
    float size;
    sf::CircleShape some_shape;
    sf::Vector2f start_position;
    sf::Vector2f current_position;
    sf::Color color;

public:
    Object(int, sf::Vector2f);
    ~Object();
    void move(float);
    void draw(sf::RenderWindow&);
};

#endif