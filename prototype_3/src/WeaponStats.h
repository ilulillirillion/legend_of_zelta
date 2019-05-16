#ifndef WEAPONSTATS_H_INCLUDED
#define WEAPONSTATS_H_INCLUDED


#include <SFML/Graphics.hpp>


struct WeaponStats {
  float mDamage;
  float mBulletSpeed;
  float mFireRate;
  float mBulletSpred;
  sf::Texture mBulletTexture;
};


enum WeaponTypes {
  RifleWeapon,
  SMGWeapon,
  ShotGunWeapon,
};


WeaponStats GetWeaponStat(WeaponTypes WeaponID);


#endif
