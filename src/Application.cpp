#include <iostream>
#include "Application.hpp"
#include "constants.hpp"

Application::Application()
{
    window = sf::RenderWindow(sf::VideoMode({constants::WINDOW_WIDTH, constants::WINDOW_HEIGHT}), "Bouncer", sf::State::Windowed);
    window.setFramerateLimit(60);
}

Application::Application(const Application &app)
{
}

Application::~Application()
{
}

void Application::handleEvents()
{
    gameState.handleEvents(window);
}

void Application::update(sf::Time dt)
{
    gameState.update(dt);
}

void Application::render()
{
    window.clear();
    gameState.render(window);
    window.display();
}

int Application::run()
{
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Time dt = clock.restart();
        handleEvents();
        update(dt);
        render();
    }
    return 0;
}