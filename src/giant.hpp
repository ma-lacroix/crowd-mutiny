#ifndef _GIANT_H_
#define _GIANT_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include "object.hpp"

class Giant : public Object {
private:    
    int red;
    int green;
    int blue;
public:
    Giant(int, sf::Color, sf::Vector2f);
    ~Giant();
    void update(float, float) override;
    void change_color();
};

#endif