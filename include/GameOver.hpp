#ifndef B6E48D8E_BDBA_4702_9186_2E70DD14AD59
#define B6E48D8E_BDBA_4702_9186_2E70DD14AD59

#include "Scene.hpp"
#include "Button.hpp"
#include <SFML/Graphics.hpp>

/// @brief gameover scene displaying score
class GameOver : public Scene
{
public:
    GameOver(AssetManager &assetManager, int score, float backgroundSplitXPosition);
    void update(sf::Time dt) override;
    void handleEvents(sf::RenderWindow &window) override;
    void render(sf::RenderWindow &window) override;
    enum class Action
    {
        Continue,
        None
    };
    Action getAction() const;
    void setAction(Action newAction);

private:
    sf::Text gameOverText;
    sf::Text scoreText;
    sf::Sprite backgroundSpriteLeft;
    sf::Sprite backgroundSpriteRight;

    Button continueButton;

    Action action;
};

#endif /* B6E48D8E_BDBA_4702_9186_2E70DD14AD59 */
