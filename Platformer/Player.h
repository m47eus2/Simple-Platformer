#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Player
{
private:
	sf::Sprite sprite;
	std::vector<sf::Texture> textures;

	float speedx;
	float speedy;

	sf::FloatRect ppos;

	bool standing;

	int animationTimer;
	int animationTimerMax;
	int animationFrame;
	bool animation;

	void initTextures();
	void initSprite();
	void initVariables();

	void setRightTexture();
	void setLeftTexture();

	void control();
	void gravity();
	void animate();

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
	void resetAnimationTimer();
	void setAnimationFrameStanding();
	void setAnimationFrameRunning();

	void update();
	void render(sf::RenderTarget &target);
};