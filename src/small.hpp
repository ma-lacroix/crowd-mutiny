#ifndef _SMALL_H_
#define _SMALL_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include "object.hpp"

class Small : public Object {
private:    
    int left_right;
    bool attraction;
    float sensitivity;
public:
    Small(int, sf::Color, sf::Vector2f);
    ~Small();
    void switchPlayer();
    void switchAttraction();
    bool isClose(sf::Vector2f);
    sf::Vector2f pushBack(sf::Vector2f player_position);
    void update(float, float, sf::Vector2f) override;
};

#endif