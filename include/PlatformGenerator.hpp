#ifndef CCDCCF22_AA20_41F3_A8EB_38C282058FD3
#define CCDCCF22_AA20_41F3_A8EB_38C282058FD3
#include <SFML/Graphics.hpp>
#include <list>

class PlatformGenerator
{
public:
    PlatformGenerator(sf::Texture platformTexture, sf::Texture smallPlatformTexture);
    void generateNextPlatform(std::list<sf::Sprite> &platforms);
    bool shouldGenerateNextPlatform(std::list<sf::Sprite> platforms);
    void initPlatforms(std::list<sf::Sprite> &platforms);

private:
    float distanceToNextPlatform = 100;
    sf::Texture platformTexture;
    sf::Texture smallPlatformTexture;
};

#endif /* CCDCCF22_AA20_41F3_A8EB_38C282058FD3 */
