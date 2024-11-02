#pragma once
#include <stdbool.h>

extern const int piece_NONE;
extern const int piece_KING;
extern const int piece_QUEEN;
extern const int piece_BISHOP;
extern const int piece_KNIGHT;
extern const int piece_ROOK;
extern const int piece_PAWN;
extern const int piece_WHITE;
extern const int piece_BLACK;

bool piece_isWhite(int pieceCode);
int piece_getType(int pieceCode);
