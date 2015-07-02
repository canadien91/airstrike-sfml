
#ifndef __AIRCRAFT_MOVER_H__
#define __AIRCRAFT_MOVER_H__

#include <SFML/Graphics.hpp>

#include <Aircraft/Aircraft.h>

class AnAircraftMover {
public:
    AnAircraftMover( const float vx, const float vy );
    AnAircraftMover( const sf::Vector2f& velocity );

    void operator() ( AnAircraft& aircraft ) const;

private:
    sf::Vector2f velocity;
};

#endif
