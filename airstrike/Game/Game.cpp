
#include "Game.h"

const float     AGame::PLAYER_SPEED     = 200.0f;
const sf::Time  AGame::TIME_PER_FRAME   = sf::Time( sf::seconds( 1.0f / 60.0f ) );

AGame::AGame() :
window( sf::VideoMode( 640, 480 ), "SFML Airstrike" ) {
    this->window.setVerticalSyncEnabled( true );
    this->texture                   = sf::Texture();
    this->player                    = sf::Sprite();
    this->font                      = sf::Font();
    this->statistics_text           = sf::Text();
    this->statistics_update_time    = sf::Time();
    this->statistics_num_frames     = 0;
    this->is_moving_up              = false;
    this->is_moving_down            = false;
    this->is_moving_left            = false;
    this->is_moving_right           = false;

    if ( !this->texture.loadFromFile( "Media/Textures/Eagle.png" ) ) {
        // Handle loading error;
    }
    this->player.setTexture( this->texture );
    this->player.setPosition( 100.0f, 100.0f );

    this->font.loadFromFile( "Media/Sansation.ttf" );
    this->statistics_text.setFont( font );
    this->statistics_text.setPosition( 5.0f, 5.0f );
    this->statistics_text.setCharacterSize( 10 );
}

void
AGame::Run() {
    sf::Clock clock;
    sf::Time time_since_last_update = sf::Time::Zero;
    while ( this->window.isOpen() ) {
        sf::Time elapsed_time = clock.restart();
        time_since_last_update += elapsed_time;
        while ( time_since_last_update > TIME_PER_FRAME ) {
            time_since_last_update -= TIME_PER_FRAME;
            this->ProcessEvents();
            this->Update( TIME_PER_FRAME );
        }
        this->UpdateStatistics( elapsed_time );
        this->Render();
    }
}

void
AGame::ProcessEvents() {
    sf::Event event;
    while ( this->window.pollEvent( event) ) {
        if ( event.type == sf::Event::Closed ) {
            this->window.close();
        } else if ( event.type == sf::Event::KeyPressed ) {
            this->HandlePlayerInput( event.key.code, true );
        } else if ( event.type == sf::Event::KeyReleased ) {
            this->HandlePlayerInput( event.key.code, false );
        }
    }
}

void
AGame::Update( const sf::Time& dt ) {
    sf::Vector2f movement( 0.0f, 0.0f );
    if ( this->is_moving_up ) {
        movement.y -= PLAYER_SPEED;
    }
    if ( this->is_moving_down ) {
        movement.y += PLAYER_SPEED;
    }
    if ( this->is_moving_left ) {
        movement.x -= PLAYER_SPEED;
    }
    if ( this->is_moving_right ) {
        movement.x += PLAYER_SPEED;
    }
    this->player.move( movement * dt.asSeconds() );
}

void
AGame::UpdateStatistics( const sf::Time& dt ) {
    this->statistics_update_time += dt;
    this->statistics_num_frames += 1;

    if ( this->statistics_update_time >= sf::seconds( 1.0f ) ) {
        this->statistics_text.setString(
            "FPS = " + std::to_string( this->statistics_num_frames ) + "\n" +
            "Time / Update = " + std::to_string(
                this->statistics_update_time.asMicroseconds() / this->statistics_num_frames
            ) + "us"
        );
        this->statistics_update_time -= sf::seconds( 1.0f );
        this->statistics_num_frames = 0;
    }
}

void
AGame::Render() {
    this->window.clear();
    this->window.draw( this->player );
    this->window.draw( this->statistics_text );
    this->window.display();
}

void
AGame::HandlePlayerInput( const sf::Keyboard::Key& key, const bool is_pressed ){
    if ( key == sf::Keyboard::W ) {
        this->is_moving_up = is_pressed;
    } else if ( key == sf::Keyboard::S ) {
        this->is_moving_down = is_pressed;
    } else if ( key == sf::Keyboard::A ) {
        this->is_moving_left = is_pressed;
    } else if ( key == sf::Keyboard::D ) {
        this->is_moving_right = is_pressed;
    }
}
