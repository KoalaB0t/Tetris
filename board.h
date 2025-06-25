#ifndef _BOARD_
#define _BOARD_

#include "pieces.h"

#define BOARD_LINE_WIDTH 16
#define BLOCK_SIZE 16
#define BOARD_POSITION 320
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
#define MIN_VERTICAL_MARGIN 20
#define MIN_HORIZONTAL_MARGIN 20
#define PIECE_BLOCKS 5

class Board {
  public:
    Board(Pieces *pieces, int screenHeight);

    int getXPixelPos(int x);
    int getYPixelPos(int y);
    bool isFreeBlock(int x, int y);
    bool isPossibleMovement(int x, int y, int piece, int rotation);
    void storePiece(int x, int y, int piece, int rotation);
    void deletePossibleLines();
    bool isGameOver();

  private:
    enum { POS_FREE, POS_FILLED };
    int board[BOARD_WIDTH][BOARD_HEIGHT];
    Pieces *pieces;
    int screenHeight;

    void initBoard();
    void deleteLine(int y);
};

#endif //_BOARD_
