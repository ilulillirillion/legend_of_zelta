#include "LevelEntityManager.h"


LevelEntityManager::LevelEntityManager();


LevelEntityManager::~LevelEntityManager();


void LevelEntityManager::Update(KeyState pKeyState) {
  mFrameTime = mFrameClock.restart().asSeconds();

  sf::Vector2f NewPlayerPos = GetPlayerNewPosition(mPlayer, pKeyState);
  sf::Vector2f NewPlayerSpritePos = sf::Vector2f(NewPlayerPosx - mPlayer.getSprite().getOrigin().x, NewPlayerPos.y - mPlayer.GetSprite().getOrigin().y);

  mPlayer.SetDirection(ToDegrees(DirectionToPoint(mPlayer.GetPosX(), mPlayer.GetPosY(), sf::Mouse::getPosition(*mpTarget).x, sf::Mouse::getPosition(*mpTarget).y)));
  mPlayer.Update(mFrameTime, pKeyState, CheckTileSolidCollision(GenerateBoxFromDimensions(NewPlayerSpritePos.x, NewPlayerSpritePos.y, mPlayer.GetTexture().getSize().x, mPlayer.GetTexture().getSize().y)));
}


sf::Vector2f LevelEntityManager::GetPlayerNewPosition(PlayerCharacter pPlayer, KeyState pKeyState) {
  float NewPlayerX = pPlayer.GetPosX();
  float NewPlayerY = pPlayer.getPosY();

  if (pKeyState.UpPressed)
    NewPlayerY -= pPlayer.GetSpeed() * mFrameTime;
  if (pKeyState.DownPressed)
    NewPlayerY += pPlayer.GetSpeed() * mFrameTime;
  if (pKeyState.LeftPressed)
    NewPlayerX -= pPlayer.GetSpeed() * mFrameTime;
  if (pKeyState.RightPressed)
    NewPlayerX += pPlayer.GetSpeed() * mFrameTime;

  sf::Vector2f NewPlayerPos(NewPlayerX, NewPlayerY);

  return NewPlayerPos;
}


void LevelEntityManager::Render() {
  // Order of rendering is important
  mTileEngine.Render(mpTarget);
  mPlayer.Render(mpTarget);
}


bool LevelEntityManager::CheckTileSolidCollision(std::vector<sf::Vector2f> CornerPoints) {
  for (int i = 0; i < CornerPoints.size(); i++) {
    if (mTileEngine.CheckSolid(CornerPoints[i].x, CornerPoints[i].y))
      return true;
  }
  return false;
}
