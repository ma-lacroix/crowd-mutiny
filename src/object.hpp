#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

class Object {
protected:    
    int speed;
    float size;
    int left_right;
    bool controls;
    sf::CircleShape some_shape;
    sf::Vector2f start_position;
    sf::Vector2f current_position;
    sf::Color color;

public:
    Object(int, sf::Color, sf::Vector2f);
    Object(int, sf::Vector2f);
    virtual ~Object();
    virtual void switchPlayer();
    virtual bool isClose(sf::Vector2f);
    virtual void update(float, float, sf::Vector2f);
    virtual sf::Vector2f getPosition();
    virtual void draw(sf::RenderWindow&);
};

#endif