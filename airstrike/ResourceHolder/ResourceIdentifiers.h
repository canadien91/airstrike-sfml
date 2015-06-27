
#ifndef __RESOURCE_IDENTIFIERS_H__
#define __RESOURCE_IDENTIFIERS_H__
#include "ResourceHolder.hpp"

namespace Textures_ns {
    enum Id_t {
        Eagle,
        Raptor,
        Desert,
    };
}

namespace Fonts_ns {
    enum Id_t {
        Main,
    };
}

typedef AResourceHolder<sf::Texture, Textures_ns::Id_t> ATextureHolder;
#endif
