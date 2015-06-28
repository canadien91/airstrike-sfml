
#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <SFML/Graphics.hpp>

class AnEntity {
public:
    void            SetVelocity( const sf::Vector2f& velocity );
    void            SetVelocity( float vx, float vy );
    sf::Vector2f    GetVelocity() const;

private:
    sf::Vector2f velocity;

};

#endif
