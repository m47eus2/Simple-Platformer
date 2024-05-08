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

void Game::playerCollisions()
{
	//Window edges
	if (this->player.getSprite().getGlobalBounds().left < 0)
		this->player.setPosition(0.f, this->player.getSprite().getPosition().y);
	if (this->player.getSprite().getGlobalBounds().left + this->player.getSprite().getGlobalBounds().width > this->window->getSize().x)
		this->player.setPosition(this->window->getSize().x - this->player.getSprite().getGlobalBounds().width, this->player.getSprite().getPosition().y);

	//Platform
	if (this->player.getSprite().getGlobalBounds().intersects(this->map.getPlatformHitbox().getGlobalBounds()))
	{
		this->player.setPosition(
			this->player.getSprite().getPosition().x, 
			this->map.getPlatformHitbox().getGlobalBounds().top - this->player.getSprite().getGlobalBounds().height);
		this->player.setSpeedy(0.f);
	}

	//Small Platform
	if (this->player.getSprite().getGlobalBounds().intersects(this->map.getSmallPlatformHitbox().getGlobalBounds()))
	{
		this->player.setPosition(
			this->player.getSprite().getPosition().x,
			this->map.getSmallPlatformHitbox().getGlobalBounds().top - this->player.getSprite().getGlobalBounds().height);
		this->player.setSpeedy(0.f);
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