#include "Player.h"

//Private functions
void Player::initTextures()
{
	sf::Texture texture;
	//Texture 0
	if (!texture.loadFromFile("Textures/Character/character.png",sf::IntRect(14,7,19,29)))
		std::cout << "Error while loading character texture 0" << std::endl;
	this->textures.push_back(texture);

	//Texture 1
	if (!texture.loadFromFile("Textures/Character/character.png", sf::IntRect(64, 6, 17, 30)))
		std::cout << "Error while loading character texture 1" << std::endl;
	this->textures.push_back(texture);

	//Texture 2
	if (!texture.loadFromFile("Textures/Character/character.png", sf::IntRect(114, 6, 19, 30)))
		std::cout << "Error while loading character texture 2" << std::endl;
	this->textures.push_back(texture);

	//Texture 3
	if (!texture.loadFromFile("Textures/Character/character.png", sf::IntRect(167, 8, 20, 28)))
		std::cout << "Error while loading character texture 3" << std::endl;
	this->textures.push_back(texture);

	//Texture 4
	if (!texture.loadFromFile("Textures/Character/character.png", sf::IntRect(216, 9, 20, 27)))
		std::cout << "Error while loading character texture 4" << std::endl;
	this->textures.push_back(texture);

	//Texture 5
	if (!texture.loadFromFile("Textures/Character/character.png", sf::IntRect(266, 11, 20, 25)))
		std::cout << "Error while loading character texture 5" << std::endl;
	this->textures.push_back(texture);

	//Texture 6
	if (!texture.loadFromFile("Textures/Character/character.png", sf::IntRect(317, 8, 23, 28)))
		std::cout << "Error while loading character texture 6" << std::endl;
	this->textures.push_back(texture);

	//Texture 7
	if (!texture.loadFromFile("Textures/Character/character.png", sf::IntRect(366, 9, 20, 27)))
		std::cout << "Error while loading character texture 7" << std::endl;
	this->textures.push_back(texture);

	//Texture 8
	if (!texture.loadFromFile("Textures/Character/character.png", sf::IntRect(416, 11, 20, 25)))
		std::cout << "Error while loading character texture 7" << std::endl;
	this->textures.push_back(texture);
}

void Player::initSprite()
{
	this->sprite.setTexture(this->textures[0]);
	this->sprite.setScale(2.f, 2.f);
	this->sprite.setPosition(762.f, 0.f);
}

void Player::initVariables()
{
	this->speedx = 5.f;
	this->speedy = 0.f;
	this->standing = false;

	this->ppos = this->sprite.getGlobalBounds();

	this->animationTimer = 0;
	this->animationTimerMax = 5;
	this->animationFrame = 0;
	this->animation = true;
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

void Player::resetAnimationTimer()
{
	this->animationTimer = 0;
}

void Player::setAnimationFrameStanding()
{
	if (this->animation == true)
	{
		this->animationFrame = 0;
		this->resetAnimationTimer();
	}
	this->animation = false;
}

void Player::setAnimationFrameRunning()
{
	if (this->animation == false)
	{
		this->animationFrame = 3;
		this->resetAnimationTimer();
	}
	this->animation = true;
}

void Player::control()
{
	//Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->sprite.move(-this->speedx, 0.f);
		this->setLeftTexture();
		//Set running animation
		this->setAnimationFrameRunning();
	}
	//Right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->sprite.move(this->speedx, 0.f);
		this->setRightTexture();
		//Set running animation
		this->setAnimationFrameRunning();
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->setAnimationFrameStanding();
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

void Player::animate()
{
	if (this->animation == true)
	{
		if (this->animationTimer >= this->animationTimerMax)
		{
			if (this->animationFrame < 8)
			{
				this->sprite.setTexture(textures[this->animationFrame + 1]);
				this->animationFrame += 1;
				this->animationTimer = 0;
			}
			else
			{
				this->sprite.setTexture(textures[3]);
				this->animationFrame = 3;
				this->animationTimer = 0;
			}
		}
		else
		{
			this->animationTimer += 1;
		}
	}
	else
	{
		if (this->animationTimer >= this->animationTimerMax*1.5)
		{
			if (this->animationFrame < 2)
			{
				this->sprite.setTexture(textures[this->animationFrame + 1]);
				this->animationFrame += 1;
				this->animationTimer = 0;
			}
			else
			{
				this->sprite.setTexture(textures[0]);
				this->animationFrame = 0;
				this->animationTimer = 0;
			}
		}
		else
		{
			this->animationTimer += 1;
		}
	}
}

void Player::update()
{
	this->setPpos();
	this->animate();
	this->control();
	this->gravity();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}