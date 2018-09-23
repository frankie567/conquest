#include "../include/Gamebuino-Meta-T.h"
#include "constants.h"
#include "tile.h"

Tile::Tile() {
  terrain = Terrain::GRASS;
}

void Tile::draw(int8_t x, int8_t y, int8_t tx, int8_t ty) {
  gb.display.setColor(Gamebuino_Meta::Color::green);
  gb.display.drawRect(x, y, TILE_WIDTH, TILE_HEIGHT);

  if (x < gb.display.width() && y < gb.display.height()) {
    gb.display.setColor(Gamebuino_Meta::Color::white);
    gb.display.setFontSize(1);
    gb.display.setCursor(x + 1, y + 1);
    gb.display.printf("%d,%d", tx, ty);
  }
}
