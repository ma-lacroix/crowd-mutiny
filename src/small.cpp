#include "small.hpp"
#define PI 3.14159265


Small::Small(int object_type, sf::Color some_color, sf::Vector2f start_position)
            :Object(object_type, some_color, start_position) {
    this->speed = rand() % 500 + 50;
    this->left_right = (speed % 2 == 0) ? -1 : 1;
    this->size = 50.0f*rand()/RAND_MAX;
    this->sensitivity = 500.0f*rand()/RAND_MAX;
    this->controls = false;
    this->attraction = false;
    this->start_position = start_position;
    this->current_position = start_position;
    this->color = some_color;
    this->some_shape = (object_type < 3) ? sf::CircleShape(size) : sf::CircleShape(size,object_type);
    some_shape.setPosition(current_position);
    some_shape.setFillColor(color);
}

Small::~Small() {
}

void Small::switchPlayer() {
    std::cout << "Switch player function called" << "\n";
    controls = true;
    speed = 500.0f;
    some_shape.setFillColor(sf::Color(100,100,100));
}

void Small::switchAttraction() {
    attraction = (attraction) ? false : true;
}

bool Small::isClose(sf::Vector2f player_position) {
    // Pythagoras theorem
    float a = powf(some_shape.getPosition().x - player_position.x,2);
    float b = powf(some_shape.getPosition().y - player_position.y,2);
    return sqrtf(a+b) < sensitivity;
}

sf::Vector2f Small::pushBack(sf::Vector2f player_position) {

    float a = sqrtf(powf(some_shape.getPosition().x - player_position.x,2));
    float b = sqrtf(powf(some_shape.getPosition().y - player_position.y,2));
    if(!attraction) {
        if (some_shape.getPosition().x < player_position.x) {
            a *= -1;
        }
        if (some_shape.getPosition().y < player_position.y) {
            b *= -1;
        }
    } else {
        if (some_shape.getPosition().x > player_position.x) {
            a *= -1;
        }
        if (some_shape.getPosition().y > player_position.y) {
            b *= -1;
        }
    }
    return sf::Vector2f(a*speed*rand()/RAND_MAX,b*speed*rand()/RAND_MAX);
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
        some_shape.move(sf::Vector2f(pushBack(player_position)*deltatime/100.0f));
    }else{
        some_shape.move(sf::Vector2f(-std::sinf(speed*totalTime/10.0f)/5.0f, std::cosf(speed*totalTime/10.0f)/5.0f*left_right));
    }
    
}