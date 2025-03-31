#include <SFML/Graphics.hpp>
#include <memory>
#include "Scene.hpp"
#include "MainMenu.hpp"
#include "GameOver.hpp"

class GameState
{
public:
    GameState();
    void setScene(std::shared_ptr<Scene> newScene);
    void update(sf::Time dt);
    void render(sf::RenderWindow &window);
    void handleEvents(sf::RenderWindow &window);
    std::shared_ptr<Scene> getCurrentScene();

    void handleMainMenuAction(MainMenu::Action action);
    void handleGameOverAction(GameOver::Action action);

private:
    AssetManager assetManager;

    std::shared_ptr<Scene> currentScene;
};
