#ifndef TILE_H
#define TILE_H

#include <stdint.h>

enum Terrain {
  GRASS,
};

class Tile {
  public:
    Tile();
    Terrain getTerrain();
    void draw(int8_t x, int8_t y, int8_t tx, int8_t ty);

  private:
    Terrain terrain;
};

#endif
