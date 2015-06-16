
#include "Game.h"

AGame::AGame() :
window( sf::VideoMode( 640, 480 ), "SFML Airstrike" ) {
    this->player            = sf::CircleShape();
    this->is_moving_up      = false;
    this->is_moving_down    = false;
    this->is_moving_left    = false;
    this->is_moving_right   = false;

    this->player.setRadius( 40.0f );
    this->player.setPosition( 100.0f, 100.0f );
    this->player.setFillColor( sf::Color::Cyan );
}

void
AGame::Run() {
    while ( this->window.isOpen() ) {
        this->ProcessEvents();
        this->Update();
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
AGame::Update() {
    sf::Vector2f movement( 0.0f, 0.0f );
    if ( this->is_moving_up ) {
        movement.y -= 1.0f;
    }
    if ( this->is_moving_down ) {
        movement.y += 1.0f;
    }
    if ( this->is_moving_left ) {
        movement.x -= 1.0f;
    }
    if ( this->is_moving_right ) {
        movement.x += 1.0f;
    }
    this->player.move( movement );
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
