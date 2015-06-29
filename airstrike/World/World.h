
#ifndef __WORLD_H__
#define __WORLD_H__

#include "Aircraft/Aircraft.h"
#include <SpriteNode/SpriteNode.h>

class AWorld : private sf::NonCopyable {
public:
    explicit    AWorld( sf::RenderWindow& window );
    void        Update( const sf::Time& dt );
    void        Draw();

private:
    enum Layer_t {
        Background,
        Air,
        LayerCount,
    };

    sf::RenderWindow&                   window;
    sf::View                            world_view;
    ATextureHolder_t                    textures;
    ASceneNode                          scene_graph;
    std::array<ASceneNode*, LayerCount> scene_layers;

    sf::FloatRect                       world_bounds;
    sf::Vector2f                        spawn_position;
    float                               scroll_speed;
    AnAircraft*                         player_aircraft;

    void LoadTextures();
    void BuildScene();
    bool IsPositionAtBounds( const sf::Vector2f& pos );
};

#endif
