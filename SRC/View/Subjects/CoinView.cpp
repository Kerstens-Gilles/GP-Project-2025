#include "./CoinView.h"

#include <SFML/Graphics.hpp>

using namespace Display;

Coin::Coin(float x, float y, int screenSize) : Subject(x, y, screenSize, 0.25) {
    sub->setFillColor(sf::Color(150, 150, 0));
}