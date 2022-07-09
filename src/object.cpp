#include "object.hpp"
#define PI 3.14159265

Object::Object(int object_type, sf::Color some_color, sf::Vector2f start_position){
    std::cout << "object constructor called" << std::endl;
    this->speed = rand() % 500 + 50;
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
    some_shape.setFillColor(sf::Color(100,100,100));
}

void Object::update(float deltatime, float totalTime) {
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
        some_shape.move(sf::Vector2f(-std::sinf(speed*totalTime/10.0f)/5.0f, std::cosf(speed*totalTime/10.0f)/5.0f));
    }
    
}

sf::Vector2f Object::getPosition(){
    return some_shape.getPosition();
}

void Object::draw(sf::RenderWindow& window) {
    window.draw(some_shape);
}