#pragma once
#include <stdint.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Pieces.h"

extern uint64_t board_bitboards[];

void board_populateBitboardsArray();
int board_setUpIMGLoader();
void board_cleanUpIMG(); 
int board_INIT(SDL_Renderer *renderer);
void board_drawGraphicalBoard(SDL_Renderer *renderer);
void board_drawPieces(SDL_Renderer *renderer);
int board_bitboardPieceExistsOnSquare(uint64_t bitboard, int square);

