#ifndef FUNCTIONLIB_H
#define FUNCTIONLIB_H


// Required headers
#include "Entity.h"
#include "SFML/Graphics.hpp"


// Required preprocessor macros
#define _PI 3.14159265


// Member functions
float DistanceBetween(float px1, float py1, float px2, float py2);
float DistanceBetween(Entity* pEntity1, Entity* pEntity2);
float ToDegrees(float radians);
float ToRadians(float degrees);
// Returns in radians the angle from a(x,y) to b(x,y)
float DirectionToPoint(float ax, float ay, float bx, float by);
// Returns in radians the angle from a to b
float DirectionToPoint(Entity* a, Entity* b);

std::vector<sf::Vector2f> GenerateBoxFromSprite(sf::Sprite pSprite);
std::vector<sf::Vector2f> GenerateBoxFromDimensions(float px, float py, float width, float height);

#endif
