#include "game.h"

#include <stdlib.h>

void Game::createNewPiece() {
  piece = nextPiece;
  rotation = nextRotation;
  posX = (BOARD_WIDTH / 2) + pieces->getXInitialPosition(piece, rotation);
  posY = pieces->getYInitialPosition(piece, rotation);

  nextPiece = getRand(0, 6);
  nextRotation = getRand(0, 3);
}

int Game::getRand(int a, int b) {
  return rand() % (b - a + 1) + a;
}

void Game::initGame() {
  srand((unsigned int) time(NULL));

  nextPiece = getRand(0, 6);
  nextRotation = getRand(0, 3);
  nextPosX = BOARD_WIDTH + 5;
  nextPosY = 5;
}
