#include <Gamebuino-Meta.h>
#include <stdlib.h>
#include "board.h"
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
  moveCursor(0, 0);
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

void Board::moveCursor(uint16_t x, uint16_t y) {
  if (x >= 0 && x < getWidth()) {
    this->cursorX = x;
  }

  if (y >= 0 && y < getHeight()) {
    this->cursorY = y;
  }
}

void Board::handleCursor() {
  if (gb.buttons.pressed(BUTTON_UP)) {
    moveCursor(cursorX, cursorY - 1);
  }

  if (gb.buttons.pressed(BUTTON_RIGHT)) {
    moveCursor(cursorX + 1, cursorY);
  }

  if (gb.buttons.pressed(BUTTON_LEFT)) {
    moveCursor(cursorX - 1, cursorY);
  }

  if (gb.buttons.pressed(BUTTON_DOWN)) {
    moveCursor(cursorX, cursorY + 1);
  }
}

void Board::drawCursor(uint16_t cameraX, uint16_t cameraY) {
  gb.display.setColor((gb.frameCount % 8) >= 4 ? Gamebuino_Meta::Color::white : Gamebuino_Meta::Color::black);
  gb.display.drawRect(cursorX * TILE_WIDTH - cameraX, cursorY * TILE_HEIGHT - cameraY, TILE_WIDTH, TILE_HEIGHT);
}
