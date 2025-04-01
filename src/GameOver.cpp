#include "GameOver.hpp"
#include <iostream>
#include "AssetManager.hpp"

GameOver::GameOver(AssetManager &assetManager, int score, float backgroundSplitXPosition) : continueButton(assetManager, {512, 500}, {150, 50}, "Continue"),
                                                                                            backgroundSpriteLeft(assetManager.getBackgroundTexture()),
                                                                                            backgroundSpriteRight(assetManager.getBackgroundTexture()),
                                                                                            gameOverText(assetManager.getFont(), "Game Over!"),
                                                                                            scoreText(assetManager.getFont(), "Score: " + std::to_string(score))
{
    backgroundSpriteLeft.setPosition({backgroundSplitXPosition - backgroundSpriteLeft.getTexture().getSize().x, 0});
    backgroundSpriteRight.setPosition({backgroundSplitXPosition, 0});

    gameOverText.setFillColor(sf::Color::Black);
    gameOverText.setCharacterSize(80);
    gameOverText.setPosition({300, 200});

    scoreText.setFillColor(sf::Color::Black);
    scoreText.setCharacterSize(50);
    scoreText.setPosition({410, 350});

    this->action = Action::None;
}

void GameOver::update(sf::Time dt)
{
}
void GameOver::render(sf::RenderWindow &window)
{
    window.draw(backgroundSpriteLeft);
    window.draw(backgroundSpriteRight);
    window.draw(gameOverText);
    window.draw(scoreText);
    continueButton.draw(window);
}

void GameOver::handleEvents(sf::RenderWindow &window)
{
    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }
        else if (const auto *mousePressed = event->getIf<sf::Event::MouseButtonPressed>())
        {

            if (mousePressed->button == sf::Mouse::Button::Left)
            {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (this->continueButton.isClicked(mousePos))
                {
                    this->setAction(GameOver::Action::Continue);
                }
            }
        }
    }
}

GameOver::Action GameOver::getAction() const
{
    return action;
}

void GameOver::setAction(Action newAction)
{
    this->action = newAction;
}

void handleEvents(sf::RenderWindow &window)
{
}