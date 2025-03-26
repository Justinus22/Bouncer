#include "Platform.hpp"
#include <iostream>

Platform::Platform() : sprite(platformTexture)
{
    if (!platformTexture.loadFromFile("assets/textures/platforms/ground_grass.png"))
    {
        std::cout << "Error loading ground grass texture;" << std::endl;
    }
    if (!platformSmallTexture.loadFromFile("assets/textures/platforms/ground_grass_small.png"))
    {
        std::cout << "Error loading ground grass small texture;" << std::endl;
    }
    if (!platformBrokenTexture.loadFromFile("assets/textures/platforms/ground_grass_broken.png"))
    {
        std::cout << "Error loading ground grass brokentexture;" << std::endl;
    }
    if (!platformSmallBrokenTexture.loadFromFile("assets/textures/platforms/ground_grass_small_broken.png"))
    {
        std::cout << "Error loading ground grass small and broken texture;" << std::endl;
    }

    sprite = sf::Sprite(platformTexture);
    size = Platform::Size::BIG;
    lifes = MAX_LIFE;
}

Platform::Platform(const Platform &oPlatform) : sprite(platformTexture)
{
    lifes = oPlatform.lifes;
    platformTexture = oPlatform.platformTexture;
    platformSmallTexture = oPlatform.platformSmallTexture;
    platformBrokenTexture = oPlatform.platformBrokenTexture;
    platformSmallBrokenTexture = oPlatform.platformSmallBrokenTexture;
    size = oPlatform.size;

    sprite = generateNewSpriteFromPlatformData(oPlatform.sprite.getPosition(), oPlatform.lifes, oPlatform.size);
}

sf::Sprite &Platform::getSprite()
{
    return this->sprite;
}

void Platform::setSprite(sf::Sprite sprite)
{
    this->sprite = sprite;
}

bool Platform::removeHealth()
{
    lifes--;
    this->sprite = generateNewSpriteFromPlatformData(this->sprite.getPosition(), this->lifes, this->size);
    return lifes > 0;
}

void Platform::render(sf::RenderWindow &window)
{
    window.draw(this->sprite);
}

Platform::Size Platform::getSize()
{
    return size;
}

void Platform::setSize(Platform::Size size)
{
    this->size = size;
    this->sprite = generateNewSpriteFromPlatformData(this->sprite.getPosition(), this->lifes, this->size);
}

sf::Sprite Platform::generateNewSpriteFromPlatformData(sf::Vector2f pos, int lifes, Size size)
{
    sf::Sprite sprite(platformTexture);
    switch (size)
    {
    case Platform::Size::BIG:
        if (lifes <= 1)
        {
            sprite = sf::Sprite(platformBrokenTexture);
        }
        else
        {
            sprite = sf::Sprite(platformTexture);
        }

        break;
    case Platform::Size::SMALL:
        if (lifes <= 1)
        {
            sprite = sf::Sprite(platformSmallBrokenTexture);
        }
        else
        {
            sprite = sf::Sprite(platformSmallTexture);
        }
        break;
    default:
        break;
    }
    sprite.setPosition(pos);
    return sprite;
}
