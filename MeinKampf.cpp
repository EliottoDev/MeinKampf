// MEINKAMPF_CPP : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.


#include<SFML/Graphics.hpp>
#include<thread>
#include<SFML/Window.hpp>
#include "Player.h"
#include<iostream>
#include "Cloud.h"

int main()
{   

    sf::RenderWindow window(sf::VideoMode(), "AAAAAA CON RAZON", sf::Style::Fullscreen);
    game::Player* player = new game::Player(&window);
    sf::Clock deltaClock;
    game::Cloud* nube = new game::Cloud(&window);

    window.setFramerateLimit(120);

    while (window.isOpen())
    {
        sf::Time deltaTime = deltaClock.restart();
        sf::Event event;

        std::cout << "X: " << player->getPosition().x << std::endl << "Y: " << player->getPosition().y << std::endl;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            //if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F11)
            //    if()
            if (event.type == sf::Event::KeyPressed)
                player->move(&event, deltaTime);
        }

        window.clear();
        player->update(deltaTime);
        nube->update(deltaTime);
        window.display();
    }

    return EXIT_SUCCESS;
};