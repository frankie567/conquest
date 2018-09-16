#include <Gamebuino-Meta.h>
#include <stdlib.h>
#include "board.h"
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
