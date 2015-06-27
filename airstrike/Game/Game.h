
#ifndef __GAME_H__
#define __GAME_H__

#include <string>

#include <SFML/Graphics.hpp>

#include "ResourceHolder/ResourceIdentifiers.h"

class AGame {
public:
    AGame();

    void Run();

private:
    static const float      PLAYER_SPEED;
    static const sf::Time   TIME_PER_FRAME;

    sf::RenderWindow        window;
    sf::Texture             texture;
    sf::Sprite              player;
    sf::Font                font;

    sf::Text                statistics_text;
    sf::Time                statistics_update_time;
    std::size_t             statistics_num_frames;

    bool                    is_moving_up;
    bool                    is_moving_down;
    bool                    is_moving_left;
    bool                    is_moving_right;

    void                    ProcessEvents();
    void                    Update( const sf::Time& dt );
    void                    UpdateStatistics( const sf::Time& dt );
    void                    Render();
    void                    HandlePlayerInput( const sf::Keyboard::Key& key, const bool is_pressed );
};

#endif
