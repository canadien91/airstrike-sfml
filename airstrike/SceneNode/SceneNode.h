
#ifndef __SCENE_NODE_H__
#define __SCENE_NODE_H__

#include <algorithm>
#include <cassert>
#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

class ASceneNode :
    public sf::Transformable,
    public sf::Drawable,
    private sf::NonCopyable {
public:
    typedef std::unique_ptr<ASceneNode> SNPointer_t;
    ASceneNode();

    void            AttachChild( SNPointer_t child );
    SNPointer_t     DetachChild( const ASceneNode& node );
    void            Update( const sf::Time& dt );
    sf::Transform   GetWorldTransform() const;
    sf::Vector2f    GetWorldPosition() const;

private:
    std::vector<SNPointer_t>    children;
    ASceneNode*                 parent;

    bool                        IsNodeRequired( SNPointer_t& snp, const ASceneNode& node );
    virtual void                draw( sf::RenderTarget& target, sf::RenderStates states ) const;
    virtual void                DrawCurrent( sf::RenderTarget& target, sf::RenderStates states ) const;
    virtual void                UpdateCurrent( const sf::Time& dt );
    void                        UpdateChildren( const sf::Time& dt );
};

#endif
