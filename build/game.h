#ifndef GAME_H
#define GAME_H

class Board {
    public:
        Board();
        void printBoard();
        void clearScreen();
    private:
        bool grid[20][10];
};

class Game : public Board {
    public:
        void gameStart();
        void initalize();
        void printGameData();
        int getScore();
        int getLinesCleared();
        void generateTetrisPieceFirstBag();
        void generateTetrisPiecePattern();
        char generateTetrisPiece();
        void printQueue();
        char getPieceInHand();
        void setPieceInHand(char);
        char getPieceOnHold();
        void setPieceOnHold(char);
        void getPlayerInput();
        bool getStatus();
        void setStatus(int);
        void printAll();
        void swapPieces();
        void showPieceInHand();
    private:
        int linesCleared = 0;
        int score = 0;
        char pieceInHand;
        char pieceOnHold;
        char tetrisQueue[7];
        Board board;
        bool status = 1;
};

#endif