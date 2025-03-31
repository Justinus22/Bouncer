#ifndef C5A3A3AE_51C7_42D6_8B16_AE07C038C32C
#define C5A3A3AE_51C7_42D6_8B16_AE07C038C32C
#include <SFML/Graphics.hpp>

class AssetManager
{
public:
    AssetManager();

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
};
#endif /* C5A3A3AE_51C7_42D6_8B16_AE07C038C32C */
