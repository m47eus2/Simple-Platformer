#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	float speedx;
	float speedy;

	void initTextures();
	void initSprite();
	void initVariables();
public:
	Player();
	virtual ~Player();

	sf::Sprite getSprite();
	void setPosition(float x, float y);
	void setSpeedy(float value);

	void control();
	void gravity();

	void update();
	void render(sf::RenderTarget &target);
};

