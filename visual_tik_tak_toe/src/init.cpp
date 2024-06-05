
#include "../header/tic_tac_toe.h"
#include "../header/class.h"

//! player et tt ces fonction qui vont avec
Player::Player() : name("NONE"), one_or_two(0), symbol(' ') {}
Player::Player(std::string name, int id, char mark) : name(name), one_or_two(id), symbol(mark) {}


//! board et tt ces fonction qui vont avec
Board::Board() : turn(0), player1(NULL), player2(NULL) {}
Board::Board(Player *player1, Player *player2) : turn(0), player1(player1), player2(player2) {
    initBoard();
}

char Board::getMark(int x, int y)
{
    if (x >= 0 && x < 3 && y >= 0 && y < 3)
        return board[x][y];
    return ' ';
}

bool Board::checkWin(void)
{
    for (int i = 0; i < 3; i++) {
        if (getMark(i, 0) == getMark(i, 1) && getMark(i, 1) == getMark(i, 2) && getMark(i, 0) != ' ')
            return true;
        if (getMark(0, i) == getMark(1, i) && getMark(1, i) == getMark(2, i) && getMark(0, i) != ' ')
            return true;
        if (getMark(0, 0) == getMark(1, 1) && getMark(1, 1) == getMark(2, 2) && getMark(0, 0) != ' ')
            return true;
        if (getMark(0, 2) == getMark(1, 1) && getMark(1, 1) == getMark(2, 0) && getMark(0, 2) != ' ')
            return true;
    }
    return false;
}

void Board::initBoard(void)
{
    board.push_back("   ");
    board.push_back("   ");
    board.push_back("   ");
}

Board *init_tic_tac_toe(char **av)
{
    Player *player1 = new Player(av[1], 1, 'X');
    Player *player2 = new Player(av[2], 2, 'O');
    Board *board = new Board(player1, player2);

    return board;
}