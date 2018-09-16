#ifndef BOARD_H
#define BOARD_H

#include <stdint.h>
#include "tile.h"

class Board {
  public:
    Board(uint16_t width, uint16_t height);
    uint16_t getWidth();
    uint16_t getHeight();
    Tile* getTile(uint16_t x, uint16_t y);

  private:
    uint16_t width;
    uint16_t height;

    Tile*** tiles;
};

#endif
