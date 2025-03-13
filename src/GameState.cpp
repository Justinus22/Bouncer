#include "GameState.hpp"
#include "MainMenu.hpp"
#include <iostream>
#include <Gameplay.hpp>

GameState::GameState() : currentScene(std::make_shared<MainMenu>()) {}

void GameState::setScene(std::shared_ptr<Scene> newScene)
{
    currentScene = newScene;
}

void GameState::update(sf::Time dt)
{
    if (currentScene)
    {
        if (std::shared_ptr<MainMenu> mainMenu = std::dynamic_pointer_cast<MainMenu>(currentScene))
        {
            handleMainMenuAction(mainMenu->getAction());
        }
        currentScene->update(dt);
    }
}

void GameState::render(sf::RenderWindow &window)
{
    if (currentScene)
    {
        currentScene->render(window);
    }
}

void GameState::handleEvents(sf::RenderWindow &window)
{
    currentScene->handleEvents(window);
}

void GameState::handleMainMenuAction(MainMenu::Action action)
{

    switch (action)
    {
    case MainMenu::Action::Play:
        setScene(std::make_shared<Gameplay>());
        break;
    case MainMenu::Action::Exit:
        break;
    case MainMenu::Action::None:
    default:
        break;
    }
}

std::shared_ptr<Scene> GameState::getCurrentScene()
{
    return currentScene;
}