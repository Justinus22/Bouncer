#include "GameOver.hpp"

GameOver::GameOver(int score) : continueButton({512, 500}, {150, 50}, font, "Continue"),
                                action(Action::NONE),
                                backgroundSprite(backgroundTexture),
                                gameOverText(font, "Game Over!"),
                                scoreText(font, "Score: " + std::to_string(score))
{
    font.openFromFile("assets/fonts/arial.ttf");
    backgroundTexture.loadFromFile("assets/textures/backgrounds/backgroundColorForest.png");

    backgroundSprite = sf::Sprite(backgroundTexture);

    gameOverText.setFillColor(sf::Color::Black);
    gameOverText.setCharacterSize(80);
    gameOverText.setPosition({300, 200});

    scoreText.setFillColor(sf::Color::Black);
    scoreText.setCharacterSize(50);
    scoreText.setPosition({410, 350});
}

void GameOver::update(sf::Time dt)
{
    action = Action::NONE;
}

void GameOver::render(sf::RenderWindow &window)
{
    window.draw(backgroundSprite);
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
                    this->setAction(GameOver::Action::CONTINUE);
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