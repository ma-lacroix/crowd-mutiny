#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <vector>
#include "object.hpp"
#include "giant.hpp"
#include "small.hpp"
#include "hud.hpp"

const float SCREEN_WIDTH {1500.0f};
const float SCREEN_HEIGHT {1500.0f};
enum class GAME_STATUS {STARTMENU,MAIN,PAUSE};

template<class T>
void genObjects(int max_random, std::vector<T*> &objects, int num_circles, int num_diamonds, int num_triangles) {
    srand(static_cast<unsigned int>(std::time(nullptr))); 
    for (int i = 0;i < num_circles;++i ) {
        float rand1 = rand() % max_random;
        float rand2 = rand() % max_random;
        objects.push_back(new T(0, sf::Color::Blue, sf::Vector2f(rand1,rand2)));
    }
    for (int i = 0;i < num_triangles;++i ) {
        float rand1 = rand() % max_random;
        float rand2 = rand() % max_random;
        objects.push_back(new T(3, sf::Color::Green, sf::Vector2f(rand1,rand2)));
    }
    for (int i = 0;i < num_diamonds;++i ) {
        float rand1 = rand() % max_random;
        float rand2 = rand() % max_random;
        objects.push_back(new T(4, sf::Color::Black, sf::Vector2f(rand1,rand2)));
    }
}

void randomPlayerSelect(int rand_pick, std::vector<Small*> &objects) {
    objects.at(rand_pick)->switchPlayer();
}

int randomPlayerPick(std::vector<Small*> &objects){
    srand(static_cast<unsigned int>(std::time(nullptr))); 
    int rand_pick = rand() % (objects.size()-1);
    randomPlayerSelect(rand_pick, objects);
    return rand_pick;
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
    sf::View hudView(screen_size/2.0f,screen_size);

    // initialising game objects
    int num_circles = rand() % 500, 
    num_diamonds = rand() % 500, 
    num_triangles = rand() % 500;
    std::vector<Small*> objects;
    std::vector<Giant*> backgrounds;
    genObjects(static_cast<int>(SCREEN_WIDTH*1.2f),objects,num_circles,num_diamonds,num_triangles);
    genObjects(static_cast<int>(SCREEN_WIDTH*1.5f),backgrounds,5,5,5);
    int rand_pick = randomPlayerPick(objects);

    // initialising hud
    Hud* hud = new Hud(sf::Vector2f(SCREEN_WIDTH*0.7,SCREEN_WIDTH*0.03),"Repulsion","Attraction");

    GAME_STATUS game_status = GAME_STATUS::MAIN; // TODO: unused variable

    sf::Color screen_colors(255,255,180);

    while(window.isOpen()) {
        sf::Vector2f player_center = objects.at(rand_pick)->getPosition();
        view.setCenter(player_center);
        window.setView(view);
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
                    obj->~Small();
                }
                for(auto back: backgrounds){
                    back->~Giant();
                }
                window.close();
            }
            // Space pressed: change dynamic
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                for(auto obj: objects){
                    obj->switchAttraction();
                }
                hud->switchMsg();
                screen_colors = (screen_colors == sf::Color(200,200,180)) ? sf::Color(255,255,180) : sf::Color(200,200,180);
            }
        }
        // objects update
        for(auto back: backgrounds){
            back->update(deltaTime,totalTime);
        }
        for(auto obj: objects){
            obj->update(deltaTime,totalTime,player_center);
        }
        
        // drawing stuff onscreen
        window.clear(screen_colors);
        for(auto back: backgrounds){
            back->draw(window);
        }
        for(auto obj: objects){
            obj->draw(window);
        }
        window.setView(hudView);
        hud->draw(window);

        window.display();

    }
    
    return 0;
}