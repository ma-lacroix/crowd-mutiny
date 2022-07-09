#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <vector>
#include "object.hpp"
#include "giant.hpp"

const float SCREEN_WIDTH {1500.0f};
const float SCREEN_HEIGHT {1500.0f};
enum class GAME_STATUS {STARTMENU,MAIN,PAUSE};


void genObjects(int max_random, std::vector<Object*> &objects, int num_circles, int num_diamonds, int num_triangles) {
    srand(static_cast<unsigned int>(std::time(nullptr))); 
    for (int i = 0;i < num_circles;++i ) {
        float rand1 = rand() % max_random;
        float rand2 = rand() % max_random;
        objects.push_back(new Object(0, sf::Color::Blue, sf::Vector2f(rand1,rand2)));
    }
    for (int i = 0;i < num_triangles;++i ) {
        float rand1 = rand() % max_random;
        float rand2 = rand() % max_random;
        objects.push_back(new Object(3, sf::Color::Red, sf::Vector2f(rand1,rand2)));
    }
    for (int i = 0;i < num_diamonds;++i ) {
        float rand1 = rand() % max_random;
        float rand2 = rand() % max_random;
        objects.push_back(new Object(4, sf::Color::Black, sf::Vector2f(rand1,rand2)));
    }
}

void randomPlayerSelect(std::vector<Object*> &objects) {
    srand(static_cast<unsigned int>(std::time(nullptr))); 
    int max_rand = objects.size()-1;
    objects.at(rand() % max_rand)->switchPlayer();
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

    // initialising game objects
    std::vector<Object*> objects;
    genObjects(static_cast<int>(SCREEN_WIDTH*0.8f),objects,5,3,6);
    randomPlayerSelect(objects);
    
    GAME_STATUS game_status = GAME_STATUS::MAIN; // TODO: unused variable

    while(window.isOpen()) {

        deltaTime = clock.restart().asSeconds();
        totalTime+=deltaTime;

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
            obj->update(deltaTime,totalTime);
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