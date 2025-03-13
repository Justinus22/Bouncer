#ifndef FB6967CE_5AC5_4CD0_873C_8CA277C9FC64
#define FB6967CE_5AC5_4CD0_873C_8CA277C9FC64
#include "Scene.hpp"
#include "Button.hpp"
#include <SFML/Graphics.hpp>

class MainMenu : public Scene
{
public:
    MainMenu();
    void update(sf::Time dt) override;
    void handleEvents(sf::RenderWindow &window) override;
    void render(sf::RenderWindow &window) override;
    enum class Action
    {
        None,
        Play,
        Exit
    };
    Action getAction() const;
    void setAction(Action newAction);

    Button getPlayButton();
    Button getExitButton();

private:
    sf::Font font;
    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;
    sf::Text title;

    Button playButton;
    Button exitButton;

    Action action;
};

#endif /* FB6967CE_5AC5_4CD0_873C_8CA277C9FC64 */
