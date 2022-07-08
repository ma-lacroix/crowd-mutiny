#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "object.hpp"
#include "giant.hpp"


const float SCREEN_WIDTH {1500.0f};
const float SCREEN_HEIGHT {1500.0f};
enum GAME_STATUS {STARTMENU,MAIN,PAUSE}; // NOT USED YET


std::vector<Object*> genObjects() {
    std::vector<Object*> objects;
    Object* circle = new Object(0,true, sf::Color::Blue, sf::Vector2f(100.0f,200.0f));
    objects.push_back(circle);
    Object* diamond = new Object(4,false, sf::Color::Red,sf::Vector2f(500.0f,500.0f));
    objects.push_back(diamond);
    Object* triangle = new Giant(3,true, sf::Vector2f(500.0f,200.0f));
    objects.push_back(triangle);
    return objects;
}


int main() {
    std::cout << "Starting program..." << std::endl;
    
    // initialising variables
    float deltaTime {0.0f};
    float totalTime {0.0f};
    sf::Clock clock;


    // initialising game window
    sf::Vector2f screen_size {SCREEN_WIDTH,SCREEN_HEIGHT};
    sf::RenderWindow window(sf::VideoMode(screen_size.x,screen_size.y),
                            "Crowd Mutiny",sf::Style::Titlebar | sf::Style::Resize);
    sf::View view(screen_size/2.0f,screen_size);

    // initialising on-screen stuff
    std::vector<Object*> objects = genObjects();


    while(window.isOpen()) {
        
        deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                for(auto obj: objects){
                    obj->~Object();
                }
                window.close();
            }
        }
        // objects update
        for(auto obj: objects){
            obj->update(deltaTime);
        }
        
        // drawing stuff onscreen
        window.clear(sf::Color(255,255,200));
        for(auto obj: objects){
            obj->draw(window);
        }
        window.display();

    }
    
    return 0;
}