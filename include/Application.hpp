#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics.hpp>
#include "GameState.hpp"

class Application
{
public:
    Application();
    Application(const Application &app);
    ~Application();

    int run();

private:
    void handleEvents();
    void update(sf::Time dt);
    void render();

    sf::RenderWindow window;
    GameState gameState;
};

#endif // APPLICATION_HPP