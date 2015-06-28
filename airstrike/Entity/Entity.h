
#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "SceneNode/SceneNode.h"

class AnEntity : ASceneNode {
public:
    void            SetVelocity( const sf::Vector2f& velocity );
    void            SetVelocity( float vx, float vy );
    sf::Vector2f    GetVelocity() const;

private:
    sf::Vector2f velocity;

};

#endif
