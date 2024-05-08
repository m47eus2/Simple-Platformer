#include "Map.h"

//Private functions
void Map::initTextures()
{
	//Sky
	if (!this->skyTexture.loadFromFile("Textures/Map/sky.png"))
		std::cout << "Error while loading sky texture" << std::endl;

	//Tree
	if (!this->treeTexture.loadFromFile("Textures/Map/tileset.png", sf::IntRect(190, 45, 123, 114)))
		std::cout << "Error while tree texture" << std::endl;

	//Small platform
	if(!this->smallPlatformTexture.loadFromFile("Textures/Map/tileset.png", sf::IntRect(40, 25, 100, 75)))
		std::cout << "Error while loading smallPlatform texture" << std::endl;

	//Platform
	if(!this->platformLeftTexture.loadFromFile("Textures/Map/tileset.png", sf::IntRect(38, 176, 90, 112)))
		std::cout << "Error while loading platformLeft texture" << std::endl;

	//Grass 1
	if (!this->grass1Texture.loadFromFile("Textures/Map/tileset.png", sf::IntRect(192, 176, 47, 47)))
		std::cout << "Error while loading grass1 texture" << std::endl;

	//Grass 2
	if(!this->grass2Texture.loadFromFile("Textures/Map/tileset.png", sf::IntRect(256, 176, 31, 47)))
		std::cout << "Error while loading grass2 texture" << std::endl;

	//Rock
	if (!this->rockTexture.loadFromFile("Textures/Map/tileset.png", sf::IntRect(192, 240, 31, 63)))
		std::cout << "Error while loading rock texture" << std::endl;
}

void Map::initSprites()
{
	//Sky
	this->sky.setTexture(skyTexture);
	this->sky.setScale(2.f, 2.f);

	//Tree
	this->tree.setTexture(treeTexture);
	this->tree.setScale(2.f, 2.f);
	this->tree.setPosition(60.f, 80.f);

	//Small platform
	this->smallPlatform.setTexture(smallPlatformTexture);
	this->smallPlatform.setScale(2.f, 2.f);
	this->smallPlatform.setPosition(100.f, 300.f);

	//Platform
	this->platformLeft.setTexture(platformLeftTexture);
	this->platformLeft.setScale(2.f, 2.f);
	this->platformLeft.setPosition(464.f, 376.f);

	//Grass1
	this->grass1.setTexture(grass1Texture);
	this->grass1.setScale(2.f, 2.f);
	this->grass1.setPosition(644.f, 376.f);

	//Grass2
	this->grass2.setTexture(grass2Texture);
	this->grass2.setScale(2.f, 2.f);
	this->grass2.setPosition(738.f, 376.f);

	//Rock
	this->rock.setTexture(rockTexture);
	this->rock.setScale(2.1f, 2.1f);
	this->rock.setPosition(644.f, 470.f);

	//FillRect
	fillRect.setFillColor(sf::Color(17, 32, 36));
	fillRect.setPosition(708.f, 470.f);
	fillRect.setSize(sf::Vector2f(100.f, 130.f));
}

void Map::initHitboxes()
{
	this->platformHitbox.set(sf::Vector2f(473.f, 405.f), sf::Vector2f(327.f, 1.f));
	this->smallPlatformHitbox.set(sf::Vector2f(105.f, 308.f), sf::Vector2f(185.f, 1.f));
}

//Constructor destructor
Map::Map()
{
	this->initTextures();
	this->initSprites();
	this->initHitboxes();
}

Map::~Map()
{
}

sf::RectangleShape Map::getPlatformHitbox()
{
	return this->platformHitbox.getRect();
}

sf::RectangleShape Map::getSmallPlatformHitbox()
{
	return this->smallPlatformHitbox.getRect();
}

//Functions
void Map::render(sf::RenderTarget& target)
{
	//Setting position and render sky
	for(int i=0; i<8; i++)
	{
		this->sky.setPosition(112.f * i, 0.f);
		target.draw(this->sky);
	}

	//Tree
	target.draw(this->tree);
	
	//Small platform
	target.draw(this->smallPlatform);

	//Platrorm left
	target.draw(this->platformLeft);
	
	//Grass1
	target.draw(this->grass1);

	//Grass2
	target.draw(this->grass2);

	//Rock
	target.draw(this->rock);

	//FillRect
	target.draw(this->fillRect);

	//Hitboxes
	//target.draw(this->platformHitbox.getRect());
	//target.draw(this->smallPlatformHitbox.getRect());
}
