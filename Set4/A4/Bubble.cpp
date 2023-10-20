#include "Bubble.h"

using namespace std;

Bubble::Bubble(const int radius, const sf::Vector2f POS,
               const sf::Vector2f VEL) {
  _vel = VEL;
  _color = sf::Color(rand(), rand(), rand());
  _radius = radius;
  _diameter = radius * 2;
  _circle.setRadius(_radius);
  _circle.setFillColor(sf::Color::Transparent);
  _circle.setOutlineColor(_color);
  _circle.setOutlineThickness(_outlineThickness);
  _circle.setPosition(POS);
}

Bubble::~Bubble() {}

void Bubble::bounce(const sf::Vector2u WINSIZE) {
  if (_circle.getPosition().x + _diameter + _outlineThickness >= WINSIZE.x ||
      _circle.getPosition().x - _outlineThickness <= 0) {
    _vel = sf::Vector2f(-1 * _vel.x, _vel.y);
  }
  if (_circle.getPosition().y + _diameter + _outlineThickness >= WINSIZE.y ||
      _circle.getPosition().y - _outlineThickness <= 0) {
    _vel = sf::Vector2f(_vel.x, -1 * _vel.y);
  }
}

void Bubble::move(const sf::Vector2u WINSIZE) {
  bounce(WINSIZE);
  _circle.move(_vel);
}

void Bubble::draw(sf::RenderWindow &window) { window.draw(_circle); }
