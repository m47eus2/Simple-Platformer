#include "Player.h"

void Player::initTextures()
{
	if (!this->texture.loadFromFile("Textures/Character/character.png",sf::IntRect(13,7,19,28)))
		std::cout << "Error while loading character texture" << std::endl;
}

void Player::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(2.f, 2.f);
	this->sprite.setPosition(762.f, 0.f);
}

void Player::initVariables()
{
	this->speedx = 5.f;
	this->speedy = 0.f;
}

Player::Player()
{
	this->initTextures();
	this->initSprite();
	this->initVariables();
}

Player::~Player()
{
}

sf::Sprite Player::getSprite()
{
	return this->sprite;
}

void Player::setPosition(float x, float y)
{
	this->sprite.setPosition(sf::Vector2f(x, y));
}

void Player::setSpeedy(float value)
{
	this->speedy = value;
}

void Player::control()
{
	//Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->sprite.move(-this->speedx, 0.f);
	//Right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->sprite.move(this->speedx, 0.f);
}

void Player::gravity()
{
	this->speedy += 0.3f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		this->speedy = -8.f;

	this->sprite.move(0.f, this->speedy);
}


void Player::update()
{
	this->control();
	this->gravity();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}