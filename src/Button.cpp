#include "Button.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <AssetManager.hpp>

Button::Button(AssetManager &assetManager, const sf::Vector2f &position, const sf::Vector2f &size, const std::string &textString)
    : sprite(assetManager.getButtonTexture()),
      text(assetManager.getFont(), textString, 24)
{

    sf::Vector2f factors({size.x / assetManager.getButtonTexture().getSize().x, size.y / assetManager.getButtonTexture().getSize().y});
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