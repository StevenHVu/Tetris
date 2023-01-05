#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
//#include "C:\Users\vuhoa\Desktop\VCPKG\vcpkg\installed\x64-windows\include\SFML\Graphics.hpp"
#include <SFML/Graphics.hpp>
#include "game.h"

using namespace std;

void window() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);

        // end the current frame
        window.display();
    }
}

void Game::gameStart() {
    cout << "\x1b[38;5;45m";

    srand(time(NULL));

    cout << "Tetris game is starting..." << endl;

    // cout << "\x1b[0m";
}


Board::Board() {
    // setting the entire board to be false
    cout << "Board constructor called..." << endl;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            grid[i][j] = false;
        }
    }
}

void Game::printAll() {
    clearScreen();
    printBoard();
    printGameData();
}

void Board::clearScreen() {
    system("CLS");
    cout << flush;
    cout << "The screen has been cleared..." << endl;
}

void Board::printBoard() {
    cout << "Printing out the board to the console..." << endl;
    // setting background color to white
    //cout << "\x1b[48;5;0m";
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            if (grid[i][j] == false) {
                cout << "\x1b[48;5;0m| ";
            }
            else {
                cout << "\x1b[48;5;255m| ";
            }
        }
        cout << "\x1b[38;5;45m|" << "\x1b[0m" << "\x1b[38;5;45m" << endl;
    }
}

int Game::getScore() {
    return score;
}

int Game::getLinesCleared() {
    return linesCleared;
}

char Game::getPieceInHand() {
    return pieceInHand;
}

void Game::setPieceInHand(char input) {
    pieceInHand = input;
}

char Game::getPieceOnHold() {
    return pieceOnHold;
}

void Game::setPieceOnHold(char input) {
    pieceOnHold = input;
}

void Game::printGameData() {
    // setting font color to be blue
    cout << "\x1b[38;5;45m";

    cout << "Score: " << getScore() << endl;
    cout << "Lines cleared: " << getLinesCleared() << endl;

    cout << "Piece in hand: [" << getPieceInHand() << "]" << endl;
    cout << "Piece on hold: [" << getPieceOnHold() << "]" << endl;
    printQueue();
}

void Game::generateTetrisPieceFirstBag() {
    bool unique = true;
    char currentPiece = generateTetrisPiece();
    setPieceInHand(currentPiece);
    
    int i = 0;
    while (i != 6) {
        //cout << "i: " << i << endl;
        currentPiece = generateTetrisPiece();
        
        for (int j = 0; j < 7; j++) {
            // if there's a match with the generated piece and the current queue
            if ((tetrisQueue[j] == currentPiece) | (getPieceInHand() == currentPiece) | (getPieceOnHold())) {
                unique = false;
            }
        }
        // if unique flag is passed, add the piece to the queue
        if (unique) {
            tetrisQueue[i] = currentPiece;
            i++;
            //printQueue();
        }
        unique = true;
        generateTetrisPiecePattern();
    } 
}

void Game::generateTetrisPiecePattern() {
    char currentPiece = generateTetrisPiece();
    int pieceCounter = 0;

    for (int i = 0; i < 7; i++) {
        if (currentPiece == tetrisQueue[i]) {
            pieceCounter++;
        }
    }
    if (pieceCounter <= 1) {
        tetrisQueue[6] = currentPiece;
    }
}

// generating pieces after initial bag
char Game::generateTetrisPiece() {
    int random = rand() % 7;
    //cout << "Random value generated: " << random << endl;

    // getting a random char of a tetris piece
    switch (random) {
        case 0:
            return 'z';
        case 1:
            return 's';
        case 2:
            return 'i';
        case 3:
            return 'o';
        case 4:
            return 'j';
        case 5:
            return 'l';
        case 6:
            return 't';
    }
    return 'n';
}

void Game::initalize() {
    generateTetrisPieceFirstBag();
}

void Game::printQueue() {
    cout << "Queue: ";
    for (int i = 0; i < 7; i++) {
        cout << "[" << tetrisQueue[i] << "]";
    }
    cout << endl;
}

bool Game::getStatus() {
    return status;
}

void Game::setStatus(int input) {
    status = input;
}

void Game::swapPieces() {
    if ((getPieceInHand() == '\0') | (getPieceOnHold() == '\0')) {
        setPieceOnHold(getPieceInHand());
        setPieceInHand(tetrisQueue[0]);
        for (int i = 0; i < 6; i++) {
            tetrisQueue[i] = tetrisQueue[i + 1];
        }
        generateTetrisPiecePattern();
    }
    else {
        char tempPiece = getPieceOnHold();
        setPieceOnHold(getPieceInHand());
        setPieceInHand(tempPiece);
    }
}

void Game::showPieceInHand() {
    if (getPieceInHand() == 'o') {
        
    }
}

void Game::getPlayerInput() {
    cout << "status: " << getStatus() << endl;
    bool swapCounter = true;
    while (getStatus() != 1) {
        if (GetKeyState(VK_LSHIFT) & 0x8000) {
            cout << "shift key was pressed" << endl;
            Sleep(500000);
            if (swapCounter == true) {
                swapPieces();
                printAll();
                swapCounter = false;
            }
        }
        else if (GetKeyState('A') & 0x8000) {
            cout << "a was pressed" << endl;
            Sleep(500000);
            printAll();
        }
    }
}