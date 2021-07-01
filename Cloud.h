#pragma once
#ifndef CLOUD_H
#define CLOUD_H

#include <SFML/Graphics.hpp>

namespace game {
	class Cloud : sf::Sprite
	{

	private:
		
		float velocity;
		sf::Vector2f position;
		sf::RectangleShape shape;
		sf::RenderWindow* window;

	public:

		Cloud(sf::RenderWindow *window);
		void move(sf::Time deltatime);
		void moveShape();
		void createShape();
		sf::RectangleShape getShape();
		void setShape(sf::RectangleShape shape);
		sf::Vector2f getPosition();
		void setPosition(sf::Vector2f position);
		void setPosition(float x, float y);
		float getVelocity();
		void setVelocity(float velocity);
		void update(sf::Time deltatime);
		void setWindow(sf::RenderWindow * window);
		sf::RenderWindow* getWindow();

	};
};

#endif
