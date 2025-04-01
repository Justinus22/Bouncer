#ifndef B96FF55E_9A87_4AD2_83E6_D7D5C8D08D2A
#define B96FF55E_9A87_4AD2_83E6_D7D5C8D08D2A
#include <SFML/Graphics.hpp>
#include <string>
#include "AssetManager.hpp"

class Button
{
public:
    Button(AssetManager &assetManager, const sf::Vector2f &position, const sf::Vector2f &size, const std::string &text);
    /// @brief
    /// @param window
    void draw(sf::RenderWindow &window);
    bool isClicked(const sf::Vector2f &mousePos) const;

private:
    sf::Sprite sprite;
    sf::Text text;
};

#endif /* B96FF55E_9A87_4AD2_83E6_D7D5C8D08D2A */
