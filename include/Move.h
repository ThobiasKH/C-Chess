#pragma once

// Flag documentation: https://www.chessprogramming.org/Encoding_Moves

typedef enum {
    QUIET                 = 0b0000,
    DOUBLE_PAWN_PUSH      = 0b0001,
    KING_CASTLE           = 0b0010,
    QUEEN_CASTLE          = 0b0011,
    CAPTURE               = 0b0100,
    CAPTURE_EN_PASSANT    = 0b0101,
    PROMO_KNIGHT          = 0b1000,
    PROMO_BISHOP          = 0b1001,
    PROMO_ROOK            = 0b1010,
    PROMO_QUEEN           = 0b1011,
    PROMO_CAPTURE_KNIGHT  = 0b1100,
    PROMO_CAPTURE_BISHOP  = 0b1101,
    PROMO_CAPTURE_ROOK    = 0b1110,
    PROMO_CAPTURE_QUEEN   = 0b1111
} MoveFlag;

typedef struct {
    int startSquare;
    int targetSquare;
    int flag;
} Move;

int isNullMove(Move move);
