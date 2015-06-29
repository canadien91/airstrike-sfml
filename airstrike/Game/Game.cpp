
#include "Game.h"

const sf::Time  AGame::TIME_PER_FRAME   = sf::Time( sf::seconds( 1.0f / 60.0f ) );

AGame::AGame() :
window( sf::VideoMode( 640, 480 ), "SFML Airstrike" ),
world( this->window ) {
    this->window.setVerticalSyncEnabled( true );
    this->font                      = sf::Font();
    this->statistics_text           = sf::Text();
    this->statistics_update_time    = sf::Time();
    this->statistics_num_frames     = 0;

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
        }
    }
}

void
AGame::Update( const sf::Time& dt ) {
    this->world.Update( dt );
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
    this->world.Draw();

    this->window.setView( this->window.getDefaultView() );
    this->window.draw( this->statistics_text );
    this->window.display();
}

void
AGame::HandlePlayerInput( const sf::Keyboard::Key& key, const bool is_pressed ){
}
