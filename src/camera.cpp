#include <Gamebuino-Meta.h>
#include "camera.h"
#include "constants.h"

Camera::Camera(uint8_t screenWidth, uint8_t screenHeight, uint16_t boardWidth, uint16_t boardHeight):
  screenWidth(screenWidth), screenHeight(screenHeight), boardWidth(boardWidth), boardHeight(boardHeight) {
  x = 0;
  y = 0;
}

void Camera::move(uint16_t x, uint16_t y) {
  if (x <= boardWidth * TILE_WIDTH - screenWidth) {
    this->x = x;
  }

  if (y <= boardHeight * TILE_HEIGHT - screenHeight) {
    this->y = y;
  }
}

void Camera::shift(uint8_t incrementX, uint8_t incrementY) {
  Camera::move(x + incrementX, y + incrementY);
}

void Camera::coordinatesMove(uint16_t x, uint16_t y) {
  Camera::move(x * TILE_WIDTH, y * TILE_HEIGHT);
}

void Camera::coordinatesShift(uint8_t incrementX, uint8_t incrementY) {
  Camera::shift(incrementX * TILE_WIDTH, incrementY * TILE_HEIGHT);
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
}

uint16_t Camera::getX() {
  return x;
}

uint16_t Camera::getY() {
  return y;
}

uint16_t Camera::getMaxX() {
  return x + screenWidth;
}

uint16_t Camera::getMaxY() {
  return y + screenHeight;
}
