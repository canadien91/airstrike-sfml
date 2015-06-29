
#include "Entity.h"

void
AnEntity::SetVelocity( const sf::Vector2f& velocity ) {
    this->velocity.x = velocity.x;
    this->velocity.y = velocity.y;
}

void
AnEntity::SetVelocity( float vx, float vy ) {
    this->velocity.x = vx;
    this->velocity.y = vy;
}

sf::Vector2f
AnEntity::GetVelocity() const {
    return this->velocity;
}

void
AnEntity::UpdateCurrent( const sf::Time& dt ) {
    this->move( this->velocity * dt.asSeconds() );
}
