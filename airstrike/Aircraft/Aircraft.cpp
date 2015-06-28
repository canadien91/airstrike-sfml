
#include "Aircraft.h"

AnAircraft::AnAircraft( Type_t type ) {
    this->type = type;
}

void
AnAircraft::DrawCurrent( sf::RenderTarget& target, sf::RenderStates states ) const {
    target.draw( this->sprite, states );
}
