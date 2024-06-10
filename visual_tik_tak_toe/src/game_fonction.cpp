
#include "../header/class.h"

Game::Game() : window(sf::VideoMode(600, 700), "SFML window") {
    font.loadFromFile("font/oswald.ttf");
    text.setFont(font);
    text.setFillColor(sf::Color::Black);
    squares.emplace_back(Square(sf::Vector2f(0, 0), sf::IntRect(0, 0, 200, 200)));
    squares.emplace_back(Square(sf::Vector2f(200, 0), sf::IntRect(200, 0, 200, 200)));
    squares.emplace_back(Square(sf::Vector2f(400, 0), sf::IntRect(400, 0, 200, 200)));
    squares.emplace_back(Square(sf::Vector2f(0, 200), sf::IntRect(0, 200, 200, 200)));
    squares.emplace_back(Square(sf::Vector2f(200, 200), sf::IntRect(200, 200, 200, 200)));
    squares.emplace_back(Square(sf::Vector2f(400, 200), sf::IntRect(400, 200, 200, 200)));
    squares.emplace_back(Square(sf::Vector2f(0, 400), sf::IntRect(0, 400, 200, 200)));
    squares.emplace_back(Square(sf::Vector2f(200, 400), sf::IntRect(200, 400, 200, 200)));
    squares.emplace_back(Square(sf::Vector2f(400, 400), sf::IntRect(400, 400, 200, 200)));
}
Game::Game(int size_x, int size_y, char *name) : window(sf::VideoMode(size_x, size_y), name) {
    squares.emplace_back(Square(sf::Vector2f(0, 0), sf::IntRect(0, 0, 200, 200)));
    squares.emplace_back(Square(sf::Vector2f(200, 0), sf::IntRect(200, 0, 200, 200)));
    squares.emplace_back(Square(sf::Vector2f(400, 0), sf::IntRect(400, 0, 200, 200)));
    squares.emplace_back(Square(sf::Vector2f(0, 200), sf::IntRect(0, 200, 200, 200)));
    squares.emplace_back(Square(sf::Vector2f(200, 200), sf::IntRect(200, 200, 200, 200)));
    squares.emplace_back(Square(sf::Vector2f(400, 200), sf::IntRect(400, 200, 200, 200)));
    squares.emplace_back(Square(sf::Vector2f(0, 400), sf::IntRect(0, 400, 200, 200)));
    squares.emplace_back(Square(sf::Vector2f(200, 400), sf::IntRect(200, 400, 200, 200)));
    squares.emplace_back(Square(sf::Vector2f(400, 400), sf::IntRect(400, 400, 200, 200)));
}



void Game::CheckEventSquare(sf::Window *window, Board *board)
{
    for (auto &square : squares)
        square.checkIsClicked(window, board);
}

void Game::displaySquares(sf::RenderWindow *window)
{
    for (auto &square : squares)
        square.display(window);
}

void Game::processEvents()
{
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update(sf::Window *window, Board *board)
{
    CheckEventSquare(window, board);
}

void Game::render(Board *board)
{
    window.clear(sf::Color(115, 115, 115));
    displaySquares(&window);
    text.setFont(font);
    if (board->turn == 0)
        text.setString(board->player1->name);
    else
        text.setString(board->player2->name);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Black);
    text.setPosition(window.getSize().x / 2 - text.getGlobalBounds().width / 2, window.getSize().y - text.getGlobalBounds().height - 40);
    window.draw(text);
    window.display();
}

void Game::run(Board *board)
{
    while (window.isOpen()) {
        processEvents();
        update(&window, board);
        render(board);
        if (board->checkWin())
            break;
    }
    board->turn ^= 1;
    while (window.isOpen()) {
        processEvents();
        window.clear(sf::Color(115, 115, 115));
        if (board->turn == 0)
            text.setString(board->player1->name + " wins");
        else
            text.setString(board->player2->name + " wins");
        text.setCharacterSize(30);
        text.setFillColor(sf::Color::Black);
        text.setPosition(window.getSize().x / 2 - text.getGlobalBounds().width / 2, window.getSize().y / 2 - text.getGlobalBounds().height / 2);
        window.draw(text);
        window.display();
    }
}