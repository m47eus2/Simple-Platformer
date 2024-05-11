#include "Player.h"

//Private functions
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
	this->standing = false;

	this->ppos = this->sprite.getGlobalBounds();
}

void Player::setRightTexture()
{
	//If mirroring texture correct position
	if (this->sprite.getScale().x < 0.f)
		this->sprite.move(-this->sprite.getGlobalBounds().width, 0.f);

	this->sprite.setScale(sf::Vector2f(2.f, 2.f));
}

void Player::setLeftTexture()
{
	//If mirroring texture correct position
	if (this->sprite.getScale().x > 0.f)
		this->sprite.move(this->sprite.getGlobalBounds().width, 0.f);

	this->sprite.setScale(sf::Vector2f(-2.f, 2.f));
}

//Constructor destructor
Player::Player()
{
	this->initTextures();
	this->initSprite();
	this->initVariables();
}

Player::~Player()
{
}

//Public functions
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

void Player::setStanding(bool s)
{
	this->standing = s;
}

void Player::setPpos()
{
	this->ppos = this->sprite.getGlobalBounds();
}

sf::FloatRect Player::getPpos()
{
	return this->ppos;
}

void Player::respawn()
{
	this->setRightTexture();
	this->speedy = 0.f;
	this->sprite.setPosition(sf::Vector2f(762.f, 0.f));
}

void Player::control()
{
	//Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->sprite.move(-this->speedx, 0.f);
		this->setLeftTexture();
	}
	//Right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->sprite.move(this->speedx, 0.f);
		this->setRightTexture();
	}
}

void Player::gravity()
{
	this->speedy += 0.4f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		if(standing == true)
			this->speedy = -12.f;

	this->sprite.move(0.f, this->speedy);
}

void Player::update()
{
	this->setPpos();
	this->control();
	this->gravity();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}