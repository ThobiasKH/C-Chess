#pragma once

// Flag documentation: https://www.chessprogramming.org/Encoding_Moves

typedef enum {
    moveFlag_QUIET                 = 0b0000,
    moveFlag_DOUBLE_PAWN_PUSH      = 0b0001,
    moveFlag_KING_CASTLE           = 0b0010,
    moveFlag_QUEEN_CASTLE          = 0b0011,
    moveFlag_CAPTURE               = 0b0100,
    moveFlag_CAPTURE_EN_PASSANT    = 0b0101,
    moveFlag_PROMO_KNIGHT          = 0b1000,
    moveFlag_PROMO_BISHOP          = 0b1001,
    moveFlag_PROMO_ROOK            = 0b1010,
    moveFlag_PROMO_QUEEN           = 0b1011,
    moveFlag_PROMO_CAPTURE_KNIGHT  = 0b1100,
    moveFlag_PROMO_CAPTURE_BISHOP  = 0b1101,
    moveFlag_PROMO_CAPTURE_ROOK    = 0b1110,
    moveFlag_PROMO_CAPTURE_QUEEN   = 0b1111
} MoveFlag;

typedef struct {
    int startSquare;
    int targetSquare;
    MoveFlag flag;
} Move;

int move_isNullMove(Move move);
int move_hasFlag(Move move, MoveFlag flag);
