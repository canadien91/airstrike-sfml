
#ifndef __AIRCRAFT_H__
#define __AIRCRAFT_H__

#include "Entity/Entity.h"

class AnAircraft : public AnEntity {
public:
    enum Type_t {
        Eagle,
        Raptor,
    };

    explicit AnAircraft( Type_t type, const ATextureHolder_t& textures );

private:
    Type_t              type;
    sf::Sprite          sprite;

    virtual void        DrawCurrent( sf::RenderTarget& target, sf::RenderStates states ) const;
    Textures_ns::Id_t   GetTextureId() const;
};

#endif
