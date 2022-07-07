#include "object.hpp"

Object::Object(int object_type, sf::Vector2f start_position){
    this->speed = 100.0f;
    this->size = 50.0f;
    this->start_position = start_position;
    this->current_position = start_position;
    this->color = sf::Color(200, 250, 50);
    this->some_shape = (object_type > 0) ? sf::CircleShape(size,object_type) : sf::CircleShape(size);
    some_shape.setPosition(current_position);
    some_shape.setFillColor(color);
}

Object::~Object() {
    std::cout << "Object destroyed" << std::endl;
}

void Object::move(float deltatime) {
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
        some_shape.move(sf::Vector2f(0.0f,-deltatime*speed));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
        some_shape.move(sf::Vector2f(0.0f,deltatime*speed));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
        some_shape.move(sf::Vector2f(-deltatime*speed,0.0f));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
        some_shape.move(sf::Vector2f(deltatime*speed,0.0f));
    }
}

void Object::draw(sf::RenderWindow& window) {
    window.draw(some_shape);
}