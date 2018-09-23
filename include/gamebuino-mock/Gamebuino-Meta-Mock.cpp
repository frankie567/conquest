#include "Gamebuino-Meta-Mock.h"

namespace Gamebuino_Meta {

  void Buttons::begin() {
    return;
  }

  bool Buttons::pressed(Button button) {
    return true;
  }

  uint16_t Buttons::timeHeld(Button button) {
    return 0;
  }

  void Gamebuino::begin() {
    buttons.begin();
  }

}

Gamebuino gb;
