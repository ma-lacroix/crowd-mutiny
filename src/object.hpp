#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

class Object {
protected:    
    int speed;
    float size;
    bool controls;
    sf::CircleShape some_shape;
    sf::Vector2f start_position;
    sf::Vector2f current_position;
    sf::Color color;

public:
    Object(int, bool, sf::Color, sf::Vector2f);
    Object(int, bool, sf::Vector2f);
    virtual ~Object();
    virtual void update(float);
    virtual void draw(sf::RenderWindow&);
};

#endif