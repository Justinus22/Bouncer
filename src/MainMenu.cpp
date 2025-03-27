#include "MainMenu.hpp"
#include <iostream>

MainMenu::MainMenu() : playButton({512, 500}, {110, 50}, font, "Play"),
                       exitButton({512, 600}, {110, 50}, font, "Exit"),
                       action(Action::None),
                       backgroundSprite(backgroundTexture),
                       title(font, "Bouncer")
{
    font.openFromFile("assets/fonts/arial.ttf");
    backgroundTexture.loadFromFile("assets/textures/backgrounds/backgroundColorForest.png");

    backgroundSprite = sf::Sprite(backgroundTexture);

    title.setFillColor(sf::Color::Black);
    title.setCharacterSize(80);
    title.setPosition({365, 200});
}

void MainMenu::update(sf::Time dt)
{
    action = Action::None;
}

void MainMenu::render(sf::RenderWindow &window)
{
    window.draw(backgroundSprite);
    window.draw(title);
    playButton.draw(window);
    exitButton.draw(window);
}

void MainMenu::handleEvents(sf::RenderWindow &window)
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
                if (this->getPlayButton().isClicked(mousePos))
                {
                    this->setAction(MainMenu::Action::Play);
                }
                else if (this->getExitButton().isClicked(mousePos))
                {
                    this->setAction(MainMenu::Action::Exit);
                    window.close();
                }
            }
        }
    }
}

MainMenu::Action MainMenu::getAction() const
{
    return action;
}

void MainMenu::setAction(Action newAction)
{
    this->action = newAction;
}

Button MainMenu::getPlayButton()
{
    return this->playButton;
}

Button MainMenu::getExitButton()
{
    return this->exitButton;
}