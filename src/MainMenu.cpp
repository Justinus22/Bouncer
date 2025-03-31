#include "MainMenu.hpp"
#include <iostream>

MainMenu::MainMenu(AssetManager &assetManager) : playButton(assetManager, {512, 500}, {110, 50}, "Play"),
                                                 exitButton(assetManager, {512, 600}, {110, 50}, "Exit"),
                                                 backgroundSprite(assetManager.getBackgroundTexture()),
                                                 accelerateInstructionSprite(assetManager.getAccelerateInstructionTexture()),
                                                 moveInstructionSprite(assetManager.getMoveInstructionTexture()),
                                                 title(assetManager.getFont(), "Bouncer"),
                                                 accelerateInstructionText(assetManager.getFont(), "accelerate down"),
                                                 moveInstructionText(assetManager.getFont(), "move right")

{

    accelerateInstructionSprite.setPosition({140, 680});

    moveInstructionSprite.setPosition({885, 680});

    title.setFillColor(sf::Color::Black);
    title.setCharacterSize(80);
    title.setPosition({365, 200});

    accelerateInstructionText.setFillColor(sf::Color::White);
    accelerateInstructionText.setCharacterSize(20);
    accelerateInstructionText.setPosition({100, 750});

    moveInstructionText.setFillColor(sf::Color::White);
    moveInstructionText.setCharacterSize(20);
    moveInstructionText.setPosition({870, 750});

    this->action = Action::None;
}

void MainMenu::update(sf::Time dt)
{
}

void MainMenu::render(sf::RenderWindow &window)
{
    window.draw(backgroundSprite);
    window.draw(title);
    window.draw(moveInstructionText);
    window.draw(accelerateInstructionText);
    window.draw(moveInstructionSprite);
    window.draw(accelerateInstructionSprite);
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