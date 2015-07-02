
#include "Command.h"

ACommand::ACommand() {
    this->action    = std::function<void( ASceneNode&, const sf::Time& )>();
    this->category  = Category_ns::None;
}
