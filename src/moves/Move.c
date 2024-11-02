#include "../../include/Move.h"

int isNullMove(Move move) {
    return move.startSquare == 0 && move.targetSquare == 0 && move.flag == 0;
}
