#pragma once
#include <stdint.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Pieces.h"

extern int board_board[];

void board_loadPositionFromFEN(char *FEN);
int board_setUpIMGLoader();
void board_cleanUpIMG(); 
int board_INIT(SDL_Renderer *renderer);
void board_drawGraphicalBoard(SDL_Renderer *renderer);
void board_drawPieces(SDL_Renderer *renderer);

