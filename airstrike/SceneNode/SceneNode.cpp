
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

bool
ASceneNode::IsNodeRequired( SNPointer_t& snp, const ASceneNode& node ) {
    return snp.get() == &node;
}
