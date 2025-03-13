#include "Button.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

Button::Button(const sf::Vector2f &position, const sf::Vector2f &size, const sf::Font &font, const std::string &textString)
    : sprite(texture),
      text(font, textString, 24)
{
    texture.loadFromFile("assets/textures/buttons/woodenTile.png");
    sprite = sf::Sprite(texture);

    sf::Vector2f factors({size.x / texture.getSize().x, size.y / texture.getSize().y});
    sprite.setScale(factors);
    sf::Vector2f spritePos({position.x - size.x / 2, position.y - size.y / 2});
    sprite.setPosition(spritePos);

    sf::Vector2f textureOffset({30, 10});
    text.setFillColor(sf::Color::White);
    text.setPosition(spritePos + textureOffset);
}

void Button::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
    window.draw(text);
}

bool Button::isClicked(const sf::Vector2f &mousePos) const
{
    return sprite.getGlobalBounds().contains(mousePos);
}