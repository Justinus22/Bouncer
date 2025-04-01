#include "GameState.hpp"
#include "MainMenu.hpp"
#include <iostream>
#include "Gameplay.hpp"
#include "GameOver.hpp"

GameState::GameState() : assetManager(), currentScene(std::make_shared<MainMenu>(assetManager))
{
}

void GameState::setScene(std::shared_ptr<Scene> newScene)
{
    currentScene = newScene;
}

void GameState::update(sf::Time dt)
{
    if (currentScene)
    {
        currentScene->update(dt);
        if (std::shared_ptr<MainMenu> mainMenu = std::dynamic_pointer_cast<MainMenu>(currentScene))
        {
            handleMainMenuAction(mainMenu->getAction());
        }
        if (std::shared_ptr<GameOver> gameOver = std::dynamic_pointer_cast<GameOver>(currentScene))
        {
            handleGameOverAction(gameOver->getAction());
        }
        if (std::shared_ptr<Gameplay> gameplay = std::dynamic_pointer_cast<Gameplay>(currentScene))
        {
            if (gameplay->isGameover())
            {
                setScene(std::make_shared<GameOver>(assetManager, gameplay->getScore(), gameplay->getBackgroundSplitXPosition()));
            }
        }
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
    if (currentScene)
    {
        currentScene->handleEvents(window);
    }
}

void GameState::handleMainMenuAction(MainMenu::Action action)
{
    switch (action)
    {
    case MainMenu::Action::Play:
        setScene(std::make_shared<Gameplay>(assetManager));
        break;
    default:
        break;
    }
}

void GameState::handleGameOverAction(GameOver::Action action)
{
    switch (action)
    {
    case GameOver::Action::Continue:
        setScene(std::make_shared<MainMenu>(assetManager));
        assetManager.randomlyUpdateTheme();
        assetManager.loadTextures();
        break;
    default:
        break;
    }
}

std::shared_ptr<Scene> GameState::getCurrentScene()
{
    return currentScene;
}