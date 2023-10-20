#ifndef CIRCLE_H
#define CIRCLE_H

#include <SFML\Graphics.hpp>

class Circle {
private:
  sf::Vector2f _pos;
  sf::VertexArray vertexes;
  int _radius;
  sf::Color _color;
  void createVertexes();

public:
  Circle(sf::Vector2f, float, sf::Color);
  void draw(sf::RenderWindow &);
  void move(sf::Vector2f);
  void setFillColor(sf::Color);
  void setRadius(int);
  void setPosition(sf::Vector2f);
  sf::Vector2f getPosition();
};

#endif