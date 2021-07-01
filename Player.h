#ifndef PLAYER_H
#define PLAYERH

#include <SFML/Graphics.hpp>

namespace game {
	class Player : sf::Sprite
	{
	private:
		sf::Texture texture;
		sf::Image image;
		float velocity;
		sf::Vector2f position = { 400, 400 };
		sf::RectangleShape * shape;
		sf::RenderWindow * window;
	public:
		Player(sf::RenderWindow *window);
		void update(sf::Time deltaTime);
		void move(sf::Event *event, sf::Time deltaTime);
		void setVelocity(float velocity);
		sf::Vector2f getPosition();
		void setPosition(float x, float y);
		void setPosition(sf::Vector2f position);
		float getVelocity();
		void setShape();
		void moveShape();
		void setWindow(sf::RenderWindow * window);
		sf::RenderWindow*  getWindow();
	};
}

#endif PLAYER_H

