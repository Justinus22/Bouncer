#ifndef B7D363E8_A6EA_4B79_837A_9982B96EEE79
#define B7D363E8_A6EA_4B79_837A_9982B96EEE79
#include "Scene.hpp"
#include "Button.hpp"
#include <SFML/Graphics.hpp>
#include <queue>
#include <list>
#include "PlatformGenerator.hpp"
#include "Bouncer.hpp"
#include "Platform.hpp"
#include <tuple>
#include <optional>
#include "AssetManager.hpp"

/// @brief gameplay scene itself with a bouncer and backgrounds
class Gameplay : public Scene
{
public:
    Gameplay(AssetManager &assetManager);
    ~Gameplay();
    void update(sf::Time dt) override;
    void render(sf::RenderWindow &window) override;
    void handleEvents(sf::RenderWindow &window) override;

    enum class Action
    {
        MOVE_RIGHT,
        MOVE_DOWN
    };

    bool isGameover();
    int getScore();
    float getBackgroundSplitXPosition();

    std::queue<Action> &getGameActionQueue();

private:
    void removeUnseenSprites();
    void removeUnseenPlatforms();
    void removeUnseenBackground();
    void addNewBackgroundIfNeeded();
    /// @brief work through the actions queue and handle all actions from that queue and update state list the position of all the sprites accordingly
    /// @param dt for fps independet movment
    void updateStateByActionsQueue(sf::Time dt);
    void moveSceneToRight(sf::Time dt);
    /// @brief calculates where the ball needs to bounce or not and removes lifes from platforms
    /// @return wether there is an intersection with platform beaneth the bouncer
    std::optional<std::tuple<sf::FloatRect, Platform *>> getBouncerIntersectionWithPlatformBelow();
    void increaseScore();

    AssetManager &assetManager;

    std::list<sf::Sprite> backgroundSprites;
    sf::Font font;
    sf::Text scoreText;

    const float BACKGROUND_PX_MOVE_PER_SEC = 200.0f;
    float PLATFORM_PX_MOVE_PER_SEC = 600.0f;

    std::queue<Action>
        gameActions;

    std::list<Platform> platforms;

    PlatformGenerator platformGenerator;

    Bouncer bouncer;

    int score;

    bool gameover;
};

#endif /* B7D363E8_A6EA_4B79_837A_9982B96EEE79 */
