#include "board.h"

int Board::getXPixelPos(int x) {
  return ((BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2))) + (x * BLOCK_SIZE));
}

int Board::getYPixelPos(int y) {
  return ((screenHeight - (BLOCK_SIZE * BOARD_HEIGHT)) + (y * BLOCK_SIZE));
}

bool Board::isFreeBlock(int x, int y) {
  return (POS_FREE == board[x][y]) ? true : false;
}

bool Board::isPossibleMovement(int x, int y, int piece, int rotation) {
  for (int i1 = x, i2 = 0; i1 < x + PIECE_BLOCKS; i1++, i2++) {
    for (int j1 = y, j2 = 0; j1 < y + PIECE_BLOCKS; j1++, j2++) {
      if (i1 < 0 || i1 > BOARD_HEIGHT - 1 || j1 > BOARD_HEIGHT - 1) {
        if (0 != pieces->getBlockType(piece, rotation, j2, i2))
          return false;
      }

      if (j1 >= 0) {
        if (0 != pieces->getBlockType(piece, rotation, j2, i2) && !isFreeBlock(i1, j1)) {
          return false;
        }
      }
    }
  }

  return true;
}

void Board::storePiece(int x, int y, int piece, int rotation) {
  for (int i1 = x, i2 = 0; i1 < x + PIECE_BLOCKS; i1++, i2++) {
    for (int j1 = y, j2 = 2; j1 < y + PIECE_BLOCKS; j1++, j2++) {
      if (0 != pieces->getBlockType(piece, rotation, i2, j2)) {
        board[i1][j1] = POS_FILLED;
      }
    }
  }
}

void Board::deletePossibleLines() {
  for (int j = 0; j < BOARD_HEIGHT; j++) {
    int i = 0;
    while (i < BOARD_WIDTH) {
      if (POS_FILLED != board[i][j])
        break;
      i++;
    }

    if (BOARD_WIDTH == i)
      deleteLine(j);
  }
}

bool Board::isGameOver() {
  for (int i = 0; i < BOARD_WIDTH; i++) {
    if (POS_FILLED == board[i][0]) {
      return true;
    }
  }
  return false;
}

void Board::initBoard() {
  for (int i = 0; i < BOARD_WIDTH; i++) {
    for (int j = 0; j < BOARD_HEIGHT; j++) {
      board[i][j] = POS_FREE;
    }
  }
}

void Board::deleteLine(int y) {
  for (int i = y; i > 0; i--) {
    for (int j = 0; j < BOARD_WIDTH; j++) {
      board[j][i] = board[j][i-1];
    }
  }
}
