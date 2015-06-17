
#ifndef __GAME_H__
#define __GAME_H__

#include <SFML/Graphics.hpp>

class AGame {
public:
    AGame();

    void Run();

private:
    sf::RenderWindow    window;
    sf::Texture         texture;
    sf::Sprite          player;
    sf::Time            time_per_frame;
    bool                is_moving_up;
    bool                is_moving_down;
    bool                is_moving_left;
    bool                is_moving_right;
    float               player_speed;

    void                ProcessEvents();
    void                Update( const sf::Time& dt );
    void                Render();
    void                HandlePlayerInput( const sf::Keyboard::Key& key, const bool is_pressed );
};

#endif
