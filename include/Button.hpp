#ifndef B96FF55E_9A87_4AD2_83E6_D7D5C8D08D2A
#define B96FF55E_9A87_4AD2_83E6_D7D5C8D08D2A
#include <SFML/Graphics.hpp>
#include <string>
#include "AssetManager.hpp"

/// @brief basic button template
class Button
{
public:
    Button(AssetManager &assetManager, const sf::Vector2f &position, const sf::Vector2f &size, const std::string &text);
    /// @brief render the button to screen
    /// @param window where to button should be rendered
    void draw(sf::RenderWindow &window);
    /// @brief calc. where the mouse clicked the button or not
    /// @param mousePos position of the mouse
    /// @return where the mousePos hit the button or not
    bool isClicked(const sf::Vector2f &mousePos) const;

private:
    /// @brief holds background of button
    sf::Sprite sprite;
    /// @brief text that the button should display
    sf::Text text;
};

#endif /* B96FF55E_9A87_4AD2_83E6_D7D5C8D08D2A */
