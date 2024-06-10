


#include "../header/class.h"

Square::Square()
{
    pos = sf::Vector2f(0, 0);
    square.setSize(sf::Vector2f(200, 200));
    square.setFillColor(sf::Color::Black);
    square.setPosition(pos);
    square.setOutlineThickness(1);
    square.setOutlineColor(sf::Color::White);
    symbol = ' ';
}

Square::Square(sf::Vector2f pos, sf::IntRect rect)
{
    this->pos = pos;
    this->rect = rect;
    square.setSize(sf::Vector2f(200, 200));
    square.setFillColor(sf::Color::Black);
    square.setPosition(pos);
    square.setOutlineThickness(1);
    square.setOutlineColor(sf::Color::White);
    symbol = ' ';
}

void Square::checkIsClicked(sf::Window *window, Board *board)
{
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(*window);

    if (rect.contains(mouse_pos)) {
        if (symbol == ' ') {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (board->turn == 0) {
                    symbol = 'X';
                    square.setFillColor(sf::Color(50, 205, 50));
                    board->board[rect.top / 200][rect.left / 200] = 'X';
                } else {
                    symbol = 'O';
                    square.setFillColor(sf::Color(238, 145, 238));
                    board->board[rect.top / 200][rect.left / 200] = 'O';
                }
                board->turn ^= 1;
            }
        }
    }
}

void Square::display(sf::RenderWindow *window)
{
    window->draw(square);
}
