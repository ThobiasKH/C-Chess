#include "../../include/Pieces.h"

const int piece_NONE   = 0;
const int piece_KING   = 1;
const int piece_QUEEN  = 2;
const int piece_BISHOP = 3;
const int piece_KNIGHT = 4;
const int piece_ROOK   = 5;
const int piece_PAWN   = 6;
const int piece_WHITE  = 8;
const int piece_BLACK  = 16;

bool piece_isWhite(int pieceCode) {
    if (pieceCode == piece_NONE) return false;

    return pieceCode < 16;
}

int piece_getType(int pieceCode) {
    if (pieceCode == 0) return 0;
    return piece_isWhite(pieceCode) ? pieceCode - 8 : pieceCode - 16; 
}
