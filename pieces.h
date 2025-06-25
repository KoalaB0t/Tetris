#ifndef _PIECES_
#define _PIECES_

class Pieces {
  public:
    int GetBlockType(int piece, int rotation, int x, int y);
    int GetXInitialPosition(int piece, int rotation);
    int GetYInitialPosition(int piece, int rotation);
};

#endif //_PIECES_
