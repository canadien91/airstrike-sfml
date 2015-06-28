
#ifndef __SCENE_NODE_H__
#define __SCENE_NODE_H__

#include <algorithm>
#include <cassert>
#include <memory>
#include <vector>

class ASceneNode {
public:
    typedef std::unique_ptr<ASceneNode> SNPointer_t;
    ASceneNode();

    void        AttachChild( SNPointer_t child );
    SNPointer_t DetachChild( const ASceneNode& node );

private:
    std::vector<SNPointer_t>    children;
    ASceneNode*                 parent;

    bool                        IsNodeRequired( SNPointer_t& snp, const ASceneNode& node );
};

#endif
