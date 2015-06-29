
#include <iostream>

#include <Game/Game.h>

int main() {
    try {
        AGame game;
        game.Run();
    } catch ( std::exception& e ) {
        std::cout << "\nEXCEPTION: " << e.what() << std::endl;
    }
    return 0;
}
