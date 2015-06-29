
#ifndef __SPRITE_NODE__
#define __SPRITE_NODE__

#include "SceneNode/SceneNode.h"

class ASpriteNode : public ASceneNode {
public:
    explicit ASpriteNode( const sf::Texture& texture );
    ASpriteNode( const sf::Texture& texture, const sf::IntRect& texture_rect );

private:
    sf::Sprite      sprite;
    virtual void    DrawCurrent( sf::RenderTarget& target, sf::RenderStates states ) const;
};

#endif
