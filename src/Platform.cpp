#include "Platform.hpp"
#include <iostream>
#include "AssetManager.hpp"

Platform::Platform(AssetManager &assetManager) : assetManager(assetManager), sprite(assetManager.getPlatformTexture())
{
    size = Platform::Size::BIG;
    lifes = MAX_LIFE;
}

Platform::Platform(const Platform &oPlatform) : assetManager(oPlatform.assetManager), sprite(assetManager.getPlatformTexture())
{
    lifes = oPlatform.lifes;
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

void Platform::removeHealth()
{
    lifes--;

    if (lifes <= 1)
    {
        this->sprite = generateNewSpriteFromPlatformData(this->sprite.getPosition(), this->lifes, this->size);
    }
}

bool Platform::hasHealthLeft()
{
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

bool Platform::operator==(const Platform &otherPlatform) const
{
    return sprite.getPosition().x == otherPlatform.sprite.getPosition().x;
}

bool Platform::operator!=(const Platform &otherPlatform) const
{
    return !operator==(otherPlatform);
}

sf::Sprite Platform::generateNewSpriteFromPlatformData(sf::Vector2f pos, int lifes, Size size)
{
    sf::Sprite sprite(assetManager.getPlatformTexture());
    switch (size)
    {
    case Platform::Size::BIG:
        if (lifes <= 1)
        {
            sprite = sf::Sprite(assetManager.getPlatformBrokenTexture());
        }
        else
        {
            sprite = sf::Sprite(assetManager.getPlatformTexture());
        }

        break;
    case Platform::Size::SMALL:
        if (lifes <= 1)
        {
            sprite = sf::Sprite(assetManager.getPlatformSmallBrokenTexture());
        }
        else
        {
            sprite = sf::Sprite(assetManager.getPlatformSmallTexture());
        }
        break;
    default:
        break;
    }
    sprite.setPosition(pos);
    return sprite;
}
