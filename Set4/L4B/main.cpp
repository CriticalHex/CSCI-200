#include <SFML\Graphics.hpp>
#include <ctime>
#include <iostream>
#include <math.h>
#include <random>
#include <vector>

float pi = 3.14159265358979;

class Circle {
public:
  sf::Vector2f _pos;
  sf::VertexArray vertices;

  Circle(sf::Vector2f pos, float radius) { // constructor
    _pos = pos;

    vertices.setPrimitiveType(sf::PrimitiveType::TriangleFan);
    vertices.append(
        sf::Vertex(sf::Vector2f(_pos.x - radius / 3, _pos.y - radius / 2),
                   sf::Color::White));

    for (int i = 0; ++i <= 361;) {
      vertices.append(
          sf::Vertex(sf::Vector2f(radius * cos(i * pi / 180) + _pos.x,
                                  radius * sin(i * pi / 180) + _pos.y),
                     sf::Color::Green));
    }
  }
  void draw(sf::RenderWindow &window) { window.draw(vertices); }

  void setColor() {
    // vertexes[0].color = sf::Color(rand(), rand(), rand());
  }
};

int main() {
  srand(time(NULL));

  sf::RenderWindow window(sf::VideoMode(1920, 1080), "Squares",
                          sf::Style::Fullscreen);
  window.setFramerateLimit(60);

  Circle shape(1920 / 2, 1080 / 2, 250);

  while (window.isOpen()) {
    // Process events-------------------------------------------
    sf::Event event;
    while (window.pollEvent(event)) {
      // Close window: exit-----------------------------------
      if (event.type == sf::Event::Closed)
        window.close();
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
        window.close();
      }
    }

    window.clear();
    shape.draw(window);
    window.display();
  }
}