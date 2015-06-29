
#include "SpriteNode.h"

ASpriteNode::ASpriteNode( const sf::Texture& texture ) {
    this->sprite = sf::Sprite( texture );
}

ASpriteNode::ASpriteNode( const sf::Texture& texture, const sf::IntRect& texture_rect ) {
    this->sprite = sf::Sprite( texture, texture_rect );
}

void
ASpriteNode::DrawCurrent( sf::RenderTarget& target, sf::RenderStates states ) const {
    target.draw( this->sprite, states );
}
