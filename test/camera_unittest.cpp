#include "gtest/gtest.h"

#include "../src/camera.h"
#include "../src/constants.h"

const uint16_t BOARD_WIDTH = 20;
const uint16_t BOARD_HEIGHT = 20;
const uint8_t SCREEN_WIDTH = 80;
const uint8_t SCREEN_HEIGHT = 64;

namespace {

  class CameraTest : public ::testing::Test {
  protected:
    void SetUp() override {
      camera = new Camera(SCREEN_WIDTH, SCREEN_HEIGHT, BOARD_WIDTH, BOARD_HEIGHT);
    }

    Camera* camera;
  };

  // Camera::Camera

  TEST_F(CameraTest, ShouldInitializeAt00) {
    EXPECT_EQ(camera->getX(), 0);
    EXPECT_EQ(camera->getY(), 0);
  }

  // Camera::move

  TEST_F(CameraTest, MoveShouldSetXAndYTOProvidedCoordinates) {
    camera->move(10, 20);
    EXPECT_EQ(camera->getX(), 10);
    EXPECT_EQ(camera->getY(), 20);
  }

  TEST_F(CameraTest, MoveShouldSetCoordinatesIfTheyAreWithinBoardBounds) {
    camera->move(BOARD_WIDTH * TILE_WIDTH, 0);
    EXPECT_EQ(camera->getX(), 0);
    
    camera->move(0, BOARD_WIDTH * TILE_HEIGHT);
    EXPECT_EQ(camera->getY(), 0);
  }

}
