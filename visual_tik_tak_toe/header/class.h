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


class Square {
    public:
        Square();
        Square(sf::Vector2f pos, sf::IntRect rect);
        void checkIsClicked(sf::Window *window, Board *board);
        void display(sf::RenderWindow *window);
    private:
        char symbol;
        sf::RectangleShape square;
        sf::IntRect rect;
        sf::Vector2f pos;
        sf::Color color;
};

class Game {
    public:
        Game();
        Game(int size_x, int size_y, char *name);
        void run(Board *board);
        void CheckEventSquare(sf::Window *window, Board *board);
        void displaySquares(sf::RenderWindow *window);
    private:
        void processEvents();
        void update(sf::Window *window, Board *board);
        void render(Board *board);
        std::vector<Square> squares;
        sf::Text text;
        sf::Font font;
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



class Board {
    public:
        Board();
        Board(Player *player1, Player *player2);

        void initBoard(void);
        char getMark(int x, int y);
        bool checkWin(void);
        std::vector<std::string> board;
        int turn;
        Player *player1;
        Player *player2;
};
