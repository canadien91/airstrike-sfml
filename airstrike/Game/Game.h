
#ifndef __GAME_H__
#define __GAME_H__

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class AGame {
public:
    AGame();

    void Run();

private:
    sf::RenderWindow    window;
    sf::CircleShape     player;

    void                ProcessEvents();
    void                Update();
    void                Render();
};

#endif
