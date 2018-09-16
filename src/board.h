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

    void moveCursor(uint16_t x, uint16_t y);
    void handleCursor();
    void drawCursor(uint16_t cameraX, uint16_t cameraY);

  private:
    uint16_t width;
    uint16_t height;

    uint16_t cursorX;
    uint16_t cursorY;

    Tile*** tiles;
};

#endif
