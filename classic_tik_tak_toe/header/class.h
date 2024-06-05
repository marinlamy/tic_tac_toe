/*
    ** class.h
    ** Created on: 03/06/2024
    ** by: Marin
*/

#pragma once

#include "incl.h"

class Board;

Board *init_tic_tac_toe(char **av);
void game_loop(Board *board);


class Game {
public:
    Game();
    Game(int size_x, int size_y, char *name);
    void run();

private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow window;
};

class Player {
    public:
        Player();
        Player(std::string name, int one_or_two, char symbol);

        int play(int x, int y, Board *board);
        std::string name;
        int one_or_two;
        char symbol;
};

class Coord {
    public:
        Coord();
        Coord(int x, int y);
        void getInput(void);
        int x;
        int y;
};

class Board {
    public:
        Board();
        Board(Player *player1, Player *player2);

        void initBoard(void);
        void display(void);
        char getMark(int x, int y);
        bool checkWin(void);
        std::vector<std::string> board;
        int turn;
        Player *player1;
        Player *player2;
};
