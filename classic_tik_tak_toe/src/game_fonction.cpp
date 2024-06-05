
#include "../header/tic_tac_toe.h"
#include "../header/class.h"

Game::Game() : window(sf::VideoMode(800, 600), "SFML window") {}
Game::Game(int size_x, int size_y, char *name) : window(sf::VideoMode(size_x, size_y), name) {}

void Game::run()
{
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update()
{
}

void Game::render()
{
    window.clear(sf::Color::Blue);
    window.display();
}