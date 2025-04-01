#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics.hpp>
#include "GameState.hpp"

/// @brief main application that handles the game loop
class Application
{
public:
    Application();
    Application(const Application &app);
    ~Application();

    int run();

private:
    /// @brief handle user input and other events
    void handleEvents();
    /// @brief update state of the game
    /// @param dt time difference from last frame to this from
    void update(sf::Time dt);
    /// @brief render according to game state
    void render();

    /// @brief where the application is rendered to
    sf::RenderWindow window;

    /// @brief holds all data regarding game state including the current scene
    GameState gameState;
};

#endif // APPLICATION_HPP