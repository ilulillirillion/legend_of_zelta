#include "SFML/Graphics.hpp"


struct Tile {
  sf::Sprite mTileSprite;
  bool mSolidState;
}


class TileEngine {
public:
  TileEngine();
  // Generate from a file
  TileEngine(std::string pFileLocation);
  // Generate from parameters
  TileEngine(float pTileWidth, float pTileHeight, unsigned int pMapSizeX, unsigned int pMapSizeY, sf::Texture pTileSet, std::vector<std::vector<int> >& pTileIDVec, std::vector<std::vector<bool> >& pSolidStateVec, float pPosX = 0, float pPosY = 0);
  // Generate from an already generated tile vector
  TileEngine(float pTileWidth, float pTileHeight, unsigned int pMapSizeX, unsigned int pMapSizeY, sf::Texture pTileSet, std::vector<std::vector<Tile> > pTiles, float pPosX = 0, flaot pPosY = 0);
  ~TileEngine();

  // Getters
  float GetPosX() { return mPosX; }
  float GetPosY() { return mPosY; }
  float GetTileWidth() { return mTileWidth; }
  float GetTileHeight() { return mTileHeight; }
  float GetSizeX() { return mMapSizeX; }
  float GetSizeY() { return mMapSizeY; }
  std::vector<std::vector<Tile> >& GetTiles() { return mTiles; }

  // Setters
  void SetPosX(float pPosX) { mPosX = pPosX; }
  void SetPosY(float pPosY) { mPosY = pPosY; }
  void SetTiles(std::vector<std::vector<Tile> >& pTiles) { mTiles = pTilesl }

  // Public member functions
  void LoadFromFile(std::string pFileLocation);
  void LoadFromParam(float pTileWidth, float pTileHeight, unsigned int pMapSizeX, unsigned int pMapSizeY, sf::Texture pTileSet, std::vector<std::vector<int> >& pTileIDVec, std::vector<std::vector<bool> >& pSolidStateVec, float pPosX = 0, float pPosY = 0);
  void LoadFromTiles(float pTileWidth, float pTileHeight, unsigned int pMapSizeX, unsigned int pMapSizeY, sf::Texture pTileSet, std::vector<std::vector<Tile> >& pTiles, float pPosX = 0, float pPosY = 0);
  void Render(sf::RenderWindow* pTarget);
  bool CheckSolid(float px, float py);

private:
  void UpdateTileSpritePos();

  // Private member variables
  float mPosX, mPosY;
  float mTileWidth, mTileHeight;
  unsigned int mMapSizeX, mMapSizeY;
  sf::Texture mTileSet;
  std::vector<std::vector<Tile> > mTiles;
};


#endif
