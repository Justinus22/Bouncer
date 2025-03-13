#ifndef B7D363E8_A6EA_4B79_837A_9982B96EEE79
#define B7D363E8_A6EA_4B79_837A_9982B96EEE79
#include "Scene.hpp"
#include "Button.hpp"
#include <SFML/Graphics.hpp>
#include <queue>
#include <list>
#include "PlatformGenerator.hpp"

class Gameplay : public Scene
{
public:
    Gameplay();
    void update(sf::Time dt) override;
    void render(sf::RenderWindow &window) override;
    void handleEvents(sf::RenderWindow &window) override;

    enum class Action
    {
        MOVE_RIGHT
    };

    std::queue<Action> &getGameActionQueue();

private:
    void removeUnseenSprites();
    void removeUnseenPlatforms();
    void removeUnseenBackground();
    void addNewBackgroundIfNeeded();
    void updateStateByActionsQueue(sf::Time dt);
    void moveSceneToRight(sf::Time dt);

    std::list<sf::Sprite>
        backgroundSprites;
    sf::Texture backgroundTexture;
    const float BACKGROUND_PX_MOVE_PER_SEC = 100.0f;
    float PLATFORM_PX_MOVE_PER_SEC = 200.0f;

    std::queue<Action>
        gameActions;

    sf::Texture platformTexture;
    sf::Texture platformSmallTexture;
    std::list<sf::Sprite> platforms;

    PlatformGenerator platformGenerator;
};

#endif /* B7D363E8_A6EA_4B79_837A_9982B96EEE79 */
