#include <Gamebuino-Meta.h>
#include "constants.h"
#include "cursor.h"

Cursor::Cursor(Board* board): board(board) {
  move(0, 0);
}

void Cursor::move(uint16_t x, uint16_t y) {
  if (x >= 0 && x < board->getWidth()) {
    this->x = x;
  }

  if (y >= 0 && y < board->getHeight()) {
    this->x = y;
  }
}

void Cursor::control() {
  if (gb.buttons.pressed(BUTTON_UP)) {
    move(x, y - 1);
  }

  if (gb.buttons.pressed(BUTTON_RIGHT)) {
    move(x + 1, y);
  }

  if (gb.buttons.pressed(BUTTON_LEFT)) {
    move(x - 1, y);
  }

  if (gb.buttons.pressed(BUTTON_DOWN)) {
    move(x, y + 1);
  }
}

void Cursor::draw(Camera* camera) {
  gb.display.setColor((gb.frameCount % 8) >= 4 ? Gamebuino_Meta::Color::white : Gamebuino_Meta::Color::black);
  gb.display.drawRect(x * TILE_WIDTH - camera->getX(), y * TILE_HEIGHT - camera->getY(), TILE_WIDTH, TILE_HEIGHT);
}
