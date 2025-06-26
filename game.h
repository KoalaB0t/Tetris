#ifndef _GAME_
#define _GAME_

#include "board.h"

#include <time.h>

#define WAIT_TIME 700

class Game {
  public:
    Game(Board *board, Pieces *pieces, int screenHeight);
    void createNewPiece();

    int posX, posY;
    int piece, rotation;

  private:
    int screenHeight;
    int nextPosX, nextPosY;
    int nextPiece, nextRotation;

    Board *board;
    Pieces *pieces;

    int getRand(int a, int b);
    void initGame();
};

#endif //_GAME_
