#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Hitbox.h"

class Map
{
private:
	//Variables

	//Sky
	sf::Sprite sky;
	sf::Texture skyTexture;

	//Tree
	sf::Sprite tree;
	sf::Texture treeTexture;

	//Small platform
	sf::Sprite smallPlatform;
	sf::Texture smallPlatformTexture;

	//platformLeft
	sf::Sprite platformLeft;
	sf::Texture platformLeftTexture;

	//Grass 1,2
	sf::Sprite grass1;
	sf::Texture grass1Texture;
	sf::Sprite grass2;
	sf::Texture grass2Texture;

	//Rock
	sf::Sprite rock;
	sf::Texture rockTexture;

	//FillRect
	sf::RectangleShape fillRect;

	//Hitboxes
	Hitbox platformHitbox;
	Hitbox smallPlatformHitbox;
	
	//Private functions
	void initTextures();
	void initSprites();
	void initHitboxes();

public:
	Map();
	virtual ~Map();

	sf::RectangleShape getPlatformHitbox();
	sf::RectangleShape getSmallPlatformHitbox();

	//Functions
	void render(sf::RenderTarget &target);
};