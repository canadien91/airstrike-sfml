
#ifndef __GAME_H__
#define __GAME_H__

#include <World/World.h>

class AGame : private sf::NonCopyable {
public:
    AGame();

    void Run();

private:
    static const sf::Time   TIME_PER_FRAME;

    sf::RenderWindow        window;
    AWorld                  world;

    sf::Font                font;
    sf::Text                statistics_text;
    sf::Time                statistics_update_time;
    std::size_t             statistics_num_frames;

    void                    ProcessEvents();
    void                    Update( const sf::Time& dt );
    void                    UpdateStatistics( const sf::Time& dt );
    void                    Render();
    void                    HandlePlayerInput( const sf::Keyboard::Key& key, const bool is_pressed );
};

#endif
