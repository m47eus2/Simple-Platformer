#pragma once
#include <SFML/Graphics.hpp>

#include "Map.h"
#include "Player.h"

class Game
{
	//Variables
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	Map map;

	Player player;

	bool standOnPlatform;

	//Private functions
	void initVariables();
	void initWindow();

public:
	//Constructor destructor
	Game();
	virtual ~Game();

	//Getters
	const bool running() const;
	const bool ifStandOnPlatform() const;

	//Functions
	void playerCollisions();

	void pollEvents();
	void update();
	void render();
};