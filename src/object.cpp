#include "object.hpp"

Object::Object(int object_type, sf::Color some_color, sf::Vector2f start_position){
    std::cout << "object constructor called" << std::endl;
    this->speed = rand() % 500;
    this->size = 50.0f;
    this->controls = false;
    this->start_position = start_position;
    this->current_position = start_position;
    this->color = some_color;
    this->some_shape = (object_type < 3) ? sf::CircleShape(size) : sf::CircleShape(size,object_type);
    some_shape.setPosition(current_position);
    some_shape.setFillColor(color);
}

Object::Object(int object_type, sf::Vector2f start_position){
    std::cout << "object constructor called" << std::endl;
    this->speed = rand() % 200;
    this->size = 50.0f;
    this->controls = false;
    this->start_position = start_position;
    this->current_position = start_position;
    this->color = sf::Color(255,255,0);
    this->some_shape = (object_type < 3) ? sf::CircleShape(size) : sf::CircleShape(size,object_type);
    some_shape.setPosition(current_position);
    some_shape.setFillColor(color);
}

Object::~Object() {
    std::cout << "Object destroyed" << std::endl;
}

void Object::switchPlayer() {
    controls = true;
}

void Object::update(float deltatime) {
    if(controls){
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
    }else{
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)){
            some_shape.move(sf::Vector2f(0.0f,deltatime*speed));
        }
    }
    
}

void Object::draw(sf::RenderWindow& window) {
    window.draw(some_shape);
}