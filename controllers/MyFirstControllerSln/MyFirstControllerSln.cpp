// File:          MyFirstControllerSln.cpp
// Date:
// Description:
// Author:
// Modifications:

#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/PositionSensor.hpp>

const int TIME_STEP {32};
const double weelRadius {0.02};
const double axleLength {0.052};

int main(int argc, char **argv) {

  webots::Robot robot {};
  
  webots::Motor *leftMotor {robot.getMotor("left wheel motor")};
  webots::Motor *rightMotor {robot.getMotor("right wheel motor")};
  
  leftMotor->setPosition(10);
  rightMotor->setPosition(10);
  
  webots::PositionSensor *leftEncoder {robot.getPositionSensor("left wheel sensor")};
  webots::PositionSensor *rightEncoder {robot.getPositionSensor("right wheel sensor")};
  
  leftEncoder->enable(TIME_STEP);
  rightEncoder->enable(TIME_STEP);
  
  while(robot.step(TIME_STEP) != -1) {
    double leftPosition {leftEncoder->getValue()};
    double rightPosition {rightEncoder->getValue()};
    std::cout << leftPosition << " " << rightPosition << ' ';
    std::cout << (leftPosition + rightPosition) / 2 * weelRadius << ' ';
    std::cout << (leftPosition - rightPosition) * weelRadius / axleLength << '\n';
  }
  
  return 0;
}