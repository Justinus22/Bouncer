#ifndef A3A0921D_BC32_4C57_8A3F_90E8FE8FD7E3
#define A3A0921D_BC32_4C57_8A3F_90E8FE8FD7E3

#include <SFML/Graphics.hpp>

/// @brief abstract class for a scene that can be displayed
class Scene
{
public:
    virtual ~Scene() = 0;
    virtual void update(sf::Time dt) = 0;
    virtual void render(sf::RenderWindow &window) = 0;
    virtual void handleEvents(sf::RenderWindow &window) = 0;
};

#endif /* A3A0921D_BC32_4C57_8A3F_90E8FE8FD7E3 */
