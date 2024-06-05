/*
    ** main.cpp
    ** Created on: 03/06/2024
    ** by: Marin
*/

#include "../header/tic_tac_toe.h"
#include "../header/class.h"

int error_mess(int argc, char **argv)
{
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <Player1Name> <Player2Name>" << std::endl;        return 1;
    }
    return 0;
}

void free_fonction(Board *board)
{
    delete board->player1;
    delete board->player2;
    delete board;
}

int main(int argc, char **argv)
{
    if (error_mess(argc, argv) == 1)
        return 1;
    Board *board = init_tic_tac_toe(argv);
    printf("Welcome to Tic Tac Toe\n");
    std::cerr << "Player 1: " << board->player1->name << " (X)" << std::endl;
    std::cerr << "Player 2: " << board->player2->name << " (O)" << std::endl;
    game_loop(board);
    free_fonction(board);
    return 0;
}
