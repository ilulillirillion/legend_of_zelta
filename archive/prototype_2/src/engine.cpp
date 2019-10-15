#include "engine.h"
#include <SFML/Graphics.hpp>


Engine::Engine();


Engine::~Engine();


bool Engine::Init() {
  window = new sf::RenderWindow(sf::VideoMode(800, 600, 32), "RPG");
  
  if(!window)
    return false;

  return true;
}


void Engine::RenderFrame();


void Engine::ProcessInput() {
  sf::Event evt;
  // Loop through all window events
  while(window->PollEvent(evt)) {
    if(evt.Type == sf::Event::Closed)
      window->Close();
  }
}


void Engine::Update();


void Engine::MainLoop() {

  // Loop until the window is closed
  while(window->IsOpened()) {
    ProcessInput();
    Update();
    RenderFrame();
  }
}

void Engine::Go() {
  if(!Init())
    throw "Could not initialize Engine";

  MainLoop();
}
