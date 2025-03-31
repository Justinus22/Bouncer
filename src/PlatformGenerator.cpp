#include "PlatformGenerator.hpp"
#include <SFML/Graphics.hpp>
#include <constants.hpp>
#include <random>
#include <iostream>
#include "AssetManager.hpp"

void PlatformGenerator::generateNextPlatform(AssetManager &assetManager, std::list<Platform> &platforms)
{
    Platform newPlatform(assetManager);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> heightDistrubution(minPlatformHight, maxPlatformHeight);
    std::uniform_int_distribution<> isSmallDistrubution(0, 1);

    const int platformHight = heightDistrubution(gen);

    newPlatform.getSprite()
        .setPosition({constants::WINDOW_WIDTH, static_cast<float>(platformHight)});

    const int isSmall = isSmallDistrubution(gen);
    if (isSmall)
    {
        newPlatform.setSize(Platform::Size::SMALL);
    }

    platforms.push_back(newPlatform);
}

bool PlatformGenerator::shouldGenerateNextPlatform(std::list<Platform> platforms)
{
    if (platforms.size() == 0)
    {
        return true;
    }
    Platform lastPlatform = platforms.back();

    return constants::WINDOW_WIDTH - (lastPlatform.getSprite().getGlobalBounds().position.x +
                                      lastPlatform.getSprite().getGlobalBounds().size.x) >
           distanceToNextPlatform;
}

std::list<Platform> PlatformGenerator::initPlatforms(AssetManager &assetManager)
{
    std::list<Platform> platforms;

    Platform landingPlatform(assetManager);
    landingPlatform.getSprite()
        .setPosition({200, 600});
    landingPlatform.setSize(Platform::Size::BIG);

    Platform starterPlatform(assetManager);
    starterPlatform.getSprite().setPosition({700, 500});
    starterPlatform.setSize(Platform::Size::BIG);

    platforms.push_back(landingPlatform);
    platforms.push_back(starterPlatform);

    return platforms;
}

void PlatformGenerator::generateDistanceToNextPlatform()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrubution(minDistanceToNextPlatform, maxDistanceToNextPlatform);

    distanceToNextPlatform = distrubution(gen);
}
