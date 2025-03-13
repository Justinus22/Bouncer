#include "PlatformGenerator.hpp"
#include <SFML/Graphics.hpp>
#include <constants.hpp>

PlatformGenerator::PlatformGenerator(sf::Texture platformTexture, sf::Texture smallPlatformTexture)
{
    this->platformTexture = platformTexture;
    this->smallPlatformTexture = smallPlatformTexture;
}

void PlatformGenerator::generateNextPlatform(std::list<sf::Sprite> &platforms)
{
    sf::Sprite newPlatform(platformTexture);
    newPlatform.setPosition({constants::WINDOW_WIDTH, 600});

    platforms.push_back(newPlatform);
}

bool PlatformGenerator::shouldGenerateNextPlatform(std::list<sf::Sprite> platforms)
{
    sf::Sprite lastPlatform = platforms.back();

    return constants::WINDOW_WIDTH - (lastPlatform.getGlobalBounds().position.x +
                                      lastPlatform.getGlobalBounds().size.x) >
           distanceToNextPlatform;
}

void PlatformGenerator::initPlatforms(std::list<sf::Sprite> &platforms)
{
    sf::Sprite landingPlatform(platformTexture);
    landingPlatform.setPosition({200, 600});

    sf::Sprite starterPlatform(platformTexture);
    starterPlatform.setPosition({700, 400});

    platforms.push_back(landingPlatform);
    platforms.push_back(starterPlatform);
}
