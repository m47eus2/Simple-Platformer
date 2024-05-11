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

	sf::FloatRect ppos;

	bool standing;

	void initTextures();
	void initSprite();
	void initVariables();

	void setRightTexture();
	void setLeftTexture();

	void control();
	void gravity();

public:
	Player();
	virtual ~Player();

	sf::Sprite getSprite();
	void setPosition(float x, float y);
	void setSpeedy(float value);
	void setStanding(bool s);
	void setPpos();
	sf::FloatRect getPpos();
	void respawn();

	void update();
	void render(sf::RenderTarget &target);
};