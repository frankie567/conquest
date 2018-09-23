#include <stdint.h>

namespace Gamebuino_Meta {

  const uint8_t NUM_BTN = 8;
  const uint8_t BTN_CS = 25;

  enum class Button : uint8_t {
    down,
    left,
    right,
    up,
    a,
    b,
    menu,
    home,
  };

  class Buttons {
    public:
      void begin();
      void update();
      bool pressed(Button button);
      bool released(Button button);
      bool held(Button button, uint16_t time);
      bool repeat(Button button, uint16_t period);
      uint16_t timeHeld(Button button);
      uint16_t states[NUM_BTN];
  };
  
  class Gamebuino {
    public:
      Buttons buttons;
  };

}

using Gamebuino_Meta::Gamebuino;
extern Gamebuino gb;

using Gamebuino_Meta::Button;

const Button BUTTON_DOWN = Button::down;
const Button BUTTON_LEFT = Button::left;
const Button BUTTON_RIGHT = Button::right;
const Button BUTTON_UP = Button::up;
const Button BUTTON_A = Button::a;
const Button BUTTON_B = Button::b;
const Button BUTTON_MENU = Button::menu;
const Button BUTTON_HOME = Button::home;
const Button BUTTON_C = Button::menu;
const Button BUTTON_D = Button::home;
