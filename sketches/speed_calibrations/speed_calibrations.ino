#include <LineFollower.h>

#define CALIBRATION_DELAY 1000.0

// Place the left motor speed in the first array and
// the right motor speed in the second array index.
const int g_motor_speeds[][2] = {
  {255, 200}, 
  {100, 200}, 
  {127, 255},
};
const int g_num_speeds = sizeof(g_motor_speeds) / sizeof(int[2]);

void calibrate_speeds(const int[][2], const int);

void setup() {
  LineFollower::reset();
}

void loop() {
  calibrate_speeds(g_motor_speeds, g_num_speeds);
}

void calibrate_speeds(const int motor_speeds[][2], const int num_speeds) {
  int i;
  for (i = 0; i < num_speeds; i++) {
    analogWrite(LEFT_MOTOR_PIN, motor_speeds[i][0]);
    analogWrite(RIGHT_MOTOR_PIN, motor_speeds[i][1]);
    delay(CALIBRATION_DELAY);
  }
}

