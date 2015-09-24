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
extern LineFollowerState state;
extern Color left_color;
extern Color right_color;

/*Sensor Variables*/
extern MAF threshold_value;
extern MAF left_color_value;
extern MAF right_color_value;

/*Helpers*/
inline Color color(int value, int threshold) {
  if(value < threshold) return LIGHT;
  else return DARK;
}

} // LineFollower

#endif // LINEFOLLOWER_H_
