#pragma once

#include <SFML/Graphics.hpp>

class Hitbox
{
private:
	sf::RectangleShape hitbox;

public:
	Hitbox();
	virtual ~Hitbox();

	void set(sf::Vector2f pos, sf::Vector2f size);
	sf::FloatRect getGlobalBounds();
	sf::RectangleShape getRect();
};

