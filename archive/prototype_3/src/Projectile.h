#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED


#include "Entity.h"
#include "FunctionLib.h"
#include <cmath>
#include <SFML/Graphics.hpp>


class Projectile : public Entity {
public:
  // Constructor and destructor
  Projectile();
  // Can give projectile a direction and speed
  Projectile(float px, float py, float pDirection, float pVelocity, float pDamage, sf::Texture mSpriteTexture);
  ~Projectile();

  // Getters
  float GetVelX() { return VelX; }
  float GetVelY() { return VelY; }
  float GetDamage() { return mDamage; }
  sf::Sprite GetSprite() { return mSprite; }
  float GetDirection() { return mDirection; }

  // Setters
  void SetVelX(float pVelX) { VelX = pVelX; }
  void SetVelY(float pVelY) { VelY = pVelY; }
  void SetDamage(float pDamage) { mDamage = pDamage; }
  void SetSprite(sf::Sprite pSprite) { mSprite = pSprite; }
  void SetDirection(float pDirection);
  void SetTexture(sf::Texture pTexture);

  // Public member functions
  void Render(sf::RenderWindow* pTarget) { pTarget->draw(mSprite); }
  void Update(float TimeStep);

private:
  // Private member functions
  void UpdateSprite();
  void CalculateVelocities(float pDirection, float pVelocity);

  // Private member variables
  float mDirection;
  float VelX, VelY;
  float mDamage;
  sf::Texture mSpriteTexture;
  sf::Sprite mSprite;
};


#endif
