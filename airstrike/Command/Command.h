
#ifndef __COMMAND_H__
#define __COMMAND_H__

#include <functional>

#include <SFML/System/Time.hpp>

#include <SceneNode/SceneNode.h>

class ACommand {
public:
    ACommand();
    std::function<void( ASceneNode&, const sf::Time& )> action;
    unsigned int                                        category;

};

#endif
