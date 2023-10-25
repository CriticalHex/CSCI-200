#include "Bubble.h"
#include <SFML\Graphics.hpp>
#include <ctime>
#include <iostream>
#include <random>
#include <thread>
#include <vector>

using namespace std;

int randint(const int MIN, const int MAX) {
  const int RANDOM = MIN + (rand() % (MAX - MIN + 1));
  // the +1 is to allow the max number to be generated
  return RANDOM;
}

float randfloat(const float MIN, const float MAX) {
  const float RANDOM = MIN + (rand() / (float)RAND_MAX) * (MAX - MIN);
  return RANDOM;
}

sf::Vector2f randvec(const float MIN, const float MAX) {
  return sf::Vector2f(randfloat(MIN, MAX), randfloat(MIN, MAX));
}

sf::Vector2f randvec(const float MINX, const float MAXX, const float MINY,
                     const float MAXY) {
  return sf::Vector2f(randfloat(MINX, MAXX), randfloat(MINY, MAXY));
}

Bubble *create_random_bubble(sf::Vector2f position) {
  return new Bubble(randint(10, 50), position, randvec(-0.1667f, 0.1667f), 150);
}

void update_bubbles(vector<Bubble *> &bubbles, uint32_t start, uint32_t stop,
                    sf::Vector2u windowSize, sf::Vector2i mouseOffset) {
  for (uint32_t i = start; i < stop; i++) {
    bubbles[i]->move(windowSize);
    bubbles[i]->reflect(mouseOffset, windowSize);
  }
}

int main(int argc, char **argv) {
  srand(time(NULL));

  sf::RenderWindow window(sf::VideoMode(1920, 1080), "Bubbles!",
                          sf::Style::None);
  sf::Color bgColor = sf::Color(6, 8, 12);
  sf::Event event;
  sf::Vector2i offset;

  vector<Bubble *> bubbles;
  vector<thread> threads;

  // uint32_t start;
  // uint32_t stop;

  if (argc > 1 && string(*(argv + 1)) == "screensaver") {
    window.create(sf::VideoMode(1920 * 3, 1080), "Bubbles!", sf::Style::None);
    offset = sf::Vector2i(1920, 0);
    int max_width = window.getSize().x - 51;  // don't want to spawn in wall
    int max_height = window.getSize().y - 51; // don't want to spawn in cieling
    for (int i = 0; ++i < 20000;) {
      bubbles.push_back(
          create_random_bubble(randvec(51, max_width, 51, max_height)));
    }
  } else {
    for (int i = 0; ++i < 5;) {
      bubbles.push_back(create_random_bubble(randvec(100.f, 400.f)));
    }
  }

  window.setFramerateLimit(60);

  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      // Close window: exit-----------------
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        window.close();
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        window.close();
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if (bubbles.size() != 0)
          delete bubbles.at(bubbles.size() - 1);
        bubbles.pop_back();
      }

      if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        bubbles.push_back(create_random_bubble(
            sf::Vector2f(sf::Mouse::getPosition() + offset)));
      }
    }

    // for (int i = 0; i < 1; i++) {
    //   start = 0;
    //   stop = bubbles.size();
    threads.emplace_back(update_bubbles, ref(bubbles), 0, bubbles.size() / 2,
                         window.getSize(), sf::Mouse::getPosition() + offset);
    threads.emplace_back(update_bubbles, ref(bubbles), bubbles.size() / 2 + 1,
                         bubbles.size(), window.getSize(),
                         sf::Mouse::getPosition() + offset);
    // }

    for (auto &t : threads) {
      if (t.joinable()) {
        t.join();
      }
    }

    window.clear(bgColor);

    for (Bubble *bubble : bubbles) {
      bubble->draw(window);
    }

    window.display();
  }

  for (Bubble *bubble : bubbles) {
    delete bubble;
    bubble = nullptr;
  }
  bubbles.clear();

  return 0;
}