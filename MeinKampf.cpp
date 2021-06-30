// MEINKAMPF_CPP : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.


#include<SFML/Graphics.hpp>
#include<thread>
#include<SFML/Window.hpp>
#include "Player.h"
#include<iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "AAAAAA CON RAZON");
    game::Player* player = new game::Player(window);
    sf::Clock deltaClock;
    while (window.isOpen())
    {
        sf::Time deltaTime = deltaClock.restart();
        sf::Event event;

        std::cout << "X: " << player->getPosition().x << std::endl << "Y: " << player->getPosition().y << std::endl;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
                player->move(&event, deltaTime);
        }

        window.clear();
        player->update(deltaTime, window);
        window.display();
    }

    return EXIT_SUCCESS;

};