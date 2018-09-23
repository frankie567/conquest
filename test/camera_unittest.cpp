#include "gtest/gtest.h"

#include "../src/camera.h"

namespace {

  TEST(CameraTest, Dummy) {
    Camera* camera = new Camera(16, 16, 16, 16);
    EXPECT_EQ(camera->getX(), 0);
  }

}
