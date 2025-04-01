#ifndef FB6967CE_5AC5_4CD0_873C_8CA277C9FC64
#define FB6967CE_5AC5_4CD0_873C_8CA277C9FC64
#include "Scene.hpp"
#include "Button.hpp"
#include <SFML/Graphics.hpp>

/// @brief main menu scene where you can start the game or exit it
class MainMenu : public Scene
{
public:
    MainMenu(AssetManager &assetManager);
    void update(sf::Time dt) override;
    void handleEvents(sf::RenderWindow &window) override;
    void render(sf::RenderWindow &window) override;
    enum class Action
    {
        Play,
        None
    };
    Action getAction() const;
    void setAction(Action newAction);

    Button getPlayButton();
    Button getExitButton();

private:
    sf::Text title;
    sf::Text accelerateInstructionText;
    sf::Text moveInstructionText;

    sf::Sprite accelerateInstructionSprite;
    sf::Sprite moveInstructionSprite;

    sf::Sprite backgroundSprite;

    Button playButton;
    Button exitButton;

    Action action;
};

#endif /* FB6967CE_5AC5_4CD0_873C_8CA277C9FC64 */
