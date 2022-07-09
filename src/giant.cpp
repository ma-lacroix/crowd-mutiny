#include "giant.hpp"


Giant::Giant(int object_type, sf::Vector2f start_position)
        :Object(object_type, start_position) {
    std::cout << "giant constructor called" << std::endl;
    this->speed = 500.0f;
    this->size = 500.0f;
    this->controls = false;
    this->start_position = start_position;
    this->red = 100;
    this->green = 100;
    this->blue = 100;
    this->current_position = start_position;
    this->some_shape = (object_type < 3) ? sf::CircleShape(size) : sf::CircleShape(size,object_type);
    some_shape.setPosition(current_position);
}

Giant::~Giant() {
    std::cout << "Giant destroyed" << std::endl;
}

void Giant::change_color() {
    some_shape.setFillColor(sf::Color(red,green,blue));
}

void Giant::update(float deltatime) {

    change_color();

    if(controls){

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
            if (red < 255) {red+=1;};
            some_shape.move(sf::Vector2f(0.0f,-deltatime*speed));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
            if (red > 0) {red-=1;};
            some_shape.move(sf::Vector2f(0.0f,deltatime*speed));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
            if (blue > 0) {blue-=1;};
            some_shape.move(sf::Vector2f(-deltatime*speed,0.0f));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
            if (blue < 255) {blue+=1;};
            some_shape.move(sf::Vector2f(deltatime*speed,0.0f));
        }
    }
}