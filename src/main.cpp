#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "object.hpp"

const float SCREEN_WIDTH {1500.0f};
const float SCREEN_HEIGHT {1500.0f};

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
    Object* circle = new Object(0,sf::Vector2f(100.0f,200.0f));

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
                circle->~Object();
                window.close();
            }
        }
        // objects update
        circle->move(deltaTime);
        
        // drawing stuff onscreen
        window.clear(sf::Color::Black);
        circle->draw(window);
        window.display();

    }
    
    return 0;
}