#include "Cloud.h"

game::Cloud::Cloud(sf::RenderWindow * window) {

	this->setWindow(window);
	this->createShape();
	this->setPosition(this->getWindow()->getSize().x + this->getShape().getSize().x, 100);
}

void game::Cloud::update(sf::Time deltatime) {
	this->move(deltatime);
	this->moveShape();
	window->draw(this->getShape());
};

void game::Cloud::move(sf::Time deltatime) {

	this->setPosition(this->getPosition().x - deltatime.asSeconds() * this->getVelocity(), this->getPosition().y);
	
	if (this->getPosition().x <= 0)
		this->setPosition(this->getWindow()->getSize().x + this->getShape().getSize().x, this->getPosition().y);
};

void game::Cloud::moveShape() {
	this->getShape().setPosition(this->getPosition());
};

void game::Cloud::createShape() {
	sf::RectangleShape rect({ 50, 50 });
	rect.setFillColor(sf::Color::White);
	rect.setPosition(this->position);
	rect.setOutlineColor(sf::Color::Red);
	rect.setOutlineThickness(2);
	this->shape = rect;
}

void game::Cloud::setShape(sf::RectangleShape shape) {
	this->shape = shape;
};

sf::Vector2f game::Cloud::getPosition() {
	return this->position;
};

void game::Cloud::setPosition(float x, float y) {
	this->position = { x, y };
};

void game::Cloud::setPosition(sf::Vector2f position) {
	this->position = position;
};

float game::Cloud::getVelocity() {
	return this->velocity;
};

void game::Cloud::setVelocity(float velocity) {
	this->velocity = velocity;
};

void game::Cloud::setWindow(sf::RenderWindow * window) {
	this->window = window;
};

sf::RenderWindow* game::Cloud::getWindow() {
	return this->window;
};