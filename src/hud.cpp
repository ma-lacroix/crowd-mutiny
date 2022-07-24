#include "hud.hpp"

Hud::Hud(sf::Vector2f position, std::string txt_msg1, std::string txt_msg2) {
    this->position = position;
    this->status = true;
    this->msg1 = txt_msg1;
    this->msg2 = txt_msg2;
    font.loadFromFile("media/fonts/Amatic-Bold.ttf");
    text.setString(txt_msg1);
    text.setFont(font);
    text.setCharacterSize(150);
    text.setPosition(position);
    text.setFillColor(sf::Color::Red);
}

Hud::~Hud() {
}

void Hud::switchMsg() {
    if(status){
        text.setString(msg2);
        status = false;
    }else{
        text.setString(msg1);
        status = true;
    }
}

void Hud::draw(sf::RenderWindow& window) {
    window.draw(text);
}