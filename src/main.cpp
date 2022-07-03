#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

const float SCREEN_WIDTH {1500.0f};
const float SCREEN_HEIGHT {1500.0f};

int main() {
    std::cout << "Starting program..." << std::endl;
    
    // TODO: create window
    sf::Vector2f screen_size {SCREEN_WIDTH,SCREEN_HEIGHT};
    sf::RenderWindow window(sf::VideoMode(screen_size.x,screen_size.y),
                            "Crowd Mutiny",sf::Style::Titlebar | sf::Style::Resize);
    sf::View view(screen_size/2.0f,screen_size);

    // TODO: main loop
    while(window.isOpen()) {

        // TODO: handle user input
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
        // TODO: objects moving logic
        sf::CircleShape circle(50.f);
        circle.setPosition(sf::Vector2f(100.0f,200.0f));
        circle.setFillColor(sf::Color(200, 250, 50));
        
        sf::CircleShape triangle(50.f,3);
        triangle.setPosition(sf::Vector2f(500.0f,200.0f));
        triangle.setFillColor(sf::Color(100, 10, 50));


        // TODO: draw functions
        window.clear(sf::Color::Black);
        window.draw(circle);
        window.draw(triangle);
        window.display();

    }
    
    return 0;
}