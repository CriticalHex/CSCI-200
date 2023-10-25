#include "Circle.h"
#include <cmath>

using namespace std;

Circle::Circle() {
  vertices.setPrimitiveType(sf::PrimitiveType::TriangleFan);
  _radius = 0;
}

Circle::Circle(sf::Vector2f pos, float radius, sf::Color color,
               uint16_t alpha) {
  _pos = pos;
  _radius = radius;
  _color = color;
  _alpha = alpha;
  vertices.setPrimitiveType(sf::PrimitiveType::TriangleFan);
  createVertices();
}

Circle::~Circle() {
  vertices.clear();
  vertices.resize(0);
}

void Circle::createVertices() {
  double pi = 3.14159265358979;
  vertices.clear();
  vertices.append(
      sf::Vertex(sf::Vector2f(_pos.x - _radius / 3, _pos.y - _radius / 2),
                 sf::Color(255, 255, 255, _alpha)));

  for (int i = 0; ++i <= 361;) {
    vertices.append(
        sf::Vertex(sf::Vector2f(_radius * cos(i * pi / 180) + _pos.x,
                                _radius * sin(i * pi / 180) + _pos.y),
                   _color));
  }
}
void Circle::draw(sf::RenderWindow &window) { window.draw(vertices); }

void Circle::move(sf::Vector2f toMoveBy) {
  _pos += toMoveBy;
  for (uint64_t i = 0; i < vertices.getVertexCount(); i++) {
    vertices[i].position += toMoveBy;
  }
}

void Circle::setFillColor(sf::Color color) {
  _color = color;
  for (uint64_t i = 1; i < vertices.getVertexCount(); i++) {
    vertices[i].color = _color;
  }
}

void Circle::setRadius(int radius) {
  _radius = radius;
  createVertices();
}

void Circle::setPosition(sf::Vector2f pos) {
  _pos = pos;
  createVertices();
}

void Circle::setAlpha(uint16_t alpha) {
  _alpha = alpha;
  createVertices();
}

sf::Vector2f Circle::getPosition() { return _pos; }

sf::Color Circle::brightnessLerp(sf::Color start, sf::Color stop, float t) {
  return t > 1 ? stop
               : sf::Color(int(start.r + (stop.r - start.r + 1) * t),
                           int(start.g + (stop.g - start.g + 1) * t),
                           int(start.b + (stop.b - start.b + 1) * t), _alpha);
}

void Circle::reflect(sf::Vector2i mousePosition, sf::Vector2u screenSize) {
  float distx = _pos.x - mousePosition.x;
  float disty = _pos.y - mousePosition.y;
  float dist = pow((pow(distx, 2) + pow(disty, 2)), .5);
  float maxDist = pow((pow(screenSize.x, 2) + pow(screenSize.y, 2)), .5) -
                  screenSize.x / 3; // gets darker faster
  short int sign = distx < 0 ? 1 : -1;
  float angle = distx == 0 ? 0 : atan(disty / distx);
  vertices[0].position =
      sf::Vector2f(sign * ((_radius / 2.f) * cos(angle)) + _pos.x,
                   sign * ((_radius / 2.f) * sin(angle)) + _pos.y);
  vertices[0].color = brightnessLerp(sf::Color::White, _color, dist / maxDist);
}