
#include "SceneNode.h"

ASceneNode::ASceneNode() {
    this->children  = std::vector<SNPointer_t>();
    this->parent    = nullptr;
}

void
ASceneNode::AttachChild( SNPointer_t child ) {
    child->parent = this;
    this->children.push_back( std::move( child ) );
}

ASceneNode::SNPointer_t
ASceneNode::DetachChild( const ASceneNode& node ) {
    auto found          = std::find_if(
        this->children.begin(),
        this->children.end(),
        [&] ( SNPointer_t& p ) -> bool { return p.get() == &node; }
    );

    assert( found != this->children.end() );

    SNPointer_t result  = std::move( *found );
    result->parent      = nullptr;
    this->children.erase( found );
    return result;
}

void
ASceneNode::Update( const sf::Time& dt ) {
    this->UpdateCurrent( dt );
    this->UpdateChildren( dt );
}

sf::Transform
ASceneNode::GetWorldTransform() const {
    sf::Transform transform = sf::Transform::Identity;
    for ( const ASceneNode* node = this; node != nullptr; node = node->parent ) {
        transform = node->getTransform() * transform;
    }
    return transform;
}

sf::Vector2f
ASceneNode::GetWorldPosition() const {
    return this->GetWorldTransform() * sf::Vector2f();
}

bool
ASceneNode::IsNodeRequired( SNPointer_t& snp, const ASceneNode& node ) {
    return snp.get() == &node;
}

void
ASceneNode::draw( sf::RenderTarget& target, sf::RenderStates states ) const {
    states.transform *= this->getTransform();

    this->DrawCurrent( target, states );
    for( const SNPointer_t& child : this->children ) {
        child->draw( target, states );
    }
}

void
ASceneNode::DrawCurrent( sf::RenderTarget& target, sf::RenderStates states ) const {
}

void
ASceneNode::UpdateCurrent( const sf::Time& dt ) {
}

void
ASceneNode::UpdateChildren( const sf::Time& dt ) {
    for ( SNPointer_t& child : this->children ) {
        child->Update( dt );
    }
}
