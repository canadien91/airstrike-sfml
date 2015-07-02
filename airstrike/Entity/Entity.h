
#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "SceneNode/SceneNode.h"
#include "ResourceHolder/ResourceIdentifiers.h"

class AnEntity : public ASceneNode {
public:
    void            SetVelocity( const sf::Vector2f& velocity );
    void            SetVelocity( float vx, float vy );
    sf::Vector2f    GetVelocity() const;

    void            Accelerate( const sf::Vector2f& velocity );
    void            Accelerate( const float vx, const float vy );

private:
    sf::Vector2f velocity;

    virtual void    UpdateCurrent( const sf::Time& dt );

};

#endif
