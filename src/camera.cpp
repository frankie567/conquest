#include <Gamebuino-Meta.h>
#include "camera.h"
#include "constants.h"

#define CAMERAL_CONTROL_HOLD_TIME 13

Camera::Camera(uint8_t width, uint8_t height, Board* board): width(width), height(height), board(board) {
  x = 0;
  y = 0;
}

void Camera::move(uint16_t x, uint16_t y) {
  if (x >= 0 && x <= board->getWidth() * TILE_WIDTH - width) {
    this->x = x;
  }

  if (y >= 0 && y <= board->getHeight() * TILE_HEIGHT - height) {
    this->y = y;
  }
}

void Camera::draw() {
  uint16_t minTileX = x / TILE_WIDTH;
  uint16_t minTileY = y / TILE_HEIGHT;
  uint16_t maxTileX = min(getMaxX() / TILE_WIDTH + 1, board->getWidth());
  uint16_t maxTileY = min(getMaxY() / TILE_HEIGHT + 1, board->getHeight());

  for (uint16_t i = minTileX; i < maxTileX; i++) {
    for (uint16_t j = minTileY; j < maxTileY; j++) {
      Tile* tile = board->getTile(i, j);
      int8_t tileX = i * TILE_WIDTH - x;
      int8_t tileY = j * TILE_HEIGHT - y;
      tile->draw(tileX, tileY, i, j);
    }
  }

  board->drawCursor(x, y);
}

void Camera::control() {
  if (gb.buttons.timeHeld(BUTTON_UP) > CAMERAL_CONTROL_HOLD_TIME) {
    move(x, y - 1);
  }

  if (gb.buttons.timeHeld(BUTTON_RIGHT) > CAMERAL_CONTROL_HOLD_TIME) {
    move(x + 1, y);
  }

  if (gb.buttons.timeHeld(BUTTON_LEFT) > CAMERAL_CONTROL_HOLD_TIME) {
    move(x - 1, y);
  }

  if (gb.buttons.timeHeld(BUTTON_DOWN) > CAMERAL_CONTROL_HOLD_TIME) {
    move(x, y + 1);
  }

  if (gb.buttons.pressed(BUTTON_MENU)) {
    move(0, 0);
  }

  draw();
}

uint16_t Camera::getMaxX() {
  return x + width;
}

uint16_t Camera::getMaxY() {
  return y + height;
}
