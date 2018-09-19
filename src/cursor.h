#ifndef CURSOR_H
#define CURSOR_H

#include <stdint.h>
#include "board.h"
#include "camera.h"

class Cursor {
  public:
    Cursor(Board* board);
    void move(uint16_t x, uint16_t y);
    void control();
    void draw(Camera* camera);

  private:
    uint16_t x;
    uint16_t y;
    Board* board;
};

#endif
