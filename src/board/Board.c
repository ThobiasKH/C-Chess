#include "../../include/Board.h"

uint64_t whitePawns   = 0x00FF000000000000; // All in rank number 2 = 1 
uint64_t whiteRooks   = 0x8100000000000000; // 0b1000 0001 = 0x81 
uint64_t whiteKings   = 0x1000000000000000; // and so on..
uint64_t whiteQueens  = 0x0800000000000000;
uint64_t whiteKnights = 0x4200000000000000;
uint64_t whiteBishops = 0x2400000000000000;

uint64_t blackPawns   = 0xFF00; 
uint64_t blackRooks   = 0x0081;
uint64_t blackKings   = 0x0010; 
uint64_t blackQueens  = 0x0008;
uint64_t blackKnights = 0x0042;
uint64_t blackBishops = 0x0024;

uint64_t board_bitboards[24];
SDL_Texture* pieceTex = NULL;

void board_populateBitboardsArray() {
    board_bitboards[piece_WHITE | piece_KING] = whiteKings;
    board_bitboards[piece_WHITE | piece_QUEEN] = whiteQueens;
    board_bitboards[piece_WHITE | piece_BISHOP] = whiteBishops;
    board_bitboards[piece_WHITE | piece_KNIGHT] = whiteKnights;
    board_bitboards[piece_WHITE | piece_ROOK] = whiteRooks;
    board_bitboards[piece_WHITE | piece_PAWN] = whitePawns;

    board_bitboards[piece_BLACK | piece_KING] = blackKings;
    board_bitboards[piece_BLACK | piece_QUEEN] = blackQueens;
    board_bitboards[piece_BLACK | piece_BISHOP] = blackBishops;
    board_bitboards[piece_BLACK | piece_KNIGHT] = blackKnights;
    board_bitboards[piece_BLACK | piece_ROOK] = blackRooks;
    board_bitboards[piece_BLACK | piece_PAWN] = blackPawns;
}

static bool board_imgInitialized= false;

int board_setUpIMGLoader() {
    if (!board_imgInitialized) {
        if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
            return -1;
        }
        board_imgInitialized = true;
    }
    return 0;
}

int board_INIT(SDL_Renderer *renderer) {
    board_populateBitboardsArray();
    if (board_setUpIMGLoader() < 0) {
        return -1; 
    }

    pieceTex = IMG_LoadTexture(renderer, "src/pieces/pieces.png");
    if (!pieceTex) {
        printf("Failed to load texture: %s\n", IMG_GetError());
        return -1; 
    }

    return 0;
}

void board_cleanupIMG() {
    if (pieceTex) {
        SDL_DestroyTexture(pieceTex); 
        pieceTex = NULL;
    }

    if (board_imgInitialized) {
        IMG_Quit();
        board_imgInitialized = 0; 
    }
}

int board_bitboardPieceExistsOnSquare(uint64_t bitboard, int square) {
    return (bitboard >> square) & 1;
}

void board_drawGraphicalBoard(SDL_Renderer *renderer) {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            int isDarkSquare = (row + col) % 2 != 0;
            SDL_Rect square;
            square.x = col * 100;
            square.y = row * 100,
            square.w = 100;
            square.h = 100;

            int r = isDarkSquare ? 160 : 230;
            int g = isDarkSquare ? 100 : 230;
            int b = isDarkSquare ?  50 : 200;

            SDL_SetRenderDrawColor(renderer, r, g, b, 255);
            SDL_RenderFillRect(renderer, &square);
        }
    }
}

void board_drawPieces(SDL_Renderer *renderer) {
    int bitboardsLength = sizeof(board_bitboards) / sizeof(board_bitboards[0]);


    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            for (int i = 0; i < bitboardsLength; i++) {
                uint64_t bitboard = board_bitboards[i];
                if (board_bitboardPieceExistsOnSquare(bitboard, row * 8 + col)) {
                    int type = piece_getType(i);
                    SDL_Rect srcRect = {
                        (type - 1) * 133,
                        piece_isWhite(i) ? 0 : 133,
                        133,
                        133,
                    };

                    SDL_Rect screenRect = {
                        col * 100,
                        row * 100,
                        100,
                        100
                    };

                    SDL_RenderCopy(renderer, pieceTex, &srcRect, &screenRect);
                }
            }
        }
    }
}
