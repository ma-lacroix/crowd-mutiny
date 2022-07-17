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
public:
    Small(int, sf::Color, sf::Vector2f);
    ~Small();
    virtual void switchPlayer();
    virtual bool isClose(sf::Vector2f);
    virtual void update(float, float, sf::Vector2f) override;
};

#endif