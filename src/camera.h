#ifndef CAMERA_H
#define CAMERA_H

#include <stdint.h>
#include "board.h"

class Camera {
  public:
    Camera(uint8_t width, uint8_t height, Board* board);
    void move(uint16_t x, uint16_t y);
    void shift(uint8_t incrementX, uint8_t incrementY);
    void coordinatesMove(uint16_t x, uint16_t y);
    void coordinatesShift(uint8_t incrementX, uint8_t incrementY);
    void draw();
    void control();

  private:
    uint8_t width;
    uint8_t height;
    Board* board;
    uint16_t x;
    uint16_t y;

    uint16_t getMaxX();
    uint16_t getMaxY();
};

#endif
