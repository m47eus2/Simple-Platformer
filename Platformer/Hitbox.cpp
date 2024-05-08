#include "Hitbox.h"

Hitbox::Hitbox()
{
	this->hitbox.setFillColor(sf::Color::Transparent);
	this->hitbox.setOutlineColor(sf::Color::Red);
	this->hitbox.setOutlineThickness(2.f);
}

Hitbox::~Hitbox()
{
}

void Hitbox::set(sf::Vector2f pos, sf::Vector2f size)
{
	this->hitbox.setPosition(pos);
	this->hitbox.setSize(size);
}

sf::FloatRect Hitbox::getGlobalBounds()
{
	return this->hitbox.getGlobalBounds();
}

sf::RectangleShape Hitbox::getRect()
{
	return this->hitbox;
}
