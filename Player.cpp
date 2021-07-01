#include "Player.h"

game::Player::Player( sf::RenderWindow * window) {
	// this->image.loadFromFile("player.jpg");
	this->setWindow(window);
	this->setVelocity(100);
	// this->texture.loadFromImage(this->image);
	this->setTexture(this->texture);
	this->setShape();
	this->setPosition(((unsigned int)this->window->getSize().x / 2), ((unsigned int)this->window->getSize().y/2));
};

void game::Player::update(sf::Time deltaTime) {
	
	this->window->draw(*this->shape);

	// TODO Hacer animaciones del jugador
	
};

void game::Player::moveShape() {
	this->shape->setPosition(this->position);
};

void game::Player::setWindow(sf::RenderWindow * window) {
	this->window = window;
};

sf::RenderWindow* game::Player::getWindow() {
	return this->window;
}

void game::Player::setShape() {
	sf::RectangleShape * rect = new sf::RectangleShape({50, 50});
	rect->setFillColor(sf::Color::Blue);
	rect->setPosition(this->position);
	rect->setOutlineColor(sf::Color::White);
	rect->setOutlineThickness(2);
	this->shape = rect;
};

void game::Player::move(sf::Event *event, sf::Time deltaTime) {
	if (event->key.code == sf::Keyboard::W || event->key.code == sf::Keyboard::Up)
		this->setPosition(this->getPosition().x, this->getPosition().y - deltaTime.asSeconds() * this->velocity);
	if (event->key.code == sf::Keyboard::S || event->key.code == sf::Keyboard::Down)
		this->setPosition(this->getPosition().x, this->getPosition().y + deltaTime.asSeconds() * this->velocity);
	this->moveShape();
};

void game::Player::setVelocity(float velocity) {
	this->velocity = velocity;
};

sf::Vector2f game::Player::getPosition(){
	return this->position;
};

float game::Player::getVelocity() {
	return this->velocity;
};

void game::Player::setPosition(sf::Vector2f position) {
	this->position = position;
};

void game::Player::setPosition(float x, float y) {
	this->position = { x, y };
};