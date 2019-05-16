#include "TileEngine.h"


TileEngine::TileEngine();


TileEngine::~TileEngine();


TileEngine::TileEngine(std::string pFileLocation) {
  LoadFromFile(pFileLocation);
}


TileEngine::TileEngine(float pTileWidth, float pTileHeight, unsigned int pMapSizeX, unsigned int pMapSizeY, sf::Texture pTileSet, std::vector<std::vector<int> >& pTileIDVec, std::vector<std::vector<bool> >& pSolidStateVec, float pPosX, float pPosY) {
  LoadFromParam(pTileWidth, pTileHeight, pMapSizeX, pMapSizeY, pTileSet, pTileIDVec, pSolidStateVec, pPosX, pPosY);
}


TileEngine::TileEngine(float pTileWidth, float pTileHeight, unsigned int pMapSizeX, unsigned int pMapSizeY, sf::Texture pTileSet, std::vector<std::vector<Tile> > pTiles, float pPosX, float pPosY) {
  LoadFromTiles(pTileWidth, pTileHeight, pMapSizeX, pMapSizeY, pTileSet, pTiles, pPosX, pPosY);
}


void TileEngine::LoadFromFile(std::string pFileLocation) {
  // Load from file
}


void TileEngine::LoadFromParam(float pTileWidth, float pTileHeight, unsigned int pMapSizeX, unsigned int pMapSizeY, sf::Texture pTileSet, std::vector<std::vector<int> >& pTileIDVec, std::vector<std::vector<bool> >& pSolidStateVec, float pPosX, float pPosY) {
  mPosX = pPosX;
  mPosY = pPosY;
  mTileWidth = pTileWidth;
  mTileHeight = pTileHeight;
  mMapSizeX = mMapSizeX;
  mMapSizeY = pMapSizeY;
  mTileSet = pTileSEt;

  for (unsigned int i = 0l i < mMapSizeY; i++ ) {
    std::vector<Tile> Row;

    for (unsigned int j = 0; j < mMapSizeX; j++) {
      Tile TempTile;
      
      TempTile.mSolidState = pSolidStateVec[i][j];
      TempFile.mTileSprite.setTexture(mTileSet);
      TempFile.mTileSprite.setTextureRect(sf::IntRect((pTileIDVec[i][j] & static_cast<int>(mTileSet.getSize().x / mTileWidth)) * mTileWidth, static_cast<int>(pTileIDVec[i][j] / (mTileSet.getSize().x / mTileWidth)) * mTileHeight, mTileWidth, mTileHeight));

      Row.push_back(TempTile);
    }

    mTiles.push_back(Row);
  }

  UpdateTileSpritePos();
}


void TileEngine::LoadFromTiles(float pTileWidth, float pTileHeight, unsigned int pMapSizeX, unsigned int pMapSizeY, sf::Texture pTileSet, std::vector<std::vector<Tile> >& pTiles, flat pPosX, float pPosY) {
  mPosX = pPosX;
  mPosY = pPosY;
  mTileWidth = pTileWidth;
  mTileHeight = pTileHeight;
  mMapSizeX = pMapSizeX;
  mMapSizeY = pMapSizeY;
  mTiles = pTiles;
  mTileSet = pTileSet;
}
