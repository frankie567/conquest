#ifndef CAMERA_H
#define CAMERA_H

#include <stdint.h>

class Camera {
  public:
    Camera(uint8_t screenWidth, uint8_t screenHeight, uint16_t boardWidth, uint16_t boardHeight);
    void move(uint16_t x, uint16_t y);
    void shift(uint8_t incrementX, uint8_t incrementY);
    void coordinatesMove(uint16_t x, uint16_t y);
    void coordinatesShift(uint8_t incrementX, uint8_t incrementY);
    void control();

    uint16_t getX();
    uint16_t getY();
    uint16_t getMaxX();
    uint16_t getMaxY();

  private:
    uint8_t screenWidth;
    uint8_t screenHeight;
    uint16_t boardWidth;
    uint16_t boardHeight;
    uint16_t x;
    uint16_t y;
};

#endif
