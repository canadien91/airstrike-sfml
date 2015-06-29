
#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "SceneNode/SceneNode.h"
#include "ResourceHolder/ResourceIdentifiers.h"

class AnEntity : ASceneNode {
public:
    void            SetVelocity( const sf::Vector2f& velocity );
    void            SetVelocity( float vx, float vy );
    sf::Vector2f    GetVelocity() const;

private:
    sf::Vector2f velocity;

    virtual void    UpdateCurrent( const sf::Time& dt );

};

#endif
