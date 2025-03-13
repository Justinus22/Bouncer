#include <SFML/Graphics.hpp>
#include <memory>
#include "Scene.hpp"
#include "MainMenu.hpp"

class GameState
{
public:
    GameState();
    void setScene(std::shared_ptr<Scene> newScene);
    void update(sf::Time dt);
    void render(sf::RenderWindow &window);
    void handleEvents(sf::RenderWindow &window);
    void handleMainMenuAction(MainMenu::Action action);
    std::shared_ptr<Scene> getCurrentScene();

private:
    std::shared_ptr<Scene> currentScene;
};
