#ifndef B060A7F6_8C30_44E3_9398_49BFAE3DAD7F
#define B060A7F6_8C30_44E3_9398_49BFAE3DAD7F

#include <SFML/Graphics.hpp>

class Bouncer
{
public:
    Bouncer();
    void render(sf::RenderWindow &window);
    void update(sf::Time dt);
    void updateAccordingToIntersection(sf::FloatRect intersection, sf::Time dt);
    sf::FloatRect getGlobalBounds();
    void addExtraAcceleration();

    const static int BOUNCER_HORIZONTAL_POSITION = 400;
    constexpr static float DOWNWARD_ACCELERATION = 30.0f;
    constexpr static float BOUNCE_FRICTION_SPEED_REDUCTION_FACTOR = 0.1f;

private:
    sf::Texture ballTexture;
    sf::Sprite ballSprite;

    sf::Texture faceTexture;
    sf::Texture faceSquishedTexture;
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
