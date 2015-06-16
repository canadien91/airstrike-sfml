
#include "Game.h"

AGame::AGame() :
window( sf::VideoMode( 640, 480), "SFML Airstrike" ) {
    this->player = sf::CircleShape();

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
        }
    }
}

void
AGame::Update() {
}

void
AGame::Render() {
    this->window.clear();
    this->window.draw( this->player );
    this->window.display();
}
