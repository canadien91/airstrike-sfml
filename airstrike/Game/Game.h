
#ifndef __GAME_H__
#define __GAME_H__

#include <SFML/Graphics.hpp>

class AGame {
public:
    AGame();

    void Run();

private:
    sf::RenderWindow    window;
    sf::CircleShape     player;
    bool                is_moving_up;
    bool                is_moving_down;
    bool                is_moving_left;
    bool                is_moving_right;

    void                ProcessEvents();
    void                Update();
    void                Render();
    void                HandlePlayerInput( const sf::Keyboard::Key& key, const bool is_pressed );
};

#endif
