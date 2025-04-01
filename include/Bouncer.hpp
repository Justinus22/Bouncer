#ifndef B060A7F6_8C30_44E3_9398_49BFAE3DAD7F
#define B060A7F6_8C30_44E3_9398_49BFAE3DAD7F

#include <SFML/Graphics.hpp>
#include <AssetManager.hpp>

/// @brief "player" object aka. "Bouncer" with all releveant data
class Bouncer
{
public:
    Bouncer(AssetManager &assetManager);
    /// @brief
    /// @param window where the bouncer should be renderd
    void render(sf::RenderWindow &window);
    /// @brief update data of bouncer
    /// @param dt time difference from last frame to this from dt
    void update(sf::Time dt);
    /// @brief if an intersection with a platform is present this overwrites the state so that the ball bounces
    /// @param intersection with a platform
    /// @param dt time difference from last frame to this from dt
    void updateAccordingToIntersection(sf::FloatRect intersection, sf::Time dt);
    /// @brief  bounds object with position and size
    /// @return bounds object with position and size
    sf::FloatRect getGlobalBounds();
    /// @brief add downward acceleration
    void addExtraAcceleration();

    /// @brief fix horizontal position of bouncer
    const static int BOUNCER_HORIZONTAL_POSITION = 400;
    /// @brief default downward acceleration e.g. "gravity"
    constexpr static float DOWNWARD_ACCELERATION = 30.0f;
    /// @brief factor by which speed is reduced on every bounce
    constexpr static float BOUNCE_FRICTION_SPEED_REDUCTION_FACTOR = 0.1f;

private:
    sf::Sprite ballSprite;
    sf::Sprite faceSprite;

    sf::Vector2f position;
    float speed;
    float acceleration;

    float extraacceleration;

    void updatePosition(sf::Time dt);
    void updateSpeed();
    void updateAcceleration();
};

#endif /* B060A7F6_8C30_44E3_9398_49BFAE3DAD7F */
