#ifndef CCDCCF22_AA20_41F3_A8EB_38C282058FD3
#define CCDCCF22_AA20_41F3_A8EB_38C282058FD3
#include <SFML/Graphics.hpp>
#include <list>
#include "Platform.hpp"
#include "AssetManager.hpp"

class PlatformGenerator
{
public:
    void generateNextPlatform(AssetManager &assetManager, std::list<Platform> &platforms);
    bool shouldGenerateNextPlatform(std::list<Platform> platforms);
    std::list<Platform> initPlatforms(AssetManager &assetManager);
    void generateDistanceToNextPlatform();

private:
    float maxDistanceToNextPlatform = 500;
    float minDistanceToNextPlatform = 150;
    float maxPlatformHeight = 500;
    float minPlatformHight = 100;

    float distanceToNextPlatform;
};

#endif /* CCDCCF22_AA20_41F3_A8EB_38C282058FD3 */
