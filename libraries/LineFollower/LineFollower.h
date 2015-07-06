#ifndef LINEFOLLOWER_H_
#define LINEFOLLOWER_H_

#define THRESHOLD_PIN     2
#define LEFT_COLOR_PIN    3
#define RIGHT_COLOR_PIN   4
#define LEFT_MOTOR_PIN    0
#define RIGHT_MOTOR_PIN   1

#include <MAF.h>

namespace LineFollower {

/*Enums*/
enum LineFollowerState {
  ON_COURSE,
  FAR_LEFT,
  FAR_RIGHT,
  OFF_COURSE
};

enum Color {
  LIGHT,
  DARK
};

/*Setup and Control*/
void reset();
void update();
void sensor_update();
void state_update();
void motion_update();

/*State variables*/
LineFollowerState state;
Color left_color;
Color right_color;

/*Sensor Variables*/
MAF threshold_value;
MAF left_color_value;
MAF right_color_value;

/*Helpers*/
Color color(int value, threshold) {
  if(value < threshold) return LIGHT;
  else return DARK;
}

} // LineFollower

#endif // LINEFOLLOWER_H_
