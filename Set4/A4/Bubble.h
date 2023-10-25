#ifndef BUBBLE_H
#define BUBBLE_H
#include "Circle.h"
#include <SFML\Graphics.hpp>
#include <random>
class Bubble {
private:
  sf::Vector2f _vel;
  sf::Color _color;
  int _radius;
  int _diameter;
  int _outlineThickness = 3;
  Circle _circle;

public:
  Bubble(const int, const sf::Vector2f, const sf::Vector2f, uint16_t);
  ~Bubble();
  void move(const sf::Vector2u);
  void bounce(const sf::Vector2u);
  void draw(sf::RenderWindow &);
  void reflect(sf::Vector2i, sf::Vector2u);
};

#endif