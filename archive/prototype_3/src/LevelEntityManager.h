#ifndef LEVELENTITYMANAGER_H
#define LEVELENTITYMANAGER_H


#include "PlayerCharacter.h"
#include "TileEngine.h"
#include <SFML/Graphics.hpp>


class LevelEntityManager {
public:
  LevelEntityManager();
  ~LevelEntityManager();

  sf::RenderWindow* GetTarget() { return mpTarget; }
  TileEngine GetTileEngine() { return mTileEngine; }
  PlayerCharacter GetPlayer() { return mPlayer; }

  void SetTarget(sf::RenderWindow* val) { mpTarget = val; }
  void SetTileEngine(TileEngine val) { mTileEngine = val; }
  void SetPlayer(PlayerCharacter val) { mPlayer = val; }

  void Render();
  void Update(KeyState pKeyState);

private:
  bool CheckTileSolidCollision(std::vector<sf::Vector2f> CornerPoints);
  sf::Vector2f GetPlayerNewPosition(PlayerCharacter pPlayer, KeyState pKeyState);

  sf::RenderWindow* mpTarget;
  TileEngine mTileEngine;
  PlayerCharacter mPlayer;

  sf::Clock mFrameClock;
  float mFrameTime;
};


#endif
