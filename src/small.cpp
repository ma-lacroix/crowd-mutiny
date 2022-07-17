#include "small.hpp"
#define PI 3.14159265


Small::Small(int object_type, sf::Color some_color, sf::Vector2f start_position)
            :Object(object_type, some_color, start_position) {
    std::cout << "object constructor called" << std::endl;
    this->speed = rand() % 500 + 50;
    this->left_right = (speed % 2 == 0) ? -1 : 1;
    this->size = 50.0f;
    this->controls = false;
    this->start_position = start_position;
    this->current_position = start_position;
    this->color = some_color;
    this->some_shape = (object_type < 3) ? sf::CircleShape(size) : sf::CircleShape(size,object_type);
    some_shape.setPosition(current_position);
    some_shape.setFillColor(color);
}

Small::~Small() {
    std::cout << "Object destroyed" << std::endl;
}

void Small::switchPlayer() {
    std::cout << "Switch player function called" << "\n";
    controls = true;
    some_shape.setFillColor(sf::Color(100,100,100));
}

bool Small::isClose(sf::Vector2f player_position) {
    // Pythagoras theorem
    float a = powf(some_shape.getPosition().x - player_position.x,2);
    float b = powf(some_shape.getPosition().y - player_position.y,2);
    return sqrtf(a+b) < 300.0f;
}

void Small::update(float deltatime, float totalTime, sf::Vector2f player_position) {
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
    }else if(isClose(player_position)){
        some_shape.move(sf::Vector2f(-std::sinf(speed*totalTime/10.0f)*2.5f, std::cosf(speed*totalTime/10.0f)*1.5f*left_right));
    }else{
        some_shape.move(sf::Vector2f(-std::sinf(speed*totalTime/10.0f)/5.0f, std::cosf(speed*totalTime/10.0f)/5.0f*left_right));
    }
    
}