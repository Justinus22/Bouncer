#ifndef F99B2B25_00DC_49C1_AFC0_8206FC561409
#define F99B2B25_00DC_49C1_AFC0_8206FC561409

#include <SFML/Graphics.hpp>
#include "AssetManager.hpp"

class Platform
{
public:
    Platform(AssetManager &assetManager);
    Platform(const Platform &platform);
    sf::Sprite &getSprite();
    void setSprite(sf::Sprite sprite);
    /// @brief removes one life from the platform and updates texture if neccesarray
    void removeHealth();
    bool hasHealthLeft();
    void render(sf::RenderWindow &window);

    enum class Size
    {
        SMALL,
        BIG
    };
    Size getSize();
    void setSize(Size size);
    Size size;

    const static int MAX_LIFE = 5;

    bool operator==(const Platform &otherPlatform) const;
    bool operator!=(const Platform &otherPlatform) const;

private:
    /// @brief gernerate a new sprite because i cant change the texture of a sprite without render bugs, idk why
    /// @param lifes of platform
    /// @param size of platform
    /// @return new sprite
    sf::Sprite generateNewSpriteFromPlatformData(sf::Vector2f pos, int lifes, Size size);

    AssetManager &assetManager;

    sf::Sprite sprite;

    int lifes = MAX_LIFE;
};

#endif /* F99B2B25_00DC_49C1_AFC0_8206FC561409 */
