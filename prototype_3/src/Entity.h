#ifndef ENTITY_H
#define ENTITY_H

#include <cmath>

class Entity {
public:
  Entity();
  Entity(float px, float py) : mPosX(px), mPosY(py) {}
  ~Entity();

  // Getters
  float GetPosX() { return mPosX; }
  float GetPosY() { return mPosY; }

  // Setters
  void SetPosX(float val) { mPosX = val; }
  void SetPoxY(float val) { mPosY = val; }

protected:
  float mPosX;
  float mPosy;
};

#endif
