#include "../../include/Move.h"

int move_isNullMove(Move move) {
    return move.startSquare == 0 && move.targetSquare == 0 && move.flag == moveFlag_QUIET;
}

int move_hasFlag(Move move, MoveFlag flag) {
    return move.flag == flag;
}
