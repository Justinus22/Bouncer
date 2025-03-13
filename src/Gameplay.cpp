#include "Gameplay.hpp"
#include <iostream>
#include "PlatformGenerator.hpp"

Gameplay::Gameplay() : platformGenerator(platformTexture, platformSmallTexture)
{
    backgroundTexture.loadFromFile("assets/textures/backgrounds/backgroundColorForest.png");
    backgroundSprites.push_back(sf::Sprite(backgroundTexture));

    platformTexture.loadFromFile("assets/textures/platforms/ground_grass.png");
    platformSmallTexture.loadFromFile("assets/textures/platforms/ground_grass_small.png");

    platformGenerator = PlatformGenerator(platformTexture, platformSmallTexture);
    platformGenerator.initPlatforms(platforms);
}

void Gameplay::update(sf::Time dt)
{
    updateStateByActionsQueue(dt);
    if (platformGenerator.shouldGenerateNextPlatform(platforms))
    {
        platformGenerator.generateNextPlatform(platforms);
    }
    addNewBackgroundIfNeeded();
    removeUnseenSprites();
}

void Gameplay::render(sf::RenderWindow &window)
{
    for (sf::Sprite backgroundSprite : backgroundSprites)
    {
        window.draw(backgroundSprite);
    }
    for (sf::Sprite platform : platforms)
    {
        window.draw(platform);
    }
}

void Gameplay::handleEvents(sf::RenderWindow &window)
{
    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }
        else if (const sf::Event::KeyPressed *keyPressed = event->getIf<sf::Event::KeyPressed>())
        {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Right)
                gameActions.push(Gameplay::Action::MOVE_RIGHT);
        }
    }
}

void Gameplay::removeUnseenSprites()
{
    removeUnseenBackground();
    removeUnseenPlatforms();
}

void Gameplay::removeUnseenPlatforms()
{
    auto i = platforms.begin();
    while (i != platforms.end())
    {
        if (i->getGlobalBounds().position.x + i->getGlobalBounds().size.x < 0)
        {
            {
                i = backgroundSprites.erase(i);
                continue;
            }
        }
        i++;
    }
}

void Gameplay::removeUnseenBackground()
{
    auto i = backgroundSprites.begin();
    while (i != backgroundSprites.end())
    {
        if (i->getGlobalBounds().position.x + i->getGlobalBounds().size.x < 0)
        {
            {
                i = backgroundSprites.erase(i);
                continue;
            }
        }
        i++;
    }
}

void Gameplay::addNewBackgroundIfNeeded()
{
    const float backPosX = backgroundSprites.back().getGlobalBounds().position.x + backgroundSprites.back().getGlobalBounds().size.x;
    if (backPosX < 1200)
    {
        backgroundSprites.push_back(sf::Sprite(backgroundTexture));
        backgroundSprites.back().setPosition({backPosX, 0});
    }
}

void Gameplay::updateStateByActionsQueue(sf::Time dt)
{
    while (!gameActions.empty())
    {
        Gameplay::Action action = gameActions.front();
        gameActions.pop();
        switch (action)
        {
        case Gameplay::Action::MOVE_RIGHT:
            moveSceneToRight(dt);
            break;
        default:
            break;
        }
    }
}

void Gameplay::moveSceneToRight(sf::Time dt)
{
    for (sf::Sprite &backgroundSprite : backgroundSprites)
    {
        backgroundSprite.setPosition({backgroundSprite.getPosition().x - BACKGROUND_PX_MOVE_PER_SEC * dt.asSeconds(), 0});
    }
    for (sf::Sprite &platform : platforms)
    {
        platform.setPosition({platform.getPosition().x - PLATFORM_PX_MOVE_PER_SEC * dt.asSeconds(), platform.getPosition().y});
    }
}
