
#include "Game.h"

AGame::AGame() :
window( sf::VideoMode( 640, 480 ), "SFML Airstrike" ) {
    this->window.setVerticalSyncEnabled( true );
    this->player            = sf::CircleShape();
    this->time_per_frame    = sf::Time( sf::seconds( 1.0f / 60.0f ) );
    this->is_moving_up      = false;
    this->is_moving_down    = false;
    this->is_moving_left    = false;
    this->is_moving_right   = false;
    this->player_speed      = 200.0f;

    this->player.setRadius( 40.0f );
    this->player.setPosition( 100.0f, 100.0f );
    this->player.setFillColor( sf::Color::Cyan );
}

void
AGame::Run() {
    sf::Clock clock;
    sf::Time time_since_last_update = sf::Time::Zero;
    while ( this->window.isOpen() ) {
        this->ProcessEvents();
        time_since_last_update += clock.restart();
        while ( time_since_last_update > this->time_per_frame ) {
            time_since_last_update -= this->time_per_frame;
            this->ProcessEvents();
            this->Update( this->time_per_frame );
        }
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
        movement.y -= this->player_speed;
    }
    if ( this->is_moving_down ) {
        movement.y += this->player_speed;
    }
    if ( this->is_moving_left ) {
        movement.x -= this->player_speed;
    }
    if ( this->is_moving_right ) {
        movement.x += this->player_speed;
    }
    this->player.move( movement * dt.asSeconds() );
}

void
AGame::Render() {
    this->window.clear();
    this->window.draw( this->player );
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
