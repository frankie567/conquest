#include <Gamebuino-Meta.h>
#include "src/board.h"
#include "src/camera.h"

Board* board;
Camera* camera;

void setup() {
  gb.begin();
  gb.pickRandomSeed();

  board = new Board(20, 20);
  camera = new Camera(gb.display.width(), gb.display.height(), board);
}

void loop() {
  while(!gb.update());
  gb.display.clear();

  camera->control();
}
