
#include "World.h"

AWorld::AWorld( sf::RenderWindow& window ) :
window( window ) {
    this->world_view        = sf::View( window.getDefaultView() );
    this->scene_layers      = std::array<ASceneNode*, LayerCount>();
    this->world_bounds      = sf::FloatRect(
        0.0f,
        0.0f,
        this->world_view.getSize().x,
        2000.f
    );
    this->spawn_position    = sf::Vector2f(
        this->world_view.getSize().x / 2.0f,
        this->world_bounds.height - this->world_view.getSize().y
    );
    this->scroll_speed      = -50.0f;
    this->player_aircraft   = nullptr;

    this->LoadTextures();
    this->BuildScene();
    this->world_view.setCenter( this->spawn_position );
}

void
AWorld::LoadTextures() {
    this->textures.LoadResourceFromFile( Textures_ns::Eagle, "Media/Textures/Eagle.png" );
    this->textures.LoadResourceFromFile( Textures_ns::Raptor, "Media/Textures/Raptor.png" );
    this->textures.LoadResourceFromFile( Textures_ns::Desert, "Media/Textures/Desert.png" );
}

void
AWorld::BuildScene() {
    for ( std::size_t i = 0; i < LayerCount; i++ ) {
        ASceneNode::SNPointer_t layer( new ASceneNode() );
        this->scene_layers[i] = layer.get();

        this->scene_graph.AttachChild( std::move( layer ) );
    }

    sf::Texture& texture = this->textures.GetResource( Textures_ns::Desert );
    sf::IntRect texture_rect( this->world_bounds );
    texture.setRepeated( true );

    std::unique_ptr<ASpriteNode> background_sprite( new ASpriteNode( texture, texture_rect ) );
    background_sprite->setPosition( this->world_bounds.left, this->world_bounds.top );
    this->scene_layers[ Background ]->AttachChild( std::move( background_sprite ) );

    std::unique_ptr<AnAircraft> leader( new AnAircraft( AnAircraft::Eagle, this->textures ) );
    this->player_aircraft = leader.get();
    this->player_aircraft->setPosition( this->spawn_position );
    this->player_aircraft->SetVelocity( 40.0f, this->scroll_speed );
    this->scene_layers[ Air ]->AttachChild( std::move( leader ) );

    std::unique_ptr<AnAircraft> letf_escort( new AnAircraft( AnAircraft::Raptor, this->textures ) );
    letf_escort->setPosition( -80.0f, 50.0f );
    this->player_aircraft->AttachChild( std::move( letf_escort ) );

    std::unique_ptr<AnAircraft> right_escort( new AnAircraft( AnAircraft::Raptor, this->textures ) );
    right_escort->setPosition( 80.0f, 50.0f );
    this->player_aircraft->AttachChild( std::move( right_escort ) );
}
