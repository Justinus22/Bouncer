#include "MainMenu.hpp"
#include <iostream>

MainMenu::MainMenu() : playButton({512, 500}, {110, 50}, font, "Play"),
                       exitButton({512, 600}, {110, 50}, font, "Exit"),
                       action(Action::None),
                       backgroundSprite(backgroundTexture),
                       accelerateInstructionSprite(accelerateInstructionTexture),
                       moveInstructionSprite(moveInstructionTexture),
                       title(font, "Bouncer"),
                       accelerateInstructionText(font, "accelerate down"),
                       moveInstructionText(font, "move right")

{
    if (!font.openFromFile("assets/fonts/arial.ttf"))
    {
        std::cout << "Error loading font" << std::endl;
    }
    if (!backgroundTexture.loadFromFile("assets/textures/backgrounds/backgroundColorForest.png"))
    {
        std::cout << "Error loading background texture." << std::endl;
    }
    if (!accelerateInstructionTexture.loadFromFile("assets/textures/instructions/keyboard_arrow_down_outline.png"))
    {
        std::cout << "Error loading accelerate instruction texture." << std::endl;
    }
    if (!moveInstructionTexture.loadFromFile("assets/textures/instructions/keyboard_arrow_right_outline.png"))
    {
        std::cout << "Error loading move instruction texture." << std::endl;
    }

    backgroundSprite = sf::Sprite(backgroundTexture);

    accelerateInstructionSprite = sf::Sprite(accelerateInstructionTexture);
    accelerateInstructionSprite.setPosition({140, 680});

    moveInstructionSprite = sf::Sprite(moveInstructionTexture);
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
}

void MainMenu::update(sf::Time dt)
{
    action = Action::None;
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