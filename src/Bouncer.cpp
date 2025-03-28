#include "Bouncer.hpp"
#include <iostream>

Bouncer::Bouncer() : ballSprite(ballTexture),
                     faceSprite(faceTexture)
{
    ballTexture.loadFromFile("assets/textures/character/red_body_circle.png");
    faceTexture.loadFromFile("assets/textures/character/face_a.png");
    faceSquishedTexture.loadFromFile("assets/textures/character/face_c.png");

    ballSprite = sf::Sprite(ballTexture);
    faceSprite = sf::Sprite(faceTexture);

    position = sf::Vector2f({BOUNCER_HORIZONTAL_POSITION, 200});
    speed = 0;
    acceleration = 0;
}

void Bouncer::render(sf::RenderWindow &window)
{

    // position sprites such that position is at the bottom center of the texture (-> contact point to platforms)
    sf::Vector2f sizeBall = ballSprite.getGlobalBounds().size;
    ballSprite.setPosition({position.x - sizeBall.x / 2, position.y});
    ballSprite.setScale({1, 1});

    sf::Vector2f sizeFace = faceSprite.getGlobalBounds().size;
    faceSprite.setPosition({position.x - sizeFace.x / 2, position.y + sizeBall.y / 2 - sizeFace.y / 2});

    window.draw(ballSprite);
    window.draw(faceSprite);
}

void Bouncer::update(sf::Time dt)
{
    updateAcceleration();
    updateSpeed();
    updatePosition(dt);

    extraacceleration = 0;
}

void Bouncer::updateAccordingToIntersection(sf::FloatRect intersection, sf::Time dt)
{
    if (intersection.size.y > 0)
    {
        // prevent position from cliping into the platform
        position = {position.x, intersection.position.y + speed * dt.asSeconds()};

        // reverse speed vector for bouncing and apply bounce friction
        speed *= -(1 - BOUNCE_FRICTION_SPEED_REDUCTION_FACTOR);
    }
}

sf::FloatRect Bouncer::getGlobalBounds()
{
    return ballSprite.getGlobalBounds();
}

void Bouncer::updatePosition(sf::Time dt)
{
    position = {position.x,
                position.y - speed * dt.asSeconds()};
}

void Bouncer::updateSpeed()
{
    speed -= acceleration;
}

void Bouncer::updateAcceleration()
{
    acceleration = DOWNWARD_ACCELERATION + extraacceleration;
}

void Bouncer::addExtraAcceleration()
{
    extraacceleration = DOWNWARD_ACCELERATION;
}
