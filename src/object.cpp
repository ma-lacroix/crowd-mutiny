#include "object.hpp"
#define PI 3.14159265

Object::Object(int object_type, sf::Color some_color, sf::Vector2f start_position){
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

Object::~Object() {
}

void Object::update(float deltatime, float totalTime) {
}

void Object::update(float deltatime, float totalTime, sf::Vector2f player_position) {
}

sf::Vector2f Object::getPosition(){
    return some_shape.getPosition();
}

void Object::draw(sf::RenderWindow& window) {
    window.draw(some_shape);
}