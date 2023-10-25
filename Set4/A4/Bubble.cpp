#include "Bubble.h"

using namespace std;

Bubble::Bubble(const int RADIUS, const sf::Vector2f POS, const sf::Vector2f VEL,
               const uint16_t ALPHA) {
  _vel = VEL;
  _color = sf::Color(rand(), rand(), rand(), ALPHA);
  _radius = RADIUS;
  _diameter = RADIUS * 2;
  _circle.setRadius(_radius);
  _circle.setFillColor(_color);
  _circle.setPosition(POS);
  _circle.setAlpha(ALPHA);
}

Bubble::~Bubble() { _circle.~Circle(); }

void Bubble::bounce(const sf::Vector2u WINSIZE) {
  if (_circle.getPosition().x + _radius >= WINSIZE.x ||
      _circle.getPosition().x - _radius <= 0) {
    _vel = sf::Vector2f(-1 * _vel.x, _vel.y);
  }
  if (_circle.getPosition().y + _radius >= WINSIZE.y ||
      _circle.getPosition().y - _radius <= 0) {
    _vel = sf::Vector2f(_vel.x, -1 * _vel.y);
  }
}

void Bubble::move(const sf::Vector2u WINSIZE) {
  bounce(WINSIZE);
  _circle.move(_vel);
}

void Bubble::draw(sf::RenderWindow &window) { _circle.draw(window); }

void Bubble::reflect(sf::Vector2i mousePosition, sf::Vector2u screenSize) {
  _circle.reflect(mousePosition, screenSize);
}