#include "AssetManager.hpp"
#include <iostream>

AssetManager::AssetManager()
{
    currentTheme = AssetManager::Theme::FOREST;
    this->loadTextures();
}

void AssetManager::loadTextures()
{
    if (!font.openFromFile("assets/fonts/arial.ttf"))
    {
        std::cout << "Error loading font." << std::endl;
    }
    if (!backgroundTexture.loadFromFile(this->THEME_TO_BACKGROUND_PATH_MAP.at(currentTheme)))
    {
        std::cout << "Error loading background texture." << std::endl;
    }
    if (!accelerateInstructionTexture.loadFromFile("assets/textures/instructions/keyboard_arrow_down_outline.png"))
    {
        std::cout << "Error loading accelerate instruction texture." << std::endl;
    }
    if (!moveInstructionTexture.loadFromFile("assets/textures/instructions/keyboard_arrow_right_outline.png"))
    {
        std::cout << "Error loading move instruction texture." << std::endl;
    }
    if (!platformTexture.loadFromFile("assets/textures/platforms/ground_grass.png"))
    {
        std::cout << "Error loading ground grass texture;" << std::endl;
    }
    if (!platformSmallTexture.loadFromFile("assets/textures/platforms/ground_grass_small.png"))
    {
        std::cout << "Error loading ground grass small texture;" << std::endl;
    }
    if (!platformBrokenTexture.loadFromFile("assets/textures/platforms/ground_grass_broken.png"))
    {
        std::cout << "Error loading ground grass broken texture;" << std::endl;
    }
    if (!platformSmallBrokenTexture.loadFromFile("assets/textures/platforms/ground_grass_small_broken.png"))
    {
        std::cout << "Error loading ground grass small and broken texture;" << std::endl;
    }
    if (!buttonTexture.loadFromFile("assets/textures/buttons/woodenTile.png"))
    {
        std::cout << "Error loading button texture;" << std::endl;
    }
    if (!ballTexture.loadFromFile("assets/textures/character/red_body_circle.png"))
    {
        std::cout << "Error loading ground ball texture;" << std::endl;
    }
    if (!faceTexture.loadFromFile("assets/textures/character/face_a.png"))
    {
        std::cout << "Error loading face texture;" << std::endl;
    }
}
void AssetManager::randomlyUpdateTheme()
{
    currentTheme = AssetManager::Theme(rand() % 4);
}
const std::map<AssetManager::Theme, std::string> AssetManager::THEME_TO_BACKGROUND_PATH_MAP = {
    {AssetManager::Theme::FOREST, "assets/textures/backgrounds/backgroundColorForest.png"},
    {AssetManager::Theme::GRASS, "assets/textures/backgrounds/backgroundColorGrass.png"},
    {AssetManager::Theme::FALL, "assets/textures/backgrounds/backgroundColorFall.png"},
    {AssetManager::Theme::DESERT, "assets/textures/backgrounds/backgroundColorDesert.png"},
};

sf::Font &AssetManager::getFont()
{
    return this->font;
}

sf::Texture &AssetManager::getBackgroundTexture()
{
    return this->backgroundTexture;
}

sf::Texture &AssetManager::getPlatformTexture()
{
    return this->platformTexture;
}

sf::Texture &AssetManager::getPlatformSmallTexture()
{
    return this->platformSmallTexture;
}

sf::Texture &AssetManager::getPlatformBrokenTexture()
{
    return this->platformBrokenTexture;
}

sf::Texture &AssetManager::getPlatformSmallBrokenTexture()
{
    return this->platformSmallBrokenTexture;
}

sf::Texture &AssetManager::getBallTexture()
{
    return this->ballTexture;
}

sf::Texture &AssetManager::getFaceTexture()
{
    return this->faceTexture;
}

sf::Texture &AssetManager::getButtonTexture()
{
    return this->buttonTexture;
}

sf::Texture &AssetManager::getAccelerateInstructionTexture()
{
    return this->accelerateInstructionTexture;
}

sf::Texture &AssetManager::getMoveInstructionTexture()
{
    return this->moveInstructionTexture;
}
