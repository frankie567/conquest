#include <Gamebuino-Meta.h>
#include "src/board.h"
#include "src/camera.h"
#include "src/cursor.h"

Board* board;
Cursor* cursor;
Camera* camera;

const uint16_t BOARD_WIDTH = 20;
const uint16_t BOARD_HEIGHT = 20;

void setup() {
  gb.begin();
  gb.pickRandomSeed();

  board = new Board(BOARD_WIDTH, BOARD_HEIGHT);
  cursor = new Cursor(board);
  camera = new Camera(gb.display.width(), gb.display.height(), BOARD_WIDTH, BOARD_HEIGHT);
}

void loop() {
  while(!gb.update());
  gb.display.clear();

  camera->control();
  cursor->control();

  board->draw(camera);
  cursor->draw(camera);
}
