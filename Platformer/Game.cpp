#include "Game.h"

//Private functions
void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;

	this->window = new sf::RenderWindow(this->videoMode, "Game", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Game::initVariables()
{
	this->window = nullptr;
	this->standOnPlatform = false;
}

//Constructor destructor
Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

//Getters
const bool Game::running() const
{
	return this->window->isOpen();
}

const bool Game::ifStandOnPlatform() const
{
	return this->standOnPlatform;
}

void Game::playerCollisions()
{
	//Player global bounds
	sf::FloatRect playerGlobalBounds = this->player.getSprite().getGlobalBounds();
	//Platform global bounds
	sf::FloatRect platformGlobalBounds = this->map.getPlatformHitbox().getGlobalBounds();
	//Small platform global bounds
	sf::FloatRect smallPlatformGlobalBounds = this->map.getSmallPlatformHitbox().getGlobalBounds();

	//Window edges
	if (playerGlobalBounds.left < 0)
	{
		//If texture is not mirrored
		if(this->player.getSprite().getScale().x > 0)
			this->player.setPosition(0.f, this->player.getSprite().getPosition().y);
		else
			this->player.setPosition(playerGlobalBounds.width, this->player.getSprite().getPosition().y);
	}

	if (playerGlobalBounds.left + playerGlobalBounds.width > this->window->getSize().x)
	{
		//If texture is not mirrored
		if (this->player.getSprite().getScale().x > 0)
			this->player.setPosition(this->window->getSize().x - playerGlobalBounds.width, this->player.getSprite().getPosition().y);
		else
			this->player.setPosition(this->window->getSize().x, this->player.getSprite().getPosition().y);
	}

	//Setting default not standing
	this->player.setStanding(false);

	//Platform collision
	if (playerGlobalBounds.intersects(platformGlobalBounds))
	{
		//If player last y cord is above platform (checks if collision is with top surface)
		if (this->player.getPpos().top + this->player.getPpos().height < platformGlobalBounds.top + 1)
		{
			//Set player positoin
			this->player.setPosition(this->player.getSprite().getPosition().x, platformGlobalBounds.top - playerGlobalBounds.height);

			//Reset player vertical speed
			this->player.setSpeedy(0.f);

			//Player is standing
			this->player.setStanding(true);
		}
	}

	//Small Platform
	if (playerGlobalBounds.intersects(smallPlatformGlobalBounds))
	{
		//If player last y cord is above platform (checks if collision is with top surface)
		if (this->player.getPpos().top + this->player.getPpos().height < smallPlatformGlobalBounds.top + 1)
		{
			//Sets player position
			this->player.setPosition(this->player.getSprite().getPosition().x, smallPlatformGlobalBounds.top - playerGlobalBounds.height);

			//Reset player vertical speed
			this->player.setSpeedy(0.f);

			//Player stands
			this->player.setStanding(true);
		}
	}
}

//Functions
void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

//Update
void Game::update()
{
	this->pollEvents();

	//Update player
	this->player.update();

	//Collision
	this->playerCollisions();

	
}

//Render
void Game::render()
{
	this->window->clear();

	//Render map
	this->map.render(*this->window);

	//Render player
	this->player.render(*this->window);

	this->window->display();
}