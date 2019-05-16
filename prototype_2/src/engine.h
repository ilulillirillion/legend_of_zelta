#ifndef _ENGINE_H
#define _ENGINE_H

#include <SFML/Graphics.hpp>

class Engine {
private:
  // SFML render window
  sf::RenderWindow* window;

  // Initialize the game engine
  bool Init();

  // Main game loop
  void MainLoop();

  // Render one frame
  void RenderFrame();

  // Process user input
  void ProcessInput();

  // Update all engine internals
  void Update();
public:
  Engine();
  ~Engine();

  // Start the engine
  void Go();
};
