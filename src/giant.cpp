#include "giant.hpp"


Giant::Giant(int object_type, sf::Color object_color, sf::Vector2f start_position)
        :Object(object_type, object_color, start_position) {
    std::cout << "giant constructor called" << std::endl;
    this->speed = 500.0f;
    this->color = object_color;
    this->size = 500.0f;    
    this->controls = false;
    this->start_position = start_position;
    this->red = 200;
    this->green = 200;
    this->blue = 200;
    this->current_position = start_position;
    this->some_shape = (object_type < 3) ? sf::CircleShape(size) : sf::CircleShape(size,object_type);
    some_shape.setPosition(current_position);
    some_shape.setFillColor(sf::Color(red,green,blue));
}

Giant::~Giant() {
    std::cout << "Giant destroyed" << std::endl;
}

void Giant::change_color() {
    some_shape.setFillColor(sf::Color(red,green,blue));
}

void Giant::update(float deltatime, float totalTime) {

    change_color();

    if(!controls){

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
            if (red < 255) {red+=1;};
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
            if (red > 0) {red-=1;};
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
            if (blue > 0) {blue-=1;};
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
            if (blue < 255) {blue+=1;};
        }
    }
}