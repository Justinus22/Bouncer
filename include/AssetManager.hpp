#ifndef C5A3A3AE_51C7_42D6_8B16_AE07C038C32C
#define C5A3A3AE_51C7_42D6_8B16_AE07C038C32C
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

/// @brief centraly manage all assest and themes
class AssetManager
{
public:
    AssetManager();

    /// @brief load needed textures from disk
    void loadTextures();
    /// @brief update the current theme for the manager
    void randomlyUpdateTheme();

    sf::Font &getFont();

    sf::Texture &getBackgroundTexture();

    sf::Texture &getPlatformTexture();
    sf::Texture &getPlatformSmallTexture();
    sf::Texture &getPlatformBrokenTexture();
    sf::Texture &getPlatformSmallBrokenTexture();

    sf::Texture &getBallTexture();
    sf::Texture &getFaceTexture();

    sf::Texture &getButtonTexture();

    sf::Texture &getAccelerateInstructionTexture();
    sf::Texture &getMoveInstructionTexture();

private:
    sf::Font font;

    sf::Texture backgroundTexture;

    sf::Texture platformTexture;
    sf::Texture platformSmallTexture;
    sf::Texture platformBrokenTexture;
    sf::Texture platformSmallBrokenTexture;

    sf::Texture ballTexture;
    sf::Texture faceTexture;

    sf::Texture buttonTexture;

    sf::Texture accelerateInstructionTexture;
    sf::Texture moveInstructionTexture;

    /// @brief themes are the look and feel for a scene
    enum Theme
    {
        GRASS,
        FOREST,
        FALL,
        DESERT
    };

    /// @brief map the theme to the according path to the asset from that theme
    static const std::map<Theme, std::string> THEME_TO_BACKGROUND_PATH_MAP;

    /// @brief what theme is currently set
    Theme currentTheme;
};
#endif /* C5A3A3AE_51C7_42D6_8B16_AE07C038C32C */
