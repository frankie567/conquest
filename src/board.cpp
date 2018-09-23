#include <algorithm>
#include "board.h"
#include "camera.h"
#include "constants.h"
#include "tile.h"

Board::Board(uint16_t width, uint16_t height): width(width), height(height) {
  tiles = new Tile**[width];
  for (uint16_t x = 0; x < width; x++) {
    tiles[x] = new Tile*[height];
    for (uint16_t y = 0; y < height; y++) {
      tiles[x][y] = new Tile();
    }
  }
}

uint16_t Board::getWidth() {
  return width;
}

uint16_t Board::getHeight() {
  return height;
}

Tile* Board::getTile(uint16_t x, uint16_t y) {
  return tiles[x][y];
}

void Board::draw(Camera* camera) {
  uint16_t minTileX = camera->getX() / TILE_WIDTH;
  uint16_t minTileY = camera->getY() / TILE_HEIGHT;
  uint16_t maxTileX = std::min(uint16_t(camera->getMaxX() / TILE_WIDTH + 1), getWidth());
  uint16_t maxTileY = std::min(uint16_t(camera->getMaxY() / TILE_HEIGHT + 1), getHeight());

  for (uint16_t i = minTileX; i < maxTileX; i++) {
    for (uint16_t j = minTileY; j < maxTileY; j++) {
      Tile* tile = getTile(i, j);
      int8_t tileX = i * TILE_WIDTH - camera->getX();
      int8_t tileY = j * TILE_HEIGHT - camera->getY();
      tile->draw(tileX, tileY, i, j);
    }
  }
}
