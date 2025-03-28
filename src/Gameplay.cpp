#include "Gameplay.hpp"
#include <iostream>
#include "PlatformGenerator.hpp"
#include <tuple>
#include "constants.hpp"
#include <stdbool.h>

Gameplay::Gameplay() : scoreText(font)
{
    score = 0;

    if (!backgroundTexture.loadFromFile("assets/textures/backgrounds/backgroundColorForest.png"))
    {
        std::cout << "Error loading background texture in gameplay." << std::endl;
    }
    backgroundSprites.push_back(sf::Sprite(backgroundTexture));

    platformGenerator = PlatformGenerator();
    this->platforms = platformGenerator.initPlatforms();
    platformGenerator.generateDistanceToNextPlatform();

    if (!font.openFromFile("assets/fonts/arial.ttf"))
    {
        std::cout << "Error loading font" << std::endl;
    }

    scoreText.setFillColor(sf::Color::Black);
    scoreText.setCharacterSize(40);
    scoreText.setPosition({constants::WINDOW_WIDTH - 50, 20});
    scoreText.setString(std::to_string(score));
}

void Gameplay::update(sf::Time dt)
{

    this->updateStateByActionsQueue(dt);
    if (platformGenerator.shouldGenerateNextPlatform(platforms))
    {
        platformGenerator.generateNextPlatform(platforms);
        platformGenerator.generateDistanceToNextPlatform();
    }

    bouncer.update(dt);
    if (std::optional<std::tuple<sf::FloatRect, Platform>> intersectionData = this->getBouncerIntersectionWithPlatformBelow())
    {
        bouncer.updateAccordingToIntersection(std::get<sf::FloatRect>(*intersectionData), dt);
        Platform intersectedPlatform = std::get<Platform>(*intersectionData);
        intersectedPlatform.removeHealth();
        this->increaseScore();
    }

    if (bouncer.getGlobalBounds().position.y + bouncer.getGlobalBounds().size.y > constants::WINDOW_HEIGHT)
    {
        this->gameover = true;
    }

    this->addNewBackgroundIfNeeded();
    this->removeUnseenSprites();
}

void Gameplay::render(sf::RenderWindow &window)
{
    for (sf::Sprite backgroundSprite : backgroundSprites)
    {
        window.draw(backgroundSprite);
    }

    window.draw(scoreText);

    for (Platform platform : platforms)
    {
        platform.render(window);
    }

    bouncer.render(window);
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
            if (keyPressed->scancode == sf::Keyboard::Scancode::Down)
                gameActions.push(Gameplay::Action::MOVE_DOWN);
        }
    }
}

bool Gameplay::isGameover()
{
    return this->gameover;
}

int Gameplay::getScore()
{
    return this->score;
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
        if (i->getSprite().getGlobalBounds().position.x + i->getSprite().getGlobalBounds().size.x < 0)
        {
            {
                i = platforms.erase(i);
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
        case Gameplay::Action::MOVE_DOWN:
            bouncer.addExtraAcceleration();
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
    for (Platform &platform : platforms)
    {
        platform.getSprite().setPosition({platform.getSprite().getPosition().x - PLATFORM_PX_MOVE_PER_SEC * dt.asSeconds(), platform.getSprite().getPosition().y});
    }
}

std::optional<std::tuple<sf::FloatRect, Platform>> Gameplay::getBouncerIntersectionWithPlatformBelow()
{
    auto platformIterator = platforms.begin();
    while (platformIterator != platforms.end())
    {
        if (platformIterator->getSprite().getGlobalBounds().findIntersection(bouncer.getGlobalBounds()))
        {
            if (!platformIterator->removeHealth())
            {
                platformIterator = platforms.erase(platformIterator);
            }

            return std::tuple(bouncer.getGlobalBounds(), *platformIterator);
        }
        platformIterator++;
    }
    return {};
}

void Gameplay::increaseScore()
{
    score++;
    scoreText.setString(std::to_string(score));
}
