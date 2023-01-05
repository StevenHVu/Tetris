#include <iostream>
#include "game.h"

using namespace std;

int main() {
    
    Game Tetris;
    Tetris.clearScreen();
    Tetris.gameStart();
    Tetris.printBoard();
    Tetris.initalize();
    Tetris.printGameData();
    Tetris.getPlayerInput();

    cout << "\x1b[0m";
    return 0;
}