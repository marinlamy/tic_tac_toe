

#include "../header/tic_tac_toe.h"
#include "../header/class.h"

Coord::Coord() : x(-1), y(-1) {}
Coord::Coord(int x, int y) : x(x), y(y) {}

bool error_case_input(std::string input)
{
    if (input.length() != 3) {
        std::cout << "Invalid input" << std::endl;
        return true;
    }
    if (input[0] < '0' || input[0] > '2' || input[2] < '0' || input[2] > '2' || input[1] != ',')
        return true;
    return false;
}

void Coord::getInput(void)
{
    std::string input;

    std::cout << "Enter your move \"y,x\": ";
    std::getline(std::cin, input);
    if (error_case_input(input)) {
        std::cout << "Invalid input" << std::endl;
        getInput();
        return;
    }
    y = input[0] - '0';
    x = input[2] - '0';
    return;
}


void game_loop(Board *board)
{
    Coord coord;
    Player *player = board->player1;
    bool win = false;

    board->display();
    while(!win) {
        std::cout << player->name << "'s turn" << std::endl;
        coord.getInput();
        if (board->getMark(coord.x, coord.y) != ' ') {
            std::cout << "Invalid move" << std::endl;
            continue;
        }
        board->board[coord.x][coord.y] = player->symbol;
        board->display();
        player = (player == board->player1) ? board->player2 : board->player1;
        win = board->checkWin();
    }
    player = (player == board->player1) ? board->player2 : board->player1;
    printf("%s wins\n", player->name.c_str());
    return;
}