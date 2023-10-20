#include "Circle.h"
#include <cmath>

using namespace std;

Circle::Circle(sf::Vector2f pos, float radius, sf::Color color) {
  _pos = pos;
  _radius = radius;
  _color = color;
  vertexes.setPrimitiveType(sf::PrimitiveType::TriangleFan);
  createVertexes();
}

void Circle::createVertexes() {
  vertexes.clear();
  vertexes.append(
      sf::Vertex(sf::Vector2f(_pos.x - _radius / 3, _pos.y - _radius / 2),
                 sf::Color::White));

  for (int i = 0; ++i <= 361;) {
    vertexes.append(
        sf::Vertex(sf::Vector2f(_radius * cos(i * M_PI / 180) + _pos.x,
                                _radius * sin(i * M_PI / 180) + _pos.y),
                   _color));
  }
}
void Circle::draw(sf::RenderWindow &window) { window.draw(vertexes); }

void Circle::move(sf::Vector2f toMoveBy) {
  for (int i = 0; ++i < vertexes.getVertexCount();) {
    vertexes[i].position += toMoveBy;
  }
}

void Circle::setFillColor(sf::Color color) {
  for (int i = 1; ++i < vertexes.getVertexCount();) {
    vertexes[i].color = color;
  }
}

void Circle::setRadius(int radius) {
  _radius = radius;
  createVertexes();
}

void Circle::setPosition(sf::Vector2f pos) {
  _pos = pos;
  createVertexes();
}

sf::Vector2f Circle::getPosition() { return _pos; }