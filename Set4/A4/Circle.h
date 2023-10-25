#ifndef CIRCLE_H
#define CIRCLE_H

#include <SFML\Graphics.hpp>

class Circle {
private:
  sf::Vector2f _pos;
  sf::VertexArray vertices;
  int _radius;
  sf::Color _color;
  uint16_t _alpha;
  void createVertices();

public:
  Circle();
  Circle(sf::Vector2f, float, sf::Color, uint16_t);
  ~Circle();
  void draw(sf::RenderWindow &);
  void move(sf::Vector2f);
  void setFillColor(sf::Color);
  void setRadius(int);
  void setPosition(sf::Vector2f);
  void setAlpha(uint16_t);
  void reflect(sf::Vector2i, sf::Vector2u);
  sf::Vector2f getPosition();
  sf::Color brightnessLerp(sf::Color, sf::Color, float);
};

#endif