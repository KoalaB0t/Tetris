#ifndef _PIECES_
#define _PIECES_

class Pieces {
  public:
    int getBlockType(int piece, int rotation, int x, int y);
    int getXInitialPosition(int piece, int rotation);
    int getYInitialPosition(int piece, int rotation);
};

#endif //_PIECES_
