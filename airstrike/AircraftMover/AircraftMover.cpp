
#include "AircraftMover.h"

AnAircraftMover::AnAircraftMover( const float vx, const float vy ) {
    this->velocity = sf::Vector2f( vx, vy );
}

AnAircraftMover::AnAircraftMover( const sf::Vector2f& velocity ) {
    this->velocity = velocity;
}

void
AnAircraftMover::operator() ( AnAircraft& aircraft ) const {
    aircraft.Accelerate( this->velocity );
}
