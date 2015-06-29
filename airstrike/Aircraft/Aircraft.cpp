
#include "Aircraft.h"

AnAircraft::AnAircraft( Type_t type, const ATextureHolder_t& textures ) {
    this->type              = type;
    this->sprite            = sf::Sprite( textures.GetResource( this->GetTextureId() ) );

    sf::FloatRect bounds    = this->sprite.getLocalBounds();
    this->sprite.setOrigin( bounds.width / 2.0f, bounds.height / 2.0f );
}

void
AnAircraft::DrawCurrent( sf::RenderTarget& target, sf::RenderStates states ) const {
    target.draw( this->sprite, states );
}

Textures_ns::Id_t
AnAircraft::GetTextureId() const {
    if ( this->type == Eagle ) {
        return Textures_ns::Eagle;
    } else if ( this->type == Raptor ) {
        return Textures_ns::Raptor;
    } else {
        return Textures_ns::Eagle;
    }
}
